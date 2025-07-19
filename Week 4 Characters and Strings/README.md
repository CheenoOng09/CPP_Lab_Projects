# Week 4 – Runs in a String (CP101)

This C++ program analyzes repeated character sequences (called runs) within strings. It was developed as part of CP101 Week 4 Lab to practice string handling, loops, and case-insensitive comparison.

## Problem Overview

The program processes a set of strings to identify "runs." A run is defined as a maximal substring containing only one type of symbol, regardless of letter case.

For each string, the program must:
1. Count the total number of runs
2. Find the length of the longest run
3. Count how many runs share that maximum length

Requirements:
- Case-insensitive comparison (e.g., `'A'` and `'a'` are treated as the same symbol)
- Use `cin` to read strings
- Use clear and expressive variable names

## Input Format

- The first line contains an integer `n`, the number of test cases
- Each of the next `n` lines contains one string with no whitespace

Example:
2
2Aaaa443333o#
aaaaaBBBBbbAAAcc


## Output Format

For each string, print three lines:
1. Number of runs
2. Length of the longest run
3. Number of longest runs

Example Output:

6
4
2
5
5
2


## Files Included

- `main.cpp` — Source code for run detection and analysis
- `Unit 4-Characters and Strings.pdf` — Original problem statement

## Key Concepts Used

- C++ `string` and character arrays
- `tolower()` for case-insensitive comparison
- `for` loops for traversal
- `if-else` logic to manage run boundaries
- Looping through multiple test cases using integer control

## Technologies

- Language: C++
- Libraries: `<iostream>`, `<string>`, `<cctype>`

## Notes

- The program assumes no whitespace appears in the input strings
- Only relevant source files and documentation are included in this repository
