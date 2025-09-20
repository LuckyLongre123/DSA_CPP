/**
 * ================================================================================
 * 🌀 LeetCode 204: Count Primes - Sieve of Eratosthenes Implementation
 * ================================================================================
 * 
 * 🎯 Problem: Given an integer `n`, return the number of prime numbers that are 
 * strictly less than `n`.
 * 
 * 📝 Approach: Sieve of Eratosthenes Algorithm
 * 1. Create a boolean array `isPrime` of size `n`, initialized to `true`
 * 2. Mark 0 and 1 as not prime (base cases)
 * 3. For each number `i` from 2 to sqrt(n):
 *    - If `i` is still marked as prime, mark all its multiples as not prime
 * 4. Count the number of `true` values in the `isPrime` array
 * 
 * ⚡ Time Complexity: O(n log log n) - The inner loop runs for n/2 + n/3 + n/5 + ...
 * 💾 Space Complexity: O(n) - To store the prime status of each number up to n
 * 
 * 🧠 Key Insight: 
 *    - The Sieve of Eratosthenes efficiently eliminates non-prime numbers
 *    - We only need to check up to sqrt(n) since any composite number has a factor ≤ sqrt(n)
 *    - Multiples of each prime can be marked starting from i² (optimization)
 * 
 * 🚀 Optimizations: 
 *    - Only check up to sqrt(n)
 *    - Start marking multiples from i²
 *    - Use vector<bool> for space efficiency (specialization that uses bits)
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    //! MAIN FUNCTION: Counts the number of prime numbers less than n
    //! @param n The upper bound (exclusive)
    //! @return The count of prime numbers less than n
    int countPrimes(int n) {
        //? Handle edge cases: 0, 1, and 2 have no primes less than them
        if (n <= 2) return 0;
        
        //? Initialize a boolean array where index represents the number
        //? and value represents if the number is prime
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;  // 0 and 1 are not prime
        
        //? Sieve of Eratosthenes algorithm
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                //? Mark all multiples of i as non-prime, starting from i²
                //? (smaller multiples would have already been marked by smaller primes)
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        //? Count the number of primes
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }
        
        return count;
    }
    
    //! ALTERNATIVE: Optimized Sieve with early termination (for reference)
    //! Time: O(n log log n), Space: O(n)
    int countPrimesOptimized(int n) {
        if (n <= 2) return 0;
        
        vector<bool> isPrime(n, true);
        int count = n - 2;  // All numbers from 2 to n-1 initially assumed prime
        
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    if (isPrime[j]) {  // Only decrement if not already marked
                        isPrime[j] = false;
                        count--;
                    }
                }
            }
        }
        
        return count;
    }
};

// ============================================================
// 🧪 TESTING SUITE - Verifies solution with various test cases
// ============================================================================

//! Helper function to print test results
void printTestResult(int n, int result, int expected) {
    cout << "\n🔍 n = " << n << "\n";
    cout << "   Result:   " << result << " prime(s) less than " << n << "\n";
    cout << "   Expected: " << expected << " prime(s) less than " << n << "\n";
    cout << "   Status:   " << (result == expected ? "✅ PASS" : "❌ FAIL");
    if (result != expected) {
        cout << " (Expected: " << expected << ")";
    }
    cout << "\n";
}

//! Helper function to print prime numbers (for small n)
void printPrimes(int n) {
    if (n <= 2) {
        cout << "   Primes:   []\n";
        return;
    }
    
    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    cout << "   Primes:   [";
    bool first = true;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            if (!first) cout << ", ";
            cout << i;
            first = false;
        }
    }
    cout << "]\n";
}

int main() {
    Solution solution;
    
    // Test Case 1: Small range with primes
    {
        int n = 10;
        int result = solution.countPrimes(n);
        printTestResult(n, result, 4);
        printPrimes(n);
    }
    
    // Test Case 2: Edge case - n = 0
    {
        int n = 0;
        int result = solution.countPrimes(n);
        printTestResult(n, result, 0);
    }
    
    // Test Case 3: Edge case - n = 1
    {
        int n = 1;
        int result = solution.countPrimes(n);
        printTestResult(n, result, 0);
    }
    
    // Test Case 4: Edge case - n = 2 (first prime)
    {
        int n = 2;
        int result = solution.countPrimes(n);
        printTestResult(n, result, 0);
    }
    
    // Test Case 5: Single prime number
    {
        int n = 3;
        int result = solution.countPrimes(n);
        printTestResult(n, result, 1);
        printPrimes(n);
    }
    
    // Test Case 6: Larger range
    {
        int n = 20;
        int result = solution.countPrimes(n);
        printTestResult(n, result, 8);
        printPrimes(n);
    }
    
    // Test Case 7: Medium-sized input
    {
        int n = 100;
        int result = solution.countPrimes(n);
        printTestResult(n, result, 25);
        // Don't print all primes for larger n to keep output clean
    }
    
    // Test Case 8: Performance test (commented out by default)
    // {
    //     int n = 1000000;  // 1 million
    //     cout << "\n🔍 Performance Test (n = " << n << ")\n";
    //     cout << "   Running countPrimes..." << endl;
    //     int result = solution.countPrimes(n);
    //     cout << "   Result: " << result << " primes less than " << n << "\n";
    //     cout << "   Expected: 78498 primes less than " << n << "\n";
    //     cout << "   Status:   " << (result == 78498 ? "✅ PASS" : "❌ FAIL") << "\n";
    // }
    
    return 0;
}

/*
 * ================================================================================
 * 📝 Additional Notes:
 * - The Sieve of Eratosthenes is one of the most efficient ways to find all primes
 *   smaller than n when n is smaller than about 10 million
 * - For very large n (beyond 10^7), more memory-efficient segmented sieve algorithms
 *   might be more appropriate
 * - The optimized version with early counting can be slightly faster for very large n
 *   as it avoids a second pass through the array
 * ================================================================================
 */
