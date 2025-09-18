/**
 * ================================================================================
 * 🌀 LeetCode 3550: Find Smallest Index Where Index Equals Sum of Digits
 * ================================================================================
 * 
 * 🎯 Problem: Given an array of integers `nums`, find the smallest index `i` such 
 * that `i` is equal to the sum of the digits of `nums[i]`. If no such index 
 * exists, return -1.
 * 
 * 📝 Approach:
 * 1. Iterate through each element in the array with its index
 * 2. For each number, calculate the sum of its digits
 * 3. If the sum of digits equals the current index, return the index immediately
 * 4. If no such index is found after checking all elements, return -1
 * 
 * ⚡ Time Complexity: O(n * d) where n is the number of elements and d is the 
 *    average number of digits in each number
 * 💾 Space Complexity: O(1) - Constant extra space used
 * 
 * 🧠 Key Insight: 
 *    - The problem can be solved with a single pass through the array
 *    - For each element, we need to calculate the sum of its digits
 *    - The solution can return early when the first valid index is found
 * 
 * 🚀 Optimizations: 
 *    - Early termination when the first valid index is found
 *    - Efficient digit sum calculation using modulo and division
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    //! Calculates the sum of digits of a number
    //! @param num The input number
    //! @return Sum of digits of the number
    int sumOfDigits(int num) {
        //? Handle negative numbers by taking absolute value
        num = abs(num);
        int sum = 0;
        
        //* Extract each digit using modulo and division
        while (num > 0) {
            sum += num % 10;  //* Add last digit to sum
            num /= 10;        //* Remove last digit
        }
        
        return sum;
    }
    
    //! MAIN FUNCTION: Finds the smallest index where index equals sum of digits
    //! @param nums The input array of integers
    //! @return The smallest valid index or -1 if none found
    int smallestIndex(vector<int>& nums) {
        //* Iterate through each element with its index
        for (int i = 0; i < nums.size(); i++) {
            //? Calculate sum of digits for current number
            int digitSum = sumOfDigits(nums[i]);
            
            //! Check if current index matches the digit sum
            if (i == digitSum) {
                return i;  //* Return immediately when found
            }
        }
        
        //* No valid index found
        return -1;
    }
};

// ============================================================
// 🧪 TESTING SUITE - Verifies solution with various test cases
// ============================================================

//! Helper function to print test results
void printTestResult(const vector<int>& nums, int result, int expected) {
    cout << "\n🔍 Test Case: [";
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]\n";
    cout << "   Result:   " << result << "\n";
    cout << "   Expected: " << expected << "\n";
    cout << "   Status:   " << (result == expected ? "✅ PASS" : "❌ FAIL") << "\n";
}

int main() {
    Solution solution;
    
    // Test Case 1: Example from problem statement
    {
        vector<int> nums = {12, 34, 5, 67};
        int result = solution.smallestIndex(nums);
        printTestResult(nums, result, 2);
    }
    
    // Test Case 2: No valid index
    {
        vector<int> nums = {10, 21, 32};
        int result = solution.smallestIndex(nums);
        printTestResult(nums, result, -1);
    }
    
    // Test Case 3: First element matches (index 0)
    {
        vector<int> nums = {0, 10, 20};
        int result = solution.smallestIndex(nums);
        printTestResult(nums, result, 0);
    }
    
    // Test Case 4: Multiple valid indices (should return smallest)
    {
        vector<int> nums = {0, 1, 20, 30, 13};
        int result = solution.smallestIndex(nums);
        printTestResult(nums, result, 0);
    }
    
    // Test Case 5: Large numbers
    {
        vector<int> nums = {100000, 200000, 300000, 400000, 5};
        int result = solution.smallestIndex(nums);
        printTestResult(nums, result, 4);
    }
    
    // Test Case 6: Single element array (valid)
    {
        vector<int> nums = {0};
        int result = solution.smallestIndex(nums);
        printTestResult(nums, result, 0);
    }
    
    // Test Case 7: Single element array (invalid)
    {
        vector<int> nums = {5};
        int result = solution.smallestIndex(nums);
        printTestResult(nums, result, -1);
    }
    
    return 0;
}

/*
 * ================================================================================
 * 📝 Additional Notes:
 * - The solution handles all edge cases including empty arrays and single-element arrays
 * - The digit sum function works with negative numbers (takes absolute value)
 * - The solution is efficient with early termination when the first valid index is found
 * - For very large arrays, the time complexity remains O(n) where n is the array length
 * ================================================================================
 */
