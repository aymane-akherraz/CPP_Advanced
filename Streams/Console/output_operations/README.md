# Console Output Operations — `operator<<`

The majority of console output operations offered by a stream are provided by overloaded output operators (`operator<<`).

For each C++ built-in data type, there is an appropriate `operator<<` overload.

The list below does not contain any operators for the `std::string` class. There are two reasons for this:

1. `std::string` is **not a built-in data type**.
2. `std::string` is a **class**, so its appropriate operator should be defined where the class is defined.

> **Remember:** This is generally true for all object types. Classes and other user-defined types can provide their own `operator<<` overloads.

Also, pay attention to how the `bool` type is displayed, as its representation depends on the stream's formatting state.

### Name

```cpp
operator<<
```

### Header

```cpp
#include <ostream>
```

### Signatures

#### Member Functions

These overloads are member functions of `std::ostream`:

```cpp
ostream& operator<<(bool val);
ostream& operator<<(short val);
ostream& operator<<(unsigned short val);
ostream& operator<<(int val);
ostream& operator<<(unsigned int val);
ostream& operator<<(long val);
ostream& operator<<(unsigned long val);
ostream& operator<<(float val);
ostream& operator<<(double val);
ostream& operator<<(long double val);
ostream& operator<<(const void* val);
```

#### Global Functions

These overloads are defined as non-member (global) functions:

```cpp
ostream& operator<<(ostream& out, char c);
ostream& operator<<(ostream& out, signed char c);
ostream& operator<<(ostream& out, unsigned char c);
ostream& operator<<(ostream& out, const char* s);
ostream& operator<<(ostream& out, const signed char* s);
ostream& operator<<(ostream& out, const unsigned char* s);
```

### Parameters

* **`val`** — A value to be inserted into the stream in a human-readable form. The exact output depends on the state of the stream flags and previously inserted manipulators.

* **`c`** — Exactly one character to be inserted into the stream.

* **`s`** — A C-style string to be inserted into the output stream. The whole string is inserted up to the terminating null character (`'\0'`), and the width field is cleared afterward.

* **`out`** — The output stream on which the operation takes place.

### Return Value

This function returns a reference to the calling stream object (`*this`) or, for the global overloads, a reference to the output stream `out`.

This is what allows output operations to be **chained**:

```cpp
std::cout << "Hello " << 42 << '\n';
```

Each `operator<<` returns the stream, allowing the next `operator<<` operation to use it.

Conceptually:

```cpp
(std::cout << "Hello ") << 42;
```

> **Remark:** To use `std::cout` (and `std::cin`) in a C++ program, you must include the `<iostream>` header.


### Errors

In the case of an error, the `badbit` flag is set.

It can be checked using the `bad()` member function:

```cpp
if (std::cout.bad())
    // An output error occurred
```

Depending on the exception mask configured through `exceptions()`, this may also cause an exception of type `std::ios_base::failure` to be thrown.

### Description

`operator<<`, also called the **output operator** or **stream insertion operator**, is responsible for inserting data into an output stream.

For example:

```cpp
std::cout << 42;
```

Here:

* `std::cout` is the output stream.
* `42` is the value being inserted.
* `operator<<` performs the insertion.

One overload is available for each supported C++ built-in data type.

Apart from characters and C-style strings, the overloads discussed above are member functions of the `std::ostream` class.

For character and C-style string types, the operators are defined as non-member functions:

```cpp
std::cout << 'A';        // Character overload
std::cout << "Hello";    // C-style string overload
```

The actual formatting of a value inserted into the stream depends on the **state of the output stream**.

This state is controlled by its formatting flags, which can be changed:

* **Directly**, through stream member functions.
* **Indirectly**, with the help of manipulators.

For example:

```cpp
std::cout << std::hex << 42 << '\n';
```

The same integer value can therefore have a different representation depending on the stream's formatting state.

## Function `put()`

### Signature

```cpp
ostream& put(char c);
```

### Parameters

* **`c`** — The character to be inserted into the output stream.

### Return Value

The function returns a reference to the output stream on which the operation takes place — `*this`.

This allows output operations to be chained:

```cpp
std::cout.put('A').put('B').put('\n');
```

In the case of an error, the `badbit` flag is set, which can be checked with the `bad()` member function.

Depending on the values set through the `exceptions()` member function, this may also cause an exception of type `ios_base::failure` to be thrown.

### Description

The `put()` method inserts **exactly one character** into the output stream.

For example:

```cpp
std::cout.put('A');
```

This writes the character `A` to `std::cout`.

Unlike `operator<<`, which has different overloads for different data types, `put()` is specifically designed for inserting **a single character**.

The exact behavior of the visible output depends on the current state of the output stream.

For example:

```cpp
std::cout.put('A');
std::cout.put('\n');
```

produces:

```text
A
```
