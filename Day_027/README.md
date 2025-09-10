# Day 27: LeetCode 796 - Rotate String

## Problem Overview

**LeetCode Problem 796: Rotate String**

Given two strings `s` and `goal`, return `true` if and only if `s` can become `goal` after some number of shifts on `s`.

A shift on `s` consists of moving the leftmost character of `s` to the rightmost position.

### Examples

**Example 1:**
```
Input: s = "abcde", goal = "cdeab"
Output: true
Explanation: s can become goal after 2 left shifts:
"abcde" -> "bcdea" -> "cdeab"
```

**Example 2:**
```
Input: s = "abcde", goal = "abced"
Output: false
Explanation: No amount of shifts can make s equal to goal
```

**Example 3:**
```
Input: s = "aa", goal = "a"
Output: false
Explanation: Different lengths, impossible to rotate
```

## Algorithm Approach

### Key Insight: String Concatenation Method

The brilliant insight for this problem is that **if `goal` is a rotation of `s`, then `goal` must be a substring of `s + s`**.

#### Why This Works:

When we concatenate `s` with itself, we get all possible rotations of `s` as substrings:

```
s = "abcde"
s + s = "abcdeabcde"

All rotations of s appear as substrings:
- "abcde" (0 rotations) - positions 0-4
- "bcdea" (1 rotation)  - positions 1-5
- "cdeab" (2 rotations) - positions 2-6
- "deabc" (3 rotations) - positions 3-7
- "eabcd" (4 rotations) - positions 4-8
```

### Algorithm Steps:

1. **Length Check**: Verify both strings have the same length
2. **Concatenation**: Create `s + s` to contain all rotations
3. **Substring Search**: Check if `goal` exists in the concatenated string

### Visual Representation:

```
Original: s = "abcde", goal = "cdeab"

Step 1: Check lengths
s.length = 5, goal.length = 5 ✓

Step 2: Create s + s
"abcde" + "abcde" = "abcdeabcde"

Step 3: Find goal in s + s
"abcdeabcde"
     ^^^^^
   "cdeab" found at position 2 ✓

Result: true
```

## Implementation Details

```cpp
bool rotateString(string s, string goal) {
    // Check if lengths are equal (necessary condition)
    if (s.size() != goal.size()) {
        return false;
    }
    
    // Check if goal is substring of s + s
    return (s + s).find(goal) != string::npos;
}
```

## Complexity Analysis

- **Time Complexity**: O(n) where n is the length of the string
  - String concatenation: O(n)
  - Substring search using KMP algorithm: O(n)
  
- **Space Complexity**: O(n) for creating the concatenated string

## Edge Cases

1. **Empty Strings**: Both empty → `true`
2. **Different Lengths**: → `false`
3. **Identical Strings**: → `true`
4. **Single Character**: 
   - Same character: `true`
   - Different characters: `false`
5. **No Valid Rotation**: Characters don't match → `false`

## Alternative Approaches

### Approach 1: Brute Force Rotation
```cpp
bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) return false;
    
    for (int i = 0; i < s.size(); i++) {
        if (s == goal) return true;
        s = s.substr(1) + s[0]; // Rotate left by 1
    }
    return false;
}
```
- **Time**: O(n²), **Space**: O(n)

### Approach 2: Find Rotation Point
```cpp
bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) return false;
    
    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i) + s.substr(0, i) == goal) {
            return true;
        }
    }
    return false;
}
```
- **Time**: O(n²), **Space**: O(n)

## Key Insights

1. **String Rotation Property**: All rotations of a string appear as substrings in the string concatenated with itself
2. **Efficient Search**: Using built-in `find()` function leverages optimized string matching algorithms
3. **Early Termination**: Length check eliminates impossible cases immediately
4. **Mathematical Elegance**: The concatenation approach transforms a rotation problem into a substring search problem

## Learning Objectives

- Understanding string rotation mechanics
- Applying mathematical insights to optimize algorithms
- Using string manipulation techniques effectively
- Recognizing patterns in cyclic data structures

## Related Problems

- LeetCode 459: Repeated Substring Pattern
- LeetCode 686: Repeated String Match
- String rotation problems in arrays

## Progress Summary

**Day 27 Achievements:**
- ✅ Implemented efficient string rotation detection
- ✅ Mastered string concatenation technique
- ✅ Analyzed multiple algorithmic approaches
- ✅ Understood time/space complexity trade-offs

**Total Problems Solved: 19**
**New Concepts Learned:**
- String rotation algorithms
- Substring search optimization
- Cyclic pattern recognition
