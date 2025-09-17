#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
================================================================================
LeetCode 567: Permutation in String
================================================================================
🔹 Problem Description:
Given two strings s1 and s2, return true if s2 contains a **permutation** of s1, 
or false otherwise. In other words, check if one of the permutations of s1 is 
a substring of s2.

--------------------------------------------------------------------------------
Examples:
Input:  s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains "ba" which is a permutation of s1.

Input:  s1 = "ab", s2 = "eidboaoo"
Output: false

================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 Idea: Sliding Window + Frequency Map
1. Use two arrays of size 26 to count character frequencies (for lowercase letters)
   - charCountS1: frequency of each character in s1
   - windowCount: frequency of each character in current sliding window of s2
2. Slide a window of length s1.size() over s2:
   - Add the new character coming into the window
   - Remove the character going out of the window
   - Compare the two frequency arrays
3. If at any point the arrays match, a permutation exists → return true.
4. If we finish sliding without matches → return false.

⏱ Time Complexity: O(n) where n = length of s2
📦 Space Complexity: O(1) - fixed arrays of size 26
================================================================================
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();

        // Edge case: s1 cannot be a permutation of a shorter string s2
        if (len1 > len2) return false;

        // Frequency arrays for lowercase letters
        vector<int> charCountS1(26, 0);  // Counts for s1
        vector<int> windowCount(26, 0);  // Counts for current window in s2

        // Initialize frequency arrays for the first window of size len1
        for (int i = 0; i < len1; ++i) {
            charCountS1[s1[i] - 'a']++;
            windowCount[s2[i] - 'a']++;
        }

        // Check if first window is a permutation
        if (charCountS1 == windowCount) return true;

        // Slide window over s2
        for (int i = len1; i < len2; ++i) {
            // Add new character to the window
            windowCount[s2[i] - 'a']++;

            // Remove character going out of the window
            windowCount[s2[i - len1] - 'a']--;

            // Check if current window matches s1
            if (charCountS1 == windowCount) return true;
        }

        // No permutation found
        return false;
    }
};

// ==================== Driver Code for Testing ====================
int main() {
    Solution obj;

    string s1 = "ab", s2 = "eidbaooo";
    cout << boolalpha << obj.checkInclusion(s1, s2) << endl;  // Output: true

    s1 = "ab"; s2 = "eidboaoo";
    cout << boolalpha << obj.checkInclusion(s1, s2) << endl;  // Output: false

    s1 = "adc"; s2 = "dcda";
    cout << boolalpha << obj.checkInclusion(s1, s2) << endl;  // Output: true

    return 0;
}
