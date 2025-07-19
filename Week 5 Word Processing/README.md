# Week 5 – Word Processing (CP101)

This C++ program performs statistical analysis on words read from keyboard input. It was developed as part of CP101 Week 5 Lab to practice string handling, character classification, loops, arrays, and logical operations.

## Problem Overview

The program reads a stream of input words until the user ends the input using `Ctrl + Z`. A word is defined as a sequence of symbols separated by space, tab, or newline.

For each valid word, the program calculates:
- The total number of words that contain at least one letter
- The number of words whose **first letter** is a vowel (case-insensitive)
- The number of words that contain **at least one letter that repeats**
- A distribution of words by **word length** (only letters are counted; lengths > 15 are grouped as 15)
- A distribution of words by their **first letter** (case-insensitive)

## Input Format

- An unknown number of words typed from keyboard
- Input ends when the user presses `Ctrl + Z` followed by Enter (on Windows)

Example input:

This is a java program to implement monoalphabetic cypher.
eve ada Noun rear Sears pop kick Sos
ab aB cD Ef gh IJ KL Mn op Qr St UV wx YZ


## Output Format

The program prints statistics in the following format:

Total number of words which has at least a letter: 189
Total number of words whose first letter is a vowel: 49
Total number of words which contain some letter repeated at least twice: 67
Distribution of words by word length:
L0 = 0
L1 = 9
L2 = 66
...

L15 = 2
Distribution of words by first letter:
A/a: 18
B/b: 4
C/c: 8
...

Z/z: 5


## Files Included

- `main.cpp` — C++ implementation of the word analyzer
- `Unit5-Words-distribution.pdf` — Original lab problem description and instructions

## Key Concepts

- Input parsing with `cin >> word`
- Use of `isalpha()`, `tolower()`, and arrays to count and classify
- Handling dynamic input using a loop until `cin.eof()`
- Mapping characters to array indices for counting

## Technologies

- Language: C++
- Libraries: `<iostream>`, `<string>`, `<cctype>`, `<algorithm>`

## Notes

- Only alphabetic characters are considered when analyzing letter-based properties
- Words without any letters are skipped from the statistics
- The implementation assumes clean console input
