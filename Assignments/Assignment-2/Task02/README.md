# Task 02 – When Does Short-Circuit Evaluation Matter?

## 1. Problem Understanding

A railway ticket counter provides concessions based on the following conditions:

- The passenger must be a senior citizen AND have an eligible ticket class.
- OR the passenger must hold a valid disability card.

The disability card verification function is slow because it checks information against a server.

C uses short-circuit evaluation to avoid unnecessary function calls and improve program efficiency.

## 2. Short-Circuit Evaluation

Short-circuit evaluation means that C does not evaluate the second operand if the result can already be determined from the first operand.

### Logical AND (&&)

For the AND operator, if the first condition is false, the second condition is not evaluated.

Example:

```c
if (0 && verify_card())
```

The function `verify_card()` is not called because the first condition is false.

### Logical OR (||)

For the OR operator, if the first condition is true, the second condition is not evaluated.

Example:

```c
if (1 || verify_card())
```

The function `verify_card()` is not called because the first condition is already true.

## 3. Experiments to Demonstrate Short-Circuit Evaluation

### Experiment 1: Logical AND

```c
if (0 && check())
```

Expected result: The function is not called.

Reason: The first operand is false, so the result of AND is already false.

### Experiment 2: Logical OR

```c
if (1 || check())
```

Expected result: The function is not called.

Reason: The first operand is true, so the result of OR is already true.

### Experiment 3: Bitwise AND (&)

```c
if (0 & check())
```

Expected result: The function is called.

Reason: Bitwise AND does not use short-circuit evaluation. Both operands are evaluated.

### Experiment 4: Logical AND (&&)

```c
if (0 && check())
```

Expected result: The function is not called.

Reason: Logical AND skips the second operand when the first operand is false.

## 4. Effect of Condition Order

The original concession condition is:

```c
(senior && eligible) || verify_card()
```

If the passenger is both a senior citizen and has an eligible ticket, the first condition is true. Therefore, the server verification function is skipped.

If the first condition is false, the verification function is called.

When the order is reversed:

```c
verify_card() || (senior && eligible)
```

The verification function is called for every passenger because it is evaluated first.

### Call Count for 1,000 Passengers

Assume:

- Total passengers = 1,000
- Senior citizens with eligible tickets = 200
- Other passengers = 800

| Condition Order | Function Calls |
|---|---:|
| (senior && eligible) || verify_card() | 800 |
| verify_card() || (senior && eligible) | 1000 |

The first order reduces the number of slow server calls by 200.

Percentage reduction:

(1000 - 800) / 1000 × 100 = 20%

Therefore, placing the senior and eligible ticket conditions first reduces unnecessary server verification calls.

## 5. Difference Between & and &&

| Logical AND (&&) | Bitwise AND (&) |
|---|---|
| Performs logical AND | Performs bitwise AND |
| Uses short-circuit evaluation | Does not use short-circuit evaluation |
| May skip the second operand | Evaluates both operands |
| Returns 0 or 1 | Returns the bitwise result |

The logical operator `&&` is preferred when checking conditions because it avoids unnecessary function calls.

Similarly, logical OR (`||`) supports short-circuit evaluation, whereas bitwise OR (`|`) evaluates both operands.

## 6. Changed Condition – Audit Logging

If the verification function also records every passenger it checks in an audit log, the recommended order must be reconsidered.

Using:

```c
(senior && eligible) || verify_card()
```

will record only the passengers who reach the verification function.

It will not record passengers who already satisfy the senior citizen condition.

If every passenger must be recorded, the verification function should be called separately for every passenger.

Example:

```c
card = verify_card();
if ((senior && eligible) || card)
```

This guarantees that all passengers are checked and recorded exactly once.

Therefore, audit requirements take priority over reducing server calls.

## 7. Alternative Concept – Nested if Statements

The combined condition can be replaced with nested if statements:

```c
if (senior && eligible)
{
    printf("Concession granted");
}
else if (verify_card())
{
    printf("Concession granted");
}
else
{
    printf("No concession");
}
```

This preserves short-circuit behaviour.

The verification function is called only when the senior citizen and ticket eligibility condition is false.

### Using Non-Short-Circuit Operators

If logical operators are replaced with bitwise operators:

```c
if ((senior & eligible) | verify_card())
```

Both operands are evaluated. Therefore, the verification function is called for every passenger.

This increases the number of slow server calls.

## 8. Complexity Analysis

Let n represent the total number of passengers.

| Method | Verification Calls | Time Complexity |
|---|---:|---|
| Short-circuit condition | n - k | O(n) |
| Reversed condition | n | O(n) |
| Nested if statements | n - k | O(n) |
| Bitwise operators | n | O(n) |
| Mandatory audit logging | n | O(n) |

Here, k represents the number of passengers who satisfy both senior citizen and ticket eligibility conditions.

### Space Complexity

The space complexity is O(1) when passengers are processed individually without storing the complete passenger list.

### Analysis

- Short-circuit evaluation reduces unnecessary server calls.
- Nested if statements provide similar efficiency.
- Bitwise operators evaluate both operands and increase server calls.
- Mandatory audit logging requires every passenger to be verified.
- All approaches have O(n) overall time complexity because each passenger is processed once.

## 9. Conclusion

Short-circuit evaluation improves program efficiency by avoiding unnecessary condition checks and slow function calls.

Logical operators `&&` and `||` should be used instead of bitwise operators when evaluating logical conditions.

The cheapest or most likely false condition should generally be placed first in an AND expression, while the cheapest or most likely true condition should be placed first in an OR expression.

However, when every passenger must be recorded in an audit log, the verification function must be called for every passenger regardless of condition order.
