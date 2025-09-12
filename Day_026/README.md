# Day 26: Array Rotation Mastery

## 🎯 Learning Objectives

By the end of this day, you will master:
- **Rotation Detection**: Identifying if an array is a rotated version of a sorted array
- **Break Point Analysis**: Finding discontinuities in array order patterns
- **Circular Array Logic**: Understanding wrap-around properties in rotated arrays
- **Pattern Recognition**: Recognizing mathematical properties of rotated sequences

---

## Problem 1: Check if Array Is Sorted and Rotated (LeetCode 1752)

### 📋 Problem Statement

**Difficulty**: Easy  
**Category**: Array, Sorting  
**Companies**: Amazon, Microsoft, Google

Given an array `nums`, return `true` if the array was originally sorted in **non-decreasing order**, then rotated some number of positions (including zero). Otherwise, return `false`.

**Key Points**:
- Duplicates are allowed in the original array
- Rotation by 0 positions means the array stays the same
- **Rotation Formula**: A[i] == B[(i+x) % A.length] where x is rotation amount

### 💡 Examples

```
Example 1:
Input: nums = [3,4,5,1,2]
Output: true
Explanation: This is [1,2,3,4,5] rotated 3 positions right
Original: [1,2,3,4,5]
Rotated:  [3,4,5,1,2] ✓

Example 2:
Input: nums = [2,1,3,4]
Output: false
Explanation: No sorted array can produce this after rotation

Example 3:
Input: nums = [1,2,3]
Output: true
Explanation: Already sorted (0 rotations) ✓

Example 4:
Input: nums = [1,1,1]
Output: true
Explanation: All elements equal, always valid ✓
```

### 🔍 Intuition

**Key Insight**: A rotated sorted array has a very specific property:
- **At most 1 "break point"** where `nums[i] > nums[i+1]`
- If there's exactly 1 break point, the **first element must be ≥ last element** (wrap-around property)

**Why this works**:
- Sorted array: 0 break points
- Rotated sorted array: exactly 1 break point at rotation boundary
- Invalid array: 2+ break points

### 🚀 Approach: Break Point Analysis

- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **Algorithm**:
  1. Count "break points" where `nums[i] > nums[i+1]`
  2. A valid rotated sorted array can have at most 1 break point
  3. If 0 break points: already sorted (return true)
  4. If 1 break point: check wrap-around condition `nums[0] >= nums[n-1]`
  5. If 2+ break points: invalid (return false)

```cpp
bool check(vector<int>& nums) {
    int bPoint = 0;  // Counter for break points
    int s = nums.size();
    
    // Count break points where order breaks
    for (int i = 0; i < s - 1; i++) {
        if (nums[i] > nums[i + 1])
            bPoint++;
    }
    
    if (bPoint == 0) return true;           // Already sorted
    if (bPoint == 1) return nums[0] >= nums[s - 1];  // Check wrap-around
    return false;                           // Too many breaks
}
```

### Key Points

1. **Break Point Logic**:
   - **Break Point**: Position where `nums[i] > nums[i+1]` (order breaks)
   - **Valid Rotation**: At most one break point can exist
   - **Wrap-around Check**: When break exists, first element ≥ last element

2. **Rotation Properties**:
   - Rotation preserves local ascending order except at rotation point
   - Original sorted array has 0 break points
   - Single rotation creates exactly 1 break point
   - Multiple breaks indicate invalid rotation

3. **Edge Cases**:
   - Already sorted: 0 break points
   - Single element: always valid
   - All equal elements: always valid
   - Reverse sorted: multiple break points (invalid)

### Algorithm Walkthrough

```
Example 1: nums = [3,4,5,1,2]

Step 1: Count break points
i=0: 3 <= 4 ✓ (no break)
i=1: 4 <= 5 ✓ (no break)  
i=2: 5 > 1 ✗ (break point found, bPoint=1)
i=3: 1 <= 2 ✓ (no break)

Step 2: Analyze result
bPoint = 1 (exactly one break point)
Check wrap-around: nums[0]=3 >= nums[4]=2 ✓

Result: true (valid rotated sorted array)

Example 2: nums = [2,1,3,4]

Step 1: Count break points
i=0: 2 > 1 ✗ (break point found, bPoint=1)
i=1: 1 <= 3 ✓ (no break)
i=2: 3 <= 4 ✓ (no break)

Step 2: Analyze result  
bPoint = 1, but nums[0]=2 < nums[3]=4 ✗

Result: false (invalid wrap-around)
```

### Visual Representation

```
Valid Rotation: [3,4,5,1,2]
                     ↑
                Break point (5>1)
                
Check: nums[0]=3 >= nums[4]=2 ✓
Original: [1,2,3,4,5] → Rotated 3 positions → [3,4,5,1,2]

Invalid Array: [2,1,3,4]
                 ↑
            Break point (2>1)
            
Check: nums[0]=2 < nums[3]=4 ✗
Cannot be formed by rotating any sorted array
```

### Edge Cases

1. **Single Element**: `nums = [5]` → true (trivially sorted)
2. **Already Sorted**: `nums = [1,2,3,4]` → true (0 break points)
3. **All Equal**: `nums = [3,3,3]` → true (0 break points)
4. **Two Elements**: `nums = [2,1]` → true (1 break, 2≥1)
5. **Reverse Sorted**: `nums = [4,3,2,1]` → false (multiple breaks)

### Alternative Approaches

1. **Concatenation Method**: Create `nums + nums` and check if original appears as contiguous subarray
2. **Rotation Simulation**: Try all possible rotations and check if any matches sorted version
3. **Two-Pass Method**: Find rotation point, then verify both parts are sorted

### Constraints

- 1 ≤ nums.length ≤ 100
- 1 ≤ nums[i] ≤ 100

### Source

[LeetCode 1752 - Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Check if Array Is Sorted and Rotated | Easy | ✅ Solved | Break Point Counting | O(n) | O(1) |

## 🎯 Key Learnings

1. **Array Rotation Properties**: Understanding how rotation affects sorted arrays
2. **Break Point Analysis**: Identifying where order breaks in rotated arrays
3. **Wrap-around Validation**: Checking circular property for valid rotations
4. **Pattern Recognition**: Recognizing rotation patterns in array problems

## 🚀 Next Steps

- Practice more array rotation problems
- Explore circular array algorithms
- Study rotation detection in different data structures
- Learn about cyclic shift operations

## 💡 Problem-Solving Tips

1. **Count Break Points**: At most one break point in valid rotated sorted array
2. **Check Wrap-around**: First element ≥ last element when break exists
3. **Handle Edge Cases**: Consider already sorted and single element arrays
4. **Think Circularly**: View array as circular for rotation validation

---

**Total Problems Solved**: 16/∞

*Detect the rotation, find the pattern! 🔄*
