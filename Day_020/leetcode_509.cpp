#include <iostream>
using namespace std;

/* 
================================================================================
LeetCode Problem 509: Fibonacci Number
================================================================================
The Fibonacci numbers are defined as follows:
- F(0) = 0
- F(1) = 1
- For n > 1 → F(n) = F(n - 1) + F(n - 2)

Given an integer `n`, return F(n).

--------------------------------------------------------------------------------
Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2

Example 3:
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3

--------------------------------------------------------------------------------
Constraints:
* 0 <= n <= 30
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
The Fibonacci sequence is built by adding the last two numbers to get the next one.  

⚡ Approach (Iterative DP):
1. Handle base cases: F(0) = 0, F(1) = 1.
2. Use variables to keep track of the last two Fibonacci numbers.
3. Loop from 2 to n:
   - F(i) = F(i-1) + F(i-2).
4. Return the final computed number.

⏱ Time Complexity: O(n)  
📦 Space Complexity: O(1)   (since we only use a few variables)
================================================================================
*/

class Solution {
public:
    int fib(int n) {
        // ! Base cases
        if (n == 0) return 0;
        if (n == 1) return 1;

        // * Variables to store previous two results
        int prev2 = 0;   // F(i-2)
        int prev1 = 1;   // F(i-1)
        int curr = 0;    // F(i)

        // * Iteratively calculate Fibonacci
        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2;  // ? Current Fibonacci number
            prev2 = prev1;         // * Update F(i-2)
            prev1 = curr;          // * Update F(i-1)
        }

        return curr;  // * Return F(n)
    }
};

int main() {
    Solution obj;

    // * Example 1
    int n1 = 2;
    cout << "Input: " << n1 << " → Output: " 
         << obj.fib(n1) << endl;

    // * Example 2
    int n2 = 3;
    cout << "Input: " << n2 << " → Output: " 
         << obj.fib(n2) << endl;

    // * Example 3
    int n3 = 4;
    cout << "Input: " << n3 << " → Output: " 
         << obj.fib(n3) << endl;

    return 0;
}
