# Day 11: Array and Bit Manipulation Problems

## Problem 1: Two Sum

### Problem Description

Given an array of integers `nums` and an integer `target`, return indices of the two numbers in `nums` such that they add up to `target`. You may assume that each input would have exactly one solution, and you may not use the same element twice.

### Examples:

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9

Input: nums = [3,2,4], target = 6
Output: [1,2]

Input: nums = [3,3], target = 6
Output: [0,1]
```

### Approaches

#### 1. Brute Force Approach (Current Implementation)

- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- **Algorithm**:
  1. Use nested loops to check all pairs
  2. For each element at index i:
     - Check all elements from index i+1 to end
     - If sum equals target, return both indices
  3. Return empty array if no solution found

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    int l = nums.size();
    vector<int> myarr;
    
    for (int i = 0; i < l; i++) {
        for (int j = i + 1; j < l; j++) {
            if (nums[i] + nums[j] == target) {
                myarr.push_back(i);
                myarr.push_back(j);
                return myarr;
            }
        }
    }
    return {};
}
```

#### 2. Hash Map Approach (Optimized)

- **Time Complexity**: O(n)
- **Space Complexity**: O(n)
- **Algorithm**:
  1. Use unordered_map to store seen numbers and their indices
  2. For each number, calculate complement (target - current)
  3. If complement exists in map, return indices
  4. Otherwise, store current number and index in map

### Key Points

1. **Index Management**:
   - Problem asks for indices, not values
   - Avoid using same element twice (i+1 in inner loop)
2. **Edge Cases**:
   - Array with exactly 2 elements
   - Duplicate values in array
3. **Optimization Opportunity**:
   - Current O(n²) can be improved to O(n) using hash map

### Constraints

- 2 ≤ nums.length ≤ 10⁴
- -10⁹ ≤ nums[i] ≤ 10⁹
- -10⁹ ≤ target ≤ 10⁹
- Only one valid solution exists

### Source

[LeetCode 1 - Two Sum](https://leetcode.com/problems/two-sum)

---

## Problem 2: Power of Two

### Problem Description

Given an integer `n`, return `true` if it is a power of two. Otherwise, return `false`. An integer `n` is a power of two if there exists an integer `x` such that `n == 2^x`.

### Examples:

```
Input: n = 1
Output: true
Explanation: 2^0 = 1

Input: n = 16
Output: true
Explanation: 2^4 = 16

Input: n = 3
Output: false
```

### Approach

#### Bit Manipulation Approach

- **Time Complexity**: O(1)
- **Space Complexity**: O(1)
- **Algorithm**:
  1. Check if n is positive (powers of 2 are always positive)
  2. Use bit manipulation trick: `n & (n-1) == 0`
  3. This works because powers of 2 have only one bit set
  4. Subtracting 1 flips all bits after the set bit

```cpp
bool isPowerOfTwo(int n) {
    return (n > 0 && (n & (n - 1)) == 0);
}
```

### Key Points

1. **Bit Manipulation Magic**:
   - Powers of 2: 1(001), 2(010), 4(100), 8(1000)
   - n-1 flips all trailing bits: 8(1000) → 7(0111)
   - AND operation: 8 & 7 = 1000 & 0111 = 0000
2. **Edge Cases**:
   - n ≤ 0 should return false
   - n = 1 is 2^0, should return true
3. **Alternative Approaches**:
   - Loop division by 2
   - Mathematical: log₂(n) should be integer

### Constraints

- -2³¹ ≤ n ≤ 2³¹ - 1

### Source

[LeetCode 231 - Power of Two](https://leetcode.com/problems/power-of-two)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Two Sum | Easy | ✅ Solved | Brute Force | O(n²) | O(1) |
| Power of Two | Easy | ✅ Solved | Bit Manipulation | O(1) | O(1) |

## 🎯 Key Learnings

1. **Array Fundamentals**: Index-based problem solving and pair finding patterns
2. **Bit Manipulation**: Efficient mathematical checks using bitwise operations
3. **Optimization Awareness**: Understanding when brute force can be improved
4. **Problem Analysis**: Reading constraints and examples carefully

## 🚀 Next Steps

- Implement hash map solution for Two Sum
- Explore more bit manipulation problems
- Practice array problems with different patterns
- Focus on time/space complexity analysis
