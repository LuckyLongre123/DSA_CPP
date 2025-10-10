/**
 * ================================================================================
 * LeetCode 33: Search in Rotated Sorted Array - modified Binary Search
 * ================================================================================
 * 
 * ! Problem: There is an integer array `nums` sorted in ascending order (with distinct values).
 * ! Prior to being passed to the function, nums is possibly rotated at an unknown pivot index k.
 * ! Given the array `nums` after the possible rotation and an integer `target`, 
 * ! return the index of `target` if it is in `nums`, or -1 if it is not in `nums`.
 * ! You must write an algorithm with O(log n) runtime complexity.
 * 
 * * Approach:
 * * 1. Use modified binary search to handle the rotated array
 * * 2. At each step, determine which half (left or right) is sorted
 * * 3. Check if target lies in the sorted half's range
 * * 4. If yes, search that half; otherwise search the other half
 * * 5. Continue until target is found or search space is exhausted
 * 
 * ? Time Complexity: O(log n) - Binary search eliminates half the array each iteration
 * ? Space Complexity: O(1) - Only constant extra space for variables
 * 
 * TODO Key Insight: 
 * *    - A rotated sorted array has two sorted portions
 * *    - At any mid point, at least ONE half is definitely sorted
 * *    - We can identify the sorted half by comparing nums[start] with nums[mid]
 * *    - Once we know which half is sorted, we can use normal range checking
 * 
 * * Optimizations: 
 * *    - Overflow-safe mid calculation: mid = s + (e - s) / 2
 * *    - Single pass with O(log n) guarantee
 * *    - No extra space needed
 * ================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Searches for a target value in a rotated sorted array
     * @param nums The rotated sorted array (distinct values)
     * @param target The value to search for
     * @return The index of target if found, -1 otherwise
     */
    int search(vector<int>& nums, int target) {
        int s = 0;                     // * Start pointer
        int e = nums.size() - 1;       // * End pointer
        
        while (s <= e) {
            int mid = s + (e - s) / 2;  // * Calculate mid (overflow-safe)
            
            // ! Check if we found the target
            if (nums[mid] == target) {
                return mid;
            }
            
            // ? Determine which half is sorted
            // * If nums[s] <= nums[mid], left half [s...mid] is sorted
            if (nums[s] <= nums[mid]) {
                // * Left half is sorted: [s, s+1, ..., mid]
                
                // ? Check if target is in the sorted left half's range
                if (nums[s] <= target && target < nums[mid]) {
                    // * Target is in left sorted portion
                    e = mid - 1;  // ! Search left half
                } else {
                    // * Target must be in right half
                    s = mid + 1;  // ! Search right half
                }
            }
            else {
                // * Right half is sorted: [mid, mid+1, ..., e]
                
                // ? Check if target is in the sorted right half's range
                if (nums[mid] < target && target <= nums[e]) {
                    // * Target is in right sorted portion
                    s = mid + 1;  // ! Search right half
                } else {
                    // * Target must be in left half
                    e = mid - 1;  // ! Search left half
                }
            }
        }
        
        // ! Target not found in the array
        return -1;
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(vector<int>& nums, int target, int result, int expected) {
    cout << "\nnums = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "], target = " << target << "\n";
    cout << "   Result:   " << result << "\n";
    cout << "   Expected: " << expected << "\n";
    cout << "   Status:   " << (result == expected ? "PASS" : "FAIL");
    cout << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Target in left sorted portion
    {
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 5;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, 1);
    }
    
    // * Test Case 2: Target in right sorted portion
    {
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 0;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, 4);
    }
    
    // * Test Case 3: Target not found
    {
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 3;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, -1);
    }
    
    // * Test Case 4: Single element found
    {
        vector<int> nums = {1};
        int target = 1;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, 0);
    }
    
    // * Test Case 5: Single element not found
    {
        vector<int> nums = {1};
        int target = 0;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, -1);
    }
    
    // * Test Case 6: No rotation (normal sorted array)
    {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
        int target = 4;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, 3);
    }
    
    // * Test Case 7: Two elements rotated
    {
        vector<int> nums = {3, 1};
        int target = 1;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, 1);
    }
    
    // * Test Case 8: Target at rotation boundary
    {
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 7;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, 3);
    }
    
    // * Test Case 9: Larger array with rotation
    {
        vector<int> nums = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
        int target = 10;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, 4);
    }
    
    // * Test Case 10: Target at first position after rotation
    {
        vector<int> nums = {5, 1, 2, 3, 4};
        int target = 5;
        int result = solution.search(nums, target);
        printTestResult(nums, target, result, 0);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The key insight is that one half of the array is always sorted after rotation
 * ! - We use nums[s] <= nums[mid] to determine which half is sorted
 * * - Once we identify the sorted half, we use normal range checking
 * ? - The algorithm maintains O(log n) time by halving search space each iteration
 * * - Edge cases like single element and no rotation are handled automatically
 * ! - The use of <= (not <) in sorted check handles the no-rotation case correctly
 * * - This technique extends to finding rotation point and minimum element
 * ================================================================================
 */