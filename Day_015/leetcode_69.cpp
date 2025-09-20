/**
 * ================================================================================
 * 🌀 LeetCode 69: Sqrt(x) - Binary Search Implementation
 * ================================================================================
 * 
 * 🎯 Problem: Given a non-negative integer `x`, return the integer square root of `x` 
 * rounded down to the nearest integer. The result must also be non-negative.
 * 
 * 📝 Approach: Binary Search
 * 1. Handle edge cases (0 and 1) directly
 * 2. Use binary search in the range [0, x] to find the square root
 * 3. For each midpoint, compare its square with x:
 *    - If square equals x → return mid
 *    - If square is less → store as potential answer and search right
 *    - If square is greater → search left
 * 4. Return the largest integer whose square is less than or equal to x
 * 
 * ⚡ Time Complexity: O(log x) - Binary search halves the search space each iteration
 * 💾 Space Complexity: O(1) - Constant extra space used
 * 
 * 🧠 Key Insight: 
 *    - Binary search is efficient for this problem due to the sorted nature of squares
 *    - Using `long long` prevents integer overflow during calculations
 *    - The search space can be optimized to [0, x/2] for x > 1
 * 
 * 🚀 Optimizations: 
 *    - Early termination for edge cases (0 and 1)
 *    - Midpoint calculation avoids overflow
 *    - Efficient search space reduction
 * ================================================================================
 */

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    //! MAIN FUNCTION: Computes the integer square root of x
    //! @param x The input non-negative integer
    //! @return The largest integer whose square is less than or equal to x
    int mySqrt(int x) {
        //? Handle edge cases
        if (x == 0) return 0;     // √0 = 0
        if (x < 4) return 1;      // √1 = 1, √2 ≈ 1.41, √3 ≈ 1.73
        
        int left = 1;             // Start from 1 (already handled 0 case)
        int right = x / 2;        // For x > 1, √x <= x/2
        int result = 0;
        
        //* Binary search implementation
        while (left <= right) {
            //? Calculate mid point (prevents overflow compared to (left + right)/2)
            int mid = left + (right - left) / 2;
            
            //? Use long long to prevent integer overflow for mid*mid
            long long square = (long long)mid * mid;
            
            if (square == x) {
                return mid;  // Found exact square root
            } 
            else if (square < x) {
                result = mid;       // Potential answer
                left = mid + 1;     // Search right half
            } 
            else {
                right = mid - 1;    // Search left half
            }
        }
        
        return result;  // Return floor of square root
    }
    
    //! ALTERNATIVE: Newton's Method (for reference)
    //! Time: O(log x), Space: O(1)
    int mySqrtNewton(int x) {
        if (x == 0) return 0;
        
        double x0 = x;
        double x1 = (x0 + x / x0) / 2.0;
        
        while (abs(x0 - x1) >= 1) {
            x0 = x1;
            x1 = (x0 + x / x0) / 2.0;
        }
        
        return (int)x1;
    }
};

// ============================================================
// 🧪 TESTING SUITE - Verifies solution with various test cases
// ============================================================

//! Helper function to print test result
void printTestResult(int x, int result, int expected) {
    cout << "\n🔍 x = " << x << "\n";
    cout << "   Result:   " << result << "\n";
    cout << "   Expected: " << expected << "\n";
    cout << "   Status:   " << (result == expected ? "✅ PASS" : "❌ FAIL");
    if (result != expected) {
        cout << " (Expected: " << expected << ")";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    
    // Test Case 1: Perfect square
    {
        int x = 16;
        int result = solution.mySqrt(x);
        printTestResult(x, result, 4);
    }
    
    // Test Case 2: Non-perfect square
    {
        int x = 8;
        int result = solution.mySqrt(x);
        printTestResult(x, result, 2);
    }
    
    // Test Case 3: Minimum value (0)
    {
        int x = 0;
        int result = solution.mySqrt(x);
        printTestResult(x, result, 0);
    }
    
    // Test Case 4: Maximum 32-bit integer (2^31 - 1)
    {
        int x = 2147483647;  // 2^31 - 1
        int result = solution.mySqrt(x);
        printTestResult(x, result, 46340);  // 46340^2 = 2,147,395,600
    }
    
    // Test Case 5: Large perfect square
    {
        int x = 1000000;  // 1000^2
        int result = solution.mySqrt(x);
        printTestResult(x, result, 1000);
    }
    
    // Test Case 6: Small number
    {
        int x = 2;
        int result = solution.mySqrt(x);
        printTestResult(x, result, 1);
    }
    
    // Test Case 7: Large non-perfect square
    {
        int x = 2000000000;  // Between 44721^2 and 44722^2
        int result = solution.mySqrt(x);
        printTestResult(x, result, 44721);
    }
    
    return 0;
}

/*
 * ================================================================================
 * 📝 Additional Notes:
 * - The binary search approach is more intuitive and has the same time complexity
 *   as Newton's method but might be easier to understand and implement
 * - For very large numbers, using `long long` is crucial to prevent overflow
 * - The search space can be further optimized by setting the upper bound to min(x/2, 46340)
 *   since the maximum possible square root of a 32-bit integer is 46340
 * ================================================================================
 */
