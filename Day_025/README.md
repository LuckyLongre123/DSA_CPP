# Day 25: Prefix Sum - Find Pivot Index

## Problem 1: Find Pivot Index

### Problem Description

Given an array of integers `nums`, calculate the pivot index of this array. The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the right of the index.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

### Examples:

```
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation: The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Input: nums = [1,2,3]
Output: -1
Explanation: There is no index that satisfies the conditions in the problem statement.

Input: nums = [2,1,-1]
Output: 0
Explanation: The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + (-1) = 0
```

### Approach

#### Two-Sum Tracking Technique

- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **Algorithm**:
  1. Initialize `presum = 0` (left sum) and calculate `aftersum` (right sum)
  2. For each position, check if left sum equals right sum
  3. If equal, return current index as pivot
  4. Update sums: add current element to left sum, remove next element from right sum
  5. Continue until end of array or pivot found
  6. Return -1 if no pivot exists

```cpp
int pivotIndex(vector<int>& nums) {
    int aftersum = 0;  // Sum of elements after current index
    int presum = 0;    // Sum of elements before current index
    
    // Calculate initial right sum (all elements except first)
    for(int i = 1; i < nums.size(); i++) aftersum += nums[i];
    
    for(int j = 0; j < nums.size(); j++){
        if(presum == aftersum) return j;  // Found pivot
        
        presum += nums[j];                // Update left sum
        if(j+1 < nums.size()) aftersum -= nums[j+1];  // Update right sum
        else aftersum = 0;                // Handle boundary
    }
    
    return -1;  // No pivot found
}
```

### Key Points

1. **Two-Sum Logic**:
   - **Left Sum (presum)**: Sum of all elements before current index
   - **Right Sum (aftersum)**: Sum of all elements after current index
   - Check equality at each position to find pivot

2. **Dynamic Sum Updates**:
   - Efficiently maintain left and right sums without recalculation
   - Add current element to left sum as we move forward
   - Remove next element from right sum to maintain accuracy

3. **Boundary Handling**:
   - At array edges, one side has sum = 0
   - Handle last element case where right sum becomes 0
   - Return leftmost pivot if multiple exist

### Algorithm Walkthrough

```
Example: nums = [1,7,3,6,5,6]

Initial: presum=0, aftersum=7+3+6+5+6=27
Array: [1,7,3,6,5,6]
        j=0

Step 1: presum=0, aftersum=27 → 0≠27
        presum += nums[0] = 1, aftersum -= nums[1] = 20
        [1,7,3,6,5,6]
          j=1

Step 2: presum=1, aftersum=20 → 1≠20
        presum += nums[1] = 8, aftersum -= nums[2] = 17
        [1,7,3,6,5,6]
            j=2

Step 3: presum=8, aftersum=17 → 8≠17
        presum += nums[2] = 11, aftersum -= nums[3] = 11
        [1,7,3,6,5,6]
              j=3

Step 4: presum=11, aftersum=11 → 11==11 ✓
        Return j=3 (pivot found!)

Final: Pivot index = 3
```

### Visual Representation

```
Original: [1,7,3,6,5,6]
           0 1 2 3 4 5

At index 3:
Left:  [1,7,3] → sum = 11
Right: [5,6]   → sum = 11
Pivot found at index 3!

Verification:
nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
nums[4] + nums[5] = 5 + 6 = 11
11 == 11 ✓
```

### Edge Cases

1. **Empty Array**: `nums = []` → Return -1 (no elements)
2. **Single Element**: `nums = [1]` → Return 0 (left=0, right=0)
3. **No Pivot**: `nums = [1,2,3]` → Return -1
4. **Multiple Pivots**: Return leftmost pivot index
5. **All Zeros**: `nums = [0,0,0]` → Return 0 (all sums equal)

### Alternative Approaches

1. **Total Sum Method**: Calculate total sum first, then use formula `leftSum == (total - nums[i]) / 2`
2. **Brute Force**: For each index, calculate left and right sums separately (O(n²))
3. **Prefix Sum Array**: Pre-calculate prefix sums, then check conditions (O(n) space)

### Constraints

- 1 ≤ nums.length ≤ 10⁴
- -1000 ≤ nums[i] ≤ 1000

### Source

[LeetCode 724 - Find Pivot Index](https://leetcode.com/problems/find-pivot-index)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Find Pivot Index | Easy | ✅ Solved | Two-Sum Tracking | O(n) | O(1) |

## 🎯 Key Learnings

1. **Prefix Sum Technique**: Efficient way to handle range sum queries
2. **Dynamic Sum Updates**: Maintain running sums without recalculation
3. **Two-Pointer-like Logic**: Use two variables to track different parts of array
4. **Boundary Conditions**: Handle edge cases at array boundaries

## 🚀 Next Steps

- Practice more prefix sum problems
- Explore range sum query problems
- Study subarray sum problems
- Learn about cumulative sum techniques

## 💡 Problem-Solving Tips

1. **Use Running Sums**: Maintain left and right sums dynamically
2. **Handle Boundaries**: Check edge cases at array start/end
3. **Early Return**: Return as soon as pivot is found
4. **Mathematical Insight**: At pivot i, leftSum = rightSum = (totalSum - nums[i]) / 2
