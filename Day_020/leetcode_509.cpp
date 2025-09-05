// LeetCode Problem 509: Fibonacci Number
// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence,
// such that each number is the sum of the two preceding ones, starting from 0 and 1.
// F(0) = 0, F(1) = 1, F(n) = F(n - 1) + F(n - 2) for n > 1.
// Example 1: Input: n = 2, Output: 1 (F(2) = F(1) + F(0) = 1 + 0 = 1)
// Example 2: Input: n = 3, Output: 2 (F(3) = F(2) + F(1) = 1 + 1 = 2)

#include <vector>
using namespace std;

class Solution {
    public:
        // Function to calculate nth Fibonacci number using iterative approach
        int fib(int n) {
            // Base cases: F(0) = 0, F(1) = 1
            if (n == 0) return 0;
            if (n == 1) return 1;
    
            // Use three variables to store previous two numbers and current result
            int prev2 = 0;  // F(n-2): stores F(i-2)
            int prev1 = 1;  // F(n-1): stores F(i-1)
            int curr;       // F(n): stores F(i) = F(i-1) + F(i-2)
            
            // Iteratively calculate Fibonacci numbers from 2 to n
            for (int i = 2; i <= n; ++i) {
                curr = prev1 + prev2;  // F(i) = F(i-1) + F(i-2)
                prev2 = prev1;         // Update F(i-2) for next iteration
                prev1 = curr;          // Update F(i-1) for next iteration
            }
    
            return curr;  // Return F(n)
        }
    };