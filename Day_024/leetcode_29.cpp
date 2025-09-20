/**
 * ================================================================================
 * 🌀 LeetCode 29: Divide Two Integers
 * ================================================================================
 * 
 * 🎯 Problem:
 *   Divide two integers `dividend` and `divisor` without using:
 *   - Multiplication (*)
 *   - Division (/)
 *   - Modulo (%)
 * 
 * ⚠️ Rules:
 *   - Truncate result toward zero (ignore decimals).
 *   - If division causes overflow (INT_MIN / -1), return INT_MAX.
 * 
 * 📝 Approach:
 * 1. Handle special cases:
 *    - divisor = 0 → return INT_MAX
 *    - dividend = INT_MIN and divisor = -1 → overflow → return INT_MAX
 * 2. Track sign separately (result is negative if dividend and divisor signs differ).
 * 3. Convert dividend and divisor to positive (long long to avoid overflow).
 * 4. Use **bit manipulation**:
 *    - Repeatedly subtract largest shifted divisor (temp <<= 1).
 *    - Accumulate quotient in result.
 * 5. Apply sign and clamp result into 32-bit integer range.
 * 
 * ⚡ Time Complexity: O(log(dividend))  
 * 💾 Space Complexity: O(1)
 * 
 * 🧠 Key Insight:
 *   Using left shifts to efficiently subtract divisor chunks speeds up the division.
 * ================================================================================
 */

 #include <iostream>
 #include <climits>
 using namespace std;
 
 class Solution {
 public:
     //! FUNCTION: Divide two integers without using *, /, %
     //! @param dividend The numerator
     //! @param divisor  The denominator (non-zero)
     //! @return Quotient truncated toward zero
     int divide(int dividend, int divisor) {
         // ! Edge Case 1: divisor == 0 → undefined, return INT_MAX
         if (divisor == 0) return INT_MAX;
 
         // ! Edge Case 2: Overflow → INT_MIN / -1
         if (dividend == INT_MIN && divisor == -1) return INT_MAX;
 
         // ? Determine sign of result
         bool negative = (dividend < 0) ^ (divisor < 0);
 
         // ? Convert to positive long long for safe calculation
         long long a = llabs((long long)dividend);
         long long b = llabs((long long)divisor);
 
         long long result = 0;
 
         // ? Perform division using subtraction + bit shifting
         while (a >= b) {
             long long temp = b;      // * Current divisor multiple
             long long multiple = 1;  // * Corresponding quotient
 
             // * Keep doubling divisor until it's too large
             while ((temp << 1) <= a) {
                 temp <<= 1;       // Double divisor
                 multiple <<= 1;   // Double multiple
             }
 
             a -= temp;           // - Subtract divisor chunk
             result += multiple;  // + Add multiple to quotient
         }
 
         // ? Apply sign
         if (negative) result = -result;
 
         // ? Clamp within 32-bit signed integer range
         if (result > INT_MAX) return INT_MAX;
         if (result < INT_MIN) return INT_MIN;
 
         return (int)result;
     }
 };
 
 // ============================================================
 // 🧪 TESTING SUITE - Verifies solution with sample test cases
 // ============================================================
 
 void runTest(int dividend, int divisor, int expected) {
     Solution obj;
     int output = obj.divide(dividend, divisor);
 
     cout << "\n🔍 Input: dividend = " << dividend << ", divisor = " << divisor;
     cout << "\n   Output:   " << output;
     cout << "\n   Expected: " << expected;
     cout << "\n   Status:   " << (output == expected ? "✅ PASS" : "❌ FAIL") << "\n";
 }
 
 int main() {
     // Test Case 1
     runTest(10, 3, 3);
 
     // Test Case 2
     runTest(7, -3, -2);
 
     // Test Case 3 (Overflow case)
     runTest(-2147483648, -1, 2147483647);
 
     // Test Case 4 (Negative dividend)
     runTest(-15, 2, -7);
 
     // Test Case 5 (Negative divisor)
     runTest(43, -8, -5);
 
     // Test Case 6 (Both negative)
     runTest(-100, -9, 11);
 
     return 0;
 }
 
 /*
  * ================================================================================
  * 📝 Additional Notes:
  * - Avoids forbidden operators (*, /, %)
  * - Handles overflow safely with 64-bit integers
  * - Efficient log(dividend) approach using bit manipulation
  * ================================================================================
  */
 