/**
 * ================================================================================
 * LeetCode 35: Search Insert Position - Binary Search Algorithm
 * ================================================================================
 * 
 * ! Problem: Given a sorted array of distinct integers and a target value,
 * ! return the index if the target is found. If not, return the index where
 * ! it would be if it were inserted in order.
 * ! You must write an algorithm with O(log n) runtime complexity.
 * 
 * * Approach:
 * * 1. Initialize two pointers: start (s) at 0 and end (e) at last index
 * * 2. Calculate mid point using safe formula to avoid overflow
 * * 3. While search space is valid (s <= e):
 * *    - If target found at mid, return mid index
 * *    - If target is greater than mid element, search right half
 * *    - If target is smaller than mid element, search left half
 * * 4. If target not found, return insertion position (mid + 1)
 * 
 * ? Time Complexity: O(log n) - Binary search halves the search space each iteration
 * ? Space Complexity: O(1) - Only constant extra space for pointers
 * 
 * TODO Key Insight: 
 * *    - Binary search works because the array is sorted
 * *    - The final position (mid + 1) is where target should be inserted
 * *    - Safe mid calculation prevents integer overflow: mid = e + (s - e) / 2
 * *    - When loop ends, 's' points to insertion position
 * 
 * * Optimizations: 
 * *    - Single pass through logarithmic search space
 * *    - No extra memory allocation required
 * *    - Handles all edge cases (empty array, boundaries, duplicates)
 * ================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds target index or insertion position in sorted array
     * @param nums Sorted array of distinct integers
     * @param target Value to search for
     * @return Index of target or position where it should be inserted
     */
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;                    // * Start pointer at beginning
        int e = nums.size() - 1;      // * End pointer at last index
        int mid = e + (s - e) / 2;    // * Safe mid calculation to prevent overflow
        
        while (s <= e) {              // * Continue while search space is valid
            if (nums[mid] == target) {
                return mid;           // ! Target found at mid index
            }
            else if (nums[mid] < target) {
                s = mid + 1;          // * Target is in right half, move start right
            }
            else {
                e = mid - 1;          // * Target is in left half, move end left
            }
            
            mid = e + (s - e) / 2;    // ? Recalculate mid for new search space
        }
        
        return mid + 1;               // ! Target not found, return insertion position
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(vector<int>& nums, int target, int result, int expected) {
    cout << "\nArray: [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "], Target: " << target << "\n";
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
    
    // * Test Case 1: Target found in middle
    {
        vector<int> nums = {1, 3, 5, 6};
        int target = 5;
        int result = solution.searchInsert(nums, target);
        printTestResult(nums, target, result, 2);
    }
    
    // * Test Case 2: Target should be inserted at beginning
    {
        vector<int> nums = {1, 3, 5, 6};
        int target = 0;
        int result = solution.searchInsert(nums, target);
        printTestResult(nums, target, result, 0);
    }
    
    // * Test Case 3: Target should be inserted in middle
    {
        vector<int> nums = {1, 3, 5, 6};
        int target = 2;
        int result = solution.searchInsert(nums, target);
        printTestResult(nums, target, result, 1);
    }
    
    // * Test Case 4: Target should be inserted at end
    {
        vector<int> nums = {1, 3, 5, 6};
        int target = 7;
        int result = solution.searchInsert(nums, target);
        printTestResult(nums, target, result, 4);
    }
    
    // * Test Case 5: Single element array - target found
    {
        vector<int> nums = {1};
        int target = 1;
        int result = solution.searchInsert(nums, target);
        printTestResult(nums, target, result, 0);
    }
    
    // ! Test Case 6: Single element array - insert before
    {
        vector<int> nums = {1};
        int target = 0;
        int result = solution.searchInsert(nums, target);
        printTestResult(nums, target, result, 0);
    }
    
    // ! Test Case 7: Single element array - insert after
    {
        vector<int> nums = {1};
        int target = 2;
        int result = solution.searchInsert(nums, target);
        printTestResult(nums, target, result, 1);
    }
    
    // * Test Case 8: Large array - target at start
    {
        vector<int> nums = {1, 3, 5, 7, 9, 11, 13, 15};
        int target = 1;
        int result = solution.searchInsert(nums, target);
        printTestResult(nums, target, result, 0);
    }
    
    // * Test Case 9: Large array - target at end
    {
        vector<int> nums = {1, 3, 5, 7, 9, 11, 13, 15};
        int target = 15;
        int result = solution.searchInsert(nums, target);
        printTestResult(nums, target, result, 7);
    }
    
    // * Test Case 10: Large array - insert in middle
    {
        vector<int> nums = {1, 3, 5, 7, 9, 11, 13, 15};
        int target = 8;
        int result = solution.searchInsert(nums, target);
        printTestResult(nums, target, result, 4);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - Binary search requires sorted array as prerequisite
 * ! - Safe mid calculation (e + (s - e) / 2) prevents overflow with large indices
 * * - When loop terminates, 's' naturally points to correct insertion position
 * ? - For duplicate elements, this returns any valid index of the target
 * * - Works for arrays of any size including empty arrays
 * ================================================================================
 */