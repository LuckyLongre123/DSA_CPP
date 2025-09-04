/*
 * Day 1: Simple Calculator Project
 * This program demonstrates basic arithmetic operations
 * and user interaction in C++
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "=== Simple Calculator ===" << endl;
    cout << "Perform basic arithmetic operations (+, -, *, /)" << endl;
    
    /*
     * SECTION 1: Get input from user
     */
    double num1, num2;
    char operation;
    
    cout << "\nEnter first number: ";
    cin >> num1;
    
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    /*
     * SECTION 2: Display the calculation
     */
    cout << "\nCalculation: " << num1 << " " << operation << " " << num2 << " = ";
    
    /*
     * SECTION 3: Perform calculation based on operation
     * We'll use if-else statements (covered in detail on Day 2)
     */
    double result;
    bool validOperation = true;
    
    if (operation == '+') {
        result = num1 + num2;
    }
    else if (operation == '-') {
        result = num1 - num2;
    }
    else if (operation == '*') {
        result = num1 * num2;
    }
    else if (operation == '/') {
        // Check for division by zero
        if (num2 != 0) {
            result = num1 / num2;
        } else {
            cout << "Error! Division by zero is not allowed." << endl;
            validOperation = false;
        }
    }
    else {
        cout << "Error! Invalid operation." << endl;
        validOperation = false;
    }
    
    /*
     * SECTION 4: Display result if operation was valid
     */
    if (validOperation) {
        cout << fixed << setprecision(2) << result << endl;
        
        // Additional information
        cout << "\n--- Additional Info ---" << endl;
        if (result > 0) {
            cout << "Result is positive" << endl;
        } else if (result < 0) {
            cout << "Result is negative" << endl;
        } else {
            cout << "Result is zero" << endl;
        }
        
        // Show if result is a whole number
        if (result == (int)result) {
            cout << "Result is a whole number" << endl;
        } else {
            cout << "Result has decimal places" << endl;
        }
    }
    
    /*
     * SECTION 5: Extended Calculator Features
     * Let's add some more operations
     */
    cout << "\n=== Extended Operations ===" << endl;
    
    // Square of first number
    double square1 = num1 * num1;
    cout << "Square of " << num1 << " = " << square1 << endl;
    
    // Square of second number
    double square2 = num2 * num2;
    cout << "Square of " << num2 << " = " << square2 << endl;
    
    // Average of both numbers
    double average = (num1 + num2) / 2.0;
    cout << "Average of " << num1 << " and " << num2 << " = " << average << endl;
    
    // Difference (absolute value)
    double difference;
    if (num1 > num2) {
        difference = num1 - num2;
    } else {
        difference = num2 - num1;
    }
    cout << "Absolute difference = " << difference << endl;
    
    cout << "\n=== Calculator Complete! ===" << endl;
    cout << "Thank you for using the calculator!" << endl;
    
    return 0;
}

/*
 * WHAT WE LEARNED:
 * 1. Getting multiple inputs from user
 * 2. Using variables to store calculation results
 * 3. Basic arithmetic operations (+, -, *, /)
 * 4. Simple decision making with if-else
 * 5. Error handling (division by zero)
 * 6. Formatting output with setprecision()
 * 7. Type casting (int)result to check whole numbers
 * 
 * PRACTICE EXERCISES:
 * 1. Add modulus (%) operation
 * 2. Add power calculation (num1 ^ num2)
 * 3. Create a temperature converter
 * 4. Make a tip calculator for restaurants
 * 5. Create a compound interest calculator
 * 
 * CONCEPTS USED:
 * - Variables (double, char, bool)
 * - Input/Output (cin, cout)
 * - Arithmetic operators
 * - Comparison operators (==, !=, >, <)
 * - Logical thinking for error handling
 */
