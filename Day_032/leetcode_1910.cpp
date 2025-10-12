/**
 * ================================================================================
 * LeetCode 1910: Remove All Occurrences of Substring - String Manipulation
 * ================================================================================
 * 
 * ! Problem: Given two strings s and part, perform the following operation on s 
 * ! until all occurrences of the substring part are removed:
 * ! - Find the leftmost occurrence of the substring part and remove it from s.
 * ! Return s after removing all occurrences of part.
 * 
 * * Approach:
 * * 1. Search for the first occurrence of part in string s
 * * 2. If found, remove it (erase the substring)
 * * 3. Repeat the process from step 1 until no more occurrences exist
 * * 4. Return the modified string
 * 
 * ? Time Complexity: O(n * m * k) where:
 * ?   - n = length of string s
 * ?   - m = length of substring part
 * ?   - k = number of occurrences to remove
 * ? Space Complexity: O(1) - Modifying string in-place (excluding output)
 * 
 * TODO Key Insight: 
 * *    - After each removal, new occurrences may be formed by adjacent characters
 * *    - Always search from the beginning to find the leftmost occurrence
 * *    - The string.find() method returns string::npos when substring not found
 * 
 * * Optimizations: 
 * *    - Using built-in string methods (find, erase) for efficiency
 * *    - Iterative approach avoids recursion overhead
 * ================================================================================
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Removes all occurrences of substring part from string s
     * @param s The source string to modify
     * @param part The substring to remove
     * @return The modified string with all occurrences removed
     */
    string removeOccurrences(string s, string part) {
        // * Find the first occurrence of part in s
        size_t pos = s.find(part);
        
        // * Continue removing while occurrences exist
        while (pos != string::npos) {  // ? string::npos means "not found"
            // ! Remove the substring at position pos with length part.size()
            s.erase(pos, part.size());
            
            // * Search again from the beginning to find next occurrence
            // ? This ensures we always get the leftmost occurrence
            pos = s.find(part);
        }
        
        return s;  // * Return the modified string
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(const string& s, const string& part, const string& result, const string& expected) {
    cout << "\ns = \"" << s << "\", part = \"" << part << "\"\n";
    cout << "   Result:   \"" << result << "\"\n";
    cout << "   Expected: \"" << expected << "\"\n";
    cout << "   Status:   " << (result == expected ? "PASS" : "FAIL");
    if (result != expected) {
        cout << " (Expected: \"" << expected << "\")";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Basic removal - single occurrence
    {
        string s = "daabcbaabcbc";
        string part = "abc";
        string result = solution.removeOccurrences(s, part);
        printTestResult(s, part, result, "dab");
    }
    
    // * Test Case 2: Multiple occurrences in sequence
    {
        string s = "axxxxyyyyb";
        string part = "xy";
        string result = solution.removeOccurrences(s, part);
        printTestResult(s, part, result, "ab");
    }
    
    // * Test Case 3: Single character removal
    {
        string s = "aaaaaa";
        string part = "a";
        string result = solution.removeOccurrences(s, part);
        printTestResult(s, part, result, "");
    }
    
    // * Test Case 4: No occurrence to remove
    {
        string s = "hello";
        string part = "xyz";
        string result = solution.removeOccurrences(s, part);
        printTestResult(s, part, result, "hello");
    }
    
    // * Test Case 5: Part equals entire string
    {
        string s = "abcdef";
        string part = "abcdef";
        string result = solution.removeOccurrences(s, part);
        printTestResult(s, part, result, "");
    }
    
    // * Test Case 6: Overlapping pattern formation
    {
        string s = "aabababa";
        string part = "aba";
        string result = solution.removeOccurrences(s, part);
        printTestResult(s, part, result, "a");
    }
    
    // * Test Case 7: Empty result after removals
    {
        string s = "abcabcabc";
        string part = "abc";
        string result = solution.removeOccurrences(s, part);
        printTestResult(s, part, result, "");
    }
    
    // * Test Case 8: Part at the end
    {
        string s = "helloworld";
        string part = "world";
        string result = solution.removeOccurrences(s, part);
        printTestResult(s, part, result, "hello");
    }
    
    // * Test Case 9: Part at the beginning
    {
        string s = "worldhello";
        string part = "world";
        string result = solution.removeOccurrences(s, part);
        printTestResult(s, part, result, "hello");
    }
    
    // * Test Case 10: Complex cascading removal
    {
        string s = "aabbccddaabbccdd";
        string part = "aabbccdd";
        string result = solution.removeOccurrences(s, part);
        printTestResult(s, part, result, "");
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The solution handles cascading removals where new patterns form after deletion
 * ! - Always searches from the beginning to ensure leftmost occurrence is found
 * * - The string::npos constant represents "no position" (typically -1 or max size_t)
 * ? - Time complexity can be high for many removals, but is acceptable for most cases
 * * - Alternative approaches include using stack or two-pointer technique
 * ================================================================================
 */  