/**
 * ================================================================================
 * LeetCode 1047: Remove All Adjacent Duplicates In String - Stack Simulation
 * ================================================================================
 * 
 * ! Problem: You are given a string s consisting of lowercase English letters. 
 * ! A duplicate removal consists of choosing two adjacent and equal letters and removing them.
 * ! We repeatedly make duplicate removals on s until we no longer can.
 * ! Return the final string after all such duplicate removals have been made.
 * 
 * * Approach:
 * * 1. Use a string as a stack to simulate the removal process
 * * 2. For each character in the input string:
 * *    - If the result stack is not empty AND the top matches current character
 * *      → Remove the top (pop_back) - this is the duplicate removal
 * *    - Otherwise, add the current character to result stack
 * * 3. The result string contains the final answer after all removals
 * 
 * ? Time Complexity: O(n) - We process each character exactly once
 * ? Space Complexity: O(n) - Result string can be at most the size of input
 * 
 * TODO Key Insight: 
 * *    - This is a classic stack problem where we use string as stack
 * *    - Each character is either added or removed (paired with previous)
 * *    - The algorithm is greedy - we remove duplicates as soon as we find them
 * *    - Similar to parentheses matching but with any adjacent equal characters
 * 
 * * Optimizations: 
 * *    - Using string instead of actual stack<char> avoids conversion overhead
 * *    - Single pass through the string ensures optimal time complexity
 * *    - No need for additional data structures
 * ================================================================================
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * Removes all adjacent duplicate characters from the string
     * @param s The input string consisting of lowercase English letters
     * @return The final string after all duplicate removals
     */
    string removeDuplicates(string s) {
        string result;  // * Acts as a stack to build the final result
        
        // * Process each character in the input string
        for (char c : s) {
            // ! Check if current character matches the top of our stack
            // ? If stack not empty AND top element equals current character
            if (!result.empty() && result.back() == c) {
                result.pop_back();  // ! Remove the duplicate pair
            } else {
                result.push_back(c);  // * Add character to result stack
            }
        }
        
        return result;  // * Return the final string with all duplicates removed
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result with visual formatting
 */
void printTestResult(const string& input, const string& result, const string& expected) {
    cout << "\nInput:    \"" << input << "\"\n";
    cout << "   Result:   \"" << result << "\"\n";
    cout << "   Expected: \"" << expected << "\"\n";
    cout << "   Status:   " << (result == expected ? "PASS ✓" : "FAIL ✗");
    if (result != expected) {
        cout << " (Expected: \"" << expected << "\")";
    }
    cout << "\n";
}

/**
 * Helper function to visualize the step-by-step process
 */
void visualizeProcess(const string& s) {
    cout << "\n--- Step-by-step visualization for \"" << s << "\" ---\n";
    string result;
    cout << "Stack: []\n";
    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        cout << "Process '" << c << "': ";
        
        if (!result.empty() && result.back() == c) {
            cout << "Match found! Remove '" << result.back() << "' → ";
            result.pop_back();
            cout << "[" << result << "]\n";
        } else {
            result.push_back(c);
            cout << "Add '" << c << "' → [" << result << "]\n";
        }
    }
    
    cout << "Final result: \"" << result << "\"\n";
}

int main() {
    Solution solution;
    
    cout << "================================================================================\n";
    cout << "LeetCode 1047: Remove All Adjacent Duplicates In String - Test Suite\n";
    cout << "================================================================================\n";
    
    // * Test Case 1: Basic duplicate removal
    {
        string s = "abbaca";
        string result = solution.removeDuplicates(s);
        printTestResult(s, result, "ca");
        // ? Explanation: Remove "bb" → "aaca", Remove "aa" → "ca"
    }
    
    // * Test Case 2: Complete cancellation
    {
        string s = "aabbcc";
        string result = solution.removeDuplicates(s);
        printTestResult(s, result, "");
        // ? All pairs cancel out
    }
    
    // * Test Case 3: No duplicates to remove
    {
        string s = "abcdef";
        string result = solution.removeDuplicates(s);
        printTestResult(s, result, "abcdef");
        // ? No adjacent duplicates exist
    }
    
    // * Test Case 4: All same characters
    {
        string s = "aaaa";
        string result = solution.removeDuplicates(s);
        printTestResult(s, result, "");
        // ? All pairs cancel: aaaa → aa → ""
    }
    
    // * Test Case 5: Odd number of same characters
    {
        string s = "aaaaa";
        string result = solution.removeDuplicates(s);
        printTestResult(s, result, "a");
        // ? Four pairs cancel, one remains
    }
    
    // * Test Case 6: Single character
    {
        string s = "a";
        string result = solution.removeDuplicates(s);
        printTestResult(s, result, "a");
        // ? Nothing to remove
    }
    
    // ! Test Case 7: Complex nested removals
    {
        string s = "azxxzy";
        string result = solution.removeDuplicates(s);
        printTestResult(s, result, "ay");
        // ? Remove "xx" → "azzy", Remove "zz" → "ay"
    }
    
    // ! Test Case 8: Multiple stages of removal
    {
        string s = "abccba";
        string result = solution.removeDuplicates(s);
        printTestResult(s, result, "");
        // ? Remove "cc" → "abba", Remove "bb" → "aa", Remove "aa" → ""
    }
    
    // * Test Case 9: Pattern with alternating characters
    {
        string s = "abab";
        string result = solution.removeDuplicates(s);
        printTestResult(s, result, "abab");
        // ? No adjacent duplicates
    }
    
    // * Test Case 10: Long repeated sequence
    {
        string s = "mississippi";
        string result = solution.removeDuplicates(s);
        printTestResult(s, result, "m");
        // ? Multiple removals lead to single 'm'
    }
    
    cout << "\n================================================================================\n";
    cout << "Detailed Visualization Example\n";
    cout << "================================================================================\n";
    
    // * Visualize a complex example
    visualizeProcess("abbaca");
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - This problem demonstrates the power of using strings as stacks in C++
 * ! - The key insight is recognizing that each removal creates new adjacencies
 * * - Similar problems: Valid Parentheses (LeetCode 20), Backspace String Compare (LeetCode 844)
 * ? - Alternative approach: Could use actual stack<char> but string is more efficient
 * * - The algorithm is optimal - can't do better than O(n) time and O(n) space
 * ! - Edge cases handled: empty result, single character, complete cancellation
 * ? - Real-world application: Text editors (backspace functionality), compiler parsers
 * ================================================================================
 */
