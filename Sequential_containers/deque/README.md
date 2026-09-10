# `std::deque` Overview

## Definition

```cpp
template <class T, class Allocator = std::allocator<T>>
class deque;
```

## Description

`std::deque` (double-ended queue) is a container from the **C++ Standard Template Library (STL)** that allows efficient insertion and removal of elements at **both the front and the back**.

In many ways, `std::deque` is similar to `std::vector`, but with an important structural difference:

* A `vector` stores elements in **contiguous memory**.
* A `deque` does **not require contiguous memory**.

Internally, a `deque` can be thought of as a **double-ended sequence of fixed-size arrays**. This structure allows:

* Fast insertion and deletion at both ends.
* No need for full reallocation when growing.
* Efficient random access using `operator[]`.

---

## Template Parameters

```cpp
template <class T, class Allocator = std::allocator<T>>
```

### `T`

The type of elements stored in the deque.

### `Allocator`

Defines the memory model used to allocate and deallocate elements.

* Default: `std::allocator<T>`
* Custom allocators can be provided.
* Each container type can technically use a different allocator.

---

## Example Usage

Since `deque` is a template class, you must specify the element type when creating it.

```cpp
class A;

std::deque<int> d1;
std::deque<float> d2;
std::deque<A> d3;
```

Each deque instance stores elements of the specified type.

---

## Constructors

### Default Constructor

```cpp
explicit deque(const Allocator& = Allocator());
```

Creates an empty deque using the specified allocator.

---

### Fill Constructor

```cpp
explicit deque(size_type n, const T& value = T(), const Allocator& = Allocator());
```

Creates a deque containing `n` elements initialized with `value`.

---

### Range Constructor

```cpp
template <class InputIterator>
deque(InputIterator first, InputIterator last, const Allocator& = Allocator());
```

Creates a deque using elements from the range `[first, last)`.

---

### Copy Constructor

```cpp
deque(const deque<T, Allocator>& x);
```

Creates a new deque as a copy of another deque.

---

## Key Characteristics

* ✔ Fast insertion at the front (`push_front`)
* ✔ Fast insertion at the back (`push_back`)
* ✔ Random access in constant time (O(1))
* ✔ No need for contiguous memory
* ✔ Dynamic resizing

---

## `std::deque` vs `std::vector`

| Feature                            | `std::vector` | `std::deque`               |
| ---------------------------------- | ------------- | -------------------------- |
| Memory Layout                      | Contiguous    | Non-contiguous (segmented) |
| Fast `push_back`                   | ✔             | ✔                          |
| Fast `push_front`                  | ✖             | ✔                          |
| Random Access                      | ✔             | ✔                          |
| Reallocation Required When Growing | Yes           | No (adds new blocks)       |

---

## When to Use `std::deque`

Use `std::deque` when:

* You frequently insert/remove elements at **both ends**.
* You need random access.
* You want to avoid costly reallocation when growing.

---

## Summary

`std::deque` is a flexible and efficient container that combines:

* Dynamic resizing
* Constant-time random access
* Efficient insertions/removals at both ends

It is ideal when you need more flexibility than `std::vector`, especially for front insertions.
