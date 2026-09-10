# Stream methods

For basic input/output formatting, the stream interface provides three important methods:

* `width()`
* `fill()`
* `precision()`

---

### Header

```cpp
#include <iostream>
```

## `width()`

### Signature

```cpp
streamsize width() const;
streamsize width(streamsize wide);
```

### Parameters

* **`wide`** — A new value for the stream's internal field related to the output width.

### Return Value

Both versions return the **previously set width** of the stream, before the call.

### Description

The first version simply returns the current value of the `width` field:

```cpp
std::cout.width();
```

The second version sets an internal parameter of the stream that specifies the **minimum number of characters** used to display a value:

```cpp
std::cout.width(10);
```

If the value requires fewer characters than the specified width, the remaining space is filled using the value specified by the stream's `fill` character.

For example:

```cpp
std::cout.width(10);
std::cout << 42;
```

The value `42` occupies a field of at least 10 characters:

```text
        42
```

The field's fill character can be changed using the `fill()` function.

The way the empty space is filled depends on the values of the flags grouped under `adjustfield`.

### Important: `width()` Is Temporary

It is important to remember that the value set by `width()` is valid **only for the next output operation**.

After that output operation, the width is reset.

For example:

```cpp
std::cout.width(10);
std::cout << 42 << 100;
```

Only `42` receives the specified width:

```text
        42 100
```

The second variant of `width()` also returns the width that was set **before** the call.

---

## `fill()`

### Signature

```cpp
char fill() const;
char fill(char ch);
```

### Parameters

* **`ch`** — A new character to be used to fill empty spaces in the output field.

### Return Value

Both versions return the **previously set fill character** of the stream.

### Description

The `fill()` function is used to get or set the character used to fill the unused space when an output field is wider than the value being displayed.

The first version returns the current fill character:

```cpp
std::cout.fill();
```

The second version changes the fill character:

```cpp
std::cout.fill('-');
```

By default, the fill character is a **space** (`' '`).

For example:

```cpp
std::cout.width(10);
std::cout << 42;
```

produces:

```text
        42
```

If we change the fill character:

```cpp
std::cout.fill('-');
std::cout.width(10);
std::cout << 42;
```

the output becomes:

```text
--------42
```

The fill character is used together with the `width()` setting. The `width()` function determines the **minimum field width**, while `fill()` determines which character is used to occupy the unused space.

The way the fill characters are positioned also depends on the stream's **`adjustfield` flags**.

For example, with right adjustment:

```cpp
std::cout.fill('.');
std::cout.width(10);
std::cout << 42;
```

produces:

```text
........42
```

### Important

Unlike `width()`, the fill character **is not reset after an output operation**.

Once changed, it remains the stream's fill character until it is changed again:

```cpp
std::cout.fill('-');

std::cout.width(10);
std::cout << 42 << '\n';

std::cout.width(10);
std::cout << 100;
```

Output:

```text
--------42
-------100
```

---

## `precision()`

### Signature

```cpp
streamsize precision() const;
streamsize precision(streamsize prec);
```

### Parameters

* **`prec`** — A new value for floating-point precision. `streamsize` is an integral type.

### Return Value

Both variants return the **previously set precision** for the stream.

### Description

The `precision()` function is used to set the number of digits displayed for a floating-point value.

```cpp
std::cout.precision(4);
```

The meaning of the precision depends on the current value of the `floatfield` flags.

### Default Format

If neither `scientific` nor `fixed` is set, the precision indicates the **maximum number of significant digits** displayed for a particular value.

This includes digits both **before and after the decimal point**.

For example:

```cpp
std::cout.precision(5);
std::cout << 123.456789;
```

The output is approximately:

```text
123.46
```

The precision represents the total number of significant digits, not simply the number of digits after the decimal point.

### `fixed` and `scientific`

When either `fixed` or `scientific` formatting is enabled, `precision()` has a different meaning.

In these formats, precision defines the **number of digits displayed after the decimal point**.

For example:

```cpp
std::cout << std::fixed;
std::cout.precision(3);
std::cout << 12.5;
```

Output:

```text
12.500
```

The required number of digits after the decimal point is displayed even when they are not needed, so **trailing zeros are added**.

Similarly:

```cpp
std::cout << std::scientific;
std::cout.precision(3);
std::cout << 12.5;
```

produces a scientific-notation representation with **3 digits after the decimal point**.
