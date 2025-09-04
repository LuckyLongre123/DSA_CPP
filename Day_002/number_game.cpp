/*
 * Day 2: Number Guessing Game Project
 * This project combines conditionals and loops to create an interactive game
 * Great practice for decision making and user interaction
 */

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    cout << "=== Number Guessing Game ===" << endl;
    cout << "I'm thinking of a number between 1 and 100!" << endl;
    cout << "Can you guess it?" << endl;
    
    /*
     * SECTION 1: Game Setup
     * Generate random number and initialize variables
     */
    
    // Seed the random number generator with current time
    srand(time(0));
    
    // Generate random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    
    int userGuess;
    int attempts = 0;
    int maxAttempts = 7;
    bool hasWon = false;
    
    /*
     * SECTION 2: Main Game Loop
     * Keep asking for guesses until win or max attempts reached
     */
    
    while (attempts < maxAttempts && !hasWon) {
        attempts++;
        
        cout << "\nAttempt " << attempts << " of " << maxAttempts << endl;
        cout << "Enter your guess (1-100): ";
        cin >> userGuess;
        
        /*
         * Input validation
         * Make sure guess is in valid range
         */
        if (userGuess < 1 || userGuess > 100) {
            cout << "Please enter a number between 1 and 100!" << endl;
            attempts--;  // Don't count invalid attempts
            continue;    // Skip to next iteration
        }
        
        /*
         * Check the guess and provide feedback
         */
        if (userGuess == secretNumber) {
            hasWon = true;
            cout << "🎉 Congratulations! You guessed it!" << endl;
            cout << "The number was " << secretNumber << endl;
            cout << "You won in " << attempts << " attempts!" << endl;
        }
        else if (userGuess < secretNumber) {
            cout << "Too low! Try a higher number." << endl;
            
            // Give additional hints based on how close they are
            int difference = secretNumber - userGuess;
            if (difference <= 5) {
                cout << "You're very close!" << endl;
            } else if (difference <= 15) {
                cout << "You're getting warm!" << endl;
            } else {
                cout << "You're quite far off." << endl;
            }
        }
        else {  // userGuess > secretNumber
            cout << "Too high! Try a lower number." << endl;
            
            // Give additional hints based on how close they are
            int difference = userGuess - secretNumber;
            if (difference <= 5) {
                cout << "You're very close!" << endl;
            } else if (difference <= 15) {
                cout << "You're getting warm!" << endl;
            } else {
                cout << "You're quite far off." << endl;
            }
        }
        
        /*
         * Show remaining attempts if not won
         */
        if (!hasWon && attempts < maxAttempts) {
            cout << "Attempts remaining: " << (maxAttempts - attempts) << endl;
        }
    }
    
    /*
     * SECTION 3: Game Over
     * Handle win/lose scenarios
     */
    
    if (!hasWon) {
        cout << "\n💔 Game Over! You've used all " << maxAttempts << " attempts." << endl;
        cout << "The secret number was: " << secretNumber << endl;
        cout << "Better luck next time!" << endl;
    }
    
    /*
     * SECTION 4: Play Again Option
     * Ask if user wants to play another round
     */
    
    char playAgain;
    cout << "\nWould you like to play again? (y/n): ";
    cin >> playAgain;
    
    if (playAgain == 'y' || playAgain == 'Y') {
        cout << "\nStarting new game..." << endl;
        
        // Reset game variables
        srand(time(0));  // New random seed
        secretNumber = rand() % 100 + 1;
        attempts = 0;
        hasWon = false;
        
        // Second game loop (simplified version)
        while (attempts < maxAttempts && !hasWon) {
            attempts++;
            cout << "\nAttempt " << attempts << ": ";
            cin >> userGuess;
            
            if (userGuess == secretNumber) {
                hasWon = true;
                cout << "🎉 You won again! Number was " << secretNumber << endl;
            } else if (userGuess < secretNumber) {
                cout << "Too low!" << endl;
            } else {
                cout << "Too high!" << endl;
            }
        }
        
        if (!hasWon) {
            cout << "Game over! The number was " << secretNumber << endl;
        }
    }
    
    /*
     * SECTION 5: Game Statistics
     * Show some interesting statistics
     */
    
    cout << "\n=== Game Statistics ===" << endl;
    cout << "Total attempts made: " << attempts << endl;
    
    if (hasWon) {
        if (attempts == 1) {
            cout << "Amazing! You got it in one try!" << endl;
        } else if (attempts <= 3) {
            cout << "Excellent! Very few attempts needed." << endl;
        } else if (attempts <= 5) {
            cout << "Good job! Reasonable number of attempts." << endl;
        } else {
            cout << "You made it! That was close." << endl;
        }
    }
    
    cout << "\nThank you for playing!" << endl;
    
    return 0;
}

/*
 * GAME FEATURES IMPLEMENTED:
 * 
 * 1. Random number generation
 * 2. Input validation
 * 3. Attempt limiting
 * 4. Hint system (too high/low + closeness)
 * 5. Win/lose conditions
 * 6. Play again functionality
 * 7. Game statistics
 * 
 * CONCEPTS USED:
 * - while loops for game continuation
 * - if-else for decision making
 * - break and continue for loop control
 * - Boolean variables for game state
 * - Random number generation
 * - Input validation
 * 
 * POSSIBLE ENHANCEMENTS:
 * 1. Difficulty levels (different ranges)
 * 2. Score system based on attempts
 * 3. High score tracking
 * 4. Multiple players
 * 5. Hint system improvements
 * 6. Better input validation
 * 7. Color output (if supported)
 * 
 * LEARNING OUTCOMES:
 * - Combining loops and conditionals
 * - Game state management
 * - User experience considerations
 * - Input validation importance
 * - Random number usage
 */
