# Day 21: Mathematical Algorithms - Binary Exponentiation

## Problem 1: Pow(x, n)

### Problem Description

Implement `pow(x, n)`, which calculates `x` raised to the power `n` (i.e., `xⁿ`).

### Examples:

```
Input: x = 2.00000, n = 10
Output: 1024.00000

Input: x = 2.10000, n = 3
Output: 9.26100

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
```

### Approach

#### Binary Exponentiation (Fast Exponentiation)

- **Time Complexity**: O(log n)
- **Space Complexity**: O(1)
- **Key Insight**: Use bit manipulation to reduce multiplications
- **Algorithm**:
  1. Handle negative exponent by converting to 1/x and making n positive
  2. Use binary representation of n to determine when to multiply
  3. Square base and halve exponent in each iteration

```cpp
double myPow(double x, int n) {
    long bf = n;
    
    if(n < 0){
        x = 1/x;
        bf = -bf;
    }
    
    double ans = 1;

    while(bf > 0){
        if(bf % 2 == 1) ans *= x;
        x *= x;
        bf /= 2;
    }
    
    return ans;
}
```

### Key Points

1. **Binary Exponentiation Logic**:
   - Convert exponent to binary representation
   - Use squaring strategy: x² → x⁴ → x⁸ → x¹⁶ ...
   - Only multiply when corresponding bit is 1

2. **Negative Exponent Handling**:
   - Convert x^(-n) to (1/x)^n
   - Use long to handle INT_MIN overflow when negating

3. **Efficiency**:
   - Reduces O(n) naive approach to O(log n)
   - Uses constant space O(1)

### Algorithm Walkthrough

```
Example: 2^10

10 in binary: 1010
2^10 = 2^8 × 2^2

Steps:
- Start: ans=1, x=2, n=10
- n=10 (even): x=4, n=5
- n=5 (odd): ans=1×4=4, x=16, n=2
- n=2 (even): x=256, n=1
- n=1 (odd): ans=4×256=1024, n=0

Result: 1024
```

### Visual Representation

```
Binary Exponentiation for x^13:
13 = 8 + 4 + 1 = 2³ + 2² + 2⁰
x^13 = x^8 × x^4 × x^1

Binary: 1101
        ↓↓↓↓
        8421
        
Process:
- Bit 0 (1): multiply by x^1
- Bit 1 (0): skip x^2
- Bit 2 (1): multiply by x^4
- Bit 3 (1): multiply by x^8
```

### Edge Cases

1. **n = 0**: Any number to power 0 is 1
2. **x = 0**: 0 to any positive power is 0
3. **Negative n**: Use reciprocal and positive exponent
4. **INT_MIN**: Handle overflow when negating (-2³¹ → 2³¹)

### Alternative Approaches

1. **Naive Iterative**: O(n) time - multiply x by itself n times
2. **Recursive Binary**: O(log n) time, O(log n) space
3. **Built-in Function**: Use `pow()` from `<cmath>`

### Mathematical Insight

Binary exponentiation exploits the property:
- x^(a+b) = x^a × x^b
- x^(2k) = (x^k)²
- x^(2k+1) = x × (x^k)²

This allows us to build the result by combining powers of 2.

### Constraints

- -100.0 < x < 100.0
- -2³¹ ≤ n ≤ 2³¹-1

### Source

[LeetCode 50 - Pow(x, n)](https://leetcode.com/problems/powx-n)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Pow(x, n) | Medium | ✅ Solved | Binary Exponentiation | O(log n) | O(1) |

## 🎯 Key Learnings

1. **Binary Exponentiation**: Efficient power calculation using bit manipulation
2. **Bit Operations**: Understanding binary representation for optimization
3. **Overflow Handling**: Managing edge cases with integer limits
4. **Mathematical Optimization**: Reducing exponential to logarithmic complexity

## 🚀 Next Steps

- Practice more bit manipulation problems
- Study modular exponentiation for large numbers
- Learn about matrix exponentiation
- Explore other mathematical optimization techniques

## 💡 Problem-Solving Tips

1. **Power Problems**: Consider binary exponentiation for O(log n) solution
2. **Negative Handling**: Convert negative exponents to positive with reciprocal
3. **Bit Analysis**: Use binary representation to optimize repeated operations
4. **Edge Cases**: Always handle n=0, x=0, and overflow scenarios
