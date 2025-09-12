# Day 27: String Rotation & Fundamental Sorting Algorithms

## 🎯 Learning Objectives

By the end of this day, you will master:
- **String Rotation Detection**: Identifying if one string is a rotation of another
- **Concatenation Technique**: Using string concatenation for efficient rotation checking
- **Fundamental Sorting Algorithms**: Bubble Sort, Selection Sort, Insertion Sort
- **Algorithm Analysis**: Understanding time/space complexity trade-offs
- **Pattern Recognition**: Understanding cyclic patterns and sorting strategies
- **Algorithm Optimization**: Converting O(n²) brute force to O(n) optimal solutions

---

## 🔄 Part 1: String Rotation Problem

### Problem 1: Rotate String (LeetCode 796)

### 📋 Problem Statement

**Difficulty**: Easy  
**Category**: String, String Matching  
**Companies**: Amazon, Microsoft, Google, Facebook

Given two strings `s` and `goal`, return `true` if and only if `s` can become `goal` after some number of **shifts** on `s`.

**Shift Definition**: Moving the leftmost character of `s` to the rightmost position.
- Example: "abcde" → "bcdea" (1 left shift)

### 💡 Examples

```
Example 1:
Input: s = "abcde", goal = "cdeab"
Output: true
Explanation: 2 left shifts transform s to goal:
"abcde" → "bcdea" → "cdeab" ✓

Example 2:
Input: s = "abcde", goal = "abced"
Output: false
Explanation: No amount of shifts can make s equal to goal

Example 3:
Input: s = "aa", goal = "a"
Output: false
Explanation: Different lengths make rotation impossible
```

### 🔍 Intuition

**Brute Force Approach**: Try all possible rotations of `s` and check if any matches `goal` → O(n²)

**Optimized Approach**: Use the **concatenation trick** → O(n)

**Key Insight**: If `goal` is a rotation of `s`, then `goal` must appear as a **substring** in `s + s`.

**Why this works**: When we concatenate `s` with itself, all possible rotations of `s` appear as contiguous substrings!

### 🚀 Approach: String Concatenation Method

#### Why This Works:

When we concatenate `s` with itself, we get all possible rotations of `s` as substrings:

```
s = "abcde"
s + s = "abcdeabcde"

All rotations of s appear as substrings:
- "abcde" (0 rotations) - positions 0-4
- "bcdea" (1 rotation)  - positions 1-5
- "cdeab" (2 rotations) - positions 2-6
- "deabc" (3 rotations) - positions 3-7
- "eabcd" (4 rotations) - positions 4-8
```

### Algorithm Steps:

1. **Length Check**: Verify both strings have the same length
2. **Concatenation**: Create `s + s` to contain all rotations
3. **Substring Search**: Check if `goal` exists in the concatenated string

### Visual Representation:

```
Original: s = "abcde", goal = "cdeab"

Step 1: Check lengths
s.length = 5, goal.length = 5 ✓

Step 2: Create s + s
"abcde" + "abcde" = "abcdeabcde"

Step 3: Find goal in s + s
"abcdeabcde"
     ^^^^^
   "cdeab" found at position 2 ✓

Result: true
```

## Implementation Details

```cpp
bool rotateString(string s, string goal) {
    // Check if lengths are equal (necessary condition)
    if (s.size() != goal.size()) {
        return false;
    }
    
    // Check if goal is substring of s + s
    return (s + s).find(goal) != string::npos;
}
```

## Complexity Analysis

- **Time Complexity**: O(n) where n is the length of the string
  - String concatenation: O(n)
  - Substring search using KMP algorithm: O(n)
  
- **Space Complexity**: O(n) for creating the concatenated string

## Edge Cases

1. **Empty Strings**: Both empty → `true`
2. **Different Lengths**: → `false`
3. **Identical Strings**: → `true`
4. **Single Character**: 
   - Same character: `true`
   - Different characters: `false`
5. **No Valid Rotation**: Characters don't match → `false`

## Alternative Approaches

### Approach 1: Brute Force Rotation
```cpp
bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) return false;
    
    for (int i = 0; i < s.size(); i++) {
        if (s == goal) return true;
        s = s.substr(1) + s[0]; // Rotate left by 1
    }
    return false;
}
```
- **Time**: O(n²), **Space**: O(n)

### Approach 2: Find Rotation Point
```cpp
bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) return false;
    
    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i) + s.substr(0, i) == goal) {
            return true;
        }
    }
    return false;
}
```
- **Time**: O(n²), **Space**: O(n)

## Key Insights

1. **String Rotation Property**: All rotations of a string appear as substrings in the string concatenated with itself
2. **Efficient Search**: Using built-in `find()` function leverages optimized string matching algorithms
3. **Early Termination**: Length check eliminates impossible cases immediately
4. **Mathematical Elegance**: The concatenation approach transforms a rotation problem into a substring search problem

## Learning Objectives

- Understanding string rotation mechanics
- Applying mathematical insights to optimize algorithms
- Using string manipulation techniques effectively
- Recognizing patterns in cyclic data structures

## Related Problems

- LeetCode 459: Repeated Substring Pattern
- LeetCode 686: Repeated String Match
- String rotation problems in arrays

### 📈 Constraints

- 1 ≤ s.length, goal.length ≤ 100
- s and goal consist of lowercase English letters

### 🔗 Source

[LeetCode 796 - Rotate String](https://leetcode.com/problems/rotate-string)

---

## 🔢 Part 2: Fundamental Sorting Algorithms

### 📚 What is Sorting?

**Sorting** means arranging elements in a specific order (usually ascending or descending). Think of it like organizing your books by height or arranging numbers from smallest to largest.

**Example:**
```
Unsorted: [64, 34, 25, 12, 22, 11, 90]
Sorted:   [11, 12, 22, 25, 34, 64, 90]
```

### 🎯 Why Learn Sorting?

- **Foundation Skill**: Essential for programming interviews
- **Problem Solving**: Helps understand algorithm design
- **Real Applications**: Used in databases, search engines, data analysis
- **Thinking Process**: Develops logical reasoning

---

## 🔵 Algorithm 1: Bubble Sort - The Simplest One

### 🤔 What is Bubble Sort?

Imagine you have a line of people of different heights. In bubble sort, you compare two people standing next to each other and swap them if the taller person is on the left. You keep doing this until everyone is arranged from shortest to tallest.

### 📖 How It Works (Step by Step)

**The Big Picture:**
- Compare adjacent elements (neighbors)
- If left > right, swap them
- Repeat until no swaps needed

**Visual Example:**
```
Array: [64, 34, 25, 12]

Pass 1:
[64, 34, 25, 12] → Compare 64 & 34 → Swap → [34, 64, 25, 12]
[34, 64, 25, 12] → Compare 64 & 25 → Swap → [34, 25, 64, 12]
[34, 25, 64, 12] → Compare 64 & 12 → Swap → [34, 25, 12, 64]
Result: [34, 25, 12, 64] (64 "bubbled" to the end!)

Pass 2:
[34, 25, 12, 64] → Compare 34 & 25 → Swap → [25, 34, 12, 64]
[25, 34, 12, 64] → Compare 34 & 12 → Swap → [25, 12, 34, 64]
[25, 12, 34, 64] → Compare 34 & 64 → No swap needed
Result: [25, 12, 34, 64] (34 bubbled to position!)

Continue until sorted: [12, 25, 34, 64]
```

### 💡 Key Concepts

**Why "Bubble"?**
- Large elements "bubble up" to their correct positions
- Like air bubbles rising to the surface of water

**Optimization:**
- Use a flag to detect if array is already sorted
- If no swaps happen in a pass, we're done!

### ⏱️ Performance Analysis

- **Best Case**: O(n) - already sorted array
- **Worst Case**: O(n²) - reverse sorted array
- **Space**: O(1) - only uses constant extra memory

### 👍 Pros & Cons

**Pros:**
- Very easy to understand and implement
- Works well for small datasets
- Stable (maintains relative order of equal elements)

**Cons:**
- Very slow for large datasets
- Many unnecessary comparisons

---

## 🟢 Algorithm 2: Selection Sort - The Organized One

### 🤔 What is Selection Sort?

Imagine you're organizing your bookshelf. You look through all books, find the shortest one, and put it in the first position. Then you look through the remaining books, find the shortest among them, and put it in the second position. Continue until done!

### 📖 How It Works (Step by Step)

**The Big Picture:**
- Find the minimum element in the unsorted part
- Swap it with the first element of unsorted part
- Move the boundary of sorted part one step right
- Repeat until entire array is sorted

**Visual Example:**
```
Array: [64, 25, 12, 22, 11]

Step 1: Find minimum in [64, 25, 12, 22, 11] → 11
        Swap with first element → [11, 25, 12, 22, 64]
        Sorted: [11] | Unsorted: [25, 12, 22, 64]

Step 2: Find minimum in [25, 12, 22, 64] → 12
        Swap with first of unsorted → [11, 12, 25, 22, 64]
        Sorted: [11, 12] | Unsorted: [25, 22, 64]

Step 3: Find minimum in [25, 22, 64] → 22
        Swap with first of unsorted → [11, 12, 22, 25, 64]
        Sorted: [11, 12, 22] | Unsorted: [25, 64]

Step 4: Find minimum in [25, 64] → 25
        Already in correct position → [11, 12, 22, 25, 64]
        Sorted: [11, 12, 22, 25] | Unsorted: [64]

Final: [11, 12, 22, 25, 64] ✅
```

### 💡 Key Concepts

**Selection Strategy:**
- Always select the minimum from unsorted portion
- Build sorted portion from left to right
- Each step places one element in its final position

**Why "Selection"?**
- We "select" the minimum element in each iteration

### ⏱️ Performance Analysis

- **All Cases**: O(n²) - always does the same number of comparisons
- **Space**: O(1) - only uses constant extra memory
- **Swaps**: O(n) - at most n swaps (better than bubble sort)

### 👍 Pros & Cons

**Pros:**
- Simple to understand and implement
- Performs well on small datasets
- Minimizes number of swaps
- Works well when memory writes are expensive

**Cons:**
- O(n²) complexity even for sorted arrays
- Not stable (can change relative order of equal elements)

---

## 🟡 Algorithm 3: Insertion Sort - The Card Player's Choice

### 🤔 What is Insertion Sort?

Think about how you arrange playing cards in your hand. You pick up cards one by one and insert each new card in its correct position among the cards you've already arranged. That's exactly how insertion sort works!

### 📖 How It Works (Step by Step)

**The Big Picture:**
- Start with second element (first is considered "sorted")
- Take current element and find its correct position in sorted part
- Shift larger elements to make space
- Insert current element in correct position
- Repeat for all elements

**Visual Example:**
```
Array: [5, 2, 4, 6, 1, 3]

Initial: [5] | [2, 4, 6, 1, 3]
         ↑     ↑
      sorted  unsorted

Step 1: Insert 2
        Compare 2 with 5 → 2 < 5, so shift 5 right
        [_, 5] → Insert 2 → [2, 5] | [4, 6, 1, 3]

Step 2: Insert 4
        Compare 4 with 5 → 4 < 5, so shift 5 right
        Compare 4 with 2 → 4 > 2, so insert after 2
        [2, 4, 5] | [6, 1, 3]

Step 3: Insert 6
        Compare 6 with 5 → 6 > 5, so insert after 5
        [2, 4, 5, 6] | [1, 3]

Step 4: Insert 1
        Compare 1 with 6 → shift 6 right
        Compare 1 with 5 → shift 5 right
        Compare 1 with 4 → shift 4 right
        Compare 1 with 2 → shift 2 right
        Insert 1 at beginning → [1, 2, 4, 5, 6] | [3]

Step 5: Insert 3
        Compare 3 with 6 → shift 6 right
        Compare 3 with 5 → shift 5 right
        Compare 3 with 4 → shift 4 right
        Compare 3 with 2 → 3 > 2, so insert after 2
        Final: [1, 2, 3, 4, 5, 6] ✅
```

### 💡 Key Concepts

**Insertion Strategy:**
- Maintain a sorted portion on the left
- Insert each new element in its correct position
- Shift elements to make room for insertion

**Why "Insertion"?**
- We "insert" each element into its correct position in the sorted part

### ⏱️ Performance Analysis

- **Best Case**: O(n) - already sorted array (just one comparison per element)
- **Worst Case**: O(n²) - reverse sorted array
- **Space**: O(1) - only uses constant extra memory

### 👍 Pros & Cons

**Pros:**
- Very efficient for small datasets
- Efficient for nearly sorted arrays
- Stable sorting algorithm
- Online algorithm (can sort as it receives data)
- Simple implementation

**Cons:**
- O(n²) complexity for large datasets
- More writes compared to selection sort

---

## 📊 Algorithm Comparison Table

| Algorithm | Best Case | Average Case | Worst Case | Space | Stable | When to Use |
|-----------|-----------|--------------|------------|-------|--------|-------------|
| **Rotate String** | O(n) | O(n) | O(n) | O(n) | N/A | String rotation detection |
| **Bubble Sort** | O(n) | O(n²) | O(n²) | O(1) | ✅ | Educational purposes, very small datasets |
| **Selection Sort** | O(n²) | O(n²) | O(n²) | O(1) | ❌ | When memory writes are expensive |
| **Insertion Sort** | O(n) | O(n²) | O(n²) | O(1) | ✅ | Small datasets, nearly sorted data |

---

## 🎮 Practice Exercises

### Exercise 1: String Rotation
- Test the concatenation method with different string pairs
- Implement the brute force approach and compare performance

### Exercise 2: Sorting Trace Through
- Manually trace through each sorting algorithm with array: `[3, 1, 4, 1, 5]`

### Exercise 3: Algorithm Modifications
- Change bubble sort to sort in descending order
- Modify selection sort to find maximum instead of minimum
- Adapt insertion sort for descending order

### Exercise 4: Performance Analysis
- Count the number of comparisons and swaps for each algorithm with array `[4, 3, 2, 1]`

---

## 🧠 Memory Tips

### String Rotation
**Remember**: "Double the string, find the rotation"
- All rotations appear as substrings in s + s

### Bubble Sort
**Remember**: "Bubbles rise to the surface"
- Large elements bubble up to the end

### Selection Sort
**Remember**: "Select the best candidate"
- Always select the minimum from remaining elements

### Insertion Sort
**Remember**: "Arranging cards in your hand"
- Insert each new card in its correct position

---

## 💡 Real-World Applications

### String Rotation
- Text processing and pattern matching
- Circular buffer implementations
- DNA sequence analysis

### Bubble Sort
- Educational tool for teaching sorting concepts
- Small embedded systems with memory constraints

### Selection Sort
- Systems where memory writes are expensive
- Finding k smallest/largest elements

### Insertion Sort
- Small datasets (< 50 elements)
- Nearly sorted data
- As a subroutine in hybrid algorithms (like Timsort)
- Online algorithms (sorting data as it arrives)

---

## 📊 Progress Summary

| Problem/Algorithm | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|-------------------|------------|--------|----------|-----------------|------------------|
| Rotate String | Easy | ✅ Solved | String Concatenation | O(n) | O(n) |
| Bubble Sort | Basic | ✅ Implemented | Adjacent Swapping | O(n²) | O(1) |
| Selection Sort | Basic | ✅ Implemented | Minimum Selection | O(n²) | O(1) |
| Insertion Sort | Basic | ✅ Implemented | Sorted Insertion | O(n²) | O(1) |

## 🎯 Key Learnings

1. **String Concatenation Trick**: Powerful technique for rotation detection problems
2. **Pattern Recognition**: Understanding how rotations appear as substrings and sorting patterns
3. **Algorithm Trade-offs**: Time vs Space vs Stability considerations
4. **Fundamental Concepts**: Building blocks for advanced algorithms
5. **Performance Analysis**: Understanding best, average, and worst-case scenarios

## 🚀 Next Steps

- Practice more string rotation and pattern matching problems
- Learn advanced sorting algorithms (Merge Sort, Quick Sort, Heap Sort)
- Study KMP algorithm for advanced string matching
- Understand stability importance in real applications
- Explore hybrid sorting algorithms

## 💡 Problem-Solving Tips

1. **Rotation Problems**: Consider the concatenation trick (s + s contains all rotations)
2. **Length Check**: Always verify equal lengths before processing
3. **Sorting Choice**: Choose algorithm based on data size and constraints
4. **Stability Matters**: Consider whether relative order of equal elements is important
5. **Early Optimization**: Use flags to detect already sorted data

---

**Total Problems/Algorithms Mastered**: 4

*Rotate, sort, and conquer! 🔄📊*
