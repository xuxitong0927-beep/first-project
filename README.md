# Top K Frequent Elements (C)

## Problem
Find the K most frequent elements from N integers.

## Approach
- Hash table
- Min heap

## Example
Input:
8 2
1 1 1 2 2 3 4 5

Output:
1 2

## What I learned
- Combining data structures

## How to Run
gcc main.c -o main
./main

## Complexity
Time: O(N log K)
Space: O(N)

This project uses a hash table to count frequencies and a min-heap to efficiently maintain the top K elements.
