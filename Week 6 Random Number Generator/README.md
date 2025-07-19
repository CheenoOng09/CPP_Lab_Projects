# Week 6 – Random Number Generator (CP101)

This C++ program implements a pseudo-random number generator using the Linear Feedback Shift Register (LFSR) method. It was developed as part of CP101 Week 6 Lab to gain familiarity with bitwise operations, logical right shifts, and simulating hardware-based randomness in software.

## Problem Overview

Each test case simulates a Fibonacci-style LFSR using:
- A given number of bits
- A set of tap positions (bit indices used for feedback)
- An initial seed
- A count of how many pseudo-random numbers to generate

For each step, the new bit is generated using XOR over the specified taps, followed by a logical right shift. After the specified number of values is generated, the program computes:

- The average number of times each possible value occurred
- The maximum and minimum number of occurrences
- The number of possible values that were never generated (i.e., had 0 occurrences)

## Input Format

Each test case consists of four lines:

1. Number of bits in the LFSR (e.g., 16)
2. Tap positions (e.g., `11 13 14 16 0`, where `0` ends the line)
3. Seed value as an integer
4. Number of pseudo-random numbers to generate

The first line of the input file gives the number of test cases.

Example input:
2
16
11 13 14 16 0
44257
10000
8
1 3 7 0
83
250


## Output Format

For each test case, output four values:

1. Average number of occurrences per generated number
2. Maximum number of occurrences
3. Minimum number of occurrences
4. Number of values that were never generated

Example output:
1.2207 2 1 3


## Files Included

- `main.cpp` — C++ source code implementing the LFSR-based generator
- `Unit6 - Random Number Generator.pdf` — Lab instructions and problem specification

## Key Concepts

- Binary operations (`>>`, `&`, `|`, `^`)
- XOR logic for feedback generation
- Frequency counting with arrays
- Handling variable-length LFSR registers and tap configurations
- Custom pseudo-random number generation

## Technologies

- Language: C++
- Libraries: `<iostream>`, `<vector>`, `<cmath>`, `<map>`, or other standard headers

## Notes

- All tap positions are 1-based indexing, consistent with typical LFSR bit-labeling
- Final output format must strictly follow the requirements to avoid grade deduction
