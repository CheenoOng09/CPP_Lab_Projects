# Week 9 – String Without Three Consecutive Same Symbols (CP101)

This C++ program removes consecutive duplicate characters in a string if a run of the same symbol appears more than twice. It was developed as part of CP101 Week 9 Lab to reinforce string processing, case-insensitive comparison, and character-by-character analysis.

## Problem Overview

Given a string with no whitespace, the task is to create a new string in which:
- Any **run** (a group of repeating same symbols) is shortened to **at most two** characters
- Upper-case and lower-case letters are treated as the **same symbol**
- All other characters (symbols, digits, etc.) are treated **literally**, but are still considered for run grouping if repeated

The goal is to suppress long repetitions while preserving the overall order and structure.

## Input Format

- The first line contains an integer `t`, the number of test cases
- Each of the next `t` lines contains a string `S`
- String length is guaranteed to be between 1 and 100

Example:
5
AABABBBBBBBBBBABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBA
AaAAabBbC
T557$&*(000)))))(()KikkKiILmn
*****&&&&#$&&&GgggHhFAaaaaBBBA
1123333654GgggYT&JJJGJJjJJJJJJJJJJJKNjkMmMMMMMMMMmmmmMMMMMMMmMMMMmMMMmmM


## Output Format

For each test case, print one line containing the transformed string where:
- No run has more than 2 of the same symbol (case-insensitive)

Example Output:
AABABBABBA
AabBC
T557$&*(00))(()KikkiILmn
**&&#$&&GgHhFAaBBA
11233654GgYT&JJGJJKNjkMm


## Files Included

- `main.cpp` — C++ implementation of the run-reduction transformation
- `Unit9-CPE Tips-At most three letters.pdf` — Problem specification and CPE context

## Key Concepts

- Character classification using `tolower()` or `toupper()`
- Tracking run length of case-insensitive characters
- Building a new output string conditionally
- No use of STL containers required; character-by-character logic is sufficient

## Technologies

- Language: C++
- Libraries: `<iostream>`, `<string>`, `<cctype>`

## Notes

- Case insensitivity means that 'A', 'a', and 'A' are all part of the same run
- Symbols such as `$`, `*`, `&`, etc., are handled normally and grouped if repeated
- This problem simulates logic similar to Lab 4's "Runs in a String"
