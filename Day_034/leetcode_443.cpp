#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
================================================================================
LeetCode 443: String Compression
================================================================================
🔹 Problem Description:
Given an array of characters `chars`, compress it using the following algorithm:
1. If a group's length is 1, append the character as is.
2. If a group's length is more than 1, append the character followed by the group's length.
3. The compressed string should overwrite the input array.
4. Return the new length of the array after compression.

--------------------------------------------------------------------------------
Examples:
Input:  chars = ["a","a","b","b","c","c","c"]
Output: 6, chars = ["a","2","b","2","c","3"]

Input:  chars = ["a"]
Output: 1, chars = ["a"]

================================================================================
✨ Beginner Friendly Explanation:
- We use **two pointers**:
  1. `read` pointer → scans the original array.
  2. `write` pointer → writes compressed characters in-place.
- Count consecutive occurrences of each character.
- If count > 1, convert it to string and write digits one by one.
- Return the `write` pointer as the new length of compressed array.

⏱ Time Complexity: O(n) where n = length of chars
📦 Space Complexity: O(1) - in-place modification, no extra arrays
================================================================================
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;  // Position to write compressed characters
        int read = 0;   // Position to read characters

        while (read < chars.size()) {
            char current = chars[read];  // Current character
            int count = 0;

            // Count occurrences of the current character
            while (read < chars.size() && chars[read] == current) {
                read++;
                count++;
            }

            // Write the character
            chars[write++] = current;

            // Write count if greater than 1
            if (count > 1) {
                string countStr = to_string(count);  // Convert count to string
                for (char c : countStr) {
                    chars[write++] = c;  // Write each digit
                }
            }
        }

        return write;  // New length of compressed array
    }
};

// ==================== Driver Code for Testing ====================
int main() {
    Solution obj;

    vector<char> chars1 = {'a','a','b','b','c','c','c'};
    int len1 = obj.compress(chars1);
    cout << "Compressed Length: " << len1 << "\nCompressed Array: ";
    for (int i = 0; i < len1; i++) cout << chars1[i] << " ";
    cout << endl;

    vector<char> chars2 = {'a'};
    int len2 = obj.compress(chars2);
    cout << "Compressed Length: " << len2 << "\nCompressed Array: ";
    for (int i = 0; i < len2; i++) cout << chars2[i] << " ";
    cout << endl;

    vector<char> chars3 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    int len3 = obj.compress(chars3);
    cout << "Compressed Length: " << len3 << "\nCompressed Array: ";
    for (int i = 0; i < len3; i++) cout << chars3[i] << " ";
    cout << endl;

    return 0;
}
