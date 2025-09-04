// LeetCode Problem 26: Remove Duplicates from Sorted Array
// Given an integer array nums sorted in non-decreasing order, remove duplicates in-place
// such that each unique element appears only once. Return the number of unique elements.
// Example 1: nums = [1,1,2] → Output: 2, nums = [1,2,_]
// Example 2: nums = [0,0,1,1,1,2,2,3,3,4] → Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]

#include <vector>
using namespace std;

class Solution {
    public:
        // Function that removes duplicates from sorted array using two pointers technique
        int removeDuplicates(vector<int>& nums) {
            int i = 0;  // Slow pointer: points to position for next unique element
            
            // Fast pointer j starts from index 1 and scans through the array
            for(int j = 1; j < nums.size(); j++){
                // If current element is different from the last unique element
                if(nums[i] != nums[j]){
                    i++;              // Move slow pointer to next position
                    nums[i] = nums[j]; // Place the new unique element at position i
                }
                // If nums[i] == nums[j], it's a duplicate, so just continue with j++
            }
            
            // Return count of unique elements (i+1 because i is 0-indexed)
            return i+1;
        }
    };