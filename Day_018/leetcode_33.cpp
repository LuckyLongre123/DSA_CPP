// LeetCode Problem 33: Search in Rotated Sorted Array
// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k.
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// Example 1: Input: nums = [4,5,6,7,0,1,2], target = 0, Output: 4
// Example 2: Input: nums = [4,5,6,7,0,1,2], target = 3, Output: -1

#include <vector>
using namespace std;

class Solution {
    public:
        // Function to search target in rotated sorted array using modified binary search
        int search(vector<int>& nums, int target) {
            int s = 0;                    // Start pointer
            int e = nums.size() - 1;      // End pointer
    
            while(s <= e){
                int mid = s + (e - s) / 2;  // Calculate middle to avoid overflow
    
                // If target found at middle, return index
                if(nums[mid] == target)
                    return mid;
    
                // Check which half is properly sorted
                // Left half is sorted (nums[s] to nums[mid])
                if(nums[s] <= nums[mid]){
                    // Check if target lies in the sorted left half
                    if(nums[s] <= target && target < nums[mid]){
                        e = mid - 1;  // Search in left half
                    } else {
                        s = mid + 1;  // Search in right half
                    }
                }
                // Right half is sorted (nums[mid] to nums[e])
                else{
                    // Check if target lies in the sorted right half
                    if(nums[mid] < target && target <= nums[e]){
                        s = mid + 1;  // Search in right half
                    } else {
                        e = mid - 1;  // Search in left half
                    }
                }
            }
    
            return -1;  // Target not found
        }
    };