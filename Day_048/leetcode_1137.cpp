/**
 * ================================================================================
 * LeetCode 1178: N-th Tribonacci Number - Dynamic Programming Optimization
 * ================================================================================
 * 
 * ! Problem: The Tribonacci sequence Tn is defined as follows:
 * ! T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
 * ! Given n, return the value of Tn.
 * 
 * * Approach:
 * * 1. Handle base cases: T0 = 0, T1 = 1, T2 = 1
 * * 2. Use three variables (a, b, c) to track last three values
 * * 3. Iterate from index 3 to n:
 * *    - Calculate next value: d = a + b + c
 * *    - Slide window: a = b, b = c, c = d
 * * 4. Return the final value stored in c
 * 
 * ? Time Complexity: O(n) - Single pass through the sequence from 3 to n
 * ? Space Complexity: O(1) - Only four variables used regardless of n
 * 
 * TODO Key Insight: 
 * *    - Space-optimized DP: Instead of storing all values, keep only last 3
 * *    - Sliding window technique eliminates need for array storage
 * *    - Each iteration builds on previous three values
 * 
 * * Optimizations: 
 * *    - Constant space instead of O(n) array
 * *    - Early termination for base cases
 * *    - Single loop iteration without recursion overhead
 * ================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Computes the n-th Tribonacci number using space-optimized DP
     * @param n The index of the Tribonacci number to compute (0 <= n <= 37)
     * @return The n-th Tribonacci number
     */
    int tribonacci(int n) {
        // ! Base case: T0 = 0
        if (n == 0)
            return 0;
        
        // ! Base cases: T1 = 1, T2 = 1
        if (n == 1 || n == 2)
            return 1;
        
        // * Initialize sliding window with first three Tribonacci numbers
        int a = 0;  // ? T(i-3): Three positions back
        int b = 1;  // ? T(i-2): Two positions back
        int c = 1;  // ? T(i-1): One position back
        int d = 0;  // * T(i): Current Tribonacci number
        
        // * Iterate from index 3 to n, building sequence incrementally
        for (int i = 3; i <= n; i++) {
            // ! Calculate next Tribonacci number: sum of previous three
            d = a + b + c;
            
            // * Slide the window forward by one position
            a = b;  // ? Move T(i-2) to T(i-3) position
            b = c;  // ? Move T(i-1) to T(i-2) position
            c = d;  // ? Move T(i) to T(i-1) position for next iteration
        }
        
        // * Return the n-th Tribonacci number
        return c;
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result with sequence visualization
 */
void printTestResult(int n, int result, int expected) {
    cout << "\nn = " << n << "\n";
    cout << "   Result:   " << result << "\n";
    cout << "   Expected: " << expected << "\n";
    cout << "   Status:   " << (result == expected ? "✓ PASS" : "✗ FAIL");
    if (result != expected) {
        cout << " (Expected: " << expected << ")";
    }
    cout << "\n";
}

/**
 * Helper function to generate and display Tribonacci sequence
 */
void displaySequence(int limit) {
    Solution solution;
    cout << "\n=== Tribonacci Sequence (First " << limit << " terms) ===\n";
    cout << "Index: ";
    for (int i = 0; i < limit; i++) {
        cout << i << "\t";
    }
    cout << "\nValue: ";
    for (int i = 0; i < limit; i++) {
        cout << solution.tribonacci(i) << "\t";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    
    cout << "================================================================================\n";
    cout << "              TRIBONACCI NUMBER - COMPREHENSIVE TEST SUITE\n";
    cout << "================================================================================\n";
    
    // * Display sequence for visualization
    displaySequence(10);
    
    cout << "\n=== Running Test Cases ===\n";
    
    // * Test Case 1: Base case T0
    {
        int n = 0;
        int result = solution.tribonacci(n);
        printTestResult(n, result, 0);
    }
    
    // * Test Case 2: Base case T1
    {
        int n = 1;
        int result = solution.tribonacci(n);
        printTestResult(n, result, 1);
    }
    
    // * Test Case 3: Base case T2
    {
        int n = 2;
        int result = solution.tribonacci(n);
        printTestResult(n, result, 1);
    }
    
    // * Test Case 4: First computed value T3
    {
        int n = 3;
        int result = solution.tribonacci(n);
        printTestResult(n, result, 2);
    }
    
    // * Test Case 5: Small value T4
    {
        int n = 4;
        int result = solution.tribonacci(n);
        printTestResult(n, result, 4);
    }
    
    // * Test Case 6: Medium value - Example from problem
    {
        int n = 10;
        int result = solution.tribonacci(n);
        printTestResult(n, result, 149);
    }
    
    // * Test Case 7: Larger value T20
    {
        int n = 20;
        int result = solution.tribonacci(n);
        printTestResult(n, result, 35890);
    }
    
    // * Test Case 8: Maximum constraint value T25
    {
        int n = 25;
        int result = solution.tribonacci(n);
        printTestResult(n, result, 1389537);
    }
    
    // ! Test Case 9: Near upper bound T30
    {
        int n = 30;
        int result = solution.tribonacci(n);
        printTestResult(n, result, 53798080);
    }
    
    // ! Test Case 10: Maximum value T37 (upper constraint)
    {
        int n = 37;
        int result = solution.tribonacci(n);
        printTestResult(n, result, 2082876103);
    }
    
    cout << "\n================================================================================\n";
    cout << "                         ALL TESTS COMPLETED\n";
    cout << "================================================================================\n";
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The solution uses space-optimized DP with O(1) space complexity
 * ! - Constraint: 0 <= n <= 37, ensures result fits in 32-bit signed integer
 * * - The sliding window technique is a common pattern in sequence problems
 * ? - Alternative approaches: Recursion (inefficient), Memoization, Matrix exponentiation
 * * - This iterative approach is optimal for the given constraints
 * ! - For very large n, matrix exponentiation would provide O(log n) time complexity
 * ? - The sequence grows exponentially, similar to Fibonacci but faster
 * ================================================================================
 */