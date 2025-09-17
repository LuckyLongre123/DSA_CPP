#include <iostream>
#include <climits>
using namespace std;

/*
================================================================================
LeetCode 29: Divide Two Integers
================================================================================
🔹 Problem Description:
Given two integers `dividend` and `divisor`, divide the two numbers **without using**:
- Multiplication `*`
- Division `/`
- Mod `%`

Return the quotient after dividing `dividend` by `divisor`.

⚠️ Important: 
- Truncate the result towards **zero** (ignore the decimal part).
- If division results in overflow (like INT_MIN / -1), return INT_MAX.

--------------------------------------------------------------------------------
Example 1:
Input:  dividend = 10, divisor = 3
Output: 3
Explanation: 10 / 3 = 3.333... → truncate to 3

Example 2:
Input:  dividend = 7, divisor = -3
Output: -2
Explanation: 7 / -3 = -2.333... → truncate to -2

Example 3:
Input:  dividend = -2147483648, divisor = -1
Output: 2147483647
Explanation: Overflow case → return INT_MAX

--------------------------------------------------------------------------------
Constraints:
* -2^31 <= dividend, divisor <= 2^31 - 1
* divisor != 0
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 We cannot use *, /, % operators.
👉 Idea: Use **bit manipulation** (shifting).
1. Convert both numbers to positive (track sign separately).
2. Keep subtracting the divisor from dividend.
3. To speed up, double the divisor each time using bit shifts (temp <<= 1).
4. Add the multiples to the result.
5. Apply sign (negative if dividend and divisor have different signs).
6. Handle special overflow case.

⏱ Time Complexity: O(log(dividend))
📦 Space Complexity: O(1)
================================================================================
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        // ! Edge Case 1: divisor == 0 → undefined
        if (divisor == 0) return INT_MAX;

        // ! Edge Case 2: Overflow when dividend = INT_MIN and divisor = -1
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // ? Check if result should be negative
        bool negative = (dividend < 0) ^ (divisor < 0);

        // ? Convert both numbers to long long positive values
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long result = 0;

        // ? Perform division using subtraction + bit shifts
        while (a >= b) {
            long long temp = b;      // * Current divisor multiple
            long long multiple = 1;  // * Track how many times divisor fits

            // * Double the divisor until it is too large
            while ((temp << 1) <= a) {
                temp <<= 1;       // Double divisor
                multiple <<= 1;   // Double multiple
            }

            a -= temp;           // - Subtract the biggest divisor chunk
            result += multiple;  // + Add the corresponding multiple
        }

        // ? Apply sign
        if (negative) result = -result;

        // ? Clamp result in 32-bit signed integer range
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return (int)result;
    }
};

// ==================== Driver Code for Testing ====================
int main() {
    Solution obj;

    cout << "Example 1: dividend = 10, divisor = 3 → Output: "
         << obj.divide(10, 3) << endl;

    cout << "Example 2: dividend = 7, divisor = -3 → Output: "
         << obj.divide(7, -3) << endl;

    cout << "Example 3: dividend = -2147483648, divisor = -1 → Output: "
         << obj.divide(-2147483648, -1) << endl;

    return 0;
}
