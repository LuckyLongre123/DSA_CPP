/**
 * ================================================================================
 * 🔺 LeetCode 120: Triangle - Minimum Path Sum (Dynamic Programming)
 * ================================================================================
 * 
 * 🎯 Problem: Given a triangle array, return the minimum path sum from top to bottom.
 * For each step, you may move to an adjacent number of the row below. More formally,
 * if you are on index i on the current row, you may move to either index i or 
 * index i + 1 on the next row.
 * 
 * 📝 Approach: Bottom-Up Dynamic Programming with Space Optimization
 * 1. Start from the bottom row of the triangle (already contains minimum sums)
 * 2. For each row above, calculate minimum path sum using values from row below
 * 3. For each position, choose minimum between two possible paths from below
 * 4. Continue until reaching the top (single element with final answer)
 * 
 * ⚡ Time Complexity: O(n²) where n is the number of rows in triangle
 * 💾 Space Complexity: O(n) using optimized 1D DP array (original: O(n²))
 * 
 * 🧠 Key Insight: 
 *    - Bottom-up approach eliminates need to track paths explicitly
 *    - Each position stores the minimum sum to reach bottom from that point
 *    - Space optimization: reuse bottom row as DP array, update in-place
 * 
 * 🚀 Optimizations: 
 *    - Single DP array instead of 2D matrix (space optimization)
 *    - Bottom-up processing eliminates recursive overhead
 *    - In-place updates reduce memory allocations
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>
#include <chrono>
using namespace std;

class Solution {
public:
    /**
     * MAIN FUNCTION: Finds minimum path sum from top to bottom of triangle
     * @param triangle 2D vector representing the triangle structure
     * @return Minimum sum of path from top to bottom
     */
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // Edge case: empty triangle
        if (n == 0) return 0;
        
        // Initialize DP array with bottom row values
        // dp[i] represents minimum path sum from position i to bottom
        vector<int> dp(triangle.back());
        
        // Process triangle from second-to-last row upward
        for (int row = n - 2; row >= 0; row--) {
            // For each position in current row
            for (int col = 0; col <= row; col++) {
                // Choose minimum path: current + min(left_below, right_below)
                // dp[col] = path through position (row+1, col)
                // dp[col+1] = path through position (row+1, col+1)
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }
        
        // dp[0] now contains minimum path sum from top to bottom
        return dp[0];
    }
    
    /**
     * ALTERNATIVE APPROACH: 2D Dynamic Programming (for educational purposes)
     * Time: O(n²), Space: O(n²)
     * More intuitive but uses additional space
     */
    int minimumTotal2D(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        
        // Create 2D DP table matching triangle structure
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(i + 1);
        }
        
        // Initialize bottom row
        for (int j = 0; j < n; j++) {
            dp[n-1][j] = triangle[n-1][j];
        }
        
        // Fill DP table bottom-up
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
    }
    
    /**
     * ALTERNATIVE APPROACH: Top-Down with Memoization (Recursive DP)
     * Time: O(n²), Space: O(n²) + O(n) recursion stack
     */
    int minimumTotalTopDown(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> memo(n);
        for (int i = 0; i < n; i++) {
            memo[i].resize(i + 1, INT_MAX);
        }
        
        return dfs(triangle, 0, 0, memo);
    }
    
private:
    /**
     * Helper function for top-down approach
     * @param triangle The input triangle
     * @param row Current row position
     * @param col Current column position  
     * @param memo Memoization table
     * @return Minimum path sum from (row, col) to bottom
     */
    int dfs(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& memo) {
        // Base case: reached bottom row
        if (row == triangle.size() - 1) {
            return triangle[row][col];
        }
        
        // Return memoized result if available
        if (memo[row][col] != INT_MAX) {
            return memo[row][col];
        }
        
        // Recursive case: try both possible moves
        int left = dfs(triangle, row + 1, col, memo);      // Move to (row+1, col)
        int right = dfs(triangle, row + 1, col + 1, memo); // Move to (row+1, col+1)
        
        // Memoize and return minimum path
        memo[row][col] = triangle[row][col] + min(left, right);
        return memo[row][col];
    }
};

// ============================================================
// 🧪 COMPREHENSIVE TESTING SUITE
// ============================================================

/**
 * Helper function to print triangle structure
 */
void printTriangle(const vector<vector<int>>& triangle) {
    cout << "\n📐 Triangle Structure:\n";
    for (int i = 0; i < triangle.size(); i++) {
        // Add spacing for triangle shape
        for (int space = 0; space < triangle.size() - i - 1; space++) {
            cout << "  ";
        }
        for (int j = 0; j < triangle[i].size(); j++) {
            cout << triangle[i][j];
            if (j < triangle[i].size() - 1) cout << "   ";
        }
        cout << "\n";
    }
}

/**
 * Helper function to print test results
 */
void printTestResult(const string& testName, const vector<vector<int>>& triangle, 
                    int result, int expected) {
    cout << "\n🔍 " << testName << "\n";
    printTriangle(triangle);
    cout << "\n   Result:   " << result << "\n";
    cout << "   Expected: " << expected << "\n";
    cout << "   Status:   " << (result == expected ? "✅ PASS" : "❌ FAIL");
    if (result != expected) {
        cout << " (Expected: " << expected << ")";
    }
    cout << "\n" << string(50, '-') << "\n";
}

/**
 * Performance comparison between different approaches
 */
void performanceTest() {
    cout << "\n🚀 PERFORMANCE COMPARISON\n";
    cout << string(50, '=') << "\n";
    
    // Create a larger triangle for performance testing
    vector<vector<int>> largeTriangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3},
        {1, 5, 3, 6, 2},
        {7, 2, 4, 1, 9, 3}
    };
    
    Solution solution;
    
    cout << "Testing with 6-row triangle...\n";
    
    // Test optimized approach
    auto start = chrono::high_resolution_clock::now();
    int result1 = solution.minimumTotal(largeTriangle);
    auto end = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << "✅ Optimized (1D DP): " << result1 << " (Time: " << duration1.count() << "μs)\n";
    
    // Test 2D approach
    start = chrono::high_resolution_clock::now();
    int result2 = solution.minimumTotal2D(largeTriangle);
    end = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << "✅ 2D DP Approach: " << result2 << " (Time: " << duration2.count() << "μs)\n";
    
    // Test top-down approach
    start = chrono::high_resolution_clock::now();
    int result3 = solution.minimumTotalTopDown(largeTriangle);
    end = chrono::high_resolution_clock::now();
    auto duration3 = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << "✅ Top-Down (Recursive): " << result3 << " (Time: " << duration3.count() << "μs)\n";
    
    cout << "\n📊 Space Complexity Comparison:\n";
    cout << "   - Optimized (1D): O(n) space\n";
    cout << "   - 2D DP: O(n²) space\n";
    cout << "   - Top-Down: O(n²) + O(n) recursion stack\n";
}

int main() {
    Solution solution;
    
    cout << "🔺 LEETCODE 120: TRIANGLE - MINIMUM PATH SUM\n";
    cout << string(60, '=') << "\n";
    
    // Test Case 1: Basic example from problem description
    {
        vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
        int result = solution.minimumTotal(triangle);
        printTestResult("Basic Triangle (LeetCode Example)", triangle, result, 11);
    }
    
    // Test Case 2: Single element triangle
    {
        vector<vector<int>> triangle = {{-10}};
        int result = solution.minimumTotal(triangle);
        printTestResult("Single Element", triangle, result, -10);
    }
    
    // Test Case 3: Two-row triangle
    {
        vector<vector<int>> triangle = {{1}, {2, 3}};
        int result = solution.minimumTotal(triangle);
        printTestResult("Two Rows", triangle, result, 3);
    }
    
    // Test Case 4: All negative numbers
    {
        vector<vector<int>> triangle = {{-1}, {-2, -3}, {-4, -5, -6}};
        int result = solution.minimumTotal(triangle);
        printTestResult("All Negative Numbers", triangle, result, -8);
    }
    
    // Test Case 5: Mixed positive and negative
    {
        vector<vector<int>> triangle = {{1}, {-1, -2}, {3, 1, -1}};
        int result = solution.minimumTotal(triangle);
        printTestResult("Mixed Positive/Negative", triangle, result, -2);
    }
    
    // Test Case 6: Larger triangle with optimal path on edges
    {
        vector<vector<int>> triangle = {
            {1},
            {2, 3},
            {4, 5, 6},
            {7, 8, 9, 10},
            {11, 12, 13, 14, 15}
        };
        int result = solution.minimumTotal(triangle);
        printTestResult("Edge Path Optimization", triangle, result, 25);
    }
    
    // Test Case 7: Verify all three approaches give same result
    {
        vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
        int result1 = solution.minimumTotal(triangle);
        int result2 = solution.minimumTotal2D(triangle);
        int result3 = solution.minimumTotalTopDown(triangle);
        
        cout << "\n🔍 Algorithm Verification Test\n";
        cout << "   Optimized 1D DP: " << result1 << "\n";
        cout << "   2D DP Approach:  " << result2 << "\n";
        cout << "   Top-Down Recursive: " << result3 << "\n";
        cout << "   All Match: " << ((result1 == result2 && result2 == result3) ? "✅ YES" : "❌ NO") << "\n";
    }
    
    // Performance testing
    performanceTest();
    
    cout << "\n🎉 All tests completed! Triangle minimum path sum mastered!\n";
    return 0;
}

/*
 * ================================================================================
 * 📝 ALGORITHM ANALYSIS & INSIGHTS:
 * 
 * 🎯 PROBLEM CHARACTERISTICS:
 * - Classic dynamic programming problem with optimal substructure
 * - Each position's optimal solution depends on optimal solutions of subproblems
 * - Multiple valid approaches: top-down, bottom-up, space-optimized
 * 
 * 🧠 KEY INSIGHTS:
 * 1. Bottom-up approach is more intuitive - start where we know the answer
 * 2. Space optimization possible because we only need previous row's values
 * 3. Triangle structure ensures valid adjacent positions (i, i+1) in next row
 * 
 * 🚀 OPTIMIZATION TECHNIQUES:
 * - Space optimization: O(n²) → O(n) by reusing input or single array
 * - In-place modification: Can modify input triangle directly if allowed
 * - Early termination: Not applicable here (need to process all positions)
 * 
 * 📊 COMPLEXITY BREAKDOWN:
 * - Total positions in triangle: 1 + 2 + 3 + ... + n = n(n+1)/2 = O(n²)
 * - Each position processed once: O(n²) time
 * - Space optimization reduces auxiliary space to O(n)
 * 
 * 🎓 LEARNING OUTCOMES:
 * - Master bottom-up dynamic programming approach
 * - Understand space optimization techniques in DP
 * - Practice with triangle/pyramid data structures
 * - Learn to identify optimal substructure in problems
 * ================================================================================
 */