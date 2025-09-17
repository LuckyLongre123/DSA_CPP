#include <iostream>
#include <vector>
using namespace std;

/*
================================================================================
LeetCode 724: Find Pivot Index
================================================================================
🔹 Problem Description:
Given an array of integers `nums`, the pivot index is the index where:
sum of all numbers strictly to the left == sum of all numbers strictly to the right.

- If index is at left edge, left sum = 0.
- If index is at right edge, right sum = 0.

Return **leftmost** pivot index. If no pivot exists, return -1.

--------------------------------------------------------------------------------
Example 1:
Input:  nums = [1,7,3,6,5,6]
Output: 3
Explanation: Left sum = 1+7+3 = 11, Right sum = 5+6 = 11

Example 2:
Input:  nums = [1,2,3]
Output: -1
Explanation: No pivot index exists.

--------------------------------------------------------------------------------
Constraints:
* 1 <= nums.length <= 10^4
* -1000 <= nums[i] <= 1000
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 We want left sum == right sum for some index.  

⚡ Approach:
1. Calculate initial **right sum** (sum of all elements except first).
2. Initialize **left sum** = 0.
3. Traverse the array:
   - Check if left sum == right sum → pivot found.
   - Update left sum: add current element.
   - Update right sum: subtract next element (moving window).
4. Return first pivot index, or -1 if none found.

⏱ Time Complexity: O(n) (single pass)  
📦 Space Complexity: O(1)
================================================================================
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int presum = 0;       // * Sum of elements to the left
        int aftersum = 0;     // * Sum of elements to the right

        // * Calculate initial right sum (all elements except first)
        for (int i = 1; i < nums.size(); i++) aftersum += nums[i];

        // * Check each position for pivot
        for (int j = 0; j < nums.size(); j++) {
            if (presum == aftersum) return j;  // ? Found pivot

            presum += nums[j];  // + Add current element to left sum

            // * Update right sum for next iteration
            if (j + 1 > nums.size() - 1) { 
                aftersum = 0; 
                continue;
            }
            aftersum -= nums[j + 1]; // - Remove next element from right sum
        }

        return -1; // ! No pivot found
    }
};

// ==================== Driver Code for Testing ====================
int main() {
    Solution obj;

    // * Example 1
    vector<int> nums1 = {1,7,3,6,5,6};
    cout << "Input: [1,7,3,6,5,6] → Pivot Index: " 
         << obj.pivotIndex(nums1) << endl;

    // * Example 2
    vector<int> nums2 = {1,2,3};
    cout << "Input: [1,2,3] → Pivot Index: " 
         << obj.pivotIndex(nums2) << endl;

    // * Example 3
    vector<int> nums3 = {2,1,-1};
    cout << "Input: [2,1,-1] → Pivot Index: " 
         << obj.pivotIndex(nums3) << endl;

    return 0;
}
