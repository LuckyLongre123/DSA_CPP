# Day 16: Two-Pointer Technique Mastery

## 🎯 Learning Objectives

By the end of this day, you will master:
- **Two-Pointer Technique**: Using multiple pointers for efficient array traversal
- **In-Place Modifications**: Modifying arrays without extra space
- **Sorted Array Optimization**: Leveraging sorted property for O(n) solutions
- **Space-Time Tradeoffs**: Achieving O(1) space complexity with optimal time

---

## Problem 1: Remove Duplicates from Sorted Array (LeetCode 26)

### 📋 Problem Statement

**Difficulty**: Easy  
**Category**: Array, Two Pointers  
**Companies**: Amazon, Microsoft, Apple, Facebook, Google

Given an integer array `nums` sorted in **non-decreasing order**, remove the duplicates **in-place** such that each unique element appears only **once**. The **relative order** of the elements should be kept the **same**. Then return the number of unique elements in `nums`.

**Key Requirements**:
- Modify the array **in-place** with O(1) extra memory
- Return the number `k` of unique elements
- First `k` elements of `nums` should hold the unique elements
- Elements beyond index `k-1` don't matter

### 🔍 Problem Analysis

**Two-Pointer Strategy**:
```
Slow Pointer (i): Points to position where next unique element should be placed
Fast Pointer (j): Scans through array to find unique elements

Key Insight: Since array is sorted, duplicates are adjacent
```

**In-Place Modification**:
```
Original: [1,1,2,2,3,3,4]
Result:   [1,2,3,4,_,_,_] (return k=4)
          ↑       ↑
        unique  don't care
```

### 📚 Examples with Detailed Analysis

#### Example 1: Simple Case
```
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]

Step-by-step process:
Initial: [1,1,2], i=0, j=1
- nums[0]=1, nums[1]=1 → duplicate, j++
- nums[0]=1, nums[2]=2 → unique, nums[++i]=nums[j] → [1,2,2], i=1, j++
- j=3 (end), return i+1=2

Result: [1,2,_] with k=2
```

#### Example 2: Multiple Duplicates
```
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]

Process visualization:
i=0, j=1: [0,0,1,1,1,2,2,3,3,4]
          ↑ ↑
i=0, j=2: [0,1,1,1,1,2,2,3,3,4] → nums[1]=1
          ↑   ↑
i=1, j=5: [0,1,2,1,1,2,2,3,3,4] → nums[2]=2
            ↑     ↑
i=2, j=7: [0,1,2,3,1,2,2,3,3,4] → nums[3]=3
              ↑       ↑
i=3, j=9: [0,1,2,3,4,2,2,3,3,4] → nums[4]=4
                ↑         ↑

Final: [0,1,2,3,4,_,_,_,_,_] with k=5
```

### 🔄 Solution Approach

#### Two Pointers Technique ⭐

**💡 Core Idea**: Use slow pointer for placement, fast pointer for scanning

**📊 Complexity Analysis**:
- **Time Complexity**: O(n) - single pass through array
- **Space Complexity**: O(1) - only using two pointer variables

**🔍 Algorithm Steps**:
1. **Initialize**: Set `i = 0` (slow pointer for unique elements position)
2. **Scan**: Use `j` starting from 1 (fast pointer for array traversal)
3. **Compare**: For each `j`, check if `nums[i] != nums[j]`
4. **Update**: If different, increment `i` and copy `nums[j]` to `nums[i]`
5. **Continue**: Repeat until `j` reaches array end
6. **Return**: `i + 1` represents count of unique elements

```cpp
int removeDuplicates(vector<int>& nums) {
    // Handle edge case: empty array
    if(nums.empty()) return 0;
    
    int i = 0;  // Slow pointer: position for next unique element
    
    // Fast pointer j starts from index 1
    for(int j = 1; j < nums.size(); j++) {
        // If current element is different from previous unique element
        if(nums[i] != nums[j]) {
            i++;              // Move to next position for unique element
            nums[i] = nums[j]; // Place the new unique element
        }
        // If nums[i] == nums[j], it's a duplicate, just continue
    }
    
    // Return count of unique elements (i+1 since i is 0-indexed)
    return i + 1;
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

### 🚨 Edge Cases and Testing Strategy

#### Critical Test Cases
```cpp
// 1. Empty Array
nums = [] → return 0
// Edge case: no elements to process

// 2. Single Element
nums = [1] → return 1, nums = [1]
// No duplicates possible with one element

// 3. No Duplicates
nums = [1,2,3,4,5] → return 5, nums = [1,2,3,4,5]
// Array remains unchanged, all elements unique

// 4. All Duplicates
nums = [1,1,1,1,1] → return 1, nums = [1,_,_,_,_]
// Only first element kept, rest ignored

// 5. Mixed Pattern
nums = [1,1,2,2,2,3,4,4] → return 4, nums = [1,2,3,4,_,_,_,_]
// Various duplicate lengths

// 6. Two Elements
nums = [1,1] → return 1, nums = [1,_]
nums = [1,2] → return 2, nums = [1,2]
```

#### Boundary Conditions
```cpp
// Maximum constraints
nums.length = 30000 (3 × 10⁴)
All elements = -100 to 100

// Worst case: all same elements
nums = [-100, -100, -100, ..., -100] (30000 times)
Result: return 1, O(n) time still efficient

// Best case: all unique elements  
nums = [-100, -99, -98, ..., 100] (201 unique values)
Result: return 201, no modifications needed
```

### 🔄 Alternative Approaches Comparison

#### Approach 1: HashSet Method
```cpp
int removeDuplicates(vector<int>& nums) {
    unordered_set<int> seen;
    int writeIndex = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (seen.find(nums[i]) == seen.end()) {
            seen.insert(nums[i]);
            nums[writeIndex++] = nums[i];
        }
    }
    return writeIndex;
}
```
**Time**: O(n), **Space**: O(k) where k = unique elements
**Pros**: Works for unsorted arrays too
**Cons**: Extra space, slower due to hash operations

#### Approach 2: New Array Method
```cpp
vector<int> removeDuplicates(vector<int>& nums) {
    vector<int> result;
    if (!nums.empty()) {
        result.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                result.push_back(nums[i]);
            }
        }
    }
    return result;
}
```
**Time**: O(n), **Space**: O(k) where k = unique elements
**Pros**: Cleaner logic, doesn't modify input
**Cons**: Extra space, doesn't meet in-place requirement

#### Approach 3: STL unique() Function
```cpp
int removeDuplicates(vector<int>& nums) {
    auto it = unique(nums.begin(), nums.end());
    return distance(nums.begin(), it);
}
```
**Time**: O(n), **Space**: O(1)
**Pros**: One-liner, highly optimized
**Cons**: Less educational, hides algorithm details

#### Approach 4: Recursive Solution
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        return removeDuplicatesHelper(nums, 0, 1);
    }
    
private:
    int removeDuplicatesHelper(vector<int>& nums, int i, int j) {
        if (j >= nums.size()) return i + 1;
        
        if (nums[i] != nums[j]) {
            nums[++i] = nums[j];
        }
        return removeDuplicatesHelper(nums, i, j + 1);
    }
};
```
**Time**: O(n), **Space**: O(n) due to recursion stack
**Pros**: Functional programming style
**Cons**: Stack overflow risk, unnecessary complexity

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

### Performance Metrics
- **Algorithm Efficiency**: Optimal O(n) time, O(1) space
- **Code Quality**: Clean, readable, and maintainable
- **Edge Case Coverage**: Comprehensive boundary condition handling
- **Pattern Mastery**: Two-pointer technique fully understood

### Skills Developed
1. **In-Place Array Manipulation**: Modifying arrays without extra space
2. **Two-Pointer Coordination**: Managing multiple pointers effectively
3. **Sorted Array Optimization**: Leveraging order for efficient processing
4. **Algorithm Analysis**: Understanding optimality and complexity

---

**🎯 Day 16 Complete! Two-Pointer Technique Mastered** ✅

## 🎯 Key Learnings Achieved

### Core Mastery ✅
- **Two-Pointer Technique**: Master the read-write pointer pattern for efficient array processing
- **Sorted Array Leverage**: Utilize sorted properties to simplify duplicate detection
- **Algorithm Optimality**: Understand why this solution is asymptotically optimal

### Advanced Skills ✅
- **Invariant Maintenance**: Keep track of array sections and their properties
{{ ... }}
- **Pattern Recognition**: Identify when two-pointer technique applies
- **Performance Analysis**: Deep understanding of time/space complexity
- **Edge Case Mastery**: Comprehensive handling of boundary conditions

### Problem-Solving Framework ✅
- **Requirement Analysis**: Break down in-place modification requirements
- **Algorithm Design**: Choose optimal approach based on constraints
- **Implementation Strategy**: Write clean, efficient, and maintainable code
- **Testing Methodology**: Create comprehensive test cases for validation

## 🚀 Next Steps and Related Problems

### Immediate Practice
- **LeetCode 80**: Remove Duplicates from Sorted Array II (allow at most 2 duplicates)
- **LeetCode 27**: Remove Element (similar two-pointer pattern)
- **LeetCode 283**: Move Zeroes (partitioning variation)
- **LeetCode 75**: Sort Colors (Dutch flag problem)

### Advanced Two-Pointer Techniques
- **Sliding Window**: Variable-size window problems
- **Fast-Slow Pointers**: Cycle detection in linked lists
- **Opposite Direction**: Two Sum in sorted array
- **Multiple Pointers**: Three Sum and Four Sum problems

### In-Place Algorithm Mastery
- Array rotation algorithms
- In-place matrix transformations
- String manipulation without extra space
- Linked list modifications

### Performance Optimization
- Cache-friendly algorithm design
- SIMD optimization for array operations
- Parallel processing with two pointers
- Memory access pattern optimization

### 🧮 Mathematical Properties and Insights

#### Two-Pointer Invariants
```cpp
// Throughout the algorithm, these invariants hold:
// 1. nums[0...i] contains all unique elements found so far
// 2. nums[i+1...j-1] contains duplicates (can be ignored)
// 3. nums[j...n-1] contains unprocessed elements

// Visual representation:
// [unique elements][duplicates/garbage][unprocessed]
//  0            i  i+1           j-1  j         n-1
```

#### Complexity Analysis Deep Dive
```cpp
// Time Complexity: O(n)
// - Single pass through array: n iterations
// - Each iteration: O(1) operations (comparison, assignment)
// - No nested loops or recursive calls
// - Linear relationship: T(n) = c₁ + c₂*n

// Space Complexity: O(1)
// - Only using two integer variables: i, j
// - No additional data structures
// - Input array modified in-place
// - Constant space regardless of input size
```

#### Optimal Performance Characteristics
```cpp
// Best Case: O(n) - All elements unique
// Average Case: O(n) - Mixed duplicates
// Worst Case: O(n) - All elements same

// The algorithm is optimal because:
// 1. Must examine each element at least once: Ω(n)
// 2. Our algorithm examines each element exactly once: O(n)
// 3. Therefore, it's asymptotically optimal: Θ(n)
```

### 🎯 Advanced Optimization Techniques

#### Early Termination Optimization
```cpp
int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();  // Quick return
    
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[i] != nums[j]) {
            // Only increment and assign if necessary
            if (++i != j) {  // Avoid self-assignment
                nums[i] = nums[j];
            }
        }
    }
    return i + 1;
}
```

#### Memory Access Pattern Optimization
```cpp
// Cache-friendly version with prefetching hint
int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();
    
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        // Prefetch next elements for better cache performance
        __builtin_prefetch(&nums[j + 1], 0, 1);
        
        if (nums[i] != nums[j]) {
            nums[++i] = nums[j];
        }
    }
    return i + 1;
}
```

### 🔍 Pattern Recognition and Extensions

#### Two-Pointer Pattern Variations
```cpp
// 1. Remove Duplicates (this problem)
// Pattern: slow pointer for writing, fast for reading

// 2. Remove Element (LeetCode 27)
// Pattern: similar, but condition is nums[j] != val

// 3. Move Zeroes (LeetCode 283)
// Pattern: move non-zeros to front, zeros naturally go to back

// 4. Partition Array (various problems)
// Pattern: separate elements based on condition
```

#### Template for Similar Problems
```cpp
template<typename Predicate>
int removeElements(vector<int>& nums, Predicate shouldKeep) {
    if (nums.empty()) return 0;
    
    int writeIndex = 0;
    for (int readIndex = 0; readIndex < nums.size(); readIndex++) {
        if (shouldKeep(nums, readIndex, writeIndex)) {
            if (writeIndex != readIndex) {
                nums[writeIndex] = nums[readIndex];
            }
            writeIndex++;
        }
    }
    return writeIndex;
}

// Usage for remove duplicates:
auto keepUnique = [](const vector<int>& nums, int read, int write) {
    return write == 0 || nums[write-1] != nums[read];
};
int result = removeElements(nums, keepUnique);
```

### 🧪 Comprehensive Testing Framework

```cpp
class RemoveDuplicatesTest {
public:
    void runAllTests() {
        testBasicCases();
        testEdgeCases();
        testPerformance();
        testBoundaryConditions();
        cout << "All tests passed!" << endl;
    }
    
private:
    void testBasicCases() {
        // Test case 1: Simple duplicates
        vector<int> nums1 = {1,1,2};
        assert(removeDuplicates(nums1) == 2);
        assert(nums1[0] == 1 && nums1[1] == 2);
        
        // Test case 2: Multiple duplicates
        vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};
        assert(removeDuplicates(nums2) == 5);
        vector<int> expected = {0,1,2,3,4};
        for (int i = 0; i < 5; i++) {
            assert(nums2[i] == expected[i]);
        }
    }
    
    void testEdgeCases() {
        // Empty array
        vector<int> empty = {};
        assert(removeDuplicates(empty) == 0);
        
        // Single element
        vector<int> single = {1};
        assert(removeDuplicates(single) == 1);
        assert(single[0] == 1);
        
        // All same elements
        vector<int> allSame = {5,5,5,5,5};
        assert(removeDuplicates(allSame) == 1);
        assert(allSame[0] == 5);
    }
    
    void testPerformance() {
        // Large array test
        vector<int> large(30000, 1);  // All same elements
        auto start = chrono::high_resolution_clock::now();
        int result = removeDuplicates(large);
        auto end = chrono::high_resolution_clock::now();
        
        assert(result == 1);
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        assert(duration.count() < 10000);  // Should complete in < 10ms
    }
};
```

### 📊 Real-World Applications

#### Database Query Optimization
```sql
-- SQL equivalent of remove duplicates
SELECT DISTINCT column_name FROM table_name ORDER BY column_name;

-- Our algorithm is similar to how databases handle:
-- 1. Sort-based duplicate elimination
-- 2. In-place result set construction
-- 3. Memory-efficient processing
```

#### Data Stream Processing
```cpp
// Real-time duplicate removal in data streams
class StreamDeduplicator {
private:
    int lastValue = INT_MIN;
    bool hasValue = false;
    
public:
    bool shouldKeep(int value) {
        if (!hasValue || value != lastValue) {
            lastValue = value;
            hasValue = true;
            return true;
        }
        return false;
    }
};
```

## 💡 Problem-Solving Tips

1. **Two-Pointer Mastery**: Practice the read-write pointer pattern for in-place modifications
2. **Sorted Array Leverage**: Use the sorted property to simplify duplicate detection
3. **Space Optimization**: Always consider in-place solutions before using extra space
4. **Invariant Maintenance**: Keep track of what each section of the array represents
5. **Edge Case Coverage**: Test empty arrays, single elements, and boundary conditions
6. **Performance Awareness**: Understand why this algorithm is optimal for the problem
7. **Pattern Recognition**: Identify when two-pointer technique applies to other problems
