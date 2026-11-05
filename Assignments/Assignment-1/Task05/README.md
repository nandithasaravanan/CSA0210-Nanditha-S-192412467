# Task 1 – Organise the Program with Header Files and Conditional Compilation

## 1. Objective
To organise the electricity-billing program using a header file, include guards, function prototypes, and conditional compilation for debugging.

## 2. Structure of a C Program
The program uses `billing.h` to store tariff constants and the `compute_bill()` function prototype. The `main.c` file contains the function implementation and `main()`, which tests the billing calculations.

## 3. Include Guards
The directives `#ifndef`, `#define`, and `#endif` prevent the same header file from being processed repeatedly within one translation unit. This avoids duplicate declaration problems.

## 4. Conditional Compilation
The `#ifdef DEBUG` directive includes debug statements only when `DEBUG` is defined during compilation. Compiling with `gcc -DDEBUG` enables the messages; compiling without it excludes them.

## 5. Angle Brackets and Double Quotes
- `#include <stdio.h>` searches the implementation's standard header locations for the standard library header.
- `#include "billing.h"` typically searches the source file's directory first, then other implementation-defined locations.

## 6. Alternative: Run-Time Debugging
An alternative is to use a run-time variable, such as `if (debug) printf(...)`. This allows debugging to be enabled or disabled while the program runs without recompilation.

However, the condition must be checked whenever execution reaches the debug statement. The executable generally retains the debug-printing code and its associated strings, even when debugging is disabled.

With `#ifdef DEBUG`, the debug statements are excluded during preprocessing when `DEBUG` is not defined. This can reduce executable code size and eliminates run-time checks for those statements.

Both approaches have constant time overhead per debug check when reached. The actual execution cost depends on the compiler and whether the branch is taken. With compile-time debugging disabled, there is no run-time cost from the excluded debug statements.

## 7. Complexity Analysis
The billing calculation performs a fixed number of operations per household, giving **O(1)** time per bill. Processing `n` households takes **O(n)** time. The calculation uses **O(1)** auxiliary space per household, excluding storage for the input records.

## 8. Result
The program was organised into a header and source file. Include guards protect the header, and conditional compilation enables debug output only when compiled with `-DDEBUG`.
