# Task01 – Diagnose, Redesign and Validate

## Selected Program: Prime Number Checking

### A. Diagnose the Bottleneck (2 Marks)

The original prime-checking program tests every divisor from 2 to n-1.

The main bottleneck is the repeated modulo operation:

`n % i == 0`

For large prime numbers, the program checks almost every possible divisor before determining that the number is prime.

Evidence from the original program:

| Ticket Number | Original Divisions |
|---:|---:|
| 97 | 95 |
| 100 | 1 |
| 7919 | 7917 |
| 1000003 | 1000001 |

For the ticket number 1,000,003, the program performs 1,000,001 divisibility tests.

This shows that the number of operations increases significantly with the input size.

The main limitation is unnecessary repeated divisor checking.

### B. Define the Design Objective (2 Marks)

The objective is to reduce the number of divisibility tests while maintaining correct prime-number detection.

The redesigned program should:

- Skip divisors that cannot be prime factors.
- Reduce the number of modulo operations.
- Maintain correct results for prime and composite numbers.
- Avoid unnecessary memory usage.

**Measurable objective:**

Reduce the number of divisibility tests for 1,000,003 from 999 in the square-root method to approximately 334 in the redesigned method.

This represents an expected reduction of approximately 66.57%.

### C. Design the Revised Solution (4 Marks)

The redesigned program uses the mathematical property that every prime number greater than 3 is of the form:

`6k - 1` or `6k + 1`

Examples:

5, 7, 11, 13, 17, 19, 23, 25...

After checking divisibility by 2 and 3, the program only checks possible divisors in the form 6k ± 1.

**Steps in the redesigned algorithm:**

1. If n is less than 2, return not prime.
2. If n is 2 or 3, return prime.
3. Check whether n is divisible by 2 or 3.
4. Start checking possible divisors from 5.
5. Check divisors i and i+2.
6. Increase i by 6.
7. Continue only while the divisor is within the square root of n.
8. If a divisor is found, return not prime.
9. Otherwise, return prime.

**Pseudocode:**

```text
START

Read n

If n < 2
    Return NOT PRIME

If n = 2 or n = 3
    Return PRIME

If n is divisible by 2 or 3
    Return NOT PRIME

Set i = 5

WHILE i * i <= n
    Check n % i
    If divisible
        Return NOT PRIME

    Check n % (i + 2)
    If divisible
        Return NOT PRIME

    i = i + 6

Return PRIME

STOP
```

**Memory requirement:**

The redesigned algorithm uses only a few variables and does not require an additional array.

Therefore, its auxiliary space complexity is O(1).

**Trade-off:**

The 6k ± 1 method is slightly more complex to understand and implement than the basic square-root method. However, it reduces unnecessary modulo operations.

### D. Predict Before Implementing (1 Mark)

The redesigned method is expected to reduce the number of divisibility tests by approximately one-third compared with the square-root method for large prime numbers.

Predicted results:

| Ticket Number | Square-Root Method | Redesigned Method |
|---:|---:|---:|
| 97 | 8 | 4 |
| 100 | 1 | 1 |
| 7919 | 87 | 30 |
| 1000003 | 999 | 334 |

For 1,000,003:

Reduction = 999 - 334 = 665 tests.

Percentage reduction:

(665 / 999) × 100 = 66.57%

### E. Implement and Validate the Redesign (2 Marks)

The original, square-root and redesigned algorithms are tested using the same ticket numbers.

Observed results:

| Ticket Number | Original | Square-Root | Redesigned |
|---:|---:|---:|---:|
| 97 | 95 | 8 | 4 |
| 100 | 1 | 1 | 1 |
| 7919 | 7917 | 87 | 30 |
| 1000003 | 1000001 | 999 | 334 |

All three methods produce the same prime or composite classification.

The redesigned method reduces the number of modulo operations significantly.

For 1,000,003, the original method performs 1,000,001 tests, while the redesigned method performs only 334 tests.

Percentage reduction compared with the original:

((1000001 - 334) / 1000001) × 100 = approximately 99.97%.

### F. Defend the Final Design (2 Marks)

The redesigned algorithm achieves the objective of reducing unnecessary divisibility tests.

For the large prime number 1,000,003:

- Original method: 1,000,001 tests.
- Square-root method: 999 tests.
- Redesigned method: 334 tests.

The redesigned method performs approximately 66.57% fewer tests than the square-root method.

**Advantages:**

- Reduces unnecessary modulo operations.
- Maintains correct prime-number classification.
- Requires constant auxiliary memory.
- Suitable for checking large individual ticket numbers.

**Limitations:**

- The
