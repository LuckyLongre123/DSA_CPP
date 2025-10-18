/**
 * ================================================================================
 * LeetCode 38: Count and Say - String Sequence Generation
 * ================================================================================
 * 
 * ! Problem: The count-and-say sequence is a sequence of digit strings where each 
 * ! term is obtained by describing the previous term. Given a positive integer n, 
 * ! return the nth term of the count-and-say sequence.
 * 
 * * Approach:
 * * 1. Start with base case "1"
 * * 2. For each iteration (n-1 times):
 * *    - Parse current string into (count, character) pairs
 * *    - Convert pairs back to string format: count + character
 * *    - Update current string for next iteration
 * * 3. Return the final string after n-1 transformations
 * 
 * ? Time Complexity: O(n × m) - n iterations, each processing string of length m
 * ? Space Complexity: O(m) - Store current string and temporary pairs
 * 
 * TODO Key Insight: 
 * *    - Each term "reads" the previous term aloud
 * *    - The sequence grows exponentially but follows predictable patterns
 * *    - Run-length encoding is the core technique used
 * *    - Consecutive identical characters are grouped and counted
 * 
 * * Optimizations: 
 * *    - Single pass through string for each iteration
 * *    - Efficient pair-based representation for counting
 * *    - Early termination at n=1
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    /**
     * Converts string to vector of (count, character) pairs
     * 
     * !! Core Function: Implements run-length encoding
     * ? This function groups consecutive identical characters
     * 
     * @param str The input string to parse
     * @return Vector of pairs representing (count, character)
     */
    vector<pair<int, char>> strToPair(string str) {
        vector<pair<int, char>> ans;
        int count = 1;           // * Track consecutive character count
        char c = str[0];         // * Current character being counted
        int l = str.length();
        
        // * Iterate through string, grouping consecutive identical characters
        for (int i = 0; i < l - 1; i++) {
            if (str[i] == str[i + 1]) {
                // ? Same character continues - increment count
                count++;
            } else {
                // ! Character changes - save current group and reset
                ans.push_back({count, c});
                count = 1;
                c = str[i + 1];
            }
        }
        
        // * Don't forget the last group
        ans.push_back({count, c});
        
        return ans;
    }
    
    /**
     * Converts vector of pairs back to count-and-say string
     * 
     * !! Core Function: Implements pair-to-string conversion
     * ? Each pair (count, char) becomes "count" + "char" in output
     * 
     * @param strPair Vector of (count, character) pairs
     * @return String in count-and-say format
     */
    string pairToStr(vector<pair<int, char>> strPair) {
        int s = strPair.size();
        string ans = "";
        
        // * Build string by concatenating count and character for each pair
        for (int i = 0; i < s; i++) {
            // ? Convert count to string, append character
            ans += to_string(strPair[i].first) + strPair[i].second;
        }
        
        return ans;
    }

public:
    /**
     * Generates the nth term of the count-and-say sequence
     * 
     * !! Main Solution Function
     * ? Iteratively builds each term from the previous term
     * 
     * @param n The term number to generate (1-indexed)
     * @return The nth term of the count-and-say sequence
     * 
     * * Algorithm Flow:
     * *   n=1: "1"
     * *   n=2: "11" (one 1)
     * *   n=3: "21" (two 1s)
     * *   n=4: "1211" (one 2, one 1)
     * *   n=5: "111221" (one 1, one 2, two 1s)
     * 
     * ! Edge Cases Handled:
     * !   - Base case n=1 returns immediately
     * !   - Handles sequences of any length
     * !   - Preserves digit ordering
     */
    string countAndSay(int n) {
        // ! Base case: First term is always "1"
        if (n == 1)
            return "1";
        
        string current = "1";  // * Start with first term
        
        // * Generate each subsequent term (n-1 iterations)
        while (--n) {
            // ? Step 1: Parse current string into (count, char) pairs
            vector<pair<int, char>> strPair = strToPair(current);
            
            // ? Step 2: Convert pairs to next term in sequence
            current = pairToStr(strPair);
        }
        
        return current;
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result with sequence visualization
 */
void printTestResult(int n, string result, string expected) {
    cout << "\nn = " << n << "\n";
    cout << "   Result:   \"" << result << "\"\n";
    cout << "   Expected: \"" << expected << "\"\n";
    cout << "   Status:   " << (result == expected ? "✅ PASS" : "❌ FAIL");
    if (result != expected) {
        cout << " (Expected: \"" << expected << "\")";
    }
    cout << "\n";
}

/**
 * Generates sequence progression for visualization
 */
void printSequenceProgression(Solution& solution, int maxN) {
    cout << "\n📊 Count-and-Say Sequence Progression:\n";
    cout << "========================================\n";
    for (int i = 1; i <= maxN; i++) {
        string term = solution.countAndSay(i);
        cout << "n=" << i << ": \"" << term << "\"";
        if (i > 1) {
            cout << " (length: " << term.length() << ")";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    
    cout << "\n🧪 TESTING LEETCODE 38: COUNT AND SAY\n";
    cout << "=====================================\n";
    
    // * Test Case 1: First term (base case)
    {
        int n = 1;
        string result = solution.countAndSay(n);
        printTestResult(n, result, "1");
    }
    
    // * Test Case 2: Second term
    {
        int n = 2;
        string result = solution.countAndSay(n);
        printTestResult(n, result, "11");
    }
    
    // * Test Case 3: Third term
    {
        int n = 3;
        string result = solution.countAndSay(n);
        printTestResult(n, result, "21");
    }
    
    // * Test Case 4: Fourth term
    {
        int n = 4;
        string result = solution.countAndSay(n);
        printTestResult(n, result, "1211");
    }
    
    // * Test Case 5: Fifth term
    {
        int n = 5;
        string result = solution.countAndSay(n);
        printTestResult(n, result, "111221");
    }
    
    // * Test Case 6: Sixth term
    {
        int n = 6;
        string result = solution.countAndSay(n);
        printTestResult(n, result, "312211");
    }
    
    // * Test Case 7: Larger term
    {
        int n = 10;
        string result = solution.countAndSay(n);
        printTestResult(n, result, "13211311123113112211");
    }
    
    // * Visualize sequence progression
    printSequenceProgression(solution, 8);
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The sequence grows exponentially: average growth factor ≈ 1.303577...
 * ! - No digit larger than 3 appears after the first few terms (Conway's Constant)
 * * - The sequence is self-describing: each term describes the previous term
 * ? - This problem demonstrates run-length encoding in action
 * * - The helper functions (strToPair, pairToStr) provide clean separation of concerns
 * ! - Memory usage grows with each iteration but is bounded by sequence properties
 * ================================================================================
 */