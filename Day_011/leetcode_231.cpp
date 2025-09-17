#include <iostream>
using namespace std;

/* 
================================================================================
LeetCode Problem 231: Power of Two
================================================================================
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that:
    n == 2^x

--------------------------------------------------------------------------------
Example 1:
Input: n = 1
Output: true
Explanation: 2^0 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 2^4 = 16

Example 3:
Input: n = 3
Output: false

--------------------------------------------------------------------------------
Constraints:
* -2^31 <= n <= 2^31 - 1
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
- Power of two means number can be written as 2^x.
  (1, 2, 4, 8, 16, 32, …)
- Only one "1" bit is present in binary form of powers of two.
  Example: 8 = 1000, 16 = 10000
- Trick:
  n & (n-1) = 0  → true only for powers of two.
- Also check that n > 0 (because negative numbers and 0 are not valid).
================================================================================
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // ? Check n is greater than 0
        // ! Important because powers of two are always positive
        if (n <= 0) return false;

        // * Trick: n & (n-1) removes the lowest set bit
        // * For powers of two → only one set bit exists → result = 0
        return (n & (n - 1)) == 0;
    }
};

int main() {
    Solution obj;

    // * Example test cases
    int n1 = 1;
    int n2 = 16;
    int n3 = 3;

    cout << "Is " << n1 << " power of two? " 
         << (obj.isPowerOfTwo(n1) ? "true" : "false") << endl;

    cout << "Is " << n2 << " power of two? " 
         << (obj.isPowerOfTwo(n2) ? "true" : "false") << endl;

    cout << "Is " << n3 << " power of two? " 
         << (obj.isPowerOfTwo(n3) ? "true" : "false") << endl;

    return 0;
}
