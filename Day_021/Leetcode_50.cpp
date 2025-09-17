#include <iostream>
#include <climits>
using namespace std;

/* 
================================================================================
LeetCode Problem 50: Pow(x, n)
================================================================================
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

--------------------------------------------------------------------------------
Example 1:
Input:  x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input:  x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input:  x = 2.00000, n = -2
Output: 0.25000
Explanation: 2^(-2) = 1 / (2^2) = 1 / 4 = 0.25

--------------------------------------------------------------------------------
Constraints:
* -100.0 < x < 100.0
* -2^31 <= n <= 2^31 - 1
* n is an integer.
* Either x is not zero or n > 0.
* -10^4 <= x^n <= 10^4
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
We need to calculate power: x^n.  
⚡ Challenge: If n is very large, multiplying x repeatedly will be too slow.  

👉 Trick: Use **Binary Exponentiation (Fast Power)**:
- If n is even → x^n = (x^2)^(n/2)
- If n is odd  → x^n = x * (x^2)^(n/2)
- Repeat until exponent becomes 0.

⚡ Also handle negative powers:
x^(-n) = (1/x)^n

⏱ Time Complexity: O(log n)  
📦 Space Complexity: O(1)
================================================================================
*/

class Solution {
public:
    double myPow(double x, int n) {
        long exp = n;   // ! Use long to handle INT_MIN safely

        // ! If exponent is negative, invert base and make exponent positive
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double ans = 1.0;  // * Result initialized to 1

        // * Binary Exponentiation loop
        while (exp > 0) {
            // ? If current exponent is odd → multiply answer with base
            if (exp % 2 == 1) {
                ans *= x;
            }

            // * Square the base for next step (x, x^2, x^4, x^8, ...)
            x *= x;

            // * Reduce exponent by half
            exp /= 2;
        }

        return ans;  // * Final result
    }
};

int main() {
    Solution obj;

    // * Example 1
    double x1 = 2.0;
    int n1 = 10;
    cout << "Input: x=" << x1 << ", n=" << n1 
         << " → Output: " << obj.myPow(x1, n1) << endl;

    // * Example 2
    double x2 = 2.1;
    int n2 = 3;
    cout << "Input: x=" << x2 << ", n=" << n2 
         << " → Output: " << obj.myPow(x2, n2) << endl;

    // * Example 3
    double x3 = 2.0;
    int n3 = -2;
    cout << "Input: x=" << x3 << ", n=" << n3 
         << " → Output: " << obj.myPow(x3, n3) << endl;

    return 0;
}
