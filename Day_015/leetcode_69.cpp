/*
 * LeetCode Problem 69: Sqrt(x)
 * 
 * Problem Description:
 * Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
 * The returned integer should be non-negative as well.
 * You must not use any built-in exponent function or operator.
 * 
 * Example 1:
 * Input: x = 4
 * Output: 2
 * Explanation: The square root of 4 is 2.
 * 
 * Example 2:
 * Input: x = 8
 * Output: 2
 * Explanation: The square root of 8 is 2.828..., and since we round it down to the nearest integer, 2 is returned.
 * 
 * Approach: Binary Search
 * - Use binary search to find the largest integer whose square is <= x
 * - Search space: [0, x-1] (for x > 1)
 * - For each mid, check if mid^2 <= x
 * - If yes, update answer and search right half
 * - If no, search left half
 * 
 * Time Complexity: O(log x)
 * Space Complexity: O(1)
 */

class Solution {
    public:
        int mySqrt(int x) {
            // Initialize binary search boundaries
            int s = 0;          // Start pointer
            int e = x - 1;      // End pointer (x-1 because sqrt(x) < x for x > 1)
            int ans = -1;       // Variable to store the answer
    
            // Handle edge cases
            if(x == 0) return 0;    // sqrt(0) = 0
            if(x == 1) return 1;    // sqrt(1) = 1
            
            // Binary search to find the square root
            while(s <= e) {
                // Calculate mid point to avoid integer overflow
                long long int mid = s + (e - s) / 2;
                
                // Calculate square of mid using long long to prevent overflow
                long long int sqr = mid * mid;
    
                // If perfect square found, return immediately
                if(sqr == x) return mid;
                
                // If mid^2 < x, mid could be our answer
                // Update ans and search in right half for potentially larger answer
                else if(sqr < x) {
                    ans = mid;          // Store current valid answer
                    s = mid + 1;        // Search right half
                }
                // If mid^2 > x, search in left half
                else {
                    e = mid - 1;        // Search left half
                }
            }
            
            // Return the largest integer whose square is <= x
            return ans;
        }
};