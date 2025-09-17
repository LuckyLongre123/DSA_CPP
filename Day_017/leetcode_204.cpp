#include <iostream>
#include <vector>
using namespace std;

/* 
================================================================================
LeetCode Problem 204: Count Primes
================================================================================
Given an integer `n`, return the number of prime numbers that are strictly 
less than `n`.

--------------------------------------------------------------------------------
Example 1:
Input: n = 10
Output: 4
Explanation: Prime numbers < 10 are [2, 3, 5, 7].

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0

--------------------------------------------------------------------------------
Constraints:
* 0 <= n <= 5 * 10^6
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
We want to count how many prime numbers are smaller than `n`.

⚡ Trick: Use **Sieve of Eratosthenes** algorithm
Steps:
1. Assume all numbers are prime initially.
2. Mark 0 and 1 as not prime.
3. For each number i starting from 2:
   - If it's still marked as prime,
   - Mark all multiples of i as not prime (because they can't be prime).
4. Finally, count how many are still prime.

⏱ Time Complexity: O(n log log n)  
📦 Space Complexity: O(n)
================================================================================
*/

class Solution {
public:
    int countPrimes(int n) {
        // ! Base case: no primes below 2
        if (n <= 2) return 0;

        // * Create a boolean array to mark prime numbers
        vector<bool> isPrime(n, true);

        // ! 0 and 1 are not prime
        isPrime[0] = isPrime[1] = false;

        // * Main sieve process
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                // ? Mark multiples of i as non-prime
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // * Count numbers still marked as prime
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }

        return count;
    }
};

int main() {
    Solution obj;

    // * Example 1
    int n1 = 10;
    cout << "Input: " << n1 << " → Count of primes = " 
         << obj.countPrimes(n1) << endl;

    // * Example 2
    int n2 = 0;
    cout << "Input: " << n2 << " → Count of primes = " 
         << obj.countPrimes(n2) << endl;

    // * Example 3
    int n3 = 1;
    cout << "Input: " << n3 << " → Count of primes = " 
         << obj.countPrimes(n3) << endl;

    return 0;
}
