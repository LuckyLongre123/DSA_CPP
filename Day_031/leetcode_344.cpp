// LeetCode Problem 344: Reverse String
// Write a function that reverses a string. The input string is given as an array of characters s.
// You must do this by modifying the input array in-place with O(1) extra memory.
// Example 1: Input: s = ["h","e","l","l","o"], Output: ["o","l","l","e","h"]
// Example 2: Input: s = ["H","a","n","n","a","h"], Output: ["h","a","n","n","a","H"]

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        // Function to reverse string in-place using two pointers approach
        void reverseString(vector<char>& s) {
            int a = 0;                    // Left pointer starting from beginning
            int b = s.size() - 1;         // Right pointer starting from end
    
            // Swap characters from both ends moving towards center
            while (a < b) {
                swap(s[a], s[b]);         // Swap characters at positions a and b
                a++;                      // Move left pointer right
                b--;                      // Move right pointer left
            }
            // When a >= b, we've reached the center and string is fully reversed
        }
    };