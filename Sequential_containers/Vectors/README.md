# `std::vector` Overview

## Definition

```cpp
template <class T, class Allocator = std::allocator<T>>
class vector;
```

## Description

`std::vector` is one of the most commonly used containers in the **C++ Standard Template Library (STL)**. It is typically the first container developers learn when starting with STL.

A `vector` is essentially a **dynamic array**:

* It stores elements in a **contiguous block of memory**.
* It allows **random access** to elements using an index.
* Element access is performed in **constant time (O(1))**.
* It automatically manages memory as elements are added or removed.

Because of these properties, `std::vector` combines the performance of arrays with the flexibility of dynamic memory management.

---

## Template Parameters

```cpp
template <class T, class Allocator = std::allocator<T>>
```

### `T`

The type of elements stored in the vector.

### `Allocator`

Defines the memory model used for allocating and deallocating elements.

* Default: `std::allocator<T>`
* Custom allocators can be provided if needed.
* Technically, you may use a different allocator for each container type.

---

## Example Usage

Since `vector` is a template class, you must specify the element type when creating it.

```cpp
class A;

std::vector<int> v1;
std::vector<float> v2;
std::vector<A> v3;
```

Each vector instance stores elements of the specified type.

---

## Constructors

### Default Constructor

```cpp
explicit vector(const Allocator& = Allocator());
```

Creates an empty vector using the specified allocator.

---

### Fill Constructor

```cpp
explicit vector(size_type n, const T& value = T(), const Allocator& = Allocator());
```

Creates a vector containing `n` elements initialized with `value`.

---

### Range Constructor

```cpp
template <class InputIterator>
vector(InputIterator first, InputIterator last, const Allocator& = Allocator());
```

Creates a vector using elements from the range `[first, last)`.

---

### Copy Constructor

```cpp
vector(const vector<T, Allocator>& x);
```

Creates a new vector as a copy of another vector.

---

## Key Characteristics

* ✔ Contiguous memory storage
* ✔ Fast random access (O(1))
* ✔ Dynamic resizing
* ✔ Automatic memory management
* ✔ STL compatible

---

## Summary

`std::vector` is a powerful, flexible, and efficient container that behaves like a dynamic array. It provides:

* High performance
* Memory safety
* Ease of use
* Full integration with STL algorithms

For most use cases requiring sequential storage with frequent access by index, `std::vector` is the preferred container.
