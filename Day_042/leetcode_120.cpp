/**
 * ================================================================================
 * LeetCode 120: Triangle - Minimum Path Sum
 * ================================================================================
 * 
 * ! Problem: Given a triangle array, return the minimum path sum from top to bottom.
 * ! For each step, you may move to an adjacent number of the row below. 
 * ! More formally, if you are on index i on the current row, you may move to 
 * ! either index i or index i + 1 on the next row.
 * 
 * * Approach:
 * * 1. Start from the bottom row of the triangle (base case)
 * * 2. Work our way up, calculating minimum path sums
 * * 3. For each position, choose the minimum of two adjacent positions below
 * * 4. Add current value to the chosen minimum
 * * 5. The top element contains the final answer
 * 
 * ? Time Complexity: O(n²) - We process each element exactly once
 * ? Space Complexity: O(n) - Only store one row at a time
 * 
 * TODO Key Insight: 
 * *    - Bottom-up DP avoids recursion overhead
 * *    - We optimize space by reusing the same array
 * *    - Each position depends only on two positions from the row below
 * 
 * * Optimizations: 
 * *    - Space optimized from O(n²) to O(n) by using 1D array
 * *    - In-place updates eliminate need for extra storage
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;
 
 class Solution {
 public:
     /**
      * Finds minimum path sum from top to bottom of triangle
      * @param triangle A 2D vector representing the triangle structure
      * @return The minimum path sum from top to bottom
      */
     int minimumTotal(vector<vector<int>>& triangle) {
         int n = triangle.size();  // * Get number of rows in triangle
         
         // * Initialize DP array with bottom row values (base case)
         // ? Starting from bottom eliminates need for complex initialization
         vector<int> dp(triangle.back());
         
         // ! Process triangle from second-last row to top
         // ? We skip the last row since it's already in our dp array
         for (int row = n - 2; row >= 0; row--) {
             // * For each element in current row
             for (int col = 0; col <= row; col++) {
                 // ! Choose minimum path: either stay at same index or move right
                 // ? dp[col] represents path through current position
                 // ? dp[col + 1] represents path through right-adjacent position
                 dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
             }
         }
         
         // * The top element now contains minimum path sum
         return dp[0];
     }
 };
 
 // ============================================================
 // * TESTING SUITE - Verifies solution with various test cases
 // ============================================================
 
 /**
  * Helper function to print triangle structure
  */
 void printTriangle(const vector<vector<int>>& triangle) {
     cout << "Triangle structure:\n";
     for (int i = 0; i < triangle.size(); i++) {
         // * Add spacing for visual triangle shape
         for (int j = 0; j < triangle.size() - i - 1; j++) {
             cout << " ";
         }
         for (int j = 0; j < triangle[i].size(); j++) {
             cout << triangle[i][j];
             if (j < triangle[i].size() - 1) cout << " ";
         }
         cout << "\n";
     }
 }
 
 /**
  * Helper function to print test result
  */
 void printTestResult(vector<vector<int>>& triangle, int result, int expected) {
     cout << "\n";
     printTriangle(triangle);
     cout << "   Result:   " << result << "\n";
     cout << "   Expected: " << expected << "\n";
     cout << "   Status:   " << (result == expected ? "PASS" : "FAIL");
     if (result != expected) {
         cout << " (Expected: " << expected << ")";
     }
     cout << "\n";
 }
 
 int main() {
     Solution solution;
     
     // * Test Case 1: Standard triangle
     {
         vector<vector<int>> triangle = {
             {2},
             {3, 4},
             {6, 5, 7},
             {4, 1, 8, 3}
         };
         int result = solution.minimumTotal(triangle);
         printTestResult(triangle, result, 11);  // Path: 2 -> 3 -> 5 -> 1
     }
     
     // * Test Case 2: Negative numbers
     {
         vector<vector<int>> triangle = {
             {-10}
         };
         int result = solution.minimumTotal(triangle);
         printTestResult(triangle, result, -10);
     }
     
     // * Test Case 3: Small triangle
     {
         vector<vector<int>> triangle = {
             {1},
             {2, 3}
         };
         int result = solution.minimumTotal(triangle);
         printTestResult(triangle, result, 3);  // Path: 1 -> 2
     }
     
     // * Test Case 4: All positive values
     {
         vector<vector<int>> triangle = {
             {5},
             {7, 8},
             {2, 3, 1}
         };
         int result = solution.minimumTotal(triangle);
         printTestResult(triangle, result, 8);  // Path: 5 -> 7 -> 2 (not minimum) or 5 -> 8 -> 1
     }
     
     // ! Test Case 5: Large values
     {
         vector<vector<int>> triangle = {
             {100},
             {50, 40},
             {30, 20, 10}
         };
         int result = solution.minimumTotal(triangle);
         printTestResult(triangle, result, 150);  // Path: 100 -> 40 -> 10
     }
     
     // * Test Case 6: Mix of positive and negative
     {
         vector<vector<int>> triangle = {
             {-1},
             {2, 3},
             {1, -1, -3}
         };
         int result = solution.minimumTotal(triangle);
         printTestResult(triangle, result, -1);  // Path: -1 -> 3 -> -3
     }
     
     // * Test Case 7: Increasing path challenge
     {
         vector<vector<int>> triangle = {
             {1},
             {2, 3},
             {4, 5, 6},
             {7, 8, 9, 10}
         };
         int result = solution.minimumTotal(triangle);
         printTestResult(triangle, result, 14);  // Path: 1 -> 2 -> 4 -> 7
     }
     
     // * Test Case 8: Equal values
     {
         vector<vector<int>> triangle = {
             {5},
             {5, 5},
             {5, 5, 5}
         };
         int result = solution.minimumTotal(triangle);
         printTestResult(triangle, result, 15);  // Any path: 5 + 5 + 5
     }
     
     return 0;
 }
 
 /*
  * ================================================================================
  * TODO Additional Notes:
  * * - Bottom-up approach is more intuitive than top-down for this problem
  * ! - Space optimization from O(n²) to O(n) significantly reduces memory usage
  * * - The algorithm naturally handles negative numbers without special cases
  * ? - For very large triangles, consider if O(n) space is still acceptable
  * ================================================================================
  */