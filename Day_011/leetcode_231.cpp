// LeetCode Problem 231: Power of Two
// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2^x.
// Example 1: Input: n = 1, Output: true (2^0 = 1)
// Example 2: Input: n = 16, Output: true (2^4 = 16)
// Example 3: Input: n = 3, Output: false

class Solution {
    public:
        // Function that checks if a given integer is a power of two
        bool isPowerOfTwo(int n) {
            // Use bit manipulation trick: A power of two has only one bit set
            // For any power of two: n & (n-1) == 0
            // Example: 8 (1000) & 7 (0111) = 0000 = 0
            // Also check n > 0 to handle negative numbers and zero
            return (n > 0 && (n & (n - 1)) == 0);
        }
    };