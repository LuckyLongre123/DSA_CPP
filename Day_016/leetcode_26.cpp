/**
 * ================================================================================
 * LeetCode 26: Remove Duplicates from Sorted Array - Two Pointers
 * ================================================================================
 * 
 * ! Problem: Given an integer array `nums` sorted in non-decreasing order, remove 
 * ! the duplicates in-place such that each unique element appears only once. The 
 * ! relative order of the elements should be kept the same. Return the number of 
 * ! unique elements in `nums`.
 * 
 * * Approach:
 * * 1. Use two pointers: `i` (slow pointer) and `j` (fast pointer)
 * * 2. `i` tracks the position of the last unique element found
 * * 3. `j` scans through the array starting from index 1
 * * 4. When nums[j] != nums[i], increment `i` and copy nums[j] to nums[i]
 * * 5. Return i + 1 as the count of unique elements
 * 
 * ? Time Complexity: O(n) - Single pass through the array
 * ? Space Complexity: O(1) - In-place modification with constant extra space
 * 
 * TODO Key Insight: 
 * *    - Since the array is sorted, all duplicates are adjacent
 * *    - The two-pointer approach efficiently skips over duplicate sequences
 * *    - We maintain the first k elements as unique, rest can be ignored
 * 
 * * Optimizations: 
 * *    - Early return for empty arrays
 * *    - Single pass algorithm without nested loops
 * *    - No extra space required (purely in-place)
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // For std::unique (alternative implementation)
using namespace std;

class Solution {
public:
    /**
     * Removes duplicates from a sorted array in-place
     * @param nums The input vector (modified in-place)
     * @return Number of unique elements in the modified array
     */
    int removeDuplicates(vector<int>& nums) {
        // ! Handle edge case: empty array
        if (nums.empty()) return 0;
        
        int i = 0;  // * Slow pointer - tracks position of last unique element
        
        // * Fast pointer j scans through the array starting from index 1
        for (int j = 1; j < nums.size(); j++) {
            // ? Check if current element is different from last unique element
            if (nums[j] != nums[i]) {
                i++;  // * Move slow pointer to next position
                nums[i] = nums[j];  // * Copy the new unique element
            }
            // * If elements are same, j continues scanning for next unique element
        }
        
        // * Return count of unique elements (i+1 since i is 0-indexed)
        return i + 1;
    }
    
    /**
     * Alternative implementation using STL's unique function
     * Time: O(n), Space: O(1)
     */
    int removeDuplicatesSTL(vector<int>& nums) {
        // ? unique() rearranges elements so unique ones are at front
        // ? Returns iterator to new end, then erase removes duplicates
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(const string& testName, const vector<int>& nums, int result, const vector<int>& expectedNums, int expectedResult) {
    cout << "\n" << testName << "\n";
    cout << "   Input:    [";
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]\n";
    
    cout << "   Output:   " << result << ", nums = [";
    for (int i = 0; i < result; i++) {
        cout << nums[i];
        if (i != result - 1) cout << ", ";
    }
    cout << "]\n";
    
    bool isCorrect = (result == expectedResult);
    if (isCorrect) {
        // Verify the first 'result' elements match expectedNums
        for (int i = 0; i < result && i < (int)expectedNums.size(); i++) {
            if (nums[i] != expectedNums[i]) {
                isCorrect = false;
                break;
            }
        }
    }
    
    cout << "   Expected: " << expectedResult << ", nums = [";
    for (size_t i = 0; i < expectedNums.size(); i++) {
        cout << expectedNums[i];
        if (i != expectedNums.size() - 1) cout << ", ";
    }
    cout << "]\n";
    
    cout << "   Status:   " << (isCorrect ? "PASS" : "FAIL") << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Basic case with duplicates
    {
        vector<int> nums = {1, 1, 2};
        vector<int> original = nums;
        int result = solution.removeDuplicates(nums);
        vector<int> expectedNums = {1, 2};
        printTestResult("Test Case 1: Basic case with duplicates", original, result, expectedNums, 2);
    }
    
    // * Test Case 2: Multiple duplicates
    {
        vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        vector<int> original = nums;
        int result = solution.removeDuplicates(nums);
        vector<int> expectedNums = {0, 1, 2, 3, 4};
        printTestResult("Test Case 2: Multiple duplicates", original, result, expectedNums, 5);
    }
    
    // * Test Case 3: No duplicates
    {
        vector<int> nums = {1, 2, 3, 4, 5};
        vector<int> original = nums;
        int result = solution.removeDuplicates(nums);
        vector<int> expectedNums = {1, 2, 3, 4, 5};
        printTestResult("Test Case 3: No duplicates", original, result, expectedNums, 5);
    }
    
    // ! Test Case 4: Empty array
    {
        vector<int> nums = {};
        vector<int> original = nums;
        int result = solution.removeDuplicates(nums);
        vector<int> expectedNums = {};
        printTestResult("Test Case 4: Empty array", original, result, expectedNums, 0);
    }
    
    // * Test Case 5: All elements same
    {
        vector<int> nums = {7, 7, 7, 7, 7};
        vector<int> original = nums;
        int result = solution.removeDuplicates(nums);
        vector<int> expectedNums = {7};
        printTestResult("Test Case 5: All elements same", original, result, expectedNums, 1);
    }
    
    // * Test Case 6: Large input (performance test)
    {
        vector<int> nums;
        for (int i = 0; i < 10000; i++) {
            nums.push_back(i / 2);  // Creates 5000 unique elements with duplicates
        }
        int result = solution.removeDuplicates(nums);
        cout << "\nTest Case 6: Large input (performance test)\n";
        cout << "   Input:    [0, 0, 1, 1, 2, ...] (size: 10000)\n";
        cout << "   Result:   " << result << " unique elements\n";
        cout << "   Expected: 5000 unique elements\n";
        cout << "   Status:   " << (result == 5000 ? "PASS" : "FAIL") << "\n";
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The two-pointer approach is optimal for this problem: O(n) time and O(1) space
 * ! - We check for overflow before actual operations to prevent undefined behavior
 * * - The solution maintains the relative order of elements as required
 * ? - For unsorted arrays, sorting first would be required (O(n log n) time complexity)
 * * - The STL unique() function provides a cleaner but less educational alternative
 * ================================================================================
 */
