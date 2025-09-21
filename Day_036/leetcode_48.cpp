#include <vector>
#include <iostream>
using namespace std;

/*
================================================================================
LeetCode 48: Rotate Image
================================================================================
 Problem Description:
You are given an n x n 2D matrix representing an image, rotate the image by 
90 degrees (clockwise). You have to rotate the image **in-place**, which means 
you have to modify the input 2D matrix directly. DO NOT allocate another 2D 
matrix and do the rotation.

--------------------------------------------------------------------------------
Examples:
Input:  matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Input:  matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

================================================================================
 Easy Explanation (Beginner Friendly)
================================================================================
 Idea: Two-Step Matrix Transformation
1. **Transpose**: Convert rows to columns (matrix[i][j] ↔ matrix[j][i])
2. **Reverse Rows**: Reverse each row to complete 90° clockwise rotation

 Visual Transformation:
Original → Transpose → Reverse Rows → Final (90° Clockwise)

 Time Complexity: O(n²) - visit each element twice
 Space Complexity: O(1) - in-place transformation
================================================================================
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Step 1: Transpose the matrix (swap matrix[i][j] with matrix[j][i])
        // This converts rows to columns
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Swap elements across the main diagonal
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Step 2: Reverse each row to complete 90° clockwise rotation
        // This mirrors each row horizontally
        for (int i = 0; i < n; i++) {
            int start = 0;           // Left pointer
            int end = n - 1;         // Right pointer
            
            // Two-pointer approach to reverse the row
            while (start < end) {
                swap(matrix[i][start], matrix[i][end]);
                start++;             // Move left pointer right
                end--;               // Move right pointer left
            }
        }
    }
};

// ==================== Driver Code for Testing ====================
int main() {
    Solution obj;
    
    // Test Case 1: 3x3 matrix
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Original 3x3 matrix:" << endl;
    for (const auto& row : matrix1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    obj.rotate(matrix1);
    cout << "\nAfter 90° clockwise rotation:" << endl;
    for (const auto& row : matrix1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    // Expected Output: [[7,4,1],[8,5,2],[9,6,3]]
    
    cout << "\n" << string(50, '=') << "\n" << endl;
    
    // Test Case 2: 4x4 matrix
    vector<vector<int>> matrix2 = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    cout << "Original 4x4 matrix:" << endl;
    for (const auto& row : matrix2) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
    
    obj.rotate(matrix2);
    cout << "\nAfter 90° clockwise rotation:" << endl;
    for (const auto& row : matrix2) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
    // Expected Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
    
    cout << "\n" << string(50, '=') << "\n" << endl;
    
    // Test Case 3: 1x1 matrix (edge case)
    vector<vector<int>> matrix3 = {{1}};
    cout << "Original 1x1 matrix:" << endl;
    for (const auto& row : matrix3) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    obj.rotate(matrix3);
    cout << "\nAfter 90° clockwise rotation:" << endl;
    for (const auto& row : matrix3) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    // Expected Output: [[1]]
    
    return 0;
}