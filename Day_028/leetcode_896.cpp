#include <iostream>
#include <vector>
using namespace std;

/*
================================================================================
LeetCode 896: Monotonic Array
================================================================================
🔹 Problem Description:
An array is monotonic if it is either:
1. Monotone increasing: nums[i] <= nums[i+1] for all valid i
2. Monotone decreasing: nums[i] >= nums[i+1] for all valid i

Return true if the array is monotonic, false otherwise.

--------------------------------------------------------------------------------
Example 1:
Input:  nums = [1,2,2,3]
Output: true
Explanation: Array is monotone increasing.

Example 2:
Input:  nums = [6,5,4,4]
Output: true
Explanation: Array is monotone decreasing.

Example 3:
Input:  nums = [1,3,2]
Output: false
Explanation: Array is neither increasing nor decreasing.

Constraints:
* 1 <= nums.length <= 10^5
* -10^5 <= nums[i] <= 10^5
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 Idea: Track both possibilities (increasing & decreasing) simultaneously.

Steps:
1. Initialize flags: inc = true, dec = true
2. For each adjacent pair:
   - If nums[i] > nums[i-1] → can't be decreasing → dec = false
   - If nums[i] < nums[i-1] → can't be increasing → inc = false
3. Array is monotonic if inc || dec is true

⏱ Time Complexity: O(n)  
📦 Space Complexity: O(1)
================================================================================
*/

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();

        bool inc = true;  // * Monotone increasing flag
        bool dec = true;  // * Monotone decreasing flag

        // * Check each adjacent pair
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) dec = false; // ? Violation of decreasing
            if(nums[i] < nums[i-1]) inc = false; // ? Violation of increasing
        }

        // * Return true if at least one direction is valid
        return inc || dec;
    }
};

// ==================== Driver Code for Testing ====================
int main() {
    Solution obj;

    // * Example 1
    vector<int> nums1 = {1,2,2,3};
    cout << "Input: [1,2,2,3] → Output: " << boolalpha << obj.isMonotonic(nums1) << endl;

    // * Example 2
    vector<int> nums2 = {6,5,4,4};
    cout << "Input: [6,5,4,4] → Output: " << boolalpha << obj.isMonotonic(nums2) << endl;

    // * Example 3
    vector<int> nums3 = {1,3,2};
    cout << "Input: [1,3,2] → Output: " << boolalpha << obj.isMonotonic(nums3) << endl;

    // * Example 4 (all equal)
    vector<int> nums4 = {2,2,2,2};
    cout << "Input: [2,2,2,2] → Output: " << boolalpha << obj.isMonotonic(nums4) << endl;

    return 0;
}
