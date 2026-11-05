# Task 2 – Read and Print Data Correctly

## Objective
To read user input safely, validate it using `scanf()`, and display monetary values correctly.

## Format Specifiers
- `%d` – `int`
- `%u` – `unsigned int`
- `%ld` – `long int`
- `%lld` – `long long int`
- `%f` – `float` with `printf()`; `float` input with `scanf()`
- `%lf` – `double` input with `scanf()`
- `%c` – character
- `%s` – string

Using an incorrect format specifier can cause incorrect output or undefined behaviour. For example, `%ld` must be used to print a `long` integer.

## Input Validation
The condition `scanf("%d", &units) != 1` checks whether an integer was successfully read. If the input is invalid, the program displays an error message and terminates.

Negative units are rejected because electricity consumption cannot be negative.

## Rupees and Paise
The bill is stored as integer paise. Dividing by 100 gives rupees, while the remainder gives paise. The format `%02ld` ensures two digits are printed for the paise portion.

## Alternative Approach: fgets() and strtol()
Using `fgets()` to read a complete line and `strtol()` to convert it provides better control over invalid input and recovery. Processing a line of length L takes O(L) time and requires O(L) buffer space. Direct `scanf()` is simpler but may leave invalid characters in the input stream.

## Complexity
The demonstrated program uses O(1) time and O(1) auxiliary space for its fixed-size input and output operations, excluding external input/output costs.

## Result
The program accepts valid integer input, rejects invalid and negative input, and displays the bill in rupees and paise.
