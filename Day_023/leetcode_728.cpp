/*
LeetCode 728: Self Dividing Numbers

Problem Description:
A self-dividing number is a number that is divisible by every digit it contains.
- For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
- A self-dividing number is not allowed to contain the digit zero.

Given two integers left and right, return a list of all the self-dividing numbers 
in the range [left, right].

Examples:
Input: left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]

Input: left = 47, right = 85
Output: [48, 55, 66, 77]

Approach:
1. Iterate through each number from left to right
2. For each number, check if it's self-dividing:
   - Extract each digit
   - Check if digit is 0 (invalid) or if number is not divisible by digit
   - If all digits divide the number, it's self-dividing
3. Add valid self-dividing numbers to result

Time Complexity: O((right - left + 1) * log10(max_number))
Space Complexity: O(1) excluding output array
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        
        // Iterate through each number in the given range
        for (int i = left; i <= right; i++) {
            int num = i;  // Copy of current number to extract digits
            bool flag = true;  // Flag to track if number is self-dividing
            
            // Extract each digit and check divisibility
            while (num > 0) {
                int curDigit = num % 10;  // Get the rightmost digit
                
                // Check two conditions for self-dividing number:
                // 1. Digit should not be 0 (division by zero)
                // 2. Original number should be divisible by this digit
                if (curDigit == 0 || i % curDigit != 0) {
                    flag = false;  // Not a self-dividing number
                    break;  // No need to check remaining digits
                }
                
                num /= 10;  // Remove the rightmost digit
            }
            
            // If all digits passed the test, add to result
            if (flag)
                result.push_back(i);
        }
        
        return result;
    }
};