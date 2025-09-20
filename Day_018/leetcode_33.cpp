/**
 * ================================================================================
 * 🌀 LeetCode 33: Search in Rotated Sorted Array - Binary Search Solution
 * ================================================================================
 * 
 * 🎯 Problem: Given an integer array `nums` sorted in ascending order (with distinct values)
 * that is rotated at some pivot index, and an integer `target`, return the index of 
 * `target` in `nums` or `-1` if not found.
 * 
 * 📝 Approach: Modified Binary Search
 * 1. Use binary search to find the target in O(log n) time
 * 2. At each step, determine which half of the array is sorted
 * 3. Check if the target lies within the sorted half:
 *    - If yes, search in that half
 *    - If no, search in the other half
 * 
 * ⚡ Time Complexity: O(log n) - Each iteration reduces search space by half
 * 💾 Space Complexity: O(1) - Constant extra space used
 * 
 * 🧠 Key Insight: 
 *    - In a rotated sorted array, at least one half (left or right of mid) is always sorted
 *    - By checking which half is sorted, we can determine where the target might be
 * 
 * 🚀 Optimizations: 
 *    - Early return when target is found
 *    - Single pass algorithm
 *    - No extra space required
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    //! MAIN FUNCTION: Searches for target in rotated sorted array
    //! @param nums The rotated sorted array with distinct values
    //! @param target The value to search for
    //! @return Index of target if found, -1 otherwise
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;  // Prevents integer overflow

            //? Found the target
            if (nums[mid] == target) {
                return mid;
            }

            //? Check if left half is sorted
            if (nums[left] <= nums[mid]) {
                //? If target is in the left sorted half
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;  // Search left
                } else {
                    left = mid + 1;   // Search right
                }
            }
            //? Right half must be sorted
            else {
                //? If target is in the right sorted half
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;   // Search right
                } else {
                    right = mid - 1;  // Search left
                }
            }
        }

        //! Target not found
        return -1;
    }
    
    //! ALTERNATIVE: Two-pass approach (for reference)
    //! 1. Find the pivot (smallest element)
    //! 2. Perform binary search on the appropriate half
    //! Time: O(log n), Space: O(1)
    int searchTwoPass(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        
        // Find the index of the smallest element (pivot)
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        int pivot = left;
        left = 0;
        right = nums.size() - 1;
        
        // Determine which subarray to search
        if (target >= nums[pivot] && target <= nums[right]) {
            left = pivot;
        } else {
            right = pivot - 1;
        }
        
        // Standard binary search
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};

// ============================================================
// 🧪 TESTING SUITE - Verifies solution with various test cases
// ============================================================

//! Helper function to print test results
void printTestResult(const vector<int>& nums, int target, int result, int expected) {
    cout << "\n🔍 Input: nums = [";
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "], target = " << target << "\n";
    
    cout << "   Result:   " << result << "\n";
    cout << "   Expected: " << expected << "\n";
    cout << "   Status:   " << (result == expected ? "✅ PASS" : "❌ FAIL");
    if (result != expected) {
        cout << " (Expected: " << expected << ")";
    }
    cout << "\n";
    
    if (result != -1) {
        cout << "   Position: nums[" << result << "] = " << nums[result] << "\n";
    }
}

int main() {
    Solution solution;
    
    // Test Case 1: Target in right half after rotation
    {
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 0;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, 4);
    }
    
    // Test Case 2: Target not in array
    {
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 3;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, -1);
    }
    
    // Test Case 3: Single element array (target found)
    {
        vector<int> nums = {1};
        int target = 1;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, 0);
    }
    
    // Test Case 4: Single element array (target not found)
    {
        vector<int> nums = {1};
        int target = 2;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, -1);
    }
    
    // Test Case 5: Not rotated array
    {
        vector<int> nums = {1, 3, 5, 7, 9, 11};
        int target = 5;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, 2);
    }
    
    // Test Case 6: Target at pivot point
    {
        vector<int> nums = {5, 1, 3};
        int target = 1;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, 1);
    }
    
    // Test Case 7: Large rotated array
    {
        vector<int> nums = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
        int target = 5;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, 8);
    }
    
    return 0;
}

/*
 * ================================================================================
 * 📝 Additional Notes:
 * - The solution assumes all elements in the array are unique
 * - For arrays with duplicates, the time complexity could degrade to O(n) in the worst case
 * - The algorithm can be extended to handle multiple rotations, but the current
 *   problem states the array is rotated at most once
 * - The two-pass approach might be more intuitive but has the same time complexity
 * ================================================================================
 */
