/**
 * ================================================================================
 * LeetCode 2094: Finding Three-Digit Even Numbers - Array Permutation
 * ================================================================================
 * 
 * ! Problem: Given an integer array `digits`, return all unique three-digit even
 * ! integers that can be formed using digits from the array. Each digit can be 
 * ! used at most once per integer. Return the answer in ascending sorted order.
 * 
 * * Approach:
 * * 1. Use three nested loops to generate all possible three-digit combinations
 * * 2. For each combination, check if indices are different (no reuse)
 * * 3. Ensure first digit is not zero (must be three-digit number)
 * * 4. Ensure last digit is even (number must be even)
 * * 5. Store valid numbers in a set to maintain uniqueness and sorting
 * * 6. Convert set to vector and return
 * 
 * ? Time Complexity: O(n³ + m log m) - n³ for triple loop, m log m for set operations
 * ? Space Complexity: O(m) - m is the number of unique valid numbers (max 450)
 * 
 * TODO Key Insight: 
 * *    - Using a set automatically handles duplicates and maintains sorted order
 * *    - The constraint checks (d1 != 0, d3 % 2 == 0, distinct indices) filter invalid combinations
 * *    - Three-digit range: [100, 999], but only even numbers are valid
 * 
 * * Optimizations: 
 * *    - Set provides automatic deduplication and sorting
 * *    - Early termination on constraint violations
 * *    - Simple index-based permutation generation
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * Finds all unique three-digit even numbers from given digits
     * @param digits Array of single digits (0-9) to form numbers from
     * @return Vector of all valid three-digit even numbers in sorted order
     */
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> st;  // * Automatically maintains uniqueness and sorted order
        
        int n = digits.size();  // * Total number of available digits
        
        // * Triple nested loop: try every possible combination of three positions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    // ! Constraint 1: Each digit position must use different array index
                    if (i == j || j == k || i == k) {
                        continue;  // * Skip if any indices are the same
                    }
                    
                    // * Extract the three digits for this combination
                    int d1 = digits[i];  // * Hundreds place
                    int d2 = digits[j];  // * Tens place
                    int d3 = digits[k];  // * Units place
                    
                    // ! Constraint 2: First digit cannot be zero (must be 3-digit number)
                    if (d1 == 0) {
                        continue;  // * Would create a 2-digit number like 012 = 12
                    }
                    
                    // ! Constraint 3: Last digit must be even (number must be even)
                    if (d3 % 2 != 0) {
                        continue;  // * Odd last digit makes entire number odd
                    }
                    
                    // * Build the three-digit number
                    int num = d1 * 100 + d2 * 10 + d3;
                    
                    // * Add to set (automatically handles duplicates and sorting)
                    st.insert(num);
                }
            }
        }
        
        // * Convert set to vector for return (maintains sorted order)
        return vector<int>(st.begin(), st.end());
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(vector<int>& digits, vector<int> result, vector<int> expected) {
    cout << "\ndigits = [";
    for (int i = 0; i < digits.size(); i++) {
        cout << digits[i];
        if (i < digits.size() - 1) cout << ", ";
    }
    cout << "]\n";
    
    cout << "   Result:   [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]\n";
    
    cout << "   Expected: [";
    for (int i = 0; i < expected.size(); i++) {
        cout << expected[i];
        if (i < expected.size() - 1) cout << ", ";
    }
    cout << "]\n";
    
    bool match = (result.size() == expected.size());
    if (match) {
        for (int i = 0; i < result.size(); i++) {
            if (result[i] != expected[i]) {
                match = false;
                break;
            }
        }
    }
    
    cout << "   Status:   " << (match ? "PASS ✓" : "FAIL ✗") << "\n";
    cout << "   Count:    " << result.size() << " numbers found\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Basic case with multiple valid combinations
    {
        vector<int> digits = {2, 1, 3, 0};
        vector<int> result = solution.findEvenNumbers(digits);
        vector<int> expected = {102, 120, 130, 132, 210, 230, 302, 310, 312, 320};
        printTestResult(digits, result, expected);
    }
    
    // * Test Case 2: Limited digits creating fewer combinations
    {
        vector<int> digits = {2, 2, 8, 8, 2};
        vector<int> result = solution.findEvenNumbers(digits);
        vector<int> expected = {222, 228, 282, 288, 822, 828, 882};
        printTestResult(digits, result, expected);
    }
    
    // * Test Case 3: Includes zero in middle/end positions
    {
        vector<int> digits = {3, 7, 5, 0};
        vector<int> result = solution.findEvenNumbers(digits);
        vector<int> expected = {350, 370, 530, 730, 750};
        printTestResult(digits, result, expected);
    }
    
    // ! Test Case 4: All odd digits - no valid even numbers possible
    {
        vector<int> digits = {1, 3, 5};
        vector<int> result = solution.findEvenNumbers(digits);
        vector<int> expected = {};
        printTestResult(digits, result, expected);
    }
    
    // * Test Case 5: All even digits
    {
        vector<int> digits = {2, 4, 6};
        vector<int> result = solution.findEvenNumbers(digits);
        vector<int> expected = {242, 246, 264, 268, 424, 426, 462, 468, 624, 628, 642, 648};
        printTestResult(digits, result, expected);
    }
    
    // * Test Case 6: Contains multiple zeros
    {
        vector<int> digits = {0, 0, 1, 2};
        vector<int> result = solution.findEvenNumbers(digits);
        vector<int> expected = {100, 102, 120, 200, 210};
        printTestResult(digits, result, expected);
    }
    
    // * Test Case 7: Minimum input size (exactly 3 digits)
    {
        vector<int> digits = {1, 2, 3};
        vector<int> result = solution.findEvenNumbers(digits);
        vector<int> expected = {132, 312};
        printTestResult(digits, result, expected);
    }
    
    // * Test Case 8: Duplicate digits creating same numbers
    {
        vector<int> digits = {1, 1, 2, 2};
        vector<int> result = solution.findEvenNumbers(digits);
        vector<int> expected = {112, 122, 212};
        printTestResult(digits, result, expected);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The set data structure is key: O(log m) insertion, automatic sorting
 * ! - Maximum possible valid numbers: 450 (900 three-digit numbers, half are even)
 * * - The algorithm explores all n³ combinations but filters efficiently
 * ? - Alternative approach: Frequency counting could reduce time to O(1000)
 * * - For larger n, consider optimization with digit frequency map
 * ================================================================================
 */