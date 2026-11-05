# Task 02 – Count the Work Done by a Loop

## 1. Problem Understanding

A college fest uses prime-number ticket verification to award prizes.

The original program checks every possible divisor from 2 to n-1. This requires many unnecessary operations.

An improved method checks divisors only up to the square root of n.

The number of divisions performed is counted using a variable called `checks`.

## 2. Mathematical Principle

If a number n has a divisor greater than √n, it must also have a divisor smaller than √n.

Therefore, checking divisors beyond √n is unnecessary.

Instead of using the sqrt() function, the loop condition can be written as:

`i * i <= n`

This checks divisors only up to the square root of n.

A safer alternative that avoids multiplication overflow is:

`i <= n / i`

## 3. Basic For Loop (2 to n-1)

The basic method checks every divisor from 2 to n-1.

```c
for (i = 2; i < n; i++)
{
    checks++;

    if (n % i == 0)
        return 0;
}
```

If a divisor is found, the function immediately returns 0 because the number is not prime.

If no divisor is found, it returns 1.

## 4. Improved For Loop (2 to √n)

The improved loop checks divisors only while the square of the divisor is less than or equal to n.

```c
for (i = 2; i * i <= n; i++)
{
    checks++;

    if (n % i == 0)
        return 0;
}
```

This reduces unnecessary division operations.

## 5. Improved While Loop

The same logic can be implemented using a while loop.

```c
i = 2;

while (i * i <= n)
{
    checks++;

    if (n % i == 0)
        return 0;

    i++;
}
```

The loop continues until the divisor exceeds the square root of n.

## 6. Improved Do-While Loop

```c
i = 2;

if (n == 2)
    return 1;

do
{
    checks++;

    if (n % i == 0)
        return 0;

    i++;

} while (i * i <= n);
```

A do-while loop executes at least once, so special handling is required for n = 2.

Otherwise, it would incorrectly identify 2 as a composite number.

The condition n < 2 must also be checked before entering the loop.

## 7. Prediction Before Execution

The given ticket numbers are:

97, 100, 7919 and 1000003.

The predicted results using the improved loop are:

| Ticket Number | Expected Result | Divisions |
|---:|---|---:|
| 97 | Prime | 8 |
| 100 | Not Prime | 1 |
| 7919 | Prime | 87 |
| 1000003 | Prime | 999 |

Explanation:

- 97: Divisors 2 to 9 are checked, giving 8 divisions.
- 100: Divisor 2 is found immediately, giving 1 division.
- 7919: Divisors 2 to 88 are checked, giving 87 divisions.
- 1000003: Divisors 2 to 1000 are checked, giving 999 divisions.

**Note:** The question paper's expected value of 8 for 7919 appears to be a printing error. The correct count is 87.

## 8. Effect of Changing the Loop Condition

If the improved loop condition is changed from:

`i * i <= n`

to:

`i < n`

the program checks more divisors.

For prime numbers, the division counts become:

| Ticket Number | Condition i * i <= n | Condition i < n |
|---:|---:|---:|
| 97 | 8 | 95 |
| 100 | 1 | 1 |
| 7919 | 87 | 7917 |
| 1000003 | 999 | 1000001 |

For composite numbers, the loop can still stop early when a divisor is found.

This demonstrates why checking only up to the square root is more efficient.

## 9. Inquiry – Special Cases and Overflow

### Why does do-while need special care for n = 2 and n = 3?

A do-while loop executes its body at least once.

For n = 2, checking 2 % 2 produces zero, which would incorrectly classify 2 as composite.

Therefore, n = 2 must be handled separately.

For n = 3, the first check is 3 % 2, which is not zero. The next loop condition becomes false, so 3 is correctly identified as prime.

Numbers less than 2 must also be rejected before entering the loop.

### Why can i * i <= n overflow?

For very large unsigned integers, multiplying i by itself may exceed the maximum value that the data type can store.

This can cause unsigned integer wraparound and incorrect loop behaviour.

A safer condition is:

`i <= n / i`

This avoids multiplication overflow.

## 10. Alternative Concept – Sieve of Eratosthenes

Instead of checking each ticket separately, all prime numbers up to N can be calculated in advance using the Sieve of Eratosthenes.

Steps:

1. Create an array of N+1 elements.
2. Initially mark all numbers as prime.
3. Mark 0 and 1 as non-prime.
4. Starting from 2, mark all multiples of each prime number as non-prime.
5. Continue until the square root of N.
6. The remaining unmarked numbers are prime.

### Complexity Analysis

| Method | Time Complexity | Space Complexity |
|---|---|---|
| Basic trial division | O(n) per query | O(1) |
| Improved trial division | O(√n) per query | O(1) |
| Sieve of Eratosthenes | O(N log log N) preprocessing | O(N) |
| Sieve query | O(1) per query | O(1) additional |

The sieve is more efficient when many ticket numbers need to be checked within the same fixed range because the prime results are calculated only once.

## 11. Conclusion

The improved prime-checking loop reduces unnecessary division operations by checking only up to the square root of the number.

The for, while and do-while loops can all implement the same optimized logic.

The Sieve of Eratosthenes is suitable when a large number of ticket numbers must be verified within a fixed range.

Therefore, choosing the correct loop condition improves program efficiency and reduces execution time.# Task 02 – Count the Work Done by a Loop

## 1. Problem Understanding

A college fest uses prime-number ticket verification to award prizes.

The original program checks every possible divisor from 2 to n-1. This requires many unnecessary operations.

An improved method checks divisors only up to the square root of n.

The number of divisions performed is counted using a variable called `checks`.

## 2. Mathematical Principle

If a number n has a divisor greater than √n, it must also have a divisor smaller than √n.

Therefore, checking divisors beyond √n is unnecessary.

Instead of using the sqrt() function, the loop condition can be written as:

`i * i <= n`

This checks divisors only up to the square root of n.

A safer alternative that avoids multiplication overflow is:

`i <= n / i`

## 3. Basic For Loop (2 to n-1)

The basic method checks every divisor from 2 to n-1.

```c
for (i = 2; i < n; i++)
{
    checks++;

    if (n % i == 0)
        return 0;
}
```

If a divisor is found, the function immediately returns 0 because the number is not prime.

If no divisor is found, it returns 1.

## 4. Improved For Loop (2 to √n)

The improved loop checks divisors only while the square of the divisor is less than or equal to n.

```c
for (i = 2; i * i <= n; i++)
{
    checks++;

    if (n % i == 0)
        return 0;
}
```

This reduces unnecessary division operations.

## 5. Improved While Loop

The same logic can be implemented using a while loop.

```c
i = 2;

while (i * i <= n)
{
    checks++;

    if (n % i == 0)
        return 0;

    i++;
}
```

The loop continues until the divisor exceeds the square root of n.

## 6. Improved Do-While Loop

```c
i = 2;

if (n == 2)
    return 1;

do
{
    checks++;

    if (n % i == 0)
        return 0;

    i++;

} while (i * i <= n);
```

A do-while loop executes at least once, so special handling is required for n = 2.

Otherwise, it would incorrectly identify 2 as a composite number.

The condition n < 2 must also be checked before entering the loop.

## 7. Prediction Before Execution

The given ticket numbers are:

97, 100, 7919 and 1000003.

The predicted results using the improved loop are:

| Ticket Number | Expected Result | Divisions |
|---:|---|---:|
| 97 | Prime | 8 |
| 100 | Not Prime | 1 |
| 7919 | Prime | 87 |
| 1000003 | Prime | 999 |

Explanation:

- 97: Divisors 2 to 9 are checked, giving 8 divisions.
- 100: Divisor 2 is found immediately, giving 1 division.
- 7919: Divisors 2 to 88 are checked, giving 87 divisions.
- 1000003: Divisors 2 to 1000 are checked, giving 999 divisions.

**Note:** The question paper's expected value of 8 for 7919 appears to be a printing error. The correct count is 87.

## 8. Effect of Changing the Loop Condition

If the improved loop condition is changed from:

`i * i <= n`

to:

`i < n`

the program checks more divisors.

For prime numbers, the division counts become:

| Ticket Number | Condition i * i <= n | Condition i < n |
|---:|---:|---:|
| 97 | 8 | 95 |
| 100 | 1 | 1 |
| 7919 | 87 | 7917 |
| 1000003 | 999 | 1000001 |

For composite numbers, the loop can still stop early when a divisor is found.

This demonstrates why checking only up to the square root is more efficient.

## 9. Inquiry – Special Cases and Overflow

### Why does do-while need special care for n = 2 and n = 3?

A do-while loop executes its body at least once.

For n = 2, checking 2 % 2 produces zero, which would incorrectly classify 2 as composite.

Therefore, n = 2 must be handled separately.

For n = 3, the first check is 3 % 2, which is not zero. The next loop condition becomes false, so 3 is correctly identified as prime.

Numbers less than 2 must also be rejected before entering the loop.

### Why can i * i <= n overflow?

For very large unsigned integers, multiplying i by itself may exceed the maximum value that the data type can store.

This can cause unsigned integer wraparound and incorrect loop behaviour.

A safer condition is:

`i <= n / i`

This avoids multiplication overflow.

## 10. Alternative Concept – Sieve of Eratosthenes

Instead of checking each ticket separately, all prime numbers up to N can be calculated in advance using the Sieve of Eratosthenes.

Steps:

1. Create an array of N+1 elements.
2. Initially mark all numbers as prime.
3. Mark 0 and 1 as non-prime.
4. Starting from 2, mark all multiples of each prime number as non-prime.
5. Continue until the square root of N.
6. The remaining unmarked numbers are prime.

### Complexity Analysis

| Method | Time Complexity | Space Complexity |
|---|---|---|
| Basic trial division | O(n) per query | O(1) |
| Improved trial division | O(√n) per query | O(1) |
| Sieve of Eratosthenes | O(N log log N) preprocessing | O(N) |
| Sieve query | O(1) per query | O(1) additional |

The sieve is more efficient when many ticket numbers need to be checked within the same fixed range because the prime results are calculated only once.

## 11. Conclusion

The improved prime-checking loop reduces unnecessary division operations by checking only up to the square root of the number.

The for, while and do-while loops can all implement the same optimized logic.

The Sieve of Eratosthenes is suitable when a large number of ticket numbers must be verified within a fixed range.

Therefore, choosing the correct loop condition improves program efficiency and reduces execution time.
