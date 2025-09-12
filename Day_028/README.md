# Day 28: Array Properties Mastery

## 🎯 Learning Objectives

By the end of this day, you will master:
- **Monotonic Array Analysis**: Understanding increasing and decreasing sequence properties
- **Two-Flag Technique**: Efficient bidirectional checking in single pass
- **Boolean Logic Optimization**: Using flags for condition tracking
- **Array Property Recognition**: Identifying mathematical patterns in sequences

---

## Problem 1: Monotonic Array (LeetCode 896)

### 📋 Problem Statement

**Difficulty**: Easy  
**Category**: Array, Math  
**Companies**: Facebook, Amazon, Google

An array is **monotonic** if it is either monotone increasing or monotone decreasing.

**Definitions**:
- **Monotone increasing**: `nums[i] <= nums[i+1]` for all valid i
- **Monotone decreasing**: `nums[i] >= nums[i+1]` for all valid i

Return `true` if the given array `nums` is monotonic, otherwise return `false`.

### 💡 Examples

```
Example 1:
Input: nums = [1,2,2,3]
Output: true
Explanation: Monotone increasing (non-decreasing)

Example 2:
Input: nums = [6,5,4,4] 
Output: true
Explanation: Monotone decreasing (non-increasing)

Example 3:
Input: nums = [1,3,2]
Output: false
Explanation: Neither increasing nor decreasing consistently
```

### 🔍 Intuition

**Brute Force Approach**: Check if array is increasing, then check if it's decreasing → O(2n)

**Optimized Approach**: Use **two flags** to track both directions simultaneously → O(n)

**Key Insight**: An array is monotonic if it maintains one consistent direction (or stays equal). We can track both possibilities in a single pass.

### 🚀 Approach: Two-Flag Method

**Algorithm Steps**:
1. Initialize `inc = true` (assume increasing) and `dec = true` (assume decreasing)
2. For each adjacent pair `(nums[i-1], nums[i])`:
   - If `nums[i] > nums[i-1]`: set `dec = false` (not decreasing)
   - If `nums[i] < nums[i-1]`: set `inc = false` (not increasing)
3. Return `inc || dec` (true if either direction is maintained)

- **Time Complexity**: O(n) - Single pass through array
- **Space Complexity**: O(1) - Only two boolean flags

```cpp
bool isMonotonic(vector<int>& nums) {
    bool inc = true, dec = true;
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i-1]) dec = false;
        if (nums[i] < nums[i-1]) inc = false;
    }
    
    return inc || dec;
}
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

### 📈 Constraints

- 1 ≤ nums.length ≤ 10⁵
- -10⁵ ≤ nums[i] ≤ 10⁵

### 🔗 Source

[LeetCode 896 - Monotonic Array](https://leetcode.com/problems/monotonic-array)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Monotonic Array | Easy | ✅ Solved | Two-Flag Method | O(n) | O(1) |

## 🎯 Key Learnings

1. **Two-Flag Technique**: Efficient method for bidirectional property checking
2. **Boolean Logic**: Using flags to track multiple conditions simultaneously
3. **Array Properties**: Understanding monotonic sequences and their characteristics
4. **Single-Pass Optimization**: Avoiding multiple iterations through data

## 🚀 Next Steps

- Practice more array property problems (sorted, rotated, etc.)
- Study sequence analysis and pattern recognition
- Explore mathematical properties of arrays
- Learn about other monotonic data structures

## 💡 Problem-Solving Tips

1. **Property Checking**: Use flags to track multiple conditions in one pass
2. **Equal Elements**: Remember that equal adjacent elements don't break monotonicity
3. **Early Optimization**: Consider early termination when both flags become false
4. **Edge Cases**: Handle single elements and empty arrays appropriately

---

**Total Problems Solved**: 18/∞

*Recognize patterns, optimize with flags! 📈*
