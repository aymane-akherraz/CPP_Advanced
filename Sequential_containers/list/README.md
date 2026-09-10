# `std::list` Overview

## Definition

```cpp
template <class T, class Allocator = std::allocator<T>>
class list;
```

## Description

`std::list` is a container from the **C++ Standard Template Library (STL)** that implements a **doubly linked list**.

Each element in a `list`:

* Stores the actual value.
* Contains a pointer to the **next element**.
* Contains a pointer to the **previous element**.

Unlike `std::vector` and `std::deque`, a `list`:

* ❌ Does **not** use contiguous memory.
* ❌ Does **not** support random access (`operator[]` is not available).
* ✔ Allows fast insertion and deletion **anywhere** in the sequence.

Because elements are individually allocated and linked together, they may reside in completely different areas of memory.

---

## Template Parameters

```cpp
template <class T, class Allocator = std::allocator<T>>
```

### `T`

The type of elements stored in the list.

### `Allocator`

Defines the memory model used to allocate and deallocate elements.

* Default: `std::allocator<T>`
* Custom allocators can be supplied if necessary.

---

## Example Usage

Since `list` is a template class, you must specify the element type during instantiation.

```cpp
class A;

std::list<int> l1;
std::list<float> l2;
std::list<A> l3;
```

Each list stores elements of the specified type.

---

## Constructors

The constructors of `std::list` are the same pattern as `vector` and `deque`.

### Default Constructor

```cpp
explicit list(const Allocator& = Allocator());
```

Creates an empty list.

---

### Fill Constructor

```cpp
explicit list(size_type n, const T& value = T(), const Allocator& = Allocator());
```

Creates a list containing `n` elements initialized with `value`.

---

### Range Constructor

```cpp
template <class InputIterator>
list(InputIterator first, InputIterator last, const Allocator& = Allocator());
```

Creates a list using elements from the range `[first, last)`.

---

### Copy Constructor

```cpp
list(const list<T, Allocator>& x);
```

Creates a new list as a copy of another list.

---

## Key Characteristics

* ✔ Fast insertion anywhere
* ✔ Fast deletion anywhere
* ✔ No reallocation required
* ✔ Stable iterators (inserting elements does not invalidate others)
* ❌ No random access (`operator[]` not available)
* ❌ Higher memory usage (extra pointers per element)

---

## Performance Considerations

### Advantages

* Efficient for frequent insertions and removals in the middle.
* Operations that change element order are generally less costly than in `vector` or `deque`.

### Disadvantages

* No constant-time random access.
* Extra memory overhead due to storing two pointers per element.
* Lower cache efficiency compared to contiguous containers.

---

## Iteration

Even though random access is not supported, you can still traverse the container using STL iterators:

```cpp
for (std::list<int>::iterator it = l1.begin(); it != l1.end(); ++it)
{
    std::cout << *it << std::endl;
}
```

---

## `std::list` vs `std::vector` vs `std::deque`

| Feature            | `std::vector` | `std::deque` | `std::list`    |
| ------------------ | ------------- | ------------ | -------------- |
| Memory Layout      | Contiguous    | Segmented    | Non-contiguous |
| Random Access      | ✔             | ✔            | ❌             |
| Fast Front Insert  | ❌            | ✔            | ✔              |
| Fast Back Insert   | ✔             | ✔            | ✔              |
| Fast Middle Insert | ❌            | ❌           | ✔              |
| Memory Overhead    | Low           | Medium       | High           |

---

## When to Use `std::list`

Use `std::list` when:

* You frequently insert/remove elements in the **middle** of the container.
* You need stable iterators.
* Random access is **not required**.

---

## Summary

`std::list` is a flexible container based on a doubly linked list structure. It provides:

* Efficient insertions and deletions anywhere
* Stable iterators
* Dynamic memory management

However, it sacrifices random access and consumes more memory compared to `vector` and `deque`.
