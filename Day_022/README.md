# Day 22: Dynamic Programming - Maximum Subarray

## Problem 1: Maximum Subarray

### Problem Description

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A **subarray** is a **contiguous** part of an array.

### Examples:

```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Input: nums = [1]
Output: 1

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The entire array has the largest sum.
```

### Approach

#### Kadane's Algorithm

- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **Key Insight**: Reset current sum when it becomes negative
- **Algorithm**:
  1. Initialize current sum to 0 and maximum sum to smallest possible value
  2. For each element, add it to current sum
  3. Update maximum sum if current sum is larger
  4. Reset current sum to 0 if it becomes negative

```cpp
int maxSubArray(vector<int>& nums) {
    int currSum = 0;
    int maxSum = INT_MIN;
    
    for(int val : nums){
        currSum += val;
        maxSum = max(currSum, maxSum);
        if(currSum < 0) currSum = 0;
    }
    
    return maxSum;
}
```

### Key Points

1. **Kadane's Algorithm Logic**:
   - Dynamic programming approach with optimal substructure
   - Track both current subarray sum and global maximum
   - Reset strategy: negative prefix never helps future sums

2. **Why Reset When Negative**:
   - If current sum becomes negative, starting fresh is always better
   - Carrying negative sum can only decrease future totals
   - This ensures we find the optimal subarray

3. **Initialization**:
   - `maxSum = INT_MIN` handles all-negative arrays correctly
   - `currSum = 0` allows fresh start for each potential subarray

### Algorithm Walkthrough

```
Example: nums = [-2,1,-3,4,-1,2,1,-5,4]

Step-by-step execution:
Index: 0  1  2  3  4  5  6  7  8
Value: -2 1 -3  4 -1  2  1 -5  4

i=0: currSum = 0 + (-2) = -2, maxSum = max(-2, INT_MIN) = -2, currSum < 0 → reset to 0
i=1: currSum = 0 + 1 = 1, maxSum = max(1, -2) = 1
i=2: currSum = 1 + (-3) = -2, maxSum = max(-2, 1) = 1, currSum < 0 → reset to 0
i=3: currSum = 0 + 4 = 4, maxSum = max(4, 1) = 4
i=4: currSum = 4 + (-1) = 3, maxSum = max(3, 4) = 4
i=5: currSum = 3 + 2 = 5, maxSum = max(5, 4) = 5
i=6: currSum = 5 + 1 = 6, maxSum = max(6, 5) = 6
i=7: currSum = 6 + (-5) = 1, maxSum = max(1, 6) = 6
i=8: currSum = 1 + 4 = 5, maxSum = max(5, 6) = 6

Result: 6 (subarray [4,-1,2,1])
```

### Visual Representation

```
Array: [-2, 1, -3, 4, -1, 2, 1, -5, 4]

Current Sum Evolution:
-2 → 0 → 1 → 0 → 4 → 3 → 5 → 6 → 1 → 5
 ↓   ↓   ↓   ↓   ↓   ↓   ↓   ↓   ↓   ↓
-2  -2   1   1   4   4   5   6   6   6  (Max Sum)

Optimal Subarray: [4, -1, 2, 1] = 6

Visual Flow:
[-2] → reset
[1] → continue
[1,-3] → reset  
[4] → continue
[4,-1] → continue
[4,-1,2] → continue
[4,-1,2,1] → continue (optimal)
[4,-1,2,1,-5] → continue
[4,-1,2,1,-5,4] → continue
```

### Edge Cases

1. **All Negative Numbers**: Return the least negative number
   - Example: `[-3,-1,-2]` → Output: `-1`
   
2. **Single Element**: Return that element
   - Example: `[5]` → Output: `5`
   
3. **All Positive Numbers**: Return sum of entire array
   - Example: `[1,2,3,4]` → Output: `10`
   
4. **Mixed Signs**: Apply Kadane's algorithm normally
   - Example: `[-1,2,-1,3]` → Output: `4` (subarray `[2,-1,3]`)

### Alternative Approaches

1. **Brute Force**: O(n²) time - check all possible subarrays
2. **Divide & Conquer**: O(n log n) time - split array and merge results
3. **Dynamic Programming Array**: O(n) time, O(n) space - store all subarray sums

### Mathematical Insight

Kadane's algorithm is based on the optimal substructure property:
- `maxSubarray(i) = max(nums[i], maxSubarray(i-1) + nums[i])`
- Either start a new subarray at position i, or extend the previous one
- The space-optimized version only tracks the current decision

### Implementation Variants

```cpp
// Variant 1: Track subarray indices
int maxSubArrayWithIndices(vector<int>& nums, int& start, int& end) {
    int currSum = 0, maxSum = INT_MIN;
    int tempStart = 0;
    start = 0, end = 0;
    
    for(int i = 0; i < nums.size(); i++){
        currSum += nums[i];
        
        if(currSum > maxSum){
            maxSum = currSum;
            start = tempStart;
            end = i;
        }
        
        if(currSum < 0){
            currSum = 0;
            tempStart = i + 1;
        }
    }
    return maxSum;
}

// Variant 2: Pure DP approach
int maxSubArrayDP(vector<int>& nums) {
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int maxSum = dp[0];
    
    for(int i = 1; i < nums.size(); i++){
        dp[i] = max(nums[i], dp[i-1] + nums[i]);
        maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
}
```

### Constraints

- 1 ≤ nums.length ≤ 10⁵
- -10⁴ ≤ nums[i] ≤ 10⁴

### Source

[LeetCode 53 - Maximum Subarray](https://leetcode.com/problems/maximum-subarray)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Maximum Subarray | Medium | ✅ Solved | Kadane's Algorithm | O(n) | O(1) |

## 🎯 Key Learnings

1. **Kadane's Algorithm**: Classic dynamic programming for maximum subarray problems
2. **Reset Strategy**: Understanding when to abandon current subarray and start fresh
3. **Space Optimization**: Reducing DP space from O(n) to O(1)
4. **Edge Case Handling**: Properly managing all-negative arrays and single elements

## 🚀 Next Steps

- Practice more dynamic programming problems (house robber, climbing stairs)
- Study other subarray problems (minimum subarray, maximum product subarray)
- Learn about sliding window techniques
- Explore 2D dynamic programming patterns

## 💡 Problem-Solving Tips

1. **Subarray Problems**: Kadane's algorithm is often the optimal approach
2. **Reset Strategy**: Drop negative prefixes to maximize future sums
3. **Initialization**: Use INT_MIN for maxSum to handle all-negative cases
4. **Track Both**: Maintain current sum and global maximum separately
