/**
 * ================================================================================
 * LeetCode 796: Rotate String - String Manipulation
 * ================================================================================
 * 
 * ! Problem: Given two strings `s` and `goal`, return true if and only if `s` can 
 * ! become `goal` after some number of shifts on `s`. A shift on `s` consists of 
 * ! moving the leftmost character of `s` to the rightmost position.
 * 
 * * Approach:
 * * 1. Check if both strings have the same length (required for rotation)
 * * 2. Key insight: If goal is a rotation of s, then goal must be a substring of s+s
 * * 3. Concatenate s with itself to create all possible rotations
 * * 4. Check if goal exists as a substring in the concatenated string
 * * 5. Return true if found, false otherwise
 * 
 * ? Time Complexity: O(n) - where n is the length of string s (string search is O(n))
 * ? Space Complexity: O(n) - for creating the concatenated string s+s
 * 
 * TODO Key Insight: 
 * *    - When you concatenate s with itself (s+s), it contains all possible rotations of s
 * *    - For example: s = "abcde", s+s = "abcdeabcde" contains all rotations:
 * *      "abcde", "bcdea", "cdeab", "deabc", "eabcd"
 * *    - If goal is any rotation of s, it will appear as a contiguous substring in s+s
 * 
 * * Optimizations: 
 * *    - Single length check eliminates impossible cases immediately
 * *    - Using built-in string::find() is highly optimized (often uses KMP algorithm)
 * *    - Early termination if lengths don't match
 * ================================================================================
 */

 #include <iostream>
 #include <string>
 using namespace std;
 
 class Solution {
 public:
     /**
      * Checks if string s can become goal after some rotations
      * @param s The original string
      * @param goal The target string to check
      * @return true if goal is a rotation of s, false otherwise
      */
     bool rotateString(string s, string goal) {
         // ! Edge case: Strings must have same length to be rotations
         // ? If lengths differ, goal cannot be a rotation of s
         if (s.size() != goal.size()) {
             return false;
         }
         
         // * CORE ALGORITHM: Check if goal is substring of s+s
         // ? When we concatenate s with itself, all rotations appear as substrings
         // * Example: s = "abcde" → s+s = "abcdeabcde"
         // *          goal = "cdeab" → exists in "abcdeabcde" starting at index 2
         string doubled = s + s;
         
         // * Use built-in find() to check if goal appears in doubled string
         // ? find() returns string::npos if goal is not found
         return doubled.find(goal) != string::npos;
     }
 };
 
 // ============================================================
 // * TESTING SUITE - Verifies solution with various test cases
 // ============================================================
 
 /**
  * Helper function to print test result
  */
 void printTestResult(const string& s, const string& goal, bool result, bool expected) {
     cout << "\ns = \"" << s << "\", goal = \"" << goal << "\"\n";
     cout << "   Result:   " << (result ? "true" : "false") << "\n";
     cout << "   Expected: " << (expected ? "true" : "false") << "\n";
     cout << "   Status:   " << (result == expected ? "PASS" : "FAIL");
     if (result != expected) {
         cout << " (Expected: " << (expected ? "true" : "false") << ")";
     }
     cout << "\n";
 }
 
 int main() {
     Solution solution;
     
     // * Test Case 1: Basic rotation - left shift by 2
     {
         string s = "abcde";
         string goal = "cdeab";
         bool result = solution.rotateString(s, goal);
         printTestResult(s, goal, result, true);
     }
     
     // * Test Case 2: No rotation possible
     {
         string s = "abcde";
         string goal = "abced";
         bool result = solution.rotateString(s, goal);
         printTestResult(s, goal, result, false);
     }
     
     // * Test Case 3: Single character - always rotates to itself
     {
         string s = "a";
         string goal = "a";
         bool result = solution.rotateString(s, goal);
         printTestResult(s, goal, result, true);
     }
     
     // * Test Case 4: Different lengths - impossible rotation
     {
         string s = "abc";
         string goal = "abcd";
         bool result = solution.rotateString(s, goal);
         printTestResult(s, goal, result, false);
     }
     
     // * Test Case 5: Empty strings - edge case
     {
         string s = "";
         string goal = "";
         bool result = solution.rotateString(s, goal);
         printTestResult(s, goal, result, true);
     }
     
     // * Test Case 6: Same string - zero rotation
     {
         string s = "hello";
         string goal = "hello";
         bool result = solution.rotateString(s, goal);
         printTestResult(s, goal, result, true);
     }
     
     // * Test Case 7: Repeated characters
     {
         string s = "aa";
         string goal = "aa";
         bool result = solution.rotateString(s, goal);
         printTestResult(s, goal, result, true);
     }
     
     // * Test Case 8: Long rotation
     {
         string s = "abcdefgh";
         string goal = "fghabcde";
         bool result = solution.rotateString(s, goal);
         printTestResult(s, goal, result, true);
     }
     
     return 0;
 }
 
 /*
  * ================================================================================
  * TODO Additional Notes:
  * * - The solution elegantly handles all edge cases including empty strings
  * ! - The concatenation trick (s+s) is a clever way to check all rotations at once
  * * - Alternative approach: manually rotate and check each position (O(n²) time)
  * ? - The string::find() method often uses optimized algorithms like KMP or Boyer-Moore
  * * - This approach is more efficient than manually checking each rotation
  * ================================================================================
  */