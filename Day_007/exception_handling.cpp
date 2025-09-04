/*
 * Day 7: Exception Handling in C++
 * This file demonstrates try-catch blocks and error handling
 * Exception handling makes programs more robust and user-friendly
 */

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    cout << "=== Exception Handling in C++ ===" << endl;
    
    /*
     * SECTION 1: Basic Try-Catch
     * Handling division by zero
     */
    
    cout << "\n=== Basic Exception Handling ===" << endl;
    
    int numerator, denominator;
    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;
    
    try {
        if (denominator == 0) {
            throw runtime_error("Division by zero is not allowed!");
        }
        
        double result = (double)numerator / denominator;
        cout << "Result: " << result << endl;
        
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
        cout << "Please enter a non-zero denominator." << endl;
    }
    
    /*
     * SECTION 2: Multiple Exception Types
     */
    
    cout << "\n=== Multiple Exception Types ===" << endl;
    
    try {
        int choice;
        cout << "Choose exception type (1-4): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                throw runtime_error("Runtime error occurred!");
                break;
            case 2:
                throw invalid_argument("Invalid argument provided!");
                break;
            case 3:
                throw out_of_range("Index out of range!");
                break;
            case 4:
                throw logic_error("Logic error in program!");
                break;
            default:
                cout << "No exception thrown" << endl;
        }
        
    } catch (const runtime_error& e) {
        cout << "Runtime Error: " << e.what() << endl;
    } catch (const invalid_argument& e) {
        cout << "Invalid Argument: " << e.what() << endl;
    } catch (const out_of_range& e) {
        cout << "Out of Range: " << e.what() << endl;
    } catch (const exception& e) {  // Catch all other exceptions
        cout << "General Exception: " << e.what() << endl;
    }
    
    /*
     * SECTION 3: Vector Bounds Checking
     */
    
    cout << "\n=== Vector Exception Handling ===" << endl;
    
    vector<int> numbers = {10, 20, 30, 40, 50};
    
    cout << "Vector contents: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    int index;
    cout << "Enter index to access (0-" << (numbers.size()-1) << "): ";
    cin >> index;
    
    try {
        // Using at() method which throws exception for invalid index
        int value = numbers.at(index);
        cout << "Value at index " << index << ": " << value << endl;
        
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
        cout << "Valid indices are 0 to " << (numbers.size()-1) << endl;
    }
    
    /*
     * SECTION 4: File Operation Exceptions
     */
    
    cout << "\n=== File Exception Handling ===" << endl;
    
    string filename;
    cout << "Enter filename to read: ";
    cin >> filename;
    
    try {
        ifstream file(filename);
        
        if (!file.is_open()) {
            throw runtime_error("Could not open file: " + filename);
        }
        
        string line;
        cout << "File contents:" << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
        
        file.close();
        cout << "File read successfully" << endl;
        
    } catch (const runtime_error& e) {
        cout << "File Error: " << e.what() << endl;
        cout << "Please check if the file exists and is readable." << endl;
    }
    
    /*
     * SECTION 5: Custom Exception Function
     */
    
    cout << "\n=== Custom Exception Function ===" << endl;
    
    auto validateAge = [](int age) {
        if (age < 0) {
            throw invalid_argument("Age cannot be negative");
        }
        if (age > 150) {
            throw out_of_range("Age seems unrealistic (over 150)");
        }
        if (age < 18) {
            throw logic_error("Must be 18 or older");
        }
        return true;
    };
    
    int age;
    cout << "Enter your age: ";
    cin >> age;
    
    try {
        validateAge(age);
        cout << "Age " << age << " is valid!" << endl;
        
    } catch (const invalid_argument& e) {
        cout << "Invalid Input: " << e.what() << endl;
    } catch (const out_of_range& e) {
        cout << "Range Error: " << e.what() << endl;
    } catch (const logic_error& e) {
        cout << "Logic Error: " << e.what() << endl;
    }
    
    /*
     * SECTION 6: Nested Try-Catch
     */
    
    cout << "\n=== Nested Exception Handling ===" << endl;
    
    try {
        cout << "Outer try block" << endl;
        
        try {
            cout << "Inner try block" << endl;
            
            int value;
            cout << "Enter a number (0 to throw exception): ";
            cin >> value;
            
            if (value == 0) {
                throw runtime_error("Zero value not allowed in inner block");
            }
            
            cout << "Inner block completed successfully" << endl;
            
        } catch (const runtime_error& e) {
            cout << "Inner catch: " << e.what() << endl;
            // Re-throw the exception to outer catch
            throw;
        }
        
        cout << "Outer try block completed" << endl;
        
    } catch (const runtime_error& e) {
        cout << "Outer catch: " << e.what() << endl;
    }
    
    /*
     * SECTION 7: Exception in Loop
     */
    
    cout << "\n=== Exception Handling in Loop ===" << endl;
    
    vector<int> data = {10, 0, 5, 0, 8, 0, 3};
    
    for (int i = 0; i < data.size(); i++) {
        try {
            if (data[i] == 0) {
                throw runtime_error("Zero value encountered at index " + to_string(i));
            }
            
            int result = 100 / data[i];
            cout << "100 / " << data[i] << " = " << result << endl;
            
        } catch (const runtime_error& e) {
            cout << "Skipping: " << e.what() << endl;
            continue;  // Continue with next iteration
        }
    }
    
    /*
     * SECTION 8: Resource Management with Exceptions
     */
    
    cout << "\n=== Resource Management ===" << endl;
    
    try {
        // Simulate resource allocation
        cout << "Allocating resources..." << endl;
        
        // Simulate some work that might throw
        bool simulateError = true;
        if (simulateError) {
            throw runtime_error("Simulated error during processing");
        }
        
        cout << "Work completed successfully" << endl;
        cout << "Releasing resources..." << endl;
        
    } catch (const exception& e) {
        cout << "Error occurred: " << e.what() << endl;
        cout << "Cleaning up resources in catch block..." << endl;
    }
    
    /*
     * SECTION 9: Input Validation with Exceptions
     */
    
    cout << "\n=== Input Validation ===" << endl;
    
    auto getValidInteger = [](const string& prompt, int min, int max) -> int {
        int value;
        while (true) {
            try {
                cout << prompt;
                cin >> value;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    throw invalid_argument("Invalid input - not a number");
                }
                
                if (value < min || value > max) {
                    throw out_of_range("Value must be between " + to_string(min) + " and " + to_string(max));
                }
                
                return value;
                
            } catch (const exception& e) {
                cout << "Error: " << e.what() << ". Please try again." << endl;
            }
        }
    };
    
    try {
        int score = getValidInteger("Enter a score (0-100): ", 0, 100);
        cout << "Valid score entered: " << score << endl;
        
        if (score >= 90) cout << "Grade: A" << endl;
        else if (score >= 80) cout << "Grade: B" << endl;
        else if (score >= 70) cout << "Grade: C" << endl;
        else if (score >= 60) cout << "Grade: D" << endl;
        else cout << "Grade: F" << endl;
        
    } catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
    }
    
    cout << "\n=== Exception Handling Complete! ===" << endl;
    
    return 0;
}

/*
 * EXCEPTION HANDLING KEY CONCEPTS:
 * 
 * 1. TRY-CATCH SYNTAX:
 *    try {
 *        // Code that might throw exception
 *    } catch (const ExceptionType& e) {
 *        // Handle specific exception
 *    } catch (...) {
 *        // Handle any exception
 *    }
 * 
 * 2. STANDARD EXCEPTIONS:
 *    - runtime_error: Runtime problems
 *    - invalid_argument: Invalid function arguments
 *    - out_of_range: Index/range violations
 *    - logic_error: Logic problems in code
 *    - bad_alloc: Memory allocation failures
 * 
 * 3. THROWING EXCEPTIONS:
 *    - throw ExceptionType("message");
 *    - throw; // Re-throw current exception
 *    - Custom exception classes possible
 * 
 * 4. EXCEPTION SAFETY:
 *    - Basic guarantee: No resource leaks
 *    - Strong guarantee: Operation succeeds or no effect
 *    - No-throw guarantee: Operation never throws
 * 
 * 5. BEST PRACTICES:
 *    - Catch specific exceptions first
 *    - Use const references in catch blocks
 *    - Don't catch and ignore exceptions
 *    - Clean up resources in catch blocks
 *    - Use RAII when possible
 * 
 * 6. WHEN TO USE EXCEPTIONS:
 *    - Unexpected error conditions
 *    - When normal return values insufficient
 *    - To separate error handling from normal flow
 *    - For propagating errors up call stack
 * 
 * 7. PERFORMANCE CONSIDERATIONS:
 *    - Exceptions have overhead when thrown
 *    - Try-catch blocks have minimal overhead
 *    - Don't use for normal control flow
 *    - Use for exceptional circumstances only
 * 
 * COMMON SCENARIOS:
 * - File operations (file not found, permission denied)
 * - Array/vector bounds checking
 * - Input validation
 * - Resource allocation failures
 * - Network operations
 * - Database operations
 */
