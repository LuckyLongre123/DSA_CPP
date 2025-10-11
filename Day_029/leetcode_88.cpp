/**
 * ================================================================================
 * LeetCode 88: Merge Sorted Array - Three-Pointer Merge Technique
 * ================================================================================
 * 
 * ! Problem: Given two integer arrays `nums1` and `nums2` sorted in non-decreasing
 * ! order, and integers `m` and `n` representing their respective element counts,
 * ! merge `nums2` into `nums1` as one sorted array. nums1 has length m+n with
 * ! extra space at the end to accommodate nums2.
 * 
 * * Approach:
 * * 1. Create temporary copy of first m elements of nums1
 * * 2. Use three pointers:
 * *    - i: tracks position in temp (original nums1 elements)
 * *    - j: tracks position in nums2
 * *    - k: tracks position in nums1 to place next element
 * * 3. Compare temp[i] and nums2[j], place smaller in nums1[k]
 * * 4. Copy remaining elements from temp or nums2 (if any exist)
 * 
 * ? Time Complexity: O(m + n) - Each element processed exactly once
 * ? Space Complexity: O(m) - Temporary array stores original nums1 elements
 * 
 * TODO Key Insight: 
 * *    - Temporary copy prevents overwriting unprocessed nums1 elements
 * *    - Three-pointer technique efficiently merges two sorted arrays
 * *    - Similar to merge step in merge sort algorithm
 * 
 * * Optimizations: 
 * *    - Single pass through both arrays
 * *    - Linear time complexity is optimal for merging
 * *    - Alternative: merge from back to front (O(1) space, but more complex)
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 using namespace std;
 
 class Solution {
 public:
     /**
      * Merges two sorted arrays into one sorted array in-place
      * @param nums1 First sorted array with extra space (size m+n)
      * @param m Number of initialized elements in nums1
      * @param nums2 Second sorted array
      * @param n Number of elements in nums2
      */
     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         // * Create temporary copy of nums1's valid elements [0, m)
         vector<int> temp(nums1.begin(), nums1.begin() + m);
         
         // * Initialize three pointers
         int i = 0;  // * Pointer for temp array (original nums1)
         int j = 0;  // * Pointer for nums2
         int k = 0;  // * Pointer for position in nums1 to write next element
         
         // ============================================================
         // ! PHASE 1: Merge elements from both arrays
         // ============================================================
         // * Compare and place smaller element until one array exhausted
         while (i < m && j < n) {
             // ? Check which element is smaller
             if(temp[i] < nums2[j]) {
                 nums1[k++] = temp[i++];  // * Take element from temp (nums1)
             } else {
                 nums1[k++] = nums2[j++]; // * Take element from nums2
             }
             // ! nums1[0...k-1] now contains k smallest elements in sorted order
         }
         
         // ============================================================
         // ! PHASE 2: Copy remaining elements (only one will execute)
         // ============================================================
         
         // * Copy remaining elements from temp (if nums2 exhausted first)
         while(i < m) {
             nums1[k++] = temp[i++];
         }
         
         // * Copy remaining elements from nums2 (if temp exhausted first)
         while(j < n) {
             nums1[k++] = nums2[j++];
         }
         
         // * After both phases: nums1 contains all m+n elements in sorted order
     }
 };

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(vector<int>& result, vector<int>& expected, string testName) {
    cout << "\n" << testName << "\n";
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
    
    // * Test Case 1: Both arrays have elements
    {
        vector<int> nums1 = {1,2,3,0,0,0};
        vector<int> nums2 = {2,5,6};
        solution.merge(nums1, 3, nums2, 3);
        vector<int> expected = {1,2,2,3,5,6};
        printTestResult(nums1, expected, "Test Case 1: Standard Merge");
    }
    
    // * Test Case 2: Second array is empty
    {
        vector<int> nums1 = {1};
        vector<int> nums2 = {};
        solution.merge(nums1, 1, nums2, 0);
        vector<int> expected = {1};
        printTestResult(nums1, expected, "Test Case 2: Empty nums2");
    }
    
    // * Test Case 3: First array is empty
    {
        vector<int> nums1 = {0};
        vector<int> nums2 = {1};
        solution.merge(nums1, 0, nums2, 1);
        vector<int> expected = {1};
        printTestResult(nums1, expected, "Test Case 3: Empty nums1");
    }
    
    // * Test Case 4: All nums2 elements smaller
    {
        vector<int> nums1 = {4,5,6,0,0,0};
        vector<int> nums2 = {1,2,3};
        solution.merge(nums1, 3, nums2, 3);
        vector<int> expected = {1,2,3,4,5,6};
        printTestResult(nums1, expected, "Test Case 4: nums2 All Smaller");
    }
    
    // ! Test Case 5: All nums2 elements larger
    {
        vector<int> nums1 = {1,2,3,0,0,0};
        vector<int> nums2 = {4,5,6};
        solution.merge(nums1, 3, nums2, 3);
        vector<int> expected = {1,2,3,4,5,6};
        printTestResult(nums1, expected, "Test Case 5: nums2 All Larger");
    }
    
    // * Test Case 6: Interleaved elements
    {
        vector<int> nums1 = {1,3,5,0,0,0};
        vector<int> nums2 = {2,4,6};
        solution.merge(nums1, 3, nums2, 3);
        vector<int> expected = {1,2,3,4,5,6};
        printTestResult(nums1, expected, "Test Case 6: Interleaved");
    }
    
    // * Test Case 7: Duplicate elements
    {
        vector<int> nums1 = {1,2,2,0,0,0};
        vector<int> nums2 = {2,2,3};
        solution.merge(nums1, 3, nums2, 3);
        vector<int> expected = {1,2,2,2,2,3};
        printTestResult(nums1, expected, "Test Case 7: Duplicates");
    }
    
    // * Test Case 8: Single elements each
    {
        vector<int> nums1 = {2,0};
        vector<int> nums2 = {1};
        solution.merge(nums1, 1, nums2, 1);
        vector<int> expected = {1,2};
        printTestResult(nums1, expected, "Test Case 8: Single Elements");
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - Temporary array approach is intuitive and easy to understand
 * ! - Three-pointer technique is fundamental in merge operations (used in merge sort)
 * * - Time complexity O(m+n) is optimal for merging two sorted arrays
 * ? - Space can be optimized to O(1) by merging from back to front (advanced technique)
 * * - The algorithm handles all edge cases: empty arrays, duplicates, different sizes
 * ================================================================================
 */
