# Week 11 – Function Overloading and Templates (CP101)

This C++ project demonstrates both function overloading and function templates to perform sorting operations. It was developed as part of CP101 Week 11 Lab to deepen understanding of polymorphism and code reuse with various data types.

## Problem Overview

The lab is divided into two parts:

### Part I – Function Overloading (70%)
You must write three overloaded sorting functions using the same name `sortFunc` to sort arrays in **descending order**. The supported data types are:
- `int`
- `double`
- `string` (sorted lexicographically, case-sensitive)

Required overloaded functions:
```cpp
void sortFunc(int[], int);
void sortFunc(double[], int);
void sortFunc(string[], int);
```
Each function:
- Sorts the array in descending order
- Uses the `>` operator for comparison
- Prints the sorted data, 10 elements per line

### Part II – Function Template (30%)
You must implement a function template to sort arrays of any type in ascending order:
```cpp
template <class T>
void sortFuncTempt(T anAry[], int numElm);
```
This function:
- Sorts elements in ascending order
- Should be defined before `main()`
- Should not have a separate prototype declaration

### Input Format
- First line: integer `t`, number of test cases
- Each test case consists of:
  - A line indicating the type (int, double, or string)
  - A line with the number of elements
  - One or more lines of data values

Example:
```
3
int
21
4 4 4 4 4 1 2 2 3 3 -1 -3
0 -9 -4 -3 -4 -1 1 5 4
double
14
0.1 0.5 0.4 0.2 0.4 0.2 -0.1 0.1
0.41 1.2 3.2 -1 -5 1.4
string
14
Bye Ace bike corE core bye fit Fet
kit Kitty zip Yam ulm via

```

### Output Format
- Each test case output begins with:
  ```yaml
  TEST x:
  ```
- Followed by sorted output in both descending and ascending order (10 values per line)
- `sortFunc()` is used for descending
- `sortFuncTempt()` is used for ascending

Example Output:
```yaml
TEST 1:
# 5 4 4 4 4 4 4 3 3 2
# 2 1 1 0 -1 -1 -3 -3 -4 -4
# -9
# -9 -4 -4 -3 -3 -1 -1 0 1 1
# 2 2 3 3 4 4 4 4 4 4
# 5

TEST 2:
# 3.2 1.4 1.2 0.5 0.41 0.4 0.4 0.2 0.2 0.1
# 0.1 -0.1 -1 -5
# -5 -1 -0.1 0.1 0.1 0.2 0.2 0.4 0.4 0.41
# 0.5 1.2 1.4 3.2

TEST 3:
# zip via ulm kit fit core corE bye bike Yam
# Kitty Fet Bye Ace
# Ace Bye Fet Kitty Yam bike bye corE core fit
# kit ulm via zip

```
### Files Included
- `main.cpp` — C++ implementation of overloaded functions and templates
- `Problem.pdf` — Problem specification and instructions

### Key Concepts
- Function overloading for type-specific logic
- Function templates for reusable sorting logic
- Array manipulation with both built-in and user-defined types
- Lexicographic sorting using string comparisons

### Technologies
- Language: C++
- Libraries: `<iostream>`, `<string>`, `<iomanip>`

### Notes
- All sorting code must be handwritten (no STL sort)
- Template functions must be defined before `main()`
- Sorting output must show 10 items per line for clarity
