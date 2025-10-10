/**
 * ================================================================================
 * LeetCode 204: Count Primes - Sieve of Eratosthenes
 * ================================================================================
 * 
 * ! Problem: Given an integer n, return the number of prime numbers that are 
 * ! strictly less than n.
 * ! 
 * ! A prime number is a natural number greater than 1 that has no positive 
 * ! divisors other than 1 and itself.
 * 
 * * Approach: Sieve of Eratosthenes Algorithm
 * * 1. Create a boolean array of size n, initially all true
 * * 2. Mark 0 and 1 as not prime
 * * 3. For each number i from 2 to √n:
 * *    - If i is still marked as prime
 * *    - Mark all multiples of i (starting from i²) as not prime
 * * 4. Count all numbers still marked as prime
 * 
 * ? Time Complexity: O(n log log n) - Near-linear performance for prime sieving
 * ? Space Complexity: O(n) - Boolean array to track prime status
 * 
 * TODO Key Insight: 
 * *    - Instead of checking each number individually (O(n√n)), we eliminate 
 * *      composites by marking multiples of known primes
 * *    - Start marking from i² because smaller multiples were already marked
 * *    - Only need to check up to √n because larger factors pair with smaller ones
 * 
 * * Optimizations: 
 * *    - Start inner loop from i*i instead of 2*i (smaller multiples already marked)
 * *    - Only iterate outer loop up to √n (mathematical optimization)
 * *    - Use boolean array instead of bitset for simplicity and speed
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    /**
     * Counts the number of prime numbers less than n using Sieve of Eratosthenes
     * @param n The upper bound (exclusive) for counting primes
     * @return The count of prime numbers less than n
     */
    int countPrimes(int n) {
        // ! Edge case: Numbers less than or equal to 2 have no primes less than them
        if (n <= 2) return 0;
        
        // * Create boolean array - initially assume all numbers are prime
        vector<bool> isPrime(n, true);
        
        // * Mark 0 and 1 as not prime (by definition)
        isPrime[0] = isPrime[1] = false;
        
        // ! Main Sieve Algorithm: Mark composites as not prime
        // ? Only need to check up to √n because if n = a*b and a > √n, then b < √n
        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                // * Mark all multiples of i as composite
                // ? Start from i*i because smaller multiples (2*i, 3*i, ..., (i-1)*i) 
                // ? were already marked by smaller primes
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;  // ! This number is composite
                }
            }
        }
        
        // * Count remaining primes
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) count++;
        }
        
        return count;
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(int n, int result, int expected) {
    cout << "\nn = " << n << "\n";
    cout << "   Result:   " << result << " primes\n";
    cout << "   Expected: " << expected << " primes\n";
    cout << "   Status:   " << (result == expected ? "PASS" : "FAIL");
    if (result != expected) {
        cout << " (Expected: " << expected << ")";
    }
    cout << "\n";
}

/**
 * Helper function to print all primes less than n (for verification)
 */
void printPrimes(int n) {
    if (n <= 2) {
        cout << "No primes less than " << n << "\n";
        return;
    }
    
    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i < n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    cout << "Primes less than " << n << ": ";
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) cout << i << " ";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Small number
    {
        int n = 10;
        int result = solution.countPrimes(n);
        printTestResult(n, result, 4);  // Primes: 2, 3, 5, 7
        printPrimes(n);
    }
    
    // * Test Case 2: Zero
    {
        int n = 0;
        int result = solution.countPrimes(n);
        printTestResult(n, result, 0);
    }
    
    // * Test Case 3: One
    {
        int n = 1;
        int result = solution.countPrimes(n);
        printTestResult(n, result, 0);
    }
    
    // * Test Case 4: Two
    {
        int n = 2;
        int result = solution.countPrimes(n);
        printTestResult(n, result, 0);
    }
    
    // * Test Case 5: Three (first prime)
    {
        int n = 3;
        int result = solution.countPrimes(n);
        printTestResult(n, result, 1);  // Prime: 2
        printPrimes(n);
    }
    
    // ! Test Case 6: Larger number
    {
        int n = 100;
        int result = solution.countPrimes(n);
        printTestResult(n, result, 25);  // 25 primes less than 100
        printPrimes(n);
    }
    
    // ! Test Case 7: Even larger number
    {
        int n = 1000;
        int result = solution.countPrimes(n);
        printTestResult(n, result, 168);  // 168 primes less than 1000
    }
    
    // ! Test Case 8: Power of 2
    {
        int n = 256;
        int result = solution.countPrimes(n);
        printTestResult(n, result, 54);  // 54 primes less than 256
    }
    
    // * Test Case 9: Perfect square
    {
        int n = 49;  // 7²
        int result = solution.countPrimes(n);
        printTestResult(n, result, 15);  // Primes: 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47
        printPrimes(n);
    }
    
    // * Test Case 10: Large boundary test
    {
        int n = 5000;
        int result = solution.countPrimes(n);
        printTestResult(n, result, 669);  // 669 primes less than 5000
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The Sieve of Eratosthenes is one of the most efficient algorithms for 
 * *   finding all primes up to a given number
 * ! - The algorithm's efficiency comes from eliminating multiples rather than 
 * !   testing divisibility of each number
 * * - Starting from i² in the inner loop is a crucial optimization that reduces 
 * *   redundant marking operations
 * ? - For very large n, consider segmented sieve or wheel factorization for 
 * ?   further optimization
 * * - The algorithm trades space (O(n)) for time efficiency (O(n log log n))
 * ================================================================================
 */