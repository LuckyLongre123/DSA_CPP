# Day 13: Boyer-Moore Voting Algorithm Mastery

## 🎯 Learning Objectives

By the end of this day, you will master:
- **Boyer-Moore Voting Algorithm**: Understanding the elegant majority detection technique
- **Space Optimization**: Achieving O(1) space complexity for counting problems
- **Mathematical Reasoning**: Understanding why the algorithm works mathematically
- **Voting Intuition**: Converting real-world voting concepts into algorithmic solutions

---

## Problem 1: Majority Element (LeetCode 169)

### 📋 Problem Statement

**Difficulty**: Easy  
**Category**: Array, Divide and Conquer, Sorting  
**Companies**: Amazon, Microsoft, Google, Facebook, Apple

Given an array `nums` of size `n`, return the **majority element**. The majority element is the element that appears **more than ⌊n / 2⌋ times**.

**Key Guarantee**: You may assume that the majority element **always exists** in the array.

### 🔍 Problem Analysis

**What is a Majority Element?**
- Appears **more than** half the time: `count > n/2`
- **Guaranteed to exist** in this problem
- **Unique**: Only one majority element possible

**Mathematical Insight**:
```
Array size n = 7
⌊n/2⌋ = ⌊7/2⌋ = 3
Majority element appears > 3 times (at least 4 times)

Array size n = 8  
⌊n/2⌋ = ⌊8/2⌋ = 4
Majority element appears > 4 times (at least 5 times)
```

### 📚 Examples with Detailed Analysis

#### Example 1: Simple Majority
```
Input: nums = [3,2,3]
Output: 3

Analysis:
- Array size: n = 3
- Threshold: ⌊3/2⌋ = 1, need > 1 occurrences
- Element 3: appears 2 times > 1 ✓
- Element 2: appears 1 time = 1 ✗
- Majority: 3 (appears 2/3 = 66.7% of the time)
```

#### Example 2: Larger Array
```
Input: nums = [2,2,1,1,1,2,2]
Output: 2

Analysis:
- Array size: n = 7
- Threshold: ⌊7/2⌋ = 3, need > 3 occurrences
- Element 2: appears 4 times > 3 ✓
- Element 1: appears 3 times = 3 ✗
- Majority: 2 (appears 4/7 = 57.1% of the time)
```

#### Example 3: Edge Case
```
Input: nums = [1]
Output: 1

Analysis:
- Array size: n = 1
- Threshold: ⌊1/2⌋ = 0, need > 0 occurrences
- Element 1: appears 1 time > 0 ✓
- Single element is always majority (100%)
```

#### Example 4: Complex Pattern
```
Input: nums = [6,5,5,6,6,6,5]
Output: 6

Analysis:
- Array size: n = 7
- Element 6: appears 4 times > 3 ✓
- Element 5: appears 3 times = 3 ✗
- Majority: 6 (appears 4/7 = 57.1% of the time)
```

### 🔄 Solution Approaches

#### Approach 1: Boyer-Moore Voting Algorithm ⭐

**💡 Core Idea**: Use voting mechanism where majority element "survives" the elimination process

**📊 Complexity Analysis**:
- **Time Complexity**: O(n) - single pass through array
- **Space Complexity**: O(1) - only two variables needed

**🔍 Algorithm Steps**:
1. **Initialize**: Set `candidate = any` and `count = 0`
2. **For each element**:
   - If `count == 0`: Set current element as new candidate
   - If element equals candidate: Increment count (vote for)
   - If element differs from candidate: Decrement count (vote against)
3. **Return**: The final candidate (guaranteed to be majority)

**🎯 Why This Works**:
- **Majority Property**: Majority element appears > n/2 times
- **Elimination Logic**: Even if all other elements "vote against" majority, majority still wins
- **Net Effect**: Majority element will have positive net votes

```cpp
int majorityElement(vector<int>& nums) {
    int count = 0;      // Vote counter for current candidate
    int candidate = 0;  // Current majority candidate
    
    // Boyer-Moore Voting Phase
    for(int i = 0; i < nums.size(); i++) {
        // If no current candidate, nominate current element
        if(count == 0) {
            candidate = nums[i];
        }
        
        // Vote: increment if same as candidate, decrement if different
        if(nums[i] == candidate) {
            count++;  // Vote FOR candidate
        } else {
            count--;  // Vote AGAINST candidate
        }
    }
    
    // Return the surviving candidate (guaranteed to be majority)
    return candidate;
}
```

### 🔬 Algorithm Deep Dive

**Voting Mechanism Explained**:
```
Think of it as a political election:
- Each array element is a "voter"
- Voters either support or oppose the current candidate
- If support drops to 0, a new candidate is nominated
- The candidate with net positive support wins
```

**Why Majority Always Survives**:
```
Let majority element appear M times, others appear O times
Where M > n/2 and O < n/2

Worst case: All O elements vote against majority
Net votes for majority = M - O
Since M > n/2 and O < n/2, we have M - O > 0

Therefore, majority always has positive net votes!
```

### 🎯 Key Learning Points

#### 1. **Boyer-Moore Voting Intuition** 🗳️

**Real-World Analogy**:
```
Imagine a classroom election:
- Students vote by raising hands for candidates
- If current candidate has no supporters, nominate new candidate
- Students either support (+1) or oppose (-1) current candidate
- Candidate with most net support wins

Array: [A, B, A, A, B, A]
Process:
- Start: candidate=A, count=1
- See B: count=0 (opposition)
- New candidate: B, count=1  
- See A: count=0 (opposition)
- New candidate: A, count=1
- See A: count=2
- See B: count=1 (opposition)
- See A: count=2
- Winner: A (final candidate)
```

#### 2. **Mathematical Proof** 📐

**Why Algorithm is Correct**:
```
Let:
- M = count of majority element
- O = count of all other elements combined
- n = total array size

Given: M > n/2 (majority condition)
Therefore: O = n - M < n/2

Worst case scenario:
All O elements vote against majority element
Net votes = M - O = M - (n - M) = 2M - n

Since M > n/2:
2M > n
Therefore: 2M - n > 0

Conclusion: Majority element always has positive net votes!
```

#### 3. **Space Optimization Genius** 💡

**Comparison with Naive Approach**:
```cpp
// ❌ Naive: O(n) space using hash map
unordered_map<int, int> count;
for(int num : nums) count[num]++;
for(auto& p : count) {
    if(p.second > nums.size()/2) return p.first;
}

// ✅ Boyer-Moore: O(1) space
int count = 0, candidate = 0;
for(int num : nums) {
    if(count == 0) candidate = num;
    count += (num == candidate) ? 1 : -1;
}
return candidate;
```

#### 4. **Edge Cases Mastery** ⚠️

**Critical Scenarios**:
```cpp
// Single element
nums = [5] → Output: 5 (trivially majority)

// All same elements  
nums = [7,7,7,7] → Output: 7 (100% majority)

// Minimum majority (just over half)
nums = [1,2,1] → Output: 1 (2/3 = 66.7%)

// Complex pattern
nums = [1,1,2,2,2,1,1] → Output: 1 (4/7 = 57.1%)
```

### 🔄 Detailed Algorithm Walkthrough

#### Example: nums = [2,2,1,1,1,2,2]

```
Initial: candidate = 0, count = 0

Step 1: nums[0] = 2
- count == 0 → New candidate = 2
- 2 == candidate(2) → count = 1
- State: candidate=2, count=1

Step 2: nums[1] = 2  
- count != 0 → Keep candidate = 2
- 2 == candidate(2) → count = 2
- State: candidate=2, count=2

Step 3: nums[2] = 1
- count != 0 → Keep candidate = 2
- 1 != candidate(2) → count = 1
- State: candidate=2, count=1

Step 4: nums[3] = 1
- count != 0 → Keep candidate = 2  
- 1 != candidate(2) → count = 0
- State: candidate=2, count=0

Step 5: nums[4] = 1
- count == 0 → New candidate = 1
- 1 == candidate(1) → count = 1
- State: candidate=1, count=1

Step 6: nums[5] = 2
- count != 0 → Keep candidate = 1
- 2 != candidate(1) → count = 0  
- State: candidate=1, count=0

Step 7: nums[6] = 2
- count == 0 → New candidate = 2
- 2 == candidate(2) → count = 1
- State: candidate=2, count=1

Final Result: candidate = 2 ✓
```

#### Visual Representation:
```
Array:     [2, 2, 1, 1, 1, 2, 2]
Candidate: [2, 2, 2, 2, 1, 1, 2]
Count:     [1, 2, 1, 0, 1, 0, 1]
Votes:     [+, +, -, -, +, -, +]

Final: Candidate 2 survives with count=1
```

### 🔄 Alternative Approaches Comparison

#### Approach 2: Hash Map Counting

**💡 Core Idea**: Count occurrences of each element, return one with count > n/2

```cpp
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> count;
    int n = nums.size();
    
    // Count occurrences
    for(int num : nums) {
        count[num]++;
        // Early termination optimization
        if(count[num] > n/2) {
            return num;
        }
    }
    
    return -1; // Should never reach here given problem constraints
}
```

**📊 Complexity**: O(n) time, O(n) space
**Pros**: Intuitive, works even without majority guarantee
**Cons**: Uses extra space

#### Approach 3: Sorting Method

**💡 Core Idea**: Sort array, element at index n/2 must be majority

```cpp
int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}
```

**📊 Complexity**: O(n log n) time, O(1) space
**Pros**: Simple, space-efficient
**Cons**: Slower due to sorting

**Why This Works**:
```
If majority element appears > n/2 times:
- After sorting, it occupies positions around middle
- Element at position n/2 must be majority

Example: [1,2,1,1,2] → sorted: [1,1,1,2,2]
Position n/2 = 2, nums[2] = 1 (majority) ✓
```

#### Approach 4: Randomized Algorithm

**💡 Core Idea**: Randomly pick elements, check if majority

```cpp
int majorityElement(vector<int>& nums) {
    srand(time(0));
    int n = nums.size();
    
    while(true) {
        int candidate = nums[rand() % n];
        int count = 0;
        
        for(int num : nums) {
            if(num == candidate) count++;
        }
        
        if(count > n/2) return candidate;
    }
}
```

**📊 Complexity**: Expected O(n) time, O(1) space
**Pros**: Interesting probabilistic approach
**Cons**: Non-deterministic, potentially slow in worst case

#### Performance Comparison:

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Boyer-Moore | O(n) | O(1) | Optimal, elegant | Requires majority guarantee |
| Hash Map | O(n) | O(n) | Intuitive, general | Extra space |
| Sorting | O(n log n) | O(1) | Simple | Slower |
| Randomized | O(n) avg | O(1) | Probabilistic | Non-deterministic |

### 🧪 Comprehensive Testing

#### Edge Cases:
```cpp
// Minimum size
nums = [1] → Expected: 1

// All identical
nums = [5,5,5,5] → Expected: 5

// Minimum majority (n=3)
nums = [1,2,1] → Expected: 1

// Large array with clear majority
nums = [1,1,1,2,2] → Expected: 1

// Alternating pattern
nums = [1,2,1,2,1] → Expected: 1

// Negative numbers
nums = [-1,-1,0] → Expected: -1
```

#### Stress Testing:
```cpp
// Large array (n = 50000)
vector<int> nums(50000);
for(int i = 0; i < 30000; i++) nums[i] = 1;  // Majority
for(int i = 30000; i < 50000; i++) nums[i] = 2;  // Minority
// Expected: 1 (appears 30000/50000 = 60%)
```

### 📏 Constraints and Implications

**Given Constraints:**
- `n == nums.length`
- `1 ≤ n ≤ 5 × 10⁴`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

**Constraint Analysis:**
```
Array Size: Up to 50,000 elements
→ O(n) algorithms are essential
→ O(n log n) sorting acceptable but not optimal
→ O(n²) brute force too slow

Element Range: Very large integers
→ Hash map keys can be large
→ No special optimizations for small ranges
→ Boyer-Moore unaffected by value range

Majority Guarantee: Always exists
→ Boyer-Moore algorithm guaranteed to work
→ No need to verify result
→ Simplifies implementation
```

### 🔗 Source and Related Problems

**Main Problem**: [LeetCode 169 - Majority Element](https://leetcode.com/problems/majority-element)

**Related Problems to Master**:
1. **LeetCode 229**: Majority Element II (find elements appearing > n/3 times)
2. **LeetCode 1287**: Element Appearing More Than 25% In Sorted Array
3. **Custom**: Find all elements appearing > n/k times
4. **Interview**: Verify if majority element exists (without guarantee)

### 🎓 Advanced Extensions

#### Boyer-Moore for Multiple Majorities:
```cpp
// Find elements appearing > n/3 times (at most 2 such elements)
vector<int> majorityElementII(vector<int>& nums) {
    int candidate1 = 0, candidate2 = 0;
    int count1 = 0, count2 = 0;
    
    // Voting phase
    for(int num : nums) {
        if(num == candidate1) count1++;
        else if(num == candidate2) count2++;
        else if(count1 == 0) candidate1 = num, count1 = 1;
        else if(count2 == 0) candidate2 = num, count2 = 1;
        else count1--, count2--;
    }
    
    // Verification phase (needed when no guarantee)
    vector<int> result;
    count1 = count2 = 0;
    for(int num : nums) {
        if(num == candidate1) count1++;
        else if(num == candidate2) count2++;
    }
    
    if(count1 > nums.size()/3) result.push_back(candidate1);
    if(count2 > nums.size()/3) result.push_back(candidate2);
    
    return result;
}
```

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Majority Element | Easy | ✅ Solved | Boyer-Moore Voting | O(n) | O(1) |

## 🎯 Key Learnings Achieved

### ✅ **Boyer-Moore Voting Mastery**
- **Algorithm Understanding**: Grasped the voting mechanism and elimination process
- **Mathematical Proof**: Understood why majority element always survives
- **Implementation Skills**: Coded the algorithm with proper variable management
- **Optimization Awareness**: Recognized O(1) space achievement vs O(n) alternatives

### ✅ **Problem-Solving Patterns**
- **Majority Detection**: Learned the fundamental pattern for finding dominant elements
- **Space-Time Tradeoffs**: Analyzed different approaches and their complexities
- **Guarantee Utilization**: Leveraged problem constraints for algorithm simplification
- **Edge Case Handling**: Managed single elements, identical arrays, and complex patterns

### ✅ **Algorithm Design Principles**
- **Intuitive Thinking**: Converted real-world voting into algorithmic logic
- **Mathematical Reasoning**: Applied mathematical proofs to validate correctness
- **Efficiency Focus**: Prioritized optimal time and space complexity
- **Pattern Recognition**: Identified when Boyer-Moore voting is applicable

## 🚀 Next Steps and Advanced Topics

### Immediate Practice:
- **LeetCode 229**: Majority Element II (> n/3 threshold)
- **Custom Problems**: Find elements appearing > n/k times
- **Verification Variants**: Problems without majority guarantee

### Advanced Concepts:
- **Generalized Boyer-Moore**: Handling multiple majority candidates
- **Streaming Algorithms**: Applying voting to data streams
- **Distributed Systems**: Majority consensus in distributed computing

## 💡 Master Problem-Solving Tips

### 🎯 **Pattern Recognition**
```
When to use Boyer-Moore Voting:
✅ Finding majority/dominant elements
✅ Space optimization is crucial (O(1) requirement)
✅ Single pass through data is needed
✅ Majority element is guaranteed to exist

When NOT to use:
❌ Need to find ALL elements above threshold
❌ No guarantee of majority existence
❌ Need exact counts, not just majority
❌ Multiple passes through data are acceptable
```

### 🧠 **Thinking Framework**
1. **Identify Majority Problems**: Look for "more than half" or "dominant element" keywords
2. **Check Guarantees**: Verify if majority is guaranteed to exist
3. **Consider Constraints**: Evaluate if O(1) space is required
4. **Apply Voting Logic**: Think in terms of votes for/against candidates
5. **Trace Examples**: Walk through algorithm with sample inputs
6. **Handle Edge Cases**: Test with single elements and boundary conditions

---

**Total Problems Solved**: 4/∞

*Vote wisely, code efficiently! 🗳️*
