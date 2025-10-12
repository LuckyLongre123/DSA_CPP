/**
 * ================================================================================
 * LeetCode 344: Reverse String - Two Pointers In-Place Modification
 * ================================================================================
 * 
 * ! Problem: Write a function that reverses a string. The input string is given
 * ! as an array of characters s. You must do this by modifying the input array 
 * ! in-place with O(1) extra memory.
 * 
 * * Approach:
 * * 1. Use two-pointer technique with left and right pointers
 * * 2. Swap characters at both ends and move pointers toward center
 * * 3. Continue until pointers meet in the middle
 * 
 * ? Time Complexity: O(n) - Visit each character once (n/2 swaps)
 * ? Space Complexity: O(1) - In-place modification, constant extra space
 * 
 * TODO Key Insight: 
 * *    - Two-pointer technique is optimal for in-place reversal
 * *    - Swap elements from both ends moving toward center
 * *    - No extra space needed - modify array directly
 * 
 * * Optimizations: 
 * *    - Already optimal - can't do better than O(n) time and O(1) space
 * *    - Single pass through half the array
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * Reverses a character array in-place
     * @param s Reference to vector of characters to reverse
     * @return void - modifies input array directly
     */
    void reverseString(vector<char>& s) {
        int a = 0;              // * Left pointer starting from beginning
        int b = s.size() - 1;   // * Right pointer starting from end

        // ! Use two-pointer technique to swap elements
        while (a < b) {
            // * Swap characters at both ends
            swap(s[a], s[b]);
            
            // * Move pointers toward center
            a++;  // * Move left pointer forward
            b--;  // * Move right pointer backward
        }
        // ? When a >= b, we've processed all elements (pointers met in middle)
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print vector
 */
void printVector(const vector<char>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << "'" << v[i] << "'";
        if (i < v.size() - 1) cout << ",";
    }
    cout << "]";
}

/**
 * Helper function to print test result
 */
void printTestResult(vector<char> s, const vector<char>& expected) {
    cout << "\nInput:    ";
    vector<char> original = s;
    printVector(original);
    
    Solution solution;
    solution.reverseString(s);
    
    cout << "\nResult:   ";
    printVector(s);
    cout << "\nExpected: ";
    printVector(expected);
    cout << "\nStatus:   " << (s == expected ? "PASS" : "FAIL") << "\n";
}

int main() {
    // * Test Case 1: Normal string
    {
        vector<char> s = {'h', 'e', 'l', 'l', 'o'};
        vector<char> expected = {'o', 'l', 'l', 'e', 'h'};
        printTestResult(s, expected);
    }
    
    // * Test Case 2: Another normal string
    {
        vector<char> s = {'H', 'a', 'n', 'n', 'a', 'h'};
        vector<char> expected = {'h', 'a', 'n', 'n', 'a', 'H'};
        printTestResult(s, expected);
    }
    
    // * Test Case 3: Single character (edge case)
    {
        vector<char> s = {'a'};
        vector<char> expected = {'a'};
        printTestResult(s, expected);
    }
    
    // * Test Case 4: Two characters
    {
        vector<char> s = {'a', 'b'};
        vector<char> expected = {'b', 'a'};
        printTestResult(s, expected);
    }
    
    // * Test Case 5: Odd length string
    {
        vector<char> s = {'a', 'b', 'c', 'd', 'e'};
        vector<char> expected = {'e', 'd', 'c', 'b', 'a'};
        printTestResult(s, expected);
    }
    
    // * Test Case 6: Even length string
    {
        vector<char> s = {'a', 'b', 'c', 'd'};
        vector<char> expected = {'d', 'c', 'b', 'a'};
        printTestResult(s, expected);
    }
    
    // ! Test Case 7: Palindrome string
    {
        vector<char> s = {'a', 'b', 'b', 'a'};
        vector<char> expected = {'a', 'b', 'b', 'a'};
        printTestResult(s, expected);
    }
    
    // * Test Case 8: All same characters
    {
        vector<char> s = {'a', 'a', 'a', 'a'};
        vector<char> expected = {'a', 'a', 'a', 'a'};
        printTestResult(s, expected);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The solution is optimal with O(n) time and O(1) space complexity
 * ! - In-place modification means we don't create any new data structures
 * * - Two-pointer technique is the standard approach for array reversal
 * ? - Works for any array type, not just characters
 * ================================================================================
 */