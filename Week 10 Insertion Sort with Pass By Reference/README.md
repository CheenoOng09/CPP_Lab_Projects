# Week 10 – Insertion Sort with Pass-by-Reference (CP101)

This C++ program performs insertion sort in **descending order** using a function that utilizes **pass-by-reference** to return extra information. It was developed as part of CP101 Week 10 Lab to demonstrate function parameters, references, and control over algorithm efficiency.

## Problem Overview

For each test case, the program:
- Sorts a list of integers in **descending order** using **insertion sort**
- Calculates the **number of element moves** made during sorting
- Identifies the **third largest value** in the original list
- Returns the **position (0-based)** of its **last occurrence**
- If a third largest number does not exist:
  - Return the second largest number
  - If that also does not exist, return the largest

All of this is done through the function:

```cpp
int insertionSort(int[], int, int&, int&);
```
Where:
- The first parameter is the array to be sorted
- The second is the number of elements
- The third returns the index of the last occurrence of the third largest value
- The fourth returns the number of moves performed during sorting
- The return value is the third largest number (or fallback value)

## Input Format
- First line: an integer `t`, the number of test cases

Each test case:
- A single line starting with an integer `n`, followed by `n` integers

Constraints:
- `1 ≤ n ≤ 100`
- Each value is a valid 32-bit signed integer

Example Input:
3
5 1 2 3 5 4
3 1 1 2
2 2 1

## Output Format
Each test case outputs two lines:
- <third_largest> <last_occurrence_index> <number_of_moves>
- <sorted_list_in_descending_order>

Example Output:
3 2 13
5 4 3 2 1
2 2 3
2 2 1
2 0 0
2 1

## Files Included
- `main.cpp` — C++ implementation of the pass-by-reference insertion sort
- `Unit10-Insertion Sort with Pass-by-reference.pdf` — Original lab instructions

## Key Concepts
- Function definition with pass-by-reference parameters
- Insertion sort algorithm in descending order
- Tracking number of shifts (moves) during sorting
- Determining third largest value with fallback handling
- Multi-test case processing

## Technologies
- Language: C++
- Libraries: `<iostream>`, `<vector>`, `<algorithm>`

## Notes
- Index of occurrence is 0-based
- If there are fewer than 3 unique values, fallback rules apply
- Move count includes only actual element assignments (not comparisons)
