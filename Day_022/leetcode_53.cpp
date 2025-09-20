/**
 * ================================================================================
 * 🌀 LeetCode 53: Maximum Subarray - Kadane's Algorithm
 * ================================================================================
 * 
 * 🎯 Problem:
 *   Given an integer array nums, find the contiguous subarray (containing at 
 *   least one number) which has the largest sum and return its sum.
 * 
 * 📝 Approach: Kadane’s Algorithm
 * 1. Keep a running sum (`currSum`) as we iterate
 * 2. If `currSum` becomes negative → reset to 0 (since negatives reduce future sums)
 * 3. Track `maxSum` as the maximum seen so far
 * 4. Answer is `maxSum` after processing all elements
 * 
 * ⚡ Time Complexity: O(n) - Single pass through array
 * 💾 Space Complexity: O(1) - Only a few variables used
 * 
 * 🧠 Key Insight:
 *   - A negative running sum can’t help in building a max subarray → reset it
 *   - Guarantees best subarray is always captured in `maxSum`
 * 
 * 🚀 Optimizations:
 *   - Kadane’s algorithm is the most optimal O(n) solution
 *   - Brute force O(n^2) or prefix sums are slower
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 #include <climits>
 #include <algorithm>
 using namespace std;
 
 class Solution {
 public:
     //! MAIN FUNCTION: Finds maximum subarray sum
     //! @param nums Input array of integers
     //! @return Maximum sum of a contiguous subarray
     int maxSubArray(vector<int>& nums) {
         int currSum = 0;        // * Current running sum
         int maxSum = INT_MIN;   // * Initialize with very small value
 
         //? Kadane’s Algorithm
         for (int val : nums) {
             currSum += val;                   // + Add current element
             maxSum = max(maxSum, currSum);    // ? Update max sum if better
 
             // ! If running sum is negative → reset
             if (currSum < 0) currSum = 0;
         }
 
         //! Final maximum subarray sum
         return maxSum;
     }
 };
 
 // ============================================================
 // 🧪 TESTING SUITE - Verifies solution with sample test cases
 // ============================================================
 
 void printTestResult(const vector<int>& nums, int result, int expected) {
     cout << "\n🔍 Input: nums = [";
     for (size_t i = 0; i < nums.size(); i++) {
         cout << nums[i];
         if (i != nums.size() - 1) cout << ", ";
     }
     cout << "]\n";
 
     cout << "   Output:   " << result << "\n";
     cout << "   Expected: " << expected << "\n";
     cout << "   Status:   " << (result == expected ? "✅ PASS" : "❌ FAIL");
     if (result != expected) {
         cout << " (Expected: " << expected << ")";
     }
     cout << "\n";
 }
 
 int main() {
     Solution obj;
 
     // Test Case 1
     {
         vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
         int result = obj.maxSubArray(nums);
         printTestResult(nums, result, 6);
     }
 
     // Test Case 2
     {
         vector<int> nums = {1};
         int result = obj.maxSubArray(nums);
         printTestResult(nums, result, 1);
     }
 
     // Test Case 3
     {
         vector<int> nums = {5,4,-1,7,8};
         int result = obj.maxSubArray(nums);
         printTestResult(nums, result, 23);
     }
 
     // Test Case 4: All negatives
     {
         vector<int> nums = {-5,-2,-3,-7};
         int result = obj.maxSubArray(nums);
         printTestResult(nums, result, -2);
     }
 
     return 0;
 }
 
 /*
  * ================================================================================
  * 📝 Additional Notes:
  * - Works even when all numbers are negative → best subarray is the least negative
  * - Brute force O(n^2) (check all subarrays) is too slow for n=10^5
  * - Kadane’s algorithm is the optimal O(n) solution
  * ================================================================================
  */
 