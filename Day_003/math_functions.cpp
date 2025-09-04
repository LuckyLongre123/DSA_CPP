/*
 * Day 3: Simple Math Functions for Beginners
 * This file demonstrates basic math functions that beginners can understand
 * Focus on simple calculations and easy-to-understand concepts
 */

#include <iostream>

using namespace std;

/*
 * Function prototypes for our simple math library
 */
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);
int findMax(int a, int b);
int findMin(int a, int b);
bool isEven(int number);
bool isOdd(int number);
int calculateSquare(int number);
double calculateCircleArea(double radius);

int main() {
    cout << "=== Simple Math Functions ===" << endl;
    
    /*
     * SECTION 1: Basic Arithmetic Operations
     */
    cout << "\n=== Basic Arithmetic ===" << endl;
    
    int num1 = 15, num2 = 8;
    cout << "Numbers: " << num1 << " and " << num2 << endl;
    cout << "Addition: " << add(num1, num2) << endl;
    cout << "Subtraction: " << subtract(num1, num2) << endl;
    cout << "Multiplication: " << multiply(num1, num2) << endl;
    cout << "Division: " << divide(num1, num2) << endl;
    
    /*
     * SECTION 2: Finding Maximum and Minimum
     */
    cout << "\n=== Max and Min Functions ===" << endl;
    
    int a = 25, b = 18;
    cout << "Numbers: " << a << " and " << b << endl;
    cout << "Maximum: " << findMax(a, b) << endl;
    cout << "Minimum: " << findMin(a, b) << endl;
    
    /*
     * SECTION 3: Even and Odd Numbers
     */
    cout << "\n=== Even/Odd Check ===" << endl;
    
    int testNumbers[] = {4, 7, 12, 15, 20};
    for (int i = 0; i < 5; i++) {
        cout << testNumbers[i] << " is " << (isEven(testNumbers[i]) ? "even" : "odd") << endl;
    }
    
    /*
     * SECTION 4: Square Calculations
     */
    cout << "\n=== Square Calculations ===" << endl;
    
    int numbers[] = {3, 5, 8, 10};
    for (int i = 0; i < 4; i++) {
        cout << "Square of " << numbers[i] << " = " << calculateSquare(numbers[i]) << endl;
    }
    
    /*
     * SECTION 5: Circle Area
     */
    cout << "\n=== Circle Area Calculation ===" << endl;
    
    double radius = 5.0;
    double area = calculateCircleArea(radius);
    cout << "Circle with radius " << radius << " has area: " << area << endl;
    
    /*
     * SECTION 6: Interactive Calculator
     */
    cout << "\n=== Interactive Math Calculator ===" << endl;
    
    int userChoice;
    cout << "Choose an operation:" << endl;
    cout << "1. Add two numbers" << endl;
    cout << "2. Find maximum of two numbers" << endl;
    cout << "3. Check if number is even" << endl;
    cout << "4. Calculate square of a number" << endl;
    cout << "5. Calculate circle area" << endl;
    cout << "Enter your choice (1-5): ";
    cin >> userChoice;
    
    switch (userChoice) {
        case 1: {
            int x, y;
            cout << "Enter two numbers: ";
            cin >> x >> y;
            cout << "Sum: " << add(x, y) << endl;
            break;
        }
        case 2: {
            int x, y;
            cout << "Enter two numbers: ";
            cin >> x >> y;
            cout << "Maximum: " << findMax(x, y) << endl;
            break;
        }
        case 3: {
            int num;
            cout << "Enter a number: ";
            cin >> num;
            cout << num << " is " << (isEven(num) ? "even" : "odd") << endl;
            break;
        }
        case 4: {
            int num;
            cout << "Enter a number: ";
            cin >> num;
            cout << "Square of " << num << " = " << calculateSquare(num) << endl;
            break;
        }
        case 5: {
            double r;
            cout << "Enter radius: ";
            cin >> r;
            cout << "Area: " << calculateCircleArea(r) << endl;
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
}

/*
 * SIMPLE MATH FUNCTION DEFINITIONS
 */

/*
 * Add two numbers
 */
int add(int a, int b) {
    return a + b;
}

/*
 * Subtract two numbers
 */
int subtract(int a, int b) {
    return a - b;
}

/*
 * Multiply two numbers
 */
int multiply(int a, int b) {
    return a * b;
}

/*
 * Divide two numbers
 * Returns decimal result
 */
double divide(int a, int b) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero!" << endl;
        return 0;
    }
    return (double)a / b;
}

/*
 * Find maximum of two numbers
 */
int findMax(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

/*
 * Find minimum of two numbers
 */
int findMin(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

/*
 * Check if a number is even
 */
bool isEven(int number) {
    return (number % 2 == 0);
}

/*
 * Check if a number is odd
 */
bool isOdd(int number) {
    return (number % 2 != 0);
}

/*
 * Calculate square of a number
 */
int calculateSquare(int number) {
    return number * number;
}

/*
 * Calculate area of a circle
 * Area = π * r²
 */
double calculateCircleArea(double radius) {
    const double PI = 3.14159;
    return PI * radius * radius;
}

/*
 * SIMPLE MATH LIBRARY SUMMARY:
 * 
 * This library demonstrates:
 * 1. Basic function creation and usage
 * 2. Simple mathematical operations
 * 3. Function parameters and return values
 * 4. Basic input validation
 * 
 * FUNCTIONS INCLUDED:
 * - add(): Add two numbers
 * - subtract(): Subtract two numbers
 * - multiply(): Multiply two numbers
 * - divide(): Divide two numbers (with zero check)
 * - findMax(): Find maximum of two numbers
 * - findMin(): Find minimum of two numbers
 * - isEven(): Check if number is even
 * - isOdd(): Check if number is odd
 * - calculateSquare(): Calculate square of a number
 * - calculateCircleArea(): Calculate area of a circle
 * 
 * PROGRAMMING CONCEPTS FOR BEGINNERS:
 * - Function declaration and definition
 * - Parameter passing
 * - Return values
 * - Basic conditional statements
 * - Simple mathematical operations
 * - User input and output
 * - Switch statements for menus
 * 
 * PRACTICE EXERCISES:
 * 1. Create a function to calculate cube of a number
 * 2. Create a function to find average of two numbers
 * 3. Create a function to convert Celsius to Fahrenheit
 * 4. Create a function to calculate rectangle area
 * 5. Create a function to check if a number is positive or negative
 */
