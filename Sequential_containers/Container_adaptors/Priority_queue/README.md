# Priority Queue (STL Container Adaptor)

`priority_queue` is a Standard Template Library (STL) container adaptor that ensures the **largest element is always at the top**, according to a specified comparison rule (strict weak ordering).

Unlike a regular queue (FIFO), elements are ordered by **priority**, not insertion order.

---

## Template Definition

```cpp
template <
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
>
class priority_queue;
```

---

## Template Parameters

| Parameter               | Description                                              |
| ----------------------- | -------------------------------------------------------- |
| `T`                     | Type of elements stored in the priority queue            |
| `Container`             | Underlying storage container (default: `std::vector<T>`) |
| `Compare`               | Comparator defining strict weak ordering                 |
| `Container::value_type` | Type of stored elements (same meaning as `T`)            |

If not explicitly specified:

* `Container` defaults to `std::vector<T>`
* `Compare` defaults to `std::less<T>` (max-heap behavior)

---

## Description

`priority_queue` is implemented as a **container adaptor**. It wraps an underlying container and maintains elements in **heap order**.

The top element is always the "greatest" according to the comparator.

### Required Container Functionality

The underlying container must:

* Provide **random access iterators**
* Implement:

  * `front()`
  * `push_back()`
  * `pop_back()`

### Compatible STL Containers

* `std::vector`
* `std::deque`

Any custom container providing the required interface is also acceptable.

---

## Heap-Based Ordering

`priority_queue` maintains ordering using heap algorithms:

* `make_heap()`
* `push_heap()`
* `pop_heap()`

These algorithms ensure:

* The largest element is always accessible via `top()`
* Insertions and removals maintain heap structure

---

## Default Behavior (Max-Heap)

By default, `std::less<T>` is used:

```cpp
std::priority_queue<int> pq;
```

This creates a **max-heap**, meaning:

```
Top → Largest element
```

---

## Custom Comparator (Min-Heap Example)

To create a min-heap:

```cpp
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
```

Now:

```
Top → Smallest element
```

---

# Priority Queue – Initialization

## Constructors

### 1. Explicit Constructor

```cpp
explicit priority_queue(
    const Compare& x = Compare(),
    const Container& y = Container()
);
```

### Parameters

| Parameter | Description                                            |
| --------- | ------------------------------------------------------ |
| `x`       | Comparator object (must match template `Compare`)      |
| `y`       | Underlying container (must match template `Container`) |

### Description

* Creates a `priority_queue` using:

  * The provided comparator
  * The provided container
* The container **does not need to be empty**
* Copies of `x` and `y` are created if provided
* After initialization, `make_heap()` is called to establish heap ordering

Example:

```cpp
std::vector<int> v = {4, 1, 7, 3};
std::priority_queue<int> pq(std::less<int>(), v);
```

---

### 2. Copy Constructor

```cpp
priority_queue(const priority_queue& other);
```

### Parameters

| Parameter | Description                                               |
| --------- | --------------------------------------------------------- |
| `other`   | Existing priority queue used to initialize the new object |

### Description

* Creates a copy of an existing `priority_queue`
* Both objects must use:

  * The same `Container` type
  * The same `Compare` type
* The underlying container and comparator are copied

Example:

```cpp
std::priority_queue<int> pq1;
std::priority_queue<int> pq2(pq1);
```

---

## Comparator Details

The comparator must satisfy **strict weak ordering**.

It:

* Takes two parameters
* Returns `true` if the first parameter has *lower priority* than the second

It can be:

* A function object (functor)
* A lambda
* A standalone function

Example using a lambda:

```cpp
auto cmp = [](int a, int b) { return a > b; };
std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
```

---

## Key Characteristics

| Feature           | Details           |
| ----------------- | ----------------- |
| Ordering          | Heap-based        |
| Default Heap Type | Max-heap          |
| Default Container | `std::vector`     |
| Iterators         | Not supported     |
| Top Access        | `top()`           |
| Type              | Container adaptor |

---

## Differences from `queue`

| `queue`            | `priority_queue`         |
| ------------------ | ------------------------ |
| FIFO ordering      | Priority-based ordering  |
| `pop_front()`      | `pop_back()` internally  |
| No sorting         | Maintains heap structure |
| Order by insertion | Order by comparator      |

---

## When to Use `priority_queue`

Use it when:

* You need fast access to the largest (or smallest) element
* You are implementing:

  * Dijkstra’s algorithm
  * Scheduling systems
  * Event simulation
  * Task prioritization

---

## Summary

* `priority_queue` ensures the highest-priority element is always accessible.
* It uses heap algorithms internally.
* The ordering depends entirely on the comparator.
* The underlying container must support random access.
