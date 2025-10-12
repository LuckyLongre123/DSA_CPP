/**
 * ================================================================================
 * LeetCode 443: String Compression - In-Place Array Manipulation
 * ================================================================================
 * 
 * ! Problem: Given an array of characters `chars`, compress it using the following 
 * ! algorithm. Begin with an empty string `s`. For each group of consecutive 
 * ! repeating characters in `chars`:
 * ! - If the group's length is 1, append the character to `s`.
 * ! - Otherwise, append the character followed by the group's length.
 * ! The compressed string `s` should not be returned separately, but instead be 
 * ! stored in the input character array `chars`. Return the new length of the array.
 * ! You must write an algorithm that uses only constant extra space.
 * 
 * * Approach:
 * * 1. Use two pointers: read (scan array) and write (position to write)
 * * 2. For each character, count consecutive occurrences
 * * 3. Write the character to the write position
 * * 4. If count > 1, write each digit of the count
 * * 5. Return the final write position (new length)
 * 
 * ? Time Complexity: O(n) - We traverse the array once with the read pointer
 * ? Space Complexity: O(1) - Only constant extra space used (two pointers)
 * 
 * TODO Key Insight: 
 * *    - Two-pointer technique allows in-place modification
 * *    - We read ahead to count characters while writing behind
 * *    - Converting count to string allows handling multi-digit counts
 * *    - Write pointer always stays behind or at read pointer
 * 
 * * Optimizations: 
 * *    - Single pass through the array
 * *    - No additional data structures needed
 * *    - Handles edge cases naturally (single char, all same, all different)
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 #include <string>
 using namespace std;
 
 class Solution {
 public:
     /**
      * Compresses the character array in-place
      * @param chars The input character array to compress
      * @return The new length of the compressed array
      */
     int compress(vector<char>& chars) {
         int write = 0;  // * Position where we write compressed data
         int read = 0;   // * Position we're currently reading from
         
         while (read < chars.size()) {
             char current = chars[read];  // * Current character to compress
             int count = 0;  // * Count of consecutive occurrences
             
             // ! Count all consecutive occurrences of current character
             // ? This moves read pointer while counting
             while (read < chars.size() && chars[read] == current) {
                 read++;
                 count++;
             }
             
             // * Write the character at write position
             chars[write++] = current;
             
             // ! If count > 1, write the count digits
             // ? We skip writing '1' for single characters
             if (count > 1) {
                 // * Convert count to string and write each digit
                 // ? This handles multi-digit counts (e.g., 12 becomes '1', '2')
                 for (char c : to_string(count)) {
                     chars[write++] = c;
                 }
             }
         }
         
         return write;  // * New length of compressed array
     }
 };
 
 // ============================================================
 // * TESTING SUITE - Verifies solution with various test cases
 // ============================================================
 
 /**
  * Helper function to print test result
  */
 void printTestResult(vector<char> chars, int result, vector<char> expected, int expectedLen) {
     cout << "\nInput:  [";
     for (size_t i = 0; i < chars.size(); i++) {
         if (i > 0) cout << ",";
         cout << "\"" << chars[i] << "\"";
     }
     cout << "]\n";
     
     cout << "Output: [";
     for (int i = 0; i < result; i++) {
         if (i > 0) cout << ",";
         cout << "\"" << chars[i] << "\"";
     }
     cout << "]\n";
     
     cout << "Length: " << result << "\n";
     cout << "Expected: [";
     for (size_t i = 0; i < expected.size(); i++) {
         if (i > 0) cout << ",";
         cout << "\"" << expected[i] << "\"";
     }
     cout << "]\n";
     cout << "Expected Length: " << expectedLen << "\n";
     
     bool match = (result == expectedLen);
     if (match) {
         for (int i = 0; i < result; i++) {
             if (chars[i] != expected[i]) {
                 match = false;
                 break;
             }
         }
     }
     
     cout << "Status: " << (match ? "PASS" : "FAIL");
     if (!match) {
         cout << " (Mismatch detected)";
     }
     cout << "\n";
 }
 
 int main() {
     Solution solution;
     
     // * Test Case 1: Mixed characters with compression
     {
         vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
         vector<char> expected = {'a', '2', 'b', '2', 'c', '3'};
         int result = solution.compress(chars);
         printTestResult(chars, result, expected, 6);
     }
     
     // * Test Case 2: Single character
     {
         vector<char> chars = {'a'};
         vector<char> expected = {'a'};
         int result = solution.compress(chars);
         printTestResult(chars, result, expected, 1);
     }
     
     // * Test Case 3: All different characters (no compression)
     {
         vector<char> chars = {'a', 'b', 'c', 'd', 'e'};
         vector<char> expected = {'a', 'b', 'c', 'd', 'e'};
         int result = solution.compress(chars);
         printTestResult(chars, result, expected, 5);
     }
     
     // * Test Case 4: All same characters
     {
         vector<char> chars = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
         vector<char> expected = {'a', '1', '0'};
         int result = solution.compress(chars);
         printTestResult(chars, result, expected, 3);
     }
     
     // ! Test Case 5: Long compression (multi-digit count)
     {
         vector<char> chars = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'b', 'b'};
         vector<char> expected = {'a', '1', '2', 'b', '2'};
         int result = solution.compress(chars);
         printTestResult(chars, result, expected, 5);
     }
     
     // * Test Case 6: Two consecutive same pairs
     {
         vector<char> chars = {'a', 'a', 'b', 'b'};
         vector<char> expected = {'a', '2', 'b', '2'};
         int result = solution.compress(chars);
         printTestResult(chars, result, expected, 4);
     }
     
     // * Test Case 7: Single char groups mixed with multi-char groups
     {
         vector<char> chars = {'a', 'b', 'b', 'c', 'd', 'd', 'd'};
         vector<char> expected = {'a', 'b', '2', 'c', 'd', '3'};
         int result = solution.compress(chars);
         printTestResult(chars, result, expected, 6);
     }
     
     // * Test Case 8: Edge case - two characters
     {
         vector<char> chars = {'a', 'b'};
         vector<char> expected = {'a', 'b'};
         int result = solution.compress(chars);
         printTestResult(chars, result, expected, 2);
     }
     
     return 0;
 }
 
 /*
  * ================================================================================
  * TODO Additional Notes:
  * * - The two-pointer technique is key to achieving O(1) space complexity
  * ! - Write pointer always lags behind or equals read pointer, preventing overwrites
  * * - Converting integers to strings handles any count size elegantly
  * ? - The algorithm naturally handles all edge cases without special conditions
  * * - In-place modification requires careful pointer management
  * ================================================================================
  */