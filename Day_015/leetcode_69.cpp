#include <iostream>
using namespace std;

/* 
================================================================================
LeetCode Problem 69: Sqrt(x)
================================================================================
Given a non-negative integer x, return the square root of x rounded down 
to the nearest integer.  

The returned integer should be non-negative as well.  

You must not use any built-in exponent function or operator.

--------------------------------------------------------------------------------
Example 1:
Input: x = 4
Output: 2
Explanation: sqrt(4) = 2

Example 2:
Input: x = 8
Output: 2
Explanation: sqrt(8) = 2.828... → round down → 2

--------------------------------------------------------------------------------
Constraints:
* 0 <= x <= 2^31 - 1
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
- We need integer square root of x (only the whole number part).
- Example:
  x = 4 → sqrt = 2
  x = 8 → sqrt = 2.828... → round down → 2
- We can’t use sqrt() function, so we use **Binary Search**.

Steps:
1. Set search range = [0, x-1] (for x > 1).
2. Calculate mid = (s+e)/2.
3. If mid*mid == x → answer found.
4. If mid*mid < x → mid could be answer → go right.
5. If mid*mid > x → go left.
6. Return largest integer whose square <= x.
================================================================================
*/

class Solution {
public:
    int mySqrt(int x) {
        // * Handle edge cases
        if (x == 0) return 0;  
        if (x == 1) return 1;  

        int s = 0;          // * start pointer
        int e = x - 1;      // * end pointer
        int ans = -1;       // * store answer

        // * Binary search loop
        while (s <= e) {
            long long mid = s + (e - s) / 2;  // ? avoid overflow
            long long sqr = mid * mid;        // * mid squared

            if (sqr == x) {
                // ! Perfect square found
                return mid;
            }
            else if (sqr < x) {
                ans = mid;     // * mid could be valid answer
                s = mid + 1;   // * search in right half
            }
            else {
                e = mid - 1;   // * search in left half
            }
        }

        // ! Return final answer (largest integer whose square <= x)
        return ans;
    }
};

int main() {
    Solution obj;

    // * Example test cases
    cout << "Sqrt(4) → " << obj.mySqrt(4) << endl;
    cout << "Sqrt(8) → " << obj.mySqrt(8) << endl;
    cout << "Sqrt(1) → " << obj.mySqrt(1) << endl;
    cout << "Sqrt(0) → " << obj.mySqrt(0) << endl;
    cout << "Sqrt(2147395599) → " << obj.mySqrt(2147395599) << endl; // near INT_MAX

    return 0;
}
