# Data Structures & Algorithms in C++

**Original Repository:** [mrkshreyash/data-structures-and-algorithms-in-cpp](https://github.com/mrkshreyash/data-structures-and-algorithms-in-cpp)

## Overview

This project is a collection of fundamental Data Structures and Algorithms (DSA) implemented in C++. It aims to provide educational, beginner-friendly code examples of widely-used concepts like:

- Recursion (e.g., Fibonacci, Factorial, Tower of Hanoi)
- Linked Lists (Singly, Doubly, Circular)
- Stacks (Array-based, Linked List-based)

The project is ideal for:

- DSA learners looking to explore implementation from scratch.
- Developers preparing for technical interviews.
- Contributors interested in extending functionality or improving readability.

---

## Installation & Setup

1. Clone the repository

```bash

git clone https://github.com/mrkshreyash/data-structures-and-algorithms-in-cpp.git
cd data-structures-and-algorithms-in-cpp
```

2. Environment & Dependencies

- A C++ compiler like `g++` or any IDE (e.g., Code::Blocks, Dev C++, VS Code)
- Recommended: C++11 or higher for compatibility
- No external libraries are required — all programs use standard C++
- No external libraries required

---

## Topic-wise Content

### [CHAPTER 02 – RECURSION](https://github.com/mrkshreyash/data-structures-and-algorithms-in-cpp/tree/main/CHAPTER%2002%20-%20RECURSION)

<table border="1" cellspacing="0" cellpadding="6">
  <thead>
    <tr>
      <th>No.</th>
      <th>File</th>
      <th>Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td><code>Fibonacci series.cpp</code></td>
      <td>
        Implements a recursive function to calculate the Nth Fibonacci number.
        Useful for understanding how recursion handles repeated calculations and
        grows with time complexity.
      </td>
    </tr>
    <tr>
      <td>2</td>
      <td><code>Factorial.cpp</code></td>
      <td>
        A basic example of recursion in mathematics: calculates factorial
        (<code>n!</code>) by multiplying <code>n * (n-1) * (n-2)...</code> until
        <code>1</code>. Great intro to base and recursive cases.
      </td>
    </tr>
    <tr>
      <td>3</td>
      <td><code>Tower of Hanoi.cpp</code></td>
      <td>
        Classic problem used to teach recursion and problem breakdown: move
        disks between rods following strict rules. This file shows the logic to
        solve it recursively and print each move.
      </td>
    </tr>
  </tbody>
</table>

---

### [CHAPTER 03 – LINKED LIST](https://github.com/mrkshreyash/data-structures-and-algorithms-in-cpp/tree/main/CHAPTER%2003%20-%20LINKED%20LIST)

<table border="1" cellspacing="0" cellpadding="6">
  <thead>
    <tr>
      <th>No.</th>
      <th>File</th>
      <th>Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td><code>Singlylinkedlist.cpp</code></td>
      <td>
        Implements a singly linked list with operations like insertion,
        deletion, and traversal. Each node has one pointer (to next node). Good
        for basic memory management.
      </td>
    </tr>
    <tr>
      <td>2</td>
      <td><code>Doublylinkedlist.cpp</code></td>
      <td>
        Implements a doubly linked list, where each node has two pointers — one
        to the next and one to the previous. Allows bidirectional traversal, and
        easier deletion.
      </td>
    </tr>
    <tr>
      <td>3</td>
      <td><code>Circularlinkedlist.cpp</code></td>
      <td>
        Demonstrates a circular linked list where the last node points back to
        the first, forming a loop. Includes insertion and deletion at various
        positions. Used in buffering, round-robin scheduling, etc.
      </td>
    </tr>
  </tbody>
</table>

---

### [CHAPTER 04 – STACKS](https://github.com/mrkshreyash/data-structures-and-algorithms-in-cpp/tree/main/CHAPTER%2004%20-%20STACKS)

<table border="1" cellspacing="0" cellpadding="6">
  <thead>
    <tr>
      <th>No.</th>
      <th>File</th>
      <th>Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td><code>Simplearraybasedstack.cpp</code></td>
      <td>
        Implements a stack using a fixed-size array. Covers <code>push()</code>,
        <code>pop()</code>, <code>peek()</code> operations. Great for learning
        the basics of stack behavior and overflow/underflow conditions.
      </td>
    </tr>
    <tr>
      <td>2</td>
      <td><code>Dynamicarraybasedstack.cpp</code></td>
      <td>
        Uses C++ STL vectors to create a stack that grows as needed (no size
        limit). This file shows how to handle stack operations using built-in
        dynamic memory features.
      </td>
    </tr>
    <tr>
      <td>3</td>
      <td><code>Linkedlistbasedstack.cpp</code></td>
      <td>
        Builds a stack using linked list nodes. Each <code>push</code> operation
        adds a new node to the top; <code>pop</code> removes it. Helps you
        understand how dynamic memory management works without arrays.
      </td>
    </tr>
  </tbody>
</table>

---

### [CHAPTER 05 – QUEUES](https://github.com/mrkshreyash/data-structures-and-algorithms-in-cpp/tree/main/CHAPTER%2005%20-%20QUEUES)

<table border="1" cellspacing="0" cellpadding="6">
  <thead>
    <tr>
      <th>No.</th>
      <th>File</th>
      <th>Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td><code>SimpleCircularQueue.cpp</code></td>
      <td>
        Circular queue with fixed array size.
      </td>
    </tr>
    <tr>
      <td>2</td>
      <td><code>	DynamicCircularQueue.cpp</code></td>
      <td>
        Dynamically resizing circular queue using <code>vector</code>.
      </td>
    </tr>
    <tr>
      <td>3</td>
      <td><code>LinkedListQueue.cpp</code></td>
      <td>
        Queue implemented with linked list (front-rear).
      </td>
    </tr>
  </tbody>
</table>

---

### [CHAPTER 06 – BINARY TREES](https://github.com/mrkshreyash/data-structures-and-algorithms-in-cpp/tree/main/CHAPTER%2006%20-%20TREES)

<table border="1" cellspacing="0" cellpadding="6">
  <thead>
    <tr>
      <th>No.</th>
      <th>File</th>
      <th>Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td><code>BinaryTreeTraversal.cpp</code></td>
      <td>
        Builds a binary tree using user input and supports </br> Preorder, Inorder, and Postorder traversals.
      </td>
    </tr>
  </tbody>
</table>

---
## Contributing Guidelines

We welcome contributions from developers and learners alike!

### How to Contribute

- Fork the repository and clone it to your machine
- Create a new branch for your feature or fix
- Follow the existing naming and commenting conventions
- Make your changes and commit them with meaningful messages.
- Push and open a Pull Request with a clear description of your contribution

### Code Standards

- Use meaningful variable/function names
- Keep your code modular and well-commented
- Ensure your code compiles without errors

### Example Pull Request

- Title: `Added Circular Queue Implementation in C++`
- Description: `Implements circular queue using arrays under Chapter 05 - Queues. Fixes issue #4`

---

## Acknowledgements

Thanks to the owner of this repository and future contributors!  
This project is inspired by the need for clean, beginner-friendly C++ examples of core data structures.
