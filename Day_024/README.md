# Day 24: Binary Division Mastery

## 🎯 Learning Objectives

By the end of this day, you will master:
- **Binary Division Algorithm**: Efficient division using bit manipulation
- **Overflow Handling**: Managing integer limits and edge cases
- **Bit Manipulation**: Using shifts for multiplication and division by powers of 2
- **Sign Detection**: XOR operations for determining result signs

---

## Problem 1: Divide Two Integers (LeetCode 29)

### 📋 Problem Statement

**Difficulty**: Medium  
**Category**: Math, Bit Manipulation  
**Companies**: Facebook, Microsoft, Amazon, Apple, Google

Given two integers `dividend` and `divisor`, divide two integers **without using** multiplication (`*`), division (`/`), and mod operator (`%`).

Return the quotient after dividing `dividend` by `divisor`.

**Important**: The integer division should **truncate toward zero**, which means losing its fractional part.
- Example: `8.345` → `8`, `-2.7335` → `-2`

### 💡 Examples

```
Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333... → truncated to 3

Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/(-3) = -2.33333... → truncated to -2

Example 3 (Overflow Case):
Input: dividend = -2147483648, divisor = -1
Output: 2147483647
Explanation: -2147483648/(-1) = 2147483648, but this exceeds INT_MAX,
so we return INT_MAX = 2147483647
```

### 🔍 Intuition

Since we can't use multiplication, division, or modulo operators, we need to think creatively:

**Key Insight**: Division is essentially finding how many times the divisor fits into the dividend. Instead of subtracting the divisor repeatedly (which is O(n)), we can use **binary search** and **bit manipulation** to achieve O(log n) complexity.

**Core Idea**: Find the largest multiple of divisor (using powers of 2) that fits into the dividend.

### 🚀 Approach: Binary Division Algorithm

- **Time Complexity**: O(log n) where n is the dividend
- **Space Complexity**: O(1)
- **Key Insight**: Use bit manipulation to find largest multiples
- **Algorithm**:
  1. Handle edge cases (division by zero, overflow)
  2. Determine result sign using XOR
  3. Convert to positive numbers using absolute values
  4. Use binary search to find largest fitting multiples
  5. Apply sign and handle overflow

```cpp
int divide(int dividend, int divisor) {
    // Handle edge cases
    if (divisor == 0) return INT_MAX;
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    
    // Determine sign
    bool negative = (dividend < 0) ^ (divisor < 0);
    
    // Convert to positive
    long long a = llabs((long long)dividend);
    long long b = llabs((long long)divisor);
    
    long long result = 0;
    
    // Binary division
    while (a >= b) {
        long long temp = b, multiple = 1;
        
        while ((temp << 1) <= a) {
            temp <<= 1;
            multiple <<= 1;
        }
        
        a -= temp;
        result += multiple;
    }
    
    // Apply sign and handle overflow
    if (negative) result = -result;
    if (result > INT_MAX) return INT_MAX;
    if (result < INT_MIN) return INT_MIN;
    
    return (int)result;
}
```

### Key Points

1. **Binary Division Logic**:
   - Instead of subtracting divisor repeatedly, find largest power of 2 that fits
   - Use bit shifting (`<<`) for efficient multiplication by 2
   - Track both the divisor multiple and corresponding quotient multiple

2. **Why Use Long Long**:
   - `INT_MIN` (-2,147,483,648) cannot be represented as positive int
   - `llabs()` correctly handles the absolute value of `INT_MIN`
   - Prevents overflow during intermediate calculations

3. **XOR for Sign Detection**:
   - `(dividend < 0) ^ (divisor < 0)` returns true if exactly one is negative
   - More efficient than checking both conditions separately
   - Handles all sign combinations correctly

4. **Overflow Handling**:
   - `INT_MIN / (-1)` would result in `INT_MAX + 1`, causing overflow
   - Check result bounds before returning to prevent integer overflow
   - Return `INT_MAX` for any overflow cases

### Algorithm Walkthrough

```
Example: dividend = 10, divisor = 3

Step 1: Handle edge cases
- No division by zero
- No INT_MIN / (-1) case

Step 2: Determine sign
- dividend = 10 (positive)
- divisor = 3 (positive)
- negative = false ^ false = false

Step 3: Convert to positive
- a = 10, b = 3

Step 4: Binary division
Iteration 1: a = 10, b = 3
- temp = 3, multiple = 1
- Check: (3 << 1) = 6 <= 10? Yes
- temp = 6, multiple = 2
- Check: (6 << 1) = 12 <= 10? No
- a = 10 - 6 = 4
- result = 0 + 2 = 2

Iteration 2: a = 4, b = 3
- temp = 3, multiple = 1
- Check: (3 << 1) = 6 <= 4? No
- a = 4 - 3 = 1
- result = 2 + 1 = 3

Iteration 3: a = 1, b = 3
- a < b, exit loop

Result: 3
```

### Visual Representation

```
Binary Division Process:

Dividend: 10, Divisor: 3

Step 1: Find largest power of 2 × divisor that fits
3 × 1 = 3  ✓
3 × 2 = 6  ✓
3 × 4 = 12 ✗ (too large)

Subtract: 10 - 6 = 4, Add to result: 2

Step 2: Find largest power of 2 × divisor that fits in remainder
3 × 1 = 3  ✓
3 × 2 = 6  ✗ (too large)

Subtract: 4 - 3 = 1, Add to result: 2 + 1 = 3

Step 3: Remainder (1) < divisor (3), stop

Final Result: 3

Visual Flow:
10 ÷ 3 = ?
├── 3 × 2 = 6 (largest that fits in 10)
│   ├── Subtract: 10 - 6 = 4
│   └── Add to result: 2
├── 3 × 1 = 3 (largest that fits in 4)
│   ├── Subtract: 4 - 3 = 1
│   └── Add to result: 2 + 1 = 3
└── Remainder 1 < divisor 3, stop
    └── Final result: 3
```

### Edge Cases

1. **Division by Zero**: Return `INT_MAX`
   - Example: `10 / 0` → Output: `2147483647`

2. **INT_MIN / (-1)**: Return `INT_MAX` (overflow prevention)
   - Example: `-2147483648 / (-1)` → Output: `2147483647`

3. **Same Sign Numbers**: Result is positive
   - Example: `10 / 3` → Output: `3`
   - Example: `-10 / (-3)` → Output: `3`

4. **Different Sign Numbers**: Result is negative
   - Example: `10 / (-3)` → Output: `-3`
   - Example: `-10 / 3` → Output: `-3`

5. **Dividend Smaller Than Divisor**: Result is 0
   - Example: `2 / 5` → Output: `0`

### Alternative Approaches

1. **Repeated Subtraction**: O(n) time - subtract divisor repeatedly
   ```cpp
   int divide(int dividend, int divisor) {
       int result = 0;
       while (dividend >= divisor) {
           dividend -= divisor;
           result++;
       }
       return result;
   }
   ```

2. **Exponential Search**: O(log n) time - similar to binary search
   ```cpp
   int divide(int dividend, int divisor) {
       if (divisor == 0) return INT_MAX;
       
       long long a = abs((long long)dividend);
       long long b = abs((long long)divisor);
       long long result = 0;
       
       while (a >= b) {
           long long temp = b;
           long long multiple = 1;
           
           while (temp <= a) {
               temp <<= 1;
               multiple <<= 1;
           }
           
           temp >>= 1;
           multiple >>= 1;
           
           a -= temp;
           result += multiple;
       }
       
       return (dividend < 0) ^ (divisor < 0) ? -result : result;
   }
   ```

### Mathematical Insight

The binary division algorithm is based on the property that any number can be represented as a sum of powers of 2:

- `dividend = divisor × (2^0 + 2^1 + 2^2 + ... + 2^k) + remainder`
- We find the largest `2^k` such that `divisor × 2^k ≤ dividend`
- This gives us the most significant bit of the quotient
- Repeat the process with the remainder

### Bit Manipulation Details

```cpp
// Left shift (<<) is equivalent to multiplication by 2
temp <<= 1;      // temp = temp * 2
multiple <<= 1;  // multiple = multiple * 2

// Right shift (>>) is equivalent to division by 2
temp >>= 1;      // temp = temp / 2
multiple >>= 1;  // multiple = multiple / 2

// XOR for sign detection
bool negative = (dividend < 0) ^ (divisor < 0);
// Returns true if exactly one operand is negative
```

### Constraints

- `-2^31 <= dividend, divisor <= 2^31 - 1`
- `divisor != 0`

### Source

[LeetCode 29 - Divide Two Integers](https://leetcode.com/problems/divide-two-integers)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Divide Two Integers | Medium | ✅ Solved | Binary Division | O(log n) | O(1) |

## 🎯 Key Learnings

1. **Binary Division**: Efficient algorithm using bit manipulation for division
2. **Overflow Handling**: Critical for integer division problems with edge cases
3. **Bit Shifting**: Using `<<` and `>>` for efficient multiplication/division by 2
4. **Sign Detection**: XOR operation for determining result sign
5. **Long Long Usage**: Handling `INT_MIN` absolute value correctly

## 🚀 Next Steps

- Practice more mathematical algorithms (power, square root)
- Study bit manipulation techniques
- Learn about modular arithmetic
- Explore other division-related problems

## 💡 Problem-Solving Tips

1. **Division Without Operators**: Use binary search and bit manipulation
2. **Overflow Prevention**: Always check `INT_MIN / (-1)` case
3. **Sign Handling**: XOR is efficient for determining result sign
4. **Bit Operations**: Left shift for multiplication by 2, right shift for division by 2
5. **Edge Cases**: Handle division by zero and overflow scenarios carefully

---

**Total Problems Solved**: 14/∞

*Divide and conquer with bits! ⚡*
