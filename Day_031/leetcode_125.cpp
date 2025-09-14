// LeetCode Problem 125: Valid Palindrome
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
// and removing all non-alphanumeric characters, it reads the same forward and backward.
// Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.
// Example 1: Input: s = "A man, a plan, a canal: Panama", Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2: Input: s = "race a car", Output: false
// Explanation: "raceacar" is not a palindrome.

#include <string>
using namespace std;

class Solution {
    private:
        // Helper function to convert uppercase character to lowercase
        char toLowerCase(char ch) {
            // Check if character is uppercase (A-Z)
            if (ch >= 'A' && ch <= 'Z')
                return ch - 'A' + 'a';  // Convert to lowercase using ASCII difference
            return ch;  // Return as-is if already lowercase or not a letter
        }
        
        // Helper function to check if character is alphanumeric
        bool isAlphaNum(char ch) {
            // Check if character is lowercase letter, uppercase letter, or digit
            return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
                   (ch >= '0' && ch <= '9');
        }
    
    public:
        // Function to check if string is a valid palindrome
        bool isPalindrome(string s) {
            // Step 1: Create cleaned string with only alphanumeric characters in lowercase
            string temp;
            for (char val : s) {
                if (isAlphaNum(val))  // Only include alphanumeric characters
                    temp.push_back(toLowerCase(val));  // Convert to lowercase and add
            }
    
            // Step 2: Use two pointers to check if cleaned string is palindrome
            int a = 0;                    // Left pointer starting from beginning
            int b = temp.size() - 1;      // Right pointer starting from end
    
            // Compare characters from both ends moving towards center
            while (a < b) {
                if (temp[a] != temp[b])   // If characters don't match, not a palindrome
                    return false;
                a++;                      // Move left pointer right
                b--;                      // Move right pointer left
            }
    
            return true;  // All characters matched, it's a palindrome
        }
};