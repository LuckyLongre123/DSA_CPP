/*
 * Day 1: Input/Output Operations in C++
 * This file demonstrates how to get input from user and display output
 * Essential for interactive programs
 */

#include <iostream>
#include <string>
#include <iomanip>  // For formatting output

using namespace std;

int main() {
    cout << "=== C++ Input/Output Practice ===" << endl;
    
    /*
     * SECTION 1: Basic Input/Output
     * cin - for input (from keyboard)
     * cout - for output (to screen)
     */
    
    string firstName, lastName;
    int age;
    
    cout << "\nLet's get to know you!" << endl;
    cout << "Enter your first name: ";
    cin >> firstName;  // Read one word (stops at space)
    
    cout << "Enter your last name: ";
    cin >> lastName;
    
    cout << "Enter your age: ";
    cin >> age;
    
    // Display the information
    cout << "\n--- Your Information ---" << endl;
    cout << "Full Name: " << firstName << " " << lastName << endl;
    cout << "Age: " << age << " years old" << endl;
    
    /*
     * SECTION 2: Reading Full Lines (with spaces)
     * getline() function reads entire line including spaces
     */
    
    cin.ignore(); // Clear the input buffer (important after using cin >>)
    
    string fullAddress;
    cout << "\nEnter your full address: ";
    getline(cin, fullAddress);  // Reads entire line including spaces
    
    cout << "Your address: " << fullAddress << endl;
    
    /*
     * SECTION 3: Multiple Inputs and Calculations
     * Let's create a simple grade calculator
     */
    
    cout << "\n=== Grade Calculator ===" << endl;
    
    double math, science, english;
    cout << "Enter your Math score: ";
    cin >> math;
    
    cout << "Enter your Science score: ";
    cin >> science;
    
    cout << "Enter your English score: ";
    cin >> english;
    
    // Calculate average
    double average = (math + science + english) / 3.0;
    
    cout << "\n--- Grade Report ---" << endl;
    cout << "Math: " << math << endl;
    cout << "Science: " << science << endl;
    cout << "English: " << english << endl;
    cout << fixed << setprecision(2);  // Show 2 decimal places
    cout << "Average: " << average << endl;
    
    /*
     * SECTION 4: Formatted Output
     * Using manipulators to format output nicely
     */
    
    cout << "\n=== Formatted Output Demo ===" << endl;
    
    double price = 19.99;
    int quantity = 5;
    double total = price * quantity;
    
    cout << "Item Price: $" << fixed << setprecision(2) << price << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Total: $" << total << endl;
    
    // Table formatting
    cout << "\n--- Shopping Receipt ---" << endl;
    cout << left << setw(15) << "Item" << setw(10) << "Price" << setw(8) << "Qty" << "Total" << endl;
    cout << string(40, '-') << endl;  // Print 40 dashes
    cout << left << setw(15) << "Widget" << "$" << setw(9) << price << setw(8) << quantity << "$" << total << endl;
    
    /*
     * SECTION 5: Character Input
     * Reading single characters
     */
    
    cout << "\n=== Character Input ===" << endl;
    
    char choice;
    cout << "Do you want to continue? (y/n): ";
    cin >> choice;
    
    cout << "You entered: " << choice << endl;
    
    /*
     * SECTION 6: Input Validation Demo
     * Basic example of handling input
     */
    
    cout << "\n=== Input Validation Example ===" << endl;
    
    int number;
    cout << "Enter a positive number: ";
    cin >> number;
    
    if (number > 0) {
        cout << "Great! You entered: " << number << endl;
    } else {
        cout << "That's not a positive number, but we'll work with it: " << number << endl;
    }
    
    /*
     * SECTION 7: Multiple Variable Input in One Line
     * Reading several values at once
     */
    
    cout << "\n=== Multiple Input Example ===" << endl;
    
    int x, y, z;
    cout << "Enter three numbers separated by spaces: ";
    cin >> x >> y >> z;
    
    cout << "You entered: " << x << ", " << y << ", " << z << endl;
    cout << "Sum: " << (x + y + z) << endl;
    
    cout << "\n=== Input/Output Practice Complete! ===" << endl;
    
    return 0;
}

/*
 * IMPORTANT INPUT/OUTPUT CONCEPTS:
 * 
 * 1. cin >> variable  - Reads until whitespace (space, tab, newline)
 * 2. getline(cin, string) - Reads entire line including spaces
 * 3. cin.ignore() - Clears input buffer (use after cin >> before getline)
 * 4. cout << - Outputs data to screen
 * 5. endl - Ends line and flushes buffer
 * 6. \n - Just adds new line (faster than endl)
 * 
 * FORMATTING:
 * - fixed - Use fixed-point notation for decimals
 * - setprecision(n) - Show n decimal places
 * - setw(n) - Set field width to n characters
 * - left/right - Align text left or right
 * 
 * COMMON MISTAKES:
 * - Forgetting cin.ignore() before getline()
 * - Not handling spaces in input properly
 * - Mixing cin >> and getline() without clearing buffer
 */
