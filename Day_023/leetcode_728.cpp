#include <iostream>
#include <vector>
using namespace std;

/*
================================================================================
LeetCode 728: Self Dividing Numbers
================================================================================
🔹 Problem Description:
A self-dividing number is a number that is divisible by every digit it contains.
- Example: 128 is self-dividing because 128 % 1 == 0, 128 % 2 == 0, 128 % 8 == 0
- A self-dividing number cannot contain the digit zero.

Given two integers left and right, return all self-dividing numbers in range [left, right].

--------------------------------------------------------------------------------
Example 1:
Input:  left = 1, right = 22
Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]

Example 2:
Input:  left = 47, right = 85
Output: [48,55,66,77]

--------------------------------------------------------------------------------
Constraints:
* 1 <= left <= right <= 10^4
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 We need to check each number between left and right.
👉 For each number:
   - Break into digits.
   - If any digit is 0 → ❌ not valid.
   - If number is not divisible by a digit → ❌ not valid.
   - Otherwise ✅ it's a self-dividing number.
👉 Collect all valid numbers into the result.

⏱ Time Complexity: O((right - left + 1) * log10(max_number))  
📦 Space Complexity: O(1) excluding result storage
================================================================================
*/

class Solution {
public:
    // ? Function to check if a number is self-dividing
    bool isSelfDividing(int num) {
        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;   // * Extract rightmost digit
            if (digit == 0 || num % digit != 0) {
                return false;        // ! Not self-dividing
            }
            temp /= 10;              // * Remove last digit
        }
        return true;                 // * Passed all checks
    }

    // ? Function to return all self-dividing numbers in [left, right]
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) {    // ? Check number
                result.push_back(i);    // + Add valid number
            }
        }
        return result;
    }
};

int main() {
    Solution obj;

    // * Example 1
    int left1 = 1, right1 = 22;
    vector<int> res1 = obj.selfDividingNumbers(left1, right1);
    cout << "Input: left = 1, right = 22 → Output: ";
    for (int num : res1) cout << num << " ";
    cout << endl;

    // * Example 2
    int left2 = 47, right2 = 85;
    vector<int> res2 = obj.selfDividingNumbers(left2, right2);
    cout << "Input: left = 47, right = 85 → Output: ";
    for (int num : res2) cout << num << " ";
    cout << endl;

    return 0;
}
