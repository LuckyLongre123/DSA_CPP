# Day 11: Array and Bit Manipulation Fundamentals

## 🎯 Learning Objectives

By the end of this day, you will master:
- **Array Traversal Patterns**: Understanding nested loops and index management
- **Hash Map Optimization**: Converting O(n²) to O(n) solutions
- **Bit Manipulation Fundamentals**: Using bitwise operations for mathematical checks
- **Problem Analysis**: Breaking down complex requirements into simple steps

---

## Problem 1: Two Sum (LeetCode 1)

### 📋 Problem Statement

**Difficulty**: Easy  
**Category**: Array, Hash Table  
**Companies**: Amazon, Google, Facebook, Microsoft

Given an array of integers `nums` and an integer `target`, return **indices** of the two numbers in `nums` such that they add up to `target`.

**Key Constraints:**
- Each input has exactly **one solution**
- You cannot use the same element twice
- Return the **indices**, not the values

### 🔍 Problem Analysis

**What we need to find:** Two indices `i` and `j` where `nums[i] + nums[j] = target`

**Input/Output Pattern:**
- **Input**: Array of integers + target sum
- **Output**: Array containing two indices
- **Guarantee**: Solution always exists

### 📚 Examples with Detailed Explanations

#### Example 1: Basic Case
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Step-by-step analysis:
- Check nums[0] = 2, need 9-2 = 7
- Check nums[1] = 7, matches our need!
- Return indices [0,1]

Verification: nums[0] + nums[1] = 2 + 7 = 9 ✓
```

#### Example 2: Non-adjacent Elements
```
Input: nums = [3,2,4], target = 6
Output: [1,2]

Step-by-step analysis:
- Check nums[0] = 3, need 6-3 = 3
- Check nums[1] = 2, need 6-2 = 4
- Check nums[2] = 4, matches our need from step 2!
- Return indices [1,2]

Verification: nums[1] + nums[2] = 2 + 4 = 6 ✓
```

#### Example 3: Duplicate Values
```
Input: nums = [3,3], target = 6
Output: [0,1]

Step-by-step analysis:
- Check nums[0] = 3, need 6-3 = 3
- Check nums[1] = 3, matches our need!
- Return indices [0,1]

Note: Same values, different indices - this is allowed!
Verification: nums[0] + nums[1] = 3 + 3 = 6 ✓
```

### 🔄 Solution Approaches

#### Approach 1: Brute Force (Nested Loops)

**💡 Core Idea**: Check every possible pair of numbers

**📊 Complexity Analysis**:
- **Time Complexity**: O(n²) - nested loops
- **Space Complexity**: O(1) - only using variables

**🔍 Algorithm Steps**:
1. **Outer Loop**: For each element at index `i` (0 to n-2)
2. **Inner Loop**: For each element at index `j` (i+1 to n-1)
3. **Check Sum**: If `nums[i] + nums[j] == target`
4. **Return Result**: Return `[i, j]` immediately
5. **No Solution**: Return empty array (won't happen per constraints)

**🎯 Why i+1 in inner loop?**
- Avoids using same element twice
- Prevents duplicate pairs like [1,0] and [0,1]
- Ensures we only check each pair once

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    int l = nums.size();
    vector<int> myarr;
    
    for (int i = 0; i < l; i++) {
        for (int j = i + 1; j < l; j++) {
            if (nums[i] + nums[j] == target) {
                myarr.push_back(i);
                myarr.push_back(j);
                return myarr;
            }
        }
    }
    return {};
}
```

#### Approach 2: Hash Map (Optimized) ⭐

**💡 Core Idea**: Use hash map to remember what we've seen and what we need

**📊 Complexity Analysis**:
- **Time Complexity**: O(n) - single pass through array
- **Space Complexity**: O(n) - hash map storage

**🔍 Algorithm Steps**:
1. **Initialize**: Create empty hash map `{value → index}`
2. **For each element**: Calculate `complement = target - nums[i]`
3. **Check Map**: If complement exists in map, return `[map[complement], i]`
4. **Store**: Add current `{nums[i] → i}` to map
5. **Continue**: Move to next element

**🎯 Key Insight**: We're looking for `x + y = target`, so if we see `x`, we need `y = target - x`

**📝 Hash Map Implementation**:
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen; // {value → index}
    
    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // Check if we've seen the complement before
        if(seen.find(complement) != seen.end()) {
            return {seen[complement], i};
        }
        
        // Store current number and its index
        seen[nums[i]] = i;
    }
    
    return {}; // No solution (won't happen per constraints)
}
```

**🔄 Trace Example**: `nums = [2,7,11,15], target = 9`
```
i=0: nums[0]=2, complement=7, seen={}, add {2→0}
i=1: nums[1]=7, complement=2, seen={2→0}, found! return [0,1]
```

### 🎯 Key Learning Points

#### 1. **Index vs Value Confusion** ⚠️
**Common Mistake**: Returning values instead of indices
```cpp
// ❌ Wrong - returns values
return {nums[i], nums[j]};

// ✅ Correct - returns indices  
return {i, j};
```

#### 2. **Same Element Usage** ⚠️
**Why start inner loop at i+1?**
- Prevents using same element twice: `nums[i] + nums[i]`
- Avoids duplicate pairs: checking (0,1) and (1,0)
- Ensures each pair is checked exactly once

#### 3. **Hash Map Benefits** 💡
**Space-Time Tradeoff**:
- **Brute Force**: O(1) space, O(n²) time
- **Hash Map**: O(n) space, O(n) time
- **When to use**: Hash map better for large arrays (n > 100)

#### 4. **Problem Guarantees** 📋
- **Exactly one solution exists**: No need to handle "no solution" case
- **Cannot use same element twice**: Must use different indices
- **Return any valid pair**: If multiple solutions exist, return any

### Constraints

- 2 ≤ nums.length ≤ 10⁴
- -10⁹ ≤ nums[i] ≤ 10⁹
- -10⁹ ≤ target ≤ 10⁹
- Only one valid solution exists

### Source

[LeetCode 1 - Two Sum](https://leetcode.com/problems/two-sum)

### 🧪 Edge Cases and Testing

#### Test Case Categories:
1. **Minimum Size**: `nums = [a, b], target = a+b`
2. **Duplicate Values**: `nums = [3,3], target = 6`
3. **Negative Numbers**: `nums = [-1,-2,-3,-4,-5], target = -8`
4. **Large Arrays**: Performance testing with n > 1000
5. **Zero Values**: `nums = [0,4,3,0], target = 0`

#### Performance Comparison:
```
Array Size | Brute Force | Hash Map
    10     |    0.1ms   |   0.1ms
   100     |    1ms     |   0.2ms  
  1000     |   100ms    |   2ms    ← Hash map wins
 10000     |  10000ms   |  20ms    ← Significant difference
```

---

## Problem 2: Power of Two (LeetCode 231)

### 📋 Problem Statement

**Difficulty**: Easy  
**Category**: Bit Manipulation, Math  
**Companies**: Google, Amazon, Microsoft

Given an integer `n`, return `true` if it is a power of two. Otherwise, return `false`.

**Definition**: An integer `n` is a power of two if there exists an integer `x` such that `n == 2^x`.

### 🔍 Mathematical Foundation

**Powers of Two Pattern**:
```
2^0 = 1   → Binary: 0001
2^1 = 2   → Binary: 0010  
2^2 = 4   → Binary: 0100
2^3 = 8   → Binary: 1000
2^4 = 16  → Binary: 10000
```

**Key Observation**: Powers of 2 have exactly **one bit set** in binary representation!

### 🎯 Problem Analysis

**What makes a number a power of 2?**
1. **Positive**: Must be greater than 0
2. **Single Bit**: Only one bit is set in binary representation
3. **Mathematical**: Can be expressed as 2^x for some integer x ≥ 0

### 📚 Examples with Binary Analysis

#### Example 1: Edge Case (Smallest Power)
```
Input: n = 1
Output: true

Analysis:
- Decimal: 1
- Binary: 0001
- Power: 2^0 = 1
- Single bit set at position 0 ✓
```

#### Example 2: Typical Power of 2
```
Input: n = 16  
Output: true

Analysis:
- Decimal: 16
- Binary: 10000
- Power: 2^4 = 16
- Single bit set at position 4 ✓
```

#### Example 3: Not a Power of 2
```
Input: n = 3
Output: false

Analysis:
- Decimal: 3
- Binary: 0011
- Multiple bits set (positions 0 and 1) ✗
- Cannot be expressed as 2^x
```

#### Example 4: Negative Number
```
Input: n = -16
Output: false

Analysis:
- Powers of 2 are always positive
- Negative numbers cannot be powers of 2
```

### 🔄 Solution Approaches

#### Approach 1: Bit Manipulation Magic ⭐

**💡 Core Idea**: Use the property `n & (n-1) == 0` for powers of 2

**📊 Complexity Analysis**:
- **Time Complexity**: O(1) - constant time operation
- **Space Complexity**: O(1) - no extra space needed

**🔍 Algorithm Steps**:
1. **Positive Check**: Ensure `n > 0` (powers of 2 are positive)
2. **Bit Trick**: Check if `n & (n-1) == 0`
3. **Return Result**: Both conditions must be true

**🎯 Why does `n & (n-1) == 0` work?**

**Visual Explanation**:
```
For n = 8 (power of 2):
n     = 8  = 1000 (binary)
n-1   = 7  = 0111 (binary)
n & (n-1) = 1000 & 0111 = 0000 = 0 ✓

For n = 6 (not power of 2):
n     = 6  = 0110 (binary)  
n-1   = 5  = 0101 (binary)
n & (n-1) = 0110 & 0101 = 0100 ≠ 0 ✗
```

**🔬 Mathematical Insight**:
- **Powers of 2**: Have exactly one bit set (e.g., 1000)
- **Subtract 1**: Flips all bits after and including the set bit (1000 → 0111)
- **AND Operation**: Results in 0 because no bits overlap

```cpp
bool isPowerOfTwo(int n) {
    // Check two conditions:
    // 1. n must be positive (powers of 2 are always > 0)
    // 2. n & (n-1) must equal 0 (single bit set property)
    return (n > 0 && (n & (n - 1)) == 0);
}
```

#### Approach 2: Iterative Division

**💡 Core Idea**: Keep dividing by 2 until we reach 1 or an odd number

```cpp
bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    
    while (n % 2 == 0) {
        n /= 2;
    }
    
    return n == 1;
}
```

**📊 Complexity**: O(log n) time, O(1) space

#### Approach 3: Mathematical Check

**💡 Core Idea**: Use logarithms to check if log₂(n) is an integer

```cpp
bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    
    double logResult = log2(n);
    return logResult == floor(logResult);
}
```

**⚠️ Note**: Floating-point precision issues make this less reliable

### 🎯 Key Learning Points

#### 1. **Bit Manipulation Patterns** 💡

**Powers of 2 in Binary**:
```
Decimal | Binary   | Pattern
   1    |   0001   | Single bit at position 0
   2    |   0010   | Single bit at position 1  
   4    |   0100   | Single bit at position 2
   8    |   1000   | Single bit at position 3
  16    |  10000   | Single bit at position 4
```

**The n-1 Trick Explained**:
```
Step 1: Start with power of 2
n = 8 = 1000₂

Step 2: Subtract 1  
n-1 = 7 = 0111₂

Step 3: AND operation
1000₂ & 0111₂ = 0000₂ = 0

Why? No overlapping bits!
```

#### 2. **Edge Cases Mastery** ⚠️

**Critical Test Cases**:
```cpp
isPowerOfTwo(0)  → false  // Zero is not a power of 2
isPowerOfTwo(1)  → true   // 2^0 = 1 (special case)
isPowerOfTwo(-8) → false  // Negative numbers invalid
isPowerOfTwo(3)  → false  // Multiple bits set
```

#### 3. **Performance Comparison** 📊

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Bit Manipulation | O(1) | O(1) | Fastest, elegant | Requires bit knowledge |
| Division Loop | O(log n) | O(1) | Intuitive | Slower for large n |
| Logarithm | O(1) | O(1) | Mathematical | Precision issues |

#### 4. **Common Mistakes** ❌

```cpp
// ❌ Forgetting positive check
return (n & (n-1)) == 0;  // Wrong for n=0

// ❌ Wrong bit operation  
return (n & n-1) == 0;    // Missing parentheses

// ✅ Correct implementation
return (n > 0 && (n & (n-1)) == 0);
```

### 🧪 Testing and Edge Cases

#### Comprehensive Test Suite:
```cpp
// Positive powers of 2
assert(isPowerOfTwo(1) == true);    // 2^0
assert(isPowerOfTwo(2) == true);    // 2^1  
assert(isPowerOfTwo(4) == true);    // 2^2
assert(isPowerOfTwo(1024) == true); // 2^10

// Non-powers of 2
assert(isPowerOfTwo(3) == false);   // Multiple bits
assert(isPowerOfTwo(6) == false);   // 110₂
assert(isPowerOfTwo(10) == false);  // 1010₂

// Edge cases
assert(isPowerOfTwo(0) == false);   // Zero
assert(isPowerOfTwo(-1) == false);  // Negative
assert(isPowerOfTwo(-16) == false); // Negative power

// Boundary values
assert(isPowerOfTwo(INT_MAX) == false);     // 2³¹-1
assert(isPowerOfTwo(1073741824) == true);   // 2³⁰ (largest valid)
```

### 📏 Constraints

- **Range**: -2³¹ ≤ n ≤ 2³¹ - 1
- **Largest Power of 2**: 2³⁰ = 1,073,741,824 (fits in 32-bit signed int)
- **Edge Case**: 2³¹ would overflow, so maximum valid input is 2³⁰

### Source

[LeetCode 231 - Power of Two](https://leetcode.com/problems/power-of-two)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Two Sum | Easy | ✅ Solved | Brute Force | O(n²) | O(1) |
| Power of Two | Easy | ✅ Solved | Bit Manipulation | O(1) | O(1) |

## 🎯 Key Learnings

1. **Array Fundamentals**: Index-based problem solving and pair finding patterns
2. **Bit Manipulation**: Efficient mathematical checks using bitwise operations
3. **Optimization Awareness**: Understanding when brute force can be improved
4. **Problem Analysis**: Reading constraints and examples carefully

## 🚀 Next Steps

- Implement hash map solution for Two Sum
- Explore more bit manipulation problems
- Practice array problems with different patterns
- Focus on time/space complexity analysis
