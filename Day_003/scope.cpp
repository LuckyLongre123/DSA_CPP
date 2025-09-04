/*
 * Day 3: Variable Scope in C++
 * This file demonstrates different types of variable scope
 * Understanding scope is crucial for avoiding naming conflicts and bugs
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * SECTION 1: Global Variables
 * These are accessible from anywhere in the program
 * Declared outside all functions
 */
int globalCounter = 0;           // Global integer
string globalMessage = "Hello";  // Global string
const double PI = 3.14159;      // Global constant

/*
 * Function prototypes
 */
void demonstrateLocalScope();
void demonstrateGlobalAccess();
void demonstrateParameterScope(int parameter);
void demonstrateShadowing();
void demonstrateBlockScope();
int calculateWithStatic();

int main() {
    cout << "=== Variable Scope Practice ===" << endl;
    
    /*
     * SECTION 2: Local Variables in main()
     * These exist only within main() function
     */
    
    int localVar = 100;        // Local to main()
    string localMessage = "Local in main";
    
    cout << "\n=== Variables in main() ===" << endl;
    cout << "Local variable in main: " << localVar << endl;
    cout << "Local message in main: " << localMessage << endl;
    cout << "Global counter: " << globalCounter << endl;
    cout << "Global message: " << globalMessage << endl;
    
    /*
     * SECTION 3: Demonstrating different scopes
     */
    
    demonstrateLocalScope();
    demonstrateGlobalAccess();
    demonstrateParameterScope(42);
    demonstrateShadowing();
    demonstrateBlockScope();
    
    /*
     * SECTION 4: Static variables
     */
    cout << "\n=== Static Variables ===" << endl;
    for (int i = 0; i < 5; i++) {
        int result = calculateWithStatic();
        cout << "Call " << (i + 1) << ": " << result << endl;
    }
    
    /*
     * SECTION 5: Scope resolution
     * Accessing global variables when local ones have same name
     */
    cout << "\n=== Scope Resolution ===" << endl;
    
    int globalCounter = 999;  // Local variable with same name as global
    cout << "Local globalCounter: " << globalCounter << endl;
    cout << "Global globalCounter: " << ::globalCounter << endl;  // :: accesses global
    
    return 0;
}

/*
 * FUNCTION DEFINITIONS
 */

/*
 * Demonstrates local variable scope
 * Variables declared here exist only in this function
 */
void demonstrateLocalScope() {
    cout << "\n=== Local Scope Demo ===" << endl;
    
    int localNum = 50;           // Local to this function
    string localText = "Function local";
    
    cout << "Local number: " << localNum << endl;
    cout << "Local text: " << localText << endl;
    
    // Can access global variables
    cout << "Global PI: " << PI << endl;
    
    // Modify local variable
    localNum = 75;
    cout << "Modified local number: " << localNum << endl;
    
    // This localNum doesn't affect any other localNum in other functions
}

/*
 * Demonstrates global variable access and modification
 */
void demonstrateGlobalAccess() {
    cout << "\n=== Global Access Demo ===" << endl;
    
    cout << "Global counter before: " << globalCounter << endl;
    globalCounter += 10;  // Modify global variable
    cout << "Global counter after: " << globalCounter << endl;
    
    globalMessage += " World";  // Modify global string
    cout << "Global message: " << globalMessage << endl;
}

/*
 * Demonstrates parameter scope
 * Parameters are local to the function
 */
void demonstrateParameterScope(int parameter) {
    cout << "\n=== Parameter Scope Demo ===" << endl;
    
    cout << "Parameter value: " << parameter << endl;
    parameter = 100;  // This only changes the local copy
    cout << "Modified parameter: " << parameter << endl;
    
    // Parameter acts like a local variable
    int localVar = parameter * 2;
    cout << "Local calculation: " << localVar << endl;
}

/*
 * Demonstrates variable shadowing
 * Local variables can "hide" global variables with the same name
 */
void demonstrateShadowing() {
    cout << "\n=== Variable Shadowing Demo ===" << endl;
    
    string globalMessage = "Local version";  // Shadows global globalMessage
    
    cout << "Local globalMessage: " << globalMessage << endl;
    cout << "Global globalMessage: " << ::globalMessage << endl;  // Access global with ::
    
    // The local version hides the global one within this function
    globalMessage = "Modified local";
    cout << "Modified local: " << globalMessage << endl;
    cout << "Global unchanged: " << ::globalMessage << endl;
}

/*
 * Demonstrates block scope
 * Variables declared in {} blocks have limited scope
 */
void demonstrateBlockScope() {
    cout << "\n=== Block Scope Demo ===" << endl;
    
    int outerVar = 10;
    cout << "Outer variable: " << outerVar << endl;
    
    {  // New block scope
        int innerVar = 20;  // Only exists in this block
        cout << "Inner variable: " << innerVar << endl;
        cout << "Outer variable accessible: " << outerVar << endl;
        
        outerVar = 15;  // Can modify outer variable
        cout << "Modified outer from inner: " << outerVar << endl;
        
        {  // Nested block
            int deepVar = 30;
            cout << "Deep variable: " << deepVar << endl;
            cout << "Inner accessible: " << innerVar << endl;
            cout << "Outer accessible: " << outerVar << endl;
        }
        // deepVar is no longer accessible here
        
    }  // innerVar is no longer accessible here
    
    cout << "Back to outer scope: " << outerVar << endl;
    // cout << innerVar;  // This would cause an error
    
    /*
     * Common use of block scope: for loops
     */
    for (int i = 0; i < 3; i++) {  // i exists only in this loop
        cout << "Loop variable i: " << i << endl;
    }
    // cout << i;  // This would cause an error - i doesn't exist here
    
    /*
     * Another block example: if statements
     */
    if (outerVar > 5) {
        int conditionVar = 100;
        cout << "Condition variable: " << conditionVar << endl;
    }
    // conditionVar doesn't exist here
}

/*
 * Demonstrates static variables
 * Static variables retain their value between function calls
 */
int calculateWithStatic() {
    static int staticCounter = 0;  // Initialized only once
    int regularCounter = 0;        // Initialized every call
    
    staticCounter++;
    regularCounter++;
    
    cout << "  Static: " << staticCounter << ", Regular: " << regularCounter << endl;
    
    return staticCounter;
}

/*
 * Additional examples of scope
 */

/*
 * Function showing scope with same variable names
 */
void scopeExample() {
    int x = 1;  // Local x
    
    {
        int x = 2;  // This x shadows the outer x
        cout << "Inner x: " << x << endl;  // Prints 2
        
        {
            int x = 3;  // This x shadows both outer x's
            cout << "Innermost x: " << x << endl;  // Prints 3
        }
        
        cout << "Back to inner x: " << x << endl;  // Prints 2
    }
    
    cout << "Outer x: " << x << endl;  // Prints 1
}

/*
 * Function demonstrating const scope
 */
void constScopeExample() {
    const int CONSTANT_VALUE = 42;  // Local constant
    
    // CONSTANT_VALUE = 50;  // This would cause an error
    
    cout << "Local constant: " << CONSTANT_VALUE << endl;
}

/*
 * KEY CONCEPTS SUMMARY:
 * 
 * 1. GLOBAL SCOPE:
 *    - Variables declared outside all functions
 *    - Accessible from anywhere in the program
 *    - Exist for the entire program duration
 *    - Use sparingly - can make code hard to debug
 * 
 * 2. LOCAL SCOPE (FUNCTION SCOPE):
 *    - Variables declared inside functions
 *    - Only accessible within that function
 *    - Created when function is called
 *    - Destroyed when function ends
 * 
 * 3. BLOCK SCOPE:
 *    - Variables declared inside {} blocks
 *    - Only accessible within that block
 *    - Includes if statements, loops, etc.
 *    - Most restrictive scope
 * 
 * 4. PARAMETER SCOPE:
 *    - Function parameters are local to that function
 *    - Act like local variables
 *    - Initialized with argument values
 * 
 * 5. STATIC VARIABLES:
 *    - Local variables that retain value between calls
 *    - Initialized only once
 *    - Useful for counters and state preservation
 * 
 * 6. VARIABLE SHADOWING:
 *    - Inner scope variables can hide outer scope variables
 *    - Use :: to access global variables when shadowed
 *    - Generally avoid - can be confusing
 * 
 * BEST PRACTICES:
 * - Minimize use of global variables
 * - Use most restrictive scope possible
 * - Avoid variable shadowing when possible
 * - Use meaningful names to avoid conflicts
 * - Declare variables close to where they're used
 * 
 * COMMON MISTAKES:
 * - Trying to access variables outside their scope
 * - Accidentally shadowing important variables
 * - Relying too heavily on global variables
 * - Not understanding when variables are created/destroyed
 */
