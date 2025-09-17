#include <iostream>
#include <vector>
using namespace std;

/* 
================================================================================
LeetCode Problem 169: Majority Element
================================================================================
Given an array nums of size n, return the majority element.

The majority element is the element that appears **more than ⌊n / 2⌋ times**.  
You may assume that the majority element always exists in the array.

--------------------------------------------------------------------------------
Example 1:
Input: nums = [3,2,3]
Output: 3
Explanation: 3 appears 2 times, and 2 > n/2 (n=3 → n/2=1.5).

--------------------------------------------------------------------------------
Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
Explanation: 2 appears 4 times, and 4 > n/2 (n=7 → n/2=3.5).

--------------------------------------------------------------------------------
Constraints:
* n == nums.length
* 1 <= n <= 5 * 10^4
* -10^9 <= nums[i] <= 10^9
* The majority element always exists.
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
- Majority element means: frequency of element > n/2.
- Example: [2,2,1,1,1,2,2]
  → n=7, n/2=3.5 → majority element = 2 (appears 4 times).
- We use **Boyer-Moore Voting Algorithm**:
  1. Start with freq = 0.
  2. If freq = 0 → choose new candidate.
  3. If current == candidate → freq++.
  4. Else → freq--.
- At the end, the candidate will be the majority element.
================================================================================
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0;  // * counter for candidate
        int ans = 0;   // * current candidate

        // * Iterate through nums
        for (int i = 0; i < nums.size(); i++) {
            // ? If counter is zero → pick new candidate
            if (freq == 0) ans = nums[i];

            // * If current == candidate → increase counter
            if (nums[i] == ans) freq++;
            // * If different → decrease counter
            else freq--;
        }

        // ! Problem guarantees majority element exists → return candidate
        return ans;
    }
};

int main() {
    Solution obj;

    // * Example test cases
    vector<int> nums1 = {3, 2, 3};
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};

    cout << "Majority element in [3,2,3] → " 
         << obj.majorityElement(nums1) << endl;

    cout << "Majority element in [2,2,1,1,1,2,2] → " 
         << obj.majorityElement(nums2) << endl;

    return 0;
}
