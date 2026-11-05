# Task 01 – Else-if Ladder or Switch?

## 1. Problem Understanding

The university examination cell classifies students based on their marks.

The grade rules are:

| Marks | Grade |
|---|---|
| 90–100 | S |
| 80–89 | A |
| 70–79 | B |
| 60–69 | C |
| 50–59 | D |
| 0–49 | F |
| Outside 0–100 | Invalid (?) |

The grade classification is implemented using two methods:

1. Else-if ladder.
2. Switch statement using marks / 10.

## 2. Else-if Ladder Implementation

The else-if ladder checks multiple conditions in sequence.

Example:

```c
if (marks >= 90 && marks <= 100)
    return 'S';
else if (marks >= 80)
    return 'A';
else if (marks >= 70)
    return 'B';
```

The program checks each condition until a matching condition is found.

Invalid marks are rejected before grade classification.

## 3. Switch Statement Implementation

The switch statement uses:

`switch (marks / 10)`

Since integer division is used, the marks are divided by 10 and the fractional part is removed.

| Marks | marks / 10 | Grade |
|---|---:|---|
| 100 | 10 | S |
| 90–99 | 9 | S |
| 80–89 | 8 | A |
| 70–79 | 7 | B |
| 60–69 | 6 | C |
| 50–59 | 5 | D |
| 0–49 | 0–4 | F |

A separate validation condition is required to reject marks below 0 or above 100.

## 4. Comparison of Both Methods

| Input | Else-if Result | Switch Result |
|---|---|---|
| 100 | S | S |
| 90 | S | S |
| 89 | A | A |
| 0 | F | F |
| -1 | ? | ? |
| 101 | ? | ? |

Both methods produce correct results when the conditions and validation are implemented properly.

However, if the switch statement does not handle case 10, marks of 100 may be classified incorrectly.

## 5. Effect of Missing break

The break statement terminates a switch case.

If break is missing, execution continues into the following case. This is called fall-through.

For example:

```c
case 9:
    grade = 'S';

case 8:
    grade = 'A';
    break;
```

If marks are 95, the program enters case 9 but continues into case 8. The final grade becomes A instead of S.

Therefore, break statements must be used correctly.

## 6. Why switch Cannot Directly Test Ranges

A switch statement compares one expression against constant values.

It cannot directly check a range such as:

`marks >= 75 && marks <= 84`

A switch case must use a constant integral value, not a relational condition or range expression.

An else-if ladder is more suitable for checking ranges.

## 7. Boundary Testing

The following test values help identify errors at grade boundaries:

| Marks | Expected Grade |
|---:|---|
| -1 | ? |
| 0 | F |
| 49 | F |
| 50 | D |
| 59 | D |
| 60 | C |
| 69 | C |
| 70 | B |
| 79 | B |
| 80 | A |
| 89 | A |
| 90 | S |
| 99 | S |
| 100 | S |
| 101 | ? |

Testing values immediately below and above each boundary helps identify incorrect conditions.

## 8. Design Decision – Scholarship Classification

The scholarship category depends on both the student's grade and family income.

I recommend using an else-if ladder for grade eligibility and nested if statements for income classification.

Reasons:

- Grade classification involves ranges.
- Income classification also involves ranges.
- Nested conditions make the relationship between grade and income clear.
- Scholarship rules can be modified independently.

A switch statement can also be used for grade categories, followed by income checks.

The exact scholarship conditions must be based on the university's official grade and income eligibility rules.

## 9. Alternative Concept – Lookup Table

A lookup table can store grades directly:

```c
char grades[11] = {
    'F', 'F', 'F', 'F', 'F',
    'D', 'C', 'B', 'A', 'S', 'S'
};
```

The grade can be obtained using:

`grades[marks / 10]`

Marks must be validated before accessing the array.

### Complexity Analysis

**Time Complexity:**

- Switch statement: O(1) for a fixed number of cases.
- Lookup table: O(1) for direct indexing.
- Else-if ladder: O(k) in the worst case, where k is the number of conditions.

**Space Complexity:**

- Else-if ladder: O(1) extra space.
- Switch statement: O(1) extra space.
- Lookup table: O(1) space for a fixed 11-element table.

The lookup table is simple and fast, but the else-if ladder is easier to modify when grade boundaries are changed.

## 10. Conclusion

Both the else-if ladder and switch statement can classify grades correctly when implemented with proper conditions and input validation.

The else-if ladder is more suitable for range-based conditions, while the switch statement is useful when values are divided into fixed categories.

A lookup table provides direct access to grades with constant-time complexity.

For a university grading and scholarship system, the else-if ladder with nested income conditions is a clear and flexible approach.
