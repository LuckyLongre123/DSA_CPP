// LeetCode Problem 7: Reverse Integer
// Given a signed 32-bit integer x, return x with its digits reversed.
// If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
// Example 1: x = 123 → Output: 321
// Example 2: x = -123 → Output: -321
// Example 3: x = 120 → Output: 21

#include <climits>
using namespace std;

class Solution {
    public:
        // Function that reverses the digits of a 32-bit signed integer with overflow protection
        int reverse(int x) {        
            int ans = 0;  // Variable to store the reversed number
            
            // Process each digit from right to left
            while(x != 0){
                // Check for overflow before multiplying by 10
                // If ans would overflow when multiplied by 10, return 0
                if(ans < INT_MIN/10 || ans > INT_MAX/10) return 0;
                
                // Extract last digit and add to reversed number
                ans = ans * 10 + x % 10;  // Build reversed number digit by digit
                x /= 10;                  // Remove the last digit from original number
            }
            
            // Return the reversed number (or 0 if overflow occurred)
            return ans;
        }
    };