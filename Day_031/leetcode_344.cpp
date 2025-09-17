#include <vector>
#include <algorithm>
using namespace std;

/*
================================================================================
LeetCode 344: Reverse String
================================================================================
🔹 Problem Description:
Write a function that reverses a string. The input string is given as an array of
characters s. You must reverse the string **in-place** with O(1) extra memory.

--------------------------------------------------------------------------------
Examples:
Input:  s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Input:  s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 Idea: Two-Pointer Swap
1. Use a left pointer (start) and a right pointer (end).
2. Swap characters at left and right pointers.
3. Move pointers towards the center.
4. Stop when pointers meet or cross each other.

⏱ Time Complexity: O(n) → single pass through array
📦 Space Complexity: O(1) → in-place swapping
================================================================================
*/

class Solution {
public:
    // * Reverse string in-place
    void reverseString(vector<char>& s) {
        int a = 0;                 // Left pointer (start of array)
        int b = s.size() - 1;      // Right pointer (end of array)

        // * Swap characters until pointers meet
        while (a < b) {
            swap(s[a], s[b]);      // Swap characters at a and b
            a++;                   // Move left pointer right
            b--;                   // Move right pointer left
        }
        // * After loop ends, string is reversed in-place
    }
};

// ==================== Driver Code for Testing ====================
#include <iostream>
int main() {
    Solution obj;

    vector<char> s1 = {'h','e','l','l','o'};
    obj.reverseString(s1);
    for(char c : s1) cout << c << " ";  // Output: o l l e h
    cout << endl;

    vector<char> s2 = {'H','a','n','n','a','h'};
    obj.reverseString(s2);
    for(char c : s2) cout << c << " ";  // Output: h a n n a H
    cout << endl;

    return 0;
}
