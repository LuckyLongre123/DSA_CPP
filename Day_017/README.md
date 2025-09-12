# Day 17: Sieve of Eratosthenes Mastery

## 🎯 Learning Objectives

By the end of this day, you will master:
- **Sieve of Eratosthenes**: The most efficient algorithm for finding multiple primes
- **Mathematical Optimization**: Understanding why sieve works and its optimizations
- **Prime Number Theory**: Fundamental concepts about prime distribution
- **Algorithm Efficiency**: Converting O(n²) to O(n log log n) complexity

---

## Problem 1: Count Primes (LeetCode 204)

### Problem Statement

**Difficulty**: Medium  
**Category**: Math, Array, Number Theory  
**Companies**: Amazon, Microsoft, Apple, Facebook, Google

Given an integer `n`, return the number of prime numbers that are less than `n`.

**Definition**: A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.

### Examples:

```
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Input: n = 0
Output: 0

Input: n = 1
Output: 0
```

### Approach

#### Sieve of Eratosthenes Algorithm

- **Time Complexity**: O(n log log n)
- **Space Complexity**: O(n)
- **Algorithm**:
  1. Create a boolean array `isPrime[0..n-1]` and initialize all entries as true
  2. Mark 0 and 1 as non-prime (false)
  3. Start with the first prime number, 2
  4. Mark all multiples of 2 (except 2 itself) as non-prime
  5. Find the next number that is still marked as prime and repeat step 4
  6. Continue until you process all numbers up to √n
  7. Count remaining prime numbers

```cpp
int countPrimes(int n) {
    if (n <= 2) return 0;
    
    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i < n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    int count = 0;
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) count++;
    }
    
    return count;
}
```

### Key Points

1. **Sieve of Eratosthenes**:
   - Ancient algorithm for finding all primes up to a given number
   - More efficient than checking each number individually
   - Works by eliminating multiples of each prime

2. **Optimization Details**:
   - Start marking multiples from `i * i` because smaller multiples already marked
   - Only check up to √n because larger factors would have been found already
   - Use boolean array for memory efficiency

3. **Why This Algorithm Works**:
   - Every composite number has a prime factor ≤ √n
   - By eliminating multiples of all primes ≤ √n, we find all primes ≤ n
   - Remaining unmarked numbers are prime

### Algorithm Walkthrough

```
Example: n = 10

Initial: isPrime = [F, F, T, T, T, T, T, T, T, T]
                    0  1  2  3  4  5  6  7  8  9

Step 1: i = 2 (first prime)
Mark multiples: 4, 6, 8
Result: isPrime = [F, F, T, T, F, T, F, T, F, T]

Step 2: i = 3 (next prime)
Mark multiples: 9 (6 already marked)
Result: isPrime = [F, F, T, T, F, T, F, T, F, F]

Step 3: i = 4, but 4*4 = 16 > 10, so stop

Count primes: 2, 3, 5, 7 → Total = 4
```

### Visual Representation

```
Sieve Process for n = 30:

Numbers: 2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
Step 1:  2  3  X  5  X  7  X  9  X  11 X  13 X  15 X  17 X  19 X  21 X  23 X  25 X  27 X  29
Step 2:  2  3  X  5  X  7  X  X  X  11 X  13 X  X  X  17 X  19 X  X  X  23 X  25 X  X  X  29
Step 3:  2  3  X  5  X  7  X  X  X  11 X  13 X  X  X  17 X  19 X  X  X  23 X  X  X  X  X  29

Primes: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 (Total: 10)
```

### Edge Cases

1. **n ≤ 2**: No primes less than 2, return 0
2. **n = 3**: Only prime 2, return 1
3. **Large n**: Algorithm remains efficient due to O(n log log n) complexity

### Alternative Approaches

1. **Brute Force**: Check each number individually - O(n√n)
2. **Optimized Trial Division**: Check divisibility up to √i for each i - O(n√n)
3. **Segmented Sieve**: For very large numbers - O(n log log n) with better space

### Mathematical Insights

1. **Prime Number Theorem**: Approximately n/ln(n) primes less than n
2. **Sieve Complexity**: O(n log log n) comes from harmonic series of primes
3. **Space-Time Tradeoff**: Uses O(n) space for O(n log log n) time efficiency

### Constraints

- 0 ≤ n ≤ 5 × 10⁶

### Source

[LeetCode 204 - Count Primes](https://leetcode.com/problems/count-primes)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Count Primes | Medium | ✅ Solved | Sieve of Eratosthenes | O(n log log n) | O(n) |

## 🎯 Key Learnings

1. **Sieve of Eratosthenes**: Classical algorithm for prime generation
2. **Mathematical Optimization**: Starting from i² and checking up to √n
3. **Algorithmic Efficiency**: Achieving sub-quadratic time complexity
4. **Memory Management**: Using boolean arrays for space efficiency

## 🚀 Next Steps

- Practice more number theory problems
- Study advanced prime algorithms (Miller-Rabin, Pollard's Rho)
- Explore segmented sieve for larger ranges
- Learn about prime factorization techniques

## 💡 Problem-Solving Tips

1. **Recognize Pattern**: Prime counting suggests sieve algorithms
2. **Optimize Early**: Start from i² instead of 2i for efficiency
3. **Boundary Conditions**: Handle edge cases (n ≤ 2) first
4. **Space Efficiency**: Use boolean array instead of integer array
