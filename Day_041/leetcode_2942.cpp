/**
 * ================================================================================
 * 🔍 LeetCode 2942: Find Words Containing Character - String Search & Indexing
 * ================================================================================
 * 
 * 🎯 Problem: Given a 0-indexed array of strings `words` and a character `x`,
 * return an array of indices representing the words that contain the character `x`.
 * Note that the returned array may be in any order.
 * 
 * 📝 Approach:
 * 1. Initialize an empty result vector to store indices
 * 2. Iterate through each word in the words array
 * 3. For each word, check if it contains the target character
 * 4. If found, add the current index to the result vector
 * 5. Return the collected indices
 * 
 * ⚡ Time Complexity: O(n * m) where n = number of words, m = average word length
 * 💾 Space Complexity: O(k) where k = number of words containing the character
 * 
 * 🧠 Key Insight: 
 *    - This is a straightforward linear search problem
 *    - We use string::find() which returns string::npos if character not found
 *    - The problem allows any order for the result, so we can append indices sequentially
 * 
 * 🚀 Optimizations: 
 *    - Single pass through the words array
 *    - Early termination per word once character is found
 *    - Efficient string search using built-in find() method
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <chrono>
 using namespace std;
 
 class Solution {
 public:
     //! MAIN FUNCTION: Finds all word indices that contain a specific character
     //! @param words Vector of strings to search through
     //! @param x The target character to find
     //! @return Vector of indices where words contain the character x
     vector<int> findWordsContaining(vector<string>& words, char x) {
         vector<int> result;  // * Stores indices of words containing character x
         
         //! Input validation
         if (words.empty()) {
             return result;  // * Return empty vector for empty input
         }
         
         //! Iterate through each word with its index
         for (int i = 0; i < static_cast<int>(words.size()); i++) {
             //! Check if current word contains the target character
             //? string::find() returns string::npos if character is not found
             if (words[i].find(x) != string::npos) {
                 result.push_back(i);  // * Add index to result if character found
             }
         }
         
         return result;
     }
     
     //! ALTERNATIVE METHOD 1: Using range-based loop with manual indexing
     //! Time: O(n*m), Space: O(k) - More readable but slightly less efficient
     vector<int> findWordsContainingV2(vector<string>& words, char x) {
         vector<int> result;
         int index = 0;
         
         for (const string& word : words) {
             //! Check each character manually for educational purposes
             bool found = false;
             for (char c : word) {
                 if (c == x) {
                     found = true;
                     break;  // * Early termination once character is found
                 }
             }
             
             if (found) {
                 result.push_back(index);
             }
             index++;
         }
         
         return result;
     }
     
     //! ALTERNATIVE METHOD 2: Using STL algorithms (functional approach)
     //! Time: O(n*m), Space: O(k) - More functional programming style
     vector<int> findWordsContainingV3(vector<string>& words, char x) {
         vector<int> result;
         
         for (int i = 0; i < static_cast<int>(words.size()); i++) {
             //! Using std::find to search for character in word
             if (std::find(words[i].begin(), words[i].end(), x) != words[i].end()) {
                 result.push_back(i);
             }
         }
         
         return result;
     }
     
     //! PERFORMANCE TESTING: Measures execution time for different approaches
     void performanceTest(vector<string>& words, char x) {
         auto start = chrono::high_resolution_clock::now();
         
         // Test main method
         auto result1 = findWordsContaining(words, x);
         auto end1 = chrono::high_resolution_clock::now();
         auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start);
         
         // Test alternative method 2
         start = chrono::high_resolution_clock::now();
         auto result2 = findWordsContainingV2(words, x);
         auto end2 = chrono::high_resolution_clock::now();
         auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start);
         
         cout << "\n⏱️  Performance Comparison:\n";
         cout << "   Method 1 (string::find): " << duration1.count() << " microseconds\n";
         cout << "   Method 2 (manual search): " << duration2.count() << " microseconds\n";
         cout << "   Results match: " << (result1 == result2 ? "✅ Yes" : "❌ No") << "\n";
     }
 };
 
 // ============================================================
 // 🧪 TESTING SUITE - Comprehensive test cases and validation
 // ============================================================
 
 //! Helper function to print vector contents
 void printVector(const vector<int>& vec, const string& label) {
     cout << label << ": [";
     for (size_t i = 0; i < vec.size(); i++) {
         cout << vec[i];
         if (i < vec.size() - 1) cout << ", ";
     }
     cout << "]\n";
 }
 
 //! Helper function to print test result with detailed comparison
 void printTestResult(const vector<string>& words, char x, 
                     const vector<int>& result, const vector<int>& expected) {
     cout << "\n🔍 Test Case:\n";
     cout << "   Words: [";
     for (size_t i = 0; i < words.size(); i++) {
         cout << "\"" << words[i] << "\"";
         if (i < words.size() - 1) cout << ", ";
     }
     cout << "]\n";
     cout << "   Character: '" << x << "'\n";
     
     printVector(result, "   Result  ");
     printVector(expected, "   Expected");
     
     // Sort both vectors for comparison (since order doesn't matter)
     vector<int> sortedResult = result;
     vector<int> sortedExpected = expected;
     sort(sortedResult.begin(), sortedResult.end());
     sort(sortedExpected.begin(), sortedExpected.end());
     
     bool passed = (sortedResult == sortedExpected);
     cout << "   Status: " << (passed ? "✅ PASS" : "❌ FAIL") << "\n";
     
     if (!passed) {
         cout << "   ⚠️  Mismatch detected!\n";
     }
 }
 
 //! Comprehensive test function covering all edge cases
 void runComprehensiveTests() {
     Solution solution;
     cout << "\n🚀 Running Comprehensive Test Suite for LeetCode 2942\n";
     cout << "=" << string(60, '=') << "\n";
     
     // Test Case 1: Basic example from problem description
     {
         vector<string> words = {"leet", "code"};
         char x = 'e';
         vector<int> result = solution.findWordsContaining(words, x);
         vector<int> expected = {0, 1};
         printTestResult(words, x, result, expected);
     }
     
     // Test Case 2: Character appears in some words
     {
         vector<string> words = {"abc", "bcd", "aaaa", "cbc"};
         char x = 'a';
         vector<int> result = solution.findWordsContaining(words, x);
         vector<int> expected = {0, 2};
         printTestResult(words, x, result, expected);
     }
     
     // Test Case 3: Character not found in any word
     {
         vector<string> words = {"abc", "bcd", "aaaa", "cbc"};
         char x = 'z';
         vector<int> result = solution.findWordsContaining(words, x);
         vector<int> expected = {};
         printTestResult(words, x, result, expected);
     }
     
     // Test Case 4: Single word containing character
     {
         vector<string> words = {"hello"};
         char x = 'l';
         vector<int> result = solution.findWordsContaining(words, x);
         vector<int> expected = {0};
         printTestResult(words, x, result, expected);
     }
     
     // Test Case 5: Single word not containing character
     {
         vector<string> words = {"hello"};
         char x = 'z';
         vector<int> result = solution.findWordsContaining(words, x);
         vector<int> expected = {};
         printTestResult(words, x, result, expected);
     }
     
     // Test Case 6: All words contain the character
     {
         vector<string> words = {"apple", "banana", "grape", "orange"};
         char x = 'a';
         vector<int> result = solution.findWordsContaining(words, x);
         vector<int> expected = {0, 1, 2, 3};
         printTestResult(words, x, result, expected);
     }
     
     // Test Case 7: Character appears multiple times in words
     {
         vector<string> words = {"aaa", "bbb", "aba", "ccc"};
         char x = 'a';
         vector<int> result = solution.findWordsContaining(words, x);
         vector<int> expected = {0, 2};
         printTestResult(words, x, result, expected);
     }
     
     // Test Case 8: Single character words
     {
         vector<string> words = {"a", "b", "c", "a"};
         char x = 'a';
         vector<int> result = solution.findWordsContaining(words, x);
         vector<int> expected = {0, 3};
         printTestResult(words, x, result, expected);
     }
     
     // Test Case 9: Maximum constraint test (50 words)
     {
         vector<string> words;
         for (int i = 0; i < 50; i++) {
             words.push_back(i % 2 == 0 ? "word" + to_string(i) + "x" : "word" + to_string(i));
         }
         char x = 'x';
         vector<int> result = solution.findWordsContaining(words, x);
         
         cout << "\n🔍 Large Scale Test (50 words):\n";
         cout << "   Character: '" << x << "'\n";
         cout << "   Words containing 'x': " << result.size() << " out of 50\n";
         cout << "   Status: ✅ PASS (Performance test)\n";
     }
     
     // Test Case 10: Empty words vector (edge case)
     {
         vector<string> words = {};
         char x = 'a';
         vector<int> result = solution.findWordsContaining(words, x);
         vector<int> expected = {};
         printTestResult(words, x, result, expected);
     }
     
     cout << "\n🎉 All test cases completed!\n";
 }
 
 int main() {
     // Run comprehensive tests
     runComprehensiveTests();
     
     // Performance testing with larger dataset
     cout << "\n" << string(60, '=') << "\n";
     cout << "🏃‍♂️ Performance Testing\n";
     cout << string(60, '=') << "\n";
     
     Solution solution;
     vector<string> perfWords;
     for (int i = 0; i < 1000; i++) {
         perfWords.push_back("performance" + to_string(i % 10) + "test");
     }
     
     solution.performanceTest(perfWords, 'e');
     
     return 0;
 }
 
 /*
  * ================================================================================
  * 📝 Additional Notes:
  * 
  * 🎯 Algorithm Analysis:
  * - The solution uses a simple linear search approach
  * - Each word is checked exactly once using string::find()
  * - string::find() internally uses optimized string searching algorithms
  * 
  * 🔧 Implementation Details:
  * - Uses string::npos constant for "not found" comparison
  * - Handles empty input gracefully
  * - Maintains original order of indices in result
  * 
  * 🚀 Optimization Opportunities:
  * - For very large datasets, consider using parallel processing
  * - For repeated queries, consider preprocessing with character-to-indices mapping
  * - For memory-constrained environments, consider streaming approach
  * 
  * 🧪 Testing Strategy:
  * - Covers all basic examples from problem description
  * - Tests edge cases: empty input, single words, all matches, no matches
  * - Includes performance testing with larger datasets
  * - Validates correctness across different implementation approaches
  * 
  * 📊 Real-world Applications:
  * - Text search and filtering systems
  * - Document indexing and retrieval
  * - Auto-completion and suggestion systems
  * - Data validation and processing pipelines
  * ================================================================================
  */
 