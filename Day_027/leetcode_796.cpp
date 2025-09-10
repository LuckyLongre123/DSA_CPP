/*
 * LeetCode 796: Rotate String
 * 
 * Problem Statement:
 * Given two strings s and goal, return true if and only if s can become goal 
 * after some number of shifts on s.
 * 
 * A shift on s consists of moving the leftmost character of s to the rightmost position.
 * For example, if s = "abcde", then it will be "bcdea" after one shift.
 * 
 * Examples:
 * Example 1:
 * Input: s = "abcde", goal = "cdeab"
 * Output: true
 * Explanation: s can become goal after 2 left shifts: "abcde" -> "bcdea" -> "cdeab"
 * 
 * Example 2:
 * Input: s = "abcde", goal = "abced"
 * Output: false
 * Explanation: No amount of shifts can make s equal to goal
 * 
 * Algorithm Explanation:
 * The key insight is that if goal is a rotation of s, then goal must be a substring
 * of s + s (s concatenated with itself).
 * 
 * Why this works:
 * - If we concatenate s with itself, we get all possible rotations of s as substrings
 * - For example: s = "abcde", s + s = "abcdeabcde"
 * - All rotations: "abcde", "bcdea", "cdeab", "deabc", "eabcd" are substrings of "abcdeabcde"
 * 
 * Steps:
 * 1. Check if both strings have the same length (necessary condition)
 * 2. Concatenate s with itself to get all possible rotations
 * 3. Check if goal exists as a substring in the concatenated string
 * 
 * Time Complexity: O(n) where n is the length of the string
 * Space Complexity: O(n) for creating the concatenated string
 * 
 * Edge Cases:
 * - Empty strings: Both empty should return true
 * - Different lengths: Should return false
 * - Same strings: Should return true
 */

#include <string>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        // First check: both strings must have the same length
        // If lengths are different, goal cannot be a rotation of s
        if (s.size() != goal.size()) {
            return false;
        }
        
        // Second check: if goal is a rotation of s, then goal must be
        // a substring of s concatenated with itself (s + s)
        // 
        // Example: s = "abcde"
        // s + s = "abcdeabcde"
        // All rotations of s appear as substrings in s + s:
        // - "abcde" (original)
        // - "bcdea" (1 rotation)
        // - "cdeab" (2 rotations)
        // - "deabc" (3 rotations)
        // - "eabcd" (4 rotations)
        return (s + s).find(goal) != string::npos;
    }
};