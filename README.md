# Binary Tree Study Guide  
---

## About This Project

This project is a **C++ implementation of a Binary Search Tree (BST)**, focused on clarity, correctness, and testability. It was created as part of a **service learning project** to help teach lower-division students foundational data structures.

Included are:

- A fully templated, reusable `BST` class  
- Support for insertion, search, and deletion operations  
- Recursive implementations of in-order, pre-order, and post-order traversal  
- Comprehensive unit tests written using the **Google Test (GTest)** framework  

The unit tests verify:

- Correctness of insert, search, and removal logic  
- Handling of edge cases (e.g., removing root, leaf, one-child, or non-existent nodes)  
- Tree behavior under sorted or unbalanced insertions  
- Full clear and root replacement scenarios  

---

## What is a Binary Search Tree?

A **Binary Search Tree (BST)** is a hierarchical data structure where each node follows these rules:

1. **Left child < Parent**
2. **Right child > Parent**

This ordering allows for efficient searching, inserting, and deleting of data.

---

## Why Use a Binary Search Tree?

Binary search trees allow for:
- **Insert**: O(log N) best case, O(N) worst case  
- **Search**: O(log N) best case, O(N) worst case  
- **Delete**: O(log N) best case, O(N) worst case  

> Note: Worst-case performance happens when the tree becomes unbalanced (e.g., like a linked list). A balanced tree ensures logarithmic performance.

---

## Why Logarithms?

Operations on BSTs follow binary search logic — halving the search space — which leads to logarithmic time complexity.  
For example, searching in a balanced tree with 1 trillion nodes takes roughly **40 steps**.

---

## Recursion and Trees

Recursion and trees naturally complement each other.  
Recursive function calls form a **recursion tree**, mirroring how binary trees are traversed and processed.

---

## C++ Implementation of BST

### Node Structure

We define a simple `struct` for a tree node with:
- A value
- Left and right children (pointers)

---

## Insertion

### Pseudocode for Insert:

```text
FUNCTION INSERT(node, value):
    IF node IS null:
        RETURN new node with value

    IF value < node.value:
        node.left = INSERT(node.left, value)

    ELSE IF value > node.value:
        node.right = INSERT(node.right, value)

    ELSE:
        // value already exists — do nothing or handle duplicates

    RETURN node
```


---

## Search

### Pseudocode for Search:

```text
FUNCTION SEARCH(node, target):
    IF node IS null:
        RETURN null

    IF target < node.value:
        RETURN SEARCH(node.left, target)

    ELSE IF target > node.value:
        RETURN SEARCH(node.right, target)

    ELSE:
        RETURN node.value
```

---

## Deletion

We must handle 3 cases:
1. Node has **no children** — delete it directly  
2. Node has **one child** — point the parent to the child  
3. Node has **two children** — find the **in-order successor**, replace, and remove

### Pseudocode for Finding the Minimum

```text
FUNCTION FIND_MINIMUM(node):
    WHILE node.left IS NOT null:
        node = node.left
    RETURN node
```

---

### Pseudocode for Removal (High-Level Steps)

1. Locate the node  
2. If it has two children, find the minimum in the right subtree  
3. Replace the node’s value with the minimum  
4. Recursively delete that minimum node  

---

## Tree Traversals

Common ways to walk a binary tree:

- **In-order** (Left → Root → Right) — gives sorted values  
- **Pre-order** (Root → Left → Right) — useful for tree copying  
- **Post-order** (Left → Right → Root) — useful for deletion  
- **Level-order** (Breadth-first traversal — not covered here)

---

### In-Order Traversal

```text
FUNCTION IN_ORDER(node):
    IF node IS null:
        RETURN
    IN_ORDER(node.left)
    VISIT(node.value)
    IN_ORDER(node.right)
```

---

### Pre-Order Traversal

```text
FUNCTION PRE_ORDER(node):
    IF node IS null:
        RETURN
    VISIT(node.value)
    PRE_ORDER(node.left)
    PRE_ORDER(node.right)
```

---

### Post-Order Traversal

```text
FUNCTION POST_ORDER(node):
    IF node IS null:
        RETURN
    POST_ORDER(node.left)
    POST_ORDER(node.right)
    VISIT(node.value)
```

---