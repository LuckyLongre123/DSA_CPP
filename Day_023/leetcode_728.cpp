/**
 * ================================================================================
 * LeetCode 728: Self Dividing Numbers - Number Manipulation
 * ================================================================================
 * 
 * ! Problem: A self-dividing number is a number that is divisible by every digit it contains.
 * ! For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
 * ! A self-dividing number is not allowed to contain the digit zero.
 * ! Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right].
 * 
 * * Approach:
 * * 1. Iterate through all numbers in the range [left, right]
 * * 2. For each number, extract its digits one by one
 * * 3. Check if the number is divisible by each digit
 * * 4. If any digit is 0 or the number is not divisible by it, skip the number
 * * 5. If all digits divide the number, add it to the result
 * 
 * ? Time Complexity: O((right - left) × log₁₀(right)) - For each number, we check all its digits
 * ? Space Complexity: O(1) - Constant extra space used (excluding output array)
 * 
 * TODO Key Insight: 
 * *    - The main challenge is extracting each digit and checking divisibility
 * *    - We must check for zero digits first to avoid division by zero
 * *    - Numbers with 0 are automatically excluded (cannot divide by 0)
 * 
 * * Optimizations: 
 * *    - Early termination when we find a digit that doesn't divide the number
 * *    - Single pass through each number's digits
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 using namespace std;
 
 class Solution {
 public:
     /**
      * Finds all self-dividing numbers in a given range
      * @param left The start of the range (inclusive)
      * @param right The end of the range (inclusive)
      * @return Vector containing all self-dividing numbers in [left, right]
      */
     vector<int> selfDividingNumbers(int left, int right) {
         vector<int> result;  // * Stores all self-dividing numbers found
         
         // * Iterate through all numbers in the range
         for (int i = left; i <= right; i++) {
             int num = i;  // * Create a copy to extract digits from
             bool isSelfDividing = true;  // * Assume number is self-dividing initially
             
             // * Extract and check each digit
             while (num > 0) {
                 int digit = num % 10;  // * Extract the last digit
                 
                 // ! Check for zero digit or non-divisibility
                 // ? If digit is 0, we cannot divide by it (invalid)
                 // ? If i is not divisible by digit, it's not self-dividing
                 if (digit == 0 || i % digit != 0) {
                     isSelfDividing = false;  // ! Not a self-dividing number
                     break;  // * Early termination - no need to check remaining digits
                 }
                 
                 // * Move to the next digit
                 num /= 10;
             }
             
             // * If all digits passed the test, add to result
             if (isSelfDividing) {
                 result.push_back(i);
             }
         }
         
         return result;
     }
 };
 
 // ============================================================
 // * TESTING SUITE - Verifies solution with various test cases
 // ============================================================
 
 /**
  * Helper function to print test result
  */
 void printTestResult(int left, int right, vector<int> result, vector<int> expected) {
     cout << "\nRange: [" << left << ", " << right << "]\n";
     cout << "   Result:   [";
     for (int i = 0; i < result.size(); i++) {
         cout << result[i];
         if (i < result.size() - 1) cout << ", ";
     }
     cout << "]\n";
     cout << "   Expected: [";
     for (int i = 0; i < expected.size(); i++) {
         cout << expected[i];
         if (i < expected.size() - 1) cout << ", ";
     }
     cout << "]\n";
     
     bool pass = result.size() == expected.size();
     if (pass) {
         for (int i = 0; i < result.size(); i++) {
             if (result[i] != expected[i]) {
                 pass = false;
                 break;
             }
         }
     }
     
     cout << "   Status:   " << (pass ? "PASS" : "FAIL") << "\n";
 }
 
 int main() {
     Solution solution;
     
     // * Test Case 1: Small range with multiple self-dividing numbers
     {
         int left = 1, right = 22;
         vector<int> result = solution.selfDividingNumbers(left, right);
         vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22};
         printTestResult(left, right, result, expected);
     }
     
     // * Test Case 2: Range with larger numbers
     {
         int left = 47, right = 85;
         vector<int> result = solution.selfDividingNumbers(left, right);
         vector<int> expected = {48, 55, 66, 77};
         printTestResult(left, right, result, expected);
     }
     
     // * Test Case 3: Single number range
     {
         int left = 128, right = 128;
         vector<int> result = solution.selfDividingNumbers(left, right);
         vector<int> expected = {128};
         printTestResult(left, right, result, expected);
     }
     
     // ! Test Case 4: Range with no self-dividing numbers
     {
         int left = 10, right = 10;
         vector<int> result = solution.selfDividingNumbers(left, right);
         vector<int> expected = {};
         printTestResult(left, right, result, expected);
     }
     
     // * Test Case 5: All single digits (all are self-dividing)
     {
         int left = 1, right = 9;
         vector<int> result = solution.selfDividingNumbers(left, right);
         vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
         printTestResult(left, right, result, expected);
     }
     
     // * Test Case 6: Range with zero-containing numbers (none should be included)
     {
         int left = 100, right = 110;
         vector<int> result = solution.selfDividingNumbers(left, right);
         vector<int> expected = {};
         printTestResult(left, right, result, expected);
     }
     
     // * Test Case 7: Larger range with various self-dividing numbers
     {
         int left = 1, right = 50;
         vector<int> result = solution.selfDividingNumbers(left, right);
         vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22, 24, 33, 36, 44, 48};
         printTestResult(left, right, result, expected);
     }
     
     // * Test Case 8: Testing numbers divisible by all digits
     {
         int left = 200, right = 220;
         vector<int> result = solution.selfDividingNumbers(left, right);
         vector<int> expected = {212};
         printTestResult(left, right, result, expected);
     }
     
     return 0;
 }
 
 /*
  * ================================================================================
  * TODO Additional Notes:
  * * - Single digit numbers (1-9) are always self-dividing
  * ! - Any number containing 0 cannot be self-dividing (division by zero is undefined)
  * * - The algorithm checks each digit independently using modulo operation
  * ? - For optimization, we could skip numbers containing 0 by checking first
  * * - The solution is straightforward but efficient for the given constraints
  * ================================================================================
  */