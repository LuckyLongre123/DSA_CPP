/*
 * LeetCode 27: Remove Element
 * 
 * Problem Description:
 * Given an integer array nums and an integer val, remove all occurrences of val 
 * in nums in-place. The order of the elements may be changed. Return the number 
 * of elements in nums which are not equal to val.
 * 
 * Examples:
 * Input: nums = [3,2,2,3], val = 3 → Output: 2, nums = [2,2,_,_]
 * Input: nums = [0,1,2,2,3,0,4,2], val = 2 → Output: 5, nums = [0,1,4,0,3,_,_,_]
 * 
 * Approach: Two-Pointer Technique
 * - Use one pointer (valIndex) to track position for next valid element
 * - Use another pointer (j) to scan through array
 * - When we find element != val, place it at valIndex position
 * - Return final position of valIndex (count of valid elements)
 * 
 * Time Complexity: O(n) - single pass through array
 * Space Complexity: O(1) - in-place modification
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int n = nums.size();
    
            // Two-pointer approach: valIndex tracks position for next valid element
            int valIndex = 0;  // Points to position where next non-val element should go
            
            for (int j = 0; j < n; j++) {
                // If current element is not the target value
                if (nums[j] != val) {
                    swap(nums[valIndex++], nums[j]);  // Move to front and increment position
                }
            }
            
            // Return count of elements that are not equal to val
            return valIndex;
        }
    };