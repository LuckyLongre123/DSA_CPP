# Day 14: Integer Manipulation - Reverse Integer

## Problem 1: Reverse Integer

### Problem Description

Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2³¹, 2³¹ - 1]`, then return `0`.

### Examples:

```
Input: x = 123
Output: 321

Input: x = -123
Output: -321

Input: x = 120
Output: 21
Explanation: Leading zeros are dropped

Input: x = 1534236469
Output: 0
Explanation: Reversed would be 9646324351, which overflows 32-bit signed integer
```

### Approach

#### Digit-by-Digit Reversal with Overflow Check

- **Time Complexity**: O(log x) - number of digits in x
- **Space Complexity**: O(1)
- **Algorithm**:
  1. Initialize result variable to 0
  2. While x is not zero:
     - Check for overflow before multiplying result by 10
     - Extract last digit using modulo operation
     - Build reversed number by adding extracted digit
     - Remove last digit from x using integer division
  3. Return result or 0 if overflow detected

```cpp
int reverse(int x) {
    int ans = 0;
    
    while(x != 0){
        // Check overflow before multiplying by 10
        if(ans < INT_MIN/10 || ans > INT_MAX/10) return 0;
        
        ans = ans * 10 + x % 10;  // Build reversed number
        x /= 10;                  // Remove last digit
    }
    
    return ans;
}
```

### Key Points

1. **Overflow Detection**:
   - Check `ans < INT_MIN/10` or `ans > INT_MAX/10`
   - Must check BEFORE multiplying by 10 to avoid overflow
   - INT_MIN = -2,147,483,648, INT_MAX = 2,147,483,647

2. **Digit Extraction**:
   - `x % 10` gets the last digit
   - `x / 10` removes the last digit
   - Works for both positive and negative numbers

3. **Edge Cases**:
   - Negative numbers: sign is preserved automatically
   - Trailing zeros become leading zeros (dropped)
   - Overflow cases return 0

### Algorithm Walkthrough

```
Example: x = 123

Step 1: ans=0, x=123
        Check: 0 < INT_MIN/10? No. 0 > INT_MAX/10? No.
        ans = 0*10 + 123%10 = 0 + 3 = 3
        x = 123/10 = 12

Step 2: ans=3, x=12
        Check: 3 < INT_MIN/10? No. 3 > INT_MAX/10? No.
        ans = 3*10 + 12%10 = 30 + 2 = 32
        x = 12/10 = 1

Step 3: ans=32, x=1
        Check: 32 < INT_MIN/10? No. 32 > INT_MAX/10? No.
        ans = 32*10 + 1%10 = 320 + 1 = 321
        x = 1/10 = 0

Step 4: x=0, loop ends
        Return ans = 321
```

### Overflow Example

```
Example: x = 1534236469 (reversed would be 9646324351)

When ans = 964632435 and we try to add next digit:
Check: 964632435 > INT_MAX/10 (214748364)? YES!
Return 0 immediately (overflow detected)
```

### Alternative Approaches

1. **String Conversion**: Convert to string, reverse, convert back (handles overflow differently)
2. **Mathematical**: Use long long for intermediate calculations
3. **Recursive**: Recursive digit extraction (less efficient)

### Constraints

- -2³¹ ≤ x ≤ 2³¹ - 1

### Source

[LeetCode 7 - Reverse Integer](https://leetcode.com/problems/reverse-integer)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Reverse Integer | Medium | ✅ Solved | Digit Manipulation | O(log x) | O(1) |

## 🎯 Key Learnings

1. **Overflow Handling**: Proactive overflow detection before arithmetic operations
2. **Digit Manipulation**: Extracting and building numbers digit by digit
3. **Integer Limits**: Understanding INT_MIN and INT_MAX boundaries
4. **Edge Case Handling**: Negative numbers, trailing zeros, and overflow scenarios

## 🚀 Next Steps

- Practice more integer manipulation problems
- Explore problems involving number properties and constraints
- Learn about different overflow detection techniques
- Study problems with mathematical constraints

## 💡 Problem-Solving Tips

1. **Check Overflow Early**: Always check before operations that might overflow
2. **Use Integer Division**: `x / 10` removes last digit, `x % 10` extracts it
3. **Test Edge Cases**: Try INT_MAX, INT_MIN, negative numbers, trailing zeros
4. **Understand Constraints**: Know the limits of data types you're working with
