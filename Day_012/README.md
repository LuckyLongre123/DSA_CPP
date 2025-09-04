# Day 12: Array and Digit Manipulation Problems

## Problem 1: Find the Smallest Index Where Index Equals Sum of Digits

### Problem Description

Given an array of integers `nums`, find the smallest index `i` such that `i` equals the sum of digits of `nums[i]`. Return the smallest such index, or `-1` if no such index exists.

### Examples:

```
Input: nums = [12, 34, 5, 67]
Output: 2
Explanation: At index 2, nums[2] = 5, sum of digits = 5, and 2 ≠ 5, but we need to check all indices.
Actually, we need index i where i equals sum of digits of nums[i].

Input: nums = [10, 1, 2, 3, 4, 5]
Output: 5
Explanation: At index 5, nums[5] = 5, sum of digits of 5 = 5, so 5 == 5

Input: nums = [99, 77, 33]
Output: -1
Explanation: No index matches the sum of digits condition
```

### Approach

#### Linear Search with Digit Sum Calculation

- **Time Complexity**: O(n × d) where n is array length and d is average number of digits
- **Space Complexity**: O(1)
- **Algorithm**:
  1. Iterate through each index i from 0 to n-1
  2. For each element at index i:
     - Calculate sum of its digits using modulo and division
     - Check if index i equals the digit sum
     - If yes, return i (smallest such index due to left-to-right iteration)
  3. Return -1 if no such index exists

```cpp
int smallestIndex(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++){
        int temp = nums[i];
        int sum = 0;
        
        // Calculate sum of digits
        while(temp != 0){
            sum += temp % 10;  // Add last digit
            temp /= 10;        // Remove last digit
        }
        
        if(i == sum) return i;  // Found matching index
    }
    return -1;  // No match found
}
```

### Key Points

1. **Digit Sum Calculation**:
   - Use `num % 10` to get last digit
   - Use `num / 10` to remove last digit
   - Repeat until num becomes 0

2. **Index Matching**:
   - Check if current index equals calculated digit sum
   - Return immediately when first match is found (smallest index)

3. **Edge Cases**:
   - Empty array (though constraints may prevent this)
   - Single digit numbers (sum equals the number itself)
   - Large numbers with multiple digits

### Digit Sum Examples

```
Number: 123 → Digits: 1, 2, 3 → Sum: 1+2+3 = 6
Number: 45  → Digits: 4, 5    → Sum: 4+5 = 9
Number: 7   → Digits: 7       → Sum: 7
Number: 100 → Digits: 1, 0, 0 → Sum: 1+0+0 = 1
```

### Constraints

- 1 ≤ nums.length ≤ 100
- 0 ≤ nums[i] ≤ 1000

### Source

[LeetCode 3550 - Find the Smallest Index Where Index Equals Sum of Digits](https://leetcode.com/problems/find-the-smallest-index-where-index-equals-sum-of-digits)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Find Smallest Index | Easy | ✅ Solved | Linear Search + Digit Sum | O(n × d) | O(1) |

## 🎯 Key Learnings

1. **Digit Manipulation**: Extracting and summing digits using modulo and division operations
2. **Array Indexing**: Matching array indices with calculated values
3. **Early Return**: Returning immediately when condition is met to find smallest index
4. **Mathematical Operations**: Understanding how to break down numbers into individual digits

## 🚀 Next Steps

- Practice more digit manipulation problems
- Explore problems involving number properties and array indexing
- Learn about more efficient digit sum calculation methods
- Focus on mathematical problem-solving patterns

## 💡 Problem-Solving Tips

1. **Break Down Numbers**: Use `% 10` and `/ 10` to process digits
2. **Index Awareness**: Remember that array indices start from 0
3. **Early Termination**: Return as soon as the first valid condition is met
4. **Edge Case Testing**: Test with single digits, multi-digits, and edge values
