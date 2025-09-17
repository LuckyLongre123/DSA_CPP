#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
================================================================================
LeetCode 283: Move Zeroes
================================================================================
🔹 Problem Description:
Given an integer array nums, move all 0's to the end of it while maintaining 
the relative order of the non-zero elements. Do this in-place without making a copy.

--------------------------------------------------------------------------------
Example 1:
Input:  nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input:  nums = [0]
Output: [0]

Constraints:
* 1 <= nums.length <= 10^4
* -2^31 <= nums[i] <= 2^31 - 1
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 Idea: Two-pointer approach

Steps:
1. Initialize zeroIndex = 0 to track position for next non-zero element.
2. Scan array with pointer j from 0 to n-1.
3. When nums[j] is non-zero:
   - Swap it with nums[zeroIndex]
   - Increment zeroIndex
4. All zeros naturally move to the end, and non-zero elements maintain their relative order.

⏱ Time Complexity: O(n)  
📦 Space Complexity: O(1) - in-place operation
================================================================================
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zeroIndex = 0;  // * Points to position for next non-zero element

        for(int j = 0; j < n; j++) {
            if(nums[j] != 0) {
                swap(nums[zeroIndex++], nums[j]);  // * Move non-zero forward, zeros shift naturally
            }
        }
    }
};

// ==================== Driver Code for Testing ====================
int main() {
    Solution obj;

    // * Example 1
    vector<int> nums1 = {0,1,0,3,12};
    obj.moveZeroes(nums1);
    cout << "After moving zeroes: [";
    for(int i = 0; i < nums1.size(); i++) cout << nums1[i] << (i < nums1.size()-1 ? "," : "");
    cout << "]" << endl;

    // * Example 2
    vector<int> nums2 = {0};
    obj.moveZeroes(nums2);
    cout << "After moving zeroes: [";
    for(int i = 0; i < nums2.size(); i++) cout << nums2[i] << (i < nums2.size()-1 ? "," : "");
    cout << "]" << endl;

    return 0;
}
