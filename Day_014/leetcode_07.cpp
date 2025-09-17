#include <iostream>
#include <climits>
using namespace std;

/* 
================================================================================
LeetCode Problem 7: Reverse Integer
================================================================================
Given a signed 32-bit integer x, return x with its digits reversed.  

If reversing x causes the value to go outside the signed 32-bit integer range:
    [-2^31, 2^31 - 1]  
then return 0.

--------------------------------------------------------------------------------
Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

--------------------------------------------------------------------------------
Constraints:
* -2^31 <= x <= 2^31 - 1
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
- We need to reverse digits of a given integer.
- But result must be inside 32-bit signed integer range.
- Example:
  x = 123 → reverse = 321
  x = -123 → reverse = -321
  x = 120 → reverse = 21
- Trick:
  1. Take last digit: x % 10
  2. Add it to answer: ans = ans * 10 + digit
  3. Remove last digit: x /= 10
  4. Before multiplying by 10, check overflow:
     if(ans < INT_MIN/10 or ans > INT_MAX/10) return 0
================================================================================
*/

class Solution {
public:
    int reverse(int x) {
        int ans = 0;  // * store reversed number

        // * Process digits until x becomes 0
        while (x != 0) {
            // ! Check overflow before multiplying by 10
            if (ans < INT_MIN / 10 || ans > INT_MAX / 10) 
                return 0;

            // * Take last digit and add to result
            ans = ans * 10 + x % 10;

            // * Remove last digit from x
            x /= 10;
        }

        // * Return final reversed number
        return ans;
    }
};

int main() {
    Solution obj;

    // * Example test cases
    int x1 = 123;
    int x2 = -123;
    int x3 = 120;
    int x4 = 1534236469; // overflow case

    cout << "Reverse of 123 → " << obj.reverse(x1) << endl;
    cout << "Reverse of -123 → " << obj.reverse(x2) << endl;
    cout << "Reverse of 120 → " << obj.reverse(x3) << endl;
    cout << "Reverse of 1534236469 (overflow) → " << obj.reverse(x4) << endl;

    return 0;
}
