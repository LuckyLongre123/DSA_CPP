#include <vector>
#include <string>
using namespace std;

/*
================================================================================
LeetCode 443: String Compression
================================================================================
🔹 Problem Description:
Given an array of characters chars, compress it using the following algorithm:
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

Input:  chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: 4, chars = ["a","b","1","2"]

================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 Idea: Two-Pointer In-Place Compression
1. Use read pointer to traverse and count consecutive characters.
2. Use write pointer to build compressed result in the same array.
3. For each group: write character, then write count digits if count > 1.
4. Return write position as new array length.

⏱ Time Complexity: O(n)
   - Single pass through array
   - Each character processed exactly once
📦 Space Complexity: O(1) (in-place modification)
================================================================================
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        // Step 1: Initialize two pointers for in-place compression
        int write = 0;  // Position to write compressed characters
        int read = 0;   // Position to read and count characters

        // Step 2: Process each group of consecutive characters
        while (read < chars.size()) {
            char current = chars[read];  // Store current character
            int count = 0;               // Count consecutive occurrences

            // Count all consecutive occurrences of current character
            while (read < chars.size() && chars[read] == current) {
                read++;
                count++;
            }

            // Step 3: Write the character to compressed position
            chars[write++] = current;

            // Step 4: Write count digits if count > 1
            if (count > 1) {
                string countStr = to_string(count);  // Convert count to string
                for (char digit : countStr) {
                    chars[write++] = digit;  // Write each digit separately
                }
            }
        }

        // Step 5: Return new length of compressed array
        return write;
    }
};

// ==================== Driver Code for Testing ====================
#include <iostream>
int main() {
    Solution obj;

    // Test Case 1: Basic compression
    vector<char> chars1 = {'a','a','b','b','c','c','c'};
    int len1 = obj.compress(chars1);
    cout << "Test 1 - Length: " << len1 << ", Array: ";
    for (int i = 0; i < len1; i++) cout << chars1[i] << " ";
    cout << endl;  // Expected: a 2 b 2 c 3

    // Test Case 2: Single character
    vector<char> chars2 = {'a'};
    int len2 = obj.compress(chars2);
    cout << "Test 2 - Length: " << len2 << ", Array: ";
    for (int i = 0; i < len2; i++) cout << chars2[i] << " ";
    cout << endl;  // Expected: a

    // Test Case 3: Double-digit count
    vector<char> chars3 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    int len3 = obj.compress(chars3);
    cout << "Test 3 - Length: " << len3 << ", Array: ";
    for (int i = 0; i < len3; i++) cout << chars3[i] << " ";
    cout << endl;  // Expected: a b 1 2

    // Test Case 4: No compression needed
    vector<char> chars4 = {'a','b','c'};
    int len4 = obj.compress(chars4);
    cout << "Test 4 - Length: " << len4 << ", Array: ";
    for (int i = 0; i < len4; i++) cout << chars4[i] << " ";
    cout << endl;  // Expected: a b c

    return 0;
}
