/**
 * ================================================================================
 * 🌀 LeetCode 231: Power of Two - Bit Manipulation Solution
 * ================================================================================
 * 
 * 🎯 Problem: Given an integer n, return true if it is a power of two. Otherwise, 
 * return false. An integer n is a power of two if there exists an integer x such 
 * that n == 2^x.
 * 
 * 📝 Approach: Bit Manipulation
 * 1. Check if n is positive (powers of two are always positive)
 * 2. Use bitwise operation: n & (n-1) == 0
 *    - This works because powers of two have exactly one '1' bit in binary
 *    - Subtracting 1 flips all bits after the '1' bit (including the '1' bit)
 *    - AND operation with original number will be 0 only for powers of two
 * 
 * ⚡ Time Complexity: O(1) - Constant time bitwise operations
 * 💾 Space Complexity: O(1) - No extra space used
 * 
 * 🧠 Key Insight: 
 *    - Powers of two in binary have exactly one '1' bit
 *    - n & (n-1) removes the rightmost '1' bit
 * 
 * 🚀 Optimizations: 
 *    - Single line solution with O(1) time and space
 *    - No loops or recursion needed
 * ================================================================================
 */

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    //! MAIN FUNCTION: Checks if a number is a power of two
    //! @param n The input integer to check
    //! @return true if n is a power of two, false otherwise
    bool isPowerOfTwo(int n) {
        //? Check if n is positive and has exactly one '1' in binary
        //! n & (n-1) == 0 only when n has exactly one '1' bit
        //! n > 0 ensures we don't consider 0 or negative numbers
        return n > 0 && (n & (n - 1)) == 0;
    }
};

// ============================================================
// 🧪 TESTING SUITE - Verifies solution with various test cases
// ============================================================

//! Helper function to print test result
void printTestResult(int n, bool result, bool expected) {
    cout << "🔍 n = " << n << "\n";
    cout << "   Result:   " << (result ? "true" : "false") << "\n";
    cout << "   Expected: " << (expected ? "true" : "false") << "\n";
    cout << "   Status:   " << (result == expected ? "✅ PASS" : "❌ FAIL") << "\n";
}

int main() {
    Solution solution;
    
    // Test Case 1: Smallest power of two (2^0 = 1)
    {
        int n = 1;
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, true);
    }
    
    // Test Case 2: Power of two (2^4 = 16)
    {
        int n = 16;
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, true);
    }
    
    // Test Case 3: Not a power of two
    {
        int n = 3;
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, false);
    }
    
    // Test Case 4: Zero (not a power of two)
    {
        int n = 0;
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, false);
    }
    
    // Test Case 5: Negative number (not a power of two)
    {
        int n = -8;
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, false);
    }
    
    // Test Case 6: Large power of two (2^30)
    {
        int n = 1 << 30;
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, true);
    }
    
    return 0;
}

/*
 * ================================================================================
 * 📝 Additional Notes:
 * - The solution handles all edge cases including 0, negative numbers, and INT_MIN
 * - The bitwise approach is more efficient than mathematical approaches using log
 * - For 32-bit integers, the largest power of two is 2^30 (1,073,741,824)
 * - The solution works for both positive and negative zeros (treated the same)
 * ================================================================================
 */
