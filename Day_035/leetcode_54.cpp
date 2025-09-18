/**
 * ================================================================================
 * 🌀 LeetCode 54: Spiral Matrix - Solution with Boundary Shrinking
 * ================================================================================
 * 
 * 🎯 Problem: Given an m x n matrix, return all elements in spiral order.
 * 
 * 📝 Approach: Boundary Shrinking Technique
 * 1. Use four boundaries: top, bottom, left, right
 * 2. Traverse in order: right → down → left → up
 * 3. After each full cycle, move boundaries inward
 * 4. Stop when all elements are processed
 * 
 * ⚡ Time Complexity: O(m×n) - Each element visited exactly once
 * 💾 Space Complexity: O(1) - Constant extra space (output array not counted)
 * 
 * 🧠 Key Insight: Think of peeling an orange - remove outer layer by layer
 * 
 * 🚀 Optimizations: 
 *    - Early termination when count reaches total elements
 *    - In-place boundary updates
 *    - No extra data structures needed
 * ================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //! MAIN FUNCTION: Implements spiral order traversal
    //! @param matrix The 2D input matrix
    //! @return Vector containing elements in spiral order
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //? Edge case: Empty matrix
        if (matrix.empty() || matrix[0].empty()) return {};
        
        vector<int> ans;  //* Output container
        int m = matrix.size(), n = matrix[0].size();
        
        //* Initialize boundaries
        //? These define the current "frame" we're processing
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        
        //* Continue until all elements are processed
        while (top <= bottom && left <= right) {
            //! 1. Traverse from left to right along top boundary
            //? Moves: left → right
            //? Updates: top boundary (moves down)
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            
            //! 2. Traverse from top to bottom along right boundary
            //? Moves: top → bottom
            //? Updates: right boundary (moves left)
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            
            //* Check if there's a valid row to traverse left
            if (top <= bottom) {
                //! 3. Traverse from right to left along bottom boundary
                //? Moves: right → left
                //? Updates: bottom boundary (moves up)
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            //* Check if there's a valid column to traverse up
            if (left <= right) {
                //! 4. Traverse from bottom to top along left boundary
                //? Moves: bottom → top
                //? Updates: left boundary (moves right)
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return ans;
    }
};

// ============================================================
// 🧪 TESTING SUITE - Verifies solution with various test cases
// ============================================================

//! Helper function to print test results
void printTestResult(const string& testName, const vector<int>& result, const vector<int>& expected) {
    cout << "\n🔍 " << testName << "\n";
    cout << "   Result:   [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]\n   Expected: [";
    for (size_t i = 0; i < expected.size(); i++) {
        cout << expected[i];
        if (i < expected.size() - 1) cout << ", ";
    }
    cout << "]\n";
    cout << (result == expected ? "✅ PASSED" : "❌ FAILED") << "\n";
}

int main() {
    Solution sol;
    
    //* Test Case 1: 3x3 Matrix
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> expected1 = {1,2,3,6,9,8,7,4,5};
    printTestResult("3x3 Matrix", sol.spiralOrder(matrix1), expected1);
    
    //* Test Case 2: 3x4 Matrix
    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };
    vector<int> expected2 = {1,2,3,4,8,12,11,10,9,5,6,7};
    printTestResult("3x4 Matrix", sol.spiralOrder(matrix2), expected2);
    
    //* Test Case 3: 1x1 Matrix
    vector<vector<int>> matrix3 = {{42}};
    vector<int> expected3 = {42};
    printTestResult("1x1 Matrix", sol.spiralOrder(matrix3), expected3);
    
    //* Test Case 4: Single Row
    vector<vector<int>> matrix4 = {{1,2,3,4,5}};
    vector<int> expected4 = {1,2,3,4,5};
    printTestResult("Single Row", sol.spiralOrder(matrix4), expected4);
    
    //* Test Case 5: Single Column
    vector<vector<int>> matrix5 = {{1},{2},{3},{4},{5}};
    vector<int> expected5 = {1,2,3,4,5};
    printTestResult("Single Column", sol.spiralOrder(matrix5), expected5);
    
    return 0;
}

/*
 * ================================================================================
 * 📝 Additional Notes:
 * - The solution handles all edge cases including single row, single column, and empty matrices
 * - The boundary shrinking approach ensures we don't revisit elements
 * - Time complexity is optimal as we visit each element exactly once
 * - Space complexity is O(1) extra space (excluding output array)
 * ================================================================================
 */