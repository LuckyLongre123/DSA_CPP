/**
 * ================================================================================
 * LeetCode 27: Remove Element - Two-Pointer In-Place Removal
 * ================================================================================
 * 
 * ! Problem: Given an integer array `nums` and an integer `val`, remove all
 * ! occurrences of `val` in-place. The relative order of elements may change.
 * ! Return the number of elements in `nums` which are not equal to `val`.
 * 
 * * Approach:
 * * 1. Initialize valIndex = 0 to track position for next valid element
 * * 2. Iterate through array with pointer j (0 to n-1)
 * * 3. When nums[j] != val:
 * *    - Swap nums[valIndex] with nums[j]
 * *    - Increment valIndex (boundary moves forward)
 * * 4. Return valIndex (count of valid elements)
 * 
 * ? Time Complexity: O(n) - Single pass through the array
 * ? Space Complexity: O(1) - In-place modifications with constant extra space
 * 
 * TODO Key Insight: 
 * *    - Two-pointer technique separates valid elements from target values
 * *    - valIndex acts as a boundary: [valid elements | garbage]
 * *    - Order may change, but all valid elements are preserved
 * 
 * * Optimizations: 
 * *    - Single pass eliminates need for auxiliary space
 * *    - Swap operation is efficient for in-place rearrangement
 * *    - Works correctly even when val is not present
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;
 
 class Solution {
 public:
     /**
      * Removes all occurrences of target value from array in-place
      * @param nums The input array to modify (passed by reference)
      * @param val The value to remove
      * @return The count of elements not equal to val
      */
     int removeElement(vector<int>& nums, int val) {
         int n = nums.size();  // * Total number of elements
         
         // * valIndex tracks the boundary between valid and invalid elements
         int valIndex = 0;  // * Position for next valid element
         
         // * Scan through entire array with j pointer
         for (int j = 0; j < n; j++) {
             // ? Check if current element should be kept
             if (nums[j] != val) {
                 // * Swap valid element to the valIndex position
                 swap(nums[valIndex], nums[j]);
                 
                 // * Move boundary forward to next empty slot
                 valIndex++;
                 // ! Elements at indices [0, valIndex) are all valid
             }
             // * If nums[j] == val, skip it (effectively removing it)
         }
         
         // * Return count of valid elements (also the new logical size)
         return valIndex;
     }
 };

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(vector<int>& nums, int val, int result, int expected) {
    cout << "\nval = " << val << ", Input array modified\n";
    cout << "   Result count:   " << result << "\n";
    cout << "   Expected count: " << expected << "\n";
    cout << "   Valid elements: [";
    for(int i = 0; i < result; i++) cout << nums[i] << (i < result-1 ? "," : "");
    cout << "]\n";
    cout << "   Status:   " << (result == expected ? "PASS" : "FAIL") << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Multiple occurrences in middle
    {
        vector<int> nums = {3,2,2,3};
        int result = solution.removeElement(nums, 3);
        printTestResult(nums, 3, result, 2);
    }
    
    // * Test Case 2: Multiple occurrences scattered
    {
        vector<int> nums = {0,1,2,2,3,0,4,2};
        int result = solution.removeElement(nums, 2);
        printTestResult(nums, 2, result, 5);
    }
    
    // * Test Case 3: Value not present
    {
        vector<int> nums = {1,2,3,4,5};
        int result = solution.removeElement(nums, 6);
        printTestResult(nums, 6, result, 5);
    }
    
    // * Test Case 4: All elements are target value
    {
        vector<int> nums = {7,7,7,7};
        int result = solution.removeElement(nums, 7);
        printTestResult(nums, 7, result, 0);
    }
    
    // ! Test Case 5: Empty array
    {
        vector<int> nums = {};
        int result = solution.removeElement(nums, 5);
        printTestResult(nums, 5, result, 0);
    }
    
    // * Test Case 6: Single element (not target)
    {
        vector<int> nums = {1};
        int result = solution.removeElement(nums, 2);
        printTestResult(nums, 2, result, 1);
    }
    
    // * Test Case 7: Single element (is target)
    {
        vector<int> nums = {3};
        int result = solution.removeElement(nums, 3);
        printTestResult(nums, 3, result, 0);
    }
    
    // * Test Case 8: Target at beginning and end
    {
        vector<int> nums = {5,1,2,3,5};
        int result = solution.removeElement(nums, 5);
        printTestResult(nums, 5, result, 3);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The two-pointer technique partitions array into valid and invalid sections
 * ! - No need to preserve original order - this allows optimal O(n) solution
 * * - valIndex boundary ensures all elements before it are valid
 * ? - After removal, elements at indices [valIndex, n) contain garbage values
 * * - Works correctly for edge cases: empty array, no target, all target
 * ================================================================================
 */
