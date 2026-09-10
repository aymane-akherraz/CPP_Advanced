# Flags — A Way to Control Stream Behavior

**Flags** are switches that control how STL I/O streams behave.

They can control, for example:

* **Input data parsing**
* **Output data formatting**
* **Numerical base** used for input and output (`decimal`, `hexadecimal`, etc.)
* **Decimal point appearance**
* **Adjustment** of output

## `fmtflags`

All stream formatting flags are defined as constants of the `ios_base::fmtflags` type.

For example:

```cpp
std::ios_base::fmtflags
```

Flags can be used to change the formatting and behavior of an I/O stream.

### Flag Groups and Masks

Some flags are **independent**, while others belong to a particular **group**.

The main flag groups are represented by masks:

* `basefield`
* `floatfield`
* `adjustfield`

These masks are also constants of type `ios_base::fmtflags`.

A mask contains the bits corresponding to all flags belonging to a particular group.

For example, `basefield` groups the flags that control the numerical base:

```text
basefield
 ├── dec
 ├── oct
 └── hex
```

Similarly:

```text
floatfield
 ├── fixed
 └── scientific
```

And:

```text
adjustfield
 ├── left
 ├── right
 └── internal
```

![flags](../../Imgs/flags.png)

### Flags Within a Group

When using flags that belong to the same group, it is important to remember that normally **only one flag should be active at a time**.

For example, for the `basefield` group, we normally want only one of the following:

```cpp
std::ios_base::dec
std::ios_base::oct
std::ios_base::hex
```

The safest way to select one flag from a group is to use the **two-argument version of `setf()`**.

Conceptually:

```cpp
stream.setf(flag, mask);
```

The first argument specifies the flag that should be enabled, while the second argument specifies the group to which that flag belongs.

For example:

```cpp
std::cout.setf(std::ios_base::hex, std::ios_base::basefield);
```

This selects hexadecimal formatting for integer output.

The mask tells `setf()` which group should be modified, ensuring that the other flags in that group are cleared.

If flags within the same group are enabled incorrectly, multiple conflicting flags can be active at the same time, which can lead to **unpredictable or unwanted results**.

### Interacting With Flags

The complete interface for interacting with stream flags will be described shortly, including functions such as:

* `flags()`
* `setf()`
* `unsetf()`

### Saving and Restoring Stream Flags

The stream's complete flag configuration can be saved using `flags()` and restored later using the same function.

This is useful when you want to **temporarily modify a stream** without permanently changing its configuration.

```cpp
#include <iostream>

int main()
{
    // 1. Save the current stream configuration
    std::ios::fmtflags original_settings = std::cout.flags();

    // 2. Modify the stream for temporary work
    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << 255;  // Outputs: ff

    // 3. Restore everything back to exactly how it was
    std::cout.flags(original_settings);
}
```

Here:

```cpp
std::ios::fmtflags original_settings = std::cout.flags();
```

saves the **entire current formatting flag configuration** of `std::cout`.

We can then temporarily modify the stream:

```cpp
std::cout.setf(std::ios::hex, std::ios::basefield);
```

The `hex` flag is selected from the `basefield` group, so:

```cpp
std::cout << 255;
```

outputs:

```text
ff
```

Finally:

```cpp
std::cout.flags(original_settings);
```

restores the previously saved configuration.

This restores the flags to **exactly the state they had before the temporary modification**.

> **Note:** `flags()` saves and restores the stream's **formatting flags**. It does not save other stream state such as `width`, `precision`, or `fill`.
