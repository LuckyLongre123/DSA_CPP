/**
 * ================================================================================
 * LeetCode 53: Maximum Subarray - Kadane's Algorithm
 * ================================================================================
 * 
 * ! Problem: Given an integer array `nums`, find the subarray with the largest sum,
 * ! and return its sum. A subarray is a contiguous non-empty sequence of elements
 * ! within an array.
 * 
 * * Approach: Kadane's Algorithm (Dynamic Programming)
 * * 1. Initialize current sum (currSum) as 0 and maximum sum (maxSum) as INT_MIN
 * * 2. Iterate through each element in the array:
 * *    - Add current element to currSum
 * *    - Update maxSum if currSum is greater
 * *    - If currSum becomes negative, reset it to 0 (start fresh subarray)
 * * 3. Return maxSum as the result
 * 
 * ? Time Complexity: O(n) - Single pass through the array
 * ? Space Complexity: O(1) - Only constant extra space used
 * 
 * TODO Key Insight: 
 * *    - Kadane's algorithm is a greedy/DP approach that maintains the maximum sum
 * *    - Key idea: If current sum becomes negative, it won't contribute positively
 * *      to any future subarray, so we reset and start fresh
 * *    - We keep track of the best sum seen so far (maxSum)
 * 
 * * Optimizations: 
 * *    - Single pass solution - optimal time complexity
 * *    - No extra space needed - optimal space complexity
 * *    - Handles all-negative arrays correctly by initializing maxSum to INT_MIN
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * Finds the maximum sum of a contiguous subarray using Kadane's Algorithm
     * @param nums The input array of integers
     * @return The maximum sum found
     */
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;      // * Tracks current subarray sum
        int maxSum = INT_MIN; // * Stores the maximum sum found so far
        
        // ! Iterate through each element in the array
        for(int val : nums) {
            // * Add current element to running sum
            currSum += val;
            
            // ? Update maximum if current sum is greater
            // This captures the best subarray ending at current position
            maxSum = max(currSum, maxSum);
            
            // ! KEY INSIGHT: If current sum is negative, reset to 0
            // ? Why? A negative sum will only decrease future sums
            // Starting fresh from next element will be better
            if(currSum < 0) {
                currSum = 0;
            }
        }
        
        return maxSum;
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(vector<int>& nums, int result, int expected) {
    cout << "\nnums = [";
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if(i < nums.size() - 1) cout << ", ";
    }
    cout << "]\n";
    cout << "   Result:   " << result << "\n";
    cout << "   Expected: " << expected << "\n";
    cout << "   Status:   " << (result == expected ? "PASS" : "FAIL");
    if (result != expected) {
        cout << " (Expected: " << expected << ")";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Mixed positive and negative numbers
    {
        vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int result = solution.maxSubArray(nums);
        printTestResult(nums, result, 6);  // Subarray: [4,-1,2,1]
    }
    
    // * Test Case 2: Single element
    {
        vector<int> nums = {1};
        int result = solution.maxSubArray(nums);
        printTestResult(nums, result, 1);
    }
    
    // * Test Case 3: All positive numbers
    {
        vector<int> nums = {5, 4, -1, 7, 8};
        int result = solution.maxSubArray(nums);
        printTestResult(nums, result, 23);  // Entire array
    }
    
    // ! Test Case 4: All negative numbers
    {
        vector<int> nums = {-3, -2, -5, -1, -4};
        int result = solution.maxSubArray(nums);
        printTestResult(nums, result, -1);  // Largest single element
    }
    
    // * Test Case 5: Two elements
    {
        vector<int> nums = {-2, 1};
        int result = solution.maxSubArray(nums);
        printTestResult(nums, result, 1);
    }
    
    // * Test Case 6: Alternating positive and negative
    {
        vector<int> nums = {1, -1, 1, -1, 1};
        int result = solution.maxSubArray(nums);
        printTestResult(nums, result, 1);
    }
    
    // * Test Case 7: Large consecutive positive sequence
    {
        vector<int> nums = {8, -19, 5, -4, 20};
        int result = solution.maxSubArray(nums);
        printTestResult(nums, result, 21);  // Subarray: [5,-4,20]
    }
    
    // * Test Case 8: Single negative element
    {
        vector<int> nums = {-1};
        int result = solution.maxSubArray(nums);
        printTestResult(nums, result, -1);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - Kadane's algorithm is one of the most elegant DP solutions
 * ! - The key insight is recognizing when to "give up" on the current subarray
 * * - This problem demonstrates the power of greedy approach in DP
 * ? - For tracking the actual subarray indices, maintain start/end pointers
 * * - Can be extended to 2D arrays (Maximum Sum Rectangle problem)
 * ================================================================================
 */