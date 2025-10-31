# Day 11: Two Classic LeetCode Problems - Complete Beginner's Guide

> **Master array manipulation and bit operations step by step!**

---

## 📚 What You'll Learn

By the end of this guide, you'll master:
- 🔍 **Array Search Algorithms** - Finding pairs that meet specific conditions
- 🗺️ **Hash Map Optimization** - Trading space for speed efficiency
- ⚖️ **Brute Force vs Optimized** - Understanding algorithmic tradeoffs
- 🔢 **Bit Manipulation** - Using bitwise operations for elegant solutions
- 📊 **Time-Space Complexity** - Analyzing and comparing different approaches

---

# Part 1: Two Sum Problem (LeetCode #1)

## 🎯 The Problem

### 📋 Problem Statement

**Given**: An array of integers `nums` and an integer `target`  
**Task**: Return **indices** of the two numbers such that they add up to `target`  
**Guarantee**: Exactly one solution exists, and you can't use the same element twice

### 🌟 Real-World Example

Think of it like finding two puzzle pieces that fit together:
- 🛒 **Shopping**: Finding two items that exactly match your budget
- 🧪 **Chemistry**: Mixing two substances to reach a target concentration
- 💰 **Finance**: Combining two investments to reach a target portfolio value

---

## 🧠 Understanding the Basics

### 🔢 What is a Pair Sum?

```
╔═══════════════════════════════════════════════════════╗
║           TWO SUM CONCEPT VISUALIZATION               ║
╚═══════════════════════════════════════════════════════╝

Array: [2, 7, 11, 15]    Target: 9

    Index:    0    1    2     3
             ┌───┬───┬────┬────┐
    Values:  │ 2 │ 7 │ 11 │ 15 │
             └───┴───┴────┴────┘
               ↓   ↓
               └───┴──→  2 + 7 = 9  ✓ MATCH!

Result: Return indices [0, 1]

KEY CONCEPT:
┌─────────────────────────────────────────────────────┐
│ • We need TWO numbers that sum to target            │
│ • Return POSITIONS (indices), not values            │
│ • Each element can only be used ONCE                │
└─────────────────────────────────────────────────────┘
```

### 📍 Array Index System

```
╔═══════════════════════════════════════════════════════╗
║              UNDERSTANDING ARRAY INDICES              ║
╚═══════════════════════════════════════════════════════╝

    Array: [2, 7, 11, 15]

    ┌─────────┬─────────┬─────────┬─────────┐
    │ Index 0 │ Index 1 │ Index 2 │ Index 3 │
    ├─────────┼─────────┼─────────┼─────────┤
    │ Value:2 │ Value:7 │ Value:11│ Value:15│
    └─────────┴─────────┴─────────┴─────────┘
        ↑         ↑         ↑         ↑
        │         │         │         │
    Position  Position  Position  Position
    starts    in the    in the    at the
    at 0      array     array     end

IMPORTANT: Array indexing starts from 0, not 1!
```

---

## 📖 Step-by-Step Examples

### 🟢 Example 1: Basic Case

**Input:** `nums = [2, 7, 11, 15]`, `target = 9`  
**Output:** `[0, 1]`

```
╔═══════════════════════════════════════════════════════╗
║               EXAMPLE 1: STEP-BY-STEP                 ║
╚═══════════════════════════════════════════════════════╝

Array: [2, 7, 11, 15]    Target: 9

STEP 1: Check first pair (indices 0, 1)
    ┌──────────────────────────┐
    │ nums[0] + nums[1]        │
    │   2    +    7    = 9     │
    │ Does 9 equal target 9?   │
    │         YES ✓            │
    └──────────────────────────┘
              ↓
    ┌──────────────────────────┐
    │   MATCH FOUND!           │
    │   Return [0, 1]          │
    └──────────────────────────┘

VERIFICATION:
    Position 0 has value 2
    Position 1 has value 7
    2 + 7 = 9 ✓
```

### 🔵 Example 2: Later in Array

**Input:** `nums = [3, 2, 4]`, `target = 6`  
**Output:** `[1, 2]`

```
╔═══════════════════════════════════════════════════════╗
║          EXAMPLE 2: SEARCHING DEEPER                  ║
╚═══════════════════════════════════════════════════════╝

Array: [3, 2, 4]    Target: 6

STEP 1: Check pair (0, 1)
    ┌──────────────────────────┐
    │ nums[0] + nums[1]        │
    │   3    +    2    = 5     │
    │ Does 5 equal target 6?   │
    │         NO ✗             │
    └──────────────────────────┘
              ↓
         Continue...

STEP 2: Check pair (0, 2)
    ┌──────────────────────────┐
    │ nums[0] + nums[2]        │
    │   3    +    4    = 7     │
    │ Does 7 equal target 6?   │
    │         NO ✗             │
    └──────────────────────────┘
              ↓
         Continue...

STEP 3: Check pair (1, 2)
    ┌──────────────────────────┐
    │ nums[1] + nums[2]        │
    │   2    +    4    = 6     │
    │ Does 6 equal target 6?   │
    │         YES ✓            │
    └──────────────────────────┘
              ↓
    ┌──────────────────────────┐
    │   MATCH FOUND!           │
    │   Return [1, 2]          │
    └──────────────────────────┘
```

### 🟡 Example 3: Same Value, Different Indices

**Input:** `nums = [3, 3]`, `target = 6`  
**Output:** `[0, 1]`

```
╔═══════════════════════════════════════════════════════╗
║        EXAMPLE 3: DUPLICATE VALUES ALLOWED            ║
╚═══════════════════════════════════════════════════════╝

Array: [3, 3]    Target: 6

    Index:    0     1
             ┌───┬───┐
    Values:  │ 3 │ 3 │  ← Same VALUE
             └───┴───┘
               ↑   ↑
               │   └──── Different INDEX (1)
               └──────── Different INDEX (0)

STEP 1: Check pair (0, 1)
    ┌──────────────────────────┐
    │ nums[0] + nums[1]        │
    │   3    +    3    = 6     │
    │ Does 6 equal target 6?   │
    │         YES ✓            │
    └──────────────────────────┘
              ↓
    ┌──────────────────────────┐
    │   Return [0, 1]          │
    └──────────────────────────┘

IMPORTANT NOTE:
┌─────────────────────────────────────────────────────┐
│ ✓ Same VALUE at different indices = OK             │
│ ✗ Same INDEX twice = NOT ALLOWED                   │
│                                                     │
│ Example: [3, 3] with target 6                      │
│   Valid:   3 (index 0) + 3 (index 1) ✓            │
│   Invalid: 3 (index 0) + 3 (index 0) ✗            │
└─────────────────────────────────────────────────────┘
```

---

## 🛠️ The Algorithm - Brute Force Approach

### 🎯 Main Strategy: Check All Pairs

```
╔═══════════════════════════════════════════════════════╗
║            BRUTE FORCE ALGORITHM FLOW                 ║
╚═══════════════════════════════════════════════════════╝

                    START
                      ↓
         ┌────────────────────────┐
         │ Initialize outer loop  │
         │      i = 0 to n-1      │
         └────────────┬───────────┘
                      ↓
         ┌────────────────────────┐
         │   Pick element i       │
         │   nums[i]              │
         └────────────┬───────────┘
                      ↓
         ┌────────────────────────┐
         │ Initialize inner loop  │
         │    j = i+1 to n        │
         └────────────┬───────────┘
                      ↓
         ┌────────────────────────┐
         │   Pick element j       │
         │   nums[j]              │
         └────────────┬───────────┘
                      ↓
         ┌────────────────────────┐
         │ Calculate sum:         │
         │ nums[i] + nums[j]      │
         └────────────┬───────────┘
                      ↓
              ┌───────────────┐
              │ sum == target?│
              └───┬───────┬───┘
                  │       │
              YES │       │ NO
                  │       │
                  ↓       ↓
         ┌──────────┐  ┌──────────┐
         │  FOUND!  │  │ Continue │
         │  Return  │  │ to next  │
         │  [i, j]  │  │   pair   │
         └──────────┘  └────┬─────┘
                            │
                            └──→ Back to inner loop
                            
    If all pairs checked and no match:
         ┌────────────────────────┐
         │  Return empty result   │
         └────────────────────────┘
```

### 💻 The Code Logic - Brute Force

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    /*
     * ═══════════════════════════════════════════════════════
     *            BRUTE FORCE ALGORITHM VISUALIZATION
     * ═══════════════════════════════════════════════════════
     * 
     * CONCEPT: Check every possible pair
     * 
     * Example: nums = [2, 7, 11, 15], target = 9
     * 
     * OUTER LOOP (i):        INNER LOOP (j):
     * ┌─────────────┐       ┌─────────────────────────────┐
     * │ i = 0       │       │ j = 1: Check 2 + 7 = 9  ✓  │
     * │ nums[i] = 2 │  ───→ │ j = 2: Check 2 + 11 = 13 ✗ │
     * └─────────────┘       │ j = 3: Check 2 + 15 = 17 ✗ │
     *                       └─────────────────────────────┘
     * ┌─────────────┐       
     * │ i = 1       │       (Found match at i=0, j=1)
     * │ nums[i] = 7 │       So we return [0, 1]
     * └─────────────┘       
     * 
     * WHY START j AT i+1?
     * ───────────────────────────────────────────────────────
     * 1. Avoid checking same pair twice: (0,1) and (1,0)
     * 2. Avoid using same element twice: (0,0)
     * 3. Only check unique pairs once
     * 
     */
    
    int n = nums.size();
    
    // ┌─────────────────────────────────────────────┐
    // │ OUTER LOOP: Pick first number               │
    // │ Start from index 0, go until second-to-last │
    // └─────────────────────────────────────────────┘
    for (int i = 0; i < n; i++) {
        
        // ┌─────────────────────────────────────────────┐
        // │ INNER LOOP: Check against remaining numbers │
        // │ Start from i+1 to avoid duplicates          │
        // └─────────────────────────────────────────────┘
        for (int j = i + 1; j < n; j++) {
            
            // ┌─────────────────────────────────────────┐
            // │ CHECK: Does this pair sum to target?    │
            // └─────────────────────────────────────────┘
            if (nums[i] + nums[j] == target) {
                /*
                 * ┌─────────────────────────────────┐
                 * │ FOUND! Return the two indices   │
                 * │                                 │
                 * │ Example: i=0, j=1               │
                 * │ Return: [0, 1]                  │
                 * └─────────────────────────────────┘
                 */
                return {i, j};
            }
            /*
             * If no match, loop continues to next j
             * ────────────────────────────────────────
             * Current pair didn't work, try next one
             */
        }
        /*
         * If inner loop completes without finding match,
         * outer loop continues to next i
         * ────────────────────────────────────────────────
         * All pairs with current i checked, move to next
         */
    }
    
    /*
     * ┌─────────────────────────────────────────────┐
     * │ If we reach here, no solution was found     │
     * │ (Problem guarantees this won't happen)      │
     * └─────────────────────────────────────────────┘
     */
    return {};
}
```

### 🔄 Execution Flow Visualization

```
╔═══════════════════════════════════════════════════════╗
║        BRUTE FORCE EXECUTION TRACE                    ║
╚═══════════════════════════════════════════════════════╝

Array: [2, 7, 11, 15]    Target: 9

═══════════════════════════════════════════════════════
ITERATION DETAILS:
═══════════════════════════════════════════════════════

i=0 (nums[0]=2)
├─ j=1 (nums[1]=7)   → 2+7=9    → target=9  ✓ FOUND!
│  └─ Return [0, 1]
│
├─ j=2 (nums[2]=11)  → 2+11=13  → target=9  ✗ Skip
│
└─ j=3 (nums[3]=15)  → 2+15=17  → target=9  ✗ Skip

i=1 (nums[1]=7)
├─ j=2 (nums[2]=11)  → 7+11=18  → target=9  ✗ Skip
│
└─ j=3 (nums[3]=15)  → 7+15=22  → target=9  ✗ Skip

i=2 (nums[2]=11)
└─ j=3 (nums[3]=15)  → 11+15=26 → target=9  ✗ Skip

═══════════════════════════════════════════════════════
TOTAL COMPARISONS: 6 pairs checked
TIME COMPLEXITY: O(n²)
═══════════════════════════════════════════════════════

VISUAL COMPARISON MATRIX:
     j=1  j=2  j=3
    ┌────┬────┬────┐
i=0 │ ✓  │ ✗  │ ✗  │  (Found at [0,1])
    ├────┼────┼────┤
i=1 │    │ ✗  │ ✗  │
    ├────┼────┼────┤
i=2 │    │    │ ✗  │
    └────┴────┴────┘
```

---

## 🚀 Optimized Approach: Hash Map

### 💡 Key Insight

```
╔═══════════════════════════════════════════════════════╗
║          WHY HASH MAP IS FASTER                       ║
╚═══════════════════════════════════════════════════════╝

PROBLEM WITH BRUTE FORCE:
┌─────────────────────────────────────────────────────┐
│ For each number, we search through ALL remaining    │
│ numbers to find its complement                      │
│                                                     │
│ Search time: O(n) for each element                 │
│ Total: O(n) × O(n) = O(n²)                         │
└─────────────────────────────────────────────────────┘
              ↓
         IMPROVEMENT
              ↓
┌─────────────────────────────────────────────────────┐
│ Instead of searching linearly, use Hash Map!       │
│                                                     │
│ Hash Map lookup time: O(1)                         │
│ Total: O(n) × O(1) = O(n)                          │
│                                                     │
│ Trade-off: Use extra space O(n) for speed          │
└─────────────────────────────────────────────────────┘

THE MAGIC:
    For each number, ask: "Have I seen its complement?"
    
    Example: target = 9, current = 7
    Complement needed = 9 - 7 = 2
    
    Instead of looping through array to find 2,
    just check: "Is 2 in my HashMap?" → O(1) time!
```

### 💻 Hash Map Solution Code

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    /*
     * ═══════════════════════════════════════════════════════
     *           HASH MAP OPTIMIZATION VISUALIZATION
     * ═══════════════════════════════════════════════════════
     * 
     * STRATEGY: Store numbers as we go, check for complement
     * 
     * Example: nums = [2, 7, 11, 15], target = 9
     * 
     * ITERATION 1: i=0, nums[0]=2
     * ┌──────────────────────────────────────────────────┐
     * │ Current: 2                                       │
     * │ Complement needed: 9 - 2 = 7                    │
     * │ Is 7 in HashMap? NO (map is empty)              │
     * │ Action: Store 2 → map[2] = 0                    │
     * │ HashMap: {2 → 0}                                │
     * └──────────────────────────────────────────────────┘
     * 
     * ITERATION 2: i=1, nums[1]=7
     * ┌──────────────────────────────────────────────────┐
     * │ Current: 7                                       │
     * │ Complement needed: 9 - 7 = 2                    │
     * │ Is 2 in HashMap? YES! (stored at index 0)       │
     * │ Action: FOUND! Return [0, 1]                    │
     * └──────────────────────────────────────────────────┘
     * 
     * WHY THIS WORKS:
     * ───────────────────────────────────────────────────────
     * 1. We check if complement exists BEFORE storing current
     * 2. This prevents using same element twice
     * 3. When we find complement, we know its index from map
     * 4. Current index is i, complement index is map[complement]
     * 
     */
    
    // ┌─────────────────────────────────────────────┐
    // │ CREATE HASH MAP                             │
    // │ Key: number value                           │
    // │ Value: index in array                       │
    // └─────────────────────────────────────────────┘
    unordered_map<int, int> map;
    
    // ┌─────────────────────────────────────────────┐
    // │ SINGLE PASS through array                   │
    // └─────────────────────────────────────────────┘
    for (int i = 0; i < nums.size(); i++) {
        
        // ┌─────────────────────────────────────────┐
        // │ STEP 1: Calculate what we need          │
        // │                                         │
        // │ If target = 9 and current = 2           │
        // │ Then we need: 9 - 2 = 7                │
        // └─────────────────────────────────────────┘
        int complement = target - nums[i];
        
        /*
         * ┌─────────────────────────────────────────┐
         * │ STEP 2: Check if complement exists     │
         * │                                         │
         * │ map.find() returns:                    │
         * │   - iterator to element if found       │
         * │   - map.end() if not found             │
         * └─────────────────────────────────────────┘
         */
        if (map.find(complement) != map.end()) {
            /*
             * ┌─────────────────────────────────────┐
             * │ FOUND! Complement exists in map     │
             * │                                     │
             * │ Return indices:                     │
             * │   1. map[complement] - old index    │
             * │   2. i - current index              │
             * │                                     │
             * │ Example:                            │
             * │   complement=2 found at index 0     │
             * │   current i=1                       │
             * │   Return: [0, 1]                    │
             * └─────────────────────────────────────┘
             */
            return {map[complement], i};
        }
        
        /*
         * ┌─────────────────────────────────────────┐
         * │ STEP 3: Complement not found            │
         * │ Store current number for future lookup  │
         * │                                         │
         * │ Example: nums[i]=2, i=0                │
         * │ Store: map[2] = 0                      │
         * │                                         │
         * │ Now if we later see 7, we can find 2!  │
         * └─────────────────────────────────────────┘
         */
        map[nums[i]] = i;
        
        /*
         * Continue to next iteration
         * ──────────────────────────────────────────
         * Try next number in array
         */
    }
    
    /*
     * ┌─────────────────────────────────────────────┐
     * │ If we reach here, no solution found         │
     * │ (Problem guarantees this won't happen)      │
     * └─────────────────────────────────────────────┘
     */
    return {};
}
```

### 📝 Step-by-step Hash Map Explanation

```
╔═══════════════════════════════════════════════════════╗
║        HASH MAP EXECUTION TRACE                       ║
╚═══════════════════════════════════════════════════════╝

Array: [2, 7, 11, 15]    Target: 9

═══════════════════════════════════════════════════════
ITERATION 1: i = 0
═══════════════════════════════════════════════════════
Current element: nums[0] = 2

Step 1: Calculate complement
    ┌──────────────────────────┐
    │ complement = target - num│
    │ complement = 9 - 2 = 7   │
    └──────────────────────────┘

Step 2: Check HashMap for complement (7)
    ┌──────────────────────────┐
    │ HashMap before: { }      │
    │ Is 7 in map? NO          │
    └──────────────────────────┘

Step 3: Add current to HashMap
    ┌──────────────────────────┐
    │ map[2] = 0               │
    │ HashMap after: {2→0}     │
    └──────────────────────────┘

───────────────────────────────────────────────────────

═══════════════════════════════════════════════════════
ITERATION 2: i = 1
═══════════════════════════════════════════════════════
Current element: nums[1] = 7

Step 1: Calculate complement
    ┌──────────────────────────┐
    │ complement = target - num│
    │ complement = 9 - 7 = 2   │
    └──────────────────────────┘

Step 2: Check HashMap for complement (2)
    ┌──────────────────────────┐
    │ HashMap: {2→0}           │
    │ Is 2 in map? YES! ✓      │
    │ Found at index: 0        │
    └──────────────────────────┘

Step 3: MATCH FOUND!
    ┌──────────────────────────┐
    │ Complement index: 0      │
    │ Current index: 1         │
    │ Return: [0, 1]           │
    └──────────────────────────┘faster!

════════════════════════════════════════════════════════

Array Size: n = 10,000
────────────────────────────────────────────────────────
Brute Force:
    Operations: 10,000 × 9,999 / 2 = 49,995,000
    Time: ~50 MILLION comparisons                 ☠️
    
Hash Map:
    Operations: n = 10,000
    Time: ~10,000 operations                      ⚡⚡⚡
    
Speed improvement: ~5,000x faster!

════════════════════════════════════════════════════════

VISUAL COMPARISON:

Time Growth as Array Size Increases:
────────────────────────────────────────────────────────
n = 100:
Brute Force:  ████████████████████████████████ 4,950
Hash Map:     ██ 100

n = 1,000:
Brute Force:  ████████████████████████████████ 499,500
Hash Map:     ██ 1,000

n = 10,000:
Brute Force:  ████████████████████████████████ 49,995,000
Hash Map:     ██ 10,000

════════════════════════════════════════════════════════

COMPLEXITY SUMMARY:
┌──────────────┬─────────────┬─────────────┬────────────┐
│  Approach    │    Time     │    Space    │  Best For  │
├──────────────┼─────────────┼─────────────┼────────────┤
│ Brute Force  │   O(n²)     │    O(1)     │  n < 100   │
│              │   🐌 Slow   │  💚 Minimal │  Learning  │
├──────────────┼─────────────┼─────────────┼────────────┤
│ Hash Map     │    O(n)     │    O(n)     │  n > 100   │
│              │   ⚡ Fast   │  💛 Moderate│ Production │
└──────────────┴─────────────┴─────────────┴────────────┘
```

---

## 🧪 Test Cases & Edge Cases

### ✅ Normal Cases

```
╔═══════════════════════════════════════════════════════╗
║              NORMAL TEST CASES                        ║
╚═══════════════════════════════════════════════════════╝

TEST CASE 1: First Two Elements
────────────────────────────────────────────────────────
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
Reason: 2 + 7 = 9 ✓

TEST CASE 2: Middle and Last
────────────────────────────────────────────────────────
Input:  nums = [3, 2, 4], target = 6
Output: [1, 2]
Reason: 2 + 4 = 6 ✓

TEST CASE 3: Duplicate Values
────────────────────────────────────────────────────────
Input:  nums = [3, 3], target = 6
Output: [0, 1]
Reason: 3 + 3 = 6 ✓ (different indices)

TEST CASE 4: Large Numbers
────────────────────────────────────────────────────────
Input:  nums = [1000, 2000, 3000], target = 5000
Output: [1, 2]
Reason: 2000 + 3000 = 5000 ✓

TEST CASE 5: Negative and Positive
────────────────────────────────────────────────────────
Input:  nums = [-1, 0, 1, 2], target = 1
Output: [0, 2]
Reason: -1 + 2 = 1 ✓
```

### ⚠️ Edge Cases

```
╔═══════════════════════════════════════════════════════╗
║              EDGE CASES TO CONSIDER                   ║
╚═══════════════════════════════════════════════════════╝

EDGE CASE 1: Zero Values
────────────────────────────────────────────────────────
Input:  nums = [0, 4, 3, 0], target = 0
Output: [0, 3]
Reason: 0 + 0 = 0 ✓
Note:   Zero is a valid number!

EDGE CASE 2: Negative Numbers
────────────────────────────────────────────────────────
Input:  nums = [-3, 4, 3, 90], target = 0
Output: [0, 2]
Reason: -3 + 3 = 0 ✓
Note:   Negative + Positive can sum to target

EDGE CASE 3: All Negative
────────────────────────────────────────────────────────
Input:  nums = [-5, -3, -2, -1], target = -8
Output: [0, 1]
Reason: -5 + (-3) = -8 ✓

EDGE CASE 4: Minimum Array Size
────────────────────────────────────────────────────────
Input:  nums = [5, 10], target = 15
Output: [0, 1]
Reason: 5 + 10 = 15 ✓
Note:   Smallest possible array (2 elements)

EDGE CASE 5: Large Target
────────────────────────────────────────────────────────
Input:  nums = [1000000, 2000000, 3000000], target = 5000000
Output: [1, 2]
Reason: 2000000 + 3000000 = 5000000 ✓
```

### 🎯 Test Coverage

```
┌─────────────────────────────────────────────────────┐
│              TEST CATEGORY CHECKLIST                │
├─────────────────────────────────────────────────────┤
│                                                     │
│ ✅ POSITIVE NUMBERS                                 │
│    • Basic arithmetic                               │
│    • Most common case                               │
│    Example: [2, 7, 11] target = 9                   │
│                                                     │
│ ✅ NEGATIVE NUMBERS                                 │
│    • Edge case handling                             │
│    • Sign management                                │
│    Example: [-3, 4, 3] target = 0                   │
│                                                     │
│ ✅ ZERO VALUES                                      │
│    • Special case (neither positive nor negative)   │
│    • Common source of bugs                          │
│    Example: [0, 4, 3, 0] target = 0                 │
│                                                     │
│ ✅ DUPLICATE VALUES                                 │
│    • Same value at different indices                │
│    • Ensures we use indices, not values             │
│    Example: [3, 3] target = 6                       │
│                                                     │
│ ✅ LARGE NUMBERS                                    │
│    • Boundary testing                               │
│    • Integer overflow awareness                     │
│    Example: [1000000, 2000000] target = 3000000     │
│                                                     │
│ ✅ MINIMUM SIZE ARRAY                               │
│    • Edge case: smallest valid input                │
│    • Array with exactly 2 elements                  │
│    Example: [5, 10] target = 15                     │
│                                                     │
└─────────────────────────────────────────────────────┘
```

---

## 📊 Complexity Analysis - Two Sum

### ⏰ Time Complexity

```
╔═══════════════════════════════════════════════════════╗
║              TIME COMPLEXITY ANALYSIS                 ║
╚═══════════════════════════════════════════════════════╝

BRUTE FORCE APPROACH: O(n²)
────────────────────────────────────────────────────────

How many operations?
    
    Outer loop runs: n times
    Inner loop runs: (n-1) + (n-2) + ... + 1
    
    Total comparisons: n × (n-1) / 2
    
Example with n = 4:
    ┌───────────────────────────────┐
    │ i=0: check 3 pairs            │
    │ i=1: check 2 pairs            │
    │ i=2: check 1 pair             │
    │ Total: 3+2+1 = 6 pairs        │
    │ Formula: 4×3/2 = 6 ✓          │
    └───────────────────────────────┘

Mathematical proof:
    Sum = n(n-1)/2
        = (n² - n)/2
        = O(n²)  (drop constants and lower terms)

Growth rate visualization:
    n = 10    →  45 operations
    n = 100   →  4,950 operations
    n = 1000  →  499,500 operations
    n = 10000 →  49,995,000 operations

════════════════════════════════════════════════════════

HASH MAP APPROACH: O(n)
────────────────────────────────────────────────────────

How many operations?
    
    Single loop: n iterations
    Each iteration:
        • Calculate complement: O(1)
        • Hash map lookup: O(1)
        • Hash map insert: O(1)
    
    Total: n × O(1) = O(n)

Growth rate visualization:
    n = 10    →  10 operations
    n = 100   →  100 operations
    n = 1000  →  1,000 operations
    n = 10000 →  10,000 operations

Linear growth! 📈

════════════════════════════════════════════════════════

COMPARISON CHART:
────────────────────────────────────────────────────────

Array Size │ Brute Force │ Hash Map  │ Speed-up
───────────┼─────────────┼───────────┼──────────
    10     │     45      │    10     │   4.5x
   100     │   4,950     │   100     │  49.5x
  1,000    │  499,500    │  1,000    │ 499.5x
 10,000    │49,995,000   │ 10,000    │4,999.5x

As n grows, Hash Map becomes exponentially better!
```

### 💾 Space Complexity

```
╔═══════════════════════════════════════════════════════╗
║              SPACE COMPLEXITY ANALYSIS                ║
╚═══════════════════════════════════════════════════════╝

BRUTE FORCE APPROACH: O(1)
────────────────────────────────────────────────────────

Memory used:
    ┌───────────────────────────────┐
    │ Variable i: 4 bytes           │
    │ Variable j: 4 bytes           │
    │ Variable n: 4 bytes           │
    │ Total: ~12 bytes              │
    └───────────────────────────────┘

No matter how large the input array:
    n = 10     → 12 bytes
    n = 100    → 12 bytes
    n = 1,000  → 12 bytes
    n = 10,000 → 12 bytes

Constant space! Does not grow with input size.

════════════════════════════════════════════════════════

HASH MAP APPROACH: O(n)
────────────────────────────────────────────────────────

Memory used:
    ┌───────────────────────────────────────┐
    │ HashMap can store up to n elements    │
    │                                       │
    │ Worst case: Store all but last        │
    │ element before finding match          │
    │                                       │
    │ Example: [2,7,11,15] target=26        │
    │ HashMap: {2→0, 7→1, 11→2}            │
    │ Found 11+15=26 at last check          │
    └───────────────────────────────────────┘

Growth rate:
    n = 10     → Store up to 10 entries
    n = 100    → Store up to 100 entries
    n = 1,000  → Store up to 1,000 entries
    n = 10,000 → Store up to 10,000 entries

Linear space! Grows with input size.

════════════════════════════════════════════════════════

TRADE-OFF VISUALIZATION:
────────────────────────────────────────────────────────

Brute Force:
    Time:  ████████████████████████████████ O(n²) Slow
    Space: ██ O(1) Minimal

Hash Map:
    Time:  ████ O(n) Fast
    Space: ████████████████ O(n) Moderate

┌─────────────────────────────────────────────────────┐
│ THE TRADE-OFF:                                      │
│                                                     │
│ Brute Force: No extra space, but very slow         │
│ Hash Map: Uses extra space, but much faster        │
│                                                     │
│ When to use which?                                  │
│ • Small arrays (n < 100): Brute force OK           │
│ • Large arrays: Hash map is better                 │
│ • Memory constrained: Brute force                  │
│ • Speed critical: Hash map                         │
└─────────────────────────────────────────────────────┘
```

---

## 💼 Interview Questions & Answers - Two Sum

### ❓ Question 1: Why is the brute force approach O(n²)?

```
╔═══════════════════════════════════════════════════════╗
║              INTERVIEW ANSWER 1                       ║
╚═══════════════════════════════════════════════════════╝

ANSWER:
────────────────────────────────────────────────────────

The brute force approach uses nested loops:
    
    Outer loop: Runs n times (once for each element)
    Inner loop: Runs (n-1), (n-2), ..., 1 times
    
    Total operations = (n-1) + (n-2) + ... + 1
                     = n(n-1)/2
                     = (n² - n)/2

In Big O notation, we:
    1. Drop constants: (n² - n)/2 → n² - n
    2. Keep highest order term: n² - n → n²
    
    Result: O(n²)

SIMPLE EXPLANATION:
────────────────────────────────────────────────────────

For each element, we check it against all remaining
elements. That's like:

    1st element: check against 99 others  (if n=100)
    2nd element: check against 98 others
    3rd element: check against 97 others
    ...
    
    Total: ~5,000 comparisons for n=100
    This grows quadratically!

VISUALIZATION:
    ┌────────────────────────────────┐
    │ n = 4                          │
    │                                │
    │ i=0: ●─●─●─●  (3 comparisons)  │
    │ i=1:   ●─●─●  (2 comparisons)  │
    │ i=2:     ●─●  (1 comparison)   │
    │                                │
    │ Total: 3+2+1 = 6 = 4×3/2       │
    │ Pattern: n(n-1)/2 = O(n²)      │
    └────────────────────────────────┘
```

---

### ❓ Question 2: Can we use the same element twice?

```
╔═══════════════════════════════════════════════════════╗
║              INTERVIEW ANSWER 2                       ║
╚═══════════════════════════════════════════════════════╝

ANSWER:
────────────────────────────────────────────────────────

NO! The problem explicitly states we cannot use the
same element twice.

IMPORTANT DISTINCTION:
    ✓ Same VALUE at different indices: ALLOWED
    ✗ Same INDEX twice: NOT ALLOWED

CODE PROOF:
────────────────────────────────────────────────────────

In brute force, we ensure this by:

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {  // j starts AFTER i
            // This guarantees i ≠ j
        }
    }

Notice: j = i + 1 (not j = i)

EXAMPLE:
────────────────────────────────────────────────────────

Array: [3, 3], target = 6

Valid:   ✓ nums[0] + nums[1] = 3 + 3 = 6
         (index 0 + index 1 = different positions)

Invalid: ✗ nums[0] + nums[0] = 3 + 3 = 6
         (same index used twice)

VISUALIZATION:
    ┌─────────────────────────────────┐
    │ Array: [3, 3]                   │
    │                                 │
    │ Index 0  Index 1                │
    │    ↓       ↓                    │
    │   [3] ─+─ [3]  ✓ Valid         │
    │        │                        │
    │        │                        │
    │   [3] ─┘      ✗ Invalid        │
    │   (loops back to itself)        │
    └─────────────────────────────────┘
```

---

### ❓ Question 3: What if there are multiple valid pairs?

```
╔═══════════════════════════════════════════════════════╗
║              INTERVIEW ANSWER 3                       ║
╚═══════════════════════════════════════════════════════╝

ANSWER:
────────────────────────────────────────────────────────

The problem guarantees EXACTLY ONE solution exists.

Our algorithm returns the FIRST valid pair it finds,
which is perfectly acceptable since only one exists.

EXAMPLE:
────────────────────────────────────────────────────────

Suppose (hypothetically) array had multiple solutions:
    Array: [1, 2, 3, 4], target = 5
    
    Valid pairs:
        1 + 4 = 5  → indices [0, 3]
        2 + 3 = 5  → indices [1, 2]

Our algorithm would return [0, 3] (first found)

BUT: Problem states this scenario won't happen!
     Only one valid pair will exist.

SIMPLE EXPLANATION:
────────────────────────────────────────────────────────

Think of it like a treasure hunt where you're
guaranteed exactly one treasure exists.

Once you find it, you're done! No need to keep
searching for more.

┌─────────────────────────────────────────────────────┐
│ Interviewer might ask: "What if problem changes?"   │
│                                                     │
│ If multiple solutions allowed:                      │
│   • Modify return type to vector<vector<int>>      │
│   • Don't return immediately, store all pairs      │
│   • Continue checking after finding match          │
└─────────────────────────────────────────────────────┘
```

---

### ❓ Question 4: How does the hash map approach work?

```
╔═══════════════════════════════════════════════════════╗
║              INTERVIEW ANSWER 4                       ║
╚═══════════════════════════════════════════════════════╝

ANSWER:
────────────────────────────────────────────────────────

The hash map approach uses a clever insight:

    Instead of searching for a pair, we ask:
    "Have I already seen the complement of current number?"

ALGORITHM:
────────────────────────────────────────────────────────

For each number:
    1. Calculate complement = target - current
    2. Check if complement exists in hash map
       • If YES: Found pair! Return indices
       • If NO: Store current number in map
    3. Continue to next number

STEP-BY-STEP EXAMPLE:
────────────────────────────────────────────────────────

Array: [2, 7, 11, 15], Target: 9

    ┌──────────────────────────────────────┐
    │ STEP 1: i=0, current=2               │
    │ Complement: 9-2=7                    │
    │ Is 7 in map? NO                      │
    │ Add: map[2]=0                        │
    │ Map: {2→0}                           │
    └──────────────────────────────────────┘
              ↓
    ┌──────────────────────────────────────┐
    │ STEP 2: i=1, current=7               │
    │ Complement: 9-7=2                    │
    │ Is 2 in map? YES! (at index 0)       │
    │ Return: [0, 1]                       │
    └──────────────────────────────────────┘

WHY THIS IS SMART:
────────────────────────────────────────────────────────

Instead of O(n) search for each element,
hash map gives O(1) lookup!

    Brute Force: O(n) × O(n) = O(n²)
    Hash Map: O(n) × O(1) = O(n)

KEY POINTS:
    • We check BEFORE adding (prevents self-pairing)
    • We store value→index mapping
    • Complement check is instant (O(1))
```

---

### ❓ Question 5: What's the trade-off between approaches?

```
╔═══════════════════════════════════════════════════════╗
║              INTERVIEW ANSWER 5                       ║
╚═══════════════════════════════════════════════════════╝

ANSWER:
────────────────────────────────────────────────────────

The fundamental trade-off is TIME vs SPACE:

┌─────────────┬─────────────┬─────────────┬────────────┐
│  Approach   │    Time     │    Space    │  Use When  │
├─────────────┼─────────────┼─────────────┼────────────┤
│ Brute Force │   O(n²)     │    O(1)     │ • n < 100  │
│             │   Slow      │  No extra   │ • Memory   │
│             │             │   memory    │   limited  │
├─────────────┼─────────────┼─────────────┼────────────┤
│ Hash Map    │    O(n)     │    O(n)     │ • n > 100  │
│             │   Fast      │  Extra      │ • Speed    │
│             │             │   memory    │   matters  │
└─────────────┴─────────────┴─────────────┴────────────┘

ANALOGY:
────────────────────────────────────────────────────────

Brute Force = Walking
    • Free (no cost)
    • Slow
    • Good for short distances

Hash Map = Taking a taxi
    • Costs money (memory)
    • Fast
    • Good for long distances

REAL-WORLD DECISION:
────────────────────────────────────────────────────────

    Small dataset (n < 100):
        → Brute force is fine
        → Not worth the memory overhead
    
    Large dataset (n > 1000):
        → Hash map is essential
        → Speed difference is massive
    
    Production code:
        → Usually use hash map
        → Memory is cheap, speed matters

INTERVIEWER FOLLOW-UP:
────────────────────────────────────────────────────────

Q: "Which would you choose in production?"

A: "Hash map, because:
    • Modern systems have plenty of memory
    • User experience depends on speed
    • O(n) scales much better than O(n²)
    • Only use brute force if memory is critically
      constrained (e.g., embedded systems)"
```

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

```
╔═══════════════════════════════════════════════════════╗
║          POWERS OF TWO - COMPLETE TABLE               ║
╚═══════════════════════════════════════════════════════╝

Exponent │ Decimal Value │ Binary Representation │ Pattern
─────────┼───────────────┼───────────────────────┼─────────
  2^0    │       1       │         0001          │ 1 bit
  2^1    │       2       │         0010          │ 1 bit
  2^2    │       4       │         0100          │ 1 bit
  2^3    │       8       │         1000          │ 1 bit
  2^4    │      16       │        10000          │ 1 bit
  2^5    │      32       │       100000          │ 1 bit
  2^6    │      64       │      1000000-1?                  │
    │                                        │
    │   n     = 1000                         │
    │   n - 1 = 0111                         │
    │                                        │
    │ Subtracting 1 from a power of 2:      │
    │   • The single '1' bit becomes '0'     │
    │   • All bits to the right become '1'   │
    │   • (no bits to the right in 1000,     │
    │      but the '1' itself becomes '0'    │
    │      and all lower bits become '1')    │
    └────────────────────────────────────────┘
    
    ┌────────────────────────────────────────┐
    │ STEP 2: What is n & (n-1)?             │
    │                                        │
    │   n     = 1000                         │
    │   n - 1 = 0111                         │
    │   ─────   ────                         │
    │   AND   = 0000  ← No overlapping bits! │
    │                                        │
    │ Result: 0 ✓                            │
    └────────────────────────────────────────┘

Visual representation:
    
    n = 8:
    Bit position: 7 6 5 4 3 2 1 0
                 ┌─┬─┬─┬─┬─┬─┬─┬─┐
    n            │0│0│0│0│1│0│0│0│
                 └─┴─┴─┴─┴─┴─┴─┴─┘
                         ↓
                   (subtract 1)
                         ↓
                 ┌─┬─┬─┬─┬─┬─┬─┬─┐
    n - 1        │0│0│0│0│0│1│1│1│
                 └─┴─┴─┴─┴─┴─┴─┴─┘
                         ↓
                    (AND operation)
                         ↓
                 ┌─┬─┬─┬─┬─┬─┬─┬─┐
    n & (n-1)    │0│0│0│0│0│0│0│0│ = 0 ✓
                 └─┴─┴─┴─┴─┴─┴─┴─┘

════════════════════════════════════════════════════════

CASE 2: n is NOT a Power of 2
────────────────────────────────────────────────────────

Structure: n has MULTIPLE '1' bits
    
    Example: n = 6 = 0110
    
    ┌────────────────────────────────────────┐
    │ STEP 1: What is n - 1?                 │
    │                                        │
    │   n     = 0110                         │
    │   n - 1 = 0101                         │
    │                                        │
    │ Subtracting 1 from non-power of 2:     │
    │   • Rightmost '1' bit becomes '0'      │
    │   • All bits to its right become '1'   │
    │   • BUT: Other '1' bits remain!        │
    └────────────────────────────────────────┘
    
    ┌────────────────────────────────────────┐
    │ STEP 2: What is n & (n-1)?             │
    │                                        │
    │   n     = 0110                         │
    │   n - 1 = 0101                         │
    │   ─────   ────                         │
    │   AND   = 0100  ← Still has a '1' bit! │
    │                                        │
    │ Result: 4 ≠ 0 ✗                        │
    └────────────────────────────────────────┘

Visual representation:
    
    n = 6:
    Bit position: 7 6 5 4 3 2 1 0
                 ┌─┬─┬─┬─┬─┬─┬─┬─┐
    n            │0│0│0│0│0│1│1│0│
                 └─┴─┴─┴─┴─┴─┴─┴─┘
                         ↑ ↑
                    Two '1' bits
                         ↓
                   (subtract 1)
                         ↓
                 ┌─┬─┬─┬─┬─┬─┬─┬─┐
    n - 1        │0│0│0│0│0│1│0│1│
                 └─┴─┴─┴─┴─┴─┴─┴─┘
                         ↓
                    (AND operation)
                         ↓
                 ┌─┬─┬─┬─┬─┬─┬─┬─┐
    n & (n-1)    │0│0│0│0│0│1│0│0│ = 4 ≠ 0 ✗
                 └─┴─┴─┴─┴─┴─┴─┴─┘
                         ↑
                  Still has '1' bit!

════════════════════════════════════════════════════════

WHY THE TRICK WORKS - SUMMARY:
────────────────────────────────────────────────────────

┌─────────────────────────────────────────────────────┐
│ POWER OF 2:                                         │
│   • Has exactly ONE '1' bit                         │
│   • Subtracting 1 flips that bit and all to right   │
│   • No overlap with original → n & (n-1) = 0        │
│                                                     │
│ NOT POWER OF 2:                                     │
│   • Has MULTIPLE '1' bits                           │
│   • Subtracting 1 only affects rightmost '1'        │
│   • Other '1' bits remain → n & (n-1) ≠ 0          │
└─────────────────────────────────────────────────────┘
```

---

## 📚 Step-by-Step Examples

### 🟢 Example 1: n = 1

```
╔═══════════════════════════════════════════════════════╗
║               EXAMPLE 1: n = 1                        ║
╚═══════════════════════════════════════════════════════╝

Input: n = 1
Output: true (because 2^0 = 1)

BINARY ANALYSIS:
────────────────────────────────────────────────────────

n = 1 in binary:
    Bit position: 7 6 5 4 3 2 1 0
                 ┌─┬─┬─┬─┬─┬─┬─┬─┐
                 │0│0│0│0│0│0│0│1│
                 └─┴─┴─┴─┴─┴─┴─┴─┘
                                 ↑
                           ONE bit set ✓

STEP-BY-STEP:
────────────────────────────────────────────────────────

STEP 1: Check if n > 0
    ┌──────────────────────────┐
    │ Is 1 > 0?                │
    │ YES ✓                    │
    └──────────────────────────┘

STEP 2: Calculate n & (n-1)
    ┌──────────────────────────┐
    │ n     = 1 = 0001         │
    │ n - 1 = 0 = 0000         │
    │ ─────     ────           │
    │ AND     = 0000 = 0       │
    └──────────────────────────┘

STEP 3: Check if result is 0
    ┌──────────────────────────┐
    │ Is n & (n-1) == 0?       │
    │ Is 0 == 0?               │
    │ YES ✓                    │
    └──────────────────────────┘

CONCLUSION:
    ┌──────────────────────────┐
    │ n > 0? ✓                 │
    │ n & (n-1) == 0? ✓        │
    │ Result: TRUE             │
    │ 1 is a power of 2 (2^0)  │
    └──────────────────────────┘
```

---

### 🔵 Example 2: n = 16

```
╔═══════════════════════════════════════════════════════╗
║              EXAMPLE 2: n = 16                        ║
╚═══════════════════════════════════════════════════════╝

Input: n = 16
Output: true (because 2^4 = 16)

BINARY ANALYSIS:
────────────────────────────────────────────────────────

n = 16 in binary:
    Bit position: 7 6 5 4 3 2 1 0
                 ┌─┬─┬─┬─┬─┬─┬─┬─┐
                 │0│0│0│1│0│0│0│0│
                 └─┴─┴─┴─┴─┴─┴─┴─┘
                         ↑
                   ONE bit set ✓

STEP-BY-STEP:
────────────────────────────────────────────────────────

STEP 1: Check if n > 0
    ┌──────────────────────────┐
    │ Is 16 > 0?               │
    │ YES ✓                    │
    └──────────────────────────┘

STEP 2: Calculate n - 1
    ┌──────────────────────────────────────┐
    │ n     = 16 = 10000                   │
    │ n - 1 = 15 = 01111                   │
    │                                      │
    │ When we subtract 1:                  │
    │   • The '1' at position 4 → '0'      │
    │   • All bits to right → '1'          │
    └──────────────────────────────────────┘

STEP 3: Calculate n & (n-1)
    ┌──────────────────────────────────────┐
    │ n     = 16 = 10000                   │
    │ n - 1 = 15 = 01111                   │
    │ ─────────    ─────                   │
    │ n & (n-1) =  00000 = 0               │
    │                                      │
    │ No overlapping '1' bits!             │
    └──────────────────────────────────────┘

Visual AND operation:
    
    Position: 4 3 2 1 0
             ┌─┬─┬─┬─┬─┐
    n        │1│0│0│0│0│
             ├─┼─┼─┼─┼─┤
    n-1      │0│1│1│1│1│
             ├─┼─┼─┼─┼─┤
    AND      │0│0│0│0│0│ ← All zeros!
             └─┴─┴─┴─┴─┘

STEP 4: Check if result is 0
    ┌──────────────────────────┐
    │ Is n & (n-1) == 0?       │
    │ Is 0 == 0?               │
    │ YES ✓                    │
    └──────────────────────────┘

CONCLUSION:
    ┌──────────────────────────┐
    │ n > 0? ✓                 │
    │ n & (n-1) == 0? ✓        │
    │ Result: TRUE             │
    │ 16 is a power of 2 (2^4) │
    └──────────────────────────┘
```

---

### 🔴 Example 3: n = 3

```
╔═══════════════════════════════════════════════════════╗
║               EXAMPLE 3: n = 3                        ║
╚═══════════════════════════════════════════════════════╝

Input: n = 3
Output: false

BINARY ANALYSIS:
────────────────────────────────────────────────────────

n = 3 in binary:
    Bit position: 7 6 5 4 3 2 1 0
                 ┌─┬─┬─┬─┬─┬─┬─┬─┐
                 │0│0│0│0│0│0│1│1│
                 └─┴─┴─┴─┴─┴─┴─┴─┘
                             ↑ ↑
                        TWO bits set ✗

STEP-BY-STEP:
────────────────────────────────────────────────────────

STEP 1: Check if n > 0
    ┌──────────────────────────┐
    │ Is 3 > 0?                │
    │ YES ✓                    │
    └──────────────────────────┘

STEP 2: Calculate n - 1
    ┌──────────────────────────────────────┐
    │ n     = 3 = 0011                     │
    │ n - 1 = 2 = 0010                     │
    │                                      │
    │ When we subtract 1:                  │
    │   • Rightmost '1' (pos 0) → '0'      │
    │   • Other '1' bit (pos 1) remains!   │
    └──────────────────────────────────────┘

STEP 3: Calculate n & (n-1)
    ┌──────────────────────────────────────┐
    │ n     = 3 = 0011                     │
    │ n - 1 = 2 = 0010                     │
    │ ─────────   ────                     │
    │ n & (n-1) = 0010 = 2 ≠ 0 ✗           │
    │                                      │
    │ Still has a '1' bit at position 1!   │
    └──────────────────────────────────────┘

Visual AND operation:
    
    Position: 3 2 1 0
             ┌─┬─┬─┬─┐
    n        │0│0│1│1│
             ├─┼─┼─┼─┤
    n-1      │0│0│1│0│
             ├─┼─┼─┼─┤
    AND      │0│0│1│0│ ← Still has '1' bit!
             └─┴─┴─┴─┘
                 ↑
            NOT zero!

STEP 4: Check if result is 0
    ┌──────────────────────────┐
    │ Is n & (n-1) == 0?       │
    │ Is 2 == 0?               │
    │ NO ✗                     │
    └──────────────────────────┘

CONCLUSION:
    ┌──────────────────────────┐
    │ n > 0? ✓                 │
    │ n & (n-1) == 0? ✗        │
    │ Result: FALSE            │
    │ 3 is NOT a power of 2    │
    └──────────────────────────┘

WHY IT FAILS:
────────────────────────────────────────────────────────

3 has TWO '1' bits in binary (0011)
Powers of 2 have exactly ONE '1' bit

    Power of 2: 0001, 0010, 0100, 1000 (one bit)
    Not power:  0011, 0101, 0110, 0111 (multiple bits)
```

---

### 🟡 Example 4: n = 5

```
╔═══════════════════════════════════════════════════════╗
║               EXAMPLE 4: n = 5                        ║
╚═══════════════════════════════════════════════════════╝

Input: n = 5
Output: false

BINARY ANALYSIS:
────────────────────────────────────────────────────────

n = 5 in binary:
    Bit position: 7 6 5 4 3 2 1 0
                 ┌─┬─┬─┬─┬─┬─┬─┬─┐
                 │0│0│0│0│0│1│0│1│
                 └─┴─┴─┴─┴─┴─┴─┴─┘
                         ↑   ↑
                    TWO bits set ✗
                  (positions 2 and 0)

STEP-BY-STEP:
────────────────────────────────────────────────────────

STEP 1: Check if n > 0
    ┌──────────────────────────┐
    │ Is 5 > 0?                │
    │ YES ✓                    │
    └──────────────────────────┘

STEP 2: Calculate n - 1
    ┌──────────────────────────────────────┐
    │ n     = 5 = 0101                     │
    │ n - 1 = 4 = 0100                     │
    │                                      │
    │ When we subtract 1:                  │
    │   • Rightmost '1' (pos 0) → '0'      │
    │   • Other '1' bit (pos 2) remains!   │
    └──────────────────────────────────────┘

STEP 3: Calculate n & (n-1)
    ┌──────────────────────────────────────┐
    │ n     = 5 = 0101                     │
    │ n - 1 = 4 = 0100                     │
    │ ─────────   ────                     │
    │ n & (n-1) = 0100 = 4 ≠ 0 ✗           │
    │                                      │
    │ Still has a '1' bit at position 2!   │
    └──────────────────────────────────────┘

Visual AND operation:
    
    Position: 3 2 1 0
             ┌─┬─┬─┬─┐
    n        │0│1│0│1│
             ├─┼─┼─┼─┤
    n-1      │0│1│0│0│
             ├─┼─┼─┼─┤
    AND      │0│1│0│0│ ← Still has '1' bit!
             └─┴─┴─┴─┘
                 ↑
            NOT zero!

STEP 4: Check if result is 0
    ┌──────────────────────────┐
    │ Is n & (n-1) == 0?       │
    │ Is 4 == 0?               │
    │ NO ✗                     │
    └──────────────────────────┘

CONCLUSION:
    ┌──────────────────────────┐
    │ n > 0? ✓                 │
    │ n & (n-1) == 0? ✗        │
    │ Result: FALSE            │
    │ 5 is NOT a power of 2    │
    └──────────────────────────┘
```

---

## 🛠️ The Algorithm

### 🎯 Main Strategy

```
╔═══════════════════════════════════════════════════════╗
║         POWER OF TWO ALGORITHM FLOWCHART              ║
╚═══════════════════════════════════════════════════════╝

                    START
                      ↓
         ┌────────────────────────┐
         │   Input: integer n     │
         └────────────┬───────────┘
                      ↓
              ┌───────────────┐
              │  Is n > 0?    │
              └───┬───────┬───┘
                  │       │
              NO  │       │ YES
                  │       │
                  ↓       ↓
         ┌──────────┐  ┌──────────────────┐
         │  Return  │  │ Calculate:       │
         │  FALSE   │  │ result = n&(n-1) │
         │          │  └────────┬─────────┘
         │ (Powers  │           │
         │  of 2    │           ↓
         │  are     │    ┌──────────────┐
         │ positive)│    │ Is result    │
         └──────────┘    │   == 0?      │
                        └──┬────────┬──┘
                           │        │
                       YES │        │ NO
                           │        │
                           ↓        ↓
                    ┌──────────┐ ┌──────────┐
                    │  Return  │ │  Return  │
                    │  TRUE    │ │  FALSE   │
                    │          │ │          │
                    │ (Power   │ │ (Not a   │
                    │  of 2!)  │ │  power)  │
                    └──────────┘ └──────────┘

═══════════════════════════════════════════════════════

DECISION LOGIC:
────────────────────────────────────────────────────────

┌─────────────────────────────────────────────────────┐
│ CONDITION 1: n > 0                                  │
│   Why? Powers of 2 are always positive             │
│   • 2^0 = 1                                         │
│   • 2^1 = 2                                         │
│   • 2^2 = 4                                         │
│   • All positive!                                   │
│                                                     │
│   Eliminates:                                       │
│   • n = 0 (not a power of 2)                        │
│   • n < 0 (negative numbers)                        │
└─────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────┐
│ CONDITION 2: n & (n-1) == 0                         │
│   Why? Only powers of 2 have this property          │
│   • Single '1' bit in binary                        │
│   • Subtracting 1 flips all bits after it           │
│   • AND operation gives 0                           │
│                                                     │
│   Example:                                          │
│   • 8:  1000 & 0111 = 0000 ✓                        │
│   • 6:  0110 & 0101 = 0100 ✗                        │
└─────────────────────────────────────────────────────┘

BOTH conditions must be TRUE for power of 2!
```

### 💻 The Complete Solution

```cpp
bool isPowerOfTwo(int n) {
    /*
     * ═══════════════════════════════════════════════════════
     *          POWER OF TWO - BIT MANIPULATION SOLUTION
     * ═══════════════════════════════════════════════════════
     * 
     * ALGORITHM: Check two conditions
     * 
     * CONDITION 1: n > 0
     * ────────────────────────────────────────────────────────
     * Why check this?
     *   • Powers of 2 are always positive (2^0, 2^1, 2^2...)
     *   • Eliminates n = 0 (not a power of 2)
     *   • Eliminates negative numbers
     * 
     * Examples:
     *   ✓ n = 1, 2, 4, 8, 16... (all positive)
     *   ✗ n = 0 (no exponent gives 0)
     *   ✗ n = -16 (negative, not considered)
     * 
     * CONDITION 2: n & (n-1) == 0
     * ────────────────────────────────────────────────────────
     * Why this works?
     *   • Powers of 2 have exactly ONE bit set
     *   • Subtracting 1 flips that bit and all to right
     *   • AND with original gives 0 (no overlap)
     * 
     * Visual proof (n = 8):
     *     n     = 8 = 1000
     *     n - 1 = 7 = 0111
     *     ──────────  ────
     *     AND       = 0000 = 0 ✓
     * 
     * Counter-example (n = 6):
     *     n     = 6 = 0110 (two bits set)
     *     n - 1 = 5 = 0101
     *     ──────────  ────
     *     AND       = 0100 = 4 ≠ 0 ✗
     * 
     * ═══════════════════════════════════════════════════════
     */
    
    /*
     * ┌─────────────────────────────────────────────┐
     * │ THE MAGIC ONE-LINER                         │
     * │                                             │
     * │ Must satisfy BOTH conditions:               │
     * │   1. n > 0      (positive number)           │
     * │   2. n&(n-1)==0 (single bit set)            │
     * │                                             │
     * │ Use logical AND (&&) to combine them        │
     * └─────────────────────────────────────────────┘
     */
    return (n > 0 && (n & (n-1)) == 0);
    
    /*
     * EXECUTION FLOW:
     * ───────────────────────────────────────────────────────
     * 
     * Example 1: n = 8
     *     Step 1: Check n > 0
     *             8 > 0 → TRUE ✓
     *     
     *     Step 2: Check n & (n-1) == 0
     *             8 & 7 = 1000 & 0111 = 0000 → TRUE ✓
     *     
     *     Both TRUE → Return TRUE ✓
     * 
     * Example 2: n = 6
     *     Step 1: Check n > 0
     *             6 > 0 → TRUE ✓
     *     
     *     Step 2: Check n & (n-1) == 0
     *             6 & 5 = 0110 & 0101 = 0100 = 4 → FALSE ✗
     *     
     *     One FALSE → Return FALSE ✗
     * 
     * Example 3: n = 0
     *     Step 1: Check n > 0
     *             0 > 0 → FALSE ✗
     *     
     *     (Short-circuit: don't check second condition)
     *     
     *     Return FALSE ✗
     * 
     * Example 4: n = -16
     *     Step 1: Check n > 0
     *             -16 > 0 → FALSE ✗
     *     
     *     (Short-circuit: don't check second condition)
     *     
     *     Return FALSE ✗
     */
}
```

### 🔍 Why Check n > 0?

```
╔═══════════════════════════════════════════════════════╗
║           WHY THE n > 0 CHECK IS CRITICAL             ║
╚═══════════════════════════════════════════════════════╝

CASE 1: n = 0 (Zero)
────────────────────────────────────────────────────────

Question: Is 0 a power of 2?

Answer: NO!

    ┌──────────────────────────────────────┐
    │ There is no exponent x where 2^x = 0 │
    │                                      │
    │ 2^0 = 1                              │
    │ 2^-1 = 0.5                           │
    │ 2^-infinity → 0 (but never equals 0) │
    └──────────────────────────────────────┘

Binary representation of 0:
    0 = 0000 (no bits set)
    
Without n > 0 check:
    0 & (0-1) = 0 & -1
              = 0000 & 1111 (in 2's complement)
              = 0000 = 0
    
    Would incorrectly return TRUE! ✗

With n > 0 check:
    0 > 0 → FALSE
    Return FALSE immediately ✓

════════════════════════════════════════════════════════

CASE 2: n < 0 (Negative Numbers)
────────────────────────────────────────────────────────

Question: Are negative numbers powers of 2?

Answer: NO (in this problem context)!

    ┌──────────────────────────────────────┐
    │ Problem asks for integer powers:     │
    │ 2^0, 2^1, 2^2, ... (all positive)    │
    │                                      ││ 4. Provides early exit (performance)                │
│ 5. Avoids complex negative number bit handling     │
└─────────────────────────────────────────────────────┘
```

---

## 🧪 Test Cases & Edge Cases - Power of Two

### ✅ Valid Powers of Two

```
╔═══════════════════════════════════════════════════════╗
║          VALID POWERS OF TWO TEST CASES               ║
╚═══════════════════════════════════════════════════════╝

TEST CASE 1: Smallest Power (2^0)
────────────────────────────────────────────────────────
Input:  n = 1
Binary: 0001
Output: true
Reason: 2^0 = 1 ✓

TEST CASE 2: Basic Power (2^1)
────────────────────────────────────────────────────────
Input:  n = 2
Binary: 0010
Output: true
Reason: 2^1 = 2 ✓

TEST CASE 3: Common Power (2^2)
────────────────────────────────────────────────────────
Input:  n = 4
Binary: 0100
Output: true
Reason: 2^2 = 4 ✓

TEST CASE 4: Byte Boundary (2^3)
────────────────────────────────────────────────────────
Input:  n = 8
Binary: 1000
Output: true
Reason: 2^3 = 8 ✓

TEST CASE 5: Medium Power (2^4)
────────────────────────────────────────────────────────
Input:  n = 16
Binary: 10000
Output: true
Reason: 2^4 = 16 ✓

TEST CASE 6: Computer Memory Size (2^5)
────────────────────────────────────────────────────────
Input:  n = 32
Binary: 100000
Output: true
Reason: 2^5 = 32 ✓

TEST CASE 7: Common in Programming (2^6)
────────────────────────────────────────────────────────
Input:  n = 64
Binary: 1000000
Output: true
Reason: 2^6 = 64 ✓

TEST CASE 8: Byte Value (2^7)
────────────────────────────────────────────────────────
Input:  n = 128
Binary: 10000000
Output: true
Reason: 2^7 = 128 ✓

TEST CASE 9: Pixel Dimension (2^8)
────────────────────────────────────────────────────────
Input:  n = 256
Binary: 100000000
Output: true
Reason: 2^8 = 256 ✓

TEST CASE 10: Kilobyte Marker (2^10)
────────────────────────────────────────────────────────
Input:  n = 1024
Binary: 10000000000
Output: true
Reason: 2^10 = 1024 ✓

PATTERN RECOGNITION:
────────────────────────────────────────────────────────
All valid powers of 2 have:
    • Exactly ONE bit set to '1'
    • n & (n-1) equals 0
    • Positive value
```

### ❌ Not Powers of Two

```
╔═══════════════════════════════════════════════════════╗
║         INVALID (NOT POWERS OF TWO) TEST CASES        ║
╚═══════════════════════════════════════════════════════╝

TEST CASE 1: Multiple Bits Set
────────────────────────────────────────────────────────
Input:  n = 3
Binary: 0011 (bits at positions 0 and 1)
Output: false
Reason: 3 & 2 = 0011 & 0010 = 0010 ≠ 0 ✗

TEST CASE 2: Multiple Bits Set
────────────────────────────────────────────────────────
Input:  n = 5
Binary: 0101 (bits at positions 0 and 2)
Output: false
Reason: 5 & 4 = 0101 & 0100 = 0100 ≠ 0 ✗

TEST CASE 3: Multiple Bits Set
────────────────────────────────────────────────────────
Input:  n = 6
Binary: 0110 (bits at positions 1 and 2)
Output: false
Reason: 6 & 5 = 0110 & 0101 = 0100 ≠ 0 ✗

TEST CASE 4: Multiple Bits Set
────────────────────────────────────────────────────────
Input:  n = 7
Binary: 0111 (bits at positions 0, 1, and 2)
Output: false
Reason: 7 & 6 = 0111 & 0110 = 0110 ≠ 0 ✗

TEST CASE 5: Zero (Special Case)
────────────────────────────────────────────────────────
Input:  n = 0
Binary: 0000 (no bits set)
Output: false
Reason: 0 is not > 0, fails first condition ✗

TEST CASE 6: Negative Number
────────────────────────────────────────────────────────
Input:  n = -16
Binary: (2's complement representation)
Output: false
Reason: -16 is not > 0, fails first condition ✗

PATTERN RECOGNITION:
────────────────────────────────────────────────────────
Invalid numbers have:
    • ZERO bits set (n = 0)
    • MULTIPLE bits set (n = 3, 5, 6, 7...)
    • Negative values
```

### 🎯 Binary Representation Analysis

```
╔═══════════════════════════════════════════════════════╗
║        VISUAL COMPARISON: POWERS vs NON-POWERS        ║
╚═══════════════════════════════════════════════════════╝

POWERS OF TWO (✓ One bit set):
────────────────────────────────────────────────────────

    1  = 00000001  ← Single '1' at position 0
    2  = 00000010  ← Single '1' at position 1
    4  = 00000100  ← Single '1' at position 2
    8  = 00001000  ← Single '1' at position 3
    16 = 00010000  ← Single '1' at position 4
    32 = 00100000  ← Single '1' at position 5

════════════════════════════════════════════════════════

NOT POWERS OF TWO (✗ Multiple/zero bits):
────────────────────────────────────────────────────────

    0  = 00000000  ← ZERO bits set
    3  = 00000011  ← TWO bits (positions 0, 1)
    5  = 00000101  ← TWO bits (positions 0, 2)
    6  = 00000110  ← TWO bits (positions 1, 2)
    7  = 00000111  ← THREE bits (positions 0, 1, 2)
    9  = 00001001  ← TWO bits (positions 0, 3)
    10 = 00001010  ← TWO bits (positions 1, 3)
    11 = 00001011  ← THREE bits (positions 0, 1, 3)
    12 = 00001100  ← TWO bits (positions 2, 3)

════════════════════════════════════════════════════════

VISUALIZATION TABLE:
────────────────────────────────────────────────────────

┌────────┬──────────┬───────────┬──────────────────────┐
│ Number │  Binary  │ Bits Set  │    Power of Two?     │
├────────┼──────────┼───────────┼──────────────────────┤
│   1    │ 00000001 │     1     │   ✓ YES (2^0)        │
│   2    │ 00000010 │     1     │   ✓ YES (2^1)        │
│   3    │ 00000011 │     2     │   ✗ NO               │
│   4    │ 00000100 │     1     │   ✓ YES (2^2)        │
│   5    │ 00000101 │     2     │   ✗ NO               │
│   6    │ 00000110 │     2     │   ✗ NO               │
│   7    │ 00000111 │     3     │   ✗ NO               │
│   8    │ 00001000 │     1     │   ✓ YES (2^3)        │
│   16   │ 00010000 │     1     │   ✓ YES (2^4)        │
│   32   │ 00100000 │     1     │   ✓ YES (2^5)        │
└────────┴──────────┴───────────┴──────────────────────┘

RULE: If bits_set == 1, then it's a power of 2!
```

---

## 📊 Complexity Analysis - Power of Two

### ⏰ Time Complexity: O(1)

```
╔═══════════════════════════════════════════════════════╗
║           TIME COMPLEXITY: O(1) CONSTANT              ║
╚═══════════════════════════════════════════════════════╝

WHY CONSTANT TIME?
────────────────────────────────────────────────────────

The algorithm performs a FIXED number of operations:

    ┌──────────────────────────────────────┐
    │ Operation 1: Check n > 0             │
    │ Time: O(1) - single comparison       │
    └──────────────────────────────────────┘
              ↓
    ┌──────────────────────────────────────┐
    │ Operation 2: Calculate n - 1         │
    │ Time: O(1) - single arithmetic op    │
    └──────────────────────────────────────┘
              ↓
    ┌──────────────────────────────────────┐
    │ Operation 3: Bitwise AND (n & n-1)   │
    │ Time: O(1) - single bitwise op       │
    └──────────────────────────────────────┘
              ↓
    ┌──────────────────────────────────────┐
    │ Operation 4: Compare result to 0     │
    │ Time: O(1) - single comparison       │
    └──────────────────────────────────────┘

Total: O(1) + O(1) + O(1) + O(1) = O(1)

════════════════════════════════════════════════════════

NO LOOPS, NO RECURSION:
────────────────────────────────────────────────────────

Unlike algorithms that iterate:
    
    ✗ NO for loops
    ✗ NO while loops
    ✗ NO recursive calls
    ✗ NO array scanning
    
    ✓ Just direct bit manipulation!

════════════════════════════════════════════════════════

PERFORMANCE CHART:
────────────────────────────────────────────────────────

Input Size │ Operations │ Time
───────────┼────────────┼─────────
    1      │     4      │ Instant
   10      │     4      │ Instant
  100      │     4      │ Instant
  1,000    │     4      │ Instant
 10,000    │     4      │ Instant
1,000,000  │     4      │ Instant

No matter the value of n, always 4 operations!

════════════════════════════════════════════════════════

COMPARISON WITH OTHER APPROACHES:
────────────────────────────────────────────────────────

Bit Manipulation (Our Solution):
    Time: O(1) ⚡⚡⚡
    Operations: 4 (always)

Division Loop Approach:
    Time: O(log n) ⚡
    Operations: log₂(n)
    Example: n = 1024 → 10 operations
    
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;

Bit Counting Approach:
    Time: O(1) ⚡⚡
    Operations: Count bits (library-dependent)
    
    return __builtin_popcount(n) == 1;

┌─────────────────────────────────────────────────────┐
│ Our bit manipulation is the FASTEST approach!       │
│ • Fewest operations                                 │
│ • No function calls                                 │
│ • Pure arithmetic and bitwise ops                   │
└─────────────────────────────────────────────────────┘
```

### 💾 Space Complexity: O(1)

```
╔═══════════════════════════════════════════════════════╗
║          SPACE COMPLEXITY: O(1) CONSTANT              ║
╚═══════════════════════════════════════════════════════╝

WHY CONSTANT SPACE?
────────────────────────────────────────────────────────

Memory Usage Analysis:

    ┌──────────────────────────────────────┐
    │ Variable: n (input parameter)        │
    │ Size: 4 bytes (int)                  │
    └──────────────────────────────────────┘
              ↓
    ┌──────────────────────────────────────┐
    │ Temporary: n - 1 (calculated)        │
    │ Size: 4 bytes                        │
    └──────────────────────────────────────┘
              ↓
    ┌──────────────────────────────────────┐
    │ Temporary: result of AND operation   │
    │ Size: 4 bytes                        │
    └──────────────────────────────────────┘

Total Memory: ~12 bytes (constant)

════════════════════════════════════════════════════════

NO EXTRA DATA STRUCTURES:
────────────────────────────────────────────────────────

    ✗ NO arrays
    ✗ NO vectors
    ✗ NO hash maps
    ✗ NO strings
    ✗ NO recursion stack
    
    ✓ Only primitive variables!

════════════════════════════════════════════════════════

SPACE USAGE TABLE:
────────────────────────────────────────────────────────

Input Value │ Space Used │ Comment
────────────┼────────────┼─────────────────────
     1      │  12 bytes  │ Constant
    10      │  12 bytes  │ Same
   100      │  12 bytes  │ Same
  1000      │  12 bytes  │ Same
1000000     │  12 bytes  │ Same

No growth with input size!

════════════════════════════════════════════════════════

SUMMARY:
────────────────────────────────────────────────────────

┌─────────────────────────────────────────────────────┐
│ Space Complexity: O(1)                              │
│                                                     │
│ • Fixed number of variables                         │
│ • No dynamic allocation                             │
│ • No data structure overhead                        │
│ • Minimal memory footprint                          │
│                                                     │
│ Perfect for:                                        │
│ • Embedded systems                                  │
│ • Memory-constrained environments                   │
│ • High-performance computing                        │
└─────────────────────────────────────────────────────┘
```

---

## 🎓 Alternative Approaches

### 🔄 Approach 1: Division Loop

```cpp
bool isPowerOfTwo(int n) {
    /*
     * ═══════════════════════════════════════════════════════
     *              DIVISION LOOP APPROACH
     * ═══════════════════════════════════════════════════════
     * 
     * CONCEPT: Keep dividing by 2 until we can't anymore
     * 
     * If n is a power of 2:
     *   • We can keep dividing by 2 evenly
     *   • Eventually reach 1
     * 
     * If n is NOT a power of 2:
     *   • At some point, division won't be even
     *   • End up with a number > 1
     * 
     * EXAMPLE: n = 8
     * ────────────────────────────────────────────────────────
     *   8 ÷ 2 = 4 (even) → continue
     *   4 ÷ 2 = 2 (even) → continue
     *   2 ÷ 2 = 1 (even) → stop, n == 1 ✓
     * 
     * EXAMPLE: n = 6
     * ────────────────────────────────────────────────────────
     *   6 ÷ 2 = 3 (even) → continue
     *   3 ÷ 2 = 1.5 (NOT even) → stop, n == 3 ≠ 1 ✗
     */
    
    // Handle edge cases
    if (n <= 0) return false;
    
    // Keep dividing by 2 while even
    while (n % 2 == 0) {
        n /= 2;
    }
    
    // If we reach 1, it was a power of 2
    return n == 1;
}

/*
 * COMPLEXITY ANALYSIS:
 * ────────────────────────────────────────────────────────
 * Time: O(log n)
 *   • Loop runs log₂(n) times
 *   • Example: n = 1024 → 10 iterations
 * 
 * Space: O(1)
 *   • Only one variable (n)
 *   • No extra data structures
 * 
 * PROS:
 * ────────────────────────────────────────────────────────
 *   ✓ Easy to understand
 *   ✓ Intuitive logic
 *   ✓ No bit manipulation knowledge needed
 * 
 * CONS:
 * ────────────────────────────────────────────────────────
 *   ✗ Slower than bit manipulation O(log n) vs O(1)
 *   ✗ Uses division (expensive operation)
 *   ✗ Modifies input variable
 */
```

**Execution Trace:**
```
╔═══════════════════════════════════════════════════════╗
║         DIVISION LOOP EXECUTION TRACE                 ║
╚═══════════════════════════════════════════════════════╝

Example 1: n = 16 (Power of 2)
────────────────────────────────────────────────────────

Initial: n = 16

Iteration 1:
    ┌──────────────────────────┐
    │ 16 % 2 == 0? YES         │
    │ n = 16 / 2 = 8           │
    └──────────────────────────┘

Iteration 2:
    ┌──────────────────────────┐
    │ 8 % 2 == 0? YES          │
    │ n = 8 / 2 = 4            │
    └──────────────────────────┘

Iteration 3:
    ┌──────────────────────────┐
    │ 4 % 2 == 0? YES          │
    │ n = 4 / 2 = 2            │
    └──────────────────────────┘

Iteration 4:
    ┌──────────────────────────┐
    │ 2 % 2 == 0? YES          │
    │ n = 2 / 2 = 1            │
    └──────────────────────────┘

Iteration 5:
    ┌──────────────────────────┐
    │ 1 % 2 == 0? NO           │
    │ Exit loop                │
    └──────────────────────────┘

Check: n == 1? YES ✓
Return: TRUE

════════════════════════════════════════════════════════

Example 2: n = 6 (NOT Power of 2)
────────────────────────────────────────────────────────

Initial: n = 6

Iteration 1:
    ┌──────────────────────────┐
    │ 6 % 2 == 0? YES          │
    │ n = 6 / 2 = 3            │
    └──────────────────────────┘

Iteration 2:
    ┌──────────────────────────┐
    │ 3 % 2 == 0? NO           │
    │ Exit loop                │
    └──────────────────────────┘

Check: n == 1? NO (n = 3) ✗
Return: FALSE
```

---

### 🔄 Approach 2: Bit Counting

```cpp
bool isPowerOfTwo(int n) {
    /*
     * ═══════════════════════════════════════════════════════
     *              BIT COUNTING APPROACH
     * ═══════════════════════════════════════════════════════
     * 
     * CONCEPT: Count how many '1' bits are set
     * 
     * Powers of 2 have exactly ONE bit set:
     *   • 1  = 0001 → 1 bit
     *   • 2  = 0010 → 1 bit
     *   • 4  = 0100 → 1 bit
     *   • 8  = 1000 → 1 bit
     * 
     * Non-powers have zero or multiple bits:
     *   • 0  = 0000 → 0 bits
     *   • 3  = 0011 → 2 bits
     *   • 6  = 0110 → 2 bits
     *   • 7  = 0111 → 3 bits
     * 
     * __builtin_popcount(): GCC/Clang built-in function
     *   • Counts number of '1' bits
     *   • Highly optimized
     *   • Uses CPU instruction if available
     */
    
    // Must be positive AND have exactly one bit set
    if (n <= 0) return false;
    return __builtin_popcount(n) == 1;
}

/*
 * COMPLEXITY ANALYSIS:
 * ────────────────────────────────────────────────────────
 * Time: O(1)
 *   • Built-in function is constant time
 *   • Uses CPU instruction (POPCNT on x86)
 *   • Or lookup table
 * 
 * Space: O(1)
 *   • No extra data structures
 * 
 * PROS:
 * ────────────────────────────────────────────────────────
 *   ✓ Very readable
 *   ✓ Clear intent
 *   ✓ Fast (if CPU supports POPCNT)
 *   ✓ Short code
 * 
 * CONS:
 * ────────────────────────────────────────────────────────
 *   ✗ Compiler-specific (GCC/Clang)
 *   ✗ Not portable (MSVC uses _popcnt)
 *   ✗ May be slower on old CPUs
 *   ✗ Overkill for this problem
 */
```

**Visual Explanation:**
```
╔═══════════════════════════════════════════════════════╗
║            BIT COUNTING VISUALIZATION                 ║
╚═══════════════════════════════════════════════════════╝

__builtin_popcount() counts '1' bits:

Example 1: n = 8
────────────────────────────────────────────────────────
    Binary: 00001000
    
    Count '1' bits:
    0 0 0 0 1 0 0 0
            ↑
          1 bit
    
    popcount(8) = 1
    1 == 1? YES ✓
    Return: TRUE

════════════════════════════════════════════════════════

Example 2: n = 6
────────────────────────────────────────────────────────
    Binary: 00000110
    
    Count '1' bits:
    0 0 0 0 0 1 1 0
              ↑ ↑
            2 bits
    
    popcount(6) = 2
    2 == 1? NO ✗
    Return: FALSE

════════════════════════════════════════════════════════

Example 3: n = 15
────────────────────────────────────────────────────────
    Binary: 00001111
    
    Count '1' bits:
    0 0 0 0 1 1 1 1
            ↑ ↑ ↑ ↑
            4 bits
    
    popcount(15) = 4
    4 == 1? NO ✗
    Return: FALSE
```

---

### 📊 Approach Comparison

```
╔═══════════════════════════════════════════════════════╗
║          ALL THREE APPROACHES COMPARED                ║
╚═══════════════════════════════════════════════════════╝

┌────────────────┬──────────────┬──────────────┬───────────────┐
│   Approach     │     Time     │    Space     │  Difficulty   │
├────────────────┼──────────────┼──────────────┼───────────────┤
│ Bit Trick      │    O(1)      │     O(1)     │   Medium      │
│ n & (n-1)==0   │   ⚡⚡⚡     │    Minimal   │ (Need to know │
│                │   Fastest    │              │  bit tricks)  │
├────────────────┼──────────────┼──────────────┼───────────────┤
│ Division Loop  │   O(log n)   │     O(1)     │     Easy      │
│ while n%2==0   │     ⚡       │    Minimal   │  (Intuitive)  │
│                │    Slower    │              │               │
├────────────────┼──────────────┼──────────────┼───────────────┤
│ Bit Counting   │    O(1)      │     O(1)     │     Easy      │
│ popcount==1    │    ⚡⚡      │    Minimal   │  (Readable)   │
│                │    Fast      │              │               │
└────────────────┴──────────────┴──────────────┴───────────────┘

WHEN TO USE WHICH?
────────────────────────────────────────────────────────

Bit Manipulation (n & (n-1) == 0):
    ✓ Best for interviews (shows bit manipulation skill)
    ✓ Fastest performance
    ✓ Most elegant solution
    ✗ Need to understand why it works

Division Loop:
    ✓ Easy to understand
    ✓ Good for beginners
    ✓ No special knowledge needed
    ✗ Slower than bit tricks

Bit Counting (__builtin_popcount):
    ✓ Very readable
    ✓ Clear intent
    ✗ Compiler-specific
    ✗ Overkill for this problem

════════════════════════════════════════════════════════

PERFORMANCE COMPARISON (n = 1024):
────────────────────────────────────────────────────────

Bit Trick:       4 operations  ⚡⚡⚡
Bit Counting:    ~10 operations ⚡⚡
Division Loop:   10 iterations  ⚡

RECOMMENDATION:
────────────────────────────────────────────────────────

┌─────────────────────────────────────────────────────┐
│ FOR INTERVIEWS: Use n & (n-1) == 0                  │
│   • Shows advanced knowledge                        │
│   • Optimal complexity                              │
│   • Demonstrates bit manipulation skills            │
│                                                     │
│ FOR PRODUCTION: Also use n & (n-1) == 0             │
│   • Fastest                                         │
│   • No dependencies                                 │
│   • Portable across compilers                       │
│                                                     │
│ FOR LEARNING: Start with Division Loop              │
│   • Easier to understand                            │
│   • Build intuition first                           │
│   • Then learn bit tricks                           │
└─────────────────────────────────────────────────────┘
```

---

## 💼 Interview Questions & Answers - Power of Two

### ❓ Question 1: Why does n & (n-1) work?

```
╔═══════════════════════════════════════════════════════╗
║              INTERVIEW ANSWER 1                       ║
╚═══════════════════════════════════════════════════════╝

ANSWER:
────────────────────────────────────────────────────────

The trick n & (n-1) works because of how powers of 2
are represented in binary.

KEY INSIGHT:
    Powers of 2 have EXACTLY ONE bit set to '1'
    
    Examples:
        1  = 0001
        2  = 0010
        4  = 0100
        8  = 1000
        16 = 10000

WHAT HAPPENS WHEN WE SUBTRACT 1?
────────────────────────────────────────────────────────

When we subtract 1 from a power of 2:
    1. The single '1' bit becomes '0'
    2. All bits to the right become '1'

Example: n = 8
    
    n     = 8 = 1000
    n - 1 = 7 = 0111
    
    Notice:
        • The '1' at position 3 became '0'
        • All bits to the right (positions 0,1,2) became '1'

WHY DOES AND GIVE ZERO?
────────────────────────────────────────────────────────

When we AND these two numbers:
    
    n     = 1000
    n - 1 = 0111
    ──────  ────
    AND   = 0000

There's NO OVERLAP! No position has '1' in both numbers.

VISUAL PROOF:
────────────────────────────────────────────────────────

    Position: 3 2 1 0
             ┌─┬─┬─┬─┐
    n        │1│0│0│0│
             ├─┼─┼─┼─┤
    n-1      │0│1│1│1│
             ├─┼─┼─┼─┤
    AND      │0│0│0│0│ = 0 ✓
             └─┴─┴─┴─┘
             ↑ ↑ ↑ ↑
             No matching '1' bits!

WHAT ABOUT NON-POWERS OF 2?
────────────────────────────────────────────────────────

For non-powers, there are MULTIPLE '1' bits.
Subtracting 1 only affects the rightmost '1' bit.
Other '1' bits remain, so AND is NOT zero.

Example: n = 6
    
    n= 6 = 0110
    n - 1 = 5 = 0101
    ──────────  ────
    AND       = 0100 = 4 ≠ 0 ✗
    
    Position: 3 2 1 0
             ┌─┬─┬─┬─┐
    n        │0│1│1│0│
             ├─┼─┼─┼─┤
    n-1      │0│1│0│1│
             ├─┼─┼─┼─┤
    AND      │0│1│0│0│ = 4 ≠ 0 ✗
             └─┴─┴─┴─┘
                 ↑
            Still has '1' bit!

SUMMARY FOR INTERVIEWER:
────────────────────────────────────────────────────────

┌─────────────────────────────────────────────────────┐
│ The trick works because:                            │
│                                                     │
│ 1. Powers of 2 have exactly ONE '1' bit             │
│ 2. Subtracting 1 flips that bit and all to right    │
│ 3. Original and (n-1) have NO overlapping bits      │
│ 4. AND operation gives 0                            │
│                                                     │
│ For non-powers:                                     │
│ 1. Multiple '1' bits exist                          │
│ 2. Subtracting 1 only affects rightmost '1'         │
│ 3. Other '1' bits remain in both numbers            │
│ 4. AND operation gives non-zero result              │
└─────────────────────────────────────────────────────┘
```

---

### ❓ Question 2: What about n = 0?

```
╔═══════════════════════════════════════════════════════╗
║              INTERVIEW ANSWER 2                       ║
╚═══════════════════════════════════════════════════════╝

ANSWER:
────────────────────────────────────────────────────────

Zero is NOT a power of 2, and that's why we need the
n > 0 check.

MATHEMATICAL REASONING:
────────────────────────────────────────────────────────

Question: Is there an exponent x where 2^x = 0?

    Let's check:
        2^0 = 1
        2^-1 = 0.5
        2^-2 = 0.25
        ...
        2^-∞ → approaches 0, but never equals 0
    
    Answer: NO! No such exponent exists.

BINARY REPRESENTATION:
────────────────────────────────────────────────────────

    0 = 00000000 (all bits are 0)
    
    Powers of 2 must have at least ONE bit set.
    Zero has NO bits set!

WITHOUT THE n > 0 CHECK:
────────────────────────────────────────────────────────

If we only used n & (n-1) == 0:
    
    0 & (0 - 1) = 0 & -1
    
    In binary (2's complement):
        0  = 00000000
       -1  = 11111111
       ───   ────────
       AND = 00000000 = 0
    
    This would incorrectly return TRUE! ✗

WITH THE n > 0 CHECK:
────────────────────────────────────────────────────────

    Step 1: Is 0 > 0? NO ✗
    Return FALSE immediately ✓
    
    We catch the error before the bit trick!

VISUAL EXPLANATION:
────────────────────────────────────────────────────────

    ┌──────────────────────────────────────┐
    │ Input: n = 0                         │
    └────────────┬─────────────────────────┘
                 │
                 ▼
         ┌───────────────┐
         │  Is n > 0?    │
         │  Is 0 > 0?    │
         │     NO ✗      │
         └───────┬───────┘
                 │
                 ▼
         ┌───────────────┐
         │ Return FALSE  │
         │ (Correct!)    │
         └───────────────┘

SIMPLE EXPLANATION:
────────────────────────────────────────────────────────

Think of it this way:
    "No matter how many times you divide 2 by itself,
     or how many times you multiply 2 by itself,
     you'll NEVER get zero!"

Therefore, 0 cannot be a power of 2.
```

---

### ❓ Question 3: Can negative numbers be powers of two?

```
╔═══════════════════════════════════════════════════════╗
║              INTERVIEW ANSWER 3                       ║
╚═══════════════════════════════════════════════════════╝

ANSWER:
────────────────────────────────────────────────────────

In this problem's context, NO. Negative numbers are
NOT considered powers of two.

PROBLEM DEFINITION:
────────────────────────────────────────────────────────

The problem asks: "Is n a power of two?"

    Meaning: Does there exist an integer x where n = 2^x?
    
    For positive x:
        2^0 = 1
        2^1 = 2
        2^2 = 4
        All positive! ✓
    
    For negative x:
        2^-1 = 0.5 (not an integer)
        2^-2 = 0.25 (not an integer)
        These give FRACTIONS, not integers!

WHAT ABOUT -16?
────────────────────────────────────────────────────────

    -16 is NOT 2^x for any integer x
    
    Even though 16 = 2^4, the negative sign means:
        -16 = -1 × 2^4
    
    This is NOT the same as 2^x!

BINARY REPRESENTATION (2's Complement):
────────────────────────────────────────────────────────

    Negative numbers in binary (2's complement):
        -1  = 11111111
        -2  = 11111110
        -4  = 11111100
        -8  = 11111000
        -16 = 11110000
    
    These have MULTIPLE '1' bits!
    Not the single-bit pattern of powers of 2.

WHY WE CHECK n > 0:
────────────────────────────────────────────────────────

    The n > 0 check eliminates:
        ✗ All negative numbers
        ✗ Zero
    
    Only considers:
        ✓ Positive integers (1, 2, 4, 8, 16, ...)

EXAMPLE:
────────────────────────────────────────────────────────

    ┌──────────────────────────────────────┐
    │ Input: n = -16                       │
    └────────────┬─────────────────────────┘
                 │
                 ▼
         ┌───────────────┐
         │  Is n > 0?    │
         │  Is -16 > 0?  │
         │     NO ✗      │
         └───────┬───────┘
                 │
                 ▼
         ┌───────────────┐
         │ Return FALSE  │
         │ (Correct!)    │
         └───────────────┘

INTERVIEWER FOLLOW-UP:
────────────────────────────────────────────────────────

Q: "What if the problem asked about 2^-x?"

A: "That's a different problem! If we wanted to check
    for fractional powers (0.5, 0.25, etc.), we'd need
    a different approach. But in the standard problem,
    we only consider positive integer powers: 2^0, 2^1,
    2^2, etc., which are all positive integers."
```

---

### ❓ Question 4: Why is bit manipulation faster than division?

```
╔═══════════════════════════════════════════════════════╗
║              INTERVIEW ANSWER 4                       ║
╚═══════════════════════════════════════════════════════╝

ANSWER:
────────────────────────────────────────────────────────

Bit manipulation is faster because it operates directly
on the binary representation using simple CPU operations.

CPU OPERATION COSTS:
────────────────────────────────────────────────────────

Modern CPU cycle counts (approximate):

    ┌─────────────────┬──────────────┬────────────┐
    │   Operation     │    Cycles    │   Speed    │
    ├─────────────────┼──────────────┼────────────┤
    │ Bitwise AND (&) │     1        │  ⚡⚡⚡    │
    │ Subtraction (-) │     1        │  ⚡⚡⚡    │
    │ Comparison (>)  │     1        │  ⚡⚡⚡    │
    ├─────────────────┼──────────────┼────────────┤
    │ Modulo (%)      │   10-20      │  ⚡        │
    │ Division (/)    │   10-40      │  🐌        │
    └─────────────────┴──────────────┴────────────┘

WHY DIVISION IS SLOW:
────────────────────────────────────────────────────────

Division is complex:
    1. CPU must perform iterative algorithm
    2. Multiple steps required
    3. Can't be done in single cycle
    4. Much slower than basic operations

Example: Calculating 16 / 2
    
    Division method:
        • 10-40 CPU cycles
        • Complex algorithm
        • Slow
    
    Bit shift method (>> 1):
        • 1 CPU cycle
        • Direct bit operation
        • Fast!

OPERATION COMPARISON:
────────────────────────────────────────────────────────

Bit Manipulation (n & (n-1) == 0):
    ┌──────────────────────────────┐
    │ Step 1: n - 1    → 1 cycle   │
    │ Step 2: n & ...  → 1 cycle   │
    │ Step 3: == 0     → 1 cycle   │
    │ Step 4: n > 0    → 1 cycle   │
    │ ────────────────────────────│
    │ Total: ~4 cycles             │
    └──────────────────────────────┘

Division Loop (n = 1024):
    ┌──────────────────────────────┐
    │ Iteration 1: n % 2 → 10 cycles│
    │ Iteration 1: n / 2 → 20 cycles│
    │ Iteration 2: n % 2 → 10 cycles│
    │ Iteration 2: n / 2 → 20 cycles│
    │ ... (10 iterations)          │
    │ ────────────────────────────│
    │ Total: ~300 cycles           │
    └──────────────────────────────┘

SPEED DIFFERENCE:
────────────────────────────────────────────────────────

For n = 1024:
    Bit manipulation: 4 cycles     ⚡⚡⚡
    Division loop:    300 cycles   🐌
    
    Speed improvement: 75x faster!

REAL-WORLD ANALOGY:
────────────────────────────────────────────────────────

┌─────────────────────────────────────────────────────┐
│ Bit Manipulation = Calculator                       │
│   • Press one button                                │
│   • Instant result                                  │
│                                                     │
│ Division = Long Division by Hand                    │
│   • Multiple steps                                  │
│   • Write things down                               │
│   • Takes much longer                               │
└─────────────────────────────────────────────────────┘

WHY IT MATTERS:
────────────────────────────────────────────────────────

In performance-critical code:
    • Called millions of times
    • 75x speed difference adds up!
    • Can mean seconds vs milliseconds
    
Example: Checking 1 million numbers
    Bit manipulation: 0.004 seconds
    Division loop:    0.3 seconds
```

---

### ❓ Question 5: How do I remember this trick?

```
╔═══════════════════════════════════════════════════════╗
║              INTERVIEW ANSWER 5                       ║
╚═══════════════════════════════════════════════════════╝

ANSWER:
────────────────────────────────────────────────────────

Here are several ways to remember the n & (n-1) trick:

METHOD 1: THE "ONE LIGHT" ANALOGY
────────────────────────────────────────────────────────

Think of binary digits as light switches:

    Powers of 2 = Exactly ONE light is ON
    
    Turning off that light (subtract 1):
        • The ON light turns OFF
        • All lights to the right turn ON
    
    Compare original with lights-flipped:
        • No lights match!
        • AND gives all OFF (zero)

Visual:
    Original:  ●○○○ (light at position 3 is ON)
    Minus 1:   ○●●● (lights at 0,1,2 are ON)
    No overlap! → AND = ○○○○

METHOD 2: THE PATTERN
────────────────────────────────────────────────────────

Remember the pattern:
    "Single bit + Subtract 1 = Flipped bits"
    
    1000 - 1 = 0111
    0100 - 1 = 0011
    0010 - 1 = 0001
    0001 - 1 = 0000
    
    Notice: The '1' moves right, filling with '1's

METHOD 3: THE MNEMONIC
────────────────────────────────────────────────────────

"Powers of Two have One bit, ANDing kills it"

    P - Powers of Two
    O - One bit set
    A - AND operation
    K - Kills the bit (gives zero)

METHOD 4: THE VISUAL SHAPE
────────────────────────────────────────────────────────

Remember the visual pattern:

    n:     1000
    n-1:   0111
           ────
    AND:   0000  ← Makes a "zero sandwich"
    
    The '1' and its complement create zero!

METHOD 5: PRACTICE EXAMPLES
────────────────────────────────────────────────────────

Memorize these key examples:

    8  & 7  = 1000 & 0111 = 0 ✓
    16 & 15 = 10000 & 01111 = 0 ✓
    
    6 & 5 = 0110 & 0101 = 0100 ≠ 0 ✗
    7 & 6 = 0111 & 0110 = 0110 ≠ 0 ✗

QUICK RECALL TRICK:
────────────────────────────────────────────────────────

When you see "Power of Two" in a problem, immediately think:

    ┌─────────────────────────────┐
    │ "n & (n - 1) == 0"          │
    │                             │
    │ One bit set?                │
    │ Subtracting 1 flips all     │
    │ AND gives zero              │
    └─────────────────────────────┘

PRACTICE EXERCISE:
────────────────────────────────────────────────────────

Try these in your head:
    • Is 32 a power of 2?  → 32 & 31 = ? → 0 ✓
    • Is 64 a power of 2?  → 64 & 63 = ? → 0 ✓
    • Is 63 a power of 2?  → 63 & 62 = ? → ≠ 0 ✗

The more you practice, the more natural it becomes!
```

---

## 🎯 Quick Reference

### 🔑 Essential Patterns

**Two Sum - Brute Force:**
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}
```

**Two Sum - Hash Map (Optimized):**
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {};
}
```

**Power of Two:**
```cpp
bool isPowerOfTwo(int n) {
    return (n > 0 && (n & (n - 1)) == 0);
}
```

### 🧠 Mental Models

```
┌─────────────────────────────────────────────────────┐
│             PROBLEM SOLVING APPROACH                │
├─────────────────────────────────────────────────────┤
│                                                     │
│ TWO SUM:                                            │
│   Concept: Pair finding in arrays                  │
│   Strategy: Trade space for speed                  │
│   Tool: Hash Map for O(1) lookups                  │
│                                                     │
│ POWER OF TWO:                                       │
│   Concept: Binary pattern recognition              │
│   Strategy: Use bit manipulation                   │
│   Tool: n & (n-1) trick                            │
│                                                     │
└─────────────────────────────────────────────────────┘
```

---

## 🏆 Mastery Checklist

### Two Sum
- [x] ✅ Understand brute force approach O(n²)
- [x] ✅ Master hash map optimization O(n)
- [x] ✅ Handle edge cases (zeros, negatives, duplicates)
- [x] ✅ Explain space-time trade-offs
- [x] ✅ Code both approaches fluently

### Power of Two
- [x] ✅ Understand binary representation of powers of 2
- [x] ✅ Master n & (n-1) bit trick
- [x] ✅ Handle edge cases (zero, negative, one)
- [x] ✅ Explain why the trick works mathematically
- [x] ✅ Compare with alternative approaches

---

## 💡 Pro Tips

```
┌─────────────────────────────────────────────────────┐
│                   PRO TIPS                          │
├─────────────────────────────────────────────────────┤
│                                                     │
│ 1. 🎯 TWO SUM OPTIMIZATION                          │
│    Always consider hash map for pair-finding        │
│    O(n²) → O(n) is a HUGE improvement!             │
│                                                     │
│ 2. 🔢 BIT MANIPULATION                              │
│    Powers of 2 appear everywhere in CS              │
│    Master this pattern - it's fundamental           │
│                                                     │
│ 3. 🧪 TEST EDGE CASES                               │
│    Always check: zero, negative, min/max values     │
│    Edge cases reveal deep understanding             │
│                                                     │
│ 4. 📚 LEARN PATTERNS                                │
│    These are foundational - many problems build     │
│    on these concepts                                │
│                                                     │
│ 5. 🎓 UNDERSTAND TRADE-OFFS                         │
│    Know when to use brute force vs optimization     │
│    Time vs space is a common interview topic        │
│                                                     │
│ 6. 💼 EXPLAIN YOUR PROCESS                          │
│    Be ready to explain YOUR thought process,        │
│    not just the solution                            │
│                                                     │
│ 7. ⚡ PRACTICE                                       │
│    Solve variations to cement understanding         │
│    Repetition builds intuition                      │
│                                                     │
└─────────────────────────────────────────────────────┘
```

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
| 🔍 Two Sum II | Easy | Two pointers technique |
| 🎲 Power of Four | Easy | Bit manipulation + pattern |

---

## 📝 Summary

### What We Learned

```
╔═══════════════════════════════════════════════════════╗
║                COMPREHENSIVE SUMMARY                  ║
╚═══════════════════════════════════════════════════════╝

TWO SUM PROBLEM:
────────────────────────────────────────────────────────
✅ Brute force checks all pairs in O(n²)
✅ Hash map optimization reduces time to O(n)
✅ Trade-off: Use more space O(n) for faster time
✅ Key insight: Store complements as you go
✅ Essential pattern for pair-finding problems

Complexity:
    Brute Force: Time O(n²), Space O(1)
    Hash Map:    Time O(n),  Space O(n)

════════════════════════════════════════════════════════

POWER OF TWO PROBLEM:
────────────────────────────────────────────────────────
✅ Powers of 2 have exactly one bit set in binary
✅ The trick n & (n-1) == 0 works perfectly
✅ Always check n > 0 to handle edge cases
✅ Bit manipulation is O(1) and elegant
✅ Fundamental pattern in computer science

Complexity:
    Bit Manipulation: Time O(1), Space O(1)
    Division Loop:    Time O(log n), Space O(1)
    Bit Counting:     Time O(1), Space O(1)
```

### Key Takeaways

```
┌─────────────────────────────────────────────────────┐
│                 CORE CONCEPTS MASTERED              │
├─────────────────────────────────────────────────────┤
│                                                     │
│ HASH MAPS:                                          │
│   • Speed up searches from O(n) to O(1)             │
│   • Essential for pair-finding problems             │
│   • Example: Two Sum O(n²) → O(n)                  │
│                                                     │
│ BIT OPERATIONS:                                     │
│   • Enable elegant O(1) solutions                   │
│   • Faster than arithmetic operations               │
│   • Example: Power of Two bit trick                 │
│                                                     │
│ TRADE-OFFS:                                         │
│   • Time vs Space complexity                        │
│   • Choose wisely based on constraints              │
│   • Optimization isn't always necessary             │
│                                                     │
└─────────────────────────────────────────────────────┘
```

---

## 🎓 Interview Tips

### When Asked Two Sum:
```
1. START WITH BRUTE FORCE
   "The naive approach is to check all pairs..."
   Shows you understand the problem

2. IDENTIFY THE BOTTLENECK
   "The nested loops make this O(n²), which is slow..."
   Shows analytical thinking

3. PROPOSE HASH MAP
   "We can optimize using a hash map for O(1) lookups..."
   Shows optimization skills

4. DISCUSS TRADE-OFFS
   "This uses O(n) extra space, but improves time to O(n)..."
   Shows understanding of complexity

5. HANDLE EDGE CASES
   "We need to consider zeros, negatives, duplicates..."
   Shows thoroughness
```

### When Asked Power of Two:
```
1. RECOGNIZE THE PATTERN
   "Powers of 2 have exactly one bit set in binary..."
   Shows pattern recognition

2. EXPLAIN THE BIT TRICK
   "The n & (n-1) trick works because..."
   Shows deep understanding

3. HANDLE EDGE CASES
   "We must check n > 0 to handle zero and negatives..."
   Shows attention to detail

4. COMPARE APPROACHES
   "There's also a division loop approach, but..."
   Shows breadth of knowledge

5. DISCUSS APPLICATIONS
   "This pattern is used in memory allocation, tree structures..."
   Shows practical knowledge
```

---

## ✨ Final Thoughts

```
╔═══════════════════════════════════════════════════════╗
║              CONGRATULATIONS! 🎉                      ║
╚═══════════════════════════════════════════════════════╝

You now have a complete understanding of:

    ✓ Array pair finding with hash maps
    ✓ Bit manipulation for pattern recognition
    ✓ Time-space complexity trade-offs
    ✓ Interview-ready problem-solving approaches

These are FUNDAMENTAL building blocks in:
    • Technical interviews
    • Algorithm design
    • System optimization
    • Software development

┌─────────────────────────────────────────────────────┐
│              NEXT STEPS FOR MASTERY                 │
├─────────────────────────────────────────────────────┤
│                                                     │
│ 1. CODE WITHOUT LOOKING                             │
│    Practice until solutions feel natural            │
│                                                     │
│ 2. SOLVE VARIATIONS                                 │
│    Try Three Sum, Four Sum, Power of Three          │
│                                                     │
│ 3. TIME YOURSELF                                    │
│    Practice under interview conditions              │
│                                                     │
│ 4. TEACH SOMEONE                                    │
│    Explain out loud - best way to solidify          │
│                                                     │
│ 5. REVIEW EDGE CASES                                │
│    Make a personal checklist                        │
│                                                     │
│ 6. STUDY PATTERNS                                   │
│    Recognize when to use these techniques           │
│                                                     │
└─────────────────────────────────────────────────────┘

═══════════════════════════════════════════════════════
       Day 11 Complete! Ready for Day 12! 🚀
═══════════════════════════════════════════════════════
```

---

**🎉 Congratulations! You now have a complete understanding of array pair finding and bit manipulation. These are fundamental building blocks for more complex algorithms. Keep practicing and happy coding! 🚀**
