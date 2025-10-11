/**
 * ================================================================================
 * LeetCode 2460: Apply Operations to an Array - Two-Pointer Array Manipulation
 * ================================================================================
 * 
 * ! Problem: Given a 0-indexed array `nums` of non-negative integers,
 * ! repeatedly apply operations where adjacent equal elements are merged
 * ! (first element doubles, second becomes 0), then move all zeros to the end
 * ! while maintaining relative order of non-zero elements.
 * 
 * * Approach:
 * * 1. Phase 1: Merge adjacent equal elements in a single pass
 * *    - Iterate from left to right (i = 0 to n-2)
 * *    - If nums[i] == nums[i+1], double nums[i] and set nums[i+1] to 0
 * * 2. Phase 2: Move all zeros to end using two-pointer technique
 * *    - zeroIndex tracks position for next non-zero element
 * *    - Swap non-zero elements to front, zeros naturally move to back
 * * 3. Return the modified array
 * 
 * ? Time Complexity: O(n) - Two sequential passes through the array
 * ? Space Complexity: O(1) - In-place modifications with constant extra space
 * 
 * TODO Key Insight: 
 * *    - The two-phase approach ensures correctness without conflicts
 * *    - First phase creates zeros from merges, second phase organizes them
 * *    - Two-pointer technique maintains relative order efficiently
 * 
 * * Optimizations: 
 * *    - Single pass for each phase (no nested loops)
 * *    - In-place swapping minimizes space usage
 * *    - Early detection of adjacent equal elements
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;
 
 class Solution {
 public:
     /**
      * Applies operations to merge adjacent equal elements and move zeros to end
      * @param nums The input array to modify (passed by reference)
      * @return The modified array with operations applied
      */
     vector<int> applyOperations(vector<int>& nums) {
         int n = nums.size();  // * Total number of elements
         
         // ============================================================
         // ! PHASE 1: Merge Adjacent Equal Elements
         // ============================================================
         for (int i = 0; i < n - 1; i++) {
             // ? Check if current element equals next element
             if (nums[i] == nums[i + 1]) {
                 nums[i] *= 2;      // * Double the first element
                 nums[i + 1] = 0;   // * Set second element to zero
                 // * Example: [2, 2] becomes [4, 0]
             }
         }
         
         // ============================================================
         // ! PHASE 2: Move All Zeros to End (Two-Pointer Technique)
         // ============================================================
         int zeroIndex = 0;  // * Position for next non-zero element
         
         for (int j = 0; j < n; j++) {
             // ? If current element is non-zero, move it forward
             if (nums[j] != 0) {
                 // * Swap non-zero element to zeroIndex position
                 swap(nums[zeroIndex], nums[j]);
                 zeroIndex++;  // * Move boundary forward
             }
             // * Zeros naturally accumulate at the end
         }
         
         return nums;  // * Return the modified array
     }
 };

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result with array visualization
 */
void printTestResult(vector<int>& input, vector<int>& result, vector<int>& expected, string testName) {
    cout << "\n" << testName << "\n";
    cout << "   Input:    [";
    for(int i = 0; i < input.size(); i++) cout << input[i] << (i < input.size()-1 ? "," : "");
    cout << "]\n";
    cout << "   Result:   [";
    for(int i = 0; i < result.size(); i++) cout << result[i] << (i < result.size()-1 ? "," : "");
    cout << "]\n";
    cout << "   Expected: [";
    for(int i = 0; i < expected.size(); i++) cout << expected[i] << (i < expected.size()-1 ? "," : "");
    cout << "]\n";
    cout << "   Status:   " << (result == expected ? "PASS" : "FAIL") << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Multiple adjacent equal elements
    {
        vector<int> input = {1,2,2,1,1,0};
        vector<int> nums = input;
        vector<int> result = solution.applyOperations(nums);
        vector<int> expected = {1,4,2,0,0,0};
        printTestResult(input, result, expected, "Test Case 1: Multiple Merges");
    }
    
    // * Test Case 2: Equal elements at beginning
    {
        vector<int> input = {0,1,1,2};
        vector<int> nums = input;
        vector<int> result = solution.applyOperations(nums);
        vector<int> expected = {2,2,0,0};
        printTestResult(input, result, expected, "Test Case 2: Beginning Merge");
    }
    
    // * Test Case 3: No equal adjacent elements
    {
        vector<int> input = {1,2,3,4};
        vector<int> nums = input;
        vector<int> result = solution.applyOperations(nums);
        vector<int> expected = {1,2,3,4};
        printTestResult(input, result, expected, "Test Case 3: No Merges");
    }
    
    // * Test Case 4: All zeros
    {
        vector<int> input = {0,0,0,0};
        vector<int> nums = input;
        vector<int> result = solution.applyOperations(nums);
        vector<int> expected = {0,0,0,0};
        printTestResult(input, result, expected, "Test Case 4: All Zeros");
    }
    
    // ! Test Case 5: Single merge creating large number
    {
        vector<int> input = {500,500,1,1};
        vector<int> nums = input;
        vector<int> result = solution.applyOperations(nums);
        vector<int> expected = {1000,2,0,0};
        printTestResult(input, result, expected, "Test Case 5: Large Number Merge");
    }
    
    // * Test Case 6: Minimal array size
    {
        vector<int> input = {5,5};
        vector<int> nums = input;
        vector<int> result = solution.applyOperations(nums);
        vector<int> expected = {10,0};
        printTestResult(input, result, expected, "Test Case 6: Minimal Size");
    }
    
    // * Test Case 7: Multiple consecutive equal elements
    {
        vector<int> input = {1,1,1,1};
        vector<int> nums = input;
        vector<int> result = solution.applyOperations(nums);
        vector<int> expected = {2,2,0,0};
        printTestResult(input, result, expected, "Test Case 7: Consecutive Equals");
    }
    
    // * Test Case 8: Mixed with initial zeros
    {
        vector<int> input = {0,3,3,0,5,5};
        vector<int> nums = input;
        vector<int> result = solution.applyOperations(nums);
        vector<int> expected = {6,10,0,0,0,0};
        printTestResult(input, result, expected, "Test Case 8: Initial Zeros");
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The two-phase approach prevents interference between merge and move operations
 * ! - Phase 1 always executes left-to-right, so each element is checked only once
 * * - Phase 2's two-pointer technique is optimal for moving zeros (O(n) single pass)
 * ? - The algorithm maintains relative order of non-zero elements (stable rearrangement)
 * * - Works efficiently even when all elements are equal or all are distinct
 * ================================================================================
 */
