/**
 * ================================================================================
 * LeetCode 896: Monotonic Array - Array Trend Analysis
 * ================================================================================
 * 
 * ! Problem: An array is monotonic if it is either monotone increasing or monotone decreasing.
 * ! An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j].
 * ! An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
 * ! Given an integer array nums, return true if the given array is monotonic, or false otherwise.
 * 
 * * Approach:
 * * 1. Initialize two boolean flags: increasing and decreasing (both start as true)
 * * 2. Iterate through the array from index 1 to n-1:
 * *    - If current element > previous element, set decreasing = false
 * *    - If current element < previous element, set increasing = false
 * * 3. Return true if either increasing OR decreasing remains true
 * 
 * ? Time Complexity: O(n) - Single pass through the array
 * ? Space Complexity: O(1) - Only using constant extra space
 * 
 * TODO Key Insight: 
 * *    - We track both possibilities simultaneously and eliminate impossible ones
 * *    - An array can be both increasing and decreasing (all elements equal)
 * *    - Early termination possible when both flags become false
 * 
 * * Optimizations: 
 * *    - Single pass algorithm
 * *    - No additional data structures needed
 * *    - Handles edge cases naturally (single element, empty array)
 * ================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Determines if an array is monotonic (either increasing or decreasing)
     * @param nums The input array to check for monotonic property
     * @return true if array is monotonic, false otherwise
     */
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();  // * Get array size
        
        // ! Handle edge cases
        if (n <= 2) {
            return true;  // * Arrays with 0, 1, or 2 elements are always monotonic
        }
        
        bool increasing = true;  // * Flag to track if array can be non-decreasing
        bool decreasing = true;  // * Flag to track if array can be non-increasing
        
        // * Iterate through array comparing adjacent elements
        for (int i = 1; i < n; i++) {
            // ? Check if current element breaks increasing trend
            if (nums[i] > nums[i-1]) {
                decreasing = false;  // ! Cannot be decreasing if we found an increase
            }
            
            // ? Check if current element breaks decreasing trend  
            if (nums[i] < nums[i-1]) {
                increasing = false;  // ! Cannot be increasing if we found a decrease
            }
            
            // * Early termination optimization (optional)
            // * If both trends are broken, we can return false immediately
            if (!increasing && !decreasing) {
                return false;
            }
        }
        
        // * Array is monotonic if at least one trend is maintained
        return increasing || decreasing;
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(vector<int>& nums, bool result, bool expected) {
    cout << "\nnums = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]\n";
    cout << "   Result:   " << (result ? "true" : "false") << "\n";
    cout << "   Expected: " << (expected ? "true" : "false") << "\n";
    cout << "   Status:   " << (result == expected ? "PASS" : "FAIL");
    if (result != expected) {
        cout << " (Expected: " << (expected ? "true" : "false") << ")";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Monotonic increasing
    {
        vector<int> nums = {1, 2, 2, 3};
        bool result = solution.isMonotonic(nums);
        printTestResult(nums, result, true);
    }
    
    // * Test Case 2: Monotonic decreasing
    {
        vector<int> nums = {6, 5, 4, 4};
        bool result = solution.isMonotonic(nums);
        printTestResult(nums, result, true);
    }
    
    // ! Test Case 3: Not monotonic
    {
        vector<int> nums = {1, 3, 2};
        bool result = solution.isMonotonic(nums);
        printTestResult(nums, result, false);
    }
    
    // * Test Case 4: Single element
    {
        vector<int> nums = {5};
        bool result = solution.isMonotonic(nums);
        printTestResult(nums, result, true);
    }
    
    // * Test Case 5: Two elements (increasing)
    {
        vector<int> nums = {1, 2};
        bool result = solution.isMonotonic(nums);
        printTestResult(nums, result, true);
    }
    
    // * Test Case 6: Two elements (decreasing)
    {
        vector<int> nums = {2, 1};
        bool result = solution.isMonotonic(nums);
        printTestResult(nums, result, true);
    }
    
    // * Test Case 7: All elements equal
    {
        vector<int> nums = {1, 1, 1, 1};
        bool result = solution.isMonotonic(nums);
        printTestResult(nums, result, true);
    }
    
    // * Test Case 8: Empty array
    {
        vector<int> nums = {};
        bool result = solution.isMonotonic(nums);
        printTestResult(nums, result, true);
    }
    
    // * Test Case 9: Large monotonic increasing
    {
        vector<int> nums = {1, 1, 2, 3, 5, 8, 13, 21};
        bool result = solution.isMonotonic(nums);
        printTestResult(nums, result, true);
    }
    
    // ! Test Case 10: Complex non-monotonic
    {
        vector<int> nums = {1, 2, 4, 5, 3, 7};
        bool result = solution.isMonotonic(nums);
        printTestResult(nums, result, false);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The solution handles all edge cases including empty arrays and single elements
 * ! - The algorithm uses a two-flag approach to track both possible monotonic trends
 * * - Early termination can be added for performance optimization in worst cases
 * ? - The solution works for arrays of any size and handles duplicate elements correctly
 * * - Time complexity is optimal O(n) as we need to examine each element at least once
 * ================================================================================
 */