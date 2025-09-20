# Day 37: Matrix Search Algorithms - Binary Search & Elimination

## 🎯 Learning Objectives

By the end of this day, you will master:
- **2D Matrix Binary Search**: Treating matrices as flattened 1D arrays for efficient searching
- **Index Conversion**: Converting between 1D and 2D coordinates in matrices
- **Matrix Elimination Strategy**: Using sorted properties to eliminate rows/columns
- **Search Space Reduction**: Optimizing search by leveraging matrix properties
- **Comparative Algorithm Analysis**: Understanding when to use different matrix search approaches

---

## Problems Overview: Matrix Search Techniques

### 📋 Problem Set

**Difficulty**: Medium  
**Category**: Binary Search, Matrix, Two Pointers  
**Companies**: Amazon, Microsoft, Google, Meta, Apple

This day covers two fundamental matrix search problems that demonstrate different approaches to searching in sorted 2D structures:

1. **LeetCode 74**: Search a 2D Matrix (Fully Sorted)
2. **LeetCode 240**: Search a 2D Matrix II (Row & Column Sorted)

---

## Problem 1: Search a 2D Matrix (LeetCode 74)

### 📋 Problem Statement

Write an efficient algorithm that searches for a target value in an `m x n` integer matrix. The matrix has the following properties:
- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

**Task**: Return `true` if target is found, `false` otherwise.

### 🔍 Problem Analysis

**Key Insights**:
- Matrix is **fully sorted** - can be treated as a single 1D sorted array
- Perfect candidate for **binary search** with O(log(m×n)) complexity
- Index conversion: `row = index / cols`, `col = index % cols`
- Maintains all properties of binary search on sorted arrays

**Matrix Structure Visualization**:
```
Matrix: [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
As 1D: [1,3,5,7,10,11,16,20,23,30,34,60]
Indices: 0 1 2 3 4  5  6  7  8  9  10 11

Index 5 → Row: 5/4 = 1, Col: 5%4 = 1 → matrix[1][1] = 11
Index 8 → Row: 8/4 = 2, Col: 8%4 = 0 → matrix[2][0] = 23
```

### 📚 Examples with Detailed Analysis

#### Example 1: Target Found
```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Step-by-step binary search:
1D representation: [1,3,5,7,10,11,16,20,23,30,34,60]
Indices:           [0,1,2,3,4, 5, 6, 7, 8, 9,10,11]

Step 1: s=0, e=11, mid=5
        matrix[5/4][5%4] = matrix[1][1] = 11
        11 > 3, so e = mid-1 = 4

Step 2: s=0, e=4, mid=2  
        matrix[2/4][2%4] = matrix[0][2] = 5
        5 > 3, so e = mid-1 = 1

Step 3: s=0, e=1, mid=0
        matrix[0/4][0%4] = matrix[0][0] = 1
        1 < 3, so s = mid+1 = 1

Step 4: s=1, e=1, mid=1
        matrix[1/4][1%4] = matrix[0][1] = 3
        3 == 3, FOUND! Return true
```

#### Example 2: Target Not Found
```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Binary search process:
Step 1: s=0, e=11, mid=5 → matrix[1][1]=11 < 13 → s=6
Step 2: s=6, e=11, mid=8 → matrix[2][0]=23 > 13 → e=7  
Step 3: s=6, e=7, mid=6  → matrix[1][2]=16 > 13 → e=5
Step 4: s=6, e=5 → s > e, exit loop
Result: false (target not found)
```

### 🔄 Solution Approach: Binary Search on Flattened Matrix

#### 💡 Core Idea
Treat the 2D matrix as a conceptual 1D sorted array and apply standard binary search, converting indices as needed.

#### 📊 Complexity Analysis
- **Time Complexity**: O(log(m × n))
  - m = number of rows, n = number of columns
  - Standard binary search on m×n elements
- **Space Complexity**: O(1) - only using constant extra variables

#### 🔍 Algorithm Steps
1. **Validation**: Check for empty matrix
2. **Initialize**: Set binary search bounds (0 to m×n-1)
3. **Search Loop**: While start ≤ end:
   - Calculate middle index
   - Convert to 2D coordinates
   - Compare with target and adjust bounds
4. **Return**: True if found, false otherwise

---

## Problem 2: Search a 2D Matrix II (LeetCode 240)

### 📋 Problem Statement

Write an efficient algorithm that searches for a target value in an `m x n` integer matrix. The matrix has the following properties:
- Integers in each row are sorted in ascending order from left to right.
- Integers in each column are sorted in ascending order from top to bottom.

**Task**: Return `true` if target is found, `false` otherwise.

### 🔍 Problem Analysis

**Key Insights**:
- Matrix is **partially sorted** - rows and columns individually sorted
- Cannot treat as single 1D array (elements between rows aren't ordered)
- **Elimination strategy** works best: start from corner and eliminate rows/columns
- Top-right or bottom-left corners provide optimal elimination paths

**Matrix Structure Visualization**:
```
Matrix: [[1,4,7,11,15],
         [2,5,8,12,19],
         [3,6,9,16,22],
         [10,13,14,17,24],
         [18,21,23,26,30]]

Starting from top-right (15):
- If current > target: move left (eliminate column)
- If current < target: move down (eliminate row)
- If current = target: found!
```

### 📚 Examples with Detailed Analysis

#### Example 1: Target Found
```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Step-by-step elimination from top-right:
Initial position: row=0, col=4 (value=15)

Step 1: matrix[0][4] = 15 > 5
        Move left: col = 3
        Position: row=0, col=3 (value=11)

Step 2: matrix[0][3] = 11 > 5  
        Move left: col = 2
        Position: row=0, col=2 (value=7)

Step 3: matrix[0][2] = 7 > 5
        Move left: col = 1  
        Position: row=0, col=1 (value=4)

Step 4: matrix[0][1] = 4 < 5
        Move down: row = 1
        Position: row=1, col=1 (value=5)

Step 5: matrix[1][1] = 5 == 5
        FOUND! Return true
```

#### Example 2: Target Not Found
```
Input: Same matrix, target = 20
Output: false

Elimination process:
Start: row=0, col=4 (value=15)
Step 1: 15 < 20 → move down → row=1, col=4 (value=19)
Step 2: 19 < 20 → move down → row=2, col=4 (value=22)  
Step 3: 22 > 20 → move left → row=2, col=3 (value=16)
Step 4: 16 < 20 → move down → row=3, col=3 (value=17)
Step 5: 17 < 20 → move down → row=4, col=3 (value=26)
Step 6: 26 > 20 → move left → row=4, col=2 (value=23)
Step 7: 23 > 20 → move left → row=4, col=1 (value=21)
Step 8: 21 > 20 → move left → row=4, col=0 (value=18)
Step 9: 18 < 20 → move down → row=5 (out of bounds)
Result: false (target not found)
```

### 🔄 Solution Approach: Corner Elimination Strategy

#### 💡 Core Idea
Start from top-right corner and eliminate entire rows or columns based on comparison with target.

#### 📊 Complexity Analysis
- **Time Complexity**: O(m + n)
  - m = number of rows, n = number of columns
  - At most m+n steps (each step eliminates a row or column)
- **Space Complexity**: O(1) - only using constant extra variables

#### 🔍 Algorithm Steps
1. **Validation**: Check for empty matrix
2. **Initialize**: Start from top-right corner (row=0, col=n-1)
3. **Elimination Loop**: While within bounds:
   - If current = target: return true
   - If current > target: move left (eliminate column)
   - If current < target: move down (eliminate row)
4. **Return**: False if bounds exceeded

---

## 📖 Complete Guide to Matrix Operations

### 1. Index Conversion in Matrices 🔄

**Purpose**: Convert between 1D array indices and 2D matrix coordinates.

**Formulas**:
```cpp
// 1D to 2D conversion
int row = index / cols;
int col = index % cols;

// 2D to 1D conversion  
int index = row * cols + col;
```

**Detailed Examples**:
```cpp
// Matrix: 3×4 (3 rows, 4 columns)
// [[0, 1, 2, 3],
//  [4, 5, 6, 7], 
//  [8, 9,10,11]]

int cols = 4;

// Convert 1D index 5 to 2D
int row = 5 / 4 = 1;    // Row 1 (0-indexed)
int col = 5 % 4 = 1;    // Column 1 (0-indexed)
// Result: matrix[1][1] = 5 ✓

// Convert 1D index 10 to 2D  
int row = 10 / 4 = 2;   // Row 2
int col = 10 % 4 = 2;   // Column 2
// Result: matrix[2][2] = 10 ✓

// Convert 2D coordinate (2,3) to 1D
int index = 2 * 4 + 3 = 11;
// Result: matrix[2][3] is at index 11 ✓
```

**Important Notes**:
- Division gives row number (how many complete rows fit)
- Modulo gives column position within the row
- Works for any rectangular matrix dimensions

### 2. Matrix Boundary Checking 🚧

**Purpose**: Prevent array out-of-bounds errors when navigating matrices.

**Common Patterns**:
```cpp
// Check if position is valid
bool isValid(int row, int col, int rows, int cols) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

// Safe matrix access
if (row < matrix.size() && col < matrix[0].size()) {
    int value = matrix[row][col];
}

// Loop with bounds checking
while (row >= 0 && row < matrix.size() && 
       col >= 0 && col < matrix[0].size()) {
    // Process matrix[row][col]
    // Update row and col
}
```

### 3. Matrix Search Patterns 🔍

**Pattern 1: Binary Search (Fully Sorted Matrix)**
```cpp
// When: Matrix sorted row-wise AND column-wise globally
// Time: O(log(m×n)), Space: O(1)
bool searchFullySorted(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = m * n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / n][mid % n];
        
        if (midValue == target) return true;
        else if (midValue < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}
```

**Pattern 2: Corner Elimination (Partially Sorted Matrix)**
```cpp
// When: Rows sorted, columns sorted, but not globally sorted
// Time: O(m+n), Space: O(1)
bool searchPartiallySorted(vector<vector<int>>& matrix, int target) {
    int row = 0, col = matrix[0].size() - 1;
    
    while (row < matrix.size() && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] > target) col--;
        else row++;
    }
    return false;
}
```

**Pattern 3: Linear Search (Unsorted Matrix)**
```cpp
// When: No sorting guarantees
// Time: O(m×n), Space: O(1)
bool searchUnsorted(vector<vector<int>>& matrix, int target) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == target) return true;
        }
    }
    return false;
}
```

---

## 🔬 Algorithm Deep Dive

### Visual Comparison: LeetCode 74 vs 240

```
LeetCode 74 Matrix (Fully Sorted):
[[ 1,  3,  5,  7],     ← Each row sorted
 [10, 11, 16, 20],     ← First element > previous row's last
 [23, 30, 34, 60]]     ← Can treat as: [1,3,5,7,10,11,16,20,23,30,34,60]

Search for 16:
Binary Search: O(log(12)) = ~3.6 steps
Step 1: mid=5 → matrix[1][1]=11 < 16 → search right half
Step 2: mid=8 → matrix[2][0]=23 > 16 → search left half  
Step 3: mid=6 → matrix[1][2]=16 = 16 → FOUND!

---

LeetCode 240 Matrix (Partially Sorted):
[[ 1,  4,  7, 11, 15],  ← Each row sorted
 [ 2,  5,  8, 12, 19],  ← Each column sorted
 [ 3,  6,  9, 16, 22],  ← But NOT globally sorted
 [10, 13, 14, 17, 24],  ← Cannot treat as 1D array
 [18, 21, 23, 26, 30]]

Search for 16:
Corner Elimination: O(5+5) = O(10) steps max
Start at top-right (15): 15 < 16 → move down
Position (19): 19 > 16 → move left
Position (12): 12 < 16 → move down  
Position (16): 16 = 16 → FOUND!
```

### Performance Analysis

| Aspect | LeetCode 74 | LeetCode 240 |
|--------|-------------|--------------|
| **Matrix Type** | Fully Sorted | Partially Sorted |
| **Search Strategy** | Binary Search | Corner Elimination |
| **Time Complexity** | O(log(m×n)) | O(m + n) |
| **Space Complexity** | O(1) | O(1) |
| **Best Case** | O(1) | O(1) |
| **Worst Case** | O(log(m×n)) | O(m + n) |
| **When to Use** | Globally sorted matrices | Row/column sorted matrices |

---

## 🧪 Comprehensive Testing

### Test Cases for LeetCode 74

```cpp
// Test Case 1: Target exists in middle
searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]], 11) → true

// Test Case 2: Target doesn't exist
searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]], 13) → false

// Test Case 3: Target at boundaries
searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]], 1) → true   // First element
searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]], 60) → true  // Last element

// Test Case 4: Single element matrix
searchMatrix([[1]], 1) → true
searchMatrix([[1]], 2) → false

// Test Case 5: Single row matrix
searchMatrix([[1,3,5,7]], 5) → true
searchMatrix([[1,3,5,7]], 4) → false

// Test Case 6: Single column matrix
searchMatrix([[1],[3],[5]], 3) → true
searchMatrix([[1],[3],[5]], 2) → false
```

### Test Cases for LeetCode 240

```cpp
// Test Case 1: Target exists
searchMatrix([[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], 5) → true

// Test Case 2: Target doesn't exist  
searchMatrix([[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], 20) → false

// Test Case 3: Target at corners
searchMatrix([[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], 1) → true   // Top-left
searchMatrix([[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], 30) → true  // Bottom-right
searchMatrix([[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], 15) → true  // Top-right
searchMatrix([[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], 18) → true  // Bottom-left

// Test Case 4: Single element
searchMatrix([[5]], 5) → true
searchMatrix([[5]], 3) → false

// Test Case 5: Duplicate elements
searchMatrix([[1,2,3],[2,3,4],[3,4,5]], 3) → true
```

### Edge Cases Analysis

#### 1. **Empty and Invalid Inputs**
```cpp
// Empty matrix
searchMatrix([], target) → false

// Matrix with empty rows  
searchMatrix([[]], target) → false

// Very large target
searchMatrix([[1,2],[3,4]], 1000) → false

// Very small target
searchMatrix([[1,2],[3,4]], -1000) → false
```

#### 2. **Matrix Size Variations**
```cpp
// 1×1 matrix
searchMatrix([[x]], target) → (x == target)

// 1×n matrix (single row)
searchMatrix([[1,2,3,4,5]], target) → binary search behavior

// n×1 matrix (single column)  
searchMatrix([[1],[2],[3],[4],[5]], target) → linear search behavior

// Large matrix (stress test)
// 1000×1000 matrix with target at various positions
```

#### 3. **Boundary Value Testing**
```cpp
// Target equals matrix boundaries
searchMatrix(matrix, matrix[0][0])                    → true  // Top-left
searchMatrix(matrix, matrix[m-1][n-1])               → true  // Bottom-right
searchMatrix(matrix, matrix[0][0] - 1)               → false // Below minimum
searchMatrix(matrix, matrix[m-1][n-1] + 1)           → false // Above maximum
```

---

## 📊 Alternative Approaches and Optimizations

### Approach 1: Row-by-Row Binary Search (LeetCode 240)
```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (auto& row : matrix) {
        if (binary_search(row.begin(), row.end(), target)) {
            return true;
        }
    }
    return false;
}
```
**Time**: O(m × log n), **Space**: O(1)  
**Pros**: Simple implementation  
**Cons**: Slower than corner elimination for large matrices

### Approach 2: Divide and Conquer (LeetCode 240)
```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    return searchHelper(matrix, target, 0, 0, matrix.size()-1, matrix[0].size()-1);
}

bool searchHelper(vector<vector<int>>& matrix, int target, 
                  int r1, int c1, int r2, int c2) {
    if (r1 > r2 || c1 > c2) return false;
    
    int midRow = (r1 + r2) / 2;
    int midCol = (c1 + c2) / 2;
    
    if (matrix[midRow][midCol] == target) return true;
    else if (matrix[midRow][midCol] > target) {
        return searchHelper(matrix, target, r1, c1, midRow-1, c2) ||
               searchHelper(matrix, target, midRow, c1, r2, midCol-1);
    } else {
        return searchHelper(matrix, target, r1, midCol+1, r2, c2) ||
               searchHelper(matrix, target, midRow+1, c1, r2, midCol);
    }
}
```
**Time**: O(n^1.58), **Space**: O(log n)  
**Pros**: Elegant recursive solution  
**Cons**: More complex, higher space complexity

### Approach 3: Bottom-Left Start (LeetCode 240)
```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size() - 1;  // Start from bottom-left
    int col = 0;
    
    while (row >= 0 && col < matrix[0].size()) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] > target) row--;  // Move up
        else col++;  // Move right
    }
    return false;
}
```
**Time**: O(m + n), **Space**: O(1)  
**Pros**: Alternative corner approach  
**Cons**: Same complexity as top-right approach

---

## 🎯 Key Learning Points

### ✅ **Matrix Search Strategy Selection**

#### **When to Use Binary Search (LeetCode 74 approach)**:
```cpp
// ✅ Good for: Fully sorted matrices
if (matrix_is_globally_sorted) {
    use_binary_search();  // O(log(m×n))
}

// Matrix properties required:
// 1. Each row sorted left to right
// 2. First element of row > last element of previous row
// 3. Can be treated as single 1D sorted array
```

#### **When to Use Corner Elimination (LeetCode 240 approach)**:
```cpp
// ✅ Good for: Partially sorted matrices  
if (rows_sorted && columns_sorted && !globally_sorted) {
    use_corner_elimination();  // O(m + n)
}

// Matrix properties required:
// 1. Each row sorted left to right
// 2. Each column sorted top to bottom  
// 3. No global ordering between rows
```

### ✅ **Index Conversion Mastery**

#### **Critical Formulas**:
```cpp
// ✅ 1D to 2D conversion
int row = index / total_columns;
int col = index % total_columns;

// ✅ 2D to 1D conversion
int index = row * total_columns + col;

// ✅ Bounds checking
bool valid = (row >= 0 && row < rows && col >= 0 && col < cols);
```

#### **Common Pitfalls to Avoid**:
```cpp
// ❌ Wrong: Using rows instead of columns for conversion
int row = index / total_rows;  // INCORRECT

// ❌ Wrong: Forgetting bounds checking
int value = matrix[row][col];  // May cause segfault

// ✅ Correct: Always validate before access
if (row < matrix.size() && col < matrix[0].size()) {
    int value = matrix[row][col];
}
```

### ✅ **Algorithm Complexity Understanding**

#### **Time Complexity Comparison**:
```
Problem Size: m×n matrix

Linear Search:     O(m × n)     - Check every element
Row Binary Search: O(m × log n) - Binary search each row  
Binary Search:     O(log(m×n))  - Single binary search (LeetCode 74)
Corner Elimination: O(m + n)    - Eliminate rows/columns (LeetCode 240)

For 1000×1000 matrix:
Linear:       1,000,000 operations
Row Binary:   ~10,000 operations  
Binary:       ~20 operations
Corner:       ~2,000 operations
```

---

## 📏 Constraints and Implications

**Given Constraints:**
- `m == matrix.length`
- `n == matrix[i].length`  
- `1 ≤ m, n ≤ 100`
- `-10^4 ≤ matrix[i][j], target ≤ 10^4`

**Constraint Analysis:**
```
Small to Medium Matrices: up to 100×100 = 10,000 elements
→ All approaches (O(log n), O(m+n), O(mn)) are feasible
→ Focus on correctness and code clarity over micro-optimizations

Integer Range: -10^4 to 10^4
→ No overflow concerns with standard int operations
→ No special handling needed for extreme values

Matrix Dimensions: At least 1×1
→ No need to handle completely empty matrices
→ Single element matrices are valid edge cases
```

---

## 🚀 Advanced Topics and Extensions

### 1. **Matrix Search Variations**
- **Rotated Sorted Matrix**: Search in matrices rotated by 90/180/270 degrees
- **Sparse Matrix Search**: Optimized search for matrices with many zeros
- **Multi-dimensional Arrays**: Extending search to 3D+ structures

### 2. **Related Algorithms**
- **KD-Trees**: For multi-dimensional range searching
- **Quad-trees**: For 2D spatial data structures
- **Range Trees**: For orthogonal range queries

### 3. **Related LeetCode Problems**
- **LeetCode 378**: Kth Smallest Element in a Sorted Matrix
- **LeetCode 668**: Kth Smallest Number in Multiplication Table
- **LeetCode 719**: Find K-th Smallest Pair Distance
- **LeetCode 786**: K-th Smallest Prime Fraction

### 4. **Real-World Applications**
- **Image Processing**: Searching for patterns in pixel matrices
- **Game Development**: Pathfinding in grid-based games
- **Data Analysis**: Searching in structured datasets
- **Computer Graphics**: Texture and sprite lookup operations

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Search a 2D Matrix (74) | Medium | ✅ Solved | Binary Search | O(log(m×n)) | O(1) |
| Search a 2D Matrix II (240) | Medium | ✅ Solved | Corner Elimination | O(m + n) | O(1) |

## 🎯 Key Learnings Achieved

### ✅ **Matrix Search Algorithm Mastery**
- **Binary Search on Matrices**: Converting 2D problems to 1D for optimal searching
- **Index Conversion**: Seamless translation between 1D and 2D coordinates
- **Corner Elimination**: Strategic row/column elimination for partially sorted matrices
- **Algorithm Selection**: Choosing optimal approach based on matrix properties

### ✅ **Problem-Solving Pattern Recognition**
- **Fully vs Partially Sorted**: Identifying matrix sorting characteristics
- **Search Space Reduction**: Leveraging sorted properties to eliminate possibilities
- **Boundary Handling**: Robust edge case management in matrix operations
- **Complexity Trade-offs**: Understanding when different approaches are optimal

---

**Total Problems Solved**: 27/∞

*Master matrix algorithms, master structured data search! 🔍*
