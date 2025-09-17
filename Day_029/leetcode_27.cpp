#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
================================================================================
LeetCode 27: Remove Element
================================================================================
🔹 Problem Description:
Given an integer array `nums` and an integer `val`, remove all occurrences of `val` 
in-place. The order of the elements may be changed. Return the number of elements 
in `nums` which are not equal to `val`.

--------------------------------------------------------------------------------
Example 1:
Input:  nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]

Example 2:
Input:  nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]

Constraints:
* 0 <= nums.length <= 100
* 0 <= nums[i] <= 50
* 0 <= val <= 100
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 Idea: Two-pointer technique

Steps:
1. Use valIndex pointer to track the position to place next valid element.
2. Use j pointer to scan through the array.
3. If nums[j] != val, move it to nums[valIndex] using swap and increment valIndex.
4. Return valIndex as the count of valid elements.

⏱ Time Complexity: O(n)  
📦 Space Complexity: O(1) (in-place)
================================================================================
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        int valIndex = 0; // * Next position to place valid element

        for (int j = 0; j < n; j++) {
            // ? Current element is valid, move to front
            if (nums[j] != val) {
                swap(nums[valIndex++], nums[j]); // * Swap and move valIndex forward
            }
        }

        return valIndex; // * Count of elements != val
    }
};

// ==================== Driver Code for Testing ====================
int main() {
    Solution obj;

    // * Example 1
    vector<int> nums1 = {3,2,2,3};
    int k1 = obj.removeElement(nums1, 3);
    cout << "Input: [3,2,2,3], val = 3 → Output: " << k1 << ", nums = [";
    for(int i = 0; i < k1; i++) cout << nums1[i] << (i<k1-1?",":"");
    cout << "]" << endl;

    // * Example 2
    vector<int> nums2 = {0,1,2,2,3,0,4,2};
    int k2 = obj.removeElement(nums2, 2);
    cout << "Input: [0,1,2,2,3,0,4,2], val = 2 → Output: " << k2 << ", nums = [";
    for(int i = 0; i < k2; i++) cout << nums2[i] << (i<k2-1?",":"");
    cout << "]" << endl;

    // * Example 3 (no val present)
    vector<int> nums3 = {1,2,3};
    int k3 = obj.removeElement(nums3, 4);
    cout << "Input: [1,2,3], val = 4 → Output: " << k3 << ", nums = [";
    for(int i = 0; i < k3; i++) cout << nums3[i] << (i<k3-1?",":"");
    cout << "]" << endl;

    return 0;
}
