/**
 * ================================================================================
 * LeetCode 2942: Find Words Containing Character - String Search Algorithm
 * ================================================================================
 * 
 * ! Problem: Given a 0-indexed array of strings `words` and a character `x`,
 * ! return an array of indices representing the words that contain the character `x`.
 * ! The returned array may be in any order.
 * 
 * * Approach:
 * * 1. Initialize an empty result vector to store matching indices
 * * 2. Iterate through each word in the words array with index i
 * * 3. For each word, use the string::find() method to search for character x
 * * 4. If find() returns a valid position (not string::npos), add index i to result
 * * 5. Return the result vector containing all matching indices
 * 
 * ? Time Complexity: O(n × m) - n is number of words, m is average word length
 * ? Space Complexity: O(k) - k is number of words containing the character
 * 
 * TODO Key Insight: 
 * *    - string::find() returns string::npos when character is not found
 * *    - string::npos is a special constant representing "not found" (-1)
 * *    - Linear scan is optimal since array is unsorted
 * *    - Each word must be checked individually
 * 
 * * Optimizations: 
 * *    - Single pass through the array
 * *    - Early termination per word when character is found
 * *    - Uses built-in string search for efficiency
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * Finds all word indices that contain the specified character
     * @param words Vector of strings to search through
     * @param x Character to search for in each word
     * @return Vector of indices where words contain character x
     */
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;              // * Stores indices of matching words
        int n = words.size();         // * Total number of words to check
        
        for (int i = 0; i < n; i++) { // * Iterate through each word
            // ? string::find(x) returns position of x, or string::npos if not found
            if (words[i].find(x) != string::npos) {
                ans.push_back(i);     // ! Character found, add index to result
            }
        }
        
        return ans;                   // * Return all matching indices
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print vector contents
 */
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

/**
 * Helper function to print test result
 */
void printTestResult(vector<string>& words, char x, vector<int>& result, vector<int>& expected) {
    cout << "\nWords: [";
    for (int i = 0; i < words.size(); i++) {
        cout << "\"" << words[i] << "\"";
        if (i < words.size() - 1) cout << ", ";
    }
    cout << "], Character: '" << x << "'\n";
    
    cout << "   Result:   ";
    printVector(result);
    cout << "\n   Expected: ";
    printVector(expected);
    
    bool pass = (result.size() == expected.size());
    if (pass) {
        for (int i = 0; i < result.size(); i++) {
            if (result[i] != expected[i]) {
                pass = false;
                break;
            }
        }
    }
    
    cout << "\n   Status:   " << (pass ? "PASS" : "FAIL") << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Multiple words contain character
    {
        vector<string> words = {"leet", "code"};
        char x = 'e';
        vector<int> result = solution.findWordsContaining(words, x);
        vector<int> expected = {0, 1};
        printTestResult(words, x, result, expected);
    }
    
    // * Test Case 2: Only some words contain character
    {
        vector<string> words = {"abc", "bcd", "aaaa", "cbc"};
        char x = 'a';
        vector<int> result = solution.findWordsContaining(words, x);
        vector<int> expected = {0, 2};
        printTestResult(words, x, result, expected);
    }
    
    // * Test Case 3: No words contain character
    {
        vector<string> words = {"abc", "bcd", "aaaa", "cbc"};
        char x = 'z';
        vector<int> result = solution.findWordsContaining(words, x);
        vector<int> expected = {};
        printTestResult(words, x, result, expected);
    }
    
    // * Test Case 4: Single word contains character
    {
        vector<string> words = {"hello"};
        char x = 'l';
        vector<int> result = solution.findWordsContaining(words, x);
        vector<int> expected = {0};
        printTestResult(words, x, result, expected);
    }
    
    // ! Test Case 5: Character appears multiple times in same word
    {
        vector<string> words = {"aaa", "bbb", "ccc"};
        char x = 'a';
        vector<int> result = solution.findWordsContaining(words, x);
        vector<int> expected = {0};
        printTestResult(words, x, result, expected);
    }
    
    // ! Test Case 6: All words contain character
    {
        vector<string> words = {"apple", "banana", "orange"};
        char x = 'a';
        vector<int> result = solution.findWordsContaining(words, x);
        vector<int> expected = {0, 1, 2};
        printTestResult(words, x, result, expected);
    }
    
    // * Test Case 7: Character at beginning of word
    {
        vector<string> words = {"start", "end", "middle"};
        char x = 's';
        vector<int> result = solution.findWordsContaining(words, x);
        vector<int> expected = {0};
        printTestResult(words, x, result, expected);
    }
    
    // * Test Case 8: Character at end of word
    {
        vector<string> words = {"cat", "dog", "rat"};
        char x = 't';
        vector<int> result = solution.findWordsContaining(words, x);
        vector<int> expected = {0, 2};
        printTestResult(words, x, result, expected);
    }
    
    // * Test Case 9: Mix of uppercase and lowercase (case-sensitive)
    {
        vector<string> words = {"Hello", "hello", "HELLO"};
        char x = 'h';
        vector<int> result = solution.findWordsContaining(words, x);
        vector<int> expected = {1};
        printTestResult(words, x, result, expected);
    }
    
    // * Test Case 10: Long words with character in middle
    {
        vector<string> words = {"programming", "algorithm", "data"};
        char x = 'r';
        vector<int> result = solution.findWordsContaining(words, x);
        vector<int> expected = {0, 1};
        printTestResult(words, x, result, expected);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - string::find() is case-sensitive: 'a' != 'A'
 * ! - string::npos is typically defined as size_t(-1), the largest possible value
 * * - The algorithm doesn't modify the input array
 * ? - For very large datasets, consider using hash maps for multiple character searches
 * * - Result order matches input array order (indices are in ascending order)
 * ================================================================================
 */