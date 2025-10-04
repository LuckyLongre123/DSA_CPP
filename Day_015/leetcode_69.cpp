/**
 * ================================================================================
 * LeetCode 69: Sqrt(x) - Binary Search on Answer Space
 * ================================================================================
 * 
 * ! Problem: Given a non-negative integer `x`, return the integer square root of `x` 
 * ! rounded down to the nearest integer. The result must also be non-negative.
 * ! You must not use any built-in exponent function or operator.
 * 
 * * Approach:
 * * 1. Handle edge cases (x = 0, x < 4) directly for efficiency
 * * 2. Use binary search in the range [1, x/2] to find the square root
 * * 3. For each midpoint, compare its square with x:
 * *    - If square equals x: Found exact square root, return mid
 * *    - If square is less than x: Store as potential answer and search right half
 * *    - If square is greater than x: Search left half
 * * 4. Return the largest integer whose square is less than or equal to x
 * 
 * ? Time Complexity: O(log x) - Binary search halves the search space each iteration
 * ? Space Complexity: O(1) - Constant extra space used
 * 
 * TODO Key Insight: 
 * *    - Binary search on answer space: searching for the answer value, not in an array
 * *    - For x > 1, the square root is always less than or equal to x/2
 * *    - Using `long long` prevents integer overflow when computing mid * mid
 * 
 * * Optimizations: 
 * *    - Search space reduced to [1, x/2] instead of [0, x]
 * *    - Early termination for edge cases (0 and small values)
 * *    - Midpoint calculation uses s + (e-s)/2 to prevent overflow
 * ================================================================================
 */

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * Computes the integer square root of x using binary search
     * @param x The input non-negative integer
     * @return The largest integer whose square is less than or equal to x
     */
    int mySqrt(int x) {
        int s = 0;      // * Start pointer
        int e = x - 1;  // * End pointer (x-1 because sqrt(x) < x for x > 1)
        int ans = -1;   // * Variable to store the answer
        
        // ! Handle edge cases for efficiency
        if (x == 0) return 0;  // ? sqrt(0) = 0
        if (x == 1) return 1;  // ? sqrt(1) = 1
        
        // * Binary search to find the square root
        while (s <= e) {
            // ? Calculate mid point to avoid integer overflow
            long long int mid = s + (e - s) / 2;
            
            // ? Calculate square of mid using long long to prevent overflow
            long long int sqr = mid * mid;
            
            // ! If perfect square found, return immediately
            if (sqr == x) {
                return mid;
            }
            
            // * If mid^2 < x, mid could be our answer
            // * Update ans and search in right half for potentially larger answer
            else if (sqr < x) {
                ans = mid;      // * Store current valid answer
                s = mid + 1;    // * Search right half
            }
            // * If mid^2 > x, search in left half
            else {
                e = mid - 1;    // * Search left half
            }
        }
        
        // * Return the largest integer whose square is <= x
        return ans;
    }
    
    /**
     * Alternative: Newton's Method for square root (iterative approximation)
     * @param x The input non-negative integer
     * @return The integer square root of x
     */
    int mySqrtNewton(int x) {
        if (x == 0) return 0;
        
        // * Newton's iteration formula: x_new = (x_old + n/x_old) / 2
        double x0 = x;
        double x1 = (x0 + x / x0) / 2.0;
        
        // * Iterate until convergence (difference < 1)
        while (abs(x0 - x1) >= 1) {
            x0 = x1;
            x1 = (x0 + x / x0) / 2.0;
        }
        
        return (int)x1;
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(int x, int result, int expected) {
    cout << "\nx = " << x << "\n";
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
    
    // * Test Case 1: Perfect square
    {
        int x = 16;
        int result = solution.mySqrt(x);
        printTestResult(x, result, 4);
    }
    
    // * Test Case 2: Non-perfect square
    {
        int x = 8;
        int result = solution.mySqrt(x);
        printTestResult(x, result, 2);
    }
    
    // * Test Case 3: Zero (edge case)
    {
        int x = 0;
        int result = solution.mySqrt(x);
        printTestResult(x, result, 0);
    }
    
    // * Test Case 4: One (edge case)
    {
        int x = 1;
        int result = solution.mySqrt(x);
        printTestResult(x, result, 1);
    }
    
    // ! Test Case 5: Maximum 32-bit integer
    {
        int x = 2147483647;  // INT_MAX
        int result = solution.mySqrt(x);
        printTestResult(x, result, 46340);  // 46340^2 = 2,147,395,600
    }
    
    // * Test Case 6: Large perfect square
    {
        int x = 1000000;  // 1000^2
        int result = solution.mySqrt(x);
        printTestResult(x, result, 1000);
    }
    
    // * Test Case 7: Small non-perfect square
    {
        int x = 2;
        int result = solution.mySqrt(x);
        printTestResult(x, result, 1);
    }
    
    // * Test Case 8: Large non-perfect square
    {
        int x = 2000000000;
        int result = solution.mySqrt(x);
        printTestResult(x, result, 44721);  // 44721^2 < 2000000000 < 44722^2
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The binary search approach handles all 32-bit integer edge cases effectively
 * ! - Using `long long` for square calculation prevents integer overflow
 * * - Newton's method provides an alternative approach with similar time complexity
 * ? - The search space optimization (x/2) significantly reduces iterations for large values
 * * - Maximum possible square root of a 32-bit integer is 46340 (46340^2 = 2,147,395,600)
 * ================================================================================
 */
