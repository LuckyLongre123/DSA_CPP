# Day 19: Peak Finding & Unimodal Arrays Mastery

## 🎯 Learning Objectives

By the end of this day, you will master:
- **Peak Finding Algorithms**: Efficiently locating peaks in mountain arrays
- **Unimodal Array Properties**: Understanding single-peak array characteristics
- **Binary Search Applications**: Using binary search for optimization problems
- **Gradient-Based Search**: Following slopes to find optimal points

---

## Problem 1: Peak Index in a Mountain Array (LeetCode 852)

### Problem Statement

**Difficulty**: Medium  
**Category**: Array, Binary Search  
**Companies**: Amazon, Microsoft, Apple, Facebook, Google

An array `arr` is a **mountain array** if and only if:
- `arr.length >= 3`
- There exists some `i` with `0 < i < arr.length - 1` such that:
  - `arr[0] < arr[1] < ... < arr[i - 1] < arr[i]` (strictly increasing)
  - `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]` (strictly decreasing)

**Task**: Given a mountain array `arr`, return the index `i` such that `arr[i]` is the peak of the mountain.

**Guarantee**: The answer is guaranteed to exist and be unique.

**Challenge**: You must solve it in `O(log(arr.length))` time complexity.

### Examples:

```
Input: arr = [0,1,0]
Output: 1

Input: arr = [0,2,1,0]
Output: 1

Input: arr = [0,10,5,2]
Output: 1
```

### Approach

#### Binary Search on Mountain Array

- **Time Complexity**: O(log n)
- **Space Complexity**: O(1)
- **Key Insight**: Peak is where ascending part transitions to descending part
- **Algorithm**:
  1. Use two pointers: `start` and `end`
  2. Calculate `mid` point
  3. Compare `arr[mid]` with `arr[mid + 1]`:
     - If `arr[mid] < arr[mid + 1]`: peak is on the right (ascending part)
     - If `arr[mid] > arr[mid + 1]`: peak is at mid or on the left (descending part)
  4. Adjust search space accordingly
  5. Continue until `start == end`

```cpp
int peakIndexInMountainArray(vector<int>& arr) {
    int s = 0;
    int e = arr.size() - 1;

    while(s < e){
        int mid = s + (e - s)/2;
        
        if(arr[mid] < arr[mid + 1]){
            s = mid + 1;  // Peak is on the right
        }else{
            e = mid;      // Peak is at mid or on the left
        }
    }
    
    return s;  // s == e at this point
}
```

### Key Points

1. **Mountain Array Properties**:
   - Strictly increasing then strictly decreasing
   - Guaranteed to have exactly one peak
   - Peak is never at boundaries (index 0 or n-1)

2. **Binary Search Logic**:
   - Compare mid with mid+1 to determine direction
   - If ascending (mid < mid+1), peak is to the right
   - If descending (mid > mid+1), peak is at mid or to the left

3. **Why This Works**:
   - Mountain property guarantees peak exists
   - Binary search eliminates half the search space each iteration
   - Converges to the unique peak position

### Algorithm Walkthrough

```
Example: arr = [0,2,1,0]

Initial: s=0, e=3
Array: [0,2,1,0]
        s     e

Step 1: mid = (0+3)/2 = 1
        arr[1]=2, arr[2]=1
        arr[mid] > arr[mid+1], so peak is at mid or left
        e = mid = 1

Step 2: s=0, e=1
        mid = (0+1)/2 = 0
        arr[0]=0, arr[1]=2
        arr[mid] < arr[mid+1], so peak is on right
        s = mid+1 = 1

Step 3: s=1, e=1 (s == e)
        Return s = 1
```

### Visual Representation

```
Mountain Array Visualization:

arr = [0,1,5,4,3,2,0]
       ↑ ↑ ↑ ↑ ↑ ↑ ↑
       0 1 2 3 4 5 6

       5 ← Peak at index 2
      /|\
     1 | 4
    /  |  \
   0   |   3
       |    \
       |     2
       |      \
       |       0

Binary Search Process:
Step 1: Compare mid with mid+1 to find direction
Step 2: Move towards the peak
Step 3: Converge to peak position
```

### Edge Cases

1. **Minimum Size**: `arr = [0,1,0]` (length = 3)
2. **Peak Near Left**: `arr = [0,2,1,0]`
3. **Peak Near Right**: `arr = [0,1,2,0]`
4. **Large Mountain**: Performance remains O(log n)

### Comparison with Linear Search

| Aspect | Linear Search | Binary Search |
|--------|---------------|---------------|
| Time Complexity | O(n) | O(log n) |
| Space Complexity | O(1) | O(1) |
| Approach | Check each element | Eliminate half each step |
| Efficiency | Less efficient | More efficient |

### Alternative Approaches

1. **Linear Scan**: O(n) - find where arr[i] > arr[i+1]
2. **Golden Section Search**: O(log n) - for unimodal functions
3. **Ternary Search**: O(log n) - divide into three parts

### Mathematical Insight

The mountain array is a **unimodal function**:
- Has exactly one peak (maximum)
- Strictly increasing before peak
- Strictly decreasing after peak
- Binary search exploits this property for efficiency

### Implementation Variants

```cpp
// Variant 1: Using while(s < e)
int peakIndex(vector<int>& arr) {
    int s = 0, e = arr.size() - 1;
    while(s < e) {
        int mid = s + (e - s) / 2;
        if(arr[mid] < arr[mid + 1]) s = mid + 1;
        else e = mid;
    }
    return s;
}

// Variant 2: Using while(s <= e) - needs careful handling
int peakIndex(vector<int>& arr) {
    int s = 0, e = arr.size() - 1;
    while(s <= e) {
        int mid = s + (e - s) / 2;
        if(mid < arr.size() - 1 && arr[mid] < arr[mid + 1]) {
            s = mid + 1;
        } else if(mid > 0 && arr[mid] < arr[mid - 1]) {
            e = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
```

### Constraints

- 3 ≤ arr.length ≤ 10⁵
- 0 ≤ arr[i] ≤ 10⁶
- `arr` is **guaranteed** to be a mountain array

### Source

[LeetCode 852 - Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Peak Index in Mountain Array | Medium | ✅ Solved | Binary Search | O(log n) | O(1) |

## 🎯 Key Learnings

1. **Unimodal Functions**: Understanding mountain arrays as unimodal functions
2. **Binary Search Applications**: Using binary search beyond sorted arrays
3. **Comparison Strategy**: Using mid vs mid+1 comparison for direction
4. **Convergence Logic**: Understanding when s < e vs s <= e conditions

## 🚀 Next Steps

- Practice more peak finding problems (2D mountain arrays)
- Study ternary search for continuous unimodal functions
- Learn about finding local maxima in general arrays
- Explore applications in optimization problems

## 💡 Problem-Solving Tips

1. **Identify Pattern**: Recognize mountain/unimodal structure
2. **Direction Decision**: Use adjacent element comparison
3. **Boundary Conditions**: Handle s < e vs s <= e carefully
4. **Guaranteed Peak**: Leverage problem constraints (mountain array guaranteed)
