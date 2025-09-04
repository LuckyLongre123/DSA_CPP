// LeetCode Problem 50: Pow(x, n)
// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
// Example 1: x = 2.00000, n = 10 → Output: 1024.00000
// Example 2: x = 2.10000, n = 3 → Output: 9.26100
// Example 3: x = 2.00000, n = -2 → Output: 0.25000

#include <climits>
using namespace std;

class Solution {
    public:
        // Function that calculates x^n using binary exponentiation for O(log n) efficiency
        double myPow(double x, int n) {
            long bf = n;  // Use long to handle INT_MIN overflow when negating
            
            // Handle negative exponent: x^(-n) = 1/(x^n)
            if(n < 0){
                x = 1/x;      // Convert to reciprocal
                bf = -bf;     // Make exponent positive
            }
            
            double ans = 1;   // Initialize result
            
            // Binary exponentiation: use binary representation of exponent
            while(bf > 0){
                // If current bit is 1 (odd exponent), multiply result by current base
                if(bf % 2 == 1) ans *= x;
                
                // Square the base for next iteration (x^1 → x^2 → x^4 → x^8...)
                x *= x;
                
                // Move to next bit (divide exponent by 2)
                bf /= 2;
            }
            
            // Return the final result
            return ans;
        }
    };