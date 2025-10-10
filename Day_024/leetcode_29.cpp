/**
 * ================================================================================
 * LeetCode 29: Divide Two Integers - Bit Manipulation & Binary Search
 * ================================================================================
 * 
 * ! Problem: Given two integers `dividend` and `divisor`, divide two integers
 * ! without using multiplication, division, and mod operator. Return the quotient
 * ! after dividing dividend by divisor. The integer division should truncate toward zero.
 * ! 
 * ! Constraints:
 * ! - Both dividend and divisor are 32-bit signed integers
 * ! - The divisor will never be 0
 * ! - Return INT_MAX if the result overflows
 * 
 * * Approach: Bit Manipulation with Exponential Search
 * * 1. Handle special cases (division by 0, overflow scenarios)
 * * 2. Determine the sign of the result using XOR
 * * 3. Work with absolute values to simplify logic
 * * 4. Use bit shifting (doubling) to find the largest multiple
 * * 5. Subtract and accumulate the quotient iteratively
 * * 6. Apply the sign and check for overflow before returning
 * 
 * ? Time Complexity: O(log²n) - Outer loop runs O(log n) times, inner loop also O(log n)
 * ? Space Complexity: O(1) - Only constant extra space used
 * 
 * TODO Key Insight: 
 * *    - Instead of subtracting divisor repeatedly (O(n)), we use bit shifting
 * *    - Bit shifting left by 1 doubles the value (equivalent to multiplying by 2)
 * *    - This reduces time complexity from O(n) to O(log²n)
 * *    - Example: 43 ÷ 8 = (8×4) + (8×1) → multiple additions instead of repeated subtraction
 * 
 * * Optimizations: 
 * *    - Using long long to prevent overflow during intermediate calculations
 * *    - XOR operation to determine result sign efficiently
 * *    - Exponential search (doubling) instead of linear search
 * ================================================================================
 */

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * Divides two integers without using multiplication, division, or mod operator
     * @param dividend The number to be divided
     * @param divisor The number to divide by
     * @return The quotient (truncated toward zero), or INT_MAX if overflow
     */
    int divide(int dividend, int divisor) {
        // ! Edge Case 1: Division by zero (though problem states divisor != 0)
        if (divisor == 0) return INT_MAX;
        
        // ! Edge Case 2: Overflow case - INT_MIN / -1 would exceed INT_MAX
        // ? INT_MIN = -2147483648, -INT_MIN = 2147483648 > INT_MAX (2147483647)
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // * Determine the sign of the result using XOR
        // ? If signs differ (one positive, one negative), result is negative
        bool negative = (dividend < 0) ^ (divisor < 0);

        // * Convert both numbers to positive using long long to avoid overflow
        // ? Using long long prevents overflow when converting INT_MIN to positive
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long result = 0;  // * Accumulates the quotient

        // * Main Division Algorithm: Subtract multiples of divisor using bit shifting
        while (a >= b) {
            long long temp = b;      // * Temporary value for doubling
            long long multiple = 1;  // * Tracks how many times we've doubled
            
            // ! Inner Loop: Find the largest multiple by doubling (bit shifting)
            // ? Keep doubling until temp exceeds dividend
            // ? Example: For 43 ÷ 8 → 8, 16, 32 (stop here as 64 > 43)
            while ((temp << 1) <= a) {
                temp <<= 1;        // * Equivalent to temp *= 2
                multiple <<= 1;    // * Equivalent to multiple *= 2
            }

            // * Subtract the largest found multiple from dividend
            a -= temp;
            
            // * Add the corresponding multiple to result
            result += multiple;
        }

        // * Apply the sign to the result
        if (negative) result = -result;

        // ! Final overflow check before returning
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return (int)result;
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(int dividend, int divisor, int result, int expected) {
    cout << "\ndividend = " << dividend << ", divisor = " << divisor << "\n";
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
    
    // * Test Case 1: Basic division with positive numbers
    {
        int dividend = 10, divisor = 3;
        int result = solution.divide(dividend, divisor);
        printTestResult(dividend, divisor, result, 3);
    }
    
    // * Test Case 2: Negative dividend
    {
        int dividend = -10, divisor = 3;
        int result = solution.divide(dividend, divisor);
        printTestResult(dividend, divisor, result, -3);
    }
    
    // * Test Case 3: Both negative (result positive)
    {
        int dividend = -10, divisor = -3;
        int result = solution.divide(dividend, divisor);
        printTestResult(dividend, divisor, result, 3);
    }
    
    // * Test Case 4: Large numbers requiring multiple doublings
    {
        int dividend = 43, divisor = 8;
        int result = solution.divide(dividend, divisor);
        printTestResult(dividend, divisor, result, 5);
    }
    
    // ! Test Case 5: Overflow case - INT_MIN / -1
    {
        int dividend = INT_MIN, divisor = -1;
        int result = solution.divide(dividend, divisor);
        printTestResult(dividend, divisor, result, INT_MAX);
    }
    
    // * Test Case 6: Dividend smaller than divisor
    {
        int dividend = 3, divisor = 10;
        int result = solution.divide(dividend, divisor);
        printTestResult(dividend, divisor, result, 0);
    }
    
    // * Test Case 7: Exact division
    {
        int dividend = 100, divisor = 10;
        int result = solution.divide(dividend, divisor);
        printTestResult(dividend, divisor, result, 10);
    }
    
    // * Test Case 8: Division by 1
    {
        int dividend = 42, divisor = 1;
        int result = solution.divide(dividend, divisor);
        printTestResult(dividend, divisor, result, 42);
    }
    
    // ! Test Case 9: INT_MIN divided by 1
    {
        int dividend = INT_MIN, divisor = 1;
        int result = solution.divide(dividend, divisor);
        printTestResult(dividend, divisor, result, INT_MIN);
    }
    
    // * Test Case 10: Large positive numbers
    {
        int dividend = 2147483647, divisor = 2;
        int result = solution.divide(dividend, divisor);
        printTestResult(dividend, divisor, result, 1073741823);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - This solution uses bit manipulation to achieve O(log²n) time complexity
 * ! - The key insight is using exponential search (doubling) instead of linear subtraction
 * * - Bit shifting left (<<) is equivalent to multiplying by 2, but much faster
 * ? - Example walkthrough for 43 ÷ 8:
 * ?   Step 1: 8×1=8, 8×2=16, 8×4=32 (stop, as 8×8=64 > 43)
 * ?   Step 2: 43-32=11, quotient=4
 * ?   Step 3: 8×1=8 (stop, as 8×2=16 > 11)
 * ?   Step 4: 11-8=3, quotient=4+1=5
 * ?   Step 5: 3<8, stop. Final quotient=5
 * * - The algorithm handles negative numbers by working with absolute values and XOR sign
 * ! - Critical overflow case: INT_MIN/-1 must return INT_MAX
 * ================================================================================
 */
