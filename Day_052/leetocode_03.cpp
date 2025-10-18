/**
 * ================================================================================
 * LeetCode 3: Longest Substring Without Repeating Characters - Sliding Window
 * ================================================================================
 * 
 * ! Problem: Given a string s, find the length of the longest substring without
 * ! repeating characters. A substring is a contiguous sequence of characters
 * ! within the string.
 * 
 * * Approach:
 * * 1. Use sliding window technique with two pointers (start and end)
 * * 2. Maintain a hash map to track last seen position of each character
 * * 3. Expand window by moving end pointer through string
 * * 4. When duplicate found, shrink window by moving start pointer
 * * 5. Track maximum window size throughout the process
 * 
 * ? Time Complexity: O(n) - Single pass through string with constant lookups
 * ? Space Complexity: O(min(n, m)) - Hash map size limited by charset (m=256)
 * 
 * TODO Key Insight:
 * *    - Sliding window allows efficient substring exploration without nested loops
 * *    - Hash map enables O(1) duplicate detection and position tracking
 * *    - Move start pointer to (duplicate_position + 1) to maintain uniqueness
 * *    - Update max length after processing each character for optimal tracking
 * 
 * * Optimizations:
 * *    - Single pass algorithm (optimal for this problem)
 * *    - Fixed-size array (256) faster than unordered_map for ASCII
 * *    - Early max calculation prevents additional loop
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * Finds the length of longest substring without repeating characters
     * @param s The input string to analyze
     * @return Length of the longest valid substring
     */
    int lengthOfLongestSubstring(string s) {
        //// * Hash array to store last seen index of each character
        //// ? Using vector<int> with size 256 covers all ASCII characters
        vector<int> seen(256, -1);  //// Initialize all positions to -1 (not seen)
        
        int maxLen = 0;  //// * Track maximum substring length found
        int st = 0;      //// * Start pointer of current window
        
        //// * Iterate through string with end pointer
        for (int i = 0; i < s.size(); i++) {
            //// ? Check if current character was seen in current window
            if (seen[s[i]] >= st) {
                //// ! Duplicate found - move start pointer past previous occurrence
                st = seen[s[i]] + 1;
            }
            
            //// * Update last seen position of current character
            seen[s[i]] = i;
            
            //// * Calculate current window size and update maximum
            //// ? Window size = (end - start + 1) = (i - st + 1)
            maxLen = max(maxLen, i - st + 1);
        }
        
        return maxLen;
    }
};

// ============================================================
// * TESTING SUITE - Comprehensive verification framework
// ============================================================

/**
 * Helper function to display test results with detailed formatting
 */
void printTestResult(const string& s, int result, int expected, const string& explanation) {
    cout << "\n----------------------------------------\n";
    cout << "Input:       \"" << s << "\"\n";
    cout << "Output:      " << result << "\n";
    cout << "Expected:    " << expected << "\n";
    cout << "Explanation: " << explanation << "\n";
    cout << "Status:      " << (result == expected ? "✓ PASS" : "✗ FAIL");
    if (result != expected) {
        cout << " (Mismatch detected!)";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    
    cout << "========================================\n";
    cout << "  LONGEST SUBSTRING WITHOUT REPEATING\n";
    cout << "       CHARACTERS - TEST SUITE\n";
    cout << "========================================\n";
    
    //// * Test Case 1: Standard case with repeating characters
    {
        string s = "abcabcbb";
        int result = solution.lengthOfLongestSubstring(s);
        printTestResult(s, result, 3, "Longest: \"abc\" (length 3)");
    }
    
    //// * Test Case 2: All same characters
    {
        string s = "bbbbb";
        int result = solution.lengthOfLongestSubstring(s);
        printTestResult(s, result, 1, "Longest: \"b\" (length 1)");
    }
    
    //// * Test Case 3: Mixed unique and repeating
    {
        string s = "pwwkew";
        int result = solution.lengthOfLongestSubstring(s);
        printTestResult(s, result, 3, "Longest: \"wke\" (length 3)");
    }
    
    //// * Test Case 4: Empty string
    {
        string s = "";
        int result = solution.lengthOfLongestSubstring(s);
        printTestResult(s, result, 0, "Empty string has length 0");
    }
    
    //// * Test Case 5: Single character
    {
        string s = "a";
        int result = solution.lengthOfLongestSubstring(s);
        printTestResult(s, result, 1, "Single character: \"a\"");
    }
    
    //// * Test Case 6: All unique characters
    {
        string s = "abcdefgh";
        int result = solution.lengthOfLongestSubstring(s);
        printTestResult(s, result, 8, "Entire string is unique");
    }
    
    //// ! Test Case 7: Pattern with early duplicate
    {
        string s = "abba";
        int result = solution.lengthOfLongestSubstring(s);
        printTestResult(s, result, 2, "Longest: \"ab\" or \"ba\" (length 2)");
    }
    
    //// ! Test Case 8: Space characters
    {
        string s = "a b c a b c";
        int result = solution.lengthOfLongestSubstring(s);
        printTestResult(s, result, 3, "Spaces count as characters");
    }
    
    //// * Test Case 9: Numbers and special characters
    {
        string s = "12#45#67";
        int result = solution.lengthOfLongestSubstring(s);
        printTestResult(s, result, 5, "Longest: \"45#67\" (length 5)");
    }
    
    //// * Test Case 10: Long string with pattern
    {
        string s = "dvdf";
        int result = solution.lengthOfLongestSubstring(s);
        printTestResult(s, result, 3, "Longest: \"vdf\" (length 3)");
    }
    
    cout << "\n========================================\n";
    cout << "  All tests completed!\n";
    cout << "========================================\n";
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - Algorithm maintains optimal O(n) time by visiting each character once
 * ! - Hash array approach faster than map for ASCII characters (constant access)
 * * - Sliding window technique is key pattern for substring/subarray problems
 * ? - Start pointer only moves forward, never backward (monotonic property)
 * * - Works with any character set by adjusting hash array size
 * ! - Edge cases handled: empty string, single char, all unique, all same
 * ================================================================================
 */