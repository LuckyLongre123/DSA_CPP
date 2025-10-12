/**
 * ================================================================================
 * LeetCode 125: Valid Palindrome - String Manipulation & Two Pointers
 * ================================================================================
 * 
 * ! Problem: A phrase is a palindrome if, after converting all uppercase letters 
 * ! to lowercase and removing all non-alphanumeric characters, it reads the same 
 * ! forward and backward. Given a string s, return true if it is a palindrome.
 * 
 * * Approach:
 * * 1. Filter the string: Extract only alphanumeric characters and convert to lowercase
 * * 2. Use two-pointer technique to compare characters from both ends
 * * 3. If all characters match, return true; otherwise return false
 * 
 * ? Time Complexity: O(n) - Single pass to filter, single pass to check palindrome
 * ? Space Complexity: O(n) - Temporary string to store filtered characters
 * 
 * TODO Key Insight: 
 * *    - The main challenge is properly filtering non-alphanumeric characters
 * *    - Two-pointer technique efficiently checks palindrome property
 * *    - Case-insensitive comparison requires converting to same case
 * 
 * * Optimizations: 
 * *    - Could use in-place two-pointer on original string (O(1) space)
 * *    - Current approach is clearer and more maintainable
 * ================================================================================
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    /**
     * Converts uppercase character to lowercase
     * @param ch Character to convert
     * @return Lowercase version of character
     */
    char toLowerCase(char ch) {
        // * Check if character is uppercase letter
        if (ch >= 'A' && ch <= 'Z')
            return ch - 'A' + 'a';  // * Convert to lowercase by offset
        return ch;  // * Already lowercase or not a letter
    }
    
    /**
     * Checks if character is alphanumeric
     * @param ch Character to check
     * @return True if letter or digit, false otherwise
     */
    bool isAlphaNum(char ch) {
        // * Check lowercase letters, uppercase letters, and digits
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
               (ch >= '0' && ch <= '9');
    }

public:
    /**
     * Determines if a string is a valid palindrome
     * @param s Input string to check
     * @return True if palindrome (ignoring case and non-alphanumeric), false otherwise
     */
    bool isPalindrome(string s) {
        string temp;  // * Stores filtered alphanumeric characters
        
        // ! Phase 1: Filter and normalize the string
        // ? Extract only alphanumeric characters and convert to lowercase
        for (char val : s) {
            if (isAlphaNum(val))
                temp.push_back(toLowerCase(val));
        }

        // ! Phase 2: Check palindrome using two-pointer technique
        int a = 0;                  // * Left pointer starting from beginning
        int b = temp.size() - 1;    // * Right pointer starting from end

        while (a < b) {
            // * Compare characters from both ends
            if (temp[a] != temp[b])
                return false;  // ! Mismatch found - not a palindrome
            a++;  // * Move left pointer forward
            b--;  // * Move right pointer backward
        }

        return true;  // * All characters matched - valid palindrome
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(const string& s, bool result, bool expected) {
    cout << "\nInput: \"" << s << "\"\n";
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
    
    // * Test Case 1: Simple palindrome with mixed case
    {
        string s = "A man, a plan, a canal: Panama";
        bool result = solution.isPalindrome(s);
        printTestResult(s, result, true);
    }
    
    // * Test Case 2: Not a palindrome
    {
        string s = "race a car";
        bool result = solution.isPalindrome(s);
        printTestResult(s, result, false);
    }
    
    // * Test Case 3: Single space (edge case)
    {
        string s = " ";
        bool result = solution.isPalindrome(s);
        printTestResult(s, result, true);
    }
    
    // * Test Case 4: Empty string
    {
        string s = "";
        bool result = solution.isPalindrome(s);
        printTestResult(s, result, true);
    }
    
    // * Test Case 5: Single character
    {
        string s = "a";
        bool result = solution.isPalindrome(s);
        printTestResult(s, result, true);
    }
    
    // ! Test Case 6: Only non-alphanumeric characters
    {
        string s = ".,!@#";
        bool result = solution.isPalindrome(s);
        printTestResult(s, result, true);
    }
    
    // * Test Case 7: Palindrome with numbers
    {
        string s = "A1b2B1a";
        bool result = solution.isPalindrome(s);
        printTestResult(s, result, true);
    }
    
    // * Test Case 8: Mixed alphanumeric
    {
        string s = "0P";
        bool result = solution.isPalindrome(s);
        printTestResult(s, result, false);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The solution handles all edge cases including empty strings and single characters
 * ! - The filtering approach makes the palindrome check straightforward
 * * - Two-pointer technique is optimal for palindrome verification
 * ? - Alternative: Could use O(1) space with in-place two-pointer on original string
 * ================================================================================
 */