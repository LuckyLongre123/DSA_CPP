/**
 * ================================================================================
 * LeetCode 567: Permutation in String - Sliding Window Technique
 * ================================================================================
 * 
 * ! Problem: Given two strings s1 and s2, return true if s2 contains a 
 * ! permutation of s1, or false otherwise. In other words, return true if 
 * ! one of s1's permutations is the substring of s2.
 * 
 * * Approach:
 * * 1. Create frequency maps for s1 and first window of s2
 * * 2. If initial window matches, return true
 * * 3. Slide the window through s2:
 * *    - Add the new character entering the window
 * *    - Remove the old character leaving the window
 * *    - Check if current window matches s1's frequency
 * * 4. Return false if no match found
 * 
 * ? Time Complexity: O(n) - Single pass through s2 with constant time comparisons
 * ? Space Complexity: O(1) - Fixed size arrays (26 letters)
 * 
 * TODO Key Insight: 
 * *    - A permutation means same characters with same frequencies
 * *    - Sliding window maintains a constant-size frequency snapshot
 * *    - Comparing two frequency arrays determines if characters match
 * 
 * * Optimizations: 
 * *    - Single pass algorithm - no backtracking needed
 * *    - Fixed space usage regardless of string length
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 #include <string>
 using namespace std;
 
 class Solution {
 public:
     /**
      * Checks if s2 contains a permutation of s1
      * @param s1 The pattern string whose permutation we're looking for
      * @param s2 The text string to search within
      * @return true if s2 contains any permutation of s1, false otherwise
      */
     bool checkInclusion(string s1, string s2) {
         int len1 = s1.size();  // * Length of pattern string
         int len2 = s2.size();  // * Length of text string
         
         // ! Early termination: pattern can't fit in text
         if (len1 > len2) {
             return false;
         }
         
         // * Create frequency maps for both strings
         // ? CharArr: stores character frequencies of s1 (target pattern)
         // ? window: stores character frequencies of current window in s2
         vector<int> CharArr(26, 0);  // * Frequency map for s1
         vector<int> window(26, 0);   // * Frequency map for sliding window
         
         // * Build initial frequency maps
         // ? Process first 'len1' characters of both strings
         for (int i = 0; i < len1; ++i) {
             CharArr[s1[i] - 'a']++;   // * Count characters in s1
             window[s2[i] - 'a']++;    // * Count characters in first window of s2
         }
         
         // ! Check if initial window is already a permutation
         if (CharArr == window) {
             return true;
         }
         
         // * Slide the window through remaining characters of s2
         // ? Start from position len1 and move one character at a time
         for (int i = len1; i < len2; ++i) {
             // * Add new character entering the window
             window[s2[i] - 'a']++;
             
             // * Remove old character leaving the window
             window[s2[i - len1] - 'a']--;
             
             // ! Check if current window matches s1's frequency
             if (CharArr == window) {
                 return true;  // ! Found a permutation
             }
         }
         
         // * No permutation found in any window
         return false;
     }
 };
 
 // ============================================================
 // * TESTING SUITE - Verifies solution with various test cases
 // ============================================================
 
 /**
  * Helper function to print test result
  */
 void printTestResult(string s1, string s2, bool result, bool expected) {
     cout << "\ns1 = \"" << s1 << "\", s2 = \"" << s2 << "\"\n";
     cout << "   Result:   " << (result ? "true" : "false") << "\n";
     cout << "   Expected: " << (expected ? "true" : "false") << "\n";
     cout << "   Status:   " << (result == expected ? "✓ PASS" : "✗ FAIL") << "\n";
 }
 
 int main() {
     Solution solution;
     
     // * Test Case 1: Basic permutation found
     {
         string s1 = "ab";
         string s2 = "eidbaooo";
         bool result = solution.checkInclusion(s1, s2);
         printTestResult(s1, s2, result, true);
         // ? "ba" is a permutation of "ab" and exists in s2
     }
     
     // * Test Case 2: No permutation exists
     {
         string s1 = "ab";
         string s2 = "eidboaoo";
         bool result = solution.checkInclusion(s1, s2);
         printTestResult(s1, s2, result, false);
         // ? No substring in s2 contains both 'a' and 'b' together
     }
     
     // * Test Case 3: Entire string is a permutation
     {
         string s1 = "abc";
         string s2 = "bca";
         bool result = solution.checkInclusion(s1, s2);
         printTestResult(s1, s2, result, true);
         // ? "bca" is a permutation of "abc"
     }
     
     // * Test Case 4: Single character match
     {
         string s1 = "a";
         string s2 = "a";
         bool result = solution.checkInclusion(s1, s2);
         printTestResult(s1, s2, result, true);
     }
     
     // ! Test Case 5: Pattern longer than text
     {
         string s1 = "hello";
         string s2 = "hi";
         bool result = solution.checkInclusion(s1, s2);
         printTestResult(s1, s2, result, false);
         // ? Impossible when pattern is longer than text
     }
     
     // * Test Case 6: Repeated characters
     {
         string s1 = "adc";
         string s2 = "dcda";
         bool result = solution.checkInclusion(s1, s2);
         printTestResult(s1, s2, result, true);
         // ? "dcd" contains 'd' twice, "cda" is permutation of "adc"
     }
     
     // * Test Case 7: No match with similar characters
     {
         string s1 = "aab";
         string s2 = "aabbbaa";
         bool result = solution.checkInclusion(s1, s2);
         printTestResult(s1, s2, result, true);
         // ? Multiple valid windows: "aab", "abb", "bba", "baa"
     }
     
     // * Test Case 8: Large input
     {
         string s1 = "abcd";
         string s2 = "xyzabcdqwerty";
         bool result = solution.checkInclusion(s1, s2);
         printTestResult(s1, s2, result, true);
         // ? "abcd" appears exactly in s2
     }
     
     // ! Test Case 9: All same characters
     {
         string s1 = "aaa";
         string s2 = "aaaaaaa";
         bool result = solution.checkInclusion(s1, s2);
         printTestResult(s1, s2, result, true);
         // ? Any window of length 3 in s2 matches s1
     }
     
     // * Test Case 10: No overlap
     {
         string s1 = "xyz";
         string s2 = "abcdef";
         bool result = solution.checkInclusion(s1, s2);
         printTestResult(s1, s2, result, false);
         // ? No characters from s1 exist in s2
     }
     
     return 0;
 }
 
 /*
  * ================================================================================
  * TODO Additional Notes:
  * * - The sliding window technique is optimal for substring pattern matching
  * ! - Character frequency comparison is O(26) = O(1) for lowercase English letters
  * * - The algorithm handles edge cases like empty strings and single characters
  * ? - For larger character sets (Unicode), space complexity would be O(charset_size)
  * * - Alternative approach: Use a single counter to track matching characters
  * ================================================================================
  */