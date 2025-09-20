#include <string>
using namespace std;

/*
================================================================================
LeetCode 1910: Remove All Occurrences of a Substring
================================================================================
🔹 Problem Description:
Given two strings s and part, remove **all occurrences** of part from s and return
the resulting string.

--------------------------------------------------------------------------------
Examples:
Input:  s = "daabcbaabcbc", part = "abc"
Output: "dab"

Input:  s = "axxxxyyyyb", part = "xy"
Output: "ab"

================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 Idea: Iterative Search & Remove
1. Use string::find() to locate the first occurrence of "part" in s.
2. If found, remove it using string::erase().
3. Repeat until no more occurrences exist.
4. Return the modified string.

⏱ Time Complexity: O(n * m * k)
   - n = length of s
   - m = length of part
   - k = number of occurrences
📦 Space Complexity: O(1) (in-place modification)
================================================================================
*/

class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Step 1: Find first occurrence of 'part' in s
        size_t pos = s.find(part);

        // Step 2: Loop until no more occurrences are found
        while (pos != string::npos) {
            // Remove substring starting at 'pos' of length 'part.size()'
            s.erase(pos, part.size());

            // Search again from beginning, since removal may create new occurrences
            pos = s.find(part);
        }

        // Step 3: Return the modified string
        return s;
    }
};

// ==================== Driver Code for Testing ====================
#include <iostream>
int main() {
    Solution obj;

    string s1 = "daabcbaabcbc", part1 = "abc";
    cout << obj.removeOccurrences(s1, part1) << endl;  // Output: "dab"

    string s2 = "axxxxyyyyb", part2 = "xy";
    cout << obj.removeOccurrences(s2, part2) << endl;  // Output: "ab"

    string s3 = "aababaab", part3 = "ab";
    cout << obj.removeOccurrences(s3, part3) << endl;  // Output: "a"

    return 0;
}
