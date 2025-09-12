# Day 15: Binary Search on Answer Space Mastery

## 🎯 Learning Objectives

By the end of this day, you will master:
- **Binary Search on Answer**: Searching in solution space rather than array elements
- **Overflow Prevention**: Handling large number multiplication safely
- **Mathematical Optimization**: Converting O(√n) to O(log n) complexity
- **Precision Handling**: Managing integer vs floating-point square roots

---

## Problem 1: Sqrt(x) (LeetCode 69)

### Problem Statement

**Difficulty**: Easy  
**Category**: Binary Search, Math  
**Companies**: Amazon, Microsoft, Apple, Facebook, Google

Given a non-negative integer `x`, return the square root of `x` rounded down to the nearest integer. The returned integer should be **non-negative** as well.

**Key Constraint**: You must not use any built-in exponent function or operator.

### Examples:

```
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2.

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.828..., and since we round it down to the nearest integer, 2 is returned.

Input: x = 1
Output: 1

Input: x = 0
Output: 0
```

### Approach

#### Binary Search Technique

- **Time Complexity**: O(log x)
- **Space Complexity**: O(1)
- **Algorithm**:
  1. Handle edge cases: `x = 0` returns 0, `x = 1` returns 1
  2. Set search boundaries: `start = 0`, `end = x - 1`
  3. Use binary search to find the largest integer whose square ≤ x
  4. For each `mid`, calculate `mid²`:
     - If `mid² = x`: Found exact square root, return `mid`
     - If `mid² < x`: Store `mid` as potential answer, search right half
     - If `mid² > x`: Search left half
  5. Return the stored answer (largest valid square root)

```cpp
int mySqrt(int x) {
    // Initialize binary search boundaries
    int s = 0;          // Start pointer
    int e = x - 1;      // End pointer (x-1 because sqrt(x) < x for x > 1)
    int ans = -1;       // Variable to store the answer

    // Handle edge cases
    if(x == 0) return 0;    // sqrt(0) = 0
    if(x == 1) return 1;    // sqrt(1) = 1
    
    // Binary search to find the square root
    while(s <= e) {
        // Calculate mid point to avoid integer overflow
        long long int mid = s + (e - s) / 2;
        
        // Calculate square of mid using long long to prevent overflow
        long long int sqr = mid * mid;

        // If perfect square found, return immediately
        if(sqr == x) return mid;
        
        // If mid^2 < x, mid could be our answer
        // Update ans and search in right half for potentially larger answer
        else if(sqr < x) {
            ans = mid;          // Store current valid answer
            s = mid + 1;        // Search right half
        }
        // If mid^2 > x, search in left half
        else {
            e = mid - 1;        // Search left half
        }
    }
    
    // Return the largest integer whose square is <= x
    return ans;
}
```

### Key Points

1. **Binary Search Logic**:
   - **Search Space**: [0, x-1] for x > 1
   - **Target**: Find largest integer `i` such that `i² ≤ x`
   - **Answer Storage**: Keep track of valid candidates during search

2. **Overflow Prevention**:
   - Use `long long` for mid and square calculations
   - Prevents integer overflow when calculating `mid * mid`
   - Calculate mid as `s + (e - s) / 2` to avoid overflow

3. **Edge Case Handling**:
   - `x = 0`: Direct return 0
   - `x = 1`: Direct return 1
   - For x > 1: Use binary search in range [0, x-1]

### Algorithm Walkthrough

```
Example: x = 8

Initial: s=0, e=7, ans=-1
Search space: [0, 1, 2, 3, 4, 5, 6, 7]

Step 1: mid = 3, sqr = 9
        9 > 8, so search left half
        s=0, e=2

Step 2: mid = 1, sqr = 1
        1 < 8, so ans = 1, search right half
        s=2, e=2

Step 3: mid = 2, sqr = 4
        4 < 8, so ans = 2, search right half
        s=3, e=2 (s > e, exit loop)

Return: ans = 2
```

### Visual Representation

```
Finding sqrt(8):

Search Space: [0, 1, 2, 3, 4, 5, 6, 7]
Target: Largest i where i² ≤ 8

Step 1: Check mid=3
        3² = 9 > 8 ❌
        Search left: [0, 1, 2]

Step 2: Check mid=1  
        1² = 1 < 8 ✅ (ans = 1)
        Search right: [2]

Step 3: Check mid=2
        2² = 4 < 8 ✅ (ans = 2)
        Search right: [] (empty)

Result: 2 (since 2² = 4 ≤ 8 < 9 = 3²)
```

### Edge Cases

1. **Perfect Squares**: `x = 4, 9, 16, 25` → Return exact square root
2. **Zero**: `x = 0` → Return 0
3. **One**: `x = 1` → Return 1
4. **Large Numbers**: Handle integer overflow with `long long`
5. **Non-Perfect Squares**: Return floor of square root

### Alternative Approaches

1. **Newton's Method**: Iterative approximation (faster convergence)
2. **Linear Search**: O(√x) time complexity (less efficient)
3. **Built-in Functions**: `sqrt()` function (not allowed in problem)
4. **Bit Manipulation**: Using bit shifts for powers of 2

### Mathematical Insight

For any positive integer `x`:
- If `x` is a perfect square: `sqrt(x)` is an integer
- If `x` is not a perfect square: `floor(sqrt(x))` is the answer
- Search range: `[0, x]` but can be optimized to `[0, x/2]` for `x ≥ 4`

### Constraints

- 0 ≤ x ≤ 2³¹ - 1
- Must not use built-in exponent functions
- Return type: integer (rounded down)

### Source

[LeetCode 69 - Sqrt(x)](https://leetcode.com/problems/sqrtx)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Sqrt(x) | Easy | ✅ Solved | Binary Search | O(log x) | O(1) |

## 🎯 Key Learnings

1. **Binary Search Applications**: Not just for sorted arrays, but for finding answers in ranges
2. **Overflow Prevention**: Using `long long` for intermediate calculations
3. **Answer Tracking**: Storing valid candidates during binary search
4. **Mathematical Optimization**: Reducing search space using mathematical properties

## 🚀 Next Steps

- Practice more binary search on answer problems
- Explore Newton's method for square root calculation
- Study other mathematical binary search applications
- Learn about binary search on floating-point ranges

## 💡 Problem-Solving Tips

1. **Binary Search on Answer**: When looking for a specific value in a range
2. **Handle Overflow**: Use larger data types for intermediate calculations
3. **Store Valid Answers**: Keep track of candidates that satisfy conditions
4. **Edge Cases First**: Handle special cases before main algorithm
