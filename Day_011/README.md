# Day 11: Two Classic LeetCode Problems - Complete Beginner's Guide

> **Master array manipulation and bit operations step by step!**

---

## 🎯 What You'll Learn

By the end of this guide, you'll master:
- 🔍 **Array Search Algorithms** - Finding pairs that meet specific conditions
- 🗺️ **Hash Map Optimization** - Trading space for speed efficiency
- ⚡ **Brute Force vs Optimized** - Understanding algorithmic tradeoffs
- 💻 **Bit Manipulation** - Using bitwise operations for elegant solutions
- 📊 **Time-Space Complexity** - Analyzing and comparing different approaches

---

# Part 1: Two Sum Problem (LeetCode #1)

## 📋 The Problem

### 🎯 Problem Statement

**Given**: An array of integers `nums` and an integer `target`  
**Task**: Return **indices** of the two numbers such that they add up to `target`  
**Guarantee**: Exactly one solution exists, and you can't use the same element twice

### 🌟 Real-World Example

Think of it like finding two puzzle pieces that fit together:
- 🛒 **Shopping**: Finding two items that exactly match your budget
- 🧪 **Chemistry**: Mixing two substances to reach a target concentration
- 💰 **Finance**: Combining two investments to reach a target portfolio value

---

## 🔍 Understanding the Basics

### 💡 What is a Pair Sum?

```
Array: [2, 7, 11, 15]
Target: 9

Check pairs:
- 2 + 7 = 9 ✅ Found!
- Return indices: [0, 1]
```

**Key Concept:**
- We need to find TWO numbers that add up to a specific target
- We return the **positions** (indices), not the numbers themselves
- Each element can only be used once

### 📍 Array Index System

```
Index:  0    1    2     3
Value: [2,   7,   11,   15]
        ↑    ↑    ↑     ↑
     First Second Third Fourth
```

---

## 📚 Step-by-Step Examples

### 🟢 Example 1: Basic Case

**Input:** `nums = [2, 7, 11, 15]`, `target = 9`  
**Output:** `[0, 1]`

**Step-by-step breakdown:**
```
Step 1: Check indices (0, 1)
        nums[0] + nums[1] = 2 + 7 = 9 ✅

Step 2: Match found! Return [0, 1]

Step 3: Verification: 2 + 7 = 9 equals target
```

### 🔵 Example 2: Later in Array

**Input:** `nums = [3, 2, 4]`, `target = 6`  
**Output:** `[1, 2]`

**Step-by-step breakdown:**
```
Pair (0,1): 3 + 2 = 5 ❌ Not target
Pair (0,2): 3 + 4 = 7 ❌ Not target
Pair (1,2): 2 + 4 = 6 ✅ Match found!
Return: [1, 2]
```

### 🟡 Example 3: Same Value, Different Indices

**Input:** `nums = [3, 3]`, `target = 6`  
**Output:** `[0, 1]`

**Important Note:** Same **value** is OK if at different **indices**!

```
Array: [3, 3]
       ↑  ↑
     idx:0 idx:1

3 (at index 0) + 3 (at index 1) = 6 ✅
```

---

## 🛠️ The Algorithm - Brute Force Approach

### 🎯 Main Strategy: Check All Pairs

**Algorithm Flow:**
```
1. Start with first element
2. Compare with all elements after it
3. If sum equals target → Return indices
4. If not → Move to next element
5. Repeat until pair found
```

### 💻 Complete Brute Force Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Outer loop: Pick first number
        for (int i = 0; i < n; i++) {
            // Inner loop: Check against all numbers after it
            for (int j = i + 1; j < n; j++) {
                // Check if pair sums to target
                if (nums[i] + nums[j] == target) {
                    return {i, j};  // Found the pair!
                }
            }
        }
        
        // No pair found (though problem guarantees one exists)
        return {};
    }
};
```

### 🔄 Execution Flow Visualization

**Example: nums = [2, 7, 11, 15], target = 9**

```
i=0, j=1: nums[0] + nums[1] = 2 + 7 = 9 ✅ Found!
Return: [0, 1]

If not found, would continue:
i=0, j=2: nums[0] + nums[2] = 2 + 11 = 13 ❌
i=0, j=3: nums[0] + nums[3] = 2 + 15 = 17 ❌
i=1, j=2: nums[1] + nums[2] = 7 + 11 = 18 ❌
i=1, j=3: nums[1] + nums[3] = 7 + 15 = 22 ❌
...and so on
```

---

## 🚀 Optimized Approach: Hash Map

### 💡 Key Insight

Instead of checking every pair, we can use a hash map to remember what we've seen!

**Strategy:**
```
For each number:
1. Calculate complement (target - current)
2. Check if complement exists in hash map
3. If YES → Found pair! Return indices
4. If NO → Add current number to hash map
5. Continue to next number
```

### 💻 Complete Hash Map Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash map to store: value → index
        unordered_map<int, int> map;
        
        // Iterate through array
        for (int i = 0; i < nums.size(); i++) {
            // Calculate what number we need
            int complement = target - nums[i];
            
            // Check if we've seen the complement before
            if (map.find(complement) != map.end()) {
                // Found it! Return both indices
                return {map[complement], i};
            }
            
            // Haven't seen complement yet
            // Store current number with its index
            map[nums[i]] = i;
        }
        
        // No solution found (though problem guarantees one exists)
        return {};
    }
};
```

### 📊 Hash Map Approach Step-by-Step

**Example:** `nums = [2, 7, 11, 15]`, `target = 9`

```
Step 1: i=0, num=2
        complement = 9 - 2 = 7
        Is 7 in map? NO
        Add to map: map[2] = 0
        Map: {2→0}

Step 2: i=1, num=7
        complement = 9 - 7 = 2
        Is 2 in map? YES! (at index 0)
        Return: [0, 1] ✅
```

**Another Example:** `nums = [3, 2, 4]`, `target = 6`

```
Step 1: i=0, num=3
        complement = 6 - 3 = 3
        Is 3 in map? NO
        Add to map: map[3] = 0
        Map: {3→0}

Step 2: i=1, num=2
        complement = 6 - 2 = 4
        Is 4 in map? NO
        Add to map: map[2] = 1
        Map: {3→0, 2→1}

Step 3: i=2, num=4
        complement = 6 - 4 = 2
        Is 2 in map? YES! (at index 1)
        Return: [1, 2] ✅
```

### ⚡ Performance Comparison

**Brute Force Approach:**
- ⏰ Time Complexity: O(n²)
- 💾 Space Complexity: O(1)
- ✅ Good for: Small arrays, simple implementation
- ❌ Bad for: Large arrays (very slow)

**Hash Map Approach:**
- ⏰ Time Complexity: O(n)
- 💾 Space Complexity: O(n)
- ✅ Good for: Large arrays (much faster!)
- ❌ Bad for: When memory is very limited

**Speed Comparison:**
```
Array size: 100 elements
- Brute Force: ~10,000 operations
- Hash Map: ~100 operations (100x faster!)

Array size: 1,000 elements
- Brute Force: ~1,000,000 operations
- Hash Map: ~1,000 operations (1000x faster!)

Array size: 10,000 elements
- Brute Force: ~100,000,000 operations
- Hash Map: ~10,000 operations (10000x faster!)
```

---

## 🧪 Test Cases & Edge Cases

### ✅ Normal Cases

| Input Array | Target | Output | Explanation |
|-------------|--------|--------|-------------|
| `[2, 7, 11, 15]` | `9` | `[0, 1]` | First two elements |
| `[3, 2, 4]` | `6` | `[1, 2]` | Middle and last |
| `[3, 3]` | `6` | `[0, 1]` | Same values, different indices |

### ⚠️ Edge Cases

| Input Array | Target | Output | Explanation |
|-------------|--------|--------|-------------|
| `[0, 4, 3, 0]` | `0` | `[0, 3]` | Zero values |
| `[-3, 4, 3, 90]` | `0` | `[0, 2]` | Negative numbers |
| `[5, 10]` | `15` | `[0, 1]` | Minimum array size |

### 🎯 Test Coverage Categories

**1. Positive Numbers ✅ Basic cases**
- Example: `[2, 7] → target 9`

**2. Negative Numbers ⚠️ Edge case handling**
- Example: `[-3, 3] → target 0`

**3. Zero Values ⚠️ Special case**
- Example: `[0, 0] → target 0`

**4. Large Numbers ✅ Boundary testing**
- Example: `[1000000, 2000000] → target 3000000`

---

## 📊 Complexity Analysis - Two Sum

### ⏰ Time Complexity

**Brute Force: O(n²)**
- Outer loop: n iterations
- Inner loop: (n-1) + (n-2) + ... + 1 = n(n-1)/2 iterations
- Total: O(n²)

**Hash Map: O(n)**
- Single pass through array: n iterations
- Hash map lookup: O(1) per element
- Total: O(n)

**Comparison:**
```
n = 100:
- Brute Force: ~10,000 operations
- Hash Map: ~100 operations

n = 1,000:
- Brute Force: ~1,000,000 operations
- Hash Map: ~1,000 operations

n = 10,000:
- Brute Force: ~100,000,000 operations
- Hash Map: ~10,000 operations
```

### 💾 Space Complexity

**Brute Force: O(1)**
- Only a few variables used
- No extra data structures

**Hash Map: O(n)**
- Store up to n elements in hash map
- Trade space for speed

---

## 💼 Interview Questions & Answers - Two Sum

### ❓ Question 1: Why is the brute force approach O(n²)?

**Answer:**  
We use nested loops. For each element (n times), we check it against all remaining elements (average n/2 times). This gives us n × n/2 = n²/2, which simplifies to O(n²).

**Simple Explanation:**  
If you have 100 numbers, in the worst case you'll make about 5,000 comparisons (100 × 50).

---

### ❓ Question 2: Can we use the same element twice?

**Answer:**  
**No!** The problem explicitly states we can't use the same element twice. That's why our inner loop starts at `j = i + 1`, not `j = i`.

**Code Proof:**
```cpp
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {  // j starts AFTER i
        // This ensures i ≠ j
    }
}
```

---

### ❓ Question 3: What if there are multiple valid pairs?

**Answer:**  
The problem guarantees **exactly one solution** exists. Our algorithm returns the first valid pair it finds, which is perfectly acceptable.

**Simple Explanation:**  
Think of it like a treasure hunt where you're guaranteed exactly one treasure. Once you find it, you're done!

---

### ❓ Question 4: How does the hash map approach work?

**Answer:**  
For each number, we calculate its complement (target - current). If the complement is in our hash map, we've found our pair! Otherwise, we add the current number to the map.

**Visual Example:**
```
Array: [2, 7, 11, 15], Target: 9

Step 1: See 2
        Complement: 9 - 2 = 7
        Is 7 in map? No
        Add: map[2] = 0

Step 2: See 7
        Complement: 9 - 7 = 2
        Is 2 in map? YES! (index 0)
        Return: [0, 1]
```

---

### ❓ Question 5: What's the trade-off between approaches?

**Answer:**  
- **Brute Force:** Simple, no extra space, but slow (O(n²))
- **Hash Map:** Fast (O(n)), but uses extra space (O(n))

**Simple Explanation:**  
It's like choosing between:
- Walking (slow but free)
- Taxi (fast but costs money)

---

# Part 2: Power of Two Problem (LeetCode #231)

## 🎯 The Problem

### 📋 Problem Statement

**Given**: An integer `n`  
**Task**: Return `true` if `n` is a power of two, otherwise return `false`  
**Definition**: A number is a power of two if there exists an integer `x` such that n = 2^x

### 🌟 Real-World Example

Think of powers of two in daily life:
- 💾 **Computer Memory**: 1GB, 2GB, 4GB, 8GB, 16GB, 32GB (all powers of 2)
- 🌳 **Tree Structures**: Perfect binary trees have 1, 2, 4, 8, 16... nodes
- 🖼️ **Pixel Dimensions**: 256×256, 512×512, 1024×1024 images

---

## 🔍 Understanding Powers of Two

### 📊 Powers of Two Table

| Exponent | Value | Binary |
|----------|-------|--------|
| 2^0 | 1 | 1 |
| 2^1 | 2 | 10 |
| 2^2 | 4 | 100 |
| 2^3 | 8 | 1000 |
| 2^4 | 16 | 10000 |
| 2^5 | 32 | 100000 |
| 2^10 | 1024 | 10000000000 |

**Pattern Recognition:**
```
Powers of Two → Exactly ONE bit set in binary

1    = 0001  ✅ (one bit)
2    = 0010  ✅ (one bit)
4    = 0100  ✅ (one bit)
8    = 1000  ✅ (one bit)

3    = 0011  ❌ (two bits)
5    = 0101  ❌ (two bits)
6    = 0110  ❌ (two bits)
```

### 🔑 Key Observation

**Powers of two have exactly ONE bit set in binary representation!**

```
Decimal 8  → Binary 1000 → One bit = Power of 2 ✅
Decimal 6  → Binary 0110 → Multiple bits = NOT power of 2 ❌
```

---

## 🎪 The Magic Bit Trick

### 🪄 n & (n-1) Trick Explained

**Rule:** If `n` is a power of 2, then `n & (n-1) == 0`

**Why this works:**
```
Power of 2: Exactly ONE bit set
Subtracting 1: Flips all bits after the rightmost 1
AND operation: No overlap = 0 ✅

Not power of 2: Multiple bits set
Subtracting 1: Still some overlap
AND operation: Result ≠ 0 ❌
```

### 🔬 How the Trick Works

**Example 1: n = 8 (Power of 2)**
```
n     = 8  = 1000  (binary)
n - 1 = 7  = 0111  (binary)
n & (n-1)  = 0000  (binary) = 0 ✅
```

**Example 2: n = 6 (NOT Power of 2)**
```
n     = 6  = 0110  (binary)
n - 1 = 5  = 0101  (binary)
n & (n-1)  = 0100  (binary) = 4 ❌
```

**Detailed Explanation:**
```
Why does subtracting 1 work?

Power of 2 (8 = 1000):
- Has one 1 followed by zeros
- Subtracting 1 flips: 0111
- AND with original: no overlap!

Not power of 2 (6 = 0110):
- Has multiple 1s
- Subtracting 1: 0101
- AND with original: still has overlap!
```

---

## 📚 Step-by-Step Examples

### 🟢 Example 1: n = 1

**Input:** `n = 1`  
**Output:** `true` (2^0 = 1)

```
n = 1 (binary: 1)
n - 1 = 0 (binary: 0)
1 & 0 = 0 ✅
Result: true
```

**Analysis:**
- `n = 1` is a special case (2^0 = 1)
- Binary: `1` (only one bit set)
- `1 & 0 = 0`, so it's a power of 2 ✅

---

### 🔵 Example 2: n = 16

**Input:** `n = 16`  
**Output:** `true` (2^4 = 16)

```
Step 1: n = 16 = 10000 (binary)
Step 2: n - 1 = 15 = 01111 (binary)
Step 3: 10000 & 01111 = 00000 = 0
Step 4: Result = 0, so return true ✅
```

**Step-by-step:**
1. `n = 16` = `10000` in binary (one bit at position 4)
2. `n - 1 = 15` = `01111` in binary (all lower bits set)
3. `10000 & 01111 = 00000` = `0`
4. Since result is 0, return `true` ✅

---

### 🔴 Example 3: n = 3

**Input:** `n = 3`  
**Output:** `false`

```
n = 3 (binary: 11) - TWO bits set
n - 1 = 2 (binary: 10)
11 & 10 = 10 = 2 ≠ 0 ❌
Result: false
```

**Analysis:**
- `n = 3` (binary: `11`) - TWO bits set, not a power of 2
- `n - 1 = 2` (binary: `10`)
- `11 & 10 = 10` = `2` ≠ `0` ❌
- Result: `false`

---

### 🟡 Example 4: n = 5

**Input:** `n = 5`  
**Output:** `false`

```
Step 1: n = 5 = 101 (binary) - bits at positions 0 and 2
Step 2: n - 1 = 4 = 100 (binary)
Step 3: 101 & 100 = 100 = 4 ≠ 0
Step 4: Result ≠ 0, so return false ❌
```

**Step-by-step:**
1. `n = 5` = `101` in binary (bits at positions 0 and 2)
2. `n - 1 = 4` = `100` in binary
3. `101 & 100 = 100` = `4` ≠ `0` ❌
4. Result: `false`

---

## 🛠️ The Algorithm

### 🎯 Main Strategy

```
Algorithm Flow:
1. Check if n > 0 (powers of 2 are positive)
2. If NO → return false
3. If YES → calculate n & (n-1)
4. If result == 0 → return true (power of 2)
5. If result != 0 → return false (not power of 2)
```

### 💻 The Complete Solution

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Must be positive AND have only one bit set
        return (n > 0 && (n & (n - 1)) == 0);
    }
};
```

**Code Breakdown:**
```cpp
n > 0              // Check if positive (powers of 2 are always positive)
&&                 // AND operator (both conditions must be true)
(n & (n - 1)) == 0 // Bit trick: only true for powers of 2
```

### 🔍 Why Check n > 0?

**Reason 1: Zero is not a power of 2**
```
0 = 2^x ?
No value of x makes this true!
```

**Reason 2: Negative numbers**
```
Powers of 2 are always positive:
2^0 = 1
2^1 = 2
2^2 = 4
...

-16 is NOT considered 2^x in this problem
```

**Edge Cases Handled:**
- `n = 0`: Not a power of 2 (no exponent gives 0)
- `n < 0`: Negative numbers aren't powers of 2
- `n = 1`: Valid! (2^0 = 1)

---

## 🧪 Test Cases & Edge Cases - Power of Two

### ✅ Valid Powers of Two

| Input | Output | Explanation |
|-------|--------|-------------|
| `1` | `true` | 2^0 = 1 |
| `2` | `true` | 2^1 = 2 |
| `4` | `true` | 2^2 = 4 |
| `8` | `true` | 2^3 = 8 |
| `16` | `true` | 2^4 = 16 |
| `1024` | `true` | 2^10 = 1024 |

### ❌ Not Powers of Two

| Input | Output | Explanation |
|-------|--------|-------------|
| `3` | `false` | Multiple bits: 11 |
| `5` | `false` | Multiple bits: 101 |
| `6` | `false` | Multiple bits: 110 |
| `7` | `false` | Multiple bits: 111 |
| `0` | `false` | Zero is not 2^x |
| `-16` | `false` | Negative numbers |

### 🎯 Binary Representation Analysis

**Powers of 2 (✅ One bit):**
```
1    = 1
2    = 10
4    = 100
8    = 1000
16   = 10000
```

**Non-powers (❌ Multiple/zero bits):**
```
3    = 11    (two bits)
5    = 101   (two bits)
6    = 110   (two bits)
7    = 111   (three bits)
0    = 0     (zero bits)
```

---

## 📊 Complexity Analysis - Power of Two

### ⏰ Time Complexity: O(1)

**Why constant time?**
- Single bitwise operation: `n & (n-1)`
- One comparison: `n > 0`
- No loops, no recursion
- Always completes in fixed time

```
Any input size → 1 operation → O(1) time
```

### 💾 Space Complexity: O(1)

**Why constant space?**
- No arrays or data structures
- Only a few variables
- No recursion stack

---

## 🎓 Alternative Approaches

### 🔄 Approach 1: Division Loop

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        
        // Keep dividing by 2
        while (n % 2 == 0) {
            n /= 2;
        }
        
        // If we reach 1, it was a power of 2
        return n == 1;
    }
};
```

**Complexity:**
- Time: O(log n) - divide by 2 each time
- Space: O(1)
- Slower than bit manipulation!

**Example: n = 16**
```
16 → 8 → 4 → 2 → 1 ✅
(4 divisions, log₂(16) = 4)
```

### 🔄 Approach 2: Bit Counting

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        
        // Count number of set bits
        return __builtin_popcount(n) == 1;
    }
};
```

**Complexity:**
- Time: O(1) (but library-dependent)
- Space: O(1)
- Uses built-in function to count set bits

**Note:** `__builtin_popcount()` counts the number of 1s in binary representation

### 📊 Approach Comparison

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| **Bit Manipulation** | O(1) | O(1) | Fastest, elegant | Needs understanding |
| **Division Loop** | O(log n) | O(1) | Easy to understand | Slower |
| **Bit Counting** | O(1) | O(1) | Uses built-in | Compiler-dependent |

**Best Choice:** Bit manipulation (`n & (n-1)`) for interviews! ✅

---

## 💼 Interview Questions & Answers - Power of Two

### ❓ Question 1: Why does n & (n-1) work?

**Answer:**  
For a power of 2, there's exactly ONE bit set. When you subtract 1, all bits to the right of that 1 become 1, and the original 1 becomes 0. The AND operation then gives 0 because there's no overlap.

**Visual:**
```
n = 8:     1000
n - 1 = 7: 0111
AND:       0000 ✅
```

---

### ❓ Question 2: What about n = 0?

**Answer:**  
**Zero is NOT a power of 2!** There's no exponent `x` where 2^x = 0. That's why we check `n > 0`.

**Simple Explanation:**  
No matter how many times you divide 2 by itself or multiply it, you'll never get zero!

---

### ❓ Question 3: Can negative numbers be powers of two?

**Answer:**  
**No!** In this problem, we only consider positive powers: 2^0, 2^1, 2^2, etc. All of these are positive.

**Note:** Some math contexts use negative exponents (2^-1 = 0.5), but this problem only deals with integers.

---

### ❓ Question 4: Why is bit manipulation faster than division?

**Answer:**  
Bit operations are performed directly by the CPU in a single cycle, while division requires multiple cycles and is one of the slowest arithmetic operations.

**Speed Comparison:**
```
Bit operation (n & (n-1)): ~1 CPU cycle
Division (n / 2):          ~10-40 CPU cycles
```

---

### ❓ Question 5: How do I remember this trick?

**Answer:**  
Remember the pattern: **"Powers of 2 have exactly one bit, subtracting 1 flips all bits after it."**

**Mnemonic:** Think of a light switch - powers of 2 have exactly ONE light on. Subtracting 1 turns that light off and all lights after it on.

---

## 🎯 Quick Reference

### 🔑 Essential Patterns

**Two Sum - Brute Force:**
```cpp
// Check all pairs - O(n²)
for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
        if (nums[i] + nums[j] == target)
            return {i, j};
```

**Two Sum - Hash Map:**
```cpp
// O(n) time with hash map
unordered_map<int, int> map;
for (int i = 0; i < n; i++) {
    int complement = target - nums[i];
    if (map.count(complement))
        return {map[complement], i};
    map[nums[i]] = i;
}
```

**Power of Two:**
```cpp
// Bit manipulation trick - O(1)
return (n > 0 && (n & (n - 1)) == 0);
```

### 🧠 Mental Models

**Problem Solving Approaches:**
- **Two Sum:** Pair finding - trade time vs space
- **Power of Two:** Pattern recognition - use bit tricks for elegant solutions

---

## 🏆 Mastery Checklist

### Two Sum
- [ ] ✅ Understand brute force approach O(n²)
- [ ] ✅ Master hash map optimization O(n)
- [ ] ✅ Handle edge cases (zeros, negatives, duplicates)
- [ ] ✅ Explain space-time trade-offs
- [ ] ✅ Code both approaches fluently

### Power of Two
- [ ] ✅ Understand binary representation of powers of 2
- [ ] ✅ Master n & (n-1) bit trick
- [ ] ✅ Handle edge cases (zero, negative, one)
- [ ] ✅ Explain why the trick works mathematically
- [ ] ✅ Compare with alternative approaches

---

## 💡 Pro Tips

1. **🎯 Two Sum**: Always consider hash map for pair-finding problems - O(n²) to O(n) is huge!
2. **🔢 Bit Manipulation**: Powers of 2 appear everywhere in CS - master this pattern
3. **🧪 Test Edge Cases**: Always check: zero, negative, minimum/maximum values
4. **📚 Learn Patterns**: These are foundational - many problems build on these concepts
5. **🎓 Understand Trade-offs**: Know when to use brute force vs optimization
6. **💼 Interview Prep**: Be ready to explain YOUR thought process, not just the solution
7. **⚡ Practice**: Solve variations to cement understanding

---

## 🚀 Practice Problems

Once you master these, try:

| Problem | Difficulty | Key Concept |
|---------|-----------|-------------|
| 🔢 Three Sum | Medium | Extend two sum concept |
| 💫 Power of Three | Easy | Similar bit patterns |
| 🎯 Four Sum | Medium | Pair finding extension |
| 🔄 Happy Number | Easy | Number manipulation |
| 📊 Contains Duplicate | Easy | Hash map usage |
| 🧮 Single Number | Easy | Bit manipulation |

---

**🎉 Congratulations! You now have a complete understanding of array pair finding and bit manipulation. These are fundamental building blocks for more complex algorithms. Keep practicing and happy coding!**
