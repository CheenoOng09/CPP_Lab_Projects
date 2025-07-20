# Week 12 – Sequential File Processing (CP101)

This C++ program demonstrates how to create, append to, and read from a sequential file. It simulates a simple client account database by storing account information into a text file. This lab was part of CP101 Week 12 and introduces file handling using `fstream`, date-time recording, and duplicate checking.

## Problem Overview

You are provided with a file named `clientFile.txt` which stores banking records. Each record contains:
- First name
- Last name
- Account balance (a `double`)
- Timestamp (seconds since Jan 1, 1970 in UTC)

### Program Behavior

The program performs the following steps:

1. **Check File Existence**
   - If `clientFile.txt` exists, display its contents.
   - Otherwise, print a message and create the file.

2. **Read New Records**
   - Repeatedly prompt the user for new entries: `first name`, `last name`, and `balance`.
   - Each entry is appended to the file only if it is **not a duplicate** (same first + last name).

3. **Display All Records**
   - After input ends (Ctrl+Z), print all records in the file including the date-time (converted from Unix timestamp).

## Function Overview

### `void createRecord(fstream &fptr, string firstN, string lastN, double actBal);`
- Adds a new record to the end of the file.
- Gets the current time and appends it with the data.
- Checks for duplicate entries using `findCopy()` before writing.

### `void displayFile(fstream &fptr);`
- Reads and displays all records from the file.
- Converts Unix timestamps into readable date-time using `ctime()`.

### `bool findCopy(fstream &fptr, string firstN, string lastN);`
- Scans the file to see if a record with the same first and last name exists.

## Input Format

User is prompted to enter: `<first_name>` `<last_name>` `<balance>`

Example:
- Lisa Lin -23
- James Liu -3


End input with `Ctrl + Z`.

## Output Format

The program prints:
- Existing content (if any)
- Prompt messages
- All records after the session, formatted like:
```sql
      Lisa             Lin     -23    Tue Dec 28 13:51:45 2021
     James             Liu      -3    Tue Dec 28 13:51:45 2021
      ...
      Number of records in the file: 7
```

## Files Included

- `main.cpp` — Program implementation with record creation and display
- `clientFile.txt` — Sample input/output data file (used across runs)
- `Unit12-Sequential Files-CreatingFile.pdf` — Lab problem description

## Key Concepts Used

- File creation and appending (`fstream`)
- Checking for duplicate records
- Using Unix timestamps and converting them to readable time
- Reading/writing from/to a text file
- File pointer manipulation with `seekg`, `seekp`, `clear()`

## Technologies

- Language: C++
- Libraries: `<fstream>`, `<iostream>`, `<ctime>`, `<iomanip>`, `<limits>`

## Notes

- The file supports a maximum of 1000 records.
- Do not modify `main()` or `displayFile()` when implementing.
- Use `clear()` to reset file stream flags before seeking or reusing the stream.
- This program is designed to be run multiple times. On subsequent runs, it should append only new, non-duplicate records.

