// LeetCode Problem 1: Two Sum
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
// Example: Input: nums = [2,7,11,15], target = 9; Output: [0,1] (because nums[0] + nums[1] = 9)

class Solution {
    public:
        // Function that takes a vector of integers and a target sum, returns indices of two numbers that add up to target
        vector<int> twoSum(vector<int>& nums, int target) {
            // Store the size of the input array for efficiency (avoid repeated size() calls)
            int l = nums.size();
            
            // Create an empty vector to store the result indices
            vector<int> myarr;
            
            // Outer loop - pick the first number from index 0 to second last
            for (int i = 0; i < l; i++) {
                // Inner loop - pick the second number (starts from i+1 to avoid using same element twice)
                for (int j = i + 1; j < l; j++) {
                    // Check if the sum of current two numbers equals the target
                    if (nums[i] + nums[j] == target) {
                        myarr.push_back(i); // Add first index to result vector
                        myarr.push_back(j); // Add second index to result vector
                        return myarr;       // Return the result immediately when solution is found
                    }
                }
            }
            
            // If no solution is found (though problem guarantees one solution exists), return empty vector
            return {};
        }
    };