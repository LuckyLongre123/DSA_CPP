#include <iostream>
#include <vector>
using namespace std;

/* 
================================================================================
LeetCode Problem 26: Remove Duplicates from Sorted Array
================================================================================
Given an integer array nums sorted in non-decreasing order, remove the duplicates 
in-place such that each unique element appears only once.  

The relative order of the elements should be kept the same.  
Then return the number of unique elements.  

You must do it using O(1) extra memory.

--------------------------------------------------------------------------------
Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]

--------------------------------------------------------------------------------
Constraints:
* 1 <= nums.length <= 3 * 10^4
* -100 <= nums[i] <= 100
* nums is sorted in non-decreasing order
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
- Since array is sorted, duplicates will always be **next to each other**.
- We use **two pointers**:
  * `i` (slow) → position to place next unique element.
  * `j` (fast) → scans the array.

Steps:
1. Start with i = 0.
2. Move j from 1 → n-1.
3. If nums[j] != nums[i], that means new unique element found:
   - Move i forward (i++).
   - Copy nums[j] to nums[i].
4. End of loop → unique elements count = i + 1.
================================================================================
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Edge case: if array size = 0 → return 0
        if (nums.size() == 0) return 0;

        int i = 0;  // * Slow pointer: tracks unique position

        // * Fast pointer j scans the array
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                // ? Found a new unique element
                i++;              // * Move slow pointer
                nums[i] = nums[j]; // * Place new unique element
            }
            // ! If nums[i] == nums[j], it's duplicate → skip
        }

        // * Number of unique elements = i + 1
        return i + 1;
    }
};

int main() {
    Solution obj;

    // * Example test case 1
    vector<int> nums1 = {1,1,2};
    int len1 = obj.removeDuplicates(nums1);
    cout << "Unique count = " << len1 << " → ";
    for (int k = 0; k < len1; k++) cout << nums1[k] << " ";
    cout << endl;

    // * Example test case 2
    vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};
    int len2 = obj.removeDuplicates(nums2);
    cout << "Unique count = " << len2 << " → ";
    for (int k = 0; k < len2; k++) cout << nums2[k] << " ";
    cout << endl;

    return 0;
}
