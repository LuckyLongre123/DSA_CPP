/*
 * Day 2: Conditional Statements in C++
 * This file demonstrates if-else statements and decision making
 * Essential for creating programs that respond to different situations
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "=== Conditional Statements Practice ===" << endl;
    
    /*
     * SECTION 1: Basic if-else statement
     * Simple decision making based on a condition
     */
    
    int age;
    cout << "\nEnter your age: ";
    cin >> age;
    
    if (age >= 18) {
        cout << "You are an adult!" << endl;
    } else {
        cout << "You are a minor." << endl;
    }
    
    /*
     * SECTION 2: Multiple conditions with else if
     * Checking multiple conditions in sequence
     */
    
    cout << "\n=== Grade Classification ===" << endl;
    
    int score;
    cout << "Enter your test score (0-100): ";
    cin >> score;
    
    if (score >= 90) {
        cout << "Grade: A (Excellent!)" << endl;
    } else if (score >= 80) {
        cout << "Grade: B (Good job!)" << endl;
    } else if (score >= 70) {
        cout << "Grade: C (Average)" << endl;
    } else if (score >= 60) {
        cout << "Grade: D (Below average)" << endl;
    } else {
        cout << "Grade: F (Needs improvement)" << endl;
    }
    
    /*
     * SECTION 3: Logical operators (&&, ||, !)
     * Combining multiple conditions
     */
    
    cout << "\n=== Movie Ticket Pricing ===" << endl;
    
    int customerAge;
    bool isStudent;
    char studentAnswer;
    
    cout << "Enter your age: ";
    cin >> customerAge;
    cout << "Are you a student? (y/n): ";
    cin >> studentAnswer;
    
    isStudent = (studentAnswer == 'y' || studentAnswer == 'Y');
    
    double ticketPrice = 12.00;  // Base price
    
    // Apply discounts based on conditions
    if (customerAge < 12) {
        ticketPrice = 6.00;  // Child discount
        cout << "Child ticket: $" << ticketPrice << endl;
    } else if (customerAge >= 65) {
        ticketPrice = 8.00;  // Senior discount
        cout << "Senior ticket: $" << ticketPrice << endl;
    } else if (isStudent && customerAge >= 13 && customerAge <= 25) {
        ticketPrice = 9.00;  // Student discount
        cout << "Student ticket: $" << ticketPrice << endl;
    } else {
        cout << "Adult ticket: $" << ticketPrice << endl;
    }
    
    /*
     * SECTION 4: Nested if statements
     * if statements inside other if statements
     */
    
    cout << "\n=== Weather Advisory ===" << endl;
    
    int temperature;
    char isRaining;
    
    cout << "Enter temperature (°F): ";
    cin >> temperature;
    cout << "Is it raining? (y/n): ";
    cin >> isRaining;
    
    if (temperature > 80) {
        cout << "It's hot outside!" << endl;
        if (isRaining == 'y' || isRaining == 'Y') {
            cout << "But it's raining - take an umbrella!" << endl;
        } else {
            cout << "Perfect weather for outdoor activities!" << endl;
        }
    } else if (temperature > 60) {
        cout << "Nice moderate temperature." << endl;
        if (isRaining == 'y' || isRaining == 'Y') {
            cout << "Light jacket and umbrella recommended." << endl;
        } else {
            cout << "Great weather for a walk!" << endl;
        }
    } else {
        cout << "It's cold outside!" << endl;
        if (isRaining == 'y' || isRaining == 'Y') {
            cout << "Cold and rainy - stay indoors if possible!" << endl;
        } else {
            cout << "Bundle up with warm clothes!" << endl;
        }
    }
    
    /*
     * SECTION 5: Switch statement (alternative to multiple if-else)
     * Good for checking a variable against multiple specific values
     */
    
    cout << "\n=== Day of Week ===" << endl;
    
    int dayNumber;
    cout << "Enter day number (1-7): ";
    cin >> dayNumber;
    
    switch (dayNumber) {
        case 1:
            cout << "Monday - Start of work week!" << endl;
            break;
        case 2:
            cout << "Tuesday - Getting into the groove" << endl;
            break;
        case 3:
            cout << "Wednesday - Hump day!" << endl;
            break;
        case 4:
            cout << "Thursday - Almost there" << endl;
            break;
        case 5:
            cout << "Friday - TGIF!" << endl;
            break;
        case 6:
            cout << "Saturday - Weekend fun!" << endl;
            break;
        case 7:
            cout << "Sunday - Rest day" << endl;
            break;
        default:
            cout << "Invalid day number! Please enter 1-7." << endl;
            break;
    }
    
    /*
     * SECTION 6: Comparison operators practice
     * Demonstrating all comparison operators
     */
    
    cout << "\n=== Number Comparison ===" << endl;
    
    int num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    cout << "\nComparison Results:" << endl;
    cout << num1 << " == " << num2 << " : " << (num1 == num2 ? "true" : "false") << endl;
    cout << num1 << " != " << num2 << " : " << (num1 != num2 ? "true" : "false") << endl;
    cout << num1 << " > " << num2 << " : " << (num1 > num2 ? "true" : "false") << endl;
    cout << num1 << " < " << num2 << " : " << (num1 < num2 ? "true" : "false") << endl;
    cout << num1 << " >= " << num2 << " : " << (num1 >= num2 ? "true" : "false") << endl;
    cout << num1 << " <= " << num2 << " : " << (num1 <= num2 ? "true" : "false") << endl;
    
    /*
     * SECTION 7: Ternary operator (shorthand if-else)
     * condition ? value_if_true : value_if_false
     */
    
    cout << "\n=== Ternary Operator Demo ===" << endl;
    
    int x = 10, y = 20;
    int max = (x > y) ? x : y;  // If x > y, max = x, otherwise max = y
    
    cout << "Between " << x << " and " << y << ", the maximum is: " << max << endl;
    
    // Multiple ternary operators
    string result = (x > y) ? "x is greater" : 
                   (x < y) ? "y is greater" : 
                   "they are equal";
    cout << "Result: " << result << endl;
    
    cout << "\n=== Conditionals Practice Complete! ===" << endl;
    
    return 0;
}

/*
 * KEY CONCEPTS LEARNED:
 * 
 * 1. if-else statements for decision making
 * 2. else if for multiple conditions
 * 3. Logical operators: && (AND), || (OR), ! (NOT)
 * 4. Comparison operators: ==, !=, >, <, >=, <=
 * 5. Nested if statements
 * 6. switch statement for multiple specific values
 * 7. Ternary operator for simple conditions
 * 
 * COMMON MISTAKES TO AVOID:
 * - Using = instead of == for comparison
 * - Forgetting break in switch statements
 * - Not handling all possible cases
 * - Complex nested conditions (keep it simple)
 * 
 * BEST PRACTICES:
 * - Use meaningful variable names
 * - Keep conditions simple and readable
 * - Handle edge cases and invalid input
 * - Use switch for multiple specific values
 * - Use if-else for ranges and complex conditions
 */
