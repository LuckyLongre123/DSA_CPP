/*
 * Day 3: Basic Functions in C++
 * This file demonstrates how to create, declare, and use functions
 * Functions help organize code and make it reusable
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * SECTION 1: Function Declarations (Prototypes)
 * These tell the compiler about functions before they're defined
 * Format: return_type function_name(parameter_types);
 */

void greetUser();                           // No parameters, no return value
int addTwoNumbers(int a, int b);           // Two parameters, returns int
double calculateArea(double length, double width);  // Returns double
bool isEven(int number);                   // Returns boolean
string createMessage(string name, int age); // String parameters and return

/*
 * SECTION 2: Main function - our program entry point
 */
int main() {
    cout << "=== Functions Practice in C++ ===" << endl;
    
    /*
     * SECTION 2.1: Calling functions without parameters
     */
    cout << "\n=== Simple Function Call ===" << endl;
    greetUser();  // Call function with no parameters
    
    /*
     * SECTION 2.2: Calling functions with parameters and return values
     */
    cout << "\n=== Functions with Parameters ===" << endl;
    
    int num1 = 15, num2 = 25;
    int sum = addTwoNumbers(num1, num2);  // Store return value
    cout << num1 << " + " << num2 << " = " << sum << endl;
    
    // Can also use function call directly in output
    cout << "10 + 20 = " << addTwoNumbers(10, 20) << endl;
    
    /*
     * SECTION 2.3: Functions returning different data types
     */
    cout << "\n=== Different Return Types ===" << endl;
    
    double roomLength = 12.5, roomWidth = 8.0;
    double area = calculateArea(roomLength, roomWidth);
    cout << "Room area: " << area << " square feet" << endl;
    
    int testNumber = 42;
    bool evenResult = isEven(testNumber);
    cout << testNumber << " is " << (evenResult ? "even" : "odd") << endl;
    
    string userName = "Alice";
    int userAge = 25;
    string message = createMessage(userName, userAge);
    cout << message << endl;
    
    /*
     * SECTION 2.4: Using functions in expressions and conditions
     */
    cout << "\n=== Functions in Expressions ===" << endl;
    
    // Using function in if condition
    if (isEven(100)) {
        cout << "100 is even!" << endl;
    }
    
    // Using functions in calculations
    double totalArea = calculateArea(10, 5) + calculateArea(8, 6);
    cout << "Total area of two rooms: " << totalArea << endl;
    
    // Nested function calls
    int result = addTwoNumbers(addTwoNumbers(5, 3), addTwoNumbers(2, 4));
    cout << "Nested calculation result: " << result << endl;
    
    return 0;
}

/*
 * SECTION 3: Function Definitions
 * These are the actual implementations of the functions
 */

/*
 * Simple function with no parameters and no return value
 * void means "returns nothing"
 */
void greetUser() {
    cout << "Hello! Welcome to C++ Functions!" << endl;
    cout << "This message comes from a function." << endl;
    // No return statement needed for void functions
}

/*
 * Function that takes two integers and returns their sum
 * Parameters: int a, int b (these are local variables)
 * Returns: int (the sum)
 */
int addTwoNumbers(int a, int b) {
    int sum = a + b;  // Local variable
    return sum;       // Return the result
    
    // Alternative: return a + b;  // Direct return
}

/*
 * Function that calculates area of a rectangle
 * Parameters: double length, double width
 * Returns: double (the calculated area)
 */
double calculateArea(double length, double width) {
    if (length <= 0 || width <= 0) {
        cout << "Error: Invalid dimensions!" << endl;
        return 0.0;  // Return 0 for invalid input
    }
    
    double area = length * width;
    return area;
}

/*
 * Function that checks if a number is even
 * Parameter: int number
 * Returns: bool (true if even, false if odd)
 */
bool isEven(int number) {
    return (number % 2 == 0);  // Direct return of boolean expression
}

/*
 * Function that creates a personalized message
 * Parameters: string name, int age
 * Returns: string (the formatted message)
 */
string createMessage(string name, int age) {
    string message = "Hello " + name + "! ";
    message += "You are " + to_string(age) + " years old.";
    
    // Add age-specific message
    if (age < 18) {
        message += " You're young and have a bright future!";
    } else if (age < 65) {
        message += " You're in your prime years!";
    } else {
        message += " Wisdom comes with age!";
    }
    
    return message;
}

/*
 * ADDITIONAL EXAMPLE FUNCTIONS
 * More examples to demonstrate different concepts
 */

/*
 * Function with multiple return points
 * Good practice: try to have single return point when possible
 */
string getGrade(int score) {
    if (score >= 90) return "A";
    if (score >= 80) return "B";
    if (score >= 70) return "C";
    if (score >= 60) return "D";
    return "F";
}

/*
 * Function that demonstrates local variables
 */
int calculateFactorial(int n) {
    if (n < 0) return -1;  // Error case
    if (n == 0 || n == 1) return 1;  // Base cases
    
    int factorial = 1;
    for (int i = 2; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

/*
 * Function with default parameter (C++ feature)
 * If no second argument is provided, it defaults to 2
 */
int power(int base, int exponent = 2) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

/*
 * KEY CONCEPTS LEARNED:
 * 
 * 1. FUNCTION STRUCTURE:
 *    return_type function_name(parameters) {
 *        // function body
 *        return value;  // if not void
 *    }
 * 
 * 2. FUNCTION DECLARATION vs DEFINITION:
 *    - Declaration: Just the signature (prototype)
 *    - Definition: The actual implementation
 * 
 * 3. PARAMETERS vs ARGUMENTS:
 *    - Parameters: Variables in function definition
 *    - Arguments: Actual values passed when calling
 * 
 * 4. RETURN VALUES:
 *    - Functions can return any data type
 *    - void functions don't return anything
 *    - return statement exits the function
 * 
 * 5. BENEFITS OF FUNCTIONS:
 *    - Code reusability
 *    - Better organization
 *    - Easier testing and debugging
 *    - Modular programming
 * 
 * BEST PRACTICES:
 * - Use descriptive function names
 * - Keep functions focused on one task
 * - Validate input parameters
 * - Document complex functions
 * - Avoid functions that are too long
 */
