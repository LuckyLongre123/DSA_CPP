/**
 * ================================================================================
 * 🌀 LeetCode 26: Remove Duplicates from Sorted Array - Two Pointers Solution
 * ================================================================================
 * 
 * 🎯 Problem: Given an integer array `nums` sorted in non-decreasing order, remove 
 * the duplicates in-place such that each unique element appears only once. The 
 * relative order of the elements should be kept the same. Return the number of 
 * unique elements.
 * 
 * 📝 Approach: Two Pointers Technique
 * 1. Use two pointers: `i` (slow) and `j` (fast)
 * 2. `i` tracks the position of the last unique element
 * 3. `j` scans through the array to find the next unique element
 * 4. When a new unique element is found, increment `i` and copy the element
 * 5. The first k elements will contain the unique elements in order
 * 
 * ⚡ Time Complexity: O(n) - Single pass through the array
 * 💾 Space Complexity: O(1) - In-place modification with constant extra space
 * 
 * 🧠 Key Insight: 
 *    - Since the array is sorted, all duplicates are adjacent
 *    - The two-pointer approach efficiently skips over duplicates
 *    - The first k elements are modified in-place to contain unique elements
 * 
 * 🚀 Optimizations: 
 *    - Early return for empty array
 *    - Single pass algorithm
 *    - No extra space required (in-place)
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm> // For std::unique (alternative implementation)
using namespace std;

class Solution {
public:
    //! MAIN FUNCTION: Removes duplicates in-place and returns the count of unique elements
    //! @param nums Reference to the input vector (modified in-place)
    //! @return Number of unique elements in the modified array
    int removeDuplicates(vector<int>& nums) {
        //? Handle edge case: empty array
        if (nums.empty()) return 0;
        
        int i = 0;  // Slow pointer (last unique element index)
        
        //? Fast pointer j scans through the array
        for (int j = 1; j < nums.size(); j++) {
            //? When a new unique element is found
            if (nums[j] != nums[i]) {
                i++;  // Move slow pointer
                nums[i] = nums[j];  // Store the unique element
            }
            //? If elements are the same, j continues to next element
        }
        
        //? Return the count of unique elements (i+1 since i is 0-based index)
        return i + 1;
    }
    
    //! ALTERNATIVE: Using STL's unique (for reference)
    //! Time: O(n), Space: O(1)
    int removeDuplicatesSTL(vector<int>& nums) {
        //? unique() moves all unique elements to the front and returns iterator to new end
        //? erase() removes the elements after the new end
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};

// ============================================================
// 🧪 TESTING SUITE - Verifies solution with various test cases
// ============================================================

//! Helper function to print test results
void printTestResult(const string& testName, const vector<int>& nums, int result, const vector<int>& expectedNums, int expectedResult) {
    cout << "\n🔍 " << testName << "\n";
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
    
    cout << "   Status:   " << (isCorrect ? "✅ PASS" : "❌ FAIL") << "\n";
}

int main() {
    Solution solution;
    
    // Test Case 1: Basic case with duplicates
    {
        vector<int> nums = {1, 1, 2};
        vector<int> original = nums; // Make a copy for display
        int result = solution.removeDuplicates(nums);
        vector<int> expectedNums = {1, 2};
        printTestResult("Basic case with duplicates", original, result, expectedNums, 2);
    }
    
    // Test Case 2: Multiple duplicates
    {
        vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        vector<int> original = nums;
        int result = solution.removeDuplicates(nums);
        vector<int> expectedNums = {0, 1, 2, 3, 4};
        printTestResult("Multiple duplicates", original, result, expectedNums, 5);
    }
    
    // Test Case 3: No duplicates
    {
        vector<int> nums = {1, 2, 3, 4, 5};
        vector<int> original = nums;
        int result = solution.removeDuplicates(nums);
        vector<int> expectedNums = {1, 2, 3, 4, 5};
        printTestResult("No duplicates", original, result, expectedNums, 5);
    }
    
    // Test Case 4: Empty array
    {
        vector<int> nums = {};
        vector<int> original = nums;
        int result = solution.removeDuplicates(nums);
        vector<int> expectedNums = {};
        printTestResult("Empty array", original, result, expectedNums, 0);
    }
    
    // Test Case 5: All elements same
    {
        vector<int> nums = {7, 7, 7, 7, 7};
        vector<int> original = nums;
        int result = solution.removeDuplicates(nums);
        vector<int> expectedNums = {7};
        printTestResult("All elements same", original, result, expectedNums, 1);
    }
    
    // Test Case 6: Large input (performance test)
    {
        vector<int> nums;
        for (int i = 0; i < 10000; i++) {
            nums.push_back(i / 2);  // Creates 5000 unique elements with duplicates
        }
        vector<int> original = {0, 1, 2};  // Just show sample for display
        int result = solution.removeDuplicates(nums);
        cout << "\n🔍 Large input (performance test)\n";
        cout << "   Input:    [0, 0, 1, 1, 2, ...] (size: 10000)\n";
        cout << "   Result:   " << result << " unique elements\n";
        cout << "   Expected: 5000 unique elements\n";
        cout << "   Status:   " << (result == 5000 ? "✅ PASS" : "❌ FAIL") << "\n";
    }
    
    return 0;
}

/*
 * ================================================================================
 * 📝 Additional Notes:
 * - The two-pointer approach is optimal for this problem with O(n) time and O(1) space
 * - The STL version using std::unique is concise but less efficient in practice
 * - The solution maintains the relative order of elements
 * - For unsorted arrays, sorting first would be needed (O(n log n) time)
 * ================================================================================
 */
