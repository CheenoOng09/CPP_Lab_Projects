# Week 8 – Third Largest Number (CP101)

This C++ program finds the third largest number in a sequence of integers and reports the index of its last occurrence. It was developed as part of CP101 Week 8 Lab to strengthen algorithmic thinking and practice comparisons, input parsing, and conditional logic.

## Problem Overview

Given a sequence of `n` integers, the task is to:
- Identify the third largest number in the list
- Report the **index (1-based)** of the **last occurrence** of that third largest number

Special conditions:
- If there is **no third largest number**, treat the third largest as the largest number, and return the index of its **last occurrence**
- All integers are 32-bit signed values
- Multiple test cases are supported

## Input Format

- The first line gives the number of test cases
- Each test case appears on its own line and contains `n + 1` integers:
  - The first integer `n` is the number of values
  - The next `n` integers are the values in the sequence

Example:
3
3 1 1 1
3 3 2 1
5 73 11 5 -2100000000 2100000000


## Output Format

For each test case, print one line starting with `#`, followed by:
- The third largest number
- The index of its **last occurrence** in the original list (1-based)

Example:
1 3
1 3
11 2


## Files Included

- `main.cpp` — C++ implementation of the third-largest number algorithm
- `Unit8- Third Largest Number.pdf` — Problem description and sample input/output

## Key Concepts

- Conditional logic for comparing numbers
- Tracking top 3 largest values with last-occurrence indices
- Handling edge cases like all values being equal
- Sorting-based and comparison-based approaches

## Technologies

- Language: C++
- Libraries: `<iostream>`, `<vector>`, `<algorithm>`

## Notes

- Program supports multiple test cases
- Indexing is 1-based (first element is index 1)
- Duplicate values and edge cases are handled as per spec
