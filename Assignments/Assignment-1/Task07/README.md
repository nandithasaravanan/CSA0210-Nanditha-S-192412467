# Task 3 – Control Type Conversion and Precision

## 1. Objective
To analyse implicit conversions, integer division, explicit casting, and rounding errors in C.

## 2. Type Conversions
C applies integer promotions and the usual arithmetic conversions when combining different data types. For example, integer operands can produce an integer result even when the programmer expects a fractional result.

## 3. Demonstrated Unexpected Results

1. **Integer division:** `199 / 100` produces `1` because both operands are integers. The fractional part is discarded.
2. **Casting after division:** `(float)(199 / 100)` produces `1.00` because division occurs before the cast.
3. **Large value cast:** Converting `3000000000L` to `int` may produce an implementation-defined result when the value is outside the range of `int`.
4. **Floating-point representation:** Decimal fractions such as `2.255` may not be represented exactly in binary floating point, so multiplication and rounding can produce unexpected results.

## 4. Integer Division and Explicit Casting
To obtain a fractional result, convert an operand before division, such as `(double)199 / 100`. Casting after integer division cannot recover the discarded fraction.

Casting a value that exceeds the destination type's representable range is unsafe and should be avoided.

## 5. Rounding to Paise
Store money as integer paise whenever possible. If a fractional charge must be converted to paise, apply a documented rounding rule, such as rounding to the nearest paise, consistently across all bills. Binary floating-point representation may affect the result of a rounding operation.

## 6. Alternative: Floating-Point Calculations
Using `float` for all charges and rounding only at the end is simpler in appearance but can accumulate representation and rounding errors across many calculations. With integer paise, each stored amount is exact within the chosen integer range.

For `n` bills, both approaches generally require O(n) total processing time and O(1) auxiliary space per bill when bills are processed one at a time. Floating-point error does not necessarily grow linearly in every case; its size depends on the values, operations, and rounding method.

## 7. Result
The program demonstrates integer division, casting, and floating-point precision issues. Integer paise and a consistent rounding rule provide more reliable monetary calculations.
