/*
 * Day 2: Pattern Printing with Loops
 * This file demonstrates how to create various patterns using nested loops
 * Great practice for understanding loop logic and visualization
 */

#include <iostream>

using namespace std;

int main() {
    cout << "=== Pattern Printing Practice ===" << endl;
    
    /*
     * SECTION 1: Basic Star Patterns
     * Simple patterns to understand nested loop logic
     */
    
    cout << "\n=== Pattern 1: Right Triangle ===" << endl;
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= row; col++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    cout << "\n=== Pattern 2: Inverted Right Triangle ===" << endl;
    for (int row = 5; row >= 1; row--) {
        for (int col = 1; col <= row; col++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    cout << "\n=== Pattern 3: Left Triangle (with spaces) ===" << endl;
    for (int row = 1; row <= 5; row++) {
        // Print spaces
        for (int space = 1; space <= 5 - row; space++) {
            cout << "  ";
        }
        // Print stars
        for (int col = 1; col <= row; col++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    /*
     * SECTION 2: Number Patterns
     * Using numbers instead of stars
     */
    
    cout << "\n=== Pattern 4: Number Triangle ===" << endl;
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= row; col++) {
            cout << col << " ";
        }
        cout << endl;
    }
    
    cout << "\n=== Pattern 5: Repeated Number Triangle ===" << endl;
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= row; col++) {
            cout << row << " ";
        }
        cout << endl;
    }
    
    cout << "\n=== Pattern 6: Sequential Numbers ===" << endl;
    int num = 1;
    for (int row = 1; row <= 4; row++) {
        for (int col = 1; col <= row; col++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    
    /*
     * SECTION 3: Advanced Star Patterns
     * More complex patterns requiring careful logic
     */
    
    cout << "\n=== Pattern 7: Full Pyramid ===" << endl;
    for (int row = 1; row <= 5; row++) {
        // Print leading spaces
        for (int space = 1; space <= 5 - row; space++) {
            cout << " ";
        }
        // Print stars
        for (int col = 1; col <= 2 * row - 1; col++) {
            cout << "*";
        }
        cout << endl;
    }
    
    cout << "\n=== Pattern 8: Inverted Pyramid ===" << endl;
    for (int row = 5; row >= 1; row--) {
        // Print leading spaces
        for (int space = 1; space <= 5 - row; space++) {
            cout << " ";
        }
        // Print stars
        for (int col = 1; col <= 2 * row - 1; col++) {
            cout << "*";
        }
        cout << endl;
    }
    
    cout << "\n=== Pattern 9: Diamond ===" << endl;
    // Upper half (including middle)
    for (int row = 1; row <= 5; row++) {
        for (int space = 1; space <= 5 - row; space++) {
            cout << " ";
        }
        for (int col = 1; col <= 2 * row - 1; col++) {
            cout << "*";
        }
        cout << endl;
    }
    // Lower half
    for (int row = 4; row >= 1; row--) {
        for (int space = 1; space <= 5 - row; space++) {
            cout << " ";
        }
        for (int col = 1; col <= 2 * row - 1; col++) {
            cout << "*";
        }
        cout << endl;
    }
    
    /*
     * SECTION 4: Hollow Patterns
     * Patterns with empty spaces inside
     */
    
    cout << "\n=== Pattern 10: Hollow Square ===" << endl;
    int size = 5;
    for (int row = 1; row <= size; row++) {
        for (int col = 1; col <= size; col++) {
            // Print star if it's border, space if it's inside
            if (row == 1 || row == size || col == 1 || col == size) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    
    cout << "\n=== Pattern 11: Hollow Triangle ===" << endl;
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= row; col++) {
            // Print star if it's border of triangle
            if (col == 1 || col == row || row == 5) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    
    /*
     * SECTION 5: Interactive Pattern Generator
     * Let user choose pattern size
     */
    
    cout << "\n=== Interactive Pattern Generator ===" << endl;
    
    int userSize;
    cout << "Enter size for your custom triangle (1-10): ";
    cin >> userSize;
    
    // Validate input
    if (userSize < 1 || userSize > 10) {
        cout << "Invalid size! Using default size 5." << endl;
        userSize = 5;
    }
    
    cout << "\nYour custom right triangle:" << endl;
    for (int row = 1; row <= userSize; row++) {
        for (int col = 1; col <= row; col++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    /*
     * SECTION 6: Character Patterns
     * Using letters instead of stars or numbers
     */
    
    cout << "\n=== Pattern 12: Alphabet Triangle ===" << endl;
    for (int row = 1; row <= 5; row++) {
        char ch = 'A';
        for (int col = 1; col <= row; col++) {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
    
    cout << "\n=== Pattern 13: Repeated Letter Triangle ===" << endl;
    for (int row = 1; row <= 5; row++) {
        char ch = 'A' + row - 1;  // A=0, B=1, C=2, etc.
        for (int col = 1; col <= row; col++) {
            cout << ch << " ";
        }
        cout << endl;
    }
    
    /*
     * SECTION 7: Mathematical Patterns
     * Patterns based on mathematical sequences
     */
    
    cout << "\n=== Pattern 14: Even Numbers Triangle ===" << endl;
    for (int row = 1; row <= 5; row++) {
        int evenNum = 2;
        for (int col = 1; col <= row; col++) {
            cout << evenNum << " ";
            evenNum += 2;
        }
        cout << endl;
    }
    
    cout << "\n=== Pattern 15: Fibonacci Triangle ===" << endl;
    int fib1 = 0, fib2 = 1;
    for (int row = 1; row <= 4; row++) {
        for (int col = 1; col <= row; col++) {
            if (col == 1) {
                cout << fib1 << " ";
            } else {
                cout << fib2 << " ";
                int nextFib = fib1 + fib2;
                fib1 = fib2;
                fib2 = nextFib;
            }
        }
        cout << endl;
    }
    
    cout << "\n=== Pattern Printing Complete! ===" << endl;
    cout << "Try creating your own patterns!" << endl;
    
    return 0;
}

/*
 * PATTERN PRINTING CONCEPTS:
 * 
 * 1. NESTED LOOPS:
 *    - Outer loop controls rows
 *    - Inner loop controls columns
 *    - Think in terms of (row, column) coordinates
 * 
 * 2. COMMON PATTERNS:
 *    - Right triangle: columns = row number
 *    - Left triangle: add spaces before stars
 *    - Pyramid: spaces + stars in specific formula
 *    - Hollow: print stars only at borders
 * 
 * 3. PATTERN FORMULAS:
 *    - Right triangle: cols <= row
 *    - Pyramid spaces: cols <= (total_rows - current_row)
 *    - Pyramid stars: cols <= (2 * current_row - 1)
 *    - Diamond: combine pyramid + inverted pyramid
 * 
 * 4. DEBUGGING TIPS:
 *    - Start with simple patterns
 *    - Print row/column numbers to understand logic
 *    - Draw pattern on paper first
 *    - Test with small sizes (3-5 rows)
 * 
 * 5. PRACTICE EXERCISES:
 *    - Create a heart pattern
 *    - Make a checkerboard pattern
 *    - Create patterns with mixed characters
 *    - Try creating 3D-looking patterns
 * 
 * COMMON MISTAKES:
 * - Confusing row and column logic
 * - Off-by-one errors in loop conditions
 * - Forgetting to print newlines
 * - Incorrect space calculations for centered patterns
 */
