/**
 * ================================================================================
 * LeetCode 74: Search a 2D Matrix - Binary Search on Virtual 1D Array
 * ================================================================================
 * 
 * ! Problem: Given an m x n integer matrix with the following properties:
 * ! - Integers in each row are sorted from left to right
 * ! - The first integer of each row is greater than the last integer of the previous row
 * ! Search for a target value and return true if found, false otherwise.
 * 
 * * Approach:
 * * 1. Treat the 2D matrix as a virtual 1D sorted array
 * * 2. Apply binary search on this virtual array
 * * 3. Convert 1D index to 2D coordinates using:
 * *    - row = index / number_of_columns
 * *    - col = index % number_of_columns
 * * 4. Compare middle element with target and adjust search space
 * 
 * ? Time Complexity: O(log(m × n)) - Binary search on m×n elements
 * ? Space Complexity: O(1) - Constant extra space used
 * 
 * TODO Key Insight: 
 * *    - The matrix properties allow us to treat it as a single sorted array
 * *    - This enables efficient O(log(m×n)) search instead of O(m+n)
 * *    - Index conversion: mid/col gives row, mid%col gives column
 * 
 * * Optimizations: 
 * *    - Single binary search instead of two separate searches
 * *    - Direct index-to-coordinate mapping eliminates extra calculations
 * ================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Searches for target in a 2D matrix using binary search
     * @param matrix A 2D vector with sorted rows and columns
     * @param target The value to search for
     * @return true if target is found, false otherwise
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();        // * Number of rows in matrix
        int col = matrix[0].size();     // * Number of columns in matrix

        int s = 0;                      // * Start of search space
        int e = row * col - 1;          // * End of search space (total elements - 1)

        int mid = s + (e - s) / 2;      // * Middle index (prevents overflow)

        while (s <= e) {
            // ! Convert 1D index 'mid' to 2D coordinates
            // ? mid / col gives the row index
            // ? mid % col gives the column index
            int cell = matrix[mid / col][mid % col];

            if (cell == target)
                return 1;               // * Target found!

            if (cell > target)
                e = mid - 1;            // * Search in left half
            else
                s = mid + 1;            // * Search in right half
            
            mid = s + (e - s) / 2;      // * Recalculate middle
        }
        return 0;                       // * Target not found
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
    
    // * Test Case 1: Target exists in middle
    {
        vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
        int target = 3;
        bool result = solution.searchMatrix(matrix, target);
        printTestResult(matrix, target, result, true);
    }
    
    // * Test Case 2: Target doesn't exist
    {
        vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
        int target = 13;
        bool result = solution.searchMatrix(matrix, target);
        printTestResult(matrix, target, result, false);
    }
    
    // * Test Case 3: Target at first position
    {
        vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
        int target = 1;
        bool result = solution.searchMatrix(matrix, target);
        printTestResult(matrix, target, result, true);
    }
    
    // * Test Case 4: Target at last position
    {
        vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
        int target = 60;
        bool result = solution.searchMatrix(matrix, target);
        printTestResult(matrix, target, result, true);
    }
    
    // * Test Case 5: Single row matrix
    {
        vector<vector<int>> matrix = {{1, 3, 5, 7}};
        int target = 5;
        bool result = solution.searchMatrix(matrix, target);
        printTestResult(matrix, target, result, true);
    }
    
    // * Test Case 6: Single column matrix
    {
        vector<vector<int>> matrix = {{1}, {3}, {5}, {7}};
        int target = 3;
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
    
    // ! Test Case 8: Single element matrix - target absent
    {
        vector<vector<int>> matrix = {{5}};
        int target = 1;
        bool result = solution.searchMatrix(matrix, target);
        printTestResult(matrix, target, result, false);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The solution leverages the sorted property of the matrix to achieve logarithmic time
 * ! - Index conversion is crucial: row = mid/col, column = mid%col
 * * - Works efficiently for matrices where rows are strictly increasing
 * ? - For matrices with different properties, consider the staircase search approach
 * ================================================================================
 */