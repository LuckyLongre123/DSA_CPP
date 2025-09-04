/*
 * Day 5: Simple Variable Practice for Beginners
 * This file demonstrates basic variable concepts and simple operations
 * Focus on understanding variables, references, and basic memory concepts
 */

#include <iostream>

using namespace std;

int main() {
    cout << "=== Simple Variable Practice ===" << endl;
    
    /*
     * SECTION 1: Variable Declaration and Initialization
     * Understanding different ways to create and use variables
     */
    
    cout << "\n=== Variable Basics ===" << endl;
    
    // Different types of variables
    int age = 25;
    double height = 5.8;
    char initial = 'J';
    bool isStudent = true;
    
    cout << "Variable values:" << endl;
    cout << "age = " << age << endl;
    cout << "height = " << height << endl;
    cout << "initial = " << initial << endl;
    cout << "isStudent = " << (isStudent ? "true" : "false") << endl;
    
    /*
     * SECTION 2: Variable Assignment and Modification
     * Changing variable values during program execution
     */
    
    cout << "\n=== Variable Assignment ===" << endl;
    
    cout << "Before changes:" << endl;
    cout << "age = " << age << endl;
    cout << "height = " << height << endl;
    
    // Modify variables
    age = 26;           // Simple assignment
    height = height + 0.1;  // Modify using current value
    initial = 'K';      // Change character
    isStudent = false;  // Change boolean
    
    cout << "After changes:" << endl;
    cout << "age = " << age << endl;
    cout << "height = " << height << endl;
    cout << "initial = " << initial << endl;
    cout << "isStudent = " << (isStudent ? "true" : "false") << endl;
    
    /*
     * SECTION 3: Variable Copying
     * Creating copies of variables
     */
    
    cout << "\n=== Variable Copying ===" << endl;
    
    int originalNumber = 100;
    int copiedNumber = originalNumber;  // Copy the value
    
    cout << "Original and copied values:" << endl;
    cout << "originalNumber = " << originalNumber << endl;
    cout << "copiedNumber = " << copiedNumber << endl;
    
    // Change original - copy remains unchanged
    originalNumber = 200;
    
    cout << "After changing original:" << endl;
    cout << "originalNumber = " << originalNumber << endl;
    cout << "copiedNumber = " << copiedNumber << " (unchanged)" << endl;
    
    /*
     * SECTION 4: Simple References (Alternative to Pointers)
     * References are easier aliases for variables
     */
    
    cout << "\n=== Simple References ===" << endl;
    
    int score = 85;
    int& scoreRef = score;  // scoreRef is another name for score
    
    cout << "Original variable and reference:" << endl;
    cout << "score = " << score << endl;
    cout << "scoreRef = " << scoreRef << endl;
    
    // Changing through reference changes original
    scoreRef = 95;
    
    cout << "After changing through reference:" << endl;
    cout << "score = " << score << endl;
    cout << "scoreRef = " << scoreRef << endl;
    
    /*
     * SECTION 5: Variable Swapping
     * Exchanging values between two variables
     */
    
    cout << "\n=== Variable Swapping ===" << endl;
    
    int first = 10;
    int second = 20;
    
    cout << "Before swapping:" << endl;
    cout << "first = " << first << endl;
    cout << "second = " << second << endl;
    
    // Swap using temporary variable
    int temp = first;
    first = second;
    second = temp;
    
    cout << "After swapping:" << endl;
    cout << "first = " << first << endl;
    cout << "second = " << second << endl;
    
    /*
     * SECTION 6: Working with Constants
     * Variables that cannot be changed after initialization
     */
    
    cout << "\n=== Constants ===" << endl;
    
    const int MAX_STUDENTS = 30;
    const double PI = 3.14159;
    
    cout << "Constant values:" << endl;
    cout << "MAX_STUDENTS = " << MAX_STUDENTS << endl;
    cout << "PI = " << PI << endl;
    
    // Constants cannot be modified (this would cause error):
    // MAX_STUDENTS = 40;  // ERROR!
    
    /*
     * SECTION 7: Variable Scope Practice
     * Understanding where variables can be used
     */
    
    cout << "\n=== Variable Scope ===" << endl;
    
    int globalVar = 100;  // Available throughout main function
    
    {
        int localVar = 200;  // Only available in this block
        cout << "Inside block:" << endl;
        cout << "globalVar = " << globalVar << endl;
        cout << "localVar = " << localVar << endl;
    }
    
    cout << "Outside block:" << endl;
    cout << "globalVar = " << globalVar << endl;
    // cout << "localVar = " << localVar;  // ERROR! localVar not accessible
    
    /*
     * PRACTICE EXERCISES FOR BEGINNERS:
     */
    
    cout << "\n=== Practice Exercises ===" << endl;
    cout << "Try these exercises on your own:" << endl;
    cout << "1. Create variables for student information (name, age, grade)" << endl;
    cout << "2. Practice swapping two numbers without using temp variable" << endl;
    cout << "3. Create a simple calculator using variables" << endl;
    cout << "4. Use references to create nicknames for variables" << endl;
    cout << "5. Practice with different data types and their sizes" << endl;
    
    return 0;
}

/*
 * SIMPLE VARIABLE CONCEPTS FOR BEGINNERS:
 * 
 * 1. VARIABLE BASICS:
 *    - Variables store data in memory
 *    - Each variable has a name, type, and value
 *    - Must declare before use: int age;
 *    - Can initialize during declaration: int age = 25;
 * 
 * 2. VARIABLE TYPES:
 *    - int: whole numbers (1, 2, 100)
 *    - double: decimal numbers (3.14, 2.5)
 *    - char: single characters ('A', 'x')
 *    - bool: true or false values
 *    - string: text ("Hello World")
 * 
 * 3. ASSIGNMENT:
 *    - Use = to assign values: age = 30;
 *    - Can use current value: age = age + 1;
 *    - Assignment copies the value
 * 
 * 4. REFERENCES:
 *    - Alternative name for existing variable
 *    - int& ref = variable;
 *    - Changes to reference affect original
 *    - Easier than pointers for beginners
 * 
 * 5. CONSTANTS:
 *    - const keyword makes variable unchangeable
 *    - const int MAX = 100;
 *    - Good for values that shouldn't change
 * 
 * BEGINNER TIPS:
 * - Choose meaningful variable names
 * - Initialize variables when you declare them
 * - Use const for values that won't change
 * - Practice with simple programs first
 * - Understand scope (where variables can be used)
 * 
 * PRACTICE IDEAS:
 * - Create a personal information program
 * - Make a simple calculator
 * - Practice variable swapping
 * - Try different data types
 * - Experiment with references
 */
