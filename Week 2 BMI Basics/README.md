# Week 2 - BMI Basics

This project is a Body Mass Index (BMI) calculator implemented in C++. It was developed as part of **CP101 Week 2 Lab Exercise** during my Computer Science studies.

## Problem Overview

The program:
- Prompts the user to enter their **weight (in kilograms)** and **height (in meters)**
- Validates that:
  - Weight is between 20kg and 200kg
  - Height is between 0.9m and 2.5m
- Calculates the BMI using the formula:

BMI = Weight / (Height * Height)


- Determines the BMI category based on the value (e.g., Normal, Overweight, Obese, etc.)
- Provides advice:
- If BMI is **unreasonably small (<10)** or **too large (>70)**, the program gives suggestions about possible height/weight corrections
- If BMI is **not in the normal range**, the program recommends how to adjust the weight to reach a normal BMI

The program continues in a loop until the user exits.

## Files Included

- `main.cpp` — C++ implementation of the BMI calculator
- `problem.pdf` — Original lab problem description provided by the instructor

## Example Output

Input weight (kg): 65.2
Input height (m): 1.73

Your weight(kg): 65.2
Your height(m): 1.73
Your BMI: 21.8
Your BMI level is normal


## Requirements

- Must follow a given C++ template using `while (testing)` and `round(...)`
- Must use at least **eight `else if` statements** to classify BMI levels
- Must strictly match the input/output format
- Use proper variable names and consistent coding style

## Technologies

- C++
- Code::Blocks or any C++-compatible IDE
- Standard Library: `<iostream>`, `<cmath>`

## Notes

- The `.exe`, `.o`, and build folders (`bin/`, `obj/`) are excluded from this repo
- Only relevant source files and the problem PDF are included
