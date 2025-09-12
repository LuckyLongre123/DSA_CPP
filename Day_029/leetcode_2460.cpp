/*
 * LeetCode 2460: Apply Operations to an Array
 * 
 * Problem Description:
 * You are given a 0-indexed array nums of size n consisting of non-negative integers.
 * Apply the following operation exactly once:
 * - Choose an index i where 0 <= i < n-1 and nums[i] == nums[i+1]
 * - Replace nums[i] with 2 * nums[i] and nums[i+1] with 0
 * - Continue until no more operations can be applied
 * - Move all 0's to the end while maintaining relative order of non-zero elements
 * 
 * Examples:
 * Input: nums = [1,2,2,1,1,0] → Output: [1,4,2,0,0,0]
 * Step 1: [1,2,2,1,1,0] → [1,4,0,1,1,0] (merge 2,2)
 * Step 2: [1,4,0,1,1,0] → [1,4,0,2,0,0] (merge 1,1)  
 * Step 3: Move zeros: [1,4,2,0,0,0]
 * 
 * Approach: Two-Phase Algorithm
 * Phase 1: Apply merge operations (double + zero)
 * Phase 2: Move all zeros to end using two-pointer technique
 * 
 * Time Complexity: O(n) - two passes through array
 * Space Complexity: O(1) - in-place modifications
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size();
    
            // Phase 1: Apply merge operations
            // Scan from left to right, merge adjacent equal elements
            for (int i = 0; i < n - 1; i++) {
                if (nums[i] == nums[i + 1]) {
                    nums[i] *= 2;        // Double the first element
                    nums[i + 1] = 0;     // Set second element to zero
                }
            }
    
            // Phase 2: Move all zeros to the end
            // Use two-pointer technique to maintain relative order
            int zeroIndex = 0;  // Points to position where next non-zero should go
            
            for (int j = 0; j < n; j++) {
                if (nums[j] != 0) {
                    swap(nums[zeroIndex++], nums[j]);  // Move non-zero to front
                }
            }
            
            return nums;
        }
    };