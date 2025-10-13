/**
 * ================================================================================
 * LeetCode 2798: Difference of Sums - Mathematical Optimization
 * ================================================================================
 * 
 * ! Problem: Given two positive integers n and m, calculate the difference between
 * ! the sum of all integers from 1 to n, minus twice the sum of integers divisible by m.
 * ! Return (sum of 1..n) - 2 * (sum of integers divisible by m in range 1..n)
 * 
 * * Approach:
 * * 1. Calculate total sum of integers from 1 to n using formula: n*(n+1)/2
 * * 2. Find count of integers divisible by m: divisibleCount = n / m
 * * 3. Calculate sum of divisible integers: m * (count*(count+1))/2
 * * 4. Return totalSum - 2 * divisibleSum
 * 
 * ? Time Complexity: O(1) - Only arithmetic operations, no loops or recursion
 * ? Space Complexity: O(1) - Constant extra space (few integer variables)
 * 
 * * Key Insight:
 * *    The divisible sum follows a pattern: m, 2m, 3m, ..., km where k = n/m
 * *    This equals m * (1 + 2 + 3 + ... + k) = m * k*(k+1)/2
 * *    We recognize this as m times the sum formula, avoiding iteration entirely
 * 
 * * Optimizations:
 * *    - Mathematical formulas eliminate need for loops
 * *    - Works for any values of n and m instantly
 * *    - Integer division handles edge cases naturally
 * ================================================================================
 */

#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * Calculates the difference of sums with divisibility constraint
     * 
     * ! Algorithm: Uses mathematical formulas to compute sums in O(1) time
     * ? Rather than iterating through all numbers, we apply the arithmetic
     * ? progression formula to both the total sum and the divisible sum
     * 
     * @param n Upper bound of the range (1 to n inclusive)
     * @param m Divisor for identifying which numbers to exclude
     * @return int The calculated difference: totalSum - 2 * divisibleSum
     */
    int differenceOfSums(int n, int m) {
        // * Calculate sum of all integers from 1 to n
        // ? Formula: sum = n * (n + 1) / 2
        // ? Example: n=5 → 5*6/2 = 15 (which is 1+2+3+4+5)
        int totalSum = n * (n + 1) / 2;
        
        // * Count how many integers from 1 to n are divisible by m
        // ? These are: m, 2m, 3m, ..., km where k = n/m
        // ? Example: n=10, m=3 → divisibleCount = 10/3 = 3 (numbers: 3, 6, 9)
        int divisibleCount = n / m;
        
        // * Calculate sum of all divisible integers: m + 2m + 3m + ... + km
        // ? This equals: m * (1 + 2 + 3 + ... + k) = m * k*(k+1)/2
        // ? Example: m=3, count=3 → sum = 3 * (3*4/2) = 3 * 6 = 18 (which is 3+6+9)
        int divisibleSum = m * (divisibleCount * (divisibleCount + 1)) / 2;
        
        // * Return final result: totalSum - 2 * divisibleSum
        // ? We subtract twice the divisible sum as per problem requirements
        // ? Example: totalSum=15, divisibleSum=18 → 15 - 2*18 = 15 - 36 = -21
        return totalSum - 2 * divisibleSum;
    }
};

// ============================================================
// * TESTING SUITE - Validates solution with comprehensive cases
// ============================================================

/**
 * Helper function to display test results
 */
void printTestResult(int n, int m, int result, int expected) {
    cout << "\nn = " << n << ", m = " << m << "\n";
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
    
    // * Test Case 1: Small values, m divides n evenly
    {
        int n = 10, m = 3;
        int result = solution.differenceOfSums(n, m);
        // * n=10: sum = 1+2+...+10 = 55
        // * divisible by 3: 3+6+9 = 18
        // * result = 55 - 2*18 = 55 - 36 = 19
        printTestResult(n, m, result, 19);
    }
    
    // * Test Case 2: m = 1 (all numbers are divisible)
    {
        int n = 5, m = 1;
        int result = solution.differenceOfSums(n, m);
        // * n=5: sum = 15
        // * divisible by 1: 1+2+3+4+5 = 15
        // * result = 15 - 2*15 = -15
        printTestResult(n, m, result, -15);
    }
    
    // * Test Case 3: m > n (no divisible numbers except if m divides n)
    {
        int n = 5, m = 10;
        int result = solution.differenceOfSums(n, m);
        // * n=5: sum = 15
        // * divisible by 10: none (count = 0, sum = 0)
        // * result = 15 - 2*0 = 15
        printTestResult(n, m, result, 15);
    }
    
    // * Test Case 4: m = n (exactly one divisible number)
    {
        int n = 7, m = 7;
        int result = solution.differenceOfSums(n, m);
        // * n=7: sum = 28
        // * divisible by 7: 7 (count = 1, sum = 7)
        // * result = 28 - 2*7 = 14
        printTestResult(n, m, result, 14);
    }
    
    // * Test Case 5: m = 2 (even numbers)
    {
        int n = 8, m = 2;
        int result = solution.differenceOfSums(n, m);
        // * n=8: sum = 36
        // * divisible by 2: 2+4+6+8 = 20
        // * result = 36 - 2*20 = -4
        printTestResult(n, m, result, -4);
    }
    
    // * Test Case 6: Single number
    {
        int n = 1, m = 1;
        int result = solution.differenceOfSums(n, m);
        // * n=1: sum = 1
        // * divisible by 1: 1
        // * result = 1 - 2*1 = -1
        printTestResult(n, m, result, -1);
    }
    
    // * Test Case 7: Larger numbers
    {
        int n = 100, m = 5;
        int result = solution.differenceOfSums(n, m);
        // * n=100: sum = 100*101/2 = 5050
        // * divisible by 5: count = 20, sum = 5*(20*21/2) = 5*210 = 1050
        // * result = 5050 - 2*1050 = 2950
        printTestResult(n, m, result, 2950);
    }
    
    // * Test Case 8: n and m are same, larger value
    {
        int n = 50, m = 50;
        int result = solution.differenceOfSums(n, m);
        // * n=50: sum = 1275
        // * divisible by 50: 50 (count = 1, sum = 50)
        // * result = 1275 - 2*50 = 1175
        printTestResult(n, m, result, 1175);
    }
    
    return 0;
}

/*
 * ================================================================================
 * * Additional Notes:
 * ! The solution demonstrates the power of mathematical thinking - what could be
 * ! solved with nested loops in O(n) time is instead solved in O(1) constant time
 * * The formula for sum of arithmetic progression is fundamental to many problems
 * ? Understanding these patterns helps optimize solutions significantly
 * * Integer division (/) works perfectly for counting divisible numbers
 * ? The approach naturally handles edge cases without special conditions
 * ================================================================================
 */