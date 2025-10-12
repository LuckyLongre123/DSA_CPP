/**
 * ================================================================================
 * LeetCode 54: Spiral Matrix - Matrix Traversal
 * ================================================================================
 * 
 * ! Problem: Given an m x n matrix, return all elements of the matrix in spiral order.
 * ! The spiral order means traversing the matrix layer by layer from outside to inside,
 * ! moving in a clockwise direction: right → down → left → up, then repeat.
 * 
 * * Approach:
 * * 1. Define four boundaries: startingRow, endingRow, startingCol, endingCol
 * * 2. Process matrix layer by layer in spiral order:
 * *    - Traverse top row from left to right
 * *    - Traverse right column from top to bottom
 * *    - Traverse bottom row from right to left
 * *    - Traverse left column from bottom to top
 * * 3. After each direction, update the corresponding boundary
 * * 4. Continue until all elements are processed
 * 
 * ? Time Complexity: O(m × n) - We visit each element exactly once
 * ? Space Complexity: O(1) - Excluding the output array, constant extra space used
 * 
 * TODO Key Insight: 
 * *    - The main challenge is handling boundary conditions and avoiding duplicates
 * *    - We must check count < totalElm in each loop to prevent revisiting elements
 * *    - After processing each direction, we shrink the corresponding boundary
 * 
 * * Optimizations: 
 * *    - Single pass through all elements
 * *    - Layer-by-layer processing ensures no element is visited twice
 * ================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Returns all elements of the matrix in spiral order
     * @param matrix The input m x n 2D matrix
     * @return Vector containing all elements in spiral traversal order
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;  // * Stores the result in spiral order
        int row = matrix.size();  // * Number of rows
        int col = matrix[0].size();  // * Number of columns
        
        int count = 0;  // * Tracks number of elements processed
        int totalElm = row * col;  // * Total elements to process
        
        // * Initialize four boundaries for the current layer
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;
        
        while (count < totalElm) {
            // ! DIRECTION 1: Traverse top row from left to right
            // ? Process elements in current startingRow from startingCol to endingCol
            for (int i = startingCol; count < totalElm && i <= endingCol; i++) {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;  // * Move top boundary down
            
            // ! DIRECTION 2: Traverse right column from top to bottom
            // ? Process elements in current endingCol from startingRow to endingRow
            for (int i = startingRow; count < totalElm && i <= endingRow; i++) {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;  // * Move right boundary left
            
            // ! DIRECTION 3: Traverse bottom row from right to left
            // ? Process elements in current endingRow from endingCol to startingCol
            for (int i = endingCol; count < totalElm && i >= startingCol; i--) {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;  // * Move bottom boundary up
            
            // ! DIRECTION 4: Traverse left column from bottom to top
            // ? Process elements in current startingCol from endingRow to startingRow
            for (int i = endingRow; count < totalElm && i >= startingRow; i--) {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;  // * Move left boundary right
        }
        
        return ans;
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print matrix
 */
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        cout << "[ ";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "]\n";
    }
}

/**
 * Helper function to print vector
 */
void printVector(const vector<int>& vec) {
    cout << "[ ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << "]\n";
}

/**
 * Helper function to print test result
 */
void printTestResult(int testNum, const vector<int>& result, const vector<int>& expected) {
    cout << "\n--- Test Case " << testNum << " ---\n";
    cout << "Result:   ";
    printVector(result);
    cout << "Expected: ";
    printVector(expected);
    bool pass = (result == expected);
    cout << "Status:   " << (pass ? "PASS ✓" : "FAIL ✗") << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Standard 3x3 matrix
    {
        vector<vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        cout << "\nTest Case 1: 3x3 Matrix\n";
        printMatrix(matrix);
        vector<int> result = solution.spiralOrder(matrix);
        vector<int> expected = {1, 2, 3, 6, 9, 8, 7, 4, 5};
        printTestResult(1, result, expected);
    }
    
    // * Test Case 2: Rectangular matrix (3x4)
    {
        vector<vector<int>> matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        };
        cout << "\nTest Case 2: 3x4 Matrix\n";
        printMatrix(matrix);
        vector<int> result = solution.spiralOrder(matrix);
        vector<int> expected = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
        printTestResult(2, result, expected);
    }
    
    // * Test Case 3: Single row matrix
    {
        vector<vector<int>> matrix = {{1, 2, 3, 4}};
        cout << "\nTest Case 3: Single Row (1x4)\n";
        printMatrix(matrix);
        vector<int> result = solution.spiralOrder(matrix);
        vector<int> expected = {1, 2, 3, 4};
        printTestResult(3, result, expected);
    }
    
    // * Test Case 4: Single column matrix
    {
        vector<vector<int>> matrix = {
            {1},
            {2},
            {3},
            {4}
        };
        cout << "\nTest Case 4: Single Column (4x1)\n";
        printMatrix(matrix);
        vector<int> result = solution.spiralOrder(matrix);
        vector<int> expected = {1, 2, 3, 4};
        printTestResult(4, result, expected);
    }
    
    // * Test Case 5: Single element matrix
    {
        vector<vector<int>> matrix = {{5}};
        cout << "\nTest Case 5: Single Element (1x1)\n";
        printMatrix(matrix);
        vector<int> result = solution.spiralOrder(matrix);
        vector<int> expected = {5};
        printTestResult(5, result, expected);
    }
    
    // * Test Case 6: Larger rectangular matrix (4x3)
    {
        vector<vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {10, 11, 12}
        };
        cout << "\nTest Case 6: 4x3 Matrix\n";
        printMatrix(matrix);
        vector<int> result = solution.spiralOrder(matrix);
        vector<int> expected = {1, 2, 3, 6, 9, 12, 11, 10, 7, 4, 5, 8};
        printTestResult(6, result, expected);
    }
    
    // * Test Case 7: 2x2 matrix (smallest multi-element)
    {
        vector<vector<int>> matrix = {
            {1, 2},
            {3, 4}
        };
        cout << "\nTest Case 7: 2x2 Matrix\n";
        printMatrix(matrix);
        vector<int> result = solution.spiralOrder(matrix);
        vector<int> expected = {1, 2, 4, 3};
        printTestResult(7, result, expected);
    }
    
    // * Test Case 8: Large 5x5 matrix with negative numbers
    {
        vector<vector<int>> matrix = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}
        };
        cout << "\nTest Case 8: 5x5 Matrix\n";
        printMatrix(matrix);
        vector<int> result = solution.spiralOrder(matrix);
        vector<int> expected = {1, 2, 3, 4, 5, 10, 15, 20, 25, 24, 23, 22, 21, 16, 11, 6, 7, 8, 9, 14, 19, 18, 17, 12, 13};
        printTestResult(8, result, expected);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The solution handles all edge cases: single row, single column, 1x1 matrix
 * ! - The count < totalElm check in each loop prevents processing elements twice
 * * - Boundaries are updated after each direction to shrink the layer
 * ? - For empty matrix handling, add check: if (matrix.empty() || matrix[0].empty())
 * * - This pattern is useful for other matrix traversal problems
 * ================================================================================
 */