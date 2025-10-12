/**
 * ================================================================================
 * LeetCode 48: Rotate Image - Matrix Manipulation
 * ================================================================================
 * 
 * ! Problem: Given an n x n 2D matrix representing an image, rotate the image 
 * ! by 90 degrees clockwise. You must rotate the matrix in-place, which means 
 * ! you have to modify the input 2D matrix directly.
 * ! DO NOT allocate another 2D matrix and do the rotation.
 * 
 * * Approach:
 * * 1. Transpose the matrix (swap elements across diagonal)
 * * 2. Reverse each row
 * * 3. The combination achieves 90-degree clockwise rotation
 * * 
 * * Mathematical Insight:
 * * - Transpose converts matrix[i][j] to matrix[j][i]
 * * - Reversing rows converts matrix[i][j] to matrix[i][n-1-j]
 * * - Combined: matrix[i][j] → matrix[j][n-1-i] (90° clockwise rotation)
 * 
 * ? Time Complexity: O(n²) - Visit each element exactly twice (transpose + reverse)
 * ? Space Complexity: O(1) - In-place rotation, no extra space needed
 * 
 * TODO Key Insight: 
 * *    - 90° clockwise rotation = Transpose + Reverse each row
 * *    - 90° counter-clockwise = Transpose + Reverse each column
 * *    - 180° rotation = Reverse rows + Reverse columns
 * *    - In-place transformation preserves space efficiency
 * 
 * * Optimizations: 
 * *    - Single pass for transpose (only upper triangle)
 * *    - Two-pointer approach for efficient row reversal
 * *    - No auxiliary matrix needed
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 using namespace std;
 
 class Solution {
 public:
     /**
      * Rotates an n x n matrix by 90 degrees clockwise in-place
      * @param matrix The input 2D matrix to rotate (passed by reference)
      */
     void rotate(vector<vector<int>>& matrix) {
         int n = matrix.size();  // * Get matrix dimension
         
         // ============================================================
         // ! STEP 1: TRANSPOSE THE MATRIX
         // * Convert rows to columns by swapping across main diagonal
         // ============================================================
         
         // ? We only need to iterate through upper triangle to avoid double-swapping
         for (int i = 0; i < n; i++) {
             for (int j = i + 1; j < n; j++) {
                 // * Swap element at (i,j) with element at (j,i)
                 // * This reflects elements across the main diagonal
                 swap(matrix[i][j], matrix[j][i]);
             }
         }
         
         // ============================================================
         // ! STEP 2: REVERSE EACH ROW
         // * Flip elements horizontally within each row
         // ============================================================
         
         for (int i = 0; i < n; i++) {
             int s = 0;        // * Start pointer at beginning of row
             int e = n - 1;    // * End pointer at end of row
             
             // ? Two-pointer technique: swap elements from both ends moving inward
             while (s <= e) {
                 // * Swap elements and move pointers toward center
                 swap(matrix[i][s++], matrix[i][e--]);
             }
         }
         
         // * At this point, the matrix is rotated 90° clockwise
     }
 };
 
 // ============================================================
 // * TESTING SUITE - Verifies solution with various test cases
 // ============================================================
 
 /**
  * Helper function to print a matrix
  */
 void printMatrix(const vector<vector<int>>& matrix, const string& label) {
     cout << "\n" << label << ":\n";
     for (const auto& row : matrix) {
         cout << "   [";
         for (int i = 0; i < row.size(); i++) {
             cout << row[i];
             if (i < row.size() - 1) cout << ", ";
         }
         cout << "]\n";
     }
 }
 
 /**
  * Helper function to compare two matrices
  */
 bool matricesEqual(const vector<vector<int>>& a, const vector<vector<int>>& b) {
     if (a.size() != b.size()) return false;
     for (int i = 0; i < a.size(); i++) {
         if (a[i] != b[i]) return false;
     }
     return true;
 }
 
 int main() {
     Solution solution;
     
     // * Test Case 1: 3x3 matrix
     {
         vector<vector<int>> matrix = {
             {1, 2, 3},
             {4, 5, 6},
             {7, 8, 9}
         };
         vector<vector<int>> expected = {
             {7, 4, 1},
             {8, 5, 2},
             {9, 6, 3}
         };
         
         printMatrix(matrix, "Test 1 - Before Rotation (3x3)");
         solution.rotate(matrix);
         printMatrix(matrix, "After 90° Clockwise Rotation");
         cout << "   Status: " << (matricesEqual(matrix, expected) ? "PASS" : "FAIL") << "\n";
     }
     
     // * Test Case 2: 4x4 matrix
     {
         vector<vector<int>> matrix = {
             {5, 1, 9, 11},
             {2, 4, 8, 10},
             {13, 3, 6, 7},
             {15, 14, 12, 16}
         };
         vector<vector<int>> expected = {
             {15, 13, 2, 5},
             {14, 3, 4, 1},
             {12, 6, 8, 9},
             {16, 7, 10, 11}
         };
         
         printMatrix(matrix, "Test 2 - Before Rotation (4x4)");
         solution.rotate(matrix);
         printMatrix(matrix, "After 90° Clockwise Rotation");
         cout << "   Status: " << (matricesEqual(matrix, expected) ? "PASS" : "FAIL") << "\n";
     }
     
     // * Test Case 3: 1x1 matrix (edge case)
     {
         vector<vector<int>> matrix = {{1}};
         vector<vector<int>> expected = {{1}};
         
         printMatrix(matrix, "Test 3 - Before Rotation (1x1)");
         solution.rotate(matrix);
         printMatrix(matrix, "After 90° Clockwise Rotation");
         cout << "   Status: " << (matricesEqual(matrix, expected) ? "PASS" : "FAIL") << "\n";
     }
     
     // * Test Case 4: 2x2 matrix (smallest non-trivial case)
     {
         vector<vector<int>> matrix = {
             {1, 2},
             {3, 4}
         };
         vector<vector<int>> expected = {
             {3, 1},
             {4, 2}
         };
         
         printMatrix(matrix, "Test 4 - Before Rotation (2x2)");
         solution.rotate(matrix);
         printMatrix(matrix, "After 90° Clockwise Rotation");
         cout << "   Status: " << (matricesEqual(matrix, expected) ? "PASS" : "FAIL") << "\n";
     }
     
     // * Test Case 5: Matrix with negative numbers
     {
         vector<vector<int>> matrix = {
             {-1, -2, -3},
             {-4, -5, -6},
             {-7, -8, -9}
         };
         vector<vector<int>> expected = {
             {-7, -4, -1},
             {-8, -5, -2},
             {-9, -6, -3}
         };
         
         printMatrix(matrix, "Test 5 - Before Rotation (Negative Numbers)");
         solution.rotate(matrix);
         printMatrix(matrix, "After 90° Clockwise Rotation");
         cout << "   Status: " << (matricesEqual(matrix, expected) ? "PASS" : "FAIL") << "\n";
     }
     
     // * Test Case 6: Matrix with zeros
     {
         vector<vector<int>> matrix = {
             {0, 0, 0},
             {0, 5, 0},
             {0, 0, 0}
         };
         vector<vector<int>> expected = {
             {0, 0, 0},
             {0, 5, 0},
             {0, 0, 0}
         };
         
         printMatrix(matrix, "Test 6 - Before Rotation (With Zeros)");
         solution.rotate(matrix);
         printMatrix(matrix, "After 90° Clockwise Rotation");
         cout << "   Status: " << (matricesEqual(matrix, expected) ? "PASS" : "FAIL") << "\n";
     }
     
     // ! Test Case 7: Large matrix (5x5)
     {
         vector<vector<int>> matrix = {
             {1, 2, 3, 4, 5},
             {6, 7, 8, 9, 10},
             {11, 12, 13, 14, 15},
             {16, 17, 18, 19, 20},
             {21, 22, 23, 24, 25}
         };
         vector<vector<int>> expected = {
             {21, 16, 11, 6, 1},
             {22, 17, 12, 7, 2},
             {23, 18, 13, 8, 3},
             {24, 19, 14, 9, 4},
             {25, 20, 15, 10, 5}
         };
         
         printMatrix(matrix, "Test 7 - Before Rotation (5x5)");
         solution.rotate(matrix);
         printMatrix(matrix, "After 90° Clockwise Rotation");
         cout << "   Status: " << (matricesEqual(matrix, expected) ? "PASS" : "FAIL") << "\n";
     }
     
     return 0;
 }
 
 /*
  * ================================================================================
  * TODO Additional Notes:
  * * - The solution achieves in-place rotation without extra space
  * ! - The transpose operation only processes upper triangle to avoid redundant swaps
  * * - Two-pointer reversal ensures O(n/2) swaps per row
  * ? - For counter-clockwise rotation: transpose + reverse columns instead of rows
  * * - For 180° rotation: reverse all rows, then reverse all columns (or vice versa)
  * 
  * * Complexity Analysis:
  * * - Transpose: O(n²/2) operations (upper triangle only)
  * * - Reverse: O(n²/2) operations (n rows × n/2 swaps each)
  * * - Total: O(n²) time with O(1) space
  * 
  * * Alternative Approaches:
  * * 1. Layer-by-layer rotation (more complex but single pass)
  * * 2. Using auxiliary matrix (easier but O(n²) space)
  * * 3. Mathematical formula approach (direct position calculation)
  * ================================================================================
  */