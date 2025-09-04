// LeetCode Problem 169: Majority Element
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times.
// You may assume that the majority element always exists in the array.
// Example: nums = [3,2,3] → Output: 3 (appears 2 times out of 3, which is > 3/2)

#include <vector>
using namespace std;

class Solution {
    public:
        // Function that finds the majority element using Boyer-Moore Voting Algorithm
        int majorityElement(vector<int>& nums) {
            int freq = 0;  // Counter for current candidate's frequency
            int ans = 0;   // Current candidate for majority element
            
            // Boyer-Moore Voting Algorithm: Find potential majority candidate
            for(int i = 0; i < nums.size(); i++){
                // If counter is 0, select current element as new candidate
                if(freq == 0) ans = nums[i];
                
                // If current element matches candidate, increment counter
                if(ans == nums[i]) freq++;
                // If current element is different, decrement counter
                else freq--;
            }
            
            // Since problem guarantees majority element exists, return the candidate
            return ans;
        }
    };