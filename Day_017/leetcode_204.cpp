// LeetCode Problem 204: Count Primes
// Count the number of prime numbers less than a non-negative number, n.
// Example 1: Input: n = 10, Output: 4 (primes: 2, 3, 5, 7)
// Example 2: Input: n = 0, Output: 0
// Example 3: Input: n = 1, Output: 0

#include <vector>
using namespace std;

class Solution {
    public:
        // Function to count prime numbers less than n using Sieve of Eratosthenes
        int countPrimes(int n) {
            // Base case: no primes less than 2
            if (n <= 2) return 0;
            
            // Create boolean array to mark prime numbers
            // Initially assume all numbers are prime (true)
            vector<bool> isPrime(n, true);
            
            // 0 and 1 are not prime numbers
            isPrime[0] = isPrime[1] = false;
    
            // Sieve of Eratosthenes algorithm
            // Only need to check up to sqrt(n) because larger factors would have been marked already
            for (int i = 2; i * i < n; ++i) {
                if (isPrime[i]) {  // If i is prime
                    // Mark all multiples of i as non-prime
                    // Start from i*i because smaller multiples already marked by smaller primes
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
    
            // Count remaining prime numbers
            int count = 0;
            for (int i = 2; i < n; ++i) {
                if (isPrime[i]) count++;
            }
    
            return count;
        }
    };