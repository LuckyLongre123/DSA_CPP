# Day 15: Mathematical Algorithms - Power Function

## Problem 1: Pow(x, n)

### Problem Description

Implement `pow(x, n)`, which calculates `x` raised to the power `n` (i.e., x^n). The function should handle both positive and negative exponents efficiently.

### Examples:

```
Input: x = 2.00000, n = 10
Output: 1024.00000

Input: x = 2.10000, n = 3
Output: 9.26100

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2^(-2) = 1/2^2 = 1/4 = 0.25
```

### Approach

#### Binary Exponentiation (Fast Exponentiation)

- **Time Complexity**: O(log n)
- **Space Complexity**: O(1)
- **Algorithm**:
  1. Handle negative exponent by converting x to 1/x and making n positive
  2. Use binary representation of exponent for efficient calculation
  3. Square the base and halve the exponent in each iteration
  4. If exponent is odd, multiply current result with base
  5. Continue until exponent becomes 0

```cpp
double myPow(double x, int n) {
    long bf = n;  // Use long to handle INT_MIN overflow
    if(n < 0){
        x = 1/x;      // Convert to reciprocal for negative exponent
        bf = -bf;     // Make exponent positive
    }
    double ans = 1;
    
    while(bf > 0){
        if(bf % 2 == 1) ans *= x;  // If exponent is odd, multiply result
        x *= x;                    // Square the base
        bf /= 2;                   // Halve the exponent
    }
    return ans;
}
```

### Key Points

1. **Binary Exponentiation Logic**:
   - Instead of multiplying x by itself n times (O(n))
   - Use binary representation of n to reduce operations to O(log n)
   - Example: 2^10 = 2^8 × 2^2 (binary: 1010)

2. **Negative Exponent Handling**:
   - x^(-n) = 1/(x^n)
   - Convert x to 1/x and make exponent positive
   - Use long to prevent overflow when n = INT_MIN

3. **Algorithm Intuition**:
   - Every number can be expressed as sum of powers of 2
   - 10 = 8 + 2 = 2^3 + 2^1 (binary: 1010)
   - So x^10 = x^8 × x^2

### Algorithm Walkthrough

```
Example: x = 2, n = 10 (binary: 1010)

Initial: bf=10, x=2, ans=1

Step 1: bf=10 (even), ans=1
        x = 2*2 = 4, bf = 10/2 = 5

Step 2: bf=5 (odd), ans = 1*4 = 4
        x = 4*4 = 16, bf = 5/2 = 2

Step 3: bf=2 (even), ans=4
        x = 16*16 = 256, bf = 2/2 = 1

Step 4: bf=1 (odd), ans = 4*256 = 1024
        x = 256*256, bf = 1/2 = 0

Result: ans = 1024 = 2^10
```

### Binary Representation Insight

```
n = 10 (decimal) = 1010 (binary)
Position:          3210

Reading from right to left:
- Position 0: 0 (don't use x^1)
- Position 1: 1 (use x^2 = 4)
- Position 2: 0 (don't use x^4)
- Position 3: 1 (use x^8 = 256)

Result: x^2 × x^8 = 4 × 256 = 1024
```

### Alternative Approaches

1. **Recursive**: Divide and conquer approach with recursion
2. **Iterative Naive**: Multiply x by itself n times (O(n))
3. **Built-in Function**: Use math.pow() (language dependent)

### Edge Cases

1. **n = 0**: Any number to power 0 is 1
2. **x = 0**: 0 to any positive power is 0
3. **n = INT_MIN**: Use long to prevent overflow
4. **x = 1**: 1 to any power is 1
5. **x = -1**: Alternates between 1 and -1 based on even/odd n

### Constraints

- -100.0 < x < 100.0
- -2³¹ ≤ n ≤ 2³¹-1
- Either x is not zero or n > 0
- -10⁴ ≤ x^n ≤ 10⁴

### Source

[LeetCode 50 - Pow(x, n)](https://leetcode.com/problems/powx-n)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Pow(x, n) | Medium | ✅ Solved | Binary Exponentiation | O(log n) | O(1) |

## 🎯 Key Learnings

1. **Binary Exponentiation**: Efficient algorithm for computing powers in logarithmic time
2. **Bit Manipulation**: Using binary representation of exponent for optimization
3. **Overflow Handling**: Using long data type to prevent integer overflow
4. **Mathematical Optimization**: Converting O(n) naive approach to O(log n)

## 🚀 Next Steps

- Practice more mathematical algorithm problems
- Explore other applications of binary exponentiation
- Study modular exponentiation for large number problems
- Learn about matrix exponentiation for sequence problems

## 💡 Problem-Solving Tips

1. **Think Binary**: For exponentiation problems, consider binary representation
2. **Handle Edge Cases**: Negative exponents, zero base, overflow scenarios
3. **Optimize Iteratively**: Start with naive approach, then optimize
4. **Use Appropriate Data Types**: long for handling overflow, double for precision
