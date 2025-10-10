/**
 * ================================================================================
 * LeetCode 50: Pow(x, n) - Fast Binary Exponentiation
 * ================================================================================
 * 
 * ! Problem: Implement pow(x, n), which calculates x raised to the power n (x^n).
 * ! The solution must be efficient and handle both positive and negative exponents,
 * ! as well as edge cases like zero exponent and negative base values.
 * 
 * * Approach: Binary Exponentiation (Fast Power Algorithm)
 * * 1. Handle negative exponents by converting x to 1/x and making exponent positive
 * * 2. Initialize result as 1
 * * 3. While exponent is greater than 0:
 * *    - If exponent is odd, multiply result by current x
 * *    - Square x (x = x * x)
 * *    - Divide exponent by 2 (using integer division)
 * * 4. Return the accumulated result
 * 
 * ? Time Complexity: O(log n) - We divide the exponent by 2 in each iteration
 * ? Space Complexity: O(1) - Constant extra space used
 * 
 * TODO Key Insight: 
 * *    - Instead of multiplying x by itself n times (O(n)), we use the property:
 * *      x^n = (x^2)^(n/2) when n is even
 * *      x^n = x * (x^2)^((n-1)/2) when n is odd
 * *    - This reduces the number of multiplications exponentially
 * *    - Example: x^10 = (x^2)^5 = x^2 * (x^4)^2 = x^2 * (x^8)^1
 * 
 * * Optimizations: 
 * *    - Binary representation: We process the exponent bit by bit
 * *    - Single pass through the bits of exponent
 * *    - Avoids recursion to save stack space
 * ================================================================================
 */

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
 
class Solution {
public:
    /**
     * Calculates x raised to the power n using binary exponentiation
     * @param x The base (can be any real number)
     * @param n The exponent (can be any integer including negative)
     * @return The result of x^n
     */
    double myPow(double x, int n) {
        long long exponent = n;  // * Use long long to handle INT_MIN edge case
        
        // ! Handle negative exponent by inverting the base
        // ? If n is negative, x^n = (1/x)^|n|
        if (n < 0) {
            x = 1 / x;           // * Convert to reciprocal
            exponent = -exponent;  // * Make exponent positive
        }
        
        double result = 1.0;  // * Initialize result (x^0 = 1)
        
        // * Binary exponentiation loop
        while (exponent > 0) {
            // ! Check if current exponent is odd
            // ? If odd, we need to multiply result by current x
            if (exponent % 2 == 1) {
                result *= x;  // * Accumulate the odd power
            }
            
            // * Square the base for next iteration
            // ? This effectively doubles the power: x -> x^2 -> x^4 -> x^8 ...
            x *= x;
            
            // * Divide exponent by 2 (process next bit)
            // ? This moves to the next significant bit in binary representation
            exponent /= 2;
        }
        
        return result;
    }
};
 
// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================
 
/**
 * Helper function to print test result with precision handling
 */
void printTestResult(double x, int n, double result, double expected) {
    cout << "\nx = " << x << ", n = " << n << "\n";
    cout << "   Result:   " << result << "\n";
    cout << "   Expected: " << expected << "\n";
     
    // * Check if results are approximately equal (floating point comparison)
    double epsilon = 1e-9;
    bool passed = abs(result - expected) < epsilon;
     
    cout << "   Status:   " << (passed ? "PASS" : "FAIL");
    if (!passed) {
        cout << " (Difference: " << abs(result - expected) << ")";
    }
    cout << "\n";
}
 
int main() {
    Solution solution;
     
    // * Test Case 1: Positive base, positive exponent
    {
        double x = 2.0;
        int n = 10;
        double result = solution.myPow(x, n);
        printTestResult(x, n, result, 1024.0);
    }
     
    // * Test Case 2: Positive base, negative exponent
    {
        double x = 2.0;
        int n = -2;
        double result = solution.myPow(x, n);
        printTestResult(x, n, result, 0.25);
    }
     
    // * Test Case 3: Decimal base, positive exponent
    {
        double x = 2.1;
        int n = 3;
        double result = solution.myPow(x, n);
        printTestResult(x, n, result, 9.261);
    }
     
    // * Test Case 4: Any base, exponent zero
    {
        double x = 5.0;
        int n = 0;
        double result = solution.myPow(x, n);
        printTestResult(x, n, result, 1.0);
    }
     
    // * Test Case 5: Base 1, large exponent
    {
        double x = 1.0;
        int n = 1000000;
        double result = solution.myPow(x, n);
        printTestResult(x, n, result, 1.0);
    }
     
    // ! Test Case 6: Negative base, odd exponent
    {
        double x = -2.0;
        int n = 3;
        double result = solution.myPow(x, n);
        printTestResult(x, n, result, -8.0);
    }
     
    // ! Test Case 7: Negative base, even exponent
    {
        double x = -2.0;
        int n = 4;
        double result = solution.myPow(x, n);
        printTestResult(x, n, result, 16.0);
    }
     
    // ! Test Case 8: Edge case - INT_MIN exponent
    {
        double x = 2.0;
        int n = -2147483648;  // INT_MIN
        double result = solution.myPow(x, n);
        // Result should be extremely close to 0 but not exactly 0
        cout << "\nx = " << x << ", n = " << n << "\n";
        cout << "   Result: " << result << " (Should be very small, close to 0)\n";
        cout << "   Status: " << ((result >= 0 && result < 1e-300) ? "PASS" : "FAIL") << "\n";
    }
     
    // * Test Case 9: Base 0 (special case)
    {
        double x = 0.0;
        int n = 5;
        double result = solution.myPow(x, n);
        printTestResult(x, n, result, 0.0);
    }
     
    // * Test Case 10: Large exponent
    {
        double x = 2.0;
        int n = 20;
        double result = solution.myPow(x, n);
        printTestResult(x, n, result, 1048576.0);
    }
     
    return 0;
}
 
/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The binary exponentiation algorithm is one of the most elegant algorithms
 * *   in computer science, reducing exponential time to logarithmic time
 * ! - Key edge case: INT_MIN cannot be negated in 32-bit integers, so we use long long
 * * - The algorithm works by processing the binary representation of the exponent
 * * - Example: 2^13 where 13 = 1101₂ (binary)
 * *   Step by step: 13 = 8 + 4 + 1 = 2³ + 2² + 2⁰
 * *   So 2^13 = 2^8 × 2^4 × 2^1
 * ? - This is also known as "Exponentiation by Squaring" or "Russian Peasant Method"
 * * - Applications: Modular exponentiation in cryptography, matrix exponentiation,
 * *   computing Fibonacci numbers, and many competitive programming problems
 * ================================================================================
 */