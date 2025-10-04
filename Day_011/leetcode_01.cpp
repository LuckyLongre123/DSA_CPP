/**
 * ================================================================================
 * LeetCode 1: Two Sum - Array Search and Pair Finding
 * ================================================================================
 * 
 * ! Problem: Given an array of integers `nums` and an integer `target`, return 
 * ! indices of the two numbers such that they add up to target. You may assume 
 * ! that each input would have exactly one solution, and you may not use the 
 * ! same element twice. You can return the answer in any order.
 * 
 * * Approach (Brute Force):
 * * 1. Use nested loops to check all possible pairs
 * * 2. For each element at index i, check all elements after it (j > i)
 * * 3. If nums[i] + nums[j] equals target, return [i, j]
 * * 4. Continue until pair is found (guaranteed by problem constraints)
 * 
 * ? Time Complexity: O(n²) - We check all possible pairs using nested loops
 * ? Space Complexity: O(1) - Only using constant extra space (not counting output)
 * 
 * TODO Key Insight: 
 * *    - This is the straightforward brute force solution
 * *    - Can be optimized to O(n) using hash map (see advanced notes)
 * *    - The problem guarantees exactly one solution exists
 * 
 * * Optimizations Possible: 
 * *    - Hash map approach: O(n) time with O(n) space
 * *    - Two pointer approach: O(n log n) with sorting
 * ================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds two indices whose elements sum to target
     * @param nums Vector of integers to search
     * @param target The target sum to find
     * @return Vector containing two indices [i, j] where nums[i] + nums[j] = target
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = nums.size();  // * Get the length of input array
        vector<int> myarr;    // * Stores the result indices
        
        // * Outer loop: Consider each element as first number
        for (int i = 0; i < l; i++) {
            // * Inner loop: Check all elements after current for complement
            for (int j = i + 1; j < l; j++) {
                // ! Check if current pair sums to target
                if (nums[i] + nums[j] == target) {
                    myarr.push_back(i);  // * Add first index
                    myarr.push_back(j);  // * Add second index
                    return myarr;         // * Return immediately when found
                }
            }
        }
        
        return {};  // ! Return empty if no solution (won't happen per problem guarantee)
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(vector<int>& nums, int target, vector<int> result, vector<int> expected) {
    cout << "\nInput: nums = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "], target = " << target << "\n";
    
    cout << "   Result:   [" << (result.size() >= 2 ? to_string(result[0]) + ", " + to_string(result[1]) : "") << "]\n";
    cout << "   Expected: [" << expected[0] << ", " << expected[1] << "]\n";
    
    bool pass = (result.size() == 2 && 
                 ((result[0] == expected[0] && result[1] == expected[1]) ||
                  (result[0] == expected[1] && result[1] == expected[0])));
    
    cout << "   Status:   " << (pass ? "PASS" : "FAIL") << "\n";
    
    if (pass && result.size() == 2) {
        cout << "   Verification: nums[" << result[0] << "] + nums[" << result[1] 
             << "] = " << nums[result[0]] << " + " << nums[result[1]] 
             << " = " << (nums[result[0]] + nums[result[1]]) << "\n";
    }
}

int main() {
    Solution solution;
    
    // * Test Case 1: Basic example from problem description
    {
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        vector<int> result = solution.twoSum(nums, target);
        vector<int> expected = {0, 1};
        printTestResult(nums, target, result, expected);
    }
    
    // * Test Case 2: Multiple valid pairs, any one is acceptable
    {
        vector<int> nums = {3, 2, 4};
        int target = 6;
        vector<int> result = solution.twoSum(nums, target);
        vector<int> expected = {1, 2};
        printTestResult(nums, target, result, expected);
    }
    
    // * Test Case 3: Same number twice (different indices)
    {
        vector<int> nums = {3, 3};
        int target = 6;
        vector<int> result = solution.twoSum(nums, target);
        vector<int> expected = {0, 1};
        printTestResult(nums, target, result, expected);
    }
    
    // * Test Case 4: Larger array
    {
        vector<int> nums = {1, 5, 3, 7, 9, 2};
        int target = 10;
        vector<int> result = solution.twoSum(nums, target);
        vector<int> expected = {1, 3};  // 5 + 5 would be same index, so 3 + 7
        printTestResult(nums, target, result, expected);
    }
    
    // * Test Case 5: Negative numbers
    {
        vector<int> nums = {-3, 4, 3, 90};
        int target = 0;
        vector<int> result = solution.twoSum(nums, target);
        vector<int> expected = {0, 2};
        printTestResult(nums, target, result, expected);
    }
    
    // * Test Case 6: Large numbers
    {
        vector<int> nums = {1000000, 2000000, 3000000};
        int target = 5000000;
        vector<int> result = solution.twoSum(nums, target);
        vector<int> expected = {1, 2};
        printTestResult(nums, target, result, expected);
    }
    
    // * Test Case 7: Two elements only
    {
        vector<int> nums = {5, 10};
        int target = 15;
        vector<int> result = solution.twoSum(nums, target);
        vector<int> expected = {0, 1};
        printTestResult(nums, target, result, expected);
    }
    
    // * Test Case 8: Zero in array
    {
        vector<int> nums = {0, 4, 3, 0};
        int target = 0;
        vector<int> result = solution.twoSum(nums, target);
        vector<int> expected = {0, 3};
        printTestResult(nums, target, result, expected);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - This brute force solution checks all n(n-1)/2 pairs
 * ! - For large arrays (n > 10,000), consider hash map optimization: O(n) time
 * * - The problem guarantees exactly one solution, so no need for multiple answers
 * ? - Hash map approach trades space for speed: O(n) extra space for O(n) time
 * * - Alternative: Sort array and use two pointers, but loses original indices
 * ================================================================================
 */