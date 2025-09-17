#include <iostream>
#include <string>
using namespace std;

/*
================================================================================
LeetCode 125: Valid Palindrome
================================================================================
🔹 Problem Description:
A phrase is a palindrome if, after converting all uppercase letters into lowercase
and removing all non-alphanumeric characters, it reads the same forward and backward.
Alphanumeric characters include letters and numbers.

--------------------------------------------------------------------------------
Examples:
Input:  s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Input:  s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 Idea: Clean & Two-Pointer Check
1. Remove non-alphanumeric characters and convert letters to lowercase.
2. Use two pointers (start and end) to compare characters from both ends.
3. If all pairs match → palindrome, otherwise → not.

⏱ Time Complexity: O(n) → single pass to clean + single pass for comparison
📦 Space Complexity: O(n) → cleaned string
================================================================================
*/

class Solution {
private:
    // * Convert uppercase letter to lowercase
    char toLowerCase(char ch) {
        if (ch >= 'A' && ch <= 'Z')
            return ch - 'A' + 'a'; // ASCII conversion
        return ch; // Already lowercase or digit
    }

    // * Check if character is alphanumeric
    bool isAlphaNum(char ch) {
        return (ch >= 'a' && ch <= 'z') ||
               (ch >= 'A' && ch <= 'Z') ||
               (ch >= '0' && ch <= '9');
    }

public:
    bool isPalindrome(string s) {
        string temp; // * Cleaned string

        // * Step 1: Build cleaned string
        for (char val : s) {
            if (isAlphaNum(val))
                temp.push_back(toLowerCase(val)); // Convert and append
        }

        // * Step 2: Two-pointer palindrome check
        int a = 0;                  // Left pointer
        int b = temp.size() - 1;    // Right pointer

        while (a < b) {
            if (temp[a] != temp[b])  // * Mismatch → not palindrome
                return false;
            a++;  // Move left pointer right
            b--;  // Move right pointer left
        }

        return true; // * All characters matched → palindrome
    }
};

// ==================== Driver Code for Testing ====================
int main() {
    Solution obj;

    string s1 = "A man, a plan, a canal: Panama";
    cout << boolalpha << obj.isPalindrome(s1) << endl; // Output: true

    string s2 = "race a car";
    cout << boolalpha << obj.isPalindrome(s2) << endl; // Output: false

    return 0;
}
