# Day 20: Dynamic Programming - Fibonacci Number

## Problem 1: Fibonacci Number

### Problem Description

The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is:

```
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
```

Given `n`, calculate `F(n)`.

### Examples:

```
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
```

### Approach

#### Iterative Dynamic Programming

- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **Key Insight**: Only need previous two values to calculate current Fibonacci number
- **Algorithm**:
  1. Handle base cases: F(0) = 0, F(1) = 1
  2. Use three variables to track F(i-2), F(i-1), and F(i)
  3. Iteratively calculate from F(2) to F(n)
  4. Update variables for next iteration

```cpp
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev2 = 0;  // F(i-2)
    int prev1 = 1;  // F(i-1)
    int curr;       // F(i)
    
    for (int i = 2; i <= n; ++i) {
        curr = prev1 + prev2;  // F(i) = F(i-1) + F(i-2)
        prev2 = prev1;         // Update for next iteration
        prev1 = curr;
    }

    return curr;
}
```

### Key Points

1. **Fibonacci Sequence Properties**:
   - Each number is sum of two preceding numbers
   - Starts with 0 and 1
   - Grows exponentially: F(n) ≈ φⁿ/√5 where φ = (1+√5)/2

2. **Space Optimization**:
   - Instead of storing all previous values, only keep last two
   - Reduces space from O(n) to O(1)
   - Maintains O(n) time complexity

3. **Iterative vs Recursive**:
   - Iterative: O(n) time, O(1) space
   - Naive recursive: O(2ⁿ) time, O(n) space
   - Memoized recursive: O(n) time, O(n) space

### Algorithm Walkthrough

```
Example: n = 5

Initial: prev2=0, prev1=1

i=2: curr = 1+0 = 1, prev2=1, prev1=1  → F(2)=1
i=3: curr = 1+1 = 2, prev2=1, prev1=2  → F(3)=2
i=4: curr = 2+1 = 3, prev2=2, prev1=3  → F(4)=3
i=5: curr = 3+2 = 5, prev2=3, prev1=5  → F(5)=5

Return curr = 5
```

### Visual Representation

```
Fibonacci Sequence:
F(0) F(1) F(2) F(3) F(4) F(5) F(6) F(7) F(8) ...
 0    1    1    2    3    5    8   13   21  ...

Iterative Process:
Step 1: [0, 1] → 1
Step 2: [1, 1] → 2  
Step 3: [1, 2] → 3
Step 4: [2, 3] → 5
Step 5: [3, 5] → 8
...

Space Usage:
Only 3 variables needed regardless of n
```

### Different Approaches Comparison

| Approach | Time Complexity | Space Complexity | Description |
|----------|----------------|------------------|-------------|
| Naive Recursive | O(2ⁿ) | O(n) | Recalculates same values |
| Memoized Recursive | O(n) | O(n) | Stores calculated values |
| Iterative DP | O(n) | O(1) | Bottom-up calculation |
| Matrix Exponentiation | O(log n) | O(1) | Advanced mathematical approach |
| Binet's Formula | O(1) | O(1) | Direct formula (precision issues) |

### Implementation Variants

```cpp
// Variant 1: Standard iterative
int fib(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

// Variant 2: Using array (O(n) space)
int fib(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Variant 3: Recursive with memoization
class Solution {
    unordered_map<int, int> memo;
public:
    int fib(int n) {
        if (n <= 1) return n;
        if (memo.count(n)) return memo[n];
        return memo[n] = fib(n-1) + fib(n-2);
    }
};
```

### Mathematical Properties

1. **Golden Ratio Relationship**: F(n) ≈ φⁿ/√5 where φ = (1+√5)/2
2. **Binet's Formula**: F(n) = (φⁿ - ψⁿ)/√5 where ψ = (1-√5)/2
3. **Divisibility**: gcd(F(m), F(n)) = F(gcd(m, n))
4. **Sum Formula**: F(0) + F(1) + ... + F(n) = F(n+2) - 1

### Edge Cases

1. **n = 0**: Return 0
2. **n = 1**: Return 1
3. **Large n**: May cause integer overflow (consider using long long)
4. **Negative n**: Problem doesn't specify, typically undefined

### Applications

1. **Computer Science**: Algorithm analysis, recursive problem solving
2. **Mathematics**: Number theory, combinatorics
3. **Nature**: Spiral patterns, population growth models
4. **Finance**: Technical analysis, market patterns

### Constraints

- 0 ≤ n ≤ 30

### Source

[LeetCode 509 - Fibonacci Number](https://leetcode.com/problems/fibonacci-number)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Fibonacci Number | Easy | ✅ Solved | Iterative DP | O(n) | O(1) |

## 🎯 Key Learnings

1. **Dynamic Programming**: Bottom-up approach for optimal substructure problems
2. **Space Optimization**: Reducing space complexity from O(n) to O(1)
3. **Iterative vs Recursive**: Trade-offs between different implementation approaches
4. **Mathematical Sequences**: Understanding Fibonacci properties and applications

## 🚀 Next Steps

- Practice more DP problems (climbing stairs, house robber)
- Study matrix exponentiation for O(log n) Fibonacci
- Learn about other famous sequences (Tribonacci, Lucas numbers)
- Explore applications in combinatorics and optimization

## 💡 Problem-Solving Tips

1. **Identify Recurrence**: Look for F(n) = F(n-1) + F(n-2) pattern
2. **Optimize Space**: Use variables instead of arrays when possible
3. **Handle Base Cases**: Always check n=0 and n=1 conditions
4. **Consider Overflow**: Use appropriate data types for large numbers
