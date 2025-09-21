/**
 * ================================================================================
 * 🧮 LeetCode 2894: Divisible and Non-divisible Sums Difference - Mathematical Optimization
 * ================================================================================
 * 
 * 🎯 Problem: You are given positive integers n and m. Define two integers as follows:
 * - num1: The sum of all integers in the range [1, n] that are NOT divisible by m
 * - num2: The sum of all integers in the range [1, n] that ARE divisible by m
 * Return num1 - num2.
 * 
 * 📝 Approach:
 * 1. Calculate total sum of numbers from 1 to n using arithmetic series formula
 * 2. Calculate sum of numbers divisible by m using arithmetic progression
 * 3. Use mathematical relationship: num1 = totalSum - num2
 * 4. Return num1 - num2 = totalSum - 2 * num2
 * 
 * ⚡ Time Complexity: O(1) - Constant time mathematical operations
 * 💾 Space Complexity: O(1) - Constant extra space used
 * 
 * 🧠 Key Insight: 
 *    - Instead of iterating through all numbers, use mathematical formulas
 *    - Arithmetic series: 1+2+...+n = n*(n+1)/2
 *    - Divisible numbers form arithmetic progression: m, 2m, 3m, ..., km where k = n/m
 * 
 * 🚀 Optimizations: 
 *    - Direct mathematical calculation eliminates need for loops
 *    - Handles large values of n efficiently
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    //! MAIN FUNCTION: Calculates difference between non-divisible and divisible sums
    //! @param n The upper bound of the range [1, n]
    //! @param m The divisor to check divisibility
    //! @return The difference (sum of non-divisible) - (sum of divisible)
    int differenceOfSums(int n, int m) {
        //! Calculate total sum of numbers from 1 to n
        //? Using arithmetic series formula: S = n*(n+1)/2
        int totalSum = n * (n + 1) / 2;
        
        //! Find how many numbers are divisible by m in range [1, n]
        //? Numbers divisible by m: m, 2m, 3m, ..., km where k = floor(n/m)
        int divisibleCount = n / m;
        
        //! Calculate sum of all numbers divisible by m
        //? These form arithmetic progression: m + 2m + 3m + ... + km
        //? Factor out m: m * (1 + 2 + 3 + ... + k) = m * k*(k+1)/2
        int divisibleSum = m * (divisibleCount * (divisibleCount + 1)) / 2;
        
        //! Calculate non-divisible sum
        //? num1 = totalSum - divisibleSum
        //? num2 = divisibleSum
        //? Result = num1 - num2 = totalSum - divisibleSum - divisibleSum
        return totalSum - 2 * divisibleSum;
    }
    
    //! ALTERNATIVE: Brute Force Approach (for comparison and verification)
    //! Time: O(n), Space: O(1)
    int differenceOfSumsBruteForce(int n, int m) {
        int num1 = 0;  // Sum of non-divisible numbers
        int num2 = 0;  // Sum of divisible numbers
        
        for (int i = 1; i <= n; i++) {
            if (i % m == 0) {
                num2 += i;  // Divisible by m
            } else {
                num1 += i;  // Not divisible by m
            }
        }
        
        return num1 - num2;
    }
    
    //! HELPER: Validates the mathematical approach against brute force
    //! @param n Upper bound for testing
    //! @param m Divisor for testing
    //! @return True if both methods give same result
    bool validateSolution(int n, int m) {
        return differenceOfSums(n, m) == differenceOfSumsBruteForce(n, m);
    }
};

// ============================================================
// 🧪 TESTING SUITE - Verifies solution with various test cases
// ============================================================

//! Helper function to print test result with detailed breakdown
void printTestResult(int n, int m, int result, int expected) {
    cout << "\n🔍 n = " << n << ", m = " << m << "\n";
    
    // Calculate components for detailed analysis
    int totalSum = n * (n + 1) / 2;
    int divisibleCount = n / m;
    int divisibleSum = m * (divisibleCount * (divisibleCount + 1)) / 2;
    int nonDivisibleSum = totalSum - divisibleSum;
    
    cout << "   Total Sum (1 to " << n << "): " << totalSum << "\n";
    cout << "   Divisible by " << m << " count: " << divisibleCount << "\n";
    cout << "   Divisible sum: " << divisibleSum << "\n";
    cout << "   Non-divisible sum: " << nonDivisibleSum << "\n";
    cout << "   Difference: " << nonDivisibleSum << " - " << divisibleSum << " = " << result << "\n";
    cout << "   Expected: " << expected << "\n";
    cout << "   Status: " << (result == expected ? "✅ PASS" : "❌ FAIL") << "\n";
}

//! Comprehensive test function covering edge cases and various scenarios
void runComprehensiveTests() {
    Solution solution;
    
    cout << "🧪 Running Comprehensive Test Suite for LeetCode 2894\n";
    cout << "=" << string(60, '=') << "\n";
    
    // Test Case 1: Basic example from problem description
    {
        int n = 10, m = 3;
        int result = solution.differenceOfSums(n, m);
        int expected = 19; // Non-divisible: 1+2+4+5+7+8+10 = 37, Divisible: 3+6+9 = 18, Diff: 37-18 = 19
        printTestResult(n, m, result, expected);
        assert(result == expected);
    }
    
    // Test Case 2: Small range
    {
        int n = 5, m = 6;
        int result = solution.differenceOfSums(n, m);
        int expected = 15; // No numbers divisible by 6 in [1,5], so all sum up: 1+2+3+4+5 = 15
        printTestResult(n, m, result, expected);
        assert(result == expected);
    }
    
    // Test Case 3: All numbers divisible
    {
        int n = 6, m = 1;
        int result = solution.differenceOfSums(n, m);
        int expected = -21; // All divisible: 1+2+3+4+5+6 = 21, Non-divisible: 0, Diff: 0-21 = -21
        printTestResult(n, m, result, expected);
        assert(result == expected);
    }
    
    // Test Case 4: Single element
    {
        int n = 1, m = 2;
        int result = solution.differenceOfSums(n, m);
        int expected = 1; // Only 1, not divisible by 2
        printTestResult(n, m, result, expected);
        assert(result == expected);
    }
    
    // Test Case 5: Large numbers
    {
        int n = 1000, m = 7;
        int result = solution.differenceOfSums(n, m);
        // Validate against brute force for correctness
        int bruteForceResult = solution.differenceOfSumsBruteForce(n, m);
        cout << "\n🔍 Large Test: n = " << n << ", m = " << m << "\n";
        cout << "   Optimized result: " << result << "\n";
        cout << "   Brute force result: " << bruteForceResult << "\n";
        cout << "   Status: " << (result == bruteForceResult ? "✅ PASS" : "❌ FAIL") << "\n";
        assert(result == bruteForceResult);
    }
    
    // Test Case 6: Edge case - m equals n
    {
        int n = 15, m = 15;
        int result = solution.differenceOfSums(n, m);
        int totalSum = 15 * 16 / 2; // 120
        int expected = totalSum - 2 * 15; // 120 - 30 = 90
        printTestResult(n, m, result, expected);
        assert(result == expected);
    }
    
    cout << "\n🎉 All tests passed! Solution is correct.\n";
}

//! Performance comparison between optimized and brute force approaches
void performanceComparison() {
    Solution solution;
    
    cout << "\n⚡ Performance Comparison\n";
    cout << "=" << string(30, '=') << "\n";
    
    vector<pair<int, int>> testCases = {
        {100, 3}, {1000, 7}, {10000, 13}, {100000, 17}
    };
    
    for (auto& testCase : testCases) {
        int n = testCase.first;
        int m = testCase.second;
        
        // Both should give same result
        int optimized = solution.differenceOfSums(n, m);
        int bruteForce = solution.differenceOfSumsBruteForce(n, m);
        
        cout << "n = " << n << ", m = " << m << "\n";
        cout << "  Optimized O(1): " << optimized << "\n";
        cout << "  Brute Force O(n): " << bruteForce << "\n";
        cout << "  Match: " << (optimized == bruteForce ? "✅" : "❌") << "\n\n";
        
        assert(optimized == bruteForce);
    }
}

int main() {
    // Run comprehensive test suite
    runComprehensiveTests();
    
    // Performance comparison
    performanceComparison();
    
    // Interactive example
    cout << "\n🎯 Interactive Example:\n";
    Solution solution;
    int n = 10, m = 3;
    
    cout << "Given n = " << n << ", m = " << m << "\n";
    cout << "Numbers from 1 to " << n << ": ";
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << "\n";
    
    cout << "Divisible by " << m << ": ";
    for (int i = 1; i <= n; i++) {
        if (i % m == 0) cout << i << " ";
    }
    cout << "\n";
    
    cout << "Non-divisible by " << m << ": ";
    for (int i = 1; i <= n; i++) {
        if (i % m != 0) cout << i << " ";
    }
    cout << "\n";
    
    int result = solution.differenceOfSums(n, m);
    cout << "Result: " << result << "\n";
    
    return 0;
}

/*
 * ================================================================================
 * 📝 Mathematical Analysis:
 * 
 * For range [1, n] and divisor m:
 * 
 * 1. Total Sum = n*(n+1)/2
 * 
 * 2. Numbers divisible by m: m, 2m, 3m, ..., km where k = floor(n/m)
 *    Sum = m + 2m + 3m + ... + km = m*(1+2+3+...+k) = m*k*(k+1)/2
 * 
 * 3. Numbers not divisible by m: Total - Divisible
 * 
 * 4. Answer = (Total - Divisible) - Divisible = Total - 2*Divisible
 * 
 * Example: n=10, m=3
 * - Total sum: 10*11/2 = 55
 * - Divisible count: 10/3 = 3 (numbers: 3, 6, 9)
 * - Divisible sum: 3*(1+2+3) = 3*6 = 18
 * - Non-divisible sum: 55-18 = 37
 * - Result: 37-18 = 19
 * 
 * Time Complexity: O(1) - constant time arithmetic operations
 * Space Complexity: O(1) - only using a few integer variables
 * ================================================================================
 */