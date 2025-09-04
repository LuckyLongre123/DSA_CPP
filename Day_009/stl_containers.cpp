/*
 * Day 9: Simple Programming Practice
 * This file demonstrates basic programming concepts with simple exercises
 * Focus on loops, arrays, functions, and problem-solving for beginners
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * SECTION 1: Simple Number Games
 * Basic programming exercises with numbers and arrays
 */

void numberGames() {
    cout << "\n=== Number Games ===" << endl;
    
    // Simple number guessing game
    int secretNumber = 42;
    int guess;
    int attempts = 0;
    
    cout << "I'm thinking of a number between 1 and 100!" << endl;
    
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        
        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You got it in " << attempts << " attempts!" << endl;
        }
    } while (guess != secretNumber && attempts < 5);
    
    if (attempts >= 5 && guess != secretNumber) {
        cout << "Game over! The number was " << secretNumber << endl;
    }
}

/*
 * SECTION 2: Simple Array Practice
 * Working with arrays and basic operations
 */

void arrayPractice() {
    cout << "\n=== Array Practice ===" << endl;
    
    // Simple array operations
    int numbers[5] = {10, 25, 30, 15, 40};
    int size = 5;
    
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // Find maximum and minimum
    int max = numbers[0];
    int min = numbers[0];
    
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    
    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;
    
    // Calculate sum and average
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    
    cout << "Sum: " << sum << endl;
    cout << "Average: " << (double)sum / size << endl;
    
    // Count even and odd numbers
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
    
    cout << "Even numbers: " << evenCount << endl;
    cout << "Odd numbers: " << oddCount << endl;
}

/*
 * SECTION 3: Simple String Practice
 * Working with strings and basic text operations
 */

void stringPractice() {
    cout << "\n=== String Practice ===" << endl;
    
    string message = "Hello World Programming";
    
    cout << "Original message: " << message << endl;
    cout << "Length: " << message.length() << endl;
    
    // Count vowels and consonants
    int vowels = 0, consonants = 0;
    for (char c : message) {
        if (c >= 'A' && c <= 'Z') {
            c = c + 32; // Convert to lowercase
        }
        
        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    
    // Reverse the string
    string reversed = "";
    for (int i = message.length() - 1; i >= 0; i--) {
        reversed += message[i];
    }
    cout << "Reversed: " << reversed << endl;
    
    // Count words (simple version)
    int wordCount = 1;
    for (char c : message) {
        if (c == ' ') {
            wordCount++;
        }
    }
    cout << "Word count: " << wordCount << endl;
}

/*
 * SECTION 4: Simple Calculator Functions
 * Practice with functions and basic math operations
 */

void calculatorPractice() {
    cout << "\n=== Calculator Practice ===" << endl;
    
    int num1, num2;
    char operation;
    
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;
    cout << "Enter second number: ";
    cin >> num2;
    
    int result = 0;
    bool validOperation = true;
    
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Division by zero!" << endl;
                validOperation = false;
            }
            break;
        default:
            cout << "Error: Invalid operation!" << endl;
            validOperation = false;
    }
    
    if (validOperation) {
        cout << num1 << " " << operation << " " << num2 << " = " << result << endl;
    }
}

int main() {
    cout << "=== Simple Programming Practice ===" << endl;
    
    // Call all our practice functions
    numberGames();
    arrayPractice();
    stringPractice();
    calculatorPractice();
    
    /*
     * PRACTICE EXERCISES FOR BEGINNERS:
     */
    
    cout << "\n=== Practice Exercises ===" << endl;
    cout << "Try these exercises on your own:" << endl;
    cout << "1. Create a simple grade calculator" << endl;
    cout << "2. Build a word counting program" << endl;
    cout << "3. Make a temperature converter" << endl;
    cout << "4. Create a simple menu-driven program" << endl;
    cout << "5. Build a basic pattern printing program" << endl;
    
    cout << "\n=== Programming Practice Complete! ===" << endl;
    
    return 0;
}

/*
 * SIMPLE PROGRAMMING PRACTICE FOR BEGINNERS:
 * 
 * 1. NUMBER GAMES:
 *    - Simple guessing games with loops and conditions
 *    - Practice with user input and output
 *    - Learn about do-while loops and if-else statements
 * 
 * 2. ARRAY PRACTICE:
 *    - Basic array operations like finding max, min, sum
 *    - Counting elements with specific properties
 *    - Simple statistics and calculations
 * 
 * 3. STRING PRACTICE:
 *    - Character counting and analysis
 *    - Simple string manipulation
 *    - Basic text processing without complex algorithms
 * 
 * 4. CALCULATOR PRACTICE:
 *    - Switch statements for different operations
 *    - Error handling for invalid input
 *    - Basic arithmetic operations
 * 
 * 5. WHY THESE EXERCISES:
 *    - Build confidence with basic programming concepts
 *    - Practice problem-solving step by step
 *    - Prepare for more advanced topics later
 *    - Learn to break down problems into smaller parts
 * 
 * BEGINNER TIPS:
 * - Start with simple problems and gradually increase difficulty
 * - Practice writing functions for different tasks
 * - Test your code with different inputs
 * - Use meaningful variable names
 * - Add comments to explain your logic
 * 
 * NEXT STEPS:
 * - Try modifying the existing functions
 * - Create your own variations of these exercises
 * - Combine different concepts in one program
 * - Practice with user input validation
 * - Experiment with different data types
 */
        cout << "Categories: " << categories.size() << endl;
    }
};

int main() {
    cout << "=== STL Containers Demonstration ===" << endl;
    
    // Demonstrate each container
    demonstrateVector();
    demonstrateMap();
    demonstrateSet();
    demonstrateQueue();
    demonstrateStack();
    demonstrateUnorderedContainers();
    
    /*
     * SECTION 8: Practical Application - Task Manager
     */
    
    cout << "\n=== Task Manager Application ===" << endl;
    
    TaskManager tm;
    
    // Add various tasks
    tm.addTask("Complete project report", 9, "Work");
    tm.addTask("Buy groceries", 5, "Personal");
    tm.addTask("Fix critical bug", 10, "Work");
    tm.addTask("Call dentist", 3, "Personal");
    tm.addTask("Prepare presentation", 8, "Work");
    tm.addTask("Exercise", 6, "Health");
    
    tm.showPendingTasks();
    tm.showTasksByCategory();
    
    // Complete some tasks
    cout << "\nCompleting tasks:" << endl;
    tm.completeNextTask();  // Should complete highest priority first
    tm.completeNextTask();
    tm.completeNextTask();
    
    tm.showTasksByCategory();
    tm.showStatistics();
    
    /*
