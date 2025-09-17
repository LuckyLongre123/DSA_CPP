#include <iostream>
#include <vector>
using namespace std;

/* 
================================================================================
LeetCode Problem 3550: Find the Smallest Index Where Index Equals Sum of Digits
================================================================================
You are given an array of integers `nums`.  
Find the **smallest index i** such that:

    i == sum_of_digits(nums[i])

If no such index exists, return -1.

--------------------------------------------------------------------------------
Example 1:
Input: nums = [12, 34, 5, 67]
Output: 2
Explanation:
nums[2] = 5 → sum_of_digits(5) = 5 → index = 2 → ✅ condition satisfied.

--------------------------------------------------------------------------------
Example 2:
Input: nums = [10, 21, 32]
Output: 1
Explanation:
nums[1] = 21 → sum_of_digits(21) = 2 + 1 = 3 → not equal.  
nums[2] = 32 → sum_of_digits(32) = 3 + 2 = 5 → not equal.  
No match found → return -1.

--------------------------------------------------------------------------------
Constraints:
* 1 <= nums.length <= 100
* 0 <= nums[i] <= 10^5
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
- We need to find the smallest index `i` where:
    index == sum of digits of nums[i].
- Steps:
  1. Go through each index of array.
  2. Calculate digit sum of nums[i].
  3. If digit sum == index, return i immediately.
  4. If no such index found → return -1.
================================================================================
*/

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        // * Loop through each index
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];  
            int sum = 0;

            // ? Calculate sum of digits of nums[i]
            while (temp != 0) {
                sum += temp % 10;  // * take last digit
                temp /= 10;        // * remove last digit
            }

            // ! Check condition: index == sum_of_digits(nums[i])
            if (i == sum) return i;  // return index immediately
        }

        // TODO: If no index found, return -1
        return -1;
    }
};

int main() {
    Solution obj;

    // * Example test case
    vector<int> nums = {12, 34, 5, 67};

    int ans = obj.smallestIndex(nums);

    cout << "Smallest index where index == sum of digits: " << ans << endl;

    return 0;
}
