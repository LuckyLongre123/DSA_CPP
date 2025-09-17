#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
================================================================================
LeetCode 2460: Apply Operations to an Array
================================================================================
🔹 Problem Description:
You are given a 0-indexed array nums of size n consisting of non-negative integers.
Apply the following operation repeatedly:

1. Choose an index i where 0 <= i < n-1 and nums[i] == nums[i+1].
2. Replace nums[i] with 2 * nums[i] and nums[i+1] with 0.
3. Continue until no more operations can be applied.
4. Move all 0's to the end while maintaining the relative order of non-zero elements.

--------------------------------------------------------------------------------
Example 1:
Input:  nums = [1,2,2,1,1,0]
Step 1: Merge 2,2 → [1,4,0,1,1,0]
Step 2: Merge 1,1 → [1,4,0,2,0,0]
Step 3: Move zeros → [1,4,2,0,0,0]
Output: [1,4,2,0,0,0]

Example 2:
Input: nums = [0,1,1,2]
Output: [2,2,0,0]

Constraints:
* 2 <= nums.length <= 2000
* 0 <= nums[i] <= 1000
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 Idea: Two-phase approach

Phase 1: Merge adjacent equal elements
- Iterate through the array from left to right
- If nums[i] == nums[i+1], double nums[i] and set nums[i+1] to 0

Phase 2: Move all zeros to the end
- Use two-pointer technique
- zeroIndex tracks where the next non-zero element should go
- Swap non-zero elements to the front, zeros naturally shift to the back

⏱ Time Complexity: O(n)  → two passes through array
📦 Space Complexity: O(1)  → in-place modifications
================================================================================
*/

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // ================= Phase 1: Merge Adjacent Equal Elements =================
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;      // * Double the first element
                nums[i + 1] = 0;   // * Set second element to zero
            }
        }

        // ================= Phase 2: Move Zeros to End =================
        int zeroIndex = 0;  // * Position for next non-zero element

        for (int j = 0; j < n; j++) {
            if (nums[j] != 0) {
                swap(nums[zeroIndex++], nums[j]);  // * Swap non-zero to front
            }
        }

        return nums;  // * Return the modified array
    }
};

// ==================== Driver Code for Testing ====================
int main() {
    Solution obj;

    vector<int> nums1 = {1,2,2,1,1,0};
    vector<int> result1 = obj.applyOperations(nums1);
    cout << "[";
    for(int i = 0; i < result1.size(); i++) cout << result1[i] << (i < result1.size()-1 ? "," : "");
    cout << "]" << endl;

    vector<int> nums2 = {0,1,1,2};
    vector<int> result2 = obj.applyOperations(nums2);
    cout << "[";
    for(int i = 0; i < result2.size(); i++) cout << result2[i] << (i < result2.size()-1 ? "," : "");
    cout << "]" << endl;

    return 0;
}
