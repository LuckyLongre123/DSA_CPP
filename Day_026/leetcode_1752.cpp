#include <iostream>
#include <vector>
using namespace std;

/*
================================================================================
LeetCode 1752: Check if Array Is Sorted and Rotated
================================================================================
🔹 Problem Description:
Given an array nums, return true if the array was originally sorted in 
non-decreasing order, then rotated some number of positions (including zero).
Otherwise, return false.

- Duplicates are allowed.
- Rotation: Array A rotated by x positions results in array B such that 
  A[i] == B[(i + x) % A.length].

--------------------------------------------------------------------------------
Example 1:
Input: nums = [3,4,5,1,2]
Output: true
Explanation: Originally [1,2,3,4,5], rotated 3 positions.

Example 2:
Input: nums = [2,1,3,4]
Output: false
Explanation: Cannot be formed by rotating a sorted array.

Example 3:
Input: nums = [1,2,3]
Output: true
Explanation: Already sorted, rotated 0 positions.

--------------------------------------------------------------------------------
Constraints:
* 1 <= nums.length <= 100
* 1 <= nums[i] <= 100
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 Idea: Count "break points" where the order decreases (nums[i] > nums[i+1]).
- A valid rotated sorted array can have at most **1 break point**.
- If there is 1 break point, the first element must be >= last element.
- If there are 0 break points, array is already sorted.

⏱ Time Complexity: O(n)  
📦 Space Complexity: O(1)
================================================================================
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int bPoint = 0;         // * Counter for break points
        int s = nums.size();    // * Array size

        // * Count break points: where current element > next element
        for (int i = 0; i < s - 1; i++) {
            if (nums[i] > nums[i + 1]) bPoint++;
        }

        // ? Case 1: No break points → already sorted
        if (bPoint == 0) return true;

        // ? Case 2: Exactly one break point → valid rotation
        if (bPoint == 1) return nums[0] >= nums[s - 1];

        // ? Case 3: More than one break point → invalid
        return false;
    }
};

// ==================== Driver Code for Testing ====================
int main() {
    Solution obj;

    // * Example 1
    vector<int> nums1 = {3,4,5,1,2};
    cout << "Input: [3,4,5,1,2] → Output: " << boolalpha << obj.check(nums1) << endl;

    // * Example 2
    vector<int> nums2 = {2,1,3,4};
    cout << "Input: [2,1,3,4] → Output: " << boolalpha << obj.check(nums2) << endl;

    // * Example 3
    vector<int> nums3 = {1,2,3};
    cout << "Input: [1,2,3] → Output: " << boolalpha << obj.check(nums3) << endl;

    // * Example 4
    vector<int> nums4 = {1,1,1};
    cout << "Input: [1,1,1] → Output: " << boolalpha << obj.check(nums4) << endl;

    return 0;
}
