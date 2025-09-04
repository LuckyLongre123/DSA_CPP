/*
 * Day 1: C++ Basics - Program Structure and Variables
 * This file demonstrates the fundamental structure of a C++ program
 * and basic variable operations
 */

#include <iostream>  // Include input/output stream library
#include <string>    // Include string library for text handling

using namespace std; // Use standard namespace to avoid writing std:: everywhere

int main() {
    // This is the main function - every C++ program starts here
    
    /*
     * SECTION 1: Basic Program Structure Demo
     * Let's start with a simple greeting
     */
    cout << "=== Welcome to C++ Programming! ===" << endl;
    cout << "This is your first C++ program." << endl;
    
    /*
     * SECTION 2: Variable Declaration and Data Types
     * Let's explore different data types in C++
     */
    
    // Integer variables (whole numbers)
    int age = 20;
    int year = 2024;
    
    // Floating-point variables (decimal numbers)
    float height = 5.8f;        // 'f' suffix indicates float
    double weight = 65.5;       // double has more precision than float
    
    // Character variables (single characters)
    char grade = 'A';
    char initial = 'J';
    
    // Boolean variables (true/false)
    bool isStudent = true;
    bool hasLicense = false;
    
    // String variables (text)
    string name = "John Doe";
    string city = "New York";
    
    /*
     * SECTION 3: Displaying Variables
     * Let's print all our variables to see their values
     */
    cout << "\n=== Variable Display ===" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << " years" << endl;
    cout << "Height: " << height << " feet" << endl;
    cout << "Weight: " << weight << " kg" << endl;
    cout << "Grade: " << grade << endl;
    cout << "Initial: " << initial << endl;
    cout << "Is Student: " << (isStudent ? "Yes" : "No") << endl;
    cout << "Has License: " << (hasLicense ? "Yes" : "No") << endl;
    cout << "City: " << city << endl;
    cout << "Year: " << year << endl;
    
    /*
     * SECTION 4: Variable Operations
     * Let's perform some basic operations with variables
     */
    cout << "\n=== Variable Operations ===" << endl;
    
    // Arithmetic operations
    int currentYear = 2024;
    int birthYear = currentYear - age;
    cout << "Birth Year: " << birthYear << endl;
    
    // String concatenation
    string fullInfo = name + " from " + city;
    cout << "Full Info: " << fullInfo << endl;
    
    // Modifying variables
    age = age + 1;  // Increment age by 1
    cout << "Next year age will be: " << age << endl;
    
    /*
     * SECTION 5: Constants
     * Constants are variables whose values cannot be changed
     */
    const double PI = 3.14159;  // const keyword makes it unchangeable
    const int DAYS_IN_WEEK = 7;
    
    cout << "\n=== Constants ===" << endl;
    cout << "Value of PI: " << PI << endl;
    cout << "Days in a week: " << DAYS_IN_WEEK << endl;
    
    // PI = 3.14; // This would cause an error because PI is constant
    
    /*
     * SECTION 6: Variable Scope Demo
     * Variables declared inside {} have local scope
     */
    cout << "\n=== Variable Scope Demo ===" << endl;
    {
        int localVar = 100;  // This variable only exists within these braces
        cout << "Local variable: " << localVar << endl;
    }
    // cout << localVar; // This would cause an error - localVar doesn't exist here
    
    cout << "\n=== Program Complete! ===" << endl;
    return 0;  // Return 0 indicates successful program execution
}

/*
 * KEY TAKEAWAYS:
 * 1. Every C++ program needs #include <iostream> for input/output
 * 2. main() function is the entry point of every C++ program
 * 3. Variables must be declared with a data type before use
 * 4. Use meaningful variable names (age, not a)
 * 5. Constants use 'const' keyword and cannot be changed
 * 6. Statements end with semicolon (;)
 * 7. Use comments to explain your code
 */
