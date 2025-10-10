/**
 * ================================================================================
 * LeetCode 1752: Check if Array Is Sorted and Rotated
 * ================================================================================
 * 
 * ! Problem: Given an array `nums`, return `true` if the array was originally sorted 
 * ! in non-decreasing order, then rotated some number of positions (including zero). 
 * ! Otherwise, return `false`.
 * 
 * * Approach:
 * * 1. Count the number of "break points" where nums[i] > nums[i+1]
 * * 2. A sorted rotated array can have at most ONE break point
 * * 3. If 0 break points: array is already sorted (return true)
 * * 4. If 1 break point: check if it forms valid rotation (nums[0] >= nums[n-1])
 * * 5. If more than 1 break point: not a sorted rotated array (return false)
 * 
 * ? Time Complexity: O(n) - Single pass through the array
 * ? Space Complexity: O(1) - Constant extra space used
 * 
 * TODO Key Insight: 
 * *    - A sorted array has 0 break points
 * *    - A rotated sorted array has exactly 1 break point at the rotation pivot
 * *    - The rotation must connect back: first element >= last element
 * *    - More than 1 break point means the array cannot be a rotated sorted array
 * 
 * * Optimizations: 
 * *    - Single pass solution - O(n) time
 * *    - No extra space required - O(1) space
 * *    - Early termination possible (can stop if break points > 1)
 * ================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Checks if array is sorted in non-decreasing order and rotated
     * @param nums The input array to check
     * @return true if array is sorted and rotated, false otherwise
     */
    bool check(vector<int>& nums) {
        int bPoint = 0;  // * Counter for break points (inversions)
        int s = nums.size();  // * Size of the array
        
        // * Scan through array to find break points
        // ? A break point is where nums[i] > nums[i+1] (descending order)
        for (int i = 0; i < s - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                bPoint++;  // * Found a break point
            }
        }
        
        // ! Case 1: No break points found
        // * Array is already sorted in non-decreasing order
        if (bPoint == 0) {
            return true;  // * Original sorted array (0 rotations)
        }
        
        // ! Case 2: Exactly one break point found
        // ? Must verify the rotation is valid
        // * For valid rotation: nums[0] >= nums[n-1] (connects back)
        if (bPoint == 1) {
            return nums[0] >= nums[s - 1];  // * Check rotation validity
        }
        
        // ! Case 3: More than one break point
        // * Cannot be a rotated sorted array
        return false;
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print array
 */
void printArray(vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]";
}

/**
 * Helper function to print test result
 */
void printTestResult(vector<int>& nums, bool result, bool expected) {
    cout << "\nArray: ";
    printArray(nums);
    cout << "\n   Result:   " << (result ? "true" : "false") << "\n";
    cout << "   Expected: " << (expected ? "true" : "false") << "\n";
    cout << "   Status:   " << (result == expected ? "PASS" : "FAIL");
    if (result != expected) {
        cout << " (Expected: " << (expected ? "true" : "false") << ")";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Valid rotation - single rotation point
    {
        vector<int> nums = {3, 4, 5, 1, 2};
        bool result = solution.check(nums);
        printTestResult(nums, result, true);
    }
    
    // * Test Case 2: Invalid - two break points
    {
        vector<int> nums = {2, 1, 3, 4};
        bool result = solution.check(nums);
        printTestResult(nums, result, false);
    }
    
    // * Test Case 3: Already sorted - no rotation
    {
        vector<int> nums = {1, 2, 3, 4, 5};
        bool result = solution.check(nums);
        printTestResult(nums, result, true);
    }
    
    // * Test Case 4: Single element
    {
        vector<int> nums = {1};
        bool result = solution.check(nums);
        printTestResult(nums, result, true);
    }
    
    // * Test Case 5: Two elements - sorted
    {
        vector<int> nums = {1, 2};
        bool result = solution.check(nums);
        printTestResult(nums, result, true);
    }
    
    // * Test Case 6: Two elements - rotated
    {
        vector<int> nums = {2, 1};
        bool result = solution.check(nums);
        printTestResult(nums, result, true);
    }
    
    // ! Test Case 7: All identical elements
    {
        vector<int> nums = {1, 1, 1, 1};
        bool result = solution.check(nums);
        printTestResult(nums, result, true);
    }
    
    // ! Test Case 8: Descending order
    {
        vector<int> nums = {5, 4, 3, 2, 1};
        bool result = solution.check(nums);
        printTestResult(nums, result, false);
    }
    
    // * Test Case 9: Rotation at beginning
    {
        vector<int> nums = {6, 10, 6};
        bool result = solution.check(nums);
        printTestResult(nums, result, true);
    }
    
    // * Test Case 10: Large rotation
    {
        vector<int> nums = {7, 9, 1, 2, 3};
        bool result = solution.check(nums);
        printTestResult(nums, result, true);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The solution handles all edge cases including single element and duplicates
 * ! - The break point counting approach is optimal for this problem
 * * - The algorithm validates rotation by checking if array "wraps around" correctly
 * ? - For arrays with duplicates, the same logic applies
 * ? - Alternative: Can also solve by checking if array is sorted after trying all rotations
 * ================================================================================
 */