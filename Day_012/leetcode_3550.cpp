/**
 * ================================================================================
 * LeetCode 3550: Smallest Index With Digit Sum Equal to Index
 * ================================================================================
 * 
 * ! Problem: Given an integer array `nums`, return the smallest index `i` 
 * ! such that the sum of the digits of `nums[i]` is equal to `i`.
 * ! If no such index exists, return -1.
 * 
 * * Approach:
 * * 1. Iterate through the array from left to right (ensures smallest index)
 * * 2. For each element at index i:
 * *    - Extract each digit using modulo 10
 * *    - Calculate the sum of all digits
 * *    - Check if digit sum equals the current index
 * * 3. Return the first matching index, or -1 if none found
 * 
 * ? Time Complexity: O(n × d) - Where n is array length, d is average digit count
 * ? Space Complexity: O(1) - Constant extra space used
 * 
 * TODO Key Insight: 
 * *    - The challenge is efficiently computing digit sums for each element
 * *    - We use modulo and division to extract digits without string conversion
 * *    - Left-to-right traversal guarantees we find the smallest matching index
 * 
 * * Optimizations: 
 * *    - Single pass through the array
 * *    - Early termination when match is found
 * *    - In-place digit extraction without extra memory
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 using namespace std;
 
 class Solution {
 public:
     /**
      * Finds the smallest index where digit sum of nums[i] equals i
      * @param nums The input integer array
      * @return The smallest matching index, or -1 if none exists
      */
     int smallestIndex(vector<int>& nums) {
         // * Iterate through each index to find the first match
         for(int i = 0; i < nums.size(); i++){
             int temp = nums[i];  // * Store current element for digit extraction
             int sum = 0;         // * Accumulator for digit sum
             
             // ! Calculate the sum of all digits in nums[i]
             // ? This loop extracts digits from right to left
             while(temp != 0){
                 sum += temp % 10;  // * Add the last digit to sum
                 temp /= 10;        // * Remove the last digit
             }
             
             // * Check if digit sum equals current index
             // ? First match is automatically the smallest due to left-to-right order
             if(i == sum) return i;
         }
         
         // ! No matching index found
         return -1;
     }
 };
 
 // ============================================================
 // * TESTING SUITE - Verifies solution with various test cases
 // ============================================================
 
 /**
  * Helper function to print test result
  */
 void printTestResult(vector<int> nums, int result, int expected) {
     cout << "\nTest: nums = [";
     for(int i = 0; i < nums.size(); i++) {
         cout << nums[i];
         if(i < nums.size() - 1) cout << ", ";
     }
     cout << "]\n";
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
     
     // * Test Case 1: Basic example with match at index 2
     {
         vector<int> nums = {1, 3, 2};
         int result = solution.smallestIndex(nums);
         printTestResult(nums, result, 2);
     }
     
     // * Test Case 2: Match at index 0
     {
         vector<int> nums = {0, 1, 2};
         int result = solution.smallestIndex(nums);
         printTestResult(nums, result, 0);
     }
     
     // * Test Case 3: No match exists
     {
         vector<int> nums = {10, 20, 30};
         int result = solution.smallestIndex(nums);
         printTestResult(nums, result, -1);
     }
     
     // * Test Case 4: Two-digit match
     {
         vector<int> nums = {10, 20, 11, 15};
         int result = solution.smallestIndex(nums);
         printTestResult(nums, result, 2);
     }
     
     // ! Test Case 5: Large numbers with no match
     {
         vector<int> nums = {99, 101, 95, 102};
         int result = solution.smallestIndex(nums);
         printTestResult(nums, result, -1);
     }
     
     // * Test Case 6: Single element matching
     {
         vector<int> nums = {0};
         int result = solution.smallestIndex(nums);
         printTestResult(nums, result, 0);
     }
     
     // * Test Case 7: Single element not matching
     {
         vector<int> nums = {5};
         int result = solution.smallestIndex(nums);
         printTestResult(nums, result, -1);
     }
     
     // * Test Case 8: Multiple potential matches
     {
         vector<int> nums = {0, 10, 11, 12};
         int result = solution.smallestIndex(nums);
         printTestResult(nums, result, 0);
     }
     
     return 0;
 }
 
 /*
  * ================================================================================
  * TODO Additional Notes:
  * * - The solution handles all integer values including zero
  * ! - The digit sum calculation works for positive integers as per problem constraints
  * * - The algorithm finds the smallest (leftmost) matching index automatically
  * ? - For negative numbers, additional handling would be needed (problem assumes positive)
  * ================================================================================
  */