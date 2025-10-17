/**
 * ================================================================================
 * LeetCode 70: Climbing Stairs - Dynamic Programming Fundamentals
 * ================================================================================
 * 
 * ! Problem: You are climbing a staircase. It takes n steps to reach the top.
 * ! Each time you can either climb 1 or 2 steps. In how many distinct ways 
 * ! can you climb to the top?
 * 
 * * Approach:
 * * 1. Recognize this as a Fibonacci sequence problem
 * * 2. Base cases: 1 step = 1 way, 2 steps = 2 ways
 * * 3. For n steps: ways(n) = ways(n-1) + ways(n-2)
 * * 4. Use iterative approach with two variables to save space
 * * 5. Build up from base cases to n
 * 
 * ? Time Complexity: O(n) - Single pass through n steps
 * ? Space Complexity: O(1) - Only three variables used
 * 
 * TODO Key Insight: 
 * *    - This is a classic Fibonacci pattern in disguise
 * *    - Each position can be reached from either 1 step back or 2 steps back
 * *    - Space optimization reduces O(n) to O(1) by keeping only last 2 values
 * *    - The pattern emerges: 1, 2, 3, 5, 8, 13... (Fibonacci starting at 1)
 * 
 * * Optimizations: 
 * *    - Iterative solution avoids recursion overhead
 * *    - Constant space instead of array storage
 * *    - Early return for base cases (n <= 2)
 * ================================================================================
 */

#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * Calculates the number of distinct ways to climb n stairs
     * @param n The total number of steps in the staircase
     * @return The number of distinct ways to reach the top
     */
    int climbStairs(int n) {
        // ! Base cases: handle small staircases directly
        if (n <= 2) {
            return n;  // * 1 step = 1 way, 2 steps = 2 ways
        }
        
        // * Initialize tracking variables for last two positions
        int one = 1;      // * Ways to reach step 1
        int two = 2;      // * Ways to reach step 2
        int current = 0;  // * Ways to reach current step
        
        // * Build up from step 3 to step n
        for (int i = 3; i <= n; i++) {
            // ? Core recurrence relation: current step reachable from previous 2 steps
            current = one + two;  // * ways(i) = ways(i-1) + ways(i-2)
            
            // * Slide the window forward
            one = two;      // * Update: what was 2 steps back is now 1 step back
            two = current;  // * Update: current becomes the new reference point
        }
        
        // * Return the final computed value
        return two;
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(int n, int result, int expected) {
    cout << "\nn = " << n << "\n";
    cout << "   Result:   " << result << " distinct ways\n";
    cout << "   Expected: " << expected << " distinct ways\n";
    cout << "   Status:   " << (result == expected ? "PASS ✓" : "FAIL ✗");
    if (result != expected) {
        cout << " (Expected: " << expected << ")";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Single step
    {
        int n = 1;
        int result = solution.climbStairs(n);
        printTestResult(n, result, 1);
    }
    
    // * Test Case 2: Two steps - demonstrates both paths
    {
        int n = 2;
        int result = solution.climbStairs(n);
        printTestResult(n, result, 2);
    }
    
    // * Test Case 3: Three steps - shows Fibonacci pattern emerging
    {
        int n = 3;
        int result = solution.climbStairs(n);
        printTestResult(n, result, 3);
    }
    
    // * Test Case 4: Small staircase
    {
        int n = 4;
        int result = solution.climbStairs(n);
        printTestResult(n, result, 5);
    }
    
    // * Test Case 5: Medium staircase
    {
        int n = 5;
        int result = solution.climbStairs(n);
        printTestResult(n, result, 8);
    }
    
    // * Test Case 6: Larger staircase - tests iteration efficiency
    {
        int n = 10;
        int result = solution.climbStairs(n);
        printTestResult(n, result, 89);
    }
    
    // * Test Case 7: Even larger - demonstrates O(n) performance
    {
        int n = 20;
        int result = solution.climbStairs(n);
        printTestResult(n, result, 10946);
    }
    
    // * Test Case 8: Maximum practical input
    {
        int n = 30;
        int result = solution.climbStairs(n);
        printTestResult(n, result, 1346269);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The solution produces the Fibonacci sequence starting at F(1)=1, F(2)=2
 * ! - For very large n (n > 45), consider using long long to prevent overflow
 * * - This pattern appears in many combinatorial problems (paths, sequences, etc.)
 * ? - Alternative approaches: recursion with memoization O(n) time/space, matrix exponentiation O(log n)
 * * - The space-optimized iterative approach is optimal for this problem's constraints
 * ================================================================================
 */