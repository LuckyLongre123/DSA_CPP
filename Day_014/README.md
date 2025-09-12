# Day 14: Integer Manipulation & Overflow Mastery

## 🎯 Learning Objectives

By the end of this day, you will master:
- **Integer Digit Manipulation**: Extracting and reconstructing digits efficiently
- **Overflow Detection**: Preventing integer overflow in mathematical operations
- **Boundary Handling**: Managing 32-bit signed integer limits
- **Mathematical Operations**: Understanding modulo and division for digit processing

---

## Problem 1: Reverse Integer (LeetCode 7)

### 📋 Problem Statement

**Difficulty**: Medium  
**Category**: Math, Integer Manipulation  
**Companies**: Amazon, Microsoft, Apple, Facebook, Bloomberg

Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2³¹, 2³¹ - 1]`, then return `0`.

**Critical Constraint**: Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

### 🔍 Problem Analysis

**Integer Boundaries**:
```
32-bit Signed Integer Range:
INT_MIN = -2,147,483,648 = -2³¹
INT_MAX =  2,147,483,647 =  2³¹ - 1

Key Insight: Only 10-digit numbers can potentially overflow
```

**Overflow Scenarios**:
```
Original: 1534236469 → Reversed: 9646324351 > INT_MAX ❌
Original: 2147483647 → Reversed: 7463847412 > INT_MAX ❌  
Original: -2147483648 → Reversed: -8463847412 < INT_MIN ❌
```

### 📚 Examples with Detailed Analysis

#### Example 1: Basic Positive Number
```
Input: x = 123
Output: 321

Step-by-step process:
- Extract digits: 3, 2, 1
- Build reversed: 0 → 3 → 32 → 321
- No overflow risk (3-digit number)
- Result: 321
```

#### Example 2: Negative Number
```
Input: x = -123
Output: -321

Step-by-step process:
- Sign is preserved automatically
- Extract digits from absolute value: 3, 2, 1
- Build reversed: 0 → 3 → 32 → 321
- Apply original sign: -321
- Result: -321
```

#### Example 3: Trailing Zeros
```
Input: x = 120
Output: 21

Step-by-step process:
- Extract digits: 0, 2, 1
- Build reversed: 0 → 0 → 02 → 021
- Leading zeros are automatically dropped: 21
- Result: 21
```

#### Example 4: Overflow Case
```
Input: x = 1534236469
Output: 0

Step-by-step process:
- Start reversing: 9, 6, 4, 6, 3, 2, 4, 3, 5, 1
- When ans = 964632435, next operation would be:
  ans * 10 + 1 = 9646324351
- Check: 964632435 > INT_MAX/10 (214748364) ✓
- Overflow detected → Return 0
```

#### Example 5: Edge Cases
```
Input: x = 0
Output: 0
Explanation: Zero reversed is still zero

Input: x = -2147483648 (INT_MIN)
Output: 0
Explanation: Reversed would be -8463847412 < INT_MIN

Input: x = 2147483647 (INT_MAX)
Output: 0
Explanation: Reversed would be 7463847412 > INT_MAX
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

### 🔄 Alternative Approaches

#### Approach 1: String Conversion Method
```cpp
int reverse(int x) {
    string s = to_string(x);
    bool negative = (s[0] == '-');
    
    if (negative) s = s.substr(1);  // Remove negative sign
    
    std::reverse(s.begin(), s.end());
    
    // Check for overflow using string comparison
    string maxStr = "2147483647";
    string minStr = "2147483648";
    
    if (s.length() > 10 || 
        (s.length() == 10 && s > (negative ? minStr : maxStr))) {
        return 0;
    }
    
    int result = stoi(s);
    return negative ? -result : result;
}
```
**Pros**: Easier overflow checking with string comparison
**Cons**: Extra space for string operations, slower performance

#### Approach 2: Long Long Method (If Allowed)
```cpp
int reverse(int x) {
    long long result = 0;
    
    while (x != 0) {
        result = result * 10 + x % 10;
        x /= 10;
    }
    
    // Check overflow after calculation
    if (result > INT_MAX || result < INT_MIN) {
        return 0;
    }
    
    return (int)result;
}
```
**Pros**: Simpler logic, no need for preemptive overflow checking
**Cons**: Uses 64-bit integers (violates problem constraint)

#### Approach 3: Recursive Digit Extraction
```cpp
class Solution {
public:
    int reverse(int x) {
        return reverseHelper(x, 0);
    }
    
private:
    int reverseHelper(int x, int result) {
        if (x == 0) return result;
        
        // Check overflow before recursion
        if (result > INT_MAX/10 || result < INT_MIN/10) {
            return 0;
        }
        
        return reverseHelper(x/10, result*10 + x%10);
    }
};
```
**Pros**: Clean recursive structure
**Cons**: Function call overhead, potential stack overflow for large numbers

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

### 🧮 Mathematical Properties Deep Dive

#### Digit Extraction Mathematics
```cpp
// For number 1234:
int num = 1234;

// Extract digits from right to left:
digit1 = 1234 % 10 = 4    // num becomes 123
digit2 = 123 % 10 = 3     // num becomes 12  
digit3 = 12 % 10 = 2      // num becomes 1
digit4 = 1 % 10 = 1       // num becomes 0

// Build reversed number:
result = 0
result = 0*10 + 4 = 4
result = 4*10 + 3 = 43
result = 43*10 + 2 = 432
result = 432*10 + 1 = 4321
```

#### Overflow Detection Mathematics
```cpp
// Why we check ans > INT_MAX/10:
INT_MAX = 2147483647
INT_MAX/10 = 214748364

// If ans = 214748365 (> INT_MAX/10):
// Next operation: ans*10 = 2147483650 > INT_MAX ❌

// If ans = 214748364 (= INT_MAX/10):
// Next operation: ans*10 + digit
// Maximum safe: 2147483640 + 7 = 2147483647 = INT_MAX ✓
// Overflow case: 2147483640 + 8 = 2147483648 > INT_MAX ❌
```

#### Negative Number Handling
```cpp
// C++ modulo with negative numbers:
-123 % 10 = -3  (not 7)
-123 / 10 = -12 (not -13)

// This naturally preserves the sign:
int x = -123, ans = 0;
ans = 0*10 + (-123%10) = 0 + (-3) = -3
ans = -3*10 + (-12%10) = -30 + (-2) = -32  
ans = -32*10 + (-1%10) = -320 + (-1) = -321
```

### 🔍 Edge Cases and Testing Strategy

#### Critical Test Cases
```cpp
// 1. Zero
reverse(0) → 0

// 2. Single digit
reverse(5) → 5
reverse(-7) → -7

// 3. Trailing zeros
reverse(1000) → 1
reverse(-1200) → -21

// 4. Palindromes
reverse(121) → 121
reverse(-131) → -131

// 5. Maximum safe values
reverse(1463847412) → 2147483641 (safe)
reverse(1463847413) → 0 (overflow)

// 6. Boundary values
reverse(INT_MAX) → 0 (overflow)
reverse(INT_MIN) → 0 (overflow)
```

#### Overflow Boundary Analysis
```cpp
// Numbers that will overflow when reversed:
Original: 1534236469 → Reversed: 9646324351 > INT_MAX
Original: 2147483647 → Reversed: 7463847412 > INT_MAX
Original: -2147483648 → Reversed: -8463847412 < INT_MIN

// Numbers that are safe:
Original: 1463847412 → Reversed: 2147483641 ≤ INT_MAX
Original: -1463847412 → Reversed: -2147483641 ≥ INT_MIN
```

### 🎯 Advanced Optimization Techniques

#### Early Termination Optimization
```cpp
int reverse(int x) {
    // Quick return for single digits
    if (x >= -9 && x <= 9) return x;
    
    int ans = 0;
    while (x != 0) {
        // Enhanced overflow check
        if (ans > INT_MAX/10 || 
            (ans == INT_MAX/10 && x%10 > 7)) return 0;
        if (ans < INT_MIN/10 || 
            (ans == INT_MIN/10 && x%10 < -8)) return 0;
            
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}
```

#### Memory-Efficient Digit Counting
```cpp
// Count digits without extra space
int countDigits(int x) {
    if (x == 0) return 1;
    int count = 0;
    x = abs(x);
    while (x > 0) {
        count++;
        x /= 10;
    }
    return count;
}
```

### 📊 Performance Analysis

#### Time Complexity Breakdown
```cpp
// O(log₁₀ x) where x is the input number
// Number of digits = ⌊log₁₀|x|⌋ + 1

Examples:
- 1-digit: O(1) - 1 iteration
- 2-digit: O(1) - 2 iterations  
- 3-digit: O(1) - 3 iterations
- 10-digit: O(1) - 10 iterations (max for 32-bit)

// Constant time for practical purposes
```

#### Space Complexity Analysis
```cpp
// O(1) - Only using fixed variables:
// - ans: result accumulator
// - x: input (modified in place)
// - No additional data structures
// - No recursion stack
```

### 🧪 Comprehensive Testing Framework

```cpp
void testReverseInteger() {
    // Basic cases
    assert(reverse(123) == 321);
    assert(reverse(-123) == -321);
    assert(reverse(120) == 21);
    
    // Edge cases
    assert(reverse(0) == 0);
    assert(reverse(1) == 1);
    assert(reverse(-1) == -1);
    
    // Overflow cases
    assert(reverse(1534236469) == 0);
    assert(reverse(2147483647) == 0);
    assert(reverse(-2147483648) == 0);
    
    // Boundary safe cases
    assert(reverse(1463847412) == 2147483641);
    assert(reverse(-1463847412) == -2147483641);
    
    cout << "All tests passed!" << endl;
}
```

## 💡 Problem-Solving Tips

1. **Overflow Prevention**: Always check bounds before arithmetic operations
2. **Digit Manipulation Mastery**: Practice `x % 10` and `x / 10` patterns
3. **Edge Case Coverage**: Test zero, single digits, trailing zeros, and boundaries
4. **Mathematical Understanding**: Know how modulo works with negative numbers
5. **Performance Awareness**: Understand logarithmic time complexity for digit problems
6. **Constraint Compliance**: Respect problem limitations (no 64-bit integers)
7. **Testing Strategy**: Create comprehensive test cases covering all scenarios
