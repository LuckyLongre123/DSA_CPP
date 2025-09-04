/*
 * Day 3: Function Parameters and Passing Methods
 * This file demonstrates different ways to pass data to functions
 * Understanding parameter passing is crucial for effective programming
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * Function Prototypes
 */
void demonstratePassByValue(int number);
void demonstratePassByReference(int& number);
void swapByValue(int a, int b);
void swapByReference(int& a, int& b);
int findMax(int a, int b, int c);
void printArray(int arr[], int size);
void modifyArray(int arr[], int size);
string formatName(string firstName, string lastName = "");
double calculatePrice(double basePrice, double taxRate = 0.08, double discount = 0.0);

int main() {
    cout << "=== Function Parameters Practice ===" << endl;
    
    /*
     * SECTION 1: Pass by Value vs Pass by Reference
     * Understanding the difference is crucial!
     */
    
    cout << "\n=== Pass by Value Demo ===" << endl;
    int originalValue = 10;
    cout << "Before function call: " << originalValue << endl;
    
    demonstratePassByValue(originalValue);
    cout << "After pass by value: " << originalValue << endl;
    cout << "Notice: Original value unchanged!" << endl;
    
    cout << "\n=== Pass by Reference Demo ===" << endl;
    int referenceValue = 10;
    cout << "Before function call: " << referenceValue << endl;
    
    demonstratePassByReference(referenceValue);
    cout << "After pass by reference: " << referenceValue << endl;
    cout << "Notice: Original value was modified!" << endl;
    
    /*
     * SECTION 2: Practical Example - Swapping Values
     * Demonstrates why pass by reference is sometimes necessary
     */
    
    cout << "\n=== Swapping Values Example ===" << endl;
    
    int x = 5, y = 15;
    cout << "Original values: x = " << x << ", y = " << y << endl;
    
    // This won't work - pass by value
    swapByValue(x, y);
    cout << "After swap by value: x = " << x << ", y = " << y << endl;
    cout << "Values not swapped!" << endl;
    
    // This will work - pass by reference
    swapByReference(x, y);
    cout << "After swap by reference: x = " << x << ", y = " << y << endl;
    cout << "Values successfully swapped!" << endl;
    
    /*
     * SECTION 3: Multiple Parameters
     * Functions can have many parameters
     */
    
    cout << "\n=== Multiple Parameters ===" << endl;
    
    int num1 = 25, num2 = 40, num3 = 15;
    int maximum = findMax(num1, num2, num3);
    cout << "Maximum of " << num1 << ", " << num2 << ", " << num3;
    cout << " is: " << maximum << endl;
    
    /*
     * SECTION 4: Array Parameters
     * Arrays are always passed by reference (sort of)
     */
    
    cout << "\n=== Array Parameters ===" << endl;
    
    int numbers[] = {1, 2, 3, 4, 5};
    int arraySize = 5;
    
    cout << "Original array: ";
    printArray(numbers, arraySize);
    
    modifyArray(numbers, arraySize);
    cout << "After modification: ";
    printArray(numbers, arraySize);
    cout << "Arrays are automatically passed by reference!" << endl;
    
    /*
     * SECTION 5: Default Parameters
     * Parameters can have default values
     */
    
    cout << "\n=== Default Parameters ===" << endl;
    
    // Using all parameters
    string fullName1 = formatName("John", "Doe");
    cout << "Full name: " << fullName1 << endl;
    
    // Using default parameter
    string fullName2 = formatName("Alice");
    cout << "Single name: " << fullName2 << endl;
    
    // Price calculation with defaults
    double price1 = calculatePrice(100.0);  // Uses default tax and discount
    cout << "Price with defaults: $" << price1 << endl;
    
    double price2 = calculatePrice(100.0, 0.10);  // Custom tax, default discount
    cout << "Price with custom tax: $" << price2 << endl;
    
    double price3 = calculatePrice(100.0, 0.10, 15.0);  // All custom values
    cout << "Price with custom tax and discount: $" << price3 << endl;
    
    /*
     * SECTION 6: Const Parameters
     * Preventing accidental modification
     */
    
    cout << "\n=== Const Parameters ===" << endl;
    
    const string message = "Hello World";
    // printMessage(message);  // Would work with const parameter
    
    return 0;
}

/*
 * FUNCTION DEFINITIONS
 */

/*
 * Pass by Value: Function receives a copy of the variable
 * Changes inside function don't affect original variable
 */
void demonstratePassByValue(int number) {
    cout << "Inside function, received: " << number << endl;
    number = 99;  // This changes only the local copy
    cout << "Inside function, changed to: " << number << endl;
}

/*
 * Pass by Reference: Function receives reference to original variable
 * Changes inside function affect the original variable
 * Note the & symbol in parameter declaration
 */
void demonstratePassByReference(int& number) {
    cout << "Inside function, received: " << number << endl;
    number = 99;  // This changes the original variable
    cout << "Inside function, changed to: " << number << endl;
}

/*
 * Swap function using pass by value - WON'T WORK
 * Only swaps the local copies
 */
void swapByValue(int a, int b) {
    cout << "Inside swapByValue: before swap a=" << a << ", b=" << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByValue: after swap a=" << a << ", b=" << b << endl;
}

/*
 * Swap function using pass by reference - WORKS
 * Swaps the original variables
 */
void swapByReference(int& a, int& b) {
    cout << "Inside swapByReference: before swap a=" << a << ", b=" << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByReference: after swap a=" << a << ", b=" << b << endl;
}

/*
 * Function with multiple parameters
 * Returns the maximum of three numbers
 */
int findMax(int a, int b, int c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

/*
 * Function that prints an array
 * Arrays are automatically passed by reference
 */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
 * Function that modifies an array
 * Demonstrates that arrays are passed by reference
 */
void modifyArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Double each element
    }
}

/*
 * Function with default parameter
 * lastName has a default value of empty string
 */
string formatName(string firstName, string lastName) {
    if (lastName.empty()) {
        return firstName;
    } else {
        return firstName + " " + lastName;
    }
}

/*
 * Function with multiple default parameters
 * Default parameters must come at the end
 */
double calculatePrice(double basePrice, double taxRate, double discount) {
    double tax = basePrice * taxRate;
    double discountAmount = basePrice * (discount / 100.0);
    return basePrice + tax - discountAmount;
}

/*
 * Function with const parameter
 * Prevents accidental modification of the parameter
 */
void printMessage(const string& message) {
    cout << "Message: " << message << endl;
    // message = "changed";  // This would cause a compiler error
}

/*
 * Function demonstrating const reference parameter
 * Efficient for large objects (no copying) but prevents modification
 */
void processLargeData(const string& data) {
    cout << "Processing data of length: " << data.length() << endl;
    // No copy is made, but we can't modify 'data'
}

/*
 * KEY CONCEPTS SUMMARY:
 * 
 * 1. PASS BY VALUE:
 *    - Function gets a copy of the variable
 *    - Original variable is not affected
 *    - Good for small data types (int, char, bool)
 *    - Safe from accidental modification
 * 
 * 2. PASS BY REFERENCE:
 *    - Function gets access to original variable
 *    - Changes affect the original variable
 *    - Use & symbol in parameter declaration
 *    - Efficient for large objects (no copying)
 * 
 * 3. ARRAYS:
 *    - Always passed by reference (automatically)
 *    - Function can modify original array elements
 *    - Must pass size separately
 * 
 * 4. DEFAULT PARAMETERS:
 *    - Provide default values for parameters
 *    - Must be at the end of parameter list
 *    - Allow function overloading-like behavior
 * 
 * 5. CONST PARAMETERS:
 *    - Prevent accidental modification
 *    - Good practice for read-only parameters
 *    - const string& is efficient for strings
 * 
 * WHEN TO USE WHAT:
 * - Pass by value: Small data, don't need to modify original
 * - Pass by reference: Need to modify original, or large objects
 * - Const reference: Large objects, read-only access
 */
