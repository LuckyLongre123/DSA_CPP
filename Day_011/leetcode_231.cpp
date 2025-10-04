/**
 * ================================================================================
 * LeetCode 231: Power of Two - Bit Manipulation
 * ================================================================================
 * 
 * ! Problem: Given an integer `n`, return `true` if it is a power of two. 
 * ! Otherwise, return `false`. An integer `n` is a power of two if there exists 
 * ! an integer `x` such that n == 2^x.
 * 
 * * Approach (Bit Manipulation):
 * * 1. Check if n is positive (powers of two are always positive)
 * * 2. Use the bit trick: n & (n-1) removes the rightmost set bit
 * * 3. For powers of two, there's only ONE bit set, so n & (n-1) == 0
 * * 4. Return true if both conditions are met
 * 
 * ? Time Complexity: O(1) - Single bitwise operation
 * ? Space Complexity: O(1) - No extra space used
 * 
 * TODO Key Insight: 
 * *    - Powers of two have exactly one bit set in binary representation
 * *    - Example: 8 = 1000, 16 = 10000, 32 = 100000
 * *    - The trick n & (n-1) removes the rightmost 1-bit
 * *    - If n is a power of 2, after removing that bit, result is 0
 * 
 * * Binary Examples: 
 * *    - 8:  1000 & 0111 = 0000 (power of 2)
 * *    - 6:  0110 & 0101 = 0100 (not power of 2)
 * *    - 16: 10000 & 01111 = 00000 (power of 2)
 * ================================================================================
 */

#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * Determines if a number is a power of two
     * @param n The integer to check
     * @return true if n is a power of two, false otherwise
     */
    bool isPowerOfTwo(int n) {
        // ! Check if n is positive AND has only one bit set
        // * n > 0: Powers of two must be positive
        // * (n & (n-1)) == 0: Only one bit is set (power of 2 property)
        return (n > 0 && (n & (n - 1)) == 0);
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print binary representation
 */
string toBinary(int n) {
    if (n == 0) return "0";
    string binary = "";
    unsigned int num = n;  // Use unsigned for proper binary display
    for (int i = 31; i >= 0; i--) {
        if ((num >> i) & 1) {
            binary += to_string((num >> i) & 1);
            for (int j = i - 1; j >= 0; j--) {
                binary += to_string((num >> j) & 1);
            }
            break;
        }
    }
    return binary.empty() ? "0" : binary;
}

/**
 * Helper function to print test result
 */
void printTestResult(int n, bool result, bool expected) {
    cout << "\nn = " << n << " (binary: " << toBinary(n) << ")\n";
    cout << "   Result:   " << (result ? "true" : "false") << "\n";
    cout << "   Expected: " << (expected ? "true" : "false") << "\n";
    cout << "   Status:   " << (result == expected ? "PASS" : "FAIL") << "\n";
    
    if (n > 0) {
        int bitCheck = n & (n - 1);
        cout << "   Analysis: " << n << " & " << (n-1) << " = " << bitCheck;
        cout << " (binary: " << toBinary(n) << " & " << toBinary(n-1) << " = " << toBinary(bitCheck) << ")\n";
    }
}

int main() {
    Solution solution;
    
    // * Test Case 1: Basic power of two
    {
        int n = 1;  // 2^0
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, true);
    }
    
    // * Test Case 2: Power of two (2^1)
    {
        int n = 2;
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, true);
    }
    
    // * Test Case 3: Not a power of two
    {
        int n = 3;
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, false);
    }
    
    // * Test Case 4: Power of two (2^2)
    {
        int n = 4;
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, true);
    }
    
    // * Test Case 5: Not a power of two
    {
        int n = 5;
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, false);
    }
    
    // * Test Case 6: Large power of two (2^4)
    {
        int n = 16;
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, true);
    }
    
    // ! Test Case 7: Negative number
    {
        int n = -16;
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, false);
    }
    
    // ! Test Case 8: Zero (edge case)
    {
        int n = 0;
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, false);
    }
    
    // * Test Case 9: Large power of two (2^10)
    {
        int n = 1024;
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, true);
    }
    
    // * Test Case 10: Not a power of two (close to power)
    {
        int n = 1023;  // 2^10 - 1
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, false);
    }
    
    // * Test Case 11: Large power of two (2^30)
    {
        int n = 1073741824;
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, true);
    }
    
    // * Test Case 12: Not power of two (multiple bits set)
    {
        int n = 6;  // 110 in binary (two bits set)
        bool result = solution.isPowerOfTwo(n);
        printTestResult(n, result, false);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The bit manipulation trick is elegant: n & (n-1) removes rightmost 1-bit
 * ! - Powers of two have exactly ONE bit set: 1, 10, 100, 1000, 10000, ...
 * * - When you subtract 1 from power of 2, all bits after the single 1 become 1
 * ? - Example: 8 (1000) - 1 = 7 (0111), then 1000 & 0111 = 0000
 * * - Alternative approach: Use loop to divide by 2, but O(log n) vs O(1)
 * ! - Remember to check n > 0 because negative numbers and zero aren't powers of 2
 * ================================================================================
 */