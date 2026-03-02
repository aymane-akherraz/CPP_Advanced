# STL Container Adaptors

## Overview

In **STL terminology**, a **container adaptor** is a class that uses an existing STL container to provide a different interface or additional functionality.

Rather than implementing a completely new data structure from scratch, a container adaptor:

* Wraps an existing sequential container
* Restricts or modifies its interface
* Provides specialized behavior (such as stack or queue operations)

Container adaptors do **not** provide iterators like regular containers. Instead, they expose only specific operations related to their purpose.

---

## Purpose

Container adaptors are used to create common abstract data structures such as:

* **Stacks**
* **Queues**
* **Priority Queues**

They internally rely on standard sequential containers like:

* `std::vector`
* `std::deque`
* `std::list`

---

## Types of STL Container Adaptors

The STL provides **three container adaptors**:

### 1. `std::stack`

Implements a **Last-In, First-Out (LIFO)** data structure.

* Elements are added and removed from the top.
* Common operations:

  * `push()`
  * `pop()`
  * `top()`

---

### 2. `std::queue`

Implements a **First-In, First-Out (FIFO)** data structure.

* Elements are added at the back.
* Elements are removed from the front.
* Common operations:

  * `push()`
  * `pop()`
  * `front()`
  * `back()`

---

### 3. `std::priority_queue`

Implements a queue where elements are ordered by priority.

* The largest (by default) element is always accessible.
* Internally uses a heap structure.
* Common operations:

  * `push()`
  * `pop()`
  * `top()`

---

## Key Characteristics

* ✔ Built on top of existing STL containers
* ✔ Provide restricted interfaces
* ✔ Designed for specific data structure behavior
* ❌ Do not support iteration
* ❌ Do not expose the underlying container directly

---

## Summary

Container adaptors in STL allow developers to easily use:

* A **stack**
* A **queue**
* A **priority queue**

without manually implementing these data structures.

They provide specialized behavior by adapting existing sequential containers, making them efficient and easy to use.

![Container adaptors](../imgs/Container_adaptors.png)
