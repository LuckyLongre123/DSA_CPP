/**
 * ================================================================================
 * 🌀 LeetCode 7: Reverse Integer - Number Manipulation
 * ================================================================================
 * 
 * 🎯 Problem: Given a signed 32-bit integer `x`, return `x` with its digits reversed. 
 * If reversing `x` causes the value to go outside the signed 32-bit integer range 
 * [-2³¹, 2³¹ - 1], then return 0.
 * 
 * 📝 Approach:
 * 1. Initialize result as 0
 * 2. While x is not zero:
 *    - Check for overflow before multiplying by 10
 *    - Get the last digit using modulo 10
 *    - Update result by shifting left and adding the digit
 *    - Remove the last digit from x
 * 3. Return the reversed number or 0 if overflow occurs
 * 
 * ⚡ Time Complexity: O(log₁₀(x)) - We process each digit exactly once
 * 💾 Space Complexity: O(1) - Constant extra space used
 * 
 * 🧠 Key Insight: 
 *    - The main challenge is handling 32-bit integer overflow
 *    - We check for potential overflow before performing operations that could cause it
 *    - Negative numbers are handled naturally by integer division and modulo operations
 * 
 * 🚀 Optimizations: 
 *    - Single pass through the digits
 *    - Early termination on overflow detection
 * ================================================================================
 */

#include <iostream>
#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    //! MAIN FUNCTION: Reverses the digits of a 32-bit signed integer
    //! @param x The input integer to reverse
    //! @return The reversed integer, or 0 if overflow occurs
    int reverse(int x) {
        int reversed = 0;  // * Stores the reversed number
        
        while (x != 0) {
            int digit = x % 10;  // * Extract the last digit
            
            //! Check for potential overflow before updating the result
            //? INT_MAX = 2147483647, so INT_MAX/10 = 214748364
            if (reversed > INT_MAX/10 || (reversed == INT_MAX/10 && digit > 7)) {
                return 0;  // * Would overflow positive
            }
            //? INT_MIN = -2147483648, so INT_MIN/10 = -214748364
            if (reversed < INT_MIN/10 || (reversed == INT_MIN/10 && digit < -8)) {
                return 0;  // * Would overflow negative
            }
            
            //* Update the reversed number
            reversed = reversed * 10 + digit;
            
            //* Remove the last digit from x
            x /= 10;
        }
        
        return reversed;
    }
    
    //! ALTERNATIVE: Using string conversion (for reference, not optimal)
    //! Time: O(log x), Space: O(log x)
    int reverseStringMethod(int x) {
        string s = to_string(x);
        bool isNegative = (s[0] == '-');
        
        if (isNegative) {
            s = s.substr(1);  // Remove the negative sign
        }
        
        std::reverse(s.begin(), s.end());
        
        try {
            int result = stoi(s);
            return isNegative ? -result : result;
        } catch (const std::out_of_range&) {
            return 0;  // Handle overflow
        }
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
    
    // Test Case 1: Positive number
    {
        int x = 123;
        int result = solution.reverse(x);
        printTestResult(x, result, 321);
    }
    
    // Test Case 2: Negative number
    {
        int x = -123;
        int result = solution.reverse(x);
        printTestResult(x, result, -321);
    }
    
    // Test Case 3: Ends with zero
    {
        int x = 120;
        int result = solution.reverse(x);
        printTestResult(x, result, 21);
    }
    
    // Test Case 4: Single digit
    {
        int x = 5;
        int result = solution.reverse(x);
        printTestResult(x, result, 5);
    }
    
    // Test Case 5: Overflow positive
    {
        int x = 1534236469;
        int result = solution.reverse(x);
        printTestResult(x, result, 0);
    }
    
    // Test Case 6: Overflow negative
    {
        int x = -2147483648;  // INT_MIN
        int result = solution.reverse(x);
        printTestResult(x, result, 0);
    }
    
    // Test Case 7: Large number that doesn't overflow when reversed
    {
        int x = 2147447412;
        int result = solution.reverse(x);
        printTestResult(x, result, 2147447412);
    }
    
    // Test Case 8: Zero
    {
        int x = 0;
        int result = solution.reverse(x);
        printTestResult(x, result, 0);
    }
    
    return 0;
}

/*
 * ================================================================================
 * 📝 Additional Notes:
 * - The solution handles all 32-bit integer edge cases, including INT_MIN and INT_MAX
 * - The overflow check is done before the actual operation to prevent undefined behavior
 * - The algorithm works with negative numbers naturally due to how modulo works in C++
 * - For a 64-bit environment, the same logic applies but with different bounds
 * ================================================================================
 */
