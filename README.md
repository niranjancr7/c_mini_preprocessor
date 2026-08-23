# C Mini Preprocessor

A simple C-based preprocessor developed using C programming and file handling concepts.

## Features

The project performs three main preprocessing operations:

1. Comment Removal
2. Header File Inclusion
3. Macro Collection and Replacement

## Project Workflow

abc.c
↓
Comment Removal
↓
Header File Inclusion
↓
Macro Collection
↓
Macro Replacement
↓
abc.i

## Tasks

### 1. Comment Removal

This task removes comments from the input C program.

It handles:

- Single-line comments `//`
- Multi-line comments `/* */`

### 2. Header File Inclusion

This task identifies header file inclusion statements such as:

#include <stdio.h>
#include "my_header.h"

The corresponding header file is opened and its contents are included in the intermediate file.

### 3. Macro Collection and Replacement

The project identifies `#define` statements and collects the macro names and their corresponding values using dynamic memory allocation.


## Technologies Used

- C Programming
- File Handling
- String Handling
- Dynamic Memory Allocation
- GCC Compiler

## Project Files

| File | Description |
|---|---|
| `main.c` | Controls the overall preprocessing flow |
| `comments_removal.c` | Implements comment removal |
| `headerfile_inclusion.c` | Implements header file inclusion |
| `macro_replacement.c` | Implements macro collection and replacement |
| `header.h` | Contains function declarations |
| `my_header.h` | User-defined header file |
| `abc.c` | Sample input C program |
| `README.md` | Project documentation |
| `.gitignore` | Specifies files that should not be uploaded |

## Compilation

Compile the project using GCC:

gcc main.c comments_removal.c headerfile_inclusion.c macro_replacement.c -o my_preprocessor

## Execution

Run the preprocessor by providing the input C file:

./my_preprocessor abc.c

The preprocessed output is generated in:

abc.i

## Concepts Demonstrated

- File opening and closing
- Reading and writing files
- String manipulation
- Dynamic memory allocation 
- File pointer manipulation
- Temporary file handling

## Output

The program generates an intermediate preprocessed file named `abc.i`.

The generated executable `my_preprocessor` and intermediate file `abc.i` are excluded from the GitHub repository using `.gitignore`.

## Author

**Niranjan DN**
