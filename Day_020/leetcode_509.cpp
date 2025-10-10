/**
 * ================================================================================
 * LeetCode 509: Fibonacci Number - Dynamic Programming Fundamentals
 * ================================================================================
 * 
 * ! Problem: The Fibonacci numbers, commonly denoted F(n), form a sequence where
 * ! each number is the sum of the two preceding ones, starting from 0 and 1.
 * ! Given n, calculate F(n).
 * ! 
 * ! F(0) = 0, F(1) = 1
 * ! F(n) = F(n-1) + F(n-2) for n > 1
 * 
 * * Approach:
 * * 1. Handle base cases: F(0) = 0, F(1) = 1
 * * 2. Use space-optimized dynamic programming with three variables
 * * 3. Iterate from 2 to n, computing each Fibonacci number
 * * 4. Keep track of only the last two numbers (prev2, prev1)
 * * 5. Update values in a rolling window fashion
 * 
 * ? Time Complexity: O(n) - Single pass through numbers from 2 to n
 * ? Space Complexity: O(1) - Only three variables used regardless of input size
 * 
 * TODO Key Insight: 
 * *    - Classic introduction to Dynamic Programming concepts
 * *    - Shows how to optimize space from O(n) (array) to O(1) (variables)
 * *    - Demonstrates the "rolling window" technique for DP problems
 * 
 * * Optimizations: 
 * *    - Space-optimized: O(1) instead of O(n) array storage
 * *    - Single pass: No recursion overhead
 * *    - Early termination: Base cases handled immediately
 * ================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    /**
     * Computes the nth Fibonacci number using space-optimized DP
     * @param n The position in the Fibonacci sequence (0-indexed)
     * @return The nth Fibonacci number
     */
    int fib(int n) {
        // ! Base Case 1: F(0) = 0
        if (n == 0) return 0;
         
        // ! Base Case 2: F(1) = 1
        if (n == 1) return 1;
         
        // * Initialize rolling window variables
        int prev2 = 0;     // * F(i-2): Two positions back
        int prev1 = 1;     // * F(i-1): One position back
        int curr;          // * F(i): Current Fibonacci number
         
        // * Iterate from position 2 to n
        for (int i = 2; i <= n; ++i) {
            // ? Core Fibonacci formula: F(n) = F(n-1) + F(n-2)
            curr = prev1 + prev2;
             
            // * Slide the window: Move values forward
            prev2 = prev1;  // * What was F(i-1) is now F(i-2)
            prev1 = curr;   // * What is F(i) is now F(i-1)
        }
         
        return curr;
    }
     
    /**
     * Alternative: Recursive approach with memoization (for educational comparison)
     * @param n The position in the Fibonacci sequence
     * @return The nth Fibonacci number
     */
    int fibRecursive(int n) {
        vector<int> memo(n + 1, -1);  // * Memoization array
        return fibHelper(n, memo);
    }
     
private:
    /**
     * Helper function for recursive memoization approach
     */
    int fibHelper(int n, vector<int>& memo) {
        // ! Base cases
        if (n == 0) return 0;
        if (n == 1) return 1;
         
        // ? Check if already computed
        if (memo[n] != -1) return memo[n];
         
        // * Compute and store result
        memo[n] = fibHelper(n - 1, memo) + fibHelper(n - 2, memo);
        return memo[n];
    }
};
 
// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================
 
/**
 * Helper function to print test result
 */
void printTestResult(int n, int result, int expected) {
    cout << "\nF(" << n << ")\n";
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
     
    // * Test Case 1: Base case F(0)
    {
        int n = 0;
        int result = solution.fib(n);
        printTestResult(n, result, 0);
    }
     
    // * Test Case 2: Base case F(1)
    {
        int n = 1;
        int result = solution.fib(n);
        printTestResult(n, result, 1);
    }
     
    // * Test Case 3: Small number F(2)
    {
        int n = 2;
        int result = solution.fib(n);
        printTestResult(n, result, 1);
    }
     
    // * Test Case 4: Classic example F(3)
    {
        int n = 3;
        int result = solution.fib(n);
        printTestResult(n, result, 2);
    }
     
    // * Test Case 5: Medium value F(10)
    {
        int n = 10;
        int result = solution.fib(n);
        printTestResult(n, result, 55);
    }
     
    // * Test Case 6: Larger value F(20)
    {
        int n = 20;
        int result = solution.fib(n);
        printTestResult(n, result, 6765);
    }
     
    // * Test Case 7: Upper constraint F(30)
    {
        int n = 30;
        int result = solution.fib(n);
        printTestResult(n, result, 832040);
    }
     
    // * Test Case 8: Compare iterative vs recursive approach
    {
        int n = 15;
        int resultIterative = solution.fib(n);
        int resultRecursive = solution.fibRecursive(n);
        cout << "\nF(" << n << ") - Method Comparison\n";
        cout << "   Iterative:  " << resultIterative << "\n";
        cout << "   Recursive:  " << resultRecursive << "\n";
        cout << "   Match:      " << (resultIterative == resultRecursive ? "YES" : "NO") << "\n";
    }
     
    return 0;
}
 
/*
 * ================================================================================
 * TODO Additional Notes:
 * * - This is a foundational Dynamic Programming problem for beginners
 * ! - The space-optimized approach demonstrates how to reduce O(n) to O(1) space
 * * - Three common approaches: Recursion (slow), Memoization (fast but O(n) space),
 *     Iteration (fast and O(1) space)
 * ? - For very large n (beyond 32-bit int), consider using long long or BigInteger
 * * - The golden ratio formula exists but has precision issues for large n
 * ================================================================================
 */