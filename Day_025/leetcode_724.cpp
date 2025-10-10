/**
 * ================================================================================
 * LeetCode 724: Find Pivot Index - Array Prefix Sum Technique
 * ================================================================================
 * 
 * ! Problem: Given an array of integers `nums`, calculate the pivot index of this array.
 * ! The pivot index is the index where the sum of all numbers strictly to the left
 * ! of the index is equal to the sum of all numbers strictly to the right of the index.
 * ! If no such index exists, return -1. If there are multiple pivot indexes, return
 * ! the left-most pivot index.
 * 
 * * Approach:
 * * 1. Calculate the total sum to the right of index 0 (all elements except first)
 * * 2. Initialize left sum (prefix sum) as 0
 * * 3. For each index from left to right:
 * *    - Check if left sum equals right sum (found pivot!)
 * *    - Update left sum by adding current element
 * *    - Update right sum by removing next element
 * * 4. Return the pivot index, or -1 if not found
 * 
 * ? Time Complexity: O(n) - Two passes through the array (one for right sum, one for finding pivot)
 * ? Space Complexity: O(1) - Constant extra space used
 * 
 * TODO Key Insight: 
 * *    - The main idea is to maintain a running prefix sum from the left
 * *    - And a running suffix sum from the right
 * *    - When they become equal, we've found the pivot index
 * *    - This avoids recalculating sums for each index (which would be O(n²))
 * 
 * * Optimizations: 
 * *    - Single pass for right sum calculation
 * *    - Single pass for pivot finding
 * *    - No extra arrays needed (unlike traditional prefix sum arrays)
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 using namespace std;
 
 class Solution {
 public:
     /**
      * Finds the pivot index where left sum equals right sum
      * @param nums The input array of integers
      * @return The left-most pivot index, or -1 if no pivot exists
      */
     int pivotIndex(vector<int>& nums) {
         int aftersum = 0;  // * Stores the sum of elements to the right of current index
         int presum = 0;    // * Stores the sum of elements to the left of current index
         
         // ! Calculate initial right sum (sum of all elements except index 0)
         // ? This gives us the sum to the right when we start at index 0
         for (int i = 1; i < nums.size(); i++) {
             aftersum += nums[i];
         }
         
         // * Iterate through each index to find the pivot
         for (int j = 0; j < nums.size(); j++) {
             // ! Check if current index is the pivot
             // ? If left sum equals right sum, we found it!
             if (presum == aftersum) {
                 return j;  // * Return the pivot index
             }
             
             // * Update prefix sum by adding current element
             // ? After this, presum represents sum of elements to the left of next index
             presum += nums[j];
             
             // ! Handle the right sum update
             // ? If we're at the last element, right sum becomes 0
             if (j + 1 > nums.size() - 1) {
                 aftersum = 0;
                 continue;
             }
             
             // * Update suffix sum by removing the next element
             // ? This maintains aftersum as the sum to the right of next index
             aftersum -= nums[j + 1];
         }
         
         // ! No pivot found
         return -1;
     }
 };
 
 // ============================================================
 // * TESTING SUITE - Verifies solution with various test cases
 // ============================================================
 
 /**
  * Helper function to print array
  */
 void printArray(const vector<int>& nums) {
     cout << "[";
     for (int i = 0; i < nums.size(); i++) {
         cout << nums[i];
         if (i < nums.size() - 1) cout << ", ";
     }
     cout << "]";
 }
 
 /**
  * Helper function to print test result
  */
 void printTestResult(vector<int>& nums, int result, int expected) {
     cout << "\nInput:    ";
     printArray(nums);
     cout << "\nResult:   " << result << "\n";
     cout << "Expected: " << expected << "\n";
     cout << "Status:   " << (result == expected ? "PASS" : "FAIL");
     if (result != expected) {
         cout << " (Expected: " << expected << ")";
     }
     cout << "\n";
 }
 
 int main() {
     Solution solution;
     
     // * Test Case 1: Pivot in middle
     {
         vector<int> nums = {1, 7, 3, 6, 5, 6};
         int result = solution.pivotIndex(nums);
         printTestResult(nums, result, 3);
     }
     
     // * Test Case 2: No pivot exists
     {
         vector<int> nums = {1, 2, 3};
         int result = solution.pivotIndex(nums);
         printTestResult(nums, result, -1);
     }
     
     // * Test Case 3: Pivot at first index
     {
         vector<int> nums = {2, 1, -1};
         int result = solution.pivotIndex(nums);
         printTestResult(nums, result, 0);
     }
     
     // * Test Case 4: Single element (always pivot)
     {
         vector<int> nums = {5};
         int result = solution.pivotIndex(nums);
         printTestResult(nums, result, 0);
     }
     
     // * Test Case 5: Two elements, no pivot
     {
         vector<int> nums = {1, 2};
         int result = solution.pivotIndex(nums);
         printTestResult(nums, result, -1);
     }
     
     // ! Test Case 6: All zeros
     {
         vector<int> nums = {0, 0, 0, 0, 0};
         int result = solution.pivotIndex(nums);
         printTestResult(nums, result, 0);
     }
     
     // * Test Case 7: Negative numbers
     {
         vector<int> nums = {-1, -1, -1, -1, -1, 0};
         int result = solution.pivotIndex(nums);
         printTestResult(nums, result, 2);
     }
     
     // * Test Case 8: Pivot at last index
     {
         vector<int> nums = {1, 1, 0};
         int result = solution.pivotIndex(nums);
         printTestResult(nums, result, 2);
     }
     
     // ! Test Case 9: Large array with pivot
     {
         vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
         int result = solution.pivotIndex(nums);
         printTestResult(nums, result, -1);
     }
     
     // * Test Case 10: Multiple valid pivots (return leftmost)
     {
         vector<int> nums = {0, 0, 0};
         int result = solution.pivotIndex(nums);
         printTestResult(nums, result, 0);
     }
     
     return 0;
 }
 
 /*
  * ================================================================================
  * TODO Additional Notes:
  * * - The solution efficiently finds the pivot in O(n) time with O(1) space
  * ! - Edge cases handled: single element, all zeros, negative numbers, no pivot
  * * - The algorithm avoids nested loops by maintaining running sums
  * ? - For empty arrays (not in problem constraints), would need additional check
  * * - The leftmost pivot is naturally returned due to left-to-right iteration
  * ================================================================================
  */
 