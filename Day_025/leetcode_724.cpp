/*
LeetCode 724: Find Pivot Index

Problem Description:
Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left 
of the index is equal to the sum of all the numbers strictly to the right of the index.

If the index is on the left edge of the array, then the left sum is 0 because there are 
no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

Examples:
Input: nums = [1,7,3,6,5,6]
Output: 3 (left sum = 1+7+3 = 11, right sum = 5+6 = 11)

Input: nums = [1,2,3]
Output: -1 (no pivot index exists)

Approach: Two-Sum Technique
1. Calculate initial right sum (all elements except first)
2. For each position, check if left sum equals right sum
3. Update sums as we move: add current to left, subtract next from right
4. Return first valid pivot index, or -1 if none found

Time Complexity: O(n) - single pass through array
Space Complexity: O(1) - only using constant extra space
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
        // Initialize sums: aftersum = sum of elements to the right, presum = sum to the left
        int aftersum = 0;  // Sum of elements after current index
        int presum = 0;    // Sum of elements before current index
        
        // Calculate initial right sum (sum of all elements except first)
        for( int i = 1 ; i < nums.size() ; i++) aftersum += nums[i];
        
        // Check each position as potential pivot
        for( int j = 0 ; j < nums.size() ; j++){
            // Check if current index is pivot (left sum == right sum)
            if(presum == aftersum) return j;
            
            // Update left sum by adding current element
            presum += nums[j];
            
            // Handle boundary: if we're at last element, right sum becomes 0
            if(j+1 > nums.size() -1){ 
                aftersum = 0; 
                continue;
            }
            
            // Update right sum by removing the next element (since it moves to left side)
            aftersum -= nums[j+1];
        }
    
        // No pivot index found
        return -1;
        }
    };