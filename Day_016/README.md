# Day 16: Two Pointers - Remove Duplicates from Sorted Array

## Problem 1: Remove Duplicates from Sorted Array

### Problem Description

Given an integer array `nums` sorted in **non-decreasing order**, remove the duplicates **in-place** such that each unique element appears only **once**. The **relative order** of the elements should be kept the **same**. Then return the number of unique elements in `nums`.

Consider the number of unique elements of `nums` to be `k`, to get accepted, you need to do the following things:
- Change the array `nums` such that the first `k` elements of `nums` contain the unique elements in the order they were present in `nums` initially.
- The remaining elements of `nums` are not important as well as the size of `nums`.
- Return `k`.

### Examples:

```
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k.
```

### Approach

#### Two Pointers Technique

- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **Algorithm**:
  1. Use two pointers: `i` (slow pointer) and `j` (fast pointer)
  2. Initialize `i = 0` (points to position for next unique element)
  3. Start `j = 1` and iterate through the array
  4. When `nums[i] != nums[j]`, we found a new unique element:
     - Increment `i` to next position
     - Copy `nums[j]` to `nums[i]`
  5. Continue until `j` reaches end of array
  6. Return `i + 1` (length of unique elements)

```cpp
int removeDuplicates(vector<int>& nums) {
    int i = 0;  // Slow pointer for unique elements position
    
    for(int j = 1; j < nums.size(); j++){  // Fast pointer for traversal
        if(nums[i] != nums[j]){  // Found new unique element
            i++;                 // Move to next position
            nums[i] = nums[j];   // Place unique element
        }
    }
    
    return i + 1;  // Return count of unique elements
}
```

### Key Points

1. **Two Pointers Logic**:
   - **Slow Pointer (i)**: Points to the last position of unique elements
   - **Fast Pointer (j)**: Scans through the array to find unique elements
   - Only move slow pointer when a new unique element is found

2. **In-Place Modification**:
   - No extra space needed for storing unique elements
   - Modify the original array by overwriting duplicates
   - First `k` elements contain all unique values

3. **Sorted Array Advantage**:
   - All duplicates are adjacent
   - Simple comparison `nums[i] != nums[j]` detects unique elements
   - No need to check entire array for duplicates

### Algorithm Walkthrough

```
Example: nums = [0,0,1,1,1,2,2,3,3,4]

Initial: i=0, j=1
Array: [0,0,1,1,1,2,2,3,3,4]
        i j

Step 1: nums[0]=0, nums[1]=0 → Same, j++
        i   j
        [0,0,1,1,1,2,2,3,3,4]

Step 2: nums[0]=0, nums[2]=1 → Different!
        i++, nums[1]=nums[2]=1, j++
        [0,1,1,1,1,2,2,3,3,4]
          i   j

Step 3: nums[1]=1, nums[3]=1 → Same, j++
Step 4: nums[1]=1, nums[4]=1 → Same, j++

Step 5: nums[1]=1, nums[5]=2 → Different!
        i++, nums[2]=nums[5]=2, j++
        [0,1,2,1,1,2,2,3,3,4]
            i       j

Continue this process...

Final: [0,1,2,3,4,_,_,_,_,_]
Return: i+1 = 5
```

### Visual Representation

```
Original: [1,1,2,2,3]
           i j

Step 1: [1,1,2,2,3] → nums[i]==nums[j], j++
         i   j

Step 2: [1,1,2,2,3] → nums[i]!=nums[j], i++, nums[i]=nums[j], j++
         i     j
Result: [1,2,2,2,3]
           i   j

Step 3: [1,2,2,2,3] → nums[i]==nums[j], j++
           i     j

Step 4: [1,2,2,2,3] → nums[i]!=nums[j], i++, nums[i]=nums[j], j++
           i       j
Result: [1,2,3,2,3]
             i

Final: Return i+1 = 3
Array: [1,2,3,_,_] (first 3 elements are unique)
```

### Edge Cases

1. **Empty Array**: `nums = []` → Return 0
2. **Single Element**: `nums = [1]` → Return 1
3. **No Duplicates**: `nums = [1,2,3]` → Return 3
4. **All Duplicates**: `nums = [1,1,1]` → Return 1

### Alternative Approaches

1. **Set/HashSet**: Use extra space to store unique elements (O(n) space)
2. **New Array**: Create new array with unique elements (O(n) space)
3. **Built-in Functions**: Use language-specific functions like `unique()` in C++

### Constraints

- 1 ≤ nums.length ≤ 3 × 10⁴
- -100 ≤ nums[i] ≤ 100
- `nums` is sorted in **non-decreasing** order

### Source

[LeetCode 26 - Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Remove Duplicates from Sorted Array | Easy | ✅ Solved | Two Pointers | O(n) | O(1) |

## 🎯 Key Learnings

1. **Two Pointers Technique**: Efficient pattern for in-place array modifications
2. **Space Optimization**: Achieving O(1) space complexity for array problems
3. **Sorted Array Properties**: Leveraging sorted order to simplify duplicate detection
4. **In-Place Algorithms**: Modifying arrays without additional space requirements

## 🚀 Next Steps

- Practice more two pointers problems
- Explore variations like "Remove Duplicates II" (allow at most 2 duplicates)
- Study other in-place array modification techniques
- Learn about sliding window problems using two pointers

## 💡 Problem-Solving Tips

1. **Use Two Pointers**: One for reading, one for writing unique elements
2. **Leverage Sorted Property**: Adjacent duplicates make detection simple
3. **In-Place Modification**: Overwrite duplicates to save space
4. **Return Count**: Problem asks for count of unique elements, not the array itself
