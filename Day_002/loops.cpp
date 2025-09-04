/*
 * Day 2: Loops in C++
 * This file demonstrates all types of loops and loop control
 * Loops are essential for repeating tasks efficiently
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "=== Loops Practice in C++ ===" << endl;
    
    /*
     * SECTION 1: for loop
     * Best when you know exactly how many times to repeat
     * Syntax: for(initialization; condition; increment/decrement)
     */
    
    cout << "\n=== For Loop Examples ===" << endl;
    
    // Basic counting
    cout << "Counting from 1 to 5:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    // Counting backwards
    cout << "Countdown from 5 to 1:" << endl;
    for (int i = 5; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;
    
    // Even numbers
    cout << "Even numbers from 2 to 10:" << endl;
    for (int i = 2; i <= 10; i += 2) {  // i += 2 means i = i + 2
        cout << i << " ";
    }
    cout << endl;
    
    /*
     * SECTION 2: while loop
     * Best when you don't know exactly how many iterations
     * Continues while condition is true
     */
    
    cout << "\n=== While Loop Examples ===" << endl;
    
    // Basic while loop
    int count = 1;
    cout << "While loop counting 1 to 3:" << endl;
    while (count <= 3) {
        cout << "Count: " << count << endl;
        count++;  // Very important! Must change the condition variable
    }
    
    // User input validation
    int userChoice;
    cout << "\nEnter a number between 1 and 10: ";
    cin >> userChoice;
    
    while (userChoice < 1 || userChoice > 10) {
        cout << "Invalid! Please enter a number between 1 and 10: ";
        cin >> userChoice;
    }
    cout << "Thank you! You entered: " << userChoice << endl;
    
    /*
     * SECTION 3: do-while loop
     * Executes at least once, then checks condition
     * Good for menus and input validation
     */
    
    cout << "\n=== Do-While Loop Examples ===" << endl;
    
    char continueChoice;
    int number = 1;
    
    do {
        cout << "Current number: " << number << endl;
        number++;
        cout << "Continue? (y/n): ";
        cin >> continueChoice;
    } while (continueChoice == 'y' || continueChoice == 'Y');
    
    /*
     * SECTION 4: Nested loops
     * Loops inside other loops - very powerful!
     */
    
    cout << "\n=== Nested Loops Examples ===" << endl;
    
    // Multiplication table
    cout << "Multiplication table (1-3):" << endl;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cout << i << " x " << j << " = " << (i * j) << "\t";
        }
        cout << endl;  // New line after each row
    }
    
    // Pattern printing
    cout << "\nStar pattern:" << endl;
    for (int row = 1; row <= 4; row++) {
        for (int col = 1; col <= row; col++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    /*
     * SECTION 5: break and continue statements
     * break: Exit the loop immediately
     * continue: Skip current iteration, go to next
     */
    
    cout << "\n=== Break and Continue Examples ===" << endl;
    
    // break example
    cout << "Numbers 1 to 10, but stop at 6:" << endl;
    for (int i = 1; i <= 10; i++) {
        if (i == 6) {
            break;  // Exit the loop when i equals 6
        }
        cout << i << " ";
    }
    cout << endl;
    
    // continue example
    cout << "Numbers 1 to 10, but skip 5:" << endl;
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            continue;  // Skip the rest of this iteration
        }
        cout << i << " ";
    }
    cout << endl;
    
    // Skip even numbers
    cout << "Odd numbers from 1 to 10:" << endl;
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {  // % is modulus operator (remainder)
            continue;  // Skip even numbers
        }
        cout << i << " ";
    }
    cout << endl;
    
    /*
     * SECTION 6: Practical loop applications
     */
    
    cout << "\n=== Practical Applications ===" << endl;
    
    // Sum of numbers
    int sum = 0;
    cout << "Sum of numbers 1 to 5:" << endl;
    for (int i = 1; i <= 5; i++) {
        sum += i;  // sum = sum + i
        cout << "Adding " << i << ", sum = " << sum << endl;
    }
    
    // Factorial calculation
    int n = 5;
    int factorial = 1;
    cout << "\nFactorial of " << n << ":" << endl;
    for (int i = 1; i <= n; i++) {
        factorial *= i;  // factorial = factorial * i
        cout << i << "! = " << factorial << endl;
    }
    
    // Finding maximum in a series
    cout << "\nEnter 3 numbers to find maximum:" << endl;
    int max = 0;
    for (int i = 1; i <= 3; i++) {
        int num;
        cout << "Enter number " << i << ": ";
        cin >> num;
        if (i == 1 || num > max) {  // First number or greater than current max
            max = num;
        }
    }
    cout << "Maximum number is: " << max << endl;
    
    /*
     * SECTION 7: Infinite loop prevention
     * Always make sure your loops can end!
     */
    
    cout << "\n=== Loop Safety Demo ===" << endl;
    
    // Safe loop with counter
    int attempts = 0;
    int target = 7;
    int guess;
    
    cout << "Guess a number between 1-10 (target is 7):" << endl;
    while (attempts < 3) {  // Limit attempts to prevent infinite loop
        cout << "Attempt " << (attempts + 1) << ": ";
        cin >> guess;
        
        if (guess == target) {
            cout << "Correct! You found it!" << endl;
            break;
        } else {
            cout << "Wrong! Try again." << endl;
        }
        attempts++;
    }
    
    if (attempts == 3 && guess != target) {
        cout << "Sorry, you've used all attempts. The number was " << target << endl;
    }
    
    cout << "\n=== Loops Practice Complete! ===" << endl;
    
    return 0;
}

/*
 * LOOP TYPES SUMMARY:
 * 
 * 1. for loop: for(init; condition; increment)
 *    - Best when you know iteration count
 *    - Common for counting and arrays
 * 
 * 2. while loop: while(condition)
 *    - Best for condition-based repetition
 *    - Good for input validation
 * 
 * 3. do-while loop: do { } while(condition)
 *    - Executes at least once
 *    - Good for menus and user interaction
 * 
 * LOOP CONTROL:
 * - break: Exit loop immediately
 * - continue: Skip to next iteration
 * 
 * IMPORTANT REMINDERS:
 * - Always ensure loop condition can become false
 * - Initialize loop variables properly
 * - Be careful with infinite loops
 * - Use meaningful variable names (i, j, k for simple counters)
 * - Indent nested loops properly for readability
 * 
 * COMMON MISTAKES:
 * - Forgetting to increment/decrement loop variable
 * - Off-by-one errors (< vs <=)
 * - Modifying loop variable incorrectly inside loop
 * - Not handling edge cases in while loops
 */
