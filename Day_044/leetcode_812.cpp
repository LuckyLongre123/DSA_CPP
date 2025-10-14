/**
 * ================================================================================
 * LeetCode 812: Largest Triangle Area - Computational Geometry
 * ================================================================================
 * 
 * ! Problem: Given an array of points on the X-Y plane, find the area of the 
 * ! largest triangle that can be formed by any three of these points. Return the 
 * ! area as a floating-point number.
 * 
 * * Approach:
 * * 1. Consider all possible combinations of three points
 * * 2. For each combination, calculate the triangle area using the shoelace formula
 * * 3. Track the maximum area encountered
 * * 4. Return the largest area found
 * 
 * ? Time Complexity: O(n³) - Three nested loops iterate through all point combinations
 * ? Space Complexity: O(1) - Only using a few variables for calculation
 * 
 * TODO Key Insight:
 * *    - The shoelace formula calculates triangle area from coordinates
 * *    - Area = |x₁(y₂-y₃) + x₂(y₃-y₁) + x₃(y₁-y₂)| / 2
 * *    - The absolute value ensures positive area regardless of point order
 * *    - With n points, we have C(n,3) = n(n-1)(n-2)/6 possible triangles
 * 
 * * Optimizations:
 * *    - Early loop termination not possible (all combinations matter)
 * *    - No pruning strategies available (must check all triangles)
 * *    - Single pass calculation per triangle
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * Finds the area of the largest triangle from given points
     * @param points Vector of 2D points [x, y] coordinates
     * @return The maximum triangle area possible
     */
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0;  // * Tracks the maximum area found so far
        int n = points.size();  // * Number of points available
        
        // ! Iterate through all possible combinations of three points
        // ? Three nested loops generate C(n,3) combinations
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    // * Extract coordinates for cleaner calculation
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    
                    // ! Calculate area using the shoelace formula
                    // ? Formula: Area = |x₁(y₂-y₃) + x₂(y₃-y₁) + x₃(y₁-y₂)| / 2
                    // ? This formula works regardless of point order (clockwise/counterclockwise)
                    double area = abs(x1 * (y2 - y3) +
                                     x2 * (y3 - y1) +
                                     x3 * (y1 - y2)) / 2.0;
                    
                    // * Update maximum if current triangle is larger
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result with formatted output
 */
void printTestResult(vector<vector<int>>& points, double result, double expected) {
    cout << "\nPoints: ";
    for (auto& p : points) {
        cout << "[" << p[0] << "," << p[1] << "] ";
    }
    cout << "\n   Result:   " << fixed << result << "\n";
    cout << "   Expected: " << fixed << expected << "\n";
    cout << "   Status:   " << (abs(result - expected) < 0.001 ? "PASS" : "FAIL");
    cout << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Simple triangle
    {
        vector<vector<int>> points = {{0, 0}, {0, 1}, {1, 0}};
        double result = solution.largestTriangleArea(points);
        printTestResult(points, result, 0.5);
    }
    
    // * Test Case 2: Right triangle with different configuration
    {
        vector<vector<int>> points = {{0, 0}, {0, 8}, {8, 0}};
        double result = solution.largestTriangleArea(points);
        printTestResult(points, result, 32.0);
    }
    
    // * Test Case 3: Four points - multiple triangles to check
    {
        vector<vector<int>> points = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        double result = solution.largestTriangleArea(points);
        printTestResult(points, result, 0.5);
    }
    
    // * Test Case 4: Collinear points (form degenerate triangle)
    {
        vector<vector<int>> points = {{0, 0}, {1, 1}, {2, 2}};
        double result = solution.largestTriangleArea(points);
        printTestResult(points, result, 0.0);
    }
    
    // * Test Case 5: Large coordinate values
    {
        vector<vector<int>> points = {{0, 0}, {0, 100}, {100, 0}};
        double result = solution.largestTriangleArea(points);
        printTestResult(points, result, 5000.0);
    }
    
    // * Test Case 6: Negative coordinates
    {
        vector<vector<int>> points = {{-1, -1}, {-1, 1}, {1, -1}};
        double result = solution.largestTriangleArea(points);
        printTestResult(points, result, 2.0);
    }
    
    // * Test Case 7: Mixed positive and negative
    {
        vector<vector<int>> points = {{-5, 0}, {0, 10}, {5, 0}};
        double result = solution.largestTriangleArea(points);
        printTestResult(points, result, 50.0);
    }
    
    // * Test Case 8: Five points - tests all combinations
    {
        vector<vector<int>> points = {{0, 0}, {0, 2}, {2, 0}, {2, 2}, {1, 1}};
        double result = solution.largestTriangleArea(points);
        printTestResult(points, result, 2.0);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The shoelace formula is a fundamental technique in computational geometry
 * ! - Collinear points produce area = 0, which is correctly handled
 * * - The algorithm works with negative coordinates without modification
 * ? - For large inputs (n > 100), consider approximation algorithms instead
 * * - The floating-point division by 2.0 ensures accurate decimal results
 * ? - Point order in the input doesn't affect the result
 * ================================================================================
 */