# Day 18: Binary Search - Search in Rotated Sorted Array

## Problem 1: Search in Rotated Sorted Array

### Problem Description

There is an integer array `nums` sorted in ascending order (with **distinct** values).

Prior to being passed to your function, `nums` is **possibly rotated** at an unknown pivot index `k` (1 <= k < nums.length) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` **after** the possible rotation and an integer `target`, return *the index of* `target` *if it is in* `nums`*, or* `-1` *if it is not in* `nums`.

You must write an algorithm with `O(log n)` runtime complexity.

### Examples:

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Input: nums = [1], target = 0
Output: -1
```

### Approach

#### Modified Binary Search

- **Time Complexity**: O(log n)
- **Space Complexity**: O(1)
- **Key Insight**: At any point, at least one half of the array is properly sorted
- **Algorithm**:
  1. Use two pointers: `start` and `end`
  2. Calculate `mid` point
  3. If `nums[mid] == target`, return `mid`
  4. Determine which half is sorted:
     - If `nums[start] <= nums[mid]`: left half is sorted
     - Otherwise: right half is sorted
  5. Check if target lies in the sorted half
  6. Adjust search space accordingly

```cpp
int search(vector<int>& nums, int target) {
    int s = 0;
    int e = nums.size() - 1;

    while(s <= e){
        int mid = s + (e - s) / 2;

        if(nums[mid] == target)
            return mid;

        if(nums[s] <= nums[mid]){  // Left half is sorted
            if(nums[s] <= target && target < nums[mid]){
                e = mid - 1;  // Search in left half
            } else {
                s = mid + 1;  // Search in right half
            }
        }
        else{  // Right half is sorted
            if(nums[mid] < target && target <= nums[e]){
                s = mid + 1;  // Search in right half
            } else {
                e = mid - 1;  // Search in left half
            }
        }
    }

    return -1;
}
```

### Key Points

1. **Rotated Array Properties**:
   - Original array was sorted in ascending order
   - Rotation creates two sorted subarrays
   - At any mid point, one half is guaranteed to be sorted

2. **Binary Search Modification**:
   - Standard binary search won't work directly
   - Need to identify which half is sorted first
   - Then check if target lies in the sorted half

3. **Sorted Half Detection**:
   - If `nums[start] <= nums[mid]`: left half is sorted
   - Otherwise: right half is sorted (due to rotation)

### Algorithm Walkthrough

```
Example: nums = [4,5,6,7,0,1,2], target = 0

Initial: s=0, e=6, mid=3
Array: [4,5,6,7,0,1,2]
        s     m     e

Step 1: nums[3]=7, target=0
        nums[0]=4 <= nums[3]=7, so left half [4,5,6,7] is sorted
        target=0 not in range [4,7], so search right half
        s = mid+1 = 4

Step 2: s=4, e=6, mid=5
Array: [4,5,6,7,0,1,2]
              s m e

Step 3: nums[4]=0 > nums[5]=1, so right half [1,2] is sorted
        target=0 not in range [1,2], so search left half
        e = mid-1 = 4

Step 4: s=4, e=4, mid=4
Array: [4,5,6,7,0,1,2]
              s/m/e

Step 5: nums[4]=0 == target=0, return 4
```

### Visual Representation

```
Rotated Array Analysis:

Original: [0,1,2,4,5,6,7]
Rotated:  [4,5,6,7,0,1,2]
           ↑       ↑
        sorted   sorted
         part     part

At any mid point:
Case 1: Mid in left sorted part
[4,5,6,7,0,1,2]
 ←sorted→

Case 2: Mid in right sorted part  
[4,5,6,7,0,1,2]
         ←sorted→
```

### Edge Cases

1. **No Rotation**: Array is normally sorted `[1,2,3,4,5]`
2. **Single Element**: `nums = [1]`
3. **Two Elements**: `nums = [1,3]` or `[3,1]`
4. **Target at Boundaries**: First or last element
5. **Target Not Present**: Return -1

### Comparison with Standard Binary Search

| Aspect | Standard Binary Search | Rotated Array Search |
|--------|------------------------|---------------------|
| Array Property | Fully sorted | Two sorted parts |
| Mid Comparison | Direct with target | Check which half is sorted first |
| Search Direction | Based on target vs mid | Based on sorted half analysis |
| Complexity | O(log n) | O(log n) |

### Alternative Approaches

1. **Find Pivot + Binary Search**: O(log n) + O(log n) = O(log n)
2. **Linear Search**: O(n) - not optimal
3. **Recursive Approach**: Same logic, different implementation

### Common Pitfalls

1. **Boundary Conditions**: Handle `nums[start] <= nums[mid]` correctly
2. **Equal Elements**: Problem states distinct values, simplifies logic
3. **Integer Overflow**: Use `s + (e - s) / 2` instead of `(s + e) / 2`

### Constraints

- 1 ≤ nums.length ≤ 5000
- -10⁴ ≤ nums[i] ≤ 10⁴
- All values of `nums` are **unique**
- `nums` is an ascending array that is possibly rotated
- -10⁴ ≤ target ≤ 10⁴

### Source

[LeetCode 33 - Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Search in Rotated Sorted Array | Medium | ✅ Solved | Modified Binary Search | O(log n) | O(1) |

## 🎯 Key Learnings

1. **Binary Search Variations**: Adapting binary search for non-standard sorted arrays
2. **Sorted Subarray Detection**: Identifying which part maintains sorted property
3. **Conditional Logic**: Complex decision making in binary search
4. **Space Efficiency**: Achieving O(1) space with O(log n) time

## 🚀 Next Steps

- Practice more rotated array problems (find minimum, search with duplicates)
- Study other binary search variations (peak finding, search in 2D matrix)
- Learn about ternary search for unimodal functions
- Explore binary search on answer technique

## 💡 Problem-Solving Tips

1. **Identify Sorted Half**: Always determine which half is properly sorted first
2. **Range Checking**: Verify if target lies within the sorted half's range
3. **Boundary Handling**: Pay attention to <= vs < comparisons
4. **Visualization**: Draw the rotated array to understand the pattern
