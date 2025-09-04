/*
 * Day 10: Simple Programming Projects
 * This file contains beginner-friendly projects that practice
 * basic programming concepts learned in the previous days
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * PROJECT 1: Simple Grade Calculator
 * Practice with basic math operations and arrays
 */

void gradeCalculator() {
    cout << "\n=== Grade Calculator ===" << endl;
    
    int numSubjects;
    cout << "How many subjects? ";
    cin >> numSubjects;
    
    if (numSubjects <= 0 || numSubjects > 10) {
        cout << "Please enter between 1 and 10 subjects." << endl;
        return;
    }
    
    int grades[10];
    int total = 0;
    
    cout << "Enter grades (0-100):" << endl;
    for (int i = 0; i < numSubjects; i++) {
        cout << "Subject " << (i + 1) << ": ";
        cin >> grades[i];
        
        if (grades[i] < 0 || grades[i] > 100) {
            cout << "Invalid grade! Using 0." << endl;
            grades[i] = 0;
        }
        
        total += grades[i];
    }
    
    double average = (double)total / numSubjects;
    
    cout << "\n--- Results ---" << endl;
    cout << "Total: " << total << endl;
    cout << "Average: " << average << endl;
    
    if (average >= 90) {
        cout << "Grade: A (Excellent!)" << endl;
    } else if (average >= 80) {
        cout << "Grade: B (Good!)" << endl;
    } else if (average >= 70) {
        cout << "Grade: C (Average)" << endl;
    } else if (average >= 60) {
        cout << "Grade: D (Below Average)" << endl;
    } else {
        cout << "Grade: F (Needs Improvement)" << endl;
}

/*
 * PROJECT 2: Simple Number Pattern Generator
 * Practice with nested loops and pattern printing
 */

void patternGenerator() {
    cout << "\n=== Pattern Generator ===" << endl;
    
    int choice;
    cout << "Choose a pattern:" << endl;
    cout << "1. Triangle of stars" << endl;
    cout << "2. Square of numbers" << endl;
    cout << "3. Pyramid pattern" << endl;
    cout << "Enter choice (1-3): ";
    cin >> choice;
    
    int size;
    cout << "Enter size: ";
    cin >> size;
    
    if (size <= 0 || size > 10) {
        cout << "Please enter size between 1 and 10." << endl;
        return;
    }
    
    switch (choice) {
        case 1:
            cout << "\nTriangle of stars:" << endl;
            for (int i = 1; i <= size; i++) {
                for (int j = 1; j <= i; j++) {
                    cout << "* ";
                }
                cout << endl;
            }
            break;
            
        case 2:
            cout << "\nSquare of numbers:" << endl;
            for (int i = 1; i <= size; i++) {
                for (int j = 1; j <= size; j++) {
                    cout << j << " ";
                }
                cout << endl;
            }
            break;
            
        case 3:
            cout << "\nPyramid pattern:" << endl;
            for (int i = 1; i <= size; i++) {
                // Print spaces
                for (int j = 1; j <= size - i; j++) {
                    cout << " ";
                }
                // Print stars
                for (int j = 1; j <= i; j++) {
                    cout << "* ";
                }
                cout << endl;
            }
            break;
            
        default:
            cout << "Invalid choice!" << endl;
    }
}

/*
 * PROJECT 3: Simple Word Game
 * Practice with strings and basic game logic
 */

void wordGame() {
    cout << "\n=== Word Guessing Game ===" << endl;
    
    string words[5] = {"programming", "computer", "keyboard", "monitor", "software"};
    int randomIndex = 2; // Simple selection for beginners
    string secretWord = words[randomIndex];
    
    string guessedWord = "";
    for (int i = 0; i < secretWord.length(); i++) {
        guessedWord += "_";
    }
    
    int attempts = 6;
    bool gameWon = false;
    
    cout << "Guess the word: " << guessedWord << endl;
    cout << "You have " << attempts << " attempts." << endl;
    
    while (attempts > 0 && !gameWon) {
        char guess;
        cout << "\nEnter a letter: ";
        cin >> guess;
        
        // Convert to lowercase
        if (guess >= 'A' && guess <= 'Z') {
            guess = guess + 32;
        }
        
        bool found = false;
        for (int i = 0; i < secretWord.length(); i++) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                found = true;
            }
        }
        
        if (found) {
            cout << "Good guess! " << guessedWord << endl;
        } else {
            attempts--;
            cout << "Wrong guess! Attempts left: " << attempts << endl;
        }
        
        // Check if word is complete
        if (guessedWord == secretWord) {
            gameWon = true;
        }
    }
    
    if (gameWon) {
        cout << "\nCongratulations! You guessed the word: " << secretWord << endl;
    } else {
        cout << "\nGame over! The word was: " << secretWord << endl;
}

int main() {
    cout << "=== Simple Programming Projects ===" << endl;
    
    int choice;
    
    do {
        cout << "\n--- Project Menu ---" << endl;
        cout << "1. Grade Calculator" << endl;
        cout << "2. Pattern Generator" << endl;
        cout << "3. Word Guessing Game" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose a project (1-4): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                gradeCalculator();
                break;
            case 2:
                patternGenerator();
                break;
            case 3:
                wordGame();
                break;
            case 4:
                cout << "Thank you for trying the projects!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        
    } while (choice != 4);
    
    cout << "\n=== Programming Projects Complete! ===" << endl;
    
    return 0;
}

/*
 * SIMPLE PROGRAMMING PROJECTS FOR BEGINNERS:
 * 
 * 1. GRADE CALCULATOR:
 *    - Practice with arrays and basic math operations
 *    - Learn input validation and conditional statements
 *    - Calculate averages and assign letter grades
 * 
 * 2. PATTERN GENERATOR:
 *    - Practice with nested loops
 *    - Learn about different loop patterns
 *    - Create visual output with stars and numbers
 * 
 * 3. WORD GUESSING GAME:
 *    - Practice with strings and character manipulation
 *    - Learn basic game logic and loops
 *    - Handle user input and game state
 * 
 * 4. WHY THESE PROJECTS:
 *    - Combine multiple programming concepts
 *    - Build confidence with complete programs
 *    - Practice problem-solving skills
 *    - Create interactive applications
 * 
 * BEGINNER TIPS:
 * - Start with one project at a time
 * - Test each part of your code as you write it
 * - Use meaningful variable names
 * - Add comments to explain your logic
 * - Don't be afraid to experiment and modify the code
 * 
 * NEXT STEPS:
 * - Try adding new features to these projects
 * - Create your own variations
 * - Combine concepts from different projects
 * - Practice with different data types and operations
 * - Build more complex interactive programs
 */
