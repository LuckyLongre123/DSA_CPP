# Day 13: Array Algorithms - Boyer-Moore Voting

## Problem 1: Majority Element

### Problem Description

Given an array `nums` of size `n`, return the majority element. The majority element is the element that appears more than `⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

### Examples:

```
Input: nums = [3,2,3]
Output: 3
Explanation: 3 appears 2 times out of 3, which is > 3/2 = 1.5

Input: nums = [2,2,1,1,1,2,2]
Output: 2
Explanation: 2 appears 4 times out of 7, which is > 7/2 = 3.5

Input: nums = [1]
Output: 1
Explanation: Single element is always majority
```

### Approach

#### Boyer-Moore Voting Algorithm

- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **Algorithm**:
  1. Initialize candidate and counter variables
  2. Iterate through array:
     - If counter is 0, set current element as candidate
     - If current element equals candidate, increment counter
     - Otherwise, decrement counter
  3. Return the candidate (guaranteed to be majority)

```cpp
int majorityElement(vector<int>& nums) {
    int freq = 0;  // Counter for current candidate
    int ans = 0;   // Current candidate
    
    for(int i = 0; i < nums.size(); i++){
        if(freq == 0) ans = nums[i];  // New candidate
        if(ans == nums[i]) freq++;    // Vote for candidate
        else freq--;                  // Vote against candidate
    }
    
    return ans;  // Majority element
}
```

### Key Points

1. **Boyer-Moore Voting Logic**:
   - Majority element appears > n/2 times
   - Even if all other elements vote against it, majority will survive
   - Counter represents "net votes" for current candidate

2. **Algorithm Intuition**:
   - Think of it as a voting contest
   - Each occurrence of candidate gets +1 vote
   - Each occurrence of different element gets -1 vote
   - Majority element will have positive net votes

3. **Why It Works**:
   - If majority element appears > n/2 times
   - All other elements combined appear < n/2 times
   - Net effect: majority element wins

### Algorithm Walkthrough

```
Array: [2,2,1,1,1,2,2]

Step 1: freq=0, ans=0 → see 2 → ans=2, freq=1
Step 2: freq=1, ans=2 → see 2 → freq=2
Step 3: freq=2, ans=2 → see 1 → freq=1
Step 4: freq=1, ans=2 → see 1 → freq=0
Step 5: freq=0, ans=2 → see 1 → ans=1, freq=1
Step 6: freq=1, ans=1 → see 2 → freq=0
Step 7: freq=0, ans=1 → see 2 → ans=2, freq=1

Result: ans=2 (correct majority element)
```

### Alternative Approaches

1. **Hash Map Counting**: O(n) time, O(n) space
2. **Sorting**: O(n log n) time, O(1) space - element at n/2 index
3. **Randomization**: Expected O(n) time, O(1) space

### Constraints

- n == nums.length
- 1 ≤ n ≤ 5 × 10⁴
- -10⁹ ≤ nums[i] ≤ 10⁹

### Source

[LeetCode 169 - Majority Element](https://leetcode.com/problems/majority-element)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Majority Element | Easy | ✅ Solved | Boyer-Moore Voting | O(n) | O(1) |

## 🎯 Key Learnings

1. **Boyer-Moore Voting Algorithm**: Efficient majority element detection in linear time
2. **Space Optimization**: Achieving O(1) space complexity for counting problems
3. **Mathematical Insight**: Understanding why majority element survives the voting process
4. **Algorithm Design**: Converting intuitive voting concept into code logic

## 🚀 Next Steps

- Practice more voting algorithm problems
- Explore majority element variations (find all elements appearing > n/3 times)
- Study other linear time algorithms for array problems
- Learn about randomized algorithms for majority detection

## 💡 Problem-Solving Tips

1. **Understand Guarantees**: Problem states majority element always exists
2. **Think Intuitively**: Voting analogy helps understand the algorithm
3. **Trace Through Examples**: Walk through algorithm step-by-step
4. **Consider Edge Cases**: Single element, all same elements, alternating pattern
