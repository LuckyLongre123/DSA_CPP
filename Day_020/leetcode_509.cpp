/**
 * ================================================================================
 * 🌀 LeetCode 509: Fibonacci Number - Iterative DP Solution
 * ================================================================================
 * 
 * 🎯 Problem:
 *   The Fibonacci numbers are defined as:
 *   - F(0) = 0
 *   - F(1) = 1
 *   - For n > 1 → F(n) = F(n - 1) + F(n - 2)
 * 
 *   Given an integer `n`, return F(n).
 * 
 * 📝 Approach: Iterative Dynamic Programming
 * 1. Handle base cases → return 0 if n == 0, return 1 if n == 1
 * 2. Use two variables to keep track of last two Fibonacci numbers
 * 3. Loop from 2 → n and compute current = prev1 + prev2
 * 4. Return the final computed number
 * 
 * ⚡ Time Complexity: O(n) - loop runs n-1 times
 * 💾 Space Complexity: O(1) - only a few variables are used
 * 
 * 🧠 Key Insight:
 *   - Instead of storing all Fibonacci numbers, just store last two
 *   - Saves space from O(n) → O(1)
 * 
 * 🚀 Optimizations:
 *   - This iterative DP method is better than recursion (no repeated work)
 *   - Recursive solution has exponential complexity, while this is linear
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 #include <string>
 using namespace std;
 
 class Solution {
 public:
     //! MAIN FUNCTION: Computes the nth Fibonacci number
     //! @param n Index of Fibonacci sequence (0 ≤ n ≤ 30)
     //! @return F(n)
     int fib(int n) {
         // ! Base cases
         if (n == 0) return 0;
         if (n == 1) return 1;
 
         // * Variables to store previous two results
         int prev2 = 0;   //? F(i-2)
         int prev1 = 1;   //? F(i-1)
         int curr = 0;    //? F(i)
 
         //? Iteratively calculate Fibonacci
         for (int i = 2; i <= n; i++) {
             curr = prev1 + prev2;  //? Current Fibonacci number
             prev2 = prev1;         // * Update F(i-2)
             prev1 = curr;          // * Update F(i-1)
         }
 
         //! Return F(n)
         return curr;
     }
 };
 
 // ============================================================
 // 🧪 TESTING SUITE - Verifies solution with sample test cases
 // ============================================================
 
 void printTestResult(int n, int result, int expected) {
     cout << "\n🔍 Input: n = " << n << "\n";
     cout << "   Output:   " << result << "\n";
     cout << "   Expected: " << expected << "\n";
     cout << "   Status:   " << (result == expected ? "✅ PASS" : "❌ FAIL");
     if (result != expected) {
         cout << " (Expected: " << expected << ")";
     }
     cout << "\n";
 }
 
 int main() {
     Solution obj;
 
     // Test Case 1
     {
         int n = 2;
         int result = obj.fib(n);
         printTestResult(n, result, 1);
     }
 
     // Test Case 2
     {
         int n = 3;
         int result = obj.fib(n);
         printTestResult(n, result, 2);
     }
 
     // Test Case 3
     {
         int n = 4;
         int result = obj.fib(n);
         printTestResult(n, result, 3);
     }
 
     // Test Case 4: Edge case n=0
     {
         int n = 0;
         int result = obj.fib(n);
         printTestResult(n, result, 0);
     }
 
     // Test Case 5: Edge case n=1
     {
         int n = 1;
         int result = obj.fib(n);
         printTestResult(n, result, 1);
     }
 
     return 0;
 }
 
 /*
  * ================================================================================
  * 📝 Additional Notes:
  * - Recursive solution (fib(n-1) + fib(n-2)) is very slow (O(2^n))
  * - This iterative DP solution is optimal for small n (≤ 30 as per constraints)
  * - Can be extended for larger n with matrix exponentiation or fast doubling
  * ================================================================================
  */
 