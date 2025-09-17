#include <iostream>
#include <vector>
using namespace std;

/* 
================================================================================
LeetCode Problem 33: Search in Rotated Sorted Array
================================================================================
You are given an integer array `nums` sorted in ascending order with **distinct values**.  
Before being passed into the function, the array might be rotated at some pivot index `k`.  
For example, `[0,1,2,4,5,6,7]` might become `[4,5,6,7,0,1,2]`.  

Given the array `nums` after rotation and an integer `target`, return the index of 
`target` if it exists, otherwise return `-1`.

--------------------------------------------------------------------------------
Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

--------------------------------------------------------------------------------
Constraints:
* 1 <= nums.length <= 5000
* -10^4 <= nums[i] <= 10^4
* All values of nums are unique
* nums is rotated at most once
* -10^4 <= target <= 10^4
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
Normal Binary Search doesn’t directly work because the array is rotated.

⚡ Trick: In every step of binary search:
- One half (left or right) is always **sorted**.
- Check if target lies in the sorted half:
  - If yes → move into that half.
  - If no → move into the other half.

⏱ Time Complexity: O(log n)  
📦 Space Complexity: O(1)
================================================================================
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;                  // * Start pointer
        int e = nums.size() - 1;    // * End pointer

        while (s <= e) {
            int mid = s + (e - s) / 2;  // * Middle index (safe from overflow)

            // ? If element found at mid → return index
            if (nums[mid] == target) return mid;

            // * Case 1: Left half is sorted
            if (nums[s] <= nums[mid]) {
                // ? Check if target lies inside sorted left half
                if (nums[s] <= target && target < nums[mid]) {
                    e = mid - 1;  // * Search left
                } else {
                    s = mid + 1;  // * Otherwise search right
                }
            }
            // * Case 2: Right half is sorted
            else {
                // ? Check if target lies inside sorted right half
                if (nums[mid] < target && target <= nums[e]) {
                    s = mid + 1;  // * Search right
                } else {
                    e = mid - 1;  // * Otherwise search left
                }
            }
        }

        // ! Target not found → return -1
        return -1;
    }
};

int main() {
    Solution obj;

    // * Example 1
    vector<int> nums1 = {4,5,6,7,0,1,2};
    int target1 = 0;
    cout << "Input: target = " << target1 
         << " → Index = " << obj.search(nums1, target1) << endl;

    // * Example 2
    vector<int> nums2 = {4,5,6,7,0,1,2};
    int target2 = 3;
    cout << "Input: target = " << target2 
         << " → Index = " << obj.search(nums2, target2) << endl;

    return 0;
}
