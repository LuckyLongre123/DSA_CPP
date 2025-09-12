/*
 * LeetCode 283: Move Zeroes
 * 
 * Problem Description:
 * Given an integer array nums, move all 0's to the end of it while maintaining 
 * the relative order of the non-zero elements. You must do this in-place 
 * without making a copy of the array.
 * 
 * Examples:
 * Input: nums = [0,1,0,3,12] → Output: [1,3,12,0,0]
 * Input: nums = [0] → Output: [0]
 * 
 * Approach: Two-Pointer Technique
 * - Use zeroIndex to track position where next non-zero element should go
 * - Scan through array with j pointer
 * - When we find non-zero element, swap it to zeroIndex position
 * - This naturally pushes all zeros to the end while preserving order
 * 
 * Time Complexity: O(n) - single pass through array
 * Space Complexity: O(1) - in-place swapping
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int n = nums.size();
    
            // Two-pointer approach: zeroIndex tracks position for next non-zero element
            int zeroIndex = 0;  // Points to position where next non-zero should go
            
            for (int j = 0; j < n; j++) {
                // If current element is non-zero
                if (nums[j] != 0) {
                    swap(nums[zeroIndex++], nums[j]);  // Move to front, zeros naturally move back
                }
            }
        }
    };