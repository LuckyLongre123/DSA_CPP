/**
 * ================================================================================
 * LeetCode 240: Search a 2D Matrix II - Staircase Search Algorithm
 * ================================================================================
 * 
 * ! Problem: Given an m x n integer matrix with the following properties:
 * ! - Integers in each row are sorted in ascending order from left to right
 * ! - Integers in each column are sorted in ascending order from top to bottom
 * ! Search for a target value and return true if found, false otherwise.
 * 
 * * Approach:
 * * 1. Start from the top-right corner of the matrix
 * * 2. If current element equals target, return true
 * * 3. If current element is greater than target, move left (eliminate column)
 * * 4. If current element is less than target, move down (eliminate row)
 * * 5. Repeat until target is found or boundaries are exceeded
 * 
 * ? Time Complexity: O(m + n) - At most m+n steps (each step eliminates a row or column)
 * ? Space Complexity: O(1) - Constant extra space used
 * 
 * TODO Key Insight: 
 * *    - Starting from top-right creates a "staircase" search pattern
 * *    - Each comparison eliminates either an entire row or column
 * *    - This is optimal for matrices where rows AND columns are sorted
 * *    - Alternative starting point: bottom-left (same complexity)
 * 
 * * Optimizations: 
 * *    - No additional data structures needed
 * *    - Each element is visited at most once
 * *    - Works even when rows don't strictly increase across row boundaries
 * ================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Searches for target in a 2D matrix using staircase algorithm
     * @param matrix A 2D vector with sorted rows and sorted columns
     * @param target The value to search for
     * @return true if target is found, false otherwise
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();        // * Number of rows in matrix
        int col = matrix[0].size();     // * Number of columns in matrix

        int rowIndex = 0;               // * Start from the top row
        int colIndex = col - 1;         // * Start from the rightmost column

        // ! Staircase search: move down or left based on comparison
        while (rowIndex < row && colIndex >= 0) {
            int cell = matrix[rowIndex][colIndex];  // * Current element
            
            if (cell == target)
                return 1;               // * Target found!

            if (cell < target)
                rowIndex++;             // * Current element too small, move down
            else
                colIndex--;             // * Current element too large, move left
        }
        return 0;                       // * Target not found after exhausting search space
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print matrix
 */
void printMatrix(vector<vector<int>>& matrix) {
    cout << "[\n";
    for (auto& row : matrix) {
        cout << "  [";
        for (int i = 0; i < row.size(); i++) {
            cout << row[i];
            if (i < row.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}

/**
 * Helper function to print test result
 */
void printTestResult(vector<vector<int>>& matrix, int target, bool result, bool expected) {
    cout << "\nMatrix:\n";
    printMatrix(matrix);
    cout << "Target: " << target << "\n";
    cout << "   Result:   " << (result ? "true" : "false") << "\n";
    cout << "   Expected: " << (expected ? "true" : "false") << "\n";
    cout << "   Status:   " << (result == expected ? "PASS" : "FAIL");
    if (result != expected) {
        cout << " (Expected: " << (expected ? "true" : "false") << ")";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Target exists in matrix (LeetCode Example 1)
    {
        vector<vector<int>> matrix = {
            {1, 4, 7, 11, 15},
            {2, 5, 8, 12, 19},
            {3, 6, 9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
        };
        int target = 5;
        bool result = solution.searchMatrix(matrix, target);
        printTestResult(matrix, target, result, true);
    }
    
    // * Test Case 2: Target doesn't exist (LeetCode Example 2)
    {
        vector<vector<int>> matrix = {
            {1, 4, 7, 11, 15},
            {2, 5, 8, 12, 19},
            {3, 6, 9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
        };
        int target = 20;
        bool result = solution.searchMatrix(matrix, target);
        printTestResult(matrix, target, result, false);
    }
    
    // * Test Case 3: Target at top-right corner
    {
        vector<vector<int>> matrix = {
            {1, 4, 7, 11, 15},
            {2, 5, 8, 12, 19},
            {3, 6, 9, 16, 22}
        };
        int target = 15;
        bool result = solution.searchMatrix(matrix, target);
        printTestResult(matrix, target, result, true);
    }
    
    // * Test Case 4: Target at bottom-left corner
    {
        vector<vector<int>> matrix = {
            {1, 4, 7, 11, 15},
            {2, 5, 8, 12, 19},
            {3, 6, 9, 16, 22}
        };
        int target = 3;
        bool result = solution.searchMatrix(matrix, target);
        printTestResult(matrix, target, result, true);
    }
    
    // * Test Case 5: Single row matrix
    {
        vector<vector<int>> matrix = {{1, 3, 5, 7, 9}};
        int target = 5;
        bool result = solution.searchMatrix(matrix, target);
        printTestResult(matrix, target, result, true);
    }
    
    // * Test Case 6: Single column matrix
    {
        vector<vector<int>> matrix = {{1}, {3}, {5}, {7}, {9}};
        int target = 7;
        bool result = solution.searchMatrix(matrix, target);
        printTestResult(matrix, target, result, true);
    }
    
    // ! Test Case 7: Single element matrix - target present
    {
        vector<vector<int>> matrix = {{5}};
        int target = 5;
        bool result = solution.searchMatrix(matrix, target);
        printTestResult(matrix, target, result, true);
    }
    
    // ! Test Case 8: Target smaller than all elements
    {
        vector<vector<int>> matrix = {
            {5, 8, 10},
            {7, 9, 12},
            {11, 13, 15}
        };
        int target = 1;
        bool result = solution.searchMatrix(matrix, target);
        printTestResult(matrix, target, result, false);
    }
    
    // ! Test Case 9: Target larger than all elements
    {
        vector<vector<int>> matrix = {
            {1, 3, 5},
            {2, 4, 6},
            {7, 8, 9}
        };
        int target = 100;
        bool result = solution.searchMatrix(matrix, target);
        printTestResult(matrix, target, result, false);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The staircase algorithm is more flexible than binary search for this problem
 * ! - Works for matrices where rows are sorted AND columns are sorted independently
 * * - Can start from top-right (shown) or bottom-left (symmetric approach)
 * ? - Cannot start from top-left or bottom-right (ambiguous elimination direction)
 * * - Each step eliminates exactly one row or one column from consideration
 * ================================================================================
 */