// LeetCode Problem 50: Pow(x, n)
// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
// Example 1: Input: x = 2.00000, n = 10, Output: 1024.00000
// Example 2: Input: x = 2.10000, n = 3, Output: 9.26100
// Example 3: Input: x = 2.00000, n = -2, Output: 0.25000

#include <climits>
using namespace std;

class Solution {
    public:
        // Function to calculate x^n using binary exponentiation (fast exponentiation)
        double myPow(double x, int n) {
            long bf = n;  // Use long to handle INT_MIN overflow when negating
            
            // Handle negative exponent: x^(-n) = (1/x)^n
            if(n < 0){
                x = 1/x;      // Convert x to 1/x
                bf = -bf;     // Make exponent positive
            }
            
            double ans = 1;   // Initialize result
    
            // Binary exponentiation algorithm
            // Time complexity: O(log n), Space complexity: O(1)
            while(bf > 0){
                // If current bit is 1 (odd exponent), multiply result by current base
                if(bf % 2 == 1) ans *= x;
                
                // Square the base for next iteration (x^2, x^4, x^8, ...)
                x *= x;
                
                // Right shift exponent by 1 (divide by 2)
                bf /= 2;
            }
            
            return ans;
        }
    };