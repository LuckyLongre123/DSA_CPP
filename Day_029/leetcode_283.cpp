/**
 * ================================================================================
 * LeetCode 283: Move Zeroes - Two-Pointer Stable Rearrangement
 * ================================================================================
 * 
 * ! Problem: Given an integer array `nums`, move all 0's to the end while
 * ! maintaining the relative order of non-zero elements. Must be done in-place
 * ! without making a copy of the array.
 * 
 * * Approach:
 * * 1. Initialize zeroIndex = 0 to track position for next non-zero element
 * * 2. Iterate through array with pointer j (0 to n-1)
 * * 3. When nums[j] != 0:
 * *    - Swap nums[zeroIndex] with nums[j]
 * *    - Increment zeroIndex (boundary moves forward)
 * * 4. Zeros naturally accumulate at the end
 * 
 * ? Time Complexity: O(n) - Single pass through the array
 * ? Space Complexity: O(1) - In-place modifications with constant extra space
 * 
 * TODO Key Insight: 
 * *    - Two-pointer technique maintains stability (relative order preserved)
 * *    - zeroIndex creates a boundary: [non-zeros | zeros]
 * *    - Swap operation ensures non-zeros move forward, zeros move backward
 * 
 * * Optimizations: 
 * *    - Single pass eliminates need for multiple scans
 * *    - Swap operation is efficient for in-place rearrangement
 * *    - Works correctly even with no zeros or all zeros
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;
 
 class Solution {
 public:
     /**
      * Moves all zeros to the end while preserving relative order of non-zeros
      * @param nums The input array to modify (passed by reference)
      */
     void moveZeroes(vector<int>& nums) {
         int n = nums.size();  // * Total number of elements
         
         // * zeroIndex tracks the boundary between non-zero and zero elements
         int zeroIndex = 0;  // * Position for next non-zero element
         
         // * Scan through entire array with j pointer
         for(int j = 0; j < n; j++) {
             // ? Check if current element is non-zero
             if(nums[j] != 0) {
                 // * Swap non-zero element to the zeroIndex position
                 swap(nums[zeroIndex], nums[j]);
                 
                 // * Move boundary forward to next empty slot
                 zeroIndex++;
                 // ! Elements at indices [0, zeroIndex) are all non-zero
             }
             // * If nums[j] == 0, skip it (it will end up at the back)
         }
         
         // * After loop: all non-zeros are at front, all zeros at end
         // * Relative order of non-zeros is preserved due to stable swapping
     }
 };

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(vector<int>& input, vector<int>& result, vector<int>& expected, string testName) {
    cout << "\n" << testName << "\n";
    cout << "   Input:    [";
    for(int i = 0; i < input.size(); i++) cout << input[i] << (i < input.size()-1 ? "," : "");
    cout << "]\n";
    cout << "   Result:   [";
    for(int i = 0; i < result.size(); i++) cout << result[i] << (i < result.size()-1 ? "," : "");
    cout << "]\n";
    cout << "   Expected: [";
    for(int i = 0; i < expected.size(); i++) cout << expected[i] << (i < expected.size()-1 ? "," : "");
    cout << "]\n";
    cout << "   Status:   " << (result == expected ? "PASS" : "FAIL") << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Mixed zeros and non-zeros
    {
        vector<int> input = {0,1,0,3,12};
        vector<int> nums = input;
        solution.moveZeroes(nums);
        vector<int> expected = {1,3,12,0,0};
        printTestResult(input, nums, expected, "Test Case 1: Mixed Elements");
    }
    
    // * Test Case 2: Single zero
    {
        vector<int> input = {0};
        vector<int> nums = input;
        solution.moveZeroes(nums);
        vector<int> expected = {0};
        printTestResult(input, nums, expected, "Test Case 2: Single Zero");
    }
    
    // * Test Case 3: No zeros
    {
        vector<int> input = {1,2,3,4,5};
        vector<int> nums = input;
        solution.moveZeroes(nums);
        vector<int> expected = {1,2,3,4,5};
        printTestResult(input, nums, expected, "Test Case 3: No Zeros");
    }
    
    // * Test Case 4: All zeros
    {
        vector<int> input = {0,0,0,0};
        vector<int> nums = input;
        solution.moveZeroes(nums);
        vector<int> expected = {0,0,0,0};
        printTestResult(input, nums, expected, "Test Case 4: All Zeros");
    }
    
    // ! Test Case 5: Zeros at beginning
    {
        vector<int> input = {0,0,1,2,3};
        vector<int> nums = input;
        solution.moveZeroes(nums);
        vector<int> expected = {1,2,3,0,0};
        printTestResult(input, nums, expected, "Test Case 5: Leading Zeros");
    }
    
    // * Test Case 6: Zeros at end (already sorted)
    {
        vector<int> input = {1,2,3,0,0};
        vector<int> nums = input;
        solution.moveZeroes(nums);
        vector<int> expected = {1,2,3,0,0};
        printTestResult(input, nums, expected, "Test Case 6: Already Sorted");
    }
    
    // * Test Case 7: Single non-zero
    {
        vector<int> input = {5};
        vector<int> nums = input;
        solution.moveZeroes(nums);
        vector<int> expected = {5};
        printTestResult(input, nums, expected, "Test Case 7: Single Non-Zero");
    }
    
    // * Test Case 8: Alternating zeros and non-zeros
    {
        vector<int> input = {0,1,0,2,0,3};
        vector<int> nums = input;
        solution.moveZeroes(nums);
        vector<int> expected = {1,2,3,0,0,0};
        printTestResult(input, nums, expected, "Test Case 8: Alternating Pattern");
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The two-pointer technique maintains relative order (stable algorithm)
 * ! - Swap operation is key: it naturally pushes zeros backward while pulling non-zeros forward
 * * - zeroIndex boundary ensures all elements before it are non-zero
 * ? - After processing, array has structure: [non-zero elements | zero elements]
 * * - Works efficiently for all edge cases: no zeros, all zeros, single element
 * ================================================================================
 */
