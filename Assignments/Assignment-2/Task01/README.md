# Q1 – Precedence, Associativity and the Discount Bug
# Name : Nanditha S    Reg.no:192412467

## 1. Problem Understanding

The Jan Aushadhi Pharmacy calculates the bill using the following rules:

- Gross amount = Price × Quantity
- Senior citizens receive a 15% discount.
- GST of 5% is added to the amount after discount.
- An additional ₹50 discount is given if the total exceeds ₹1000.

The original program uses a single expression without proper brackets, which can cause incorrect calculations due to operator precedence and integer division.

## 2. Predictions Before Execution

Three test cases are selected:

| Test Case | Price | Quantity | Senior |
|---|---:|---:|---:|
| 1 | 100 | 2 | 1 |
| 2 | 500 | 2 | 0 |
| 3 | 250 | 4 | 1 |

Assuming all variables in the original expression are integers:

### Case 1: Price = 100, Quantity = 2, Senior = 1

Original expression:

total = 100 * 2 - 100 * 2 * 15 / 100 * 1 + 100 * 2 * 5 / 100

Evaluation:

- 100 * 2 = 200
- 200 * 15 = 3000
- 3000 / 100 = 30
- 30 * 1 = 30
- 200 * 5 = 1000
- 1000 / 100 = 10
- Total = 200 - 30 + 10 = 180

**Predicted Total = ₹180**

Since the total is below ₹1000, Net = ₹180.

### Case 2: Price = 500, Quantity = 2, Senior = 0

- Gross amount = 500 * 2 = 1000
- Discount = 1000 * 15 / 100 * 0 = 0
- GST = 1000 * 5 / 100 = 50
- Total = 1000 - 0 + 50 = 1050
- Net = 1050 - 50 = 1000

**Predicted Total = ₹1050**

**Predicted Net = ₹1000**

### Case 3: Price = 250, Quantity = 4, Senior = 1

- Gross amount = 250 * 4 = 1000
- Discount = 1000 * 15 / 100 = 150
- GST = 1000 * 5 / 100 = 50
- Total = 1000 - 150 + 50 = 900

**Predicted Total = ₹900**

Since the total is below ₹1000, Net = ₹900.

## 3. Operator Precedence and Associativity

The original expression is:

total = price * qty - price * qty * 15 / 100 * senior + price * qty * 5 / 100;

The operators are evaluated in the following order:

1. Multiplication (*), division (/) have higher precedence than addition (+) and subtraction (-).
2. Multiplication and division have left-to-right associativity.
3. Addition and subtraction also have left-to-right associativity.
4. The comparison operator (>) is evaluated before the conditional operator (?:).
5. The conditional operator selects either total - 50 or total.

Therefore, the multiplication and division operations are performed before addition and subtraction.

## 4. Integer Division

In C, integer division removes the fractional part of the result.

Example:

int discount = 99 * 15 / 100;

Calculation:

99 * 15 / 100 = 14.85

Since integer division is used, the stored result is 14 instead of 14.85.

This can produce inaccurate pharmacy bills when percentage calculations involve decimal values.

## 5. Analysis of Incorrect Expressions

### Original total expression

The original expression calculates GST on the gross amount instead of the discounted amount.

The intended calculation is:

- Calculate gross amount.
- Subtract the senior citizen discount.
- Calculate GST on the discounted amount.
- Add GST to the discounted amount.

The original expression also uses integer arithmetic if all operands are integers, causing fractional values to be discarded.

### Net expression

net = total > 1000 ? total - 50 : total;

This expression is logically correct for the additional ₹50 discount.

However, the result depends on the accuracy of the calculated total.

### Count expression

count = count++ + 1;

This statement causes undefined behaviour in C.

The post-increment operator modifies count, and the assignment also modifies count without the required sequencing between these operations.

The compiler may produce a warning when compiled using:

gcc program.c -Wall -o program

A warning may indicate that the operation on count may be undefined.

The -Wall option enables many common compiler warnings. It does not automatically correct undefined behaviour.

A safe alternative is:

count = count + 1;

## 6. Corrected Calculation

The calculation is rewritten using intermediate variables and floating-point values.

Formulas:

Gross = Price * Quantity

Discount = Gross * 15 / 100 (for senior citizens)

Taxable Amount = Gross - Discount

GST = Taxable Amount * 5 / 100

Total = Taxable Amount + GST

Net = Total > 1000 ? Total - 50 : Total

Floating-point variables are used to preserve decimal values.

## 7. Design Decision

Both brackets and intermediate variables are used.

Reasons:

- Brackets clearly specify the order of calculations.
- Intermediate variables separate gross amount, discount and GST.
- Floating-point calculations avoid integer division errors.
- The program becomes easier to read, test and debug.
- Individual calculations can be modified without changing the entire expression.

## 8. Alternative Concept and Complexity Analysis

If the long expression is replaced with separate statements:

gross = price * qty;

discount = senior ? gross * 0.15 : 0.0;

taxable = gross - discount;

tax = taxable * 0.05;

total = taxable + tax;

net = (total > 1000) ? total - 50 : total;

### Complexity Analysis

**Time Complexity: O(1)**

The program performs a fixed number of arithmetic and comparison operations. Therefore, the time complexity remains constant.

**Space Complexity: O(1)**

Intermediate variables such as gross, discount, taxable and tax require additional memory. However, the number of variables remains constant, so the space complexity is O(1).

### Advantages

- Improves readability.
- Makes debugging easier.
- Reduces calculation mistakes.
- Improves maintainability.
- Makes individual operations easier to verify.

The number of operations remains constant, but the use of temporary variables makes the program easier to understand.

## 9. Conclusion

The original pharmacy billing expression can produce incorrect amounts because of integer division and calculating GST on the wrong amount. The count++ statement also causes undefined behaviour.

Using floating-point variables, intermediate calculations and proper brackets produces a more accurate, readable and reliable billing program.
