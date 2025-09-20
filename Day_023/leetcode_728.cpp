/**
 * ================================================================================
 * 🌀 LeetCode 728: Self Dividing Numbers
 * ================================================================================
 * 
 * 🎯 Problem:
 *   A self-dividing number is a number divisible by every digit it contains.
 *   - Example: 128 is self-dividing because 128 % 1 == 0, 128 % 2 == 0, 128 % 8 == 0
 *   - A self-dividing number cannot contain the digit zero.
 * 
 *   Given two integers left and right, return all self-dividing numbers in [left, right].
 * 
 * 📝 Approach:
 * 1. Iterate through all numbers from left → right
 * 2. For each number:
 *    - Extract digits one by one
 *    - If any digit is 0 → invalid
 *    - If number is not divisible by digit → invalid
 *    - Otherwise → valid (self-dividing)
 * 3. Collect all valid numbers into result
 * 
 * ⚡ Time Complexity: O((right - left + 1) * log10(max_number))  
 * 💾 Space Complexity: O(1) (excluding result storage)
 * 
 * 🧠 Key Insight:
 *   - Simple digit check for each number
 *   - Works efficiently even for range up to 10^4
 * 
 * 🚀 Optimizations:
 *   - Early exit if digit=0
 *   - No extra space used beyond result vector
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 using namespace std;
 
 class Solution {
 public:
     //! HELPER: Checks if a number is self-dividing
     //! @param num The number to check
     //! @return true if self-dividing, false otherwise
     bool isSelfDividing(int num) {
         int temp = num;
         while (temp > 0) {
             int digit = temp % 10;   // * Extract rightmost digit
             if (digit == 0 || num % digit != 0) {
                 return false;        // ! Not self-dividing
             }
             temp /= 10;              // * Remove last digit
         }
         return true;                 // ✅ Passed all checks
     }
 
     //! MAIN FUNCTION: Finds all self-dividing numbers in range
     //! @param left Lower bound of range
     //! @param right Upper bound of range
     //! @return Vector of self-dividing numbers
     vector<int> selfDividingNumbers(int left, int right) {
         vector<int> result;
         for (int i = left; i <= right; i++) {
             if (isSelfDividing(i)) {    // ? Check number
                 result.push_back(i);    // + Add valid number
             }
         }
         return result;
     }
 };
 
 // ============================================================
 // 🧪 TESTING SUITE - Verifies solution with sample test cases
 // ============================================================
 
 void printTestResult(int left, int right, const vector<int>& result, const vector<int>& expected) {
     cout << "\n🔍 Input: left = " << left << ", right = " << right << "\n";
     
     cout << "   Output:   [";
     for (size_t i = 0; i < result.size(); i++) {
         cout << result[i] << (i + 1 < result.size() ? ", " : "");
     }
     cout << "]\n";
 
     cout << "   Expected: [";
     for (size_t i = 0; i < expected.size(); i++) {
         cout << expected[i] << (i + 1 < expected.size() ? ", " : "");
     }
     cout << "]\n";
 
     cout << "   Status:   " << (result == expected ? "✅ PASS" : "❌ FAIL");
     cout << "\n";
 }
 
 int main() {
     Solution obj;
 
     // Test Case 1
     {
         int left = 1, right = 22;
         vector<int> result = obj.selfDividingNumbers(left, right);
         vector<int> expected = {1,2,3,4,5,6,7,8,9,11,12,15,22};
         printTestResult(left, right, result, expected);
     }
 
     // Test Case 2
     {
         int left = 47, right = 85;
         vector<int> result = obj.selfDividingNumbers(left, right);
         vector<int> expected = {48,55,66,77};
         printTestResult(left, right, result, expected);
     }
 
     // Test Case 3: Single number range
     {
         int left = 128, right = 128;
         vector<int> result = obj.selfDividingNumbers(left, right);
         vector<int> expected = {128};
         printTestResult(left, right, result, expected);
     }
 
     return 0;
 }
 
 /*
  * ================================================================================
  * 📝 Additional Notes:
  * - Numbers containing 0 are automatically invalid
  * - Works fine up to 10^4 as per constraints
  * - Simple, clean, brute-force check (no complex optimization required)
  * ================================================================================
  */
 