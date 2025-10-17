/**
 * ================================================================================
 * LeetCode 2022: Convert 1D Array Into 2D Array - Array Transformation
 * ================================================================================
 * 
 * ! Problem: Given a 0-indexed 1D integer array `original`, and two integers `m` and `n`,
 * ! construct a 2D array with `m` rows and `n` columns using all elements from `original`.
 * ! If it is impossible (original.size() != m * n), return an empty 2D array.
 * 
 * * Approach:
 * * 1. Validate that original array size equals m × n
 * * 2. If validation fails, return empty 2D array
 * * 3. Create a 2D array with m rows and n columns
 * * 4. Fill the 2D array row by row using elements from original array
 * * 5. Use a counter to track position in original array
 * 
 * ? Time Complexity: O(m × n) - We process each element exactly once
 * ? Space Complexity: O(m × n) - For the output 2D array (not counting output space)
 * 
 * TODO Key Insight: 
 * *    - The problem is essentially reshaping a 1D array into 2D format
 * *    - We must validate dimensions before attempting conversion
 * *    - Elements are filled row by row (row-major order)
 * *    - Index mapping: original[k] → result[k/n][k%n]
 * 
 * * Optimizations: 
 * *    - Early validation prevents unnecessary array creation
 * *    - Single pass through original array for construction
 * *    - Direct index mapping avoids complex calculations
 * ================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Converts a 1D array into a 2D array with specified dimensions
     * @param original The input 1D array to convert
     * @param m Number of rows in the resulting 2D array
     * @param n Number of columns in the resulting 2D array
     * @return 2D array with m rows and n columns, or empty array if impossible
     */
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // ! Critical validation: Check if conversion is possible
        // ? If original size doesn't match m × n, it's impossible to form the 2D array
        if (original.size() != m * n) {
            return {};  // ! Return empty 2D array
        }
        
        // * Initialize the result 2D array with m rows and n columns
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        // * Track current position in original array
        int index = 0;
        
        // * Fill the 2D array row by row
        for (int i = 0; i < m; i++) {  // ? Iterate through each row
            for (int j = 0; j < n; j++) {  // ? Iterate through each column
                // * Map 1D index to 2D position: original[index] → ans[i][j]
                ans[i][j] = original[index++];
            }
        }
        
        return ans;  // * Return the constructed 2D array
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print 2D array
 */
void print2DArray(const vector<vector<int>>& arr) {
    if (arr.empty()) {
        cout << "[]";
        return;
    }
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j];
            if (j < arr[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < arr.size() - 1) cout << ",";
    }
    cout << "]";
}

/**
 * Helper function to print test result
 */
void printTestResult(vector<int>& original, int m, int n, 
                     const vector<vector<int>>& result) {
    cout << "\noriginal = [";
    for (size_t i = 0; i < original.size(); i++) {
        cout << original[i];
        if (i < original.size() - 1) cout << ",";
    }
    cout << "], m = " << m << ", n = " << n << "\n";
    cout << "   Result: ";
    print2DArray(result);
    cout << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Standard conversion
    {
        vector<int> original = {1, 2, 3, 4};
        int m = 2, n = 2;
        auto result = solution.construct2DArray(original, m, n);
        printTestResult(original, m, n, result);
        // Expected: [[1,2],[3,4]]
    }
    
    // * Test Case 2: Single row
    {
        vector<int> original = {1, 2, 3};
        int m = 1, n = 3;
        auto result = solution.construct2DArray(original, m, n);
        printTestResult(original, m, n, result);
        // Expected: [[1,2,3]]
    }
    
    // ! Test Case 3: Impossible conversion (size mismatch)
    {
        vector<int> original = {1, 2};
        int m = 1, n = 1;
        auto result = solution.construct2DArray(original, m, n);
        printTestResult(original, m, n, result);
        // Expected: []
    }
    
    // * Test Case 4: Single column
    {
        vector<int> original = {3};
        int m = 1, n = 1;
        auto result = solution.construct2DArray(original, m, n);
        printTestResult(original, m, n, result);
        // Expected: [[3]]
    }
    
    // * Test Case 5: Larger array
    {
        vector<int> original = {1, 2, 3, 4, 5, 6};
        int m = 3, n = 2;
        auto result = solution.construct2DArray(original, m, n);
        printTestResult(original, m, n, result);
        // Expected: [[1,2],[3,4],[5,6]]
    }
    
    // ! Test Case 6: Empty original array
    {
        vector<int> original = {};
        int m = 0, n = 0;
        auto result = solution.construct2DArray(original, m, n);
        printTestResult(original, m, n, result);
        // Expected: []
    }
    
    // * Test Case 7: Tall matrix
    {
        vector<int> original = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
        int m = 6, n = 2;
        auto result = solution.construct2DArray(original, m, n);
        printTestResult(original, m, n, result);
        // Expected: [[1,2],[3,4],[5,6],[7,8],[9,10],[11,12]]
    }
    
    // ! Test Case 8: Wrong dimensions
    {
        vector<int> original = {1, 2, 3, 4, 5};
        int m = 2, n = 2;
        auto result = solution.construct2DArray(original, m, n);
        printTestResult(original, m, n, result);
        // Expected: []
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The solution handles all edge cases including empty arrays and mismatched dimensions
 * ! - The validation check is crucial and must happen before array allocation
 * * - Elements are filled in row-major order (standard C++ 2D array order)
 * ? - Alternative: Use index mapping formula: ans[k/n][k%n] = original[k]
 * * - Space complexity is O(1) if we don't count the output array
 * ================================================================================
 */