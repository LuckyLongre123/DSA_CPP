#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/* 
================================================================================
LeetCode Problem 53: Maximum Subarray
================================================================================
Given an integer array nums, find the contiguous subarray (containing at least 
one number) which has the largest sum and return its sum.

--------------------------------------------------------------------------------
Example 1:
Input:  nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: Subarray [4,-1,2,1] has the largest sum = 6.

Example 2:
Input:  nums = [1]
Output: 1

Example 3:
Input:  nums = [5,4,-1,7,8]
Output: 23
Explanation: Entire array is the answer.
--------------------------------------------------------------------------------
Constraints:
* 1 <= nums.length <= 10^5
* -10^4 <= nums[i] <= 10^4
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
We need to find the subarray with maximum sum.

👉 Brute Force Approach:
   - Check all possible subarrays and calculate their sums.
   - Time: O(n^2) (too slow for large inputs).

👉 Optimized Approach: Kadane's Algorithm
   - Keep a running sum of elements (`currSum`).
   - If `currSum` becomes negative, reset it to 0 (because negative sum reduces 
     future totals).
   - Track the maximum sum seen so far in `maxSum`.

⏱ Time Complexity: O(n)  
📦 Space Complexity: O(1)
================================================================================
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;        // * Current running sum
        int maxSum = INT_MIN;   // * Initialize with smallest possible number

        // * Kadane's Algorithm
        for (int val : nums) {
            currSum += val;                   // + Add current element
            maxSum = max(maxSum, currSum);    // ? Update maximum if needed

            // ! If running sum becomes negative, reset to 0
            if (currSum < 0) currSum = 0;
        }

        return maxSum;  // * Final maximum subarray sum
    }
};

int main() {
    Solution obj;

    // * Example 1
    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Input: nums = [-2,1,-3,4,-1,2,1,-5,4]"
         << " → Output: " << obj.maxSubArray(nums1) << endl;

    // * Example 2
    vector<int> nums2 = {1};
    cout << "Input: nums = [1]"
         << " → Output: " << obj.maxSubArray(nums2) << endl;

    // * Example 3
    vector<int> nums3 = {5,4,-1,7,8};
    cout << "Input: nums = [5,4,-1,7,8]"
         << " → Output: " << obj.maxSubArray(nums3) << endl;

    return 0;
}
