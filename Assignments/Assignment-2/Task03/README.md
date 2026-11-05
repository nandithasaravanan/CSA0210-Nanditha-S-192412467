# Task 03 – Engineer a Device-Status Register with Bitwise Operators

## 1. Problem Understanding

A smart-home controller uses one unsigned char (8 bits) to store the ON/OFF status of up to eight devices.

Each bit represents one device.

- Bit 0 – Light
- Bit 1 – Fan
- Bit 2 – AC
- Bit 3 – Heater
- Bit 4 – Pump
- Bit 5 – Device 6
- Bit 6 – Device 7
- Bit 7 – Device 8

A bit value of 1 represents ON, and a bit value of 0 represents OFF.

## 2. Bitwise Operations

The following bitwise operators are used:

| Operator | Purpose |
|---|---|
| `|` | Set a bit |
| `&` | Clear or test a bit |
| `^` | Toggle a bit |
| `~` | Invert bits |
| `<<` | Left shift |
| `>>` | Right shift |

### Switch ON

The bit is set using the OR operator.

`reg = reg | (1u << dev);`

### Switch OFF

The bit is cleared using AND and NOT.

`reg = reg & ~(1u << dev);`

### Toggle

The bit is flipped using XOR.

`reg = reg ^ (1u << dev);`

### Test Device Status

The AND operator checks whether a particular bit is set.

`(reg & (1u << dev)) != 0`

It returns 1 if the device is ON and 0 if it is OFF.

## 3. Prediction Before Execution

The initial register value is:

`reg = 00000000`

The following operations are performed:

| Operation | Register Value | Decimal Value |
|---|---|---:|
| Initial register | 00000000 | 0 |
| Switch ON LIGHT | 00000001 | 1 |
| Switch ON AC | 00000101 | 5 |
| Switch OFF LIGHT | 00000100 | 4 |
| Switch ON FAN | 00000110 | 6 |

Therefore:

- First displayed register = `00000101`
- Second displayed register = `00000110`
- AC status = ON
- PUMP status = OFF

## 4. Printing the Register in Binary

The register is printed from bit 7 to bit 0.

The expression used is:

`(reg >> bit) & 1u`

The right-shift operator moves the required bit to position 0. The AND operator extracts that bit.

The result is printed using `putchar()`.

## 5. Counting Devices That Are ON

The number of active devices can be counted by checking each of the eight bits.

For every bit:

`count += (reg >> bit) & 1u;`

If the bit is 1, the count increases by one.

## 6. Inquiry – Operator Precedence

Consider:

`reg & 1 << dev`

The shift operator has higher precedence than the bitwise AND operator.

Therefore, it is evaluated as:

`reg & (1 << dev)`

This correctly checks the selected device bit.

However:

`(reg & 1) << dev`

first checks only bit 0 and then shifts the result.

It does not correctly test the status of the selected device.

## 7. Signed char Problem

Using signed char instead of unsigned char can cause problems when bit 7 is set.

A signed char may represent negative values. When bit 7 is set, the value may be interpreted as negative.

Right-shifting a negative signed integer has implementation-defined behaviour in C.

Therefore, unsigned char is preferred for bitwise register operations because it represents values from 0 to 255.

## 8. Alternative Concept – Using an Array

Instead of storing eight device states in one byte, an array can be used:

`char state[8];`

Each array element stores one device's ON/OFF status.

Example:

- state[0] = 1 for LIGHT ON
- state[1] = 0 for FAN OFF
- state[2] = 1 for AC ON

### Time Complexity

| Operation | Bitwise Register | Array |
|---|---|---|
| Switch ON | O(1) | O(1) |
| Switch OFF | O(1) | O(1) |
| Toggle | O(1) | O(1) |
| Check status | O(1) | O(1) |
| Count ON devices | O(1) for 8 bits | O(8), or O(n) generally |

Both methods have constant-time individual operations.

### Space Complexity

For one home:

- Bitwise register = 1 byte.
- Array = 8 bytes.

For 1,000,000 homes:

- Bitwise storage = 1,000,000 bytes (approximately 1 MB).
- Array storage = 8,000,000 bytes (approximately 8 MB).

The bitwise method saves approximately 7 MB of memory.

## 9. Conclusion

Bitwise operators provide an efficient way to store and manage eight device states using only one byte of memory.

The bitwise register method saves memory compared with an array while providing constant-time operations for switching devices ON, switching them OFF, toggling and checking their status.

Therefore, the bitwise method is suitable for low-memory embedded systems and smart-home controllers.
