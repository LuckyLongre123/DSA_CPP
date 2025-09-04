/*
 * Day 5: Dynamic Memory Allocation in C++
 * This file demonstrates new/delete operators for runtime memory allocation
 * Dynamic memory allows creating variables whose size is determined at runtime
 */

#include <iostream>

using namespace std;

int main() {
    cout << "=== Dynamic Memory Allocation ===" << endl;
    
    /*
     * SECTION 1: Basic Dynamic Allocation
     * Using new operator to allocate memory at runtime
     */
    
    cout << "\n=== Basic new/delete ===" << endl;
    
    // Allocate single integer
    int* dynamicInt = new int(42);  // Allocate and initialize
    cout << "Dynamic integer value: " << *dynamicInt << endl;
    cout << "Address: " << dynamicInt << endl;
    
    // Modify the value
    *dynamicInt = 100;
    cout << "Modified value: " << *dynamicInt << endl;
    
    // Free the memory (very important!)
    delete dynamicInt;
    dynamicInt = nullptr;  // Good practice to avoid dangling pointer
    
    cout << "Memory freed and pointer set to nullptr" << endl;
    
    /*
     * SECTION 2: Dynamic Arrays
     * Allocating arrays whose size is determined at runtime
     */
    
    cout << "\n=== Dynamic Arrays ===" << endl;
    
    int size;
    cout << "Enter array size: ";
    cin >> size;
    
    // Allocate dynamic array
    int* dynamicArray = new int[size];
    
    // Initialize array
    cout << "Enter " << size << " numbers:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element " << i << ": ";
        cin >> dynamicArray[i];
    }
    
    // Display array
    cout << "Your array: ";
    for (int i = 0; i < size; i++) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;
    
    // Calculate sum
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += dynamicArray[i];
    }
    cout << "Sum: " << sum << endl;
    cout << "Average: " << (double)sum / size << endl;
    
    // Free array memory
    delete[] dynamicArray;  // Note: delete[] for arrays
    dynamicArray = nullptr;
    
    cout << "Dynamic array memory freed" << endl;
    
    /*
     * SECTION 3: Dynamic vs Static Memory Comparison
     */
    
    cout << "\n=== Dynamic vs Static Memory ===" << endl;
    
    // Static allocation (on stack)
    int staticArray[5] = {1, 2, 3, 4, 5};
    cout << "Static array address: " << staticArray << endl;
    
    // Dynamic allocation (on heap)
    int* heapArray = new int[5]{10, 20, 30, 40, 50};
    cout << "Dynamic array address: " << heapArray << endl;
    
    cout << "Static array values: ";
    for (int i = 0; i < 5; i++) {
        cout << staticArray[i] << " ";
    }
    cout << endl;
    
    cout << "Dynamic array values: ";
    for (int i = 0; i < 5; i++) {
        cout << heapArray[i] << " ";
    }
    cout << endl;
    
    // Clean up dynamic memory
    delete[] heapArray;
    heapArray = nullptr;
    
    /*
     * SECTION 4: Dynamic Memory for Different Data Types
     */
    
    cout << "\n=== Different Data Types ===" << endl;
    
    // Dynamic double
    double* dynamicDouble = new double(3.14159);
    cout << "Dynamic double: " << *dynamicDouble << endl;
    
    // Dynamic character array (C-style string)
    int strLength = 20;
    char* dynamicString = new char[strLength];
    cout << "Enter a word (max " << (strLength-1) << " chars): ";
    cin >> dynamicString;
    cout << "You entered: " << dynamicString << endl;
    
    // Dynamic boolean
    bool* dynamicBool = new bool(true);
    cout << "Dynamic boolean: " << (*dynamicBool ? "true" : "false") << endl;
    
    // Clean up
    delete dynamicDouble;
    delete[] dynamicString;
    delete dynamicBool;
    
    cout << "All dynamic memory freed" << endl;
    
    /*
     * SECTION 5: Memory Allocation Failure Handling
     */
    
    cout << "\n=== Memory Allocation Safety ===" << endl;
    
    try {
        // Try to allocate a reasonable amount
        int* safeArray = new int[1000];
        cout << "Successfully allocated array of 1000 integers" << endl;
        
        // Initialize first few elements
        for (int i = 0; i < 10; i++) {
            safeArray[i] = i * i;
        }
        
        cout << "First 10 squares: ";
        for (int i = 0; i < 10; i++) {
            cout << safeArray[i] << " ";
        }
        cout << endl;
        
        delete[] safeArray;
        
    } catch (bad_alloc& e) {
        cout << "Memory allocation failed: " << e.what() << endl;
    }
    
    /*
     * SECTION 6: Dynamic 2D Arrays
     * Creating 2D arrays with dynamic allocation
     */
    
    cout << "\n=== Dynamic 2D Arrays ===" << endl;
    
    int rows = 3, cols = 4;
    
    // Allocate array of pointers (for rows)
    int** matrix = new int*[rows];
    
    // Allocate each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    
    // Initialize matrix
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
        }
    }
    
    // Display matrix
    cout << "Dynamic 2D array (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    // Clean up 2D array (reverse order)
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];  // Delete each row
    }
    delete[] matrix;  // Delete array of pointers
    matrix = nullptr;
    
    cout << "2D array memory freed" << endl;
    
    /*
     * SECTION 7: Memory Leak Demonstration (and Prevention)
     */
    
    cout << "\n=== Memory Management Best Practices ===" << endl;
    
    // Good practice: Immediate cleanup
    {
        int* tempPtr = new int(999);
        cout << "Temporary value: " << *tempPtr << endl;
        delete tempPtr;  // Clean up immediately when done
        tempPtr = nullptr;
    }
    
    // Function to demonstrate proper cleanup
    auto createAndCleanup = []() {
        int* localPtr = new int[100];
        // Do some work with localPtr
        for (int i = 0; i < 10; i++) {
            localPtr[i] = i;
        }
        // Always clean up before returning
        delete[] localPtr;
        return true;
    };
    
    if (createAndCleanup()) {
        cout << "Function completed with proper cleanup" << endl;
    }
    
    /*
     * SECTION 8: Smart Pointer Alternative Preview
     * Modern C++ provides smart pointers to avoid manual memory management
     */
    
    cout << "\n=== Manual vs Automatic Management ===" << endl;
    
    // Manual management (what we've been doing)
    int* manualPtr = new int(42);
    cout << "Manual pointer value: " << *manualPtr << endl;
    delete manualPtr;  // Must remember to delete
    manualPtr = nullptr;
    
    // Note: In modern C++, you would use smart pointers like unique_ptr
    // which automatically manage memory, but that's beyond basic fundamentals
    
    cout << "Manual memory management completed" << endl;
    
    /*
     * SECTION 9: Dynamic Memory Statistics
     */
    
    cout << "\n=== Memory Usage Example ===" << endl;
    
    // Allocate different sizes and show addresses
    int* small = new int(1);
    int* medium = new int[100];
    int* large = new int[1000];
    
    cout << "Small allocation address: " << small << endl;
    cout << "Medium allocation address: " << medium << endl;
    cout << "Large allocation address: " << large << endl;
    
    // Clean up
    delete small;
    delete[] medium;
    delete[] large;
    
    cout << "All allocations cleaned up" << endl;
    
    cout << "\n=== Dynamic Memory Complete! ===" << endl;
    
    return 0;
}

/*
 * DYNAMIC MEMORY KEY CONCEPTS:
 * 
 * 1. STACK vs HEAP:
 *    - Stack: Automatic variables, limited size, fast access
 *    - Heap: Dynamic variables, large size, manual management
 * 
 * 2. NEW OPERATOR:
 *    - new int(42); // Allocate single int with value 42
 *    - new int[size]; // Allocate array of size elements
 *    - new int{}; // Zero-initialize
 *    - Returns pointer to allocated memory
 * 
 * 3. DELETE OPERATOR:
 *    - delete ptr; // Free single object
 *    - delete[] ptr; // Free array
 *    - Must match new with delete, new[] with delete[]
 * 
 * 4. MEMORY MANAGEMENT RULES:
 *    - Every new must have corresponding delete
 *    - Every new[] must have corresponding delete[]
 *    - Don't delete the same memory twice
 *    - Set pointers to nullptr after delete
 * 
 * 5. ADVANTAGES OF DYNAMIC MEMORY:
 *    - Size determined at runtime
 *    - Can allocate large amounts
 *    - Memory persists until explicitly freed
 *    - Flexible memory usage
 * 
 * 6. DISADVANTAGES:
 *    - Manual memory management required
 *    - Risk of memory leaks
 *    - Risk of dangling pointers
 *    - Slower than stack allocation
 * 
 * 7. COMMON ERRORS:
 *    - Memory leaks (forgetting delete)
 *    - Dangling pointers (using after delete)
 *    - Double deletion (delete twice)
 *    - Using delete instead of delete[] for arrays
 * 
 * 8. BEST PRACTICES:
 *    - Always pair new with delete
 *    - Set pointers to nullptr after delete
 *    - Use try-catch for allocation failures
 *    - Consider RAII (Resource Acquisition Is Initialization)
 *    - In modern C++, prefer smart pointers
 * 
 * WHEN TO USE DYNAMIC MEMORY:
 * - Array size unknown at compile time
 * - Large data structures
 * - Data that outlives current scope
 * - Implementing data structures (linked lists, trees)
 * 
 * MEMORY LAYOUT:
 * - Stack: Local variables, function parameters
 * - Heap: Dynamically allocated memory
 * - Global: Global and static variables
 * - Code: Program instructions
 */
