#include <iostream>
#include <vector>
using namespace std;

/* 
================================================================================
LeetCode Problem 1: Two Sum
================================================================================
Given an array of integers nums and an integer target, return indices of the 
two numbers such that they add up to target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

You can return the answer in any order.

--------------------------------------------------------------------------------
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

--------------------------------------------------------------------------------
Constraints:
* 2 <= nums.length <= 10^4
* -10^9 <= nums[i] <= 10^9
* -10^9 <= target <= 10^9
* Only one valid answer exists.

================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
- We have an array of numbers.
- We need to find two numbers whose sum = target.
- Return their indices (array positions).
- We cannot use the same number twice.
- Only one solution exists for every test case.
================================================================================
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();   

        // * Outer loop: pick the first number
        for (int i = 0; i < n; i++) {
            // * Inner loop: pick the second number (after i)
            for (int j = i + 1; j < n; j++) {
                
                // ? Check if nums[i] + nums[j] is equal to target
                if (nums[i] + nums[j] == target) {
                    // ! Found the solution → return indices immediately
                    return {i, j};
                }
            }
        }

        // TODO: If no solution found (though problem guarantees one), return empty
        return {};
    }
};

int main() {
    Solution obj;

    // * Example test case
    vector<int> nums = {2, 7, 11, 15};  
    int target = 9;

    // * Call the function
    vector<int> ans = obj.twoSum(nums, target);

    // * Print the result
    cout << "Indices: ";
    for (int index : ans) {
        cout << index << " ";  
    }
    cout << endl;

    return 0;
}
