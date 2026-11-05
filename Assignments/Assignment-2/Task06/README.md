# Task 03 – Loops That Must Terminate: Loan Repayment Schedule

## 1. Problem Understanding

A women's self-help group provides micro-loans with a fixed monthly repayment amount and a monthly interest rate.

Every month:

1. Interest is added to the outstanding loan balance.
2. The member makes a repayment.
3. The remaining balance is calculated.
4. The process continues until the loan is fully repaid.

The program must display the monthly repayment schedule, total interest paid and the number of months required to repay the loan.

## 2. Choosing the Correct Loop

A while loop is suitable for this problem because the number of repayment months is not known in advance.

The loop continues as long as the loan balance is greater than zero.

Example:

```c
while (balance > 0)
{
    // Calculate interest and repayment
}
```

A while loop checks the condition before executing the loop body, preventing unnecessary execution when the loan is already repaid.

## 3. Termination Condition

The termination condition is:

`balance > 0`

The loop stops when the remaining balance becomes zero.

Using `balance != 0` is dangerous with floating-point values because decimal calculations may produce tiny rounding errors.

Therefore, a tolerance or an explicit assignment of zero in the final repayment is used to ensure reliable termination.

## 4. Last Month Repayment

In the final month, the remaining balance may be smaller than the fixed repayment amount.

The member should pay only the amount due instead of the full fixed repayment.

Formula:

Amount Due = Balance + Interest

Actual Repayment = Minimum of Fixed Repayment and Amount Due

New Balance = Amount Due - Actual Repayment

This prevents the program from charging more than the outstanding loan amount.

## 5. What Happens if Repayment is Smaller Than Monthly Interest?

If the repayment is smaller than or equal to the initial monthly interest, the loan cannot be fully repaid.

- If repayment is smaller than interest, the outstanding balance increases.
- If repayment equals interest, the outstanding balance remains unchanged.
- If repayment is greater than interest, the principal gradually decreases.

Therefore, the program must reject repayment amounts that are less than or equal to the initial monthly interest.

## 6. Hand Calculation and Correctness Check

Given:

- Principal = ₹10,000
- Monthly interest rate = 2%
- Fixed repayment = ₹2,000

Monthly interest = Balance × 2 / 100

| Month | Opening Balance | Interest | Repayment | Closing Balance |
|---|---:|---:|---:|---:|
| 1 | 10,000.00 | 200.00 | 2,000.00 | 8,200.00 |
| 2 | 8,200.00 | 164.00 | 2,000.00 | 6,364.00 |
| 3 | 6,364.00 | 127.28 | 2,000.00 | 4,491.28 |
| 4 | 4,491.28 | 89.83 | 2,000.00 | 2,581.11 |
| 5 | 2,581.11 | 51.62 | 2,000.00 | 632.73 |
| 6 | 632.73 | 12.65 | 645.38 | 0.00 |

Total Interest Paid = ₹645.38

Total Months = 6

The sixth repayment is reduced to ₹645.38 because the remaining amount due is smaller than ₹2,000.

## 7. Growth Investigation

The number of repayment months increases when the repayment amount approaches the monthly interest.

For a loan of ₹10,000 at 2% monthly interest:

Initial monthly interest = ₹200.

| Monthly Repayment | Number of Months |
|---:|---:|
| ₹2,000 | 6 |
| ₹500 | 26 |
| ₹250 | 82 |
| ₹201 | 268 |
| ₹200 | Cannot be repaid |
| ₹199 | Cannot be repaid |

As the repayment approaches ₹200 from above, the number of iterations increases significantly.

When repayment is equal to or below ₹200, the loan cannot be fully repaid.

## 8. Deployment Decision – Safety Limit

A maximum limit of 360 months is added to prevent an infinite loop.

If the loan is not repaid within 360 months, the program stops using the break statement.

It displays a message indicating that the repayment period has exceeded the permitted limit.

This protects the program from running indefinitely due to unsuitable repayment values or unexpected calculation problems.

## 9. Alternative Concept – Direct Loan Formula

Instead of simulating every month, the number of repayment months can be calculated using:

n = -log(1 - rP/E) / log(1 + r)

Where:

- n = Number of months
- P = Initial principal
- r = Monthly interest rate
- E = Fixed monthly repayment

This formula is valid when E is greater than rP.

The result is rounded up to the next whole month.

### Complexity Analysis

| Method | Time Complexity | Space Complexity |
|---|---|---|
| Monthly loop simulation | O(n) | O(1) |
| Direct mathematical formula | O(1) | O(1) |

### Advantages of Loop Simulation

- Displays the monthly repayment schedule.
- Calculates the actual final repayment.
- Tracks total interest paid.
- Easy to understand and verify.

### Advantages of Direct Formula

- Calculates the repayment duration without simulating every month.
- Requires fewer computational steps.
- Suitable when only the repayment duration is needed.

### Precision Problems

The direct formula uses logarithmic and floating-point calculations.

Small rounding errors may affect the calculated repayment duration.

The loop simulation also uses floating-point arithmetic, but it calculates each month's balance individually and can apply rounding rules at each payment.

## 10. Conclusion

A while loop is suitable for the loan repayment problem because the number of iterations depends on the outstanding balance.

A final adjusted repayment, a proper termination condition and a 360-month safety limit prevent overpayment and non-terminating loops.

The loop-based method is useful when a complete monthly repayment schedule is required, while the direct formula is more efficient when only the repayment duration is needed.# Task 03 – Loops That Must Terminate: Loan Repayment Schedule

## 1. Problem Understanding

A women's self-help group provides micro-loans with a fixed monthly repayment amount and a monthly interest rate.

Every month:

1. Interest is added to the outstanding loan balance.
2. The member makes a repayment.
3. The remaining balance is calculated.
4. The process continues until the loan is fully repaid.

The program must display the monthly repayment schedule, total interest paid and the number of months required to repay the loan.

## 2. Choosing the Correct Loop

A while loop is suitable for this problem because the number of repayment months is not known in advance.

The loop continues as long as the loan balance is greater than zero.

Example:

```c
while (balance > 0)
{
    // Calculate interest and repayment
}
```

A while loop checks the condition before executing the loop body, preventing unnecessary execution when the loan is already repaid.

## 3. Termination Condition

The termination condition is:

`balance > 0`

The loop stops when the remaining balance becomes zero.

Using `balance != 0` is dangerous with floating-point values because decimal calculations may produce tiny rounding errors.

Therefore, a tolerance or an explicit assignment of zero in the final repayment is used to ensure reliable termination.

## 4. Last Month Repayment

In the final month, the remaining balance may be smaller than the fixed repayment amount.

The member should pay only the amount due instead of the full fixed repayment.

Formula:

Amount Due = Balance + Interest

Actual Repayment = Minimum of Fixed Repayment and Amount Due

New Balance = Amount Due - Actual Repayment

This prevents the program from charging more than the outstanding loan amount.

## 5. What Happens if Repayment is Smaller Than Monthly Interest?

If the repayment is smaller than or equal to the initial monthly interest, the loan cannot be fully repaid.

- If repayment is smaller than interest, the outstanding balance increases.
- If repayment equals interest, the outstanding balance remains unchanged.
- If repayment is greater than interest, the principal gradually decreases.

Therefore, the program must reject repayment amounts that are less than or equal to the initial monthly interest.

## 6. Hand Calculation and Correctness Check

Given:

- Principal = ₹10,000
- Monthly interest rate = 2%
- Fixed repayment = ₹2,000

Monthly interest = Balance × 2 / 100

| Month | Opening Balance | Interest | Repayment | Closing Balance |
|---|---:|---:|---:|---:|
| 1 | 10,000.00 | 200.00 | 2,000.00 | 8,200.00 |
| 2 | 8,200.00 | 164.00 | 2,000.00 | 6,364.00 |
| 3 | 6,364.00 | 127.28 | 2,000.00 | 4,491.28 |
| 4 | 4,491.28 | 89.83 | 2,000.00 | 2,581.11 |
| 5 | 2,581.11 | 51.62 | 2,000.00 | 632.73 |
| 6 | 632.73 | 12.65 | 645.38 | 0.00 |

Total Interest Paid = ₹645.38

Total Months = 6

The sixth repayment is reduced to ₹645.38 because the remaining amount due is smaller than ₹2,000.

## 7. Growth Investigation

The number of repayment months increases when the repayment amount approaches the monthly interest.

For a loan of ₹10,000 at 2% monthly interest:

Initial monthly interest = ₹200.

| Monthly Repayment | Number of Months |
|---:|---:|
| ₹2,000 | 6 |
| ₹500 | 26 |
| ₹250 | 82 |
| ₹201 | 268 |
| ₹200 | Cannot be repaid |
| ₹199 | Cannot be repaid |

As the repayment approaches ₹200 from above, the number of iterations increases significantly.

When repayment is equal to or below ₹200, the loan cannot be fully repaid.

## 8. Deployment Decision – Safety Limit

A maximum limit of 360 months is added to prevent an infinite loop.

If the loan is not repaid within 360 months, the program stops using the break statement.

It displays a message indicating that the repayment period has exceeded the permitted limit.

This protects the program from running indefinitely due to unsuitable repayment values or unexpected calculation problems.

## 9. Alternative Concept – Direct Loan Formula

Instead of simulating every month, the number of repayment months can be calculated using:

n = -log(1 - rP/E) / log(1 + r)

Where:

- n = Number of months
- P = Initial principal
- r = Monthly interest rate
- E = Fixed monthly repayment

This formula is valid when E is greater than rP.

The result is rounded up to the next whole month.

### Complexity Analysis

| Method | Time Complexity | Space Complexity |
|---|---|---|
| Monthly loop simulation | O(n) | O(1) |
| Direct mathematical formula | O(1) | O(1) |

### Advantages of Loop Simulation

- Displays the monthly repayment schedule.
- Calculates the actual final repayment.
- Tracks total interest paid.
- Easy to understand and verify.

### Advantages of Direct Formula

- Calculates the repayment duration without simulating every month.
- Requires fewer computational steps.
- Suitable when only the repayment duration is needed.

### Precision Problems

The direct formula uses logarithmic and floating-point calculations.

Small rounding errors may affect the calculated repayment duration.

The loop simulation also uses floating-point arithmetic, but it calculates each month's balance individually and can apply rounding rules at each payment.

## 10. Conclusion

A while loop is suitable for the loan repayment problem because the number of iterations depends on the outstanding balance.

A final adjusted repayment, a proper termination condition and a 360-month safety limit prevent overpayment and non-terminating loops.

The loop-based method is useful when a complete monthly repayment schedule is required, while the direct formula is more efficient when only the repayment duration is needed.
