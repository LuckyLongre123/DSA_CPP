/*
 * LeetCode 896: Monotonic Array
 * 
 * Problem Description:
 * An array is monotonic if it is either monotone increasing or monotone decreasing.
 * - Monotone increasing: nums[i] <= nums[i+1] for all valid i
 * - Monotone decreasing: nums[i] >= nums[i+1] for all valid i
 * 
 * Examples:
 * Input: nums = [1,2,2,3] → Output: true (monotone increasing)
 * Input: nums = [6,5,4,4] → Output: true (monotone decreasing)  
 * Input: nums = [1,3,2] → Output: false (neither increasing nor decreasing)
 * 
 * Approach: Two-Flag Method
 * - Track both increasing and decreasing possibilities simultaneously
 * - If we find a violation of increasing order, mark inc = false
 * - If we find a violation of decreasing order, mark dec = false
 * - Array is monotonic if at least one direction remains valid
 * 
 * Time Complexity: O(n) - single pass through array
 * Space Complexity: O(1) - only using two boolean flags
 */

#include <vector>
using namespace std;

class Solution {
    public:
        bool isMonotonic(vector<int>& nums) {
            int n = nums.size();
            
            // Initialize flags for both directions
            bool inc = true;  // Assume array can be monotone increasing
            bool dec = true;  // Assume array can be monotone decreasing
            
            // Check each adjacent pair
            for(int i = 1; i < n; i++) {
                // If current element is greater than previous, it can't be decreasing
                if(nums[i] > nums[i-1]) {
                    dec = false;
                }
                // If current element is less than previous, it can't be increasing
                if(nums[i] < nums[i-1]) {
                    inc = false;
                }
            }
            
            // Array is monotonic if it's either increasing OR decreasing
            return inc || dec;
        }
    };