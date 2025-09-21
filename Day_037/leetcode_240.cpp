#include <vector>
using namespace std;

/*
================================================================================
LeetCode 240: Search a 2D Matrix II
================================================================================
🔹 Problem Description:
Write an efficient algorithm that searches for a target value in an m x n integer
matrix. The matrix has the following properties:
- Integers in each row are sorted in ascending order from left to right.
- Integers in each column are sorted in ascending order from top to bottom.

--------------------------------------------------------------------------------
Examples:
Input:  matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Input:  matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false

================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 Idea: Start from Top-Right Corner
1. Start from the top-right corner of the matrix.
2. If current element equals target, return true.
3. If current element is greater than target, move left (eliminate column).
4. If current element is less than target, move down (eliminate row).
5. Continue until target is found or boundaries are exceeded.

⏱ Time Complexity: O(m + n)
   - m = number of rows
   - n = number of columns
📦 Space Complexity: O(1) (only using constant extra space)
================================================================================
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Step 1: Handle edge cases
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        // Step 2: Initialize pointers - start from top-right corner
        int row = 0;                    // Start from first row
        int col = matrix[0].size() - 1; // Start from last column
        
        // Step 3: Search using elimination strategy
        while (row < matrix.size() && col >= 0) {
            int current = matrix[row][col];
            
            // Found the target
            if (current == target) {
                return true;
            }
            // Current element is greater than target
            // Move left to eliminate this column
            else if (current > target) {
                col--;
            }
            // Current element is less than target
            // Move down to eliminate this row
            else {
                row++;
            }
        }
        
        // Step 4: Target not found
        return false;
    }
};

// ==================== Driver Code for Testing ====================
#include <iostream>
int main() {
    Solution obj;
    
    // Test Case 1: Target exists
    vector<vector<int>> matrix1 = {
        {1,  4,  7,  11, 15},
        {2,  5,  8,  12, 19},
        {3,  6,  9,  16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    cout << "Test 1 (target=5): " << obj.searchMatrix(matrix1, 5) << endl;   // Output: 1 (true)
    
    // Test Case 2: Target doesn't exist
    cout << "Test 2 (target=20): " << obj.searchMatrix(matrix1, 20) << endl; // Output: 0 (false)
    
    // Test Case 3: Target at corner
    cout << "Test 3 (target=1): " << obj.searchMatrix(matrix1, 1) << endl;   // Output: 1 (true)
    cout << "Test 4 (target=30): " << obj.searchMatrix(matrix1, 30) << endl; // Output: 1 (true)
    
    return 0;
}