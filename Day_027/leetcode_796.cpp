#include <iostream>
#include <string>
using namespace std;

/*
================================================================================
LeetCode 796: Rotate String
================================================================================
🔹 Problem Description:
Given two strings `s` and `goal`, return true if and only if `s` can become `goal` 
after some number of left shifts.

- A left shift moves the leftmost character of `s` to the rightmost position.
- Example: s = "abcde", after one shift → "bcdea"

--------------------------------------------------------------------------------
Example 1:
Input:  s = "abcde", goal = "cdeab"
Output: true
Explanation: 2 shifts: "abcde" -> "bcdea" -> "cdeab"

Example 2:
Input:  s = "abcde", goal = "abced"
Output: false
Explanation: No amount of shifts can make s equal to goal.

Constraints:
* 1 <= s.length, goal.length <= 100
* s and goal consist of lowercase letters.
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 Key Idea: If goal is a rotation of s, then goal is a **substring of s+s**.

Steps:
1. Both strings must have the same length.
2. Concatenate s with itself → all rotations appear as substrings.
3. Check if goal exists as a substring in s+s.

⏱ Time Complexity: O(n)  
📦 Space Complexity: O(n) (for s+s)
================================================================================
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        // ! Step 1: Length check
        if (s.size() != goal.size()) return false;

        // ! Step 2: Concatenate s with itself
        string doubled = s + s;

        // ! Step 3: Check if goal is a substring
        return doubled.find(goal) != string::npos;
    }
};

// ==================== Driver Code for Testing ====================
int main() {
    Solution obj;

    // * Example 1
    string s1 = "abcde", goal1 = "cdeab";
    cout << "Input: s = \"abcde\", goal = \"cdeab\" → Output: "
         << boolalpha << obj.rotateString(s1, goal1) << endl;

    // * Example 2
    string s2 = "abcde", goal2 = "abced";
    cout << "Input: s = \"abcde\", goal = \"abced\" → Output: "
         << boolalpha << obj.rotateString(s2, goal2) << endl;

    // * Example 3 (already same)
    string s3 = "aaaa", goal3 = "aaaa";
    cout << "Input: s = \"aaaa\", goal = \"aaaa\" → Output: "
         << boolalpha << obj.rotateString(s3, goal3) << endl;

    // * Example 4 (different lengths)
    string s4 = "abc", goal4 = "abcd";
    cout << "Input: s = \"abc\", goal = \"abcd\" → Output: "
         << boolalpha << obj.rotateString(s4, goal4) << endl;

    return 0;
}
