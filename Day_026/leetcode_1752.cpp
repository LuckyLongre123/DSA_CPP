/*
LeetCode 1752: Check if Array Is Sorted and Rotated

Problem Description:
Given an array nums, return true if the array was originally sorted in non-decreasing 
order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length 
such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

Examples:
Input: nums = [3,4,5,1,2]
Output: true (originally [1,2,3,4,5], rotated 3 positions)

Input: nums = [2,1,3,4]
Output: false (cannot be formed by rotating a sorted array)

Input: nums = [1,2,3]
Output: true (originally sorted, rotated 0 positions)

Approach: Break Point Counting
1. Count "break points" where nums[i] > nums[i+1]
2. A valid rotated sorted array can have at most 1 break point
3. If 1 break point exists, first element must be >= last element
4. If 0 break points, array is already sorted

Time Complexity: O(n) - single pass through array
Space Complexity: O(1) - only using constant extra space
*/

#include <vector>
using namespace std;

class Solution {
    public:
        bool check(vector<int>& nums) {
            int bPoint = 0;  // Counter for break points (where order breaks)
            int s = nums.size();  // Store array size for efficiency
    
            // Count break points: positions where nums[i] > nums[i+1]
            // A break point indicates where the rotation occurred
            for (int i = 0; i < s - 1; i++) {
                if (nums[i] > nums[i + 1])
                    bPoint++;  // Found a break in ascending order
            }
            
            // Case 1: No break points found
            // Array is already sorted in non-decreasing order
            if (bPoint == 0)
                return true;
            
            // Case 2: Exactly one break point found
            // This could be a valid rotated sorted array
            // Additional check: first element must be >= last element
            // This ensures the "wrap-around" maintains sorted property
            if (bPoint == 1) {
                return nums[0] >= nums[s - 1];
            }
            
            // Case 3: More than one break point
            // Cannot be a rotated sorted array (too many breaks in order)
            return false;
        }
    };