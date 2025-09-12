# Day 28: Array Properties - Monotonic Array

## 📋 Problems Solved

### 1. LeetCode 896: Monotonic Array
**Difficulty:** Easy  
**Category:** Array Properties  
**Status:** ✅ Solved

---

## 🎯 Problem Description

### Monotonic Array
An array is **monotonic** if it is either monotone increasing or monotone decreasing:
- **Monotone increasing:** `nums[i] <= nums[i+1]` for all valid i
- **Monotone decreasing:** `nums[i] >= nums[i+1]` for all valid i

**Examples:**
```
Input: nums = [1,2,2,3]
Output: true
Explanation: Monotone increasing

Input: nums = [6,5,4,4] 
Output: true
Explanation: Monotone decreasing

Input: nums = [1,3,2]
Output: false
Explanation: Neither increasing nor decreasing
```

---

## 🔍 Algorithm Approach

### Two-Flag Method
```
1. Initialize two flags: inc = true, dec = true
2. Iterate through array from index 1 to n-1
3. For each adjacent pair (nums[i-1], nums[i]):
   - If nums[i] > nums[i-1]: set dec = false
   - If nums[i] < nums[i-1]: set inc = false
4. Return inc || dec (true if either direction is valid)
```

### Visual Representation
```
Array: [1, 2, 2, 3]
       ↑  ↑  ↑  ↑
       1≤2 2≤2 2≤3  ✓ Monotone Increasing

Array: [6, 5, 4, 4]
       ↑  ↑  ↑  ↑
       6≥5 5≥4 4≥4  ✓ Monotone Decreasing

Array: [1, 3, 2]
       ↑  ↑  ↑
       1<3 3>2      ✗ Neither direction
```

---

## 📊 Complexity Analysis

| Metric | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n) | Single pass through array |
| **Space** | O(1) | Only two boolean flags used |

---

## 🔄 Alternative Approaches

### 1. **Two-Pass Method**
- First pass: Check if array is non-decreasing
- Second pass: Check if array is non-increasing
- **Time:** O(n), **Space:** O(1)

### 2. **Direction Detection**
- Find first non-equal pair to determine direction
- Continue checking in that direction only
- **Time:** O(n), **Space:** O(1)

---

## 🎯 Key Insights

1. **Simultaneous Checking:** Track both directions in single pass
2. **Early Termination:** Could optimize by stopping when both flags become false
3. **Edge Cases:** Single element or empty arrays are always monotonic
4. **Equal Elements:** Equal adjacent elements don't violate monotonicity

---

## 🧪 Edge Cases

- **Single element:** `[5]` → Always monotonic
- **Two elements:** `[1,2]` or `[2,1]` → Always monotonic
- **All equal:** `[3,3,3,3]` → Both increasing and decreasing
- **Empty array:** `[]` → Considered monotonic

---

## 📈 Learning Objectives

- [x] Understanding array monotonicity properties
- [x] Two-flag technique for bidirectional checking
- [x] Efficient single-pass algorithms
- [x] Boolean logic optimization

---

## 🎉 Progress Summary

**Day 28 Achievements:**
- ✅ Solved 1 LeetCode problem
- ✅ Mastered array property analysis
- ✅ Implemented efficient two-flag technique
- ✅ Analyzed time/space complexity

**Total Problems Solved:** 19/∞

---

*Keep practicing array algorithms! 🚀*
