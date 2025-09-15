/*
LeetCode 1910: Remove All Occurrences of a Substring
Problem: Given two strings s and part, remove all occurrences of part from s and return the result.

Key Concepts:
1. String searching using find() method
2. String deletion using erase() method  
3. Iterative removal until no more occurrences exist
4. Understanding string::npos (no position found indicator)

Time Complexity: O(n * m * k) where n = length of s, m = length of part, k = number of occurrences
Space Complexity: O(1) - in-place modification of string s
*/

#include <string>
using namespace std;

class Solution {
    public:
        string removeOccurrences(string s, string part) {
            /*
            Algorithm Approach: Iterative Search and Remove
            
            Step 1: Find the first occurrence of 'part' in string 's'
            Step 2: If found, remove it from the string
            Step 3: Repeat until no more occurrences exist
            Step 4: Return the modified string
            
            Why this works:
            - Each removal might expose new occurrences (overlapping patterns)
            - We need to keep searching from the beginning after each removal
            - string::npos indicates "not found" condition
            */
            
            // Find the first occurrence of 'part' in string 's'
            // find() returns the position of first character of the match
            // Returns string::npos if substring is not found
            size_t pos = s.find(part);
                
            // Continue removing while occurrences exist
            // string::npos is a special value meaning "no position" or "not found"
            // It's typically the largest possible value for size_t type
            while (pos != string::npos) {
                /*
                erase(pos, length) method:
                - pos: starting position to erase from
                - part.size(): number of characters to erase
                - Removes characters from position 'pos' for 'part.size()' length
                - Automatically shifts remaining characters to fill the gap
                */
                s.erase(pos, part.size());
                
                // Search again for next occurrence
                // We start from beginning because removal might create new patterns
                // Example: s="abcabc", part="ca" -> after removing first "ca", 
                // we get "ababc" which might have new "ca" patterns
                pos = s.find(part);
            }
            
            // Return the string with all occurrences of 'part' removed
            return s;
        }
};