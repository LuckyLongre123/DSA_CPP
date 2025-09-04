/*
 * Day 4: Strings in C++
 * This file demonstrates string class operations and character arrays
 * Strings are essential for text processing and user interaction
 */

#include <iostream>
#include <string>
#include <cctype>  // For character functions

using namespace std;

int main() {
    cout << "=== Strings in C++ ===" << endl;
    
    /*
     * SECTION 1: String Declaration and Initialization
     * Different ways to create strings
     */
    
    cout << "\n=== String Declaration ===" << endl;
    
    // Method 1: Direct initialization
    string greeting = "Hello World";
    
    // Method 2: Constructor initialization
    string name("Alice");
    
    // Method 3: Empty string
    string empty;
    
    // Method 4: Fill constructor
    string repeated(5, 'A');  // "AAAAA"
    
    // Method 5: From another string
    string copy = greeting;
    
    cout << "Greeting: " << greeting << endl;
    cout << "Name: " << name << endl;
    cout << "Empty: '" << empty << "'" << endl;
    cout << "Repeated: " << repeated << endl;
    cout << "Copy: " << copy << endl;
    
    /*
     * SECTION 2: String Input and Output
     */
    
    cout << "\n=== String Input/Output ===" << endl;
    
    string firstName, lastName, fullSentence;
    
    cout << "Enter your first name: ";
    cin >> firstName;  // Reads until whitespace
    
    cout << "Enter your last name: ";
    cin >> lastName;
    
    cin.ignore();  // Clear input buffer
    cout << "Enter a full sentence: ";
    getline(cin, fullSentence);  // Reads entire line
    
    cout << "First name: " << firstName << endl;
    cout << "Last name: " << lastName << endl;
    cout << "Full sentence: " << fullSentence << endl;
    
    /*
     * SECTION 3: String Properties and Basic Operations
     */
    
    cout << "\n=== String Properties ===" << endl;
    
    string text = "Programming";
    
    cout << "Text: " << text << endl;
    cout << "Length: " << text.length() << endl;
    cout << "Size: " << text.size() << endl;  // Same as length()
    cout << "Is empty: " << (text.empty() ? "Yes" : "No") << endl;
    cout << "Capacity: " << text.capacity() << endl;
    
    // Accessing individual characters
    cout << "First character: " << text[0] << endl;
    cout << "Last character: " << text[text.length() - 1] << endl;
    cout << "Character at index 3: " << text.at(3) << endl;  // Safer than []
    
    /*
     * SECTION 4: String Concatenation
     */
    
    cout << "\n=== String Concatenation ===" << endl;
    
    string first = "Hello";
    string second = "World";
    
    // Method 1: Using + operator
    string combined1 = first + " " + second;
    cout << "Combined with +: " << combined1 << endl;
    
    // Method 2: Using += operator
    string combined2 = first;
    combined2 += " ";
    combined2 += second;
    cout << "Combined with +=: " << combined2 << endl;
    
    // Method 3: Using append()
    string combined3 = first;
    combined3.append(" ").append(second);
    cout << "Combined with append(): " << combined3 << endl;
    
    /*
     * SECTION 5: String Comparison
     */
    
    cout << "\n=== String Comparison ===" << endl;
    
    string str1 = "apple";
    string str2 = "banana";
    string str3 = "apple";
    
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    
    cout << "str1 == str2: " << (str1 == str2 ? "true" : "false") << endl;
    cout << "str1 == str3: " << (str1 == str3 ? "true" : "false") << endl;
    cout << "str1 < str2: " << (str1 < str2 ? "true" : "false") << endl;  // Lexicographic
    cout << "str1 > str2: " << (str1 > str2 ? "true" : "false") << endl;
    
    // Using compare() method
    int result = str1.compare(str2);
    cout << "str1.compare(str2): " << result;
    if (result < 0) cout << " (str1 < str2)";
    else if (result > 0) cout << " (str1 > str2)";
    else cout << " (str1 == str2)";
    cout << endl;
    
    /*
     * SECTION 6: String Searching
     */
    
    cout << "\n=== String Searching ===" << endl;
    
    string sentence = "The quick brown fox jumps over the lazy dog";
    
    cout << "Sentence: " << sentence << endl;
    
    // Find substring
    size_t pos = sentence.find("fox");
    if (pos != string::npos) {
        cout << "'fox' found at position: " << pos << endl;
    } else {
        cout << "'fox' not found" << endl;
    }
    
    // Find character
    pos = sentence.find('o');
    cout << "First 'o' found at position: " << pos << endl;
    
    // Find last occurrence
    pos = sentence.rfind('o');
    cout << "Last 'o' found at position: " << pos << endl;
    
    // Count occurrences of a character
    int count = 0;
    for (char c : sentence) {
        if (c == 'o') count++;
    }
    cout << "Number of 'o' characters: " << count << endl;
    
    /*
     * SECTION 7: String Modification
     */
    
    cout << "\n=== String Modification ===" << endl;
    
    string modifiable = "Hello World";
    cout << "Original: " << modifiable << endl;
    
    // Change individual character
    modifiable[6] = 'w';
    cout << "After changing index 6: " << modifiable << endl;
    
    // Insert substring
    modifiable.insert(5, " Beautiful");
    cout << "After insert: " << modifiable << endl;
    
    // Erase part of string
    modifiable.erase(5, 10);  // Remove 10 characters starting at position 5
    cout << "After erase: " << modifiable << endl;
    
    // Replace part of string
    modifiable.replace(6, 5, "Universe");
    cout << "After replace: " << modifiable << endl;
    
    /*
     * SECTION 8: Substring Operations
     */
    
    cout << "\n=== Substring Operations ===" << endl;
    
    string original = "Programming is fun and challenging";
    cout << "Original: " << original << endl;
    
    // Extract substring
    string sub1 = original.substr(0, 11);  // From position 0, length 11
    cout << "First 11 characters: " << sub1 << endl;
    
    string sub2 = original.substr(15);  // From position 15 to end
    cout << "From position 15: " << sub2 << endl;
    
    string sub3 = original.substr(12, 3);  // 3 characters starting at position 12
    cout << "3 chars from position 12: " << sub3 << endl;
    
    /*
     * SECTION 9: Character Analysis
     */
    
    cout << "\n=== Character Analysis ===" << endl;
    
    string testStr = "Hello123 World!";
    cout << "Test string: " << testStr << endl;
    
    int letters = 0, digits = 0, spaces = 0, others = 0;
    
    for (char c : testStr) {
        if (isalpha(c)) {
            letters++;
        } else if (isdigit(c)) {
            digits++;
        } else if (isspace(c)) {
            spaces++;
        } else {
            others++;
        }
    }
    
    cout << "Letters: " << letters << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl;
    cout << "Other characters: " << others << endl;
    
    /*
     * SECTION 10: Case Conversion
     */
    
    cout << "\n=== Case Conversion ===" << endl;
    
    string mixedCase = "Hello World 123";
    cout << "Original: " << mixedCase << endl;
    
    // Convert to uppercase
    string uppercase = mixedCase;
    for (char& c : uppercase) {
        c = toupper(c);
    }
    cout << "Uppercase: " << uppercase << endl;
    
    // Convert to lowercase
    string lowercase = mixedCase;
    for (char& c : lowercase) {
        c = tolower(c);
    }
    cout << "Lowercase: " << lowercase << endl;
    
    /*
     * SECTION 11: String Reversal
     */
    
    cout << "\n=== String Reversal ===" << endl;
    
    string toReverse = "Programming";
    cout << "Original: " << toReverse << endl;
    
    string reversed = "";
    for (int i = toReverse.length() - 1; i >= 0; i--) {
        reversed += toReverse[i];
    }
    cout << "Reversed: " << reversed << endl;
    
    // Alternative method using reverse iterators
    string reversed2(toReverse.rbegin(), toReverse.rend());
    cout << "Reversed (method 2): " << reversed2 << endl;
    
    /*
     * SECTION 12: Palindrome Check
     */
    
    cout << "\n=== Palindrome Check ===" << endl;
    
    string palindromes[] = {"racecar", "hello", "madam", "world", "level"};
    
    for (const string& word : palindromes) {
        bool isPalindrome = true;
        int len = word.length();
        
        for (int i = 0; i < len / 2; i++) {
            if (word[i] != word[len - 1 - i]) {
                isPalindrome = false;
                break;
            }
        }
        
        cout << "'" << word << "' is " << (isPalindrome ? "a palindrome" : "not a palindrome") << endl;
    }
    
    cout << "\n=== Strings Complete! ===" << endl;
    
    return 0;
}

/*
 * STRING CLASS KEY CONCEPTS:
 * 
 * 1. STRING DECLARATION:
 *    - string str = "Hello";
 *    - string str("Hello");
 *    - string str(5, 'A'); // "AAAAA"
 * 
 * 2. STRING INPUT:
 *    - cin >> str; // Reads until whitespace
 *    - getline(cin, str); // Reads entire line
 *    - Remember cin.ignore() after cin >>
 * 
 * 3. STRING PROPERTIES:
 *    - str.length() or str.size() // Get length
 *    - str.empty() // Check if empty
 *    - str.capacity() // Current capacity
 * 
 * 4. CHARACTER ACCESS:
 *    - str[index] // Direct access (no bounds check)
 *    - str.at(index) // Safe access (throws exception)
 *    - str.front() // First character
 *    - str.back() // Last character
 * 
 * 5. STRING OPERATIONS:
 *    - Concatenation: str1 + str2, str1 += str2
 *    - Comparison: ==, !=, <, >, <=, >=
 *    - Search: find(), rfind(), find_first_of()
 *    - Modification: insert(), erase(), replace()
 *    - Substring: substr(pos, len)
 * 
 * 6. CHARACTER FUNCTIONS (cctype):
 *    - isalpha(c) // Is letter
 *    - isdigit(c) // Is digit
 *    - isspace(c) // Is whitespace
 *    - toupper(c) // Convert to uppercase
 *    - tolower(c) // Convert to lowercase
 * 
 * ADVANTAGES OF string CLASS:
 * - Dynamic size (can grow/shrink)
 * - Rich set of member functions
 * - Safe (bounds checking with at())
 * - Easy concatenation and comparison
 * - Automatic memory management
 * 
 * COMMON OPERATIONS:
 * - Text processing
 * - User input handling
 * - File name manipulation
 * - Data parsing
 * - Pattern matching
 * 
 * BEST PRACTICES:
 * - Use string class over char arrays
 * - Use getline() for full line input
 * - Check string::npos for find() results
 * - Use at() for safe access when needed
 * - Initialize strings to avoid undefined behavior
 */
