/**
 * ================================================================================
 * 🌀 LeetCode 169: Majority Element - Boyer-Moore Voting Algorithm
 * ================================================================================
 * 
 * 🎯 Problem: Given an array `nums` of size `n`, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * 
 * 📝 Approach: Boyer-Moore Voting Algorithm
 * 1. Initialize a counter and a candidate variable
 * 2. Iterate through the array:
 *    - If counter is 0, set current element as candidate
 *    - If current element equals candidate, increment counter
 *    - Otherwise, decrement counter
 * 3. The candidate at the end is guaranteed to be the majority element
 * 
 * ⚡ Time Complexity: O(n) - Single pass through the array
 * 💾 Space Complexity: O(1) - Constant extra space used
 * 
 * 🧠 Key Insight: 
 *    - The majority element will always survive the cancellation with other elements
 *    - The algorithm works because the majority element appears more than n/2 times
 * 
 * 🚀 Optimizations: 
 *    - Single pass solution with O(1) space
 *    - No hash maps or sorting required
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 #include <unordered_map>
 using namespace std;
 
 class Solution {
 public:
     //! MAIN FUNCTION: Finds the majority element in the array
     //! @param nums The input array of integers
     //! @return The majority element (appears more than n/2 times)
     int majorityElement(vector<int>& nums) {
         int count = 0;    // * Counter for the current candidate
         int candidate = 0; // * Current candidate for majority element
 
         //* First pass: Find a candidate for majority element
         for (int num : nums) {
             //? If count is zero, we pick a new candidate
             if (count == 0) {
                 candidate = num;
             }
             
             //* Update count based on whether current element matches candidate
             count += (num == candidate) ? 1 : -1;
         }
 
         //! Note: Problem guarantees a majority element exists, so we don't need verification
         //! For a more general solution, we would add a second pass to verify
         
         return candidate;
     }
     
     //! ALTERNATIVE: Using hash map (for comparison)
     //! Time: O(n), Space: O(n)
     int majorityElementHash(vector<int>& nums) {
         unordered_map<int, int> freq;
         int n = nums.size();
         
         for (int num : nums) {
             if (++freq[num] > n/2) {
                 return num;
             }
         }
         
         return -1; // Shouldn't reach here per problem statement
     }
 };
 
 // ============================================================
 // 🧪 TESTING SUITE - Verifies solution with various test cases
 // ============================================================
 
 //! Helper function to print test results
 void printTestResult(const string& testName, const vector<int>& nums, int result, int expected) {
     cout << "\n🔍 " << testName << "\n";
     cout << "   Input:    [";
     for (size_t i = 0; i < nums.size(); i++) {
         cout << nums[i];
         if (i != nums.size() - 1) cout << ", ";
     }
     cout << "]\n";
     cout << "   Result:   " << result << "\n";
     cout << "   Expected: " << expected << "\n";
     cout << "   Status:   " << (result == expected ? "✅ PASS" : "❌ FAIL") << "\n";
 }
 
 int main() {
     Solution solution;
     
     // Test Case 1: Example from problem statement (odd length)
     {
         vector<int> nums = {3, 2, 3};
         int result = solution.majorityElement(nums);
         printTestResult("Test Case 1: Small Array", nums, result, 3);
     }
     
     // Test Case 2: Example from problem statement (even length)
     {
         vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
         int result = solution.majorityElement(nums);
         printTestResult("Test Case 2: Larger Array", nums, result, 2);
     }
     
     // Test Case 3: Single element array
     {
         vector<int> nums = {5};
         int result = solution.majorityElement(nums);
         printTestResult("Test Case 3: Single Element", nums, result, 5);
     }
     
     // Test Case 4: All elements the same
     {
         vector<int> nums = {4, 4, 4, 4};
         int result = solution.majorityElement(nums);
         printTestResult("Test Case 4: All Same Elements", nums, result, 4);
     }
     
     // Test Case 5: Large array
     {
         vector<int> nums(10000, 7);
         nums[9999] = 8;  // Only one different element
         int result = solution.majorityElement(nums);
         printTestResult("Test Case 5: Large Array", vector<int>{7, 7, 7, 8}, result, 7);
     }
     
     // Test Case 6: Negative numbers
     {
         vector<int> nums = {-1, -1, -1, 2, 3, -1, -1};
         int result = solution.majorityElement(nums);
         printTestResult("Test Case 6: Negative Numbers", nums, result, -1);
     }
     
     return 0;
 }
 
 /*
  * ================================================================================
  * 📝 Additional Notes:
  * - The Boyer-Moore Voting Algorithm is optimal for this problem with O(n) time and O(1) space
  * - The problem guarantees a majority element exists, so we don't need verification
  * - For a more general case where majority element might not exist, a second pass is needed
  * - Alternative approaches include sorting (O(n log n) time) or hash map (O(n) time and space)
  * ================================================================================
  */
 