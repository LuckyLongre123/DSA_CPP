/*
 * Day 3: Introduction to Recursion in C++
 * This file demonstrates basic recursion concepts
 * Recursion is when a function calls itself to solve a problem
 */

#include <iostream>

using namespace std;

/*
 * Function prototypes
 */
int factorial(int n);
int fibonacci(int n);
int power(int base, int exponent);
void countdown(int n);
void printNumbers(int start, int end);
int sumOfDigits(int number);
int gcd(int a, int b);
void printPattern(int n);

int main() {
    cout << "=== Introduction to Recursion ===" << endl;
    
    /*
     * SECTION 1: Basic Recursion - Factorial
     * n! = n * (n-1) * (n-2) * ... * 1
     * Example: 5! = 5 * 4 * 3 * 2 * 1 = 120
     */
    
    cout << "\n=== Factorial Examples ===" << endl;
    
    for (int i = 0; i <= 6; i++) {
        int result = factorial(i);
        cout << i << "! = " << result << endl;
    }
    
    /*
     * SECTION 2: Fibonacci Sequence
     * Each number is sum of two preceding ones
     * 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
     */
    
    cout << "\n=== Fibonacci Sequence ===" << endl;
    cout << "First 10 Fibonacci numbers:" << endl;
    
    for (int i = 0; i < 10; i++) {
        cout << "F(" << i << ") = " << fibonacci(i) << endl;
    }
    
    /*
     * SECTION 3: Power Function
     * base^exponent using recursion
     */
    
    cout << "\n=== Power Function ===" << endl;
    
    int base = 2;
    for (int exp = 0; exp <= 5; exp++) {
        cout << base << "^" << exp << " = " << power(base, exp) << endl;
    }
    
    /*
     * SECTION 4: Countdown Function
     * Simple recursion for counting down
     */
    
    cout << "\n=== Countdown Demo ===" << endl;
    cout << "Countdown from 5:" << endl;
    countdown(5);
    
    /*
     * SECTION 5: Print Numbers in Range
     * Recursive function to print numbers
     */
    
    cout << "\n=== Print Numbers Range ===" << endl;
    cout << "Numbers from 1 to 5:" << endl;
    printNumbers(1, 5);
    cout << endl;
    
    /*
     * SECTION 6: Sum of Digits
     * Add all digits in a number
     */
    
    cout << "\n=== Sum of Digits ===" << endl;
    
    int numbers[] = {123, 456, 789, 1234};
    for (int i = 0; i < 4; i++) {
        int sum = sumOfDigits(numbers[i]);
        cout << "Sum of digits in " << numbers[i] << " = " << sum << endl;
    }
    
    /*
     * SECTION 7: Greatest Common Divisor (GCD)
     * Using Euclidean algorithm recursively
     */
    
    cout << "\n=== Greatest Common Divisor ===" << endl;
    
    int pairs[][2] = {{48, 18}, {56, 42}, {17, 13}};
    for (int i = 0; i < 3; i++) {
        int result = gcd(pairs[i][0], pairs[i][1]);
        cout << "GCD(" << pairs[i][0] << ", " << pairs[i][1] << ") = " << result << endl;
    }
    
    /*
     * SECTION 8: Pattern Printing
     * Recursive pattern printing
     */
    
    cout << "\n=== Recursive Pattern ===" << endl;
    printPattern(5);
    
    return 0;
}

/*
 * RECURSIVE FUNCTION DEFINITIONS
 */

/*
 * Factorial function using recursion
 * Base case: 0! = 1, 1! = 1
 * Recursive case: n! = n * (n-1)!
 */
int factorial(int n) {
    // Base case - stopping condition
    if (n == 0 || n == 1) {
        return 1;
    }
    
    // Recursive case - function calls itself
    return n * factorial(n - 1);
    
    /*
     * How it works for factorial(5):
     * factorial(5) = 5 * factorial(4)
     * factorial(4) = 4 * factorial(3)
     * factorial(3) = 3 * factorial(2)
     * factorial(2) = 2 * factorial(1)
     * factorial(1) = 1 (base case)
     * 
     * Then it unwinds:
     * factorial(2) = 2 * 1 = 2
     * factorial(3) = 3 * 2 = 6
     * factorial(4) = 4 * 6 = 24
     * factorial(5) = 5 * 24 = 120
     */
}

/*
 * Fibonacci function using recursion
 * Base cases: F(0) = 0, F(1) = 1
 * Recursive case: F(n) = F(n-1) + F(n-2)
 */
int fibonacci(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
    
    /*
     * Note: This is not the most efficient implementation
     * It recalculates the same values multiple times
     * For large n, it becomes very slow
     */
}

/*
 * Power function using recursion
 * Base case: base^0 = 1
 * Recursive case: base^n = base * base^(n-1)
 */
int power(int base, int exponent) {
    // Base case
    if (exponent == 0) {
        return 1;
    }
    
    // Handle negative exponents (simplified)
    if (exponent < 0) {
        return 0;  // For integer division, we'll return 0
    }
    
    // Recursive case
    return base * power(base, exponent - 1);
}

/*
 * Countdown function using recursion
 * Prints numbers from n down to 1
 */
void countdown(int n) {
    // Base case
    if (n <= 0) {
        cout << "Blast off!" << endl;
        return;
    }
    
    // Print current number
    cout << n << "... ";
    
    // Recursive call
    countdown(n - 1);
}

/*
 * Print numbers in range using recursion
 * Prints numbers from start to end
 */
void printNumbers(int start, int end) {
    // Base case
    if (start > end) {
        return;
    }
    
    // Print current number
    cout << start << " ";
    
    // Recursive call
    printNumbers(start + 1, end);
}

/*
 * Sum of digits using recursion
 * Adds all digits in a number
 */
int sumOfDigits(int number) {
    // Base case
    if (number == 0) {
        return 0;
    }
    
    // Recursive case
    // Last digit + sum of remaining digits
    return (number % 10) + sumOfDigits(number / 10);
    
    /*
     * How it works for sumOfDigits(123):
     * sumOfDigits(123) = 3 + sumOfDigits(12)
     * sumOfDigits(12) = 2 + sumOfDigits(1)
     * sumOfDigits(1) = 1 + sumOfDigits(0)
     * sumOfDigits(0) = 0 (base case)
     * 
     * Result: 3 + 2 + 1 + 0 = 6
     */
}

/*
 * Greatest Common Divisor using Euclidean algorithm
 * GCD(a, b) = GCD(b, a % b) when b != 0
 * GCD(a, 0) = a
 */
int gcd(int a, int b) {
    // Base case
    if (b == 0) {
        return a;
    }
    
    // Recursive case
    return gcd(b, a % b);
    
    /*
     * How it works for gcd(48, 18):
     * gcd(48, 18) = gcd(18, 48 % 18) = gcd(18, 12)
     * gcd(18, 12) = gcd(12, 18 % 12) = gcd(12, 6)
     * gcd(12, 6) = gcd(6, 12 % 6) = gcd(6, 0)
     * gcd(6, 0) = 6 (base case)
     */
}

/*
 * Recursive pattern printing
 * Prints a pattern of stars
 */
void printPattern(int n) {
    // Base case
    if (n <= 0) {
        return;
    }
    
    // Print stars for current row
    for (int i = 0; i < n; i++) {
        cout << "* ";
    }
    cout << endl;
    
    // Recursive call for next row
    printPattern(n - 1);
}

/*
 * Alternative recursive functions for practice
 */

/*
 * Check if string is palindrome (reads same forwards and backwards)
 */
bool isPalindrome(string str, int start, int end) {
    // Base case: single character or empty
    if (start >= end) {
        return true;
    }
    
    // Check if first and last characters match
    if (str[start] != str[end]) {
        return false;
    }
    
    // Recursive case: check inner substring
    return isPalindrome(str, start + 1, end - 1);
}

/*
 * Binary search using recursion
 */
int binarySearch(int arr[], int left, int right, int target) {
    // Base case: element not found
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    // Base case: element found
    if (arr[mid] == target) {
        return mid;
    }
    
    // Recursive cases
    if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target);
    } else {
        return binarySearch(arr, mid + 1, right, target);
    }
}

/*
 * KEY RECURSION CONCEPTS:
 * 
 * 1. RECURSION DEFINITION:
 *    - A function that calls itself
 *    - Breaks problem into smaller subproblems
 *    - Each call works on a smaller version of the problem
 * 
 * 2. ESSENTIAL COMPONENTS:
 *    - Base case: Condition to stop recursion
 *    - Recursive case: Function calls itself with modified parameters
 *    - Progress: Each call must move toward the base case
 * 
 * 3. HOW RECURSION WORKS:
 *    - Function calls are stored on the call stack
 *    - Each call waits for the next call to complete
 *    - Results are combined as calls return
 * 
 * 4. ADVANTAGES:
 *    - Clean, elegant solutions for certain problems
 *    - Natural for tree/graph traversal
 *    - Good for divide-and-conquer algorithms
 * 
 * 5. DISADVANTAGES:
 *    - Can be slower than iterative solutions
 *    - Uses more memory (call stack)
 *    - Risk of stack overflow for deep recursion
 * 
 * 6. WHEN TO USE RECURSION:
 *    - Problem can be broken into similar subproblems
 *    - Tree or graph structures
 *    - Mathematical sequences (factorial, fibonacci)
 *    - Backtracking algorithms
 * 
 * COMMON MISTAKES:
 * - Forgetting the base case (infinite recursion)
 * - Base case never reached (no progress)
 * - Too much recursion depth (stack overflow)
 * - Inefficient recursive solutions (like naive fibonacci)
 * 
 * DEBUGGING TIPS:
 * - Add print statements to trace execution
 * - Verify base case is correct
 * - Ensure progress toward base case
 * - Test with small inputs first
 */
