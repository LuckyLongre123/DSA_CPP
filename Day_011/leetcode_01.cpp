/**
 * ================================================================================
 * 🌀 LeetCode 1: Two Sum - Hash Map Solution
 * ================================================================================
 * 
 * 🎯 Problem: Given an array of integers nums and an integer target, return indices
 * of the two numbers such that they add up to target.
 * 
 * 📝 Approach: Hash Map (One-pass)
 * 1. Use a hash map to store numbers and their indices
 * 2. For each number, calculate its complement (target - current number)
 * 3. If complement exists in map, return the indices
 * 4. Otherwise, add current number and its index to the map
 * 
 * ⚡ Time Complexity: O(n) - Single pass through the array
 * 💾 Space Complexity: O(n) - Store at most n elements in the hash map
 * 
 * 🧠 Key Insight: The complement (target - current) helps find the pair efficiently
 * 
 * 🚀 Optimizations: 
 *    - One-pass solution (faster in practice)
 *    - Early termination when pair is found
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //! MAIN FUNCTION: Finds two numbers that add up to target
    //! @param nums The input array of integers
    //! @param target The target sum to find
    //! @return Vector containing the indices of the two numbers
    vector<int> twoSum(vector<int>& nums, int target) {
        //? Hash map to store value -> index mapping
        unordered_map<int, int> numMap;
        
        //* Single pass through the array
        for (int i = 0; i < nums.size(); i++) {
            //? Calculate the complement needed to reach target
            int complement = target - nums[i];
            
            //! Check if complement exists in the map
            if (numMap.find(complement) != numMap.end()) {
                //* Found the pair, return the indices
                return {numMap[complement], i};
            }
            
            //* Add current number and its index to the map
            numMap[nums[i]] = i;
        }
        
        //* No solution found (though problem states there is exactly one)
        return {};
    }
};

// ============================================================
// 🧪 TESTING SUITE - Verifies solution with various test cases
// ============================================================

//! Helper function to print test results
void printTestResult(const string& testName, const vector<int>& result, const vector<int>& expected) {
    cout << "\n🔍 " << testName << "\n";
    cout << "   Result:   [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]\n   Expected: [";
    for (size_t i = 0; i < expected.size(); i++) {
        cout << expected[i];
        if (i != expected.size() - 1) cout << ", ";
    }
    cout << "]\n";
    cout << "   Status:   " << (result == expected ? "✅ PASS" : "❌ FAIL") << "\n";
}

int main() {
    Solution solution;
    
    // Test Case 1: Basic case
    {
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        vector<int> result = solution.twoSum(nums, target);
        printTestResult("Test Case 1: Basic Case", result, {0, 1});
    }
    
    // Test Case 2: Duplicate values
    {
        vector<int> nums = {3, 2, 4};
        int target = 6;
        vector<int> result = solution.twoSum(nums, target);
        printTestResult("Test Case 2: Duplicate Values", result, {1, 2});
    }
    
    // Test Case 3: Same number used twice (not allowed)
    {
        vector<int> nums = {3, 3};
        int target = 6;
        vector<int> result = solution.twoSum(nums, target);
        printTestResult("Test Case 3: Same Number Twice", result, {0, 1});
    }
    
    // Test Case 4: Negative numbers
    {
        vector<int> nums = {-1, -2, -3, -4, -5};
        int target = -8;
        vector<int> result = solution.twoSum(nums, target);
        printTestResult("Test Case 4: Negative Numbers", result, {2, 4});
    }
    
    return 0;
}

/*
 * ================================================================================
 * 📝 Additional Notes:
 * - The solution handles all edge cases including negative numbers and zero
 * - The hash map approach is more efficient than the brute-force O(n²) solution
 * - The problem guarantees exactly one solution, so we don't need to handle
 *   multiple solutions or no solution cases in the main logic
 * ================================================================================
 */
