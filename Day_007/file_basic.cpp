/*
 * Day 7: Simple Text Processing for Beginners
 * This file demonstrates basic text and string operations
 * Focus on string manipulation instead of complex file I/O
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "=== Simple Text Processing for Beginners ===" << endl;
    
    /*
     * SECTION 1: Basic String Operations
     * Working with text and strings
     */
    
    cout << "\n=== String Basics ===" << endl;
    
    string firstName = "John";
    string lastName = "Doe";
    string fullName = firstName + " " + lastName;
    
    cout << "First name: " << firstName << endl;
    cout << "Last name: " << lastName << endl;
    cout << "Full name: " << fullName << endl;
    cout << "Name length: " << fullName.length() << " characters" << endl;
    
    /*
     * SECTION 2: String Input and Processing
     * Getting text from user and working with it
     */
    
    cout << "\n=== String Input ===" << endl;
    
    string userInput;
    cout << "Enter your favorite color: ";
    cin >> userInput;
    
    cout << "You entered: " << userInput << endl;
    cout << "Length: " << userInput.length() << " characters" << endl;
    
    // Convert to uppercase (simple method)
    string upperCase = userInput;
    for (int i = 0; i < upperCase.length(); i++) {
        if (upperCase[i] >= 'a' && upperCase[i] <= 'z') {
            upperCase[i] = upperCase[i] - 'a' + 'A';
        }
    }
    cout << "Uppercase: " << upperCase << endl;
    
    /*
     * SECTION 3: String Comparison and Searching
     */
    
    cout << "\n=== String Comparison ===" << endl;
    
    string word1 = "apple";
    string word2 = "banana";
    string word3 = "apple";
    
    cout << "Comparing strings:" << endl;
    cout << word1 << " == " << word2 << ": " << (word1 == word2 ? "true" : "false") << endl;
    cout << word1 << " == " << word3 << ": " << (word1 == word3 ? "true" : "false") << endl;
    
    // Simple search
    string sentence = "The quick brown fox jumps";
    string searchWord = "fox";
    
    if (sentence.find(searchWord) != string::npos) {
        cout << "Found '" << searchWord << "' in the sentence" << endl;
    } else {
        cout << "'" << searchWord << "' not found" << endl;
    }
    
    /*
     * SECTION 4: Working with Multiple Strings
     */
    
    cout << "\n=== String Arrays ===" << endl;
    
    string fruits[5] = {"apple", "banana", "orange", "grape", "mango"};
    
    cout << "Fruit list:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << (i + 1) << ". " << fruits[i] << endl;
    }
    
    // Find longest fruit name
    string longest = fruits[0];
    for (int i = 1; i < 5; i++) {
        if (fruits[i].length() > longest.length()) {
            longest = fruits[i];
        }
    }
    cout << "Longest fruit name: " << longest << " (" << longest.length() << " letters)" << endl;
    
    /*
     * SECTION 5: Simple Text Games
     */
    
    cout << "\n=== Word Guessing Game ===" << endl;
    
    string secretWord = "programming";
    string guessedWord = "___________";  // Same length as secret word
    
    cout << "Secret word (" << secretWord.length() << " letters): " << guessedWord << endl;
    
    char guess;
    cout << "Guess a letter: ";
    cin >> guess;
    
    bool found = false;
    for (int i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == guess) {
            guessedWord[i] = guess;
            found = true;
        }
    }
    
    if (found) {
        cout << "Good guess! Word now: " << guessedWord << endl;
    } else {
        cout << "Letter not found. Try again!" << endl;
    }
    
    /*
     * PRACTICE EXERCISES FOR BEGINNERS:
     */
    
    cout << "\n=== Practice Exercises ===" << endl;
    cout << "Try these exercises on your own:" << endl;
    cout << "1. Create a program to count vowels in a sentence" << endl;
    cout << "2. Make a simple password checker" << endl;
    cout << "3. Build a program to reverse a string" << endl;
    cout << "4. Create a word counter for sentences" << endl;
    cout << "5. Make a simple text-based menu system" << endl;
    
    return 0;
}

/*
 * SIMPLE TEXT PROCESSING CONCEPTS FOR BEGINNERS:
 * 
 * 1. STRING BASICS:
 *    - string variable = "text"; - Create string
 *    - variable.length() - Get string length
 *    - variable[i] - Access character at position i
 *    - string1 + string2 - Combine strings
 * 
 * 2. STRING INPUT:
 *    - cin >> variable; - Read single word
 *    - getline(cin, variable); - Read full line
 *    - Always check what user enters
 * 
 * 3. STRING COMPARISON:
 *    - string1 == string2 - Check if equal
 *    - string1 != string2 - Check if different
 *    - Can compare with < and > for alphabetical order
 * 
 * 4. CHARACTER ANALYSIS:
 *    - Check if letter: (c >= 'A' && c <= 'Z')
 *    - Check if digit: (c >= '0' && c <= '9')
 *    - Convert case: c - 'a' + 'A' (lowercase to uppercase)
 * 
 * 5. STRING SEARCHING:
 *    - variable.find("text") - Find text in string
 *    - Returns position or string::npos if not found
 *    - Use loops to search character by character
 * 
 * BEGINNER TIPS:
 * - Start with simple string operations
 * - Practice with user input and output
 * - Use loops to process each character
 * - Build simple text-based programs
 * - Always validate user input
 * 
 * PRACTICE IDEAS:
 * - Make a name formatter
 * - Create a simple word game
 * - Build a character counter
 * - Make a text analyzer
 * - Create interactive text menus
 */
