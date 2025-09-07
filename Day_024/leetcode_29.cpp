// LeetCode Problem 29: Divide Two Integers
// Given two integers dividend and divisor, divide two integers without using multiplication, 
// division, and mod operator. Return the quotient after dividing dividend by divisor.
// Example 1: Input: dividend = 10, divisor = 3, Output: 3 (10/3 = 3.333... → 3)
// Example 2: Input: dividend = 7, divisor = -3, Output: -2 (7/(-3) = -2.333... → -2)
// Example 3: Input: dividend = -2147483648, divisor = -1, Output: 2147483647 (overflow case)

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to divide two integers using bit manipulation and binary search approach
    int divide(int dividend, int divisor) {
        // Edge case: Division by zero
        if (divisor == 0) return INT_MAX;
        
        // Edge case: INT_MIN / (-1) would cause overflow (result = INT_MAX + 1)
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Determine if result should be negative using XOR
        // XOR returns true if exactly one operand is negative
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to positive numbers using long long to handle INT_MIN
        // llabs() handles the special case of INT_MIN correctly
        long long a = llabs((long long)dividend);  // Absolute value of dividend
        long long b = llabs((long long)divisor);   // Absolute value of divisor

        long long result = 0;  // Initialize result to 0

        // Binary division algorithm: repeatedly subtract largest possible multiple
        while (a >= b) {
            long long temp = b;      // Current divisor multiple
            long long multiple = 1;  // How many times we've doubled the divisor

            // Keep doubling the divisor until it exceeds the remaining dividend
            // This finds the largest power of 2 that fits in the remaining dividend
            while ((temp << 1) <= a) {  // temp << 1 is equivalent to temp * 2
                temp <<= 1;      // Double the divisor
                multiple <<= 1;  // Double the multiple
            }

            // Subtract the largest fitting multiple from dividend
            a -= temp;
            // Add the corresponding multiple to our result
            result += multiple;
        }

        // Apply negative sign if needed
        if (negative) result = -result;

        // Handle overflow cases
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return (int)result;
    }
};
