# Week 3 – BMI Level Distribution (CP101)

This C++ program calculates and classifies Body Mass Index (BMI) levels for multiple data sets. It was developed as part of CP101 Week 3 Lab to practice iteration, conditionals, arrays, and switch statements.

## Problem Overview

The program repeatedly:
1. Accepts input of weight and height pairs from the user.
2. Stops reading when any value is 0 or below.
3. For valid data sets:
   - Calculates BMI using the formula:

     ```
     BMI = weight / (height * height)
     ```

   - Categorizes the BMI into one of 10 levels:
     - USL, HSUW, SUW, UW, NW, OW, OB, SOB, HSOB, ULL
   - Increments the count for the corresponding BMI level.

4. At the end, it displays:
   - Names of the BMI levels
   - Number of people in each level (aligned under each label using `setw`)
   - Total number of valid data sets (head count)
   - The level(s) with the highest count

## Files Included

- `main.cpp` — Source code for the BMI distribution calculator
- `Unit3-BMI-While-RB.pdf` — Problem specification and lab instruction file

## Key Requirements

- Input validation:
  - Weight must be between 20 kg and 200 kg
  - Height must be between 0.9 m and 2.5 m
- Invalid data sets are ignored
- Uses:
  - At least one `while` loop
  - Two `for` loops
  - A `switch` statement
  - An integer array `disBMI[10]` for storing category counts
- Follow output formatting exactly (align numbers under labels using `setw()`)

## Example Input
56 1.5
27 0.93
200 2.4
0 0


## Example Output
USL   HSUW  SUW   UW   NW   OW   OB   SOB   HSOB   ULL
0     1     0     0    2    0    0    0     0      0

Head count = 3
Maximum category: NW


## Technologies

- Language: C++
- IDE: Code::Blocks / VSCode / g++
- Libraries: `<iostream>`, `<iomanip>`, `<cmath>`

## Notes

- Object files and executable binaries are excluded
- Only clean source code and lab instructions are included

