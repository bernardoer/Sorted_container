# Sorted Class in C++

## Project Overview

This project implements a C++ class named **`Sorted`** that maintains a collection of elements sorted dynamically as they are added during the program execution. The goal is to efficiently manage the collection and provide fast access to key properties such as minimum, maximum, and size.

## Features

- **Constructor**: Initialize the `Sorted` class from a `std::vector` of elements.
- **push**: Insert a new element into the sorted structure. The insertion method guarantees an algorithmic complexity strictly less than *O(n)*, where *n* is the current number of elements.
- **size**: Retrieve the number of elements currently stored.
- **min / max**: Retrieve the minimal and maximal elements from the collection.
- **Output stream operator (`<<`)**: Overloaded to allow easy display and debugging of the stored elements.
- **vect**: Generate and return a sorted `std::vector` representation of the stored elements.
- **Memory Management**: Ensures no memory leaks through proper destruction of internal data structures.

## Implementation Details

The `Sorted` class uses a Binary Search Tree (BST) internally to maintain the sorted order with efficient insertion and traversal operations.
