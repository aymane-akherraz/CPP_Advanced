# Input Stream Operations

## `operator>>`

### Name

```cpp
operator>>
```

### Header

```cpp
#include <istream>
```

### Signatures

#### Member Functions

These overloads are member functions of `std::istream`:

```cpp
istream& operator>>(bool& val);
istream& operator>>(short& val);
istream& operator>>(unsigned short& val);
istream& operator>>(int& val);
istream& operator>>(unsigned int& val);
istream& operator>>(long& val);
istream& operator>>(unsigned long& val);
istream& operator>>(float& val);
istream& operator>>(double& val);
istream& operator>>(long double& val);
istream& operator>>(void*& val);
```

#### Non-Member Functions

The character and C-style string overloads are non-member functions:

```cpp
istream& operator>>(istream& is, char& ch);
istream& operator>>(istream& is, signed char& ch);
istream& operator>>(istream& is, unsigned char& ch);
istream& operator>>(istream& is, char* str);
istream& operator>>(istream& is, signed char* str);
istream& operator>>(istream& is, unsigned char* str);
```

### Parameters

* **`val`** — The parameter to which the extracted value is stored.

  Stream objects read characters and attempt to **convert them to the type of `val`**. There is a different input operator overload for each supported C++ built-in type.

  For example:

  ```cpp
  int n;

  std::cin >> n;
  ```

  Characters are read from `std::cin` and converted to an `int`.

* **`ch`** — One character is extracted from the input stream and stored in `ch`.

  ```cpp
  char ch;

  std::cin >> ch;
  ```

* **`str`** — A C-style string into which the extracted characters are stored.

  The extraction generally ends when the stream encounters:

  * A whitespace character
  * An end-of-line character
  * An end-of-file condition

  A terminating null character (`'\0'`) is automatically added to the string.

* **`is`** — The input stream on which the operation takes place.

### Return Value

The function returns a reference to the input stream on which the operation takes place.

For member functions, this is a reference to the calling object (`*this`).

This allows input operations to be chained:

```cpp
int a;
int b;

std::cin >> a >> b;
```

Conceptually:

```cpp
(std::cin >> a) >> b;
```

The value extracted by the function is stored in its argument (`val`, `ch`, or `str`).

---

## Input State Flags

During input operations, the stream's internal state flags may be modified.

The main flags are:

| Flag      | Meaning                                                                                                                          |
| --------- | -------------------------------------------------------------------------------------------------------------------------------- |
| `eofbit`  | The end of the character source was reached during the operation.                                                                |
| `failbit` | The input could not be interpreted as an element of the required type. Some situations that set `eofbit` can also set `failbit`. |
| `badbit`  | An error other than the conditions represented by `eofbit` or `failbit` occurred.                                                |

These flags can be inspected using the stream's state functions such as:

```cpp
std::cin.eof();
std::cin.fail();
std::cin.bad();
```

### Example: `failbit`

Suppose an integer is expected:

```cpp
int n;

std::cin >> n;
```

If the user enters:

```text
hello
```

the characters cannot be converted into an integer, so the stream sets `failbit`.

---

## Description

The input operator performs data input operations using a given input stream.

The operation usually consists of:

1. **Reading characters** from the input stream.
2. **Interpreting and converting** those characters.
3. **Storing the resulting value** in the object supplied as the operator's argument.

For example:

```cpp
int n;

std::cin >> n;
```

The input stream reads characters and converts them to the expected type, `int`.

There are many overloaded variants of the input operator, but the important ones are presented here.

### Member and Non-Member Overloads

The first group consists of member functions of the `std::istream` class:

```cpp
istream& operator>>(int& val);
istream& operator>>(double& val);
```

The second group consists of non-member functions, which handle characters and C-style strings:

```cpp
istream& operator>>(istream& is, char& ch);
istream& operator>>(istream& is, char* str);
```

This follows the same general idea as `operator<<`: most numeric overloads are members, while character and C-style string overloads are non-member functions.

---

## Reading C-Style Strings

When a C-style string is read using `operator>>`, extraction generally stops when whitespace is encountered.

For example:

```cpp
char str[20];

std::cin >> str;
```

If the user enters:

```text
Hello World
```

only:

```text
Hello
```

is extracted into `str`.

The space terminates the extraction, and `'\0'` is automatically appended:

```text
H e l l o \0
```

### Controlling String Extraction with `width()`

The internal `width` field can also limit how many characters are extracted.

If `width()` has a non-zero value, the string extraction operator reads at most:

```text
width - 1
```

characters.

The remaining character is reserved for the terminating null character (`'\0'`).

For example:

```cpp
char str[10];

std::cin.width(10);
std::cin >> str;
```

At most **9 characters** are extracted:

```text
9 characters + '\0'
```

This is why the extraction limit is `width - 1`.

> **Important:** The `width()` value is consumed by this extraction operation and is then reset, just as it is for formatted output.

## Input Stream Operations — `get()`

The `get()` function provides a way to perform **unformatted input**. Unlike formatted extraction with `operator>>`, it reads characters directly from the stream without trying to interpret them as a particular data type.

### Signatures

```cpp
int get();
istream& get(char& c);
istream& get(char* s, streamsize n);
istream& get(char* s, streamsize n, char delim);
```

### Parameters

* **`c`** — A `char` variable used to store an extracted character.

* **`s`** — A pointer to an array that will hold the extracted C-style string.

* **`n`** — The maximum number of characters that `get()` can read and store, **including the terminating null character**.

* **`delim`** — The delimiting character. Extraction stops when this character is encountered.

  If `delim` is not specified, the default delimiter is the newline character (`'\n'`).

### Return Value

The first version:

```cpp
int get();
```

returns the extracted character as an `int`.

The other versions return a reference to the input stream on which the operation was performed:

```cpp
istream& get(...);
```

This is a reference to the calling object (`*this`) and allows operations to be chained.

### Input State Flags

Errors are signalled by modifying the stream's internal state flags:

| Flag      | Meaning                                                                                                                                               |
| --------- | ----------------------------------------------------------------------------------------------------------------------------------------------------- |
| `eofbit`  | The end of the character source was reached during the operation.                                                                                     |
| `failbit` | No characters were extracted because the end was reached prematurely or the destination operation failed. Some `eofbit` cases can also set `failbit`. |
| `badbit`  | An error other than the conditions represented by `eofbit` or `failbit` occurred.                                                                     |

Depending on the stream's configured exception mask, an exception may also be thrown when an error occurs.

---

## Description

The `get()` function performs **unformatted input**.

Basically, it reads characters directly from the input stream and places them into the specified destination.

### Reading One Character

The first two variants read exactly **one character** from the stream:

```cpp
int get();
istream& get(char& c);
```

For example:

```cpp
char c;

std::cin.get(c);
```

If the input is:

```text
Hello
```

the first call extracts:

```text
H
```

The next character, `e`, remains in the stream.

The difference between the two single-character versions is their return value:

```cpp
int c = std::cin.get();
```

versus:

```cpp
char c;
std::cin.get(c);
```

The first returns the extracted character directly as an `int`, while the second stores the character in `c` and returns the stream.

---

## Reading a C-Style String

The other variants can extract multiple characters into a character array:

```cpp
istream& get(char* s, streamsize n);
istream& get(char* s, streamsize n, char delim);
```

The function continues extracting characters until one of the following conditions occurs:

1. `n - 1` characters have been extracted.
2. The delimiter is encountered.
3. The end of the input source is reached.

One character position is reserved for the terminating null character (`'\0'`).

For example:

```cpp
char str[10];

std::cin.get(str, 10);
```

At most:

```text
9 characters + '\0'
```

can be stored in `str`.

---

## Delimiter

By default, `get()` uses the newline character (`'\n'`) as its delimiter:

```cpp
std::cin.get(str, 10);
```

The delimiter **is not extracted** from the stream.

For example, if the input is:

```text
Hello
World
```

then:

```cpp
char str[20];

std::cin.get(str, 20);
```

stores:

```text
Hello
```

but leaves the newline character in the input stream.

The next input operation can therefore encounter that `'\n'`.

### Custom Delimiter

A different delimiter can be supplied:

```cpp
char str[20];

std::cin.get(str, 20, ',');
```

For input:

```text
Hello,World
```

the extraction stops when `,` is encountered.

The result is:

```text
Hello
```

The comma is **not extracted** and remains available for the next input operation.

> **Important:** This is one of the main differences between `get()` and functions that consume their delimiter. With `get()`, the delimiting character is detected but **left in the stream**.

---

## `get()` vs `operator>>`

The important difference is that `get()` performs **unformatted input**, while `operator>>` performs **formatted input**.

For example:

```cpp
char c;

std::cin >> c;
```

and:

```cpp
std::cin.get(c);
```

do not behave identically.

`operator>>` performs formatted extraction and normally **skips leading whitespace**.

`get()` performs unformatted extraction and **does not skip whitespace**.

So if the next character in the stream is a newline:

```cpp
std::cin.get(c);
```

can read that newline directly into `c`.

This makes `get()` useful when the program needs to process the input **character by character**, including whitespace and newline characters.

## Input Stream Operations — `getline()`

The `getline()` function is an **unformatted input operation** used to extract characters from an input stream and store them in a C-string buffer.

### Signatures

```cpp
istream& getline(char* s, streamsize n);
istream& getline(char* s, streamsize n, char delim);
```

### Parameters

| Parameter | Description                                                                                   |
| --------- | --------------------------------------------------------------------------------------------- |
| `s`       | Pointer to the character array where the extracted line is stored.                            |
| `n`       | Maximum number of characters that can be stored in `s`, **including** the terminating `'\0'`. |
| `delim`   | Character that causes extraction to stop. Optional; defaults to `'\n'`.                       |

### Return Value

Both versions return a reference to the stream on which the function was invoked:

```cpp
*this
```

This allows input operations to be chained.

### Stream State Flags

Errors are signaled by modifying the stream's internal state flags:

| Flag      | Meaning                                                                                                                                                                                |
| --------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `eofbit`  | The end of the input source was reached during the operation.                                                                                                                          |
| `failbit` | No characters were extracted because the end was reached prematurely, or `n - 1` characters were extracted without encountering the delimiter. Some `eofbit` cases also set `failbit`. |
| `badbit`  | An error other than the above occurred.                                                                                                                                                |

Depending on the stream's exception mask, an exception may also be thrown when an error occurs.

### Description

`getline()` extracts characters from the input stream and stores them in the buffer `s`.

Extraction stops when one of the following conditions occurs:

1. **`n - 1` characters have been extracted**
2. **The delimiter character is encountered**
3. **An input error occurs**, such as reaching EOF

The delimiter is handled differently from `get()`:

> **Important:** If the delimiter is found, it is **extracted and discarded**. It will **not** remain in the input stream for the next operation.

The terminating null character `'\0'` is automatically added to the buffer.

### Example

```cpp
char str[20];

std::cin.getline(str, 20);
```

If the user enters:

```text
Hello World
```

the buffer contains:

```text
H e l l o   W o r l d \0
```

The newline generated by pressing Enter is **extracted and discarded** by `getline()`.

## Input Stream Operations — `getline()` for `std::string`

The `std::getline()` function provides a version of `getline()` specifically designed to read input into a `std::string` object.

### Header

```cpp id="v5v8oa"
#include <string>
```

### Signatures

```cpp id="j9x4ke"
istream& getline(istream& is, string& str, char delim);
istream& getline(istream& is, string& str);
```

### Parameters

| Parameter | Description                                                                 |
| --------- | --------------------------------------------------------------------------- |
| `is`      | The input stream from which characters are extracted.                       |
| `str`     | The `std::string` object that receives the extracted characters.            |
| `delim`   | The delimiter that causes extraction to stop. Optional; defaults to `'\n'`. |

### Return Value

Both versions return a reference to the input stream provided as the `is` parameter:

```cpp id="j6m2fz"
is
```

This allows the result to be used in further stream operations.

### Description

These functions are the `std::string` versions of the `std::istream::getline()` operations.

The main difference is that they store the extracted characters in a `std::string` instead of a fixed-size character array.

Because a `std::string` can **automatically increase its size** when necessary, there is no need to provide a maximum buffer size:

```cpp id="g8q2rx"
std::string str;

std::getline(std::cin, str);
```

This is the main difference from `istream::getline()`, which requires a buffer and its maximum size:

```cpp id="w3j7kp"
char str[100];

std::cin.getline(str, 100);
```

With `std::getline()`, the string can grow as needed, so the programmer does not need to manually specify the maximum number of characters.

> **Important:** `std::getline()` is a **non-member function**. It is part of the `<string>` interface, but it is not a member function of the `std::string` class. It is defined as a global function that operates on a `std::string` object.

### Example

```cpp id="q2m8vd"
#include <iostream>
#include <string>

int main()
{
    std::string str;

    std::getline(std::cin, str);

    std::cout << str << '\n';
}
```

If the input is:

```text id="a7n3kx"
Hello World
```

the entire line, including the space between `Hello` and `World`, is stored in `str`.

The newline character `'\n'` is **extracted and discarded**, so it is not stored in the string.
