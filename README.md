# Fenwick Tree (Binary Indexed Tree)

This repository contains a simple C++ implementation of the Fenwick Tree
(Binary Indexed Tree) data structure, supporting efficient prefix sum queries
and point updates.

## Description
The Fenwick Tree allows both update and query operations to be performed
in logarithmic time, making it more efficient than a simple array-based approach
for cumulative sum calculations.

## Example
Given an integer array, the structure can efficiently:
- Compute prefix sums
- Answer range sum queries
- Apply point updates

## Implementation Details
- Uses a 1-based indexing system internally
- Applies bit manipulation (`idx & -idx`) to traverse the tree
- Separates data structure logic from example usage in `main`

## Technical Information
- Language: C++
- Time Complexity: O(log n) for update and query
- Space Complexity: O(n)

## Run
```bash
g++ fenwick_tree.cpp -o fenwick
./fenwick
