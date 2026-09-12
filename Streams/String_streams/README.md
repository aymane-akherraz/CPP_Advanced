# String Streams

String streams allow you to perform input and output operations on a `std::string` as if it were a file or console stream.

The `<sstream>` header provides three main string-stream classes:

* `std::istringstream` — input from a string
* `std::ostringstream` — output to a string
* `std::stringstream` — both input and output

Like `std::ifstream` and `std::ofstream`, these classes support the standard stream extraction (`>>`) and insertion (`<<`) operators. However, instead of communicating with a file, they operate on an internal `std::string`.

```cpp
#include <sstream>
#include <string>
```

---

## `istringstream`

`std::istringstream` is used to **read data from a string**.

It behaves similarly to `std::ifstream`, except that the source of the input is a string rather than a file.

### Constructor

**Signature:**

```cpp
explicit istringstream(
    openmode mode = ios_base::in
);

explicit istringstream(
    const string &str,
    openmode mode = ios_base::in
);
```

### Parameters

* `mode` – the mode of opening. The same stream mode flags used by file streams are available, such as `ios_base::in`.
* `str` – the string whose contents are used to initialize the `istringstream`.

### Description

The constructor creates an `istringstream` object.

The default mode is `ios_base::in`, because an `istringstream` is intended primarily for input.

The second constructor initializes the stream with a copy of the contents of `str`.

There is no connection between `str` and the stream after construction.

```cpp
std::string data = "42 3.14 hello";

std::istringstream stream(data);

int i;
double d;
std::string s;

stream >> i >> d >> s;
```

After the extraction:

```text
i = 42
d = 3.14
s = "hello"
```

### `str()`

**Signature:**

```cpp
string str() const;
void str(const string &s);
```

The first version retrieves the current contents of the stream.

The second version replaces the contents of the stream with a copy of `s`.

```cpp
std::istringstream stream("123 456");

std::cout << stream.str() << '\n';
```

Output:

```text
123 456
```

---

## `ostringstream`

`std::ostringstream` is used to **write data into a string**.

It behaves similarly to `std::ofstream`, except that the destination is an internal string rather than a file.

### Constructor

**Signature:**

```cpp
explicit ostringstream(
    openmode mode = ios_base::out
);

explicit ostringstream(
    const string &str,
    openmode mode = ios_base::out
);
```

### Parameters

* `mode` – the mode of opening. The same stream mode flags used by file streams are available, such as `ios_base::out`.
* `str` – the string whose contents are used to initialize the `ostringstream`.

### Description

The constructor creates an `ostringstream` object.

The default mode is `ios_base::out`, because an `ostringstream` is intended primarily for output.

Data can be inserted into the stream using the `<<` operator.

```cpp
std::ostringstream stream;

stream << "Value: " << 42 << ", pi: " << 3.14;
```

The resulting string can be retrieved using `str()`:

```cpp
std::cout << stream.str();
```

Output:

```text
Value: 42, pi: 3.14
```

### `str()`

**Signature:**

```cpp
string str() const;
void str(const string &s);
```

The first version returns the current contents of the `ostringstream`.

The second version replaces the contents of the stream with a copy of `s`.

```cpp
std::ostringstream stream;

stream << "Hello " << "world";

std::string result = stream.str();

std::cout << result << '\n';
```

Output:

```text
Hello world
```

---

## `stringstream`

`std::stringstream` supports **both input and output**.

It combines the functionality of `istringstream` and `ostringstream`.

Therefore, it can be used to:

* write data into a string;
* read data from the string;
* modify the contents of the stream.

### Constructor

**Signature:**

```cpp
explicit stringstream(
    openmode mode = ios_base::out | ios_base::in
);

explicit stringstream(
    const string &str,
    openmode mode = ios_base::out | ios_base::in
);
```

### Parameters

* `mode` – the mode of opening. The same mode flags available for `ifstream` and `ofstream` can be used.
* `str` – the string whose contents are used to initialize the `stringstream`.

### Description

The constructor creates a `stringstream` object and opens it in the specified mode.

The default mode is:

```cpp
ios_base::out | ios_base::in
```

This means that the stream supports both output and input.

The second constructor initializes the stream with a copy of the contents of `str`.

There is no connection between `str` and the `stringstream` after construction.

### Writing and reading

```cpp
std::stringstream stream;

stream << "42 " << "hello";

int number;
std::string word;

stream >> number >> word;
```

Here, the same stream is first used for output:

```cpp
stream << "42 " << "hello";
```

and then for input:

```cpp
stream >> number >> word;
```

---

## `stringstream::str()`

**Signature:**

```cpp
string str() const;
void str(const string &s);
```

### Parameters

* `s` – a string whose contents are used to replace the current contents of the stringstream.

### Return value

The first version returns the current contents of the `stringstream`.

The second version does not return a value.

### Description

The first version retrieves the current contents of the stream.

```cpp
std::stringstream stream;

stream << "Hello " << 42;

std::string result = stream.str();

std::cout << result << '\n';
```

Output:

```text
Hello 42
```

The second version replaces the contents of the existing stream:

```cpp
std::stringstream stream("old value");

stream.str("new value");

std::cout << stream.str() << '\n';
```

Output:

```text
new value
```

The supplied string is copied into the stream.

---

# Comparison

| Class           | Input | Output | Main purpose            |
| --------------- | ----: | -----: | ----------------------- |
| `istringstream` |   Yes |     No | Read from a string      |
| `ostringstream` |    No |    Yes | Build/write a string    |
| `stringstream`  |   Yes |    Yes | Read and write a string |

They can be compared to the file-stream classes:

| String stream   | File stream | Purpose        |
| --------------- | ----------- | -------------- |
| `istringstream` | `ifstream`  | Input          |
| `ostringstream` | `ofstream`  | Output         |
| `stringstream`  | `fstream`   | Input + output |

The important difference is the underlying source or destination:

```text
ifstream / ofstream
        ↓
      File

istringstream / ostringstream / stringstream
        ↓
      std::string
```

---

# Stream Operators

The same extraction and insertion operators used by other standard streams are available.

### Extraction operator `>>`

Used to read formatted data from an input string stream:

```cpp
std::istringstream stream("42 3.14");

int i;
double d;

stream >> i >> d;
```

### Insertion operator `<<`

Used to write formatted data into an output string stream:

```cpp
std::ostringstream stream;

stream << "Value = " << 42;
```

This is one of the main advantages of string streams: the normal stream syntax can be used to perform string formatting and parsing.

---

# Example: Parsing a String

`istringstream` is useful when a string contains several values that need to be extracted.

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string line = "42 3.14 hello";

    std::istringstream stream(line);

    int number;
    double decimal;
    std::string word;

    stream >> number >> decimal >> word;

    std::cout << number << '\n';
    std::cout << decimal << '\n';
    std::cout << word << '\n';
}
```

Output:

```text
42
3.14
hello
```

---

# Example: Building a String

`ostringstream` is useful when several values need to be combined into a formatted string.

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::ostringstream stream;

    stream << "Name: " << "Aymane";
    stream << ", Age: " << 42;

    std::string result = stream.str();

    std::cout << result << '\n';
}
```

Output:

```text
Name: Aymane, Age: 42
```

---

# Example: Reading and Writing

`stringstream` can perform both operations.

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::stringstream stream;

    stream << "42 hello";

    int number;
    std::string word;

    stream >> number >> word;

    std::cout << "number: " << number << '\n';
    std::cout << "word: " << word << '\n';
}
```

Output:

```text
number: 42
word: hello
```

---

# Important Difference from File Streams

A string stream does **not** open a file.

For example:

```cpp
std::ifstream file("data.txt");
```

opens a file and reads data from it.

Whereas:

```cpp
std::istringstream stream("42 hello");
```

uses the supplied string as its input source.

Similarly:

```cpp
std::ofstream file("data.txt");
```

writes to a file, while:

```cpp
std::ostringstream stream;
```

writes to an internal string.

The result of an output string stream is obtained with:

```cpp
stream.str();
```

---

# Summary

```text
                    <sstream>
                       │
          ┌────────────┼────────────┐
          │            │            │
          ▼            ▼            ▼
 istringstream   ostringstream  stringstream
          │            │            │
          │            │            │
       input         output      input + output
          │            │            │
          └────────────┼────────────┘
                       │
                  std::string
```

* `istringstream` reads **from** a string.
* `ostringstream` writes **to** a string.
* `stringstream` reads **from** and writes **to** a string.
* All three use the standard stream operators such as `>>` and `<<`.
* `str()` retrieves the current string contents.
* `str(const string&)` replaces the current string contents.
* The string supplied to a constructor is **copied**; the stream does not remain connected to the original string.
* `stringstream` defaults to `ios_base::in | ios_base::out`.
* `istringstream` defaults to `ios_base::in`.
* `ostringstream` defaults to `ios_base::out`.
