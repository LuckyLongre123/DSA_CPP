# Day 23: Self Dividing Numbers

## Problem Overview
**LeetCode 728: Self Dividing Numbers**

A self-dividing number is a number that is divisible by every digit it contains. Self-dividing numbers are not allowed to contain the digit zero.

Given two integers `left` and `right`, return a list of all the self-dividing numbers in the range `[left, right]`.

## Examples

### Example 1:
```
Input: left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
Explanation: 
- 1 is self-dividing (1 % 1 = 0)
- 2 is self-dividing (2 % 2 = 0)
- 10 is not self-dividing (contains 0)
- 11 is self-dividing (11 % 1 = 0)
- 12 is self-dividing (12 % 1 = 0, 12 % 2 = 0)
```

### Example 2:
```
Input: left = 47, right = 85
Output: [48, 55, 66, 77]
Explanation:
- 48: 48 % 4 = 0, 48 % 8 = 0 ✓
- 55: 55 % 5 = 0, 55 % 5 = 0 ✓
- 66: 66 % 6 = 0, 66 % 6 = 0 ✓
- 77: 77 % 7 = 0, 77 % 7 = 0 ✓
```

## Approach

### Algorithm: Digit Extraction and Validation
1. **Iterate through range**: Check each number from `left` to `right`
2. **Extract digits**: Use modulo and division operations to get each digit
3. **Validate conditions**:
   - Digit must not be 0 (to avoid division by zero)
   - Original number must be divisible by the digit
4. **Collect results**: Add valid self-dividing numbers to result array

### Visual Representation
```
Number: 128
Digits: 1, 2, 8

Check: 128 % 1 = 0 ✓
Check: 128 % 2 = 0 ✓  
Check: 128 % 8 = 0 ✓

Result: 128 is self-dividing
```

### Algorithm Walkthrough
```cpp
For number 128:
1. num = 128, extract digit: 128 % 10 = 8
   - Check: 128 % 8 = 0 ✓
   - num = 128 / 10 = 12

2. num = 12, extract digit: 12 % 10 = 2  
   - Check: 128 % 2 = 0 ✓
   - num = 12 / 10 = 1

3. num = 1, extract digit: 1 % 10 = 1
   - Check: 128 % 1 = 0 ✓
   - num = 1 / 10 = 0

4. All digits passed → 128 is self-dividing
```

## Complexity Analysis
- **Time Complexity**: O((right - left + 1) × log₁₀(max_number))
  - We iterate through (right - left + 1) numbers
  - For each number, we extract log₁₀(number) digits
- **Space Complexity**: O(1) excluding the output array
  - Only using constant extra space for variables

## Edge Cases
1. **Single digit numbers**: All single digits (1-9) are self-dividing
2. **Numbers with 0**: Any number containing 0 is not self-dividing
3. **Large ranges**: Algorithm handles any valid integer range efficiently
4. **Empty result**: If no self-dividing numbers exist in range

## Alternative Approaches

### Approach 1: String Conversion (Less Efficient)
```cpp
// Convert number to string and check each character
string s = to_string(num);
for (char c : s) {
    int digit = c - '0';
    if (digit == 0 || num % digit != 0) return false;
}
```

### Approach 2: Recursive Digit Extraction
```cpp
bool isSelfDividing(int num, int original) {
    if (num == 0) return true;
    int digit = num % 10;
    if (digit == 0 || original % digit != 0) return false;
    return isSelfDividing(num / 10, original);
}
```

## Key Insights
1. **Digit Extraction Pattern**: Using `num % 10` and `num /= 10` is efficient for digit processing
2. **Early Termination**: Break immediately when invalid digit found
3. **Zero Handling**: Must check for zero digits to avoid division by zero
4. **Mathematical Property**: Self-dividing numbers are relatively rare in larger ranges

## Learning Objectives
- Understanding digit extraction techniques
- Implementing validation logic with multiple conditions
- Optimizing with early termination
- Handling edge cases in mathematical problems

## Progress Summary
- ✅ Implemented efficient digit extraction algorithm
- ✅ Added comprehensive input validation
- ✅ Optimized with early break conditions
- ✅ Handled all edge cases including zero digits
- ✅ Achieved optimal time complexity for the problem constraints
