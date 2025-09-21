#include <vector>
using namespace std;

/*
================================================================================
LeetCode 74: Search a 2D Matrix
================================================================================
🔹 Problem Description:
Write an efficient algorithm that searches for a target value in an m x n integer
matrix. The matrix has the following properties:
- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

--------------------------------------------------------------------------------
Examples:
Input:  matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input:  matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 Idea: Treat 2D Matrix as 1D Array + Binary Search
1. Since matrix is sorted row-wise and first element of each row > last of previous,
   we can treat it as a single sorted 1D array.
2. Use binary search on this conceptual 1D array.
3. Convert 1D index to 2D coordinates: row = index/cols, col = index%cols.
4. Apply standard binary search logic.

⏱ Time Complexity: O(log(m × n))
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
        
        // Step 2: Get matrix dimensions
        int row = matrix.size();        // Total number of rows
        int col = matrix[0].size();     // Total number of columns
        
        // Step 3: Initialize binary search pointers
        int s = 0;                      // Start index (treating as 1D array)
        int e = row * col - 1;          // End index (treating as 1D array)
        
        // Step 4: Perform binary search
        while (s <= e) {
            // Calculate middle index (avoid overflow)
            int mid = s + (e - s) / 2;
            
            // Convert 1D index to 2D coordinates
            int cell = matrix[mid / col][mid % col];
            
            // Found the target
            if (cell == target) {
                return true;
            }
            // Target is smaller, search left half
            else if (cell > target) {
                e = mid - 1;
            }
            // Target is larger, search right half
            else {
                s = mid + 1;
            }
        }
        
        // Step 5: Target not found
        return false;
    }
};

// ==================== Driver Code for Testing ====================
#include <iostream>
int main() {
    Solution obj;
    
    // Test Case 1: Target exists
    vector<vector<int>> matrix1 = {
        {1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    cout << "Test 1 (target=3): " << obj.searchMatrix(matrix1, 3) << endl;   // Output: 1 (true)
    
    // Test Case 2: Target doesn't exist
    cout << "Test 2 (target=13): " << obj.searchMatrix(matrix1, 13) << endl; // Output: 0 (false)
    
    // Test Case 3: Target at boundaries
    cout << "Test 3 (target=1): " << obj.searchMatrix(matrix1, 1) << endl;   // Output: 1 (true)
    cout << "Test 4 (target=60): " << obj.searchMatrix(matrix1, 60) << endl; // Output: 1 (true)
    
    // Test Case 5: Single element matrix
    vector<vector<int>> matrix2 = {{1}};
    cout << "Test 5 (target=1): " << obj.searchMatrix(matrix2, 1) << endl;   // Output: 1 (true)
    
    return 0;
}