/**
 * ================================================================================
 * 🌀 LeetCode 50: Pow(x, n) - Fast Power (Binary Exponentiation)
 * ================================================================================
 * 
 * 🎯 Problem:
 *   Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
 * 
 * 📝 Approach: Binary Exponentiation (Fast Power)
 * 1. Convert negative exponent → x^(-n) = (1/x)^n
 * 2. Use binary exponentiation to reduce time:
 *    - If n is even → x^n = (x^2)^(n/2)
 *    - If n is odd  → x^n = x * (x^2)^(n/2)
 * 3. Repeat until exponent becomes 0
 * 
 * ⚡ Time Complexity: O(log n) - Exponent halves each step
 * 💾 Space Complexity: O(1) - Iterative implementation, no recursion stack
 * 
 * 🧠 Key Insight:
 *   - Direct multiplication is too slow for large n
 *   - Binary exponentiation makes it logarithmic
 *   - Handle negative powers carefully using long type (for INT_MIN)
 * 
 * 🚀 Optimizations:
 *   - Uses iterative approach (faster & safer than recursion)
 *   - Avoids overflow by casting n to long
 * ================================================================================
 */

 #include <iostream>
 #include <climits>
 using namespace std;
 
 class Solution {
 public:
     //! MAIN FUNCTION: Computes x^n
     //! @param x The base value
     //! @param n The exponent (can be negative)
     //! @return Result of x raised to the power n
     double myPow(double x, int n) {
         long exp = n;   // ! Convert to long to handle edge case (INT_MIN)
 
         // ! If exponent is negative → invert base and make exponent positive
         if (exp < 0) {
             x = 1 / x;
             exp = -exp;
         }
 
         double ans = 1.0;  // * Result initialized to 1
 
         //? Binary Exponentiation loop
         while (exp > 0) {
             if (exp % 2 == 1) {
                 ans *= x;   // * If exponent is odd, multiply answer by base
             }
 
             x *= x;        // * Square the base for next step
             exp /= 2;      // * Reduce exponent by half
         }
 
         //! Final result
         return ans;
     }
 };
 
 // ============================================================
 // 🧪 TESTING SUITE - Verifies solution with sample test cases
 // ============================================================
 
 void printTestResult(double x, int n, double result, double expected) {
     cout << "\n🔍 Input: x = " << x << ", n = " << n << "\n";
     cout << "   Output:   " << result << "\n";
     cout << "   Expected: " << expected << "\n";
     cout << "   Status:   " << (abs(result - expected) < 1e-5 ? "✅ PASS" : "❌ FAIL");
     if (abs(result - expected) >= 1e-5) {
         cout << " (Expected: " << expected << ")";
     }
     cout << "\n";
 }
 
 int main() {
     Solution obj;
 
     // Test Case 1
     {
         double x = 2.0; int n = 10;
         double result = obj.myPow(x, n);
         printTestResult(x, n, result, 1024.0);
     }
 
     // Test Case 2
     {
         double x = 2.1; int n = 3;
         double result = obj.myPow(x, n);
         printTestResult(x, n, result, 9.261);
     }
 
     // Test Case 3
     {
         double x = 2.0; int n = -2;
         double result = obj.myPow(x, n);
         printTestResult(x, n, result, 0.25);
     }
 
     // Test Case 4: Edge case n=0
     {
         double x = 5.0; int n = 0;
         double result = obj.myPow(x, n);
         printTestResult(x, n, result, 1.0);
     }
 
     // Test Case 5: Negative base
     {
         double x = -2.0; int n = 3;
         double result = obj.myPow(x, n);
         printTestResult(x, n, result, -8.0);
     }
 
     return 0;
 }
 
 /*
  * ================================================================================
  * 📝 Additional Notes:
  * - Direct recursion would lead to stack overflow for large n
  * - Using iterative binary exponentiation avoids recursion overhead
  * - Edge cases:
  *    * n = 0 → Always return 1
  *    * n = INT_MIN → Must cast to long to avoid overflow when negating
  * - This solution is optimal and widely used in competitive programming
  * ================================================================================
  */
 