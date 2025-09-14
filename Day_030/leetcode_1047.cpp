// LeetCode Problem 1047: Remove All Adjacent Duplicates In String
// You are given a string s consisting of lowercase English letters. A duplicate removal 
// consists of choosing two adjacent and equal letters and removing them.
// We repeatedly make duplicate removals on s until we no longer can.
// Return the final string after all such duplicate removals have been made.
// Example 1: Input: s = "abbaca", Output: "ca"
// Explanation: "abbaca" -> "aaca" -> "ca"
// Example 2: Input: s = "azxxzy", Output: "ay"
// Explanation: "azxxzy" -> "azzy" -> "ay"

#include <string>
using namespace std;

class Solution {
    public:
        // Function to remove all adjacent duplicates using stack-like approach
        string removeDuplicates(string s) {
            // Use result string as a stack to efficiently handle removals
            string result;
            
            // Process each character in the input string
            for (char c : s) {
                // Check if result is not empty and top character matches current character
                if (!result.empty() && result.back() == c) {
                    // Adjacent duplicate found - remove the last character (stack pop)
                    result.pop_back();
                } else {
                    // No duplicate - add current character to result (stack push)
                    result.push_back(c);
                }
            }
            
            // Return the final string after all duplicate removals
            return result;
        }
};