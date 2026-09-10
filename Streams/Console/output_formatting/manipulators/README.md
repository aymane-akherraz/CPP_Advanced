# Manipulators

**Manipulators** are another way of changing the formatting behavior of a stream.

You can think of them as **values inserted into the stream to alter its state**.

For example:

```cpp
std::cout << std::hex << 255;
```

Here, `std::hex` changes the formatting state of `std::cout`, causing `255` to be displayed in hexadecimal:

```text
ff
```

Technically, manipulators are implemented as **functions**.

The combined functionality provided by manipulators is equivalent to that provided by **stream flags and stream interface functions**.

For example:

```cpp
std::cout.setf(std::ios_base::hex, std::ios_base::basefield);
```

is equivalent to:

```cpp
std::cout << std::hex;
```

Manipulators are therefore a more convenient way to perform many common stream operations.

---

## Headers

Different manipulators are provided by different headers.

For the manipulators discussed here, the most important header is:

```cpp
#include <iomanip>
```

It is important to remember that you will **usually only need to include `<iomanip>` directly** when using the manipulators defined there.

Other headers are often included indirectly through the STL input/output library.

For example, `<ios>` is one of the fundamental headers of the STL input/output library and provides the definitions needed for stream-related functionality.

> **Remark:** When using a particular manipulator, check which header defines it. Do not rely on indirect inclusion if your program specifically requires a header.

---

## Signatures of Manipulators

Manipulators belonging to the same category have similar signatures, so it is enough to understand the general form of each category.

There are currently **four distinct groups of manipulators**.

### 1. Independent and Grouped Flag Manipulators

This category includes manipulators for:

* Independent flags
* `basefield`
* `floatfield`
* `adjustfield`

General signature:

```cpp
ios_base& manipulator(ios_base& str);
```

For example:

```cpp
std::cout << std::hex;
std::cout << std::showpos;
std::cout << std::fixed;
std::cout << std::left;
```

These manipulators receive a reference to the stream and modify its formatting flags.

---

### 2. Input Manipulators

General signature:

```cpp
istream& manipulator(istream& is);
```

These manipulators operate on an input stream such as `std::cin`.

Example:

```cpp
std::cin >> std::ws;
```

---

### 3. Output Manipulators

General signature:

```cpp
ostream& manipulator(ostream& os);
```

These manipulators operate on an output stream such as `std::cout`.

For example:

```cpp
std::cout << std::endl;
```

The manipulator receives the output stream and performs its operation on it.

---

### 4. Parameterized Manipulators

Some manipulators need an additional parameter.

Their general form is different because the parameter must first be supplied to the manipulator:

```cpp
smanip setiosflags(ios_base::fmtflags mask);
smanip resetiosflags(ios_base::fmtflags mask);
smanip setbase(int base);
smanip setfill(char c);
smanip setprecision(int n);
smanip setw(int n);
```

Examples:

```cpp
std::cout << std::setprecision(3);
std::cout << std::setw(10);
std::cout << std::setfill('-');
std::cout << std::setbase(16);
```

For example:

```cpp
std::cout << std::setw(10) << 42;
```

The `setw(10)` manipulator changes the width for the next output operation.

Parameterized manipulators therefore provide a convenient way to perform operations that require a value.

![manipulators](../../Imgs/manipulators.png)
