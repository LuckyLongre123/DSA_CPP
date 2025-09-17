#include <iostream>
#include <string>
using namespace std;

/*
================================================================================
LeetCode 1047: Remove All Adjacent Duplicates In String
================================================================================
🔹 Problem Description:
You are given a string s consisting of lowercase English letters.
A duplicate removal consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until no more can be done.

--------------------------------------------------------------------------------
Examples:
Input:  s = "abbaca"
Step 1: "abbaca" -> "aaca"  (remove "bb")
Step 2: "aaca"  -> "ca"    (remove "aa")
Output: "ca"

Input:  s = "azxxzy"
Step 1: "azxxzy" -> "azzy" (remove "xx")
Step 2: "azzy"  -> "ay"   (remove "zz")
Output: "ay"

Constraints:
* 1 <= s.length <= 10^5
* s consists of lowercase English letters.
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 Idea: Stack-like approach using string
1. Use the result string as a "stack".
2. Iterate through each character in input string:
   - If stack is not empty and top element == current character, pop it (remove duplicate)
   - Otherwise, push current character onto stack
3. The stack (result string) contains final answer.

⏱ Time Complexity: O(n) → single pass through string
📦 Space Complexity: O(n) → worst-case all characters are unique
================================================================================
*/

class Solution {
public:
    string removeDuplicates(string s) {
        string result;  // * Use as stack to store characters

        for (char c : s) {
            // * If last char in stack matches current char → remove duplicate
            if (!result.empty() && result.back() == c) {
                result.pop_back();  // * Pop the top element (duplicate removed)
            } else {
                result.push_back(c);  // * Push current char to stack
            }
        }

        return result;  // * Return final string after all removals
    }
};

// ==================== Driver Code for Testing ====================
int main() {
    Solution obj;

    string s1 = "abbaca";
    cout << obj.removeDuplicates(s1) << endl; // Output: "ca"

    string s2 = "azxxzy";
    cout << obj.removeDuplicates(s2) << endl; // Output: "ay"

    return 0;
}
