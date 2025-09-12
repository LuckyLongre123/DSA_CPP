# Day 21: Binary Exponentiation Mastery

## 🎯 Learning Objectives

By the end of this day, you will master:
- **Binary Exponentiation**: Efficient power calculation using divide-and-conquer
- **Mathematical Optimization**: Converting O(n) to O(log n) complexity
- **Bit Manipulation**: Using binary representation for algorithmic optimization
- **Edge Case Handling**: Managing negative exponents and overflow scenarios
- **Recursive vs Iterative**: Understanding different implementation approaches
- **Mathematical Properties**: Exploiting exponentiation laws for efficiency

---

## Problem 1: Pow(x, n) (LeetCode 50)

### Problem Statement

**Difficulty**: Medium  
**Category**: Math, Recursion, Divide and Conquer  
**Companies**: Amazon, Microsoft, Apple, Facebook, Google

Implement `pow(x, n)`, which calculates `x` raised to the power `n` (i.e., `x^n`).

**Key Challenge**: You must write an algorithm with better than O(n) time complexity.

### 💡 Examples with Detailed Analysis

**Example 1: Positive Integer Exponent**
```
Input: x = 2.00000, n = 10
Output: 1024.00000

Explanation:
2^10 = 1024
Binary of 10: 1010
10 = 8 + 2 = 2³ + 2¹
2^10 = 2^8 × 2^2 = 256 × 4 = 1024
```

**Example 2: Decimal Base**
```
Input: x = 2.10000, n = 3
Output: 9.26100

Explanation:
2.1^3 = 2.1 × 2.1 × 2.1 = 9.261
Binary of 3: 11
3 = 2 + 1 = 2¹ + 2⁰
2.1^3 = 2.1^2 × 2.1^1 = 4.41 × 2.1 = 9.261
```

**Example 3: Negative Exponent**
```
Input: x = 2.00000, n = -2
Output: 0.25000

Explanation:
2^(-2) = 1/(2^2) = 1/4 = 0.25
Convert to: (1/2)^2 = 0.5^2 = 0.25
```

**Example 4: Edge Cases**
```
Input: x = 1.00000, n = -2147483648 (INT_MIN)
Output: 1.00000
Explanation: 1 raised to any power is 1

Input: x = 2.00000, n = 0
Output: 1.00000
Explanation: Any number to power 0 is 1
```

### 🚀 Approach: Binary Exponentiation (Fast Exponentiation)

#### 🔍 Core Intuition

Instead of multiplying x by itself n times (O(n)), we can use the binary representation of n to reduce the number of multiplications to O(log n).

**Key Mathematical Insight:**
- x^n can be broken down using binary representation of n
- If n = b₁×2¹ + b₂×2² + ... + bₖ×2ᵏ (binary form)
- Then x^n = x^(b₁×2¹) × x^(b₂×2²) × ... × x^(bₖ×2ᵏ)

#### 📊 Complexity Analysis
- **Time Complexity**: O(log n) - we halve n in each iteration
- **Space Complexity**: O(1) - only using constant extra space
- **Optimization**: Reduces from O(n) naive approach

#### 🔧 Algorithm Steps
1. **Handle Negative Exponent**: Convert x^(-n) to (1/x)^n
2. **Binary Processing**: Use binary representation of n
3. **Squaring Strategy**: Square base and halve exponent iteratively
4. **Conditional Multiplication**: Multiply result when bit is 1

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

### 🔄 Detailed Algorithm Walkthrough

**Example 1: Computing 2^10**
```
10 in binary: 1010 (reading right to left: positions 1 and 3 are set)
2^10 = 2^(8+2) = 2^8 × 2^2

Step-by-step execution:
Initial: ans = 1, x = 2, n = 10

Iteration 1: n = 10 (1010₂)
  - n % 2 = 0 (even) → don't multiply
  - x = x² = 2² = 4
  - n = n/2 = 5
  - ans = 1

Iteration 2: n = 5 (101₂)
  - n % 2 = 1 (odd) → multiply: ans = ans × x = 1 × 4 = 4
  - x = x² = 4² = 16
  - n = n/2 = 2
  - ans = 4

Iteration 3: n = 2 (10₂)
  - n % 2 = 0 (even) → don't multiply
  - x = x² = 16² = 256
  - n = n/2 = 1
  - ans = 4

Iteration 4: n = 1 (1₂)
  - n % 2 = 1 (odd) → multiply: ans = ans × x = 4 × 256 = 1024
  - x = x² = 256² = 65536 (not used)
  - n = n/2 = 0
  - ans = 1024

Final Result: 1024 ✅
```

**Example 2: Computing 3^13 with Binary Analysis**
```
13 in binary: 1101₂ = 8 + 4 + 1 = 2³ + 2² + 2⁰
3^13 = 3^8 × 3^4 × 3^1

Binary breakdown:
Position: 3 2 1 0
Binary:   1 1 0 1
Power:    8 4 2 1
Use:      ✓ ✓ ✗ ✓

Result: 3^8 × 3^4 × 3^1 = 6561 × 81 × 3 = 1,594,323
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

### 🚨 Comprehensive Edge Cases

#### 1. **Exponent Edge Cases**
```cpp
// n = 0: Any number^0 = 1
myPow(5.0, 0) → 1.0
myPow(-3.0, 0) → 1.0
myPow(0.0, 0) → 1.0  // Mathematical convention

// n = 1: Any number^1 = itself
myPow(7.5, 1) → 7.5
myPow(-2.0, 1) → -2.0
```

#### 2. **Base Edge Cases**
```cpp
// x = 0: 0^positive = 0, 0^0 = 1 (by convention)
myPow(0.0, 5) → 0.0
myPow(0.0, 0) → 1.0

// x = 1: 1^anything = 1
myPow(1.0, 1000000) → 1.0
myPow(1.0, -1000000) → 1.0

// x = -1: Alternates between 1 and -1
myPow(-1.0, 4) → 1.0   // Even power
myPow(-1.0, 5) → -1.0  // Odd power
```

#### 3. **Negative Exponent Handling**
```cpp
// Convert x^(-n) to (1/x)^n
myPow(2.0, -3) → (1/2.0)^3 → 0.125
myPow(0.5, -2) → (1/0.5)^2 → 2.0^2 → 4.0
```

#### 4. **Integer Overflow (Critical)**
```cpp
// INT_MIN = -2,147,483,648 cannot be negated safely
// -(-2,147,483,648) = 2,147,483,648 > INT_MAX
// Solution: Use long long for safe negation
long long bf = n;
if (n < 0) {
    x = 1.0 / x;
    bf = -bf;  // Safe with long long
}
```

#### 5. **Precision Considerations**
```cpp
// Very large positive exponents may cause overflow
myPow(2.0, 1000) → May exceed double precision

// Very large negative exponents may cause underflow
myPow(2.0, -1000) → May approach 0.0
```

### 🔄 Alternative Approaches with Analysis

#### Approach 1: Naive Iterative (Brute Force)
```cpp
double naivePow(double x, int n) {
    if (n == 0) return 1.0;
    
    bool negative = n < 0;
    if (negative) {
        x = 1.0 / x;
        n = -n;
    }
    
    double result = 1.0;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    
    return result;
}
```
**Analysis:**
- **Time**: O(n) - n multiplications
- **Space**: O(1)
- **Pros**: Simple to understand and implement
- **Cons**: Too slow for large n, may cause timeout

#### Approach 2: Recursive Binary Exponentiation
```cpp
double recursivePow(double x, long long n) {
    if (n == 0) return 1.0;
    if (n == 1) return x;
    
    if (n % 2 == 0) {
        double half = recursivePow(x, n / 2);
        return half * half;
    } else {
        return x * recursivePow(x, n - 1);
    }
}

double myPow(double x, int n) {
    long long bf = n;
    if (n < 0) {
        x = 1.0 / x;
        bf = -bf;
    }
    return recursivePow(x, bf);
}
```
**Analysis:**
- **Time**: O(log n) - halving at each recursive call
- **Space**: O(log n) - recursion stack depth
- **Pros**: Clean and intuitive recursive structure
- **Cons**: Uses extra space for recursion stack

#### Approach 3: Iterative Binary Exponentiation (Optimal)
```cpp
double myPow(double x, int n) {
    long long bf = n;
    
    if (n < 0) {
        x = 1.0 / x;
        bf = -bf;
    }
    
    double result = 1.0;
    double current_power = x;
    
    while (bf > 0) {
        if (bf % 2 == 1) {
            result *= current_power;
        }
        current_power *= current_power;
        bf /= 2;
    }
    
    return result;
}
```
**Analysis:**
- **Time**: O(log n) - optimal time complexity
- **Space**: O(1) - constant space usage
- **Pros**: Best space efficiency, no recursion overhead
- **Cons**: Slightly more complex logic

#### Approach 4: Built-in Function
```cpp
#include <cmath>
double myPow(double x, int n) {
    return std::pow(x, n);
}
```
**Analysis:**
- **Time**: O(1) or O(log n) depending on implementation
- **Space**: O(1)
- **Pros**: Simplest implementation, highly optimized
- **Cons**: Not allowed in interviews, doesn't show algorithmic thinking

#### Approach 5: Matrix Exponentiation (Advanced)
```cpp
// For computing Fibonacci numbers using matrix exponentiation
// [[1,1],[1,0]]^n gives Fibonacci sequence
// This approach extends binary exponentiation to matrices
```
**Use Case**: Computing recurrence relations efficiently

### 🧮 Mathematical Insights and Properties

#### Core Mathematical Properties

**1. Exponentiation Laws:**
```
x^(a+b) = x^a × x^b     (Addition rule)
x^(a×b) = (x^a)^b       (Multiplication rule)
x^(-a) = 1/(x^a)        (Negative exponent rule)
x^0 = 1                 (Zero exponent rule)
```

**2. Binary Decomposition:**
```
Any integer n can be written as: n = Σ(bᵢ × 2ⁱ) where bᵢ ∈ {0,1}
Therefore: x^n = x^(Σ(bᵢ × 2ⁱ)) = Π(x^(bᵢ × 2ⁱ))

Example: 13 = 8 + 4 + 1 = 2³ + 2² + 2⁰
So: x^13 = x^8 × x^4 × x^1
```

**3. Squaring Strategy:**
```
x^(2k) = (x^k)²         (Even exponent)
x^(2k+1) = x × (x^k)²   (Odd exponent)

This allows us to build powers of 2 efficiently:
x¹ → x² → x⁴ → x⁸ → x¹⁶ → ...
```

#### Why Binary Exponentiation Works

**Bit-by-Bit Processing:**
```
For n = 13 (binary: 1101):
Bit 0 (value 1): Include x^1 in result
Bit 1 (value 0): Skip x^2
Bit 2 (value 1): Include x^4 in result  
Bit 3 (value 1): Include x^8 in result

Final: x^1 × x^4 × x^8 = x^13
```

**Efficiency Analysis:**
```
Naive: x × x × x × ... × x (n times) = O(n)
Binary: Build x^1, x^2, x^4, x^8, ... and combine = O(log n)

For n = 1000:
Naive: 1000 multiplications
Binary: ~10 multiplications (log₂(1000) ≈ 10)
```

#### Real-World Applications

**1. Cryptography:**
- RSA encryption uses modular exponentiation
- Computing (base^exponent) mod prime efficiently

**2. Computer Graphics:**
- Bezier curve calculations
- Transformation matrix powers

**3. Scientific Computing:**
- Numerical analysis algorithms
- Physics simulations with exponential growth/decay

**4. Competitive Programming:**
- Fast computation of large powers
- Matrix exponentiation for recurrence relations

### Constraints

- -100.0 < x < 100.0
- -2³¹ ≤ n ≤ 2³¹-1

### Source

[LeetCode 50 - Pow(x, n)](https://leetcode.com/problems/powx-n)

---

## 🎮 Practice Exercises

### Exercise 1: Manual Calculation
Trace through the binary exponentiation algorithm for these cases:
- Compute 3^11 step by step
- Compute 5^16 using binary representation
- Handle 2^(-5) with negative exponent conversion

### Exercise 2: Implementation Variations
- Implement the recursive version of binary exponentiation
- Add detailed logging to show each step of the algorithm
- Implement modular exponentiation: (base^exp) % mod

### Exercise 3: Edge Case Testing
- Test with INT_MIN exponent
- Test with base = 0, 1, -1
- Test with very large exponents (close to INT_MAX)

### Exercise 4: Performance Analysis
- Compare naive vs binary exponentiation for different input sizes
- Measure actual execution time for large exponents
- Analyze memory usage patterns

---

## 🧠 Memory Tips and Mnemonics

### Binary Exponentiation
**Remember**: "Square and Skip, Multiply when Odd"
- **Square**: Always square the base (x = x²)
- **Skip**: Skip multiplication when exponent bit is 0
- **Multiply**: Multiply result when exponent bit is 1
- **Odd**: Check if current exponent is odd (n % 2 == 1)

### Negative Exponent
**Remember**: "Flip and Negate"
- **Flip**: Convert x to 1/x
- **Negate**: Make exponent positive

### Overflow Prevention
**Remember**: "Long Long for Safety"
- Use `long long` to handle INT_MIN safely

---

## 💡 Real-World Problem Extensions

### 1. Modular Exponentiation
```cpp
// Compute (base^exp) % mod efficiently
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
```
**Applications**: Cryptography, number theory problems

### 2. Matrix Exponentiation
```cpp
// For computing Fibonacci numbers in O(log n)
// F(n) = [[1,1],[1,0]]^n * [[F(1)],[F(0)]]
vector<vector<long long>> matrixPower(vector<vector<long long>>& mat, int n);
```
**Applications**: Recurrence relations, dynamic programming optimization

### 3. Fast Doubling for Fibonacci
```cpp
// F(2n) = F(n) * (2*F(n+1) - F(n))
// F(2n+1) = F(n+1)² + F(n)²
pair<long long, long long> fibFast(int n);
```
**Applications**: Competitive programming, mathematical sequences

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Pow(x, n) | Medium | ✅ Solved | Binary Exponentiation | O(log n) | O(1) |

## 🎯 Key Learnings

1. **Binary Exponentiation**: Efficient power calculation using bit manipulation
2. **Mathematical Optimization**: Converting O(n) to O(log n) complexity
3. **Bit Operations**: Understanding binary representation for optimization
4. **Overflow Handling**: Managing edge cases with integer limits
5. **Algorithm Design**: Divide-and-conquer approach to mathematical problems
6. **Real-World Applications**: Cryptography, graphics, scientific computing

## 🚀 Next Steps

- Practice modular exponentiation problems (RSA, number theory)
- Study matrix exponentiation for recurrence relations
- Learn fast doubling techniques for Fibonacci sequences
- Explore other mathematical optimization techniques
- Practice bit manipulation and divide-and-conquer problems
- Study advanced topics: Chinese Remainder Theorem, Fermat's Little Theorem

## 💡 Problem-Solving Tips

1. **Power Problems**: Always consider binary exponentiation for O(log n) solution
2. **Negative Handling**: Convert negative exponents to positive with reciprocal
3. **Bit Analysis**: Use binary representation to optimize repeated operations
4. **Edge Cases**: Always handle n=0, x=0, and overflow scenarios
5. **Modular Arithmetic**: For large numbers, use modular exponentiation
6. **Pattern Recognition**: Look for opportunities to apply divide-and-conquer

---

**Total Problems Mastered**: 1

*Master the art of efficient computation! ⚡*
