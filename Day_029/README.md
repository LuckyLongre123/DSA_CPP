# Day 29: Array Manipulation - Two-Pointer Techniques

## 📋 Problems Solved

### 1. LeetCode 2460: Apply Operations to an Array
**Difficulty:** Easy  
**Category:** Array Manipulation  
**Status:** ✅ Solved

### 2. LeetCode 27: Remove Element
**Difficulty:** Easy  
**Category:** Two Pointers  
**Status:** ✅ Solved

### 3. LeetCode 283: Move Zeroes
**Difficulty:** Easy  
**Category:** Two Pointers  
**Status:** ✅ Solved

### 4. LeetCode 88: Merge Sorted Array
**Difficulty:** Easy  
**Category:** Array Merging  
**Status:** ✅ Solved

---

## 🎯 Problem Descriptions

### Apply Operations to an Array (LeetCode 2460)
Apply merge operations on adjacent equal elements, then move all zeros to end.

**Example:**
```
Input: nums = [1,2,2,1,1,0]
Step 1: [1,4,0,1,1,0] (merge 2,2 → 4,0)
Step 2: [1,4,0,2,0,0] (merge 1,1 → 2,0)
Step 3: [1,4,2,0,0,0] (move zeros to end)
Output: [1,4,2,0,0,0]
```

### Remove Element (LeetCode 27)
Remove all occurrences of a given value in-place, return count of remaining elements.

**Example:**
```
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
```

### Move Zeroes (LeetCode 283)
Move all zeros to end while maintaining relative order of non-zero elements.

**Example:**
```
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
```

### Merge Sorted Array (LeetCode 88)
Merge two sorted arrays into first array which has extra space.

**Example:**
```
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
```

---

## 🔍 Algorithm Approaches

### 1. Two-Phase Processing (LeetCode 2460)
```
Phase 1: Apply Operations
- Scan left to right
- If nums[i] == nums[i+1]: nums[i] *= 2, nums[i+1] = 0

Phase 2: Move Zeros
- Use two-pointer technique
- Move non-zeros to front, zeros naturally go to back
```

### 2. Two-Pointer Filtering (LeetCode 27, 283)
```
Algorithm:
1. Initialize writeIndex = 0
2. For each element in array:
   - If element meets criteria (!=val or !=0):
     - Place at writeIndex position
     - Increment writeIndex
3. Return writeIndex (for count) or continue (for rearrangement)
```

### 3. Three-Pointer Merging (LeetCode 88)
```
Algorithm:
1. Create temporary copy of nums1
2. Use three pointers: i (temp), j (nums2), k (result)
3. Compare temp[i] vs nums2[j], place smaller at nums1[k]
4. Handle remaining elements from both arrays
```

---

## 📊 Complexity Analysis

| Problem | Time | Space | Technique |
|---------|------|-------|-----------|
| **LeetCode 2460** | O(n) | O(1) | Two-Phase Processing |
| **LeetCode 27** | O(n) | O(1) | Two-Pointer Filtering |
| **LeetCode 283** | O(n) | O(1) | Two-Pointer Rearrangement |
| **LeetCode 88** | O(m+n) | O(m) | Three-Pointer Merge |

---

## 🔄 Alternative Approaches

### For Move Zeroes (LeetCode 283):
1. **Count and Fill:** Count zeros, shift non-zeros, fill zeros
2. **Bubble Sort Style:** Repeatedly bubble zeros to end
3. **Stable Partitioning:** Use stable partition algorithm

### For Merge Arrays (LeetCode 88):
1. **Reverse Merge:** Start from end to avoid overwriting
2. **Direct Merge:** Use extra space for cleaner logic
3. **In-place Rotation:** Complex but O(1) space solution

---

## 🎯 Key Insights

### Two-Pointer Pattern Recognition:
1. **Filtering Pattern:** Remove/keep elements based on condition
2. **Partitioning Pattern:** Separate elements into two groups
3. **Merging Pattern:** Combine two sorted sequences

### Common Two-Pointer Variations:
- **Same Direction:** Both pointers move left to right
- **Opposite Direction:** Pointers move toward each other
- **Fast-Slow:** Different speeds for cycle detection

---

## 🧪 Edge Cases

### Array Manipulation:
- **Empty arrays:** `[]` → Handle gracefully
- **Single element:** `[x]` → Usually no change needed
- **All same elements:** `[3,3,3,3]` → Test filtering logic
- **No target elements:** Array without val/zeros

### Merging:
- **One empty array:** Only copy from non-empty
- **All elements from one array smaller:** Sequential copying
- **Duplicate elements:** Maintain stability

---

## 📈 Learning Objectives

- [x] Master two-pointer technique variations
- [x] Understand in-place array manipulation
- [x] Implement efficient filtering algorithms
- [x] Handle array merging with different approaches
- [x] Optimize space complexity in array problems

---

## 🎉 Progress Summary

**Day 29 Achievements:**
- ✅ Solved 4 LeetCode problems
- ✅ Mastered two-pointer techniques
- ✅ Implemented various array manipulation patterns
- ✅ Analyzed multiple algorithmic approaches

**Total Problems Solved:** 23/∞

---

*Two pointers, infinite possibilities! 🚀*
