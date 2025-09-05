// LeetCode Problem 53: Maximum Subarray
// Given an integer array nums, find the contiguous subarray (containing at least one number) 
// which has the largest sum and return its sum.
// Example 1: Input: nums = [-2,1,-3,4,-1,2,1,-5,4], Output: 6 (subarray [4,-1,2,1])
// Example 2: Input: nums = [1], Output: 1
// Example 3: Input: nums = [5,4,-1,7,8], Output: 23 (entire array)

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
    public:
        // Function to find maximum sum of contiguous subarray using Kadane's Algorithm
        int maxSubArray(vector<int>& nums) {
            int currSum = 0;        // Current subarray sum
            int maxSum = INT_MIN;   // Maximum sum found so far (initialize to smallest possible value)
            
            // Kadane's Algorithm: Dynamic Programming approach
            // Time Complexity: O(n), Space Complexity: O(1)
            for(int val : nums){
                currSum += val;                    // Add current element to current sum
                maxSum = max(currSum, maxSum);     // Update maximum if current sum is larger
                
                // If current sum becomes negative, reset it to 0
                // (starting fresh is better than carrying negative sum)
                if(currSum < 0) currSum = 0;
            }
            
            return maxSum;
            // Using Kadane's Algorithm - optimal solution for maximum subarray problem
        }
    };