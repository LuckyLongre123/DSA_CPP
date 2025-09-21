/**
 * @file 01_basic_pointers.cpp
 * @brief Basic Pointer Concepts - Beginner Level
 * @author C++ Pointers Learning Guide
 * 
 * This file demonstrates fundamental pointer concepts including:
 * - Pointer declaration and initialization
 * - Address-of operator (&)
 * - Dereference operator (*)
 * - Null pointers
 * - Basic pointer operations
 * 
 * Compilation: g++ -std=c++17 -Wall -Wextra -o basic_pointers 01_basic_pointers.cpp
 * Run: ./basic_pointers
 */

#include <iostream>
#include <iomanip>

using namespace std;

// Function declarations
void demonstrateBasicPointers();
void demonstrateAddressOperator();
void demonstrateDereferencing();
void demonstrateNullPointers();
void demonstratePointerModification();
void demonstrateMultiplePointers();
void demonstratePointerSizes();

int main() {
    cout << "=== C++ Basic Pointers Demonstration ===" << endl;
    cout << "=========================================" << endl << endl;
    
    demonstrateBasicPointers();
    demonstrateAddressOperator();
    demonstrateDereferencing();
    demonstrateNullPointers();
    demonstratePointerModification();
    demonstrateMultiplePointers();
    demonstratePointerSizes();
    
    cout << "\n=== End of Basic Pointers Demo ===" << endl;
    return 0;
}

/**
 * @brief Demonstrates basic pointer declaration and initialization
 */
void demonstrateBasicPointers() {
    cout << "1. BASIC POINTER DECLARATION AND INITIALIZATION" << endl;
    cout << "===============================================" << endl;
    
    // Variable declaration
    int number = 42;
    double pi = 3.14159;
    char letter = 'A';
    
    // Pointer declarations
    int* intPtr;        // Uninitialized pointer (dangerous!)
    double* doublePtr;  // Uninitialized pointer
    char* charPtr;      // Uninitialized pointer
    
    // Pointer initialization
    intPtr = &number;   // Point to the address of 'number'
    doublePtr = &pi;    // Point to the address of 'pi'
    charPtr = &letter;  // Point to the address of 'letter'
    
    cout << "Variables and their values:" << endl;
    cout << "  number = " << number << endl;
    cout << "  pi = " << pi << endl;
    cout << "  letter = " << letter << endl << endl;
    
    cout << "Pointers and their values (addresses):" << endl;
    cout << "  intPtr = " << intPtr << endl;
    cout << "  doublePtr = " << doublePtr << endl;
    cout << "  charPtr = " << static_cast<void*>(charPtr) << endl;
    cout << endl;
}

/**
 * @brief Demonstrates the address-of operator (&)
 */
void demonstrateAddressOperator() {
    cout << "2. ADDRESS-OF OPERATOR (&)" << endl;
    cout << "===========================" << endl;
    
    int value1 = 100;
    int value2 = 200;
    int value3 = 300;
    
    cout << "Variables and their addresses:" << endl;
    cout << "  value1 = " << setw(3) << value1 << " at address: " << &value1 << endl;
    cout << "  value2 = " << setw(3) << value2 << " at address: " << &value2 << endl;
    cout << "  value3 = " << setw(3) << value3 << " at address: " << &value3 << endl;
    
    // Notice how addresses are typically sequential (but not guaranteed)
    cout << "\nAddress differences (bytes):" << endl;
    cout << "  &value2 - &value1 = " << (char*)&value2 - (char*)&value1 << " bytes" << endl;
    cout << "  &value3 - &value2 = " << (char*)&value3 - (char*)&value2 << " bytes" << endl;
    
    // Different ways to get addresses
    int* ptr1 = &value1;
    int* ptr2 = &value2;
    
    cout << "\nPointer values (should match addresses above):" << endl;
    cout << "  ptr1 = " << ptr1 << endl;
    cout << "  ptr2 = " << ptr2 << endl;
    cout << endl;
}

/**
 * @brief Demonstrates the dereference operator (*)
 */
void demonstrateDereferencing() {
    cout << "3. DEREFERENCE OPERATOR (*)" << endl;
    cout << "============================" << endl;
    
    int original = 555;
    int* ptr = &original;
    
    cout << "Original variable:" << endl;
    cout << "  original = " << original << endl;
    cout << "  Address of original = " << &original << endl << endl;
    
    cout << "Pointer information:" << endl;
    cout << "  ptr = " << ptr << " (address it points to)" << endl;
    cout << "  *ptr = " << *ptr << " (value at that address)" << endl << endl;
    
    cout << "Verification that ptr points to original:" << endl;
    cout << "  ptr == &original: " << (ptr == &original ? "true" : "false") << endl;
    cout << "  *ptr == original: " << (*ptr == original ? "true" : "false") << endl;
    
    // Modifying through pointer
    cout << "\nModifying value through pointer:" << endl;
    cout << "  Before: original = " << original << ", *ptr = " << *ptr << endl;
    
    *ptr = 777;  // Change value through pointer
    
    cout << "  After *ptr = 777:" << endl;
    cout << "  original = " << original << ", *ptr = " << *ptr << endl;
    cout << "  Both changed because they refer to the same memory location!" << endl;
    cout << endl;
}

/**
 * @brief Demonstrates null pointers and safe practices
 */
void demonstrateNullPointers() {
    cout << "4. NULL POINTERS AND SAFETY" << endl;
    cout << "============================" << endl;
    
    // Different ways to create null pointers
    int* ptr1 = nullptr;    // C++11 and later (preferred)
    int* ptr2 = NULL;       // C-style (legacy)
    int* ptr3 = 0;          // Integer literal (not recommended)
    
    cout << "Null pointer values:" << endl;
    cout << "  ptr1 (nullptr) = " << ptr1 << endl;
    cout << "  ptr2 (NULL) = " << ptr2 << endl;
    cout << "  ptr3 (0) = " << ptr3 << endl << endl;
    
    // Safe dereferencing
    cout << "Safe pointer dereferencing:" << endl;
    
    if (ptr1 != nullptr) {
        cout << "  ptr1 is not null, value = " << *ptr1 << endl;
    } else {
        cout << "  ptr1 is null, cannot dereference safely" << endl;
    }
    
    // Assign a valid address
    int value = 999;
    ptr1 = &value;
    
    cout << "\nAfter assigning valid address:" << endl;
    if (ptr1 != nullptr) {
        cout << "  ptr1 is not null, value = " << *ptr1 << endl;
    } else {
        cout << "  ptr1 is null, cannot dereference safely" << endl;
    }
    
    // Best practice: set to nullptr after use
    ptr1 = nullptr;
    cout << "  Set ptr1 back to nullptr for safety" << endl;
    cout << endl;
}

/**
 * @brief Demonstrates pointer modification and reassignment
 */
void demonstratePointerModification() {
    cout << "5. POINTER MODIFICATION AND REASSIGNMENT" << endl;
    cout << "=========================================" << endl;
    
    int var1 = 10;
    int var2 = 20;
    int var3 = 30;
    
    int* ptr = &var1;
    
    cout << "Initial state:" << endl;
    cout << "  var1 = " << var1 << ", var2 = " << var2 << ", var3 = " << var3 << endl;
    cout << "  ptr points to var1, *ptr = " << *ptr << endl << endl;
    
    // Modify value through pointer
    *ptr = 15;
    cout << "After *ptr = 15:" << endl;
    cout << "  var1 = " << var1 << " (changed!)" << endl;
    cout << "  var2 = " << var2 << " (unchanged)" << endl;
    cout << "  var3 = " << var3 << " (unchanged)" << endl << endl;
    
    // Reassign pointer to different variable
    ptr = &var2;
    cout << "After ptr = &var2:" << endl;
    cout << "  ptr now points to var2, *ptr = " << *ptr << endl;
    
    *ptr = 25;
    cout << "After *ptr = 25:" << endl;
    cout << "  var1 = " << var1 << " (unchanged)" << endl;
    cout << "  var2 = " << var2 << " (changed!)" << endl;
    cout << "  var3 = " << var3 << " (unchanged)" << endl << endl;
    
    // Point to var3 and modify
    ptr = &var3;
    *ptr = 35;
    cout << "After ptr = &var3 and *ptr = 35:" << endl;
    cout << "  var1 = " << var1 << ", var2 = " << var2 << ", var3 = " << var3 << endl;
    cout << endl;
}

/**
 * @brief Demonstrates multiple pointers to the same variable
 */
void demonstrateMultiplePointers() {
    cout << "6. MULTIPLE POINTERS TO SAME VARIABLE" << endl;
    cout << "======================================" << endl;
    
    int sharedVar = 100;
    
    // Multiple pointers to the same variable
    int* ptr1 = &sharedVar;
    int* ptr2 = &sharedVar;
    int* ptr3 = &sharedVar;
    
    cout << "One variable, multiple pointers:" << endl;
    cout << "  sharedVar = " << sharedVar << " at address " << &sharedVar << endl;
    cout << "  ptr1 = " << ptr1 << ", *ptr1 = " << *ptr1 << endl;
    cout << "  ptr2 = " << ptr2 << ", *ptr2 = " << *ptr2 << endl;
    cout << "  ptr3 = " << ptr3 << ", *ptr3 = " << *ptr3 << endl << endl;
    
    cout << "All pointers point to the same address:" << endl;
    cout << "  ptr1 == ptr2: " << (ptr1 == ptr2 ? "true" : "false") << endl;
    cout << "  ptr2 == ptr3: " << (ptr2 == ptr3 ? "true" : "false") << endl;
    cout << "  ptr1 == &sharedVar: " << (ptr1 == &sharedVar ? "true" : "false") << endl << endl;
    
    // Modify through one pointer, all see the change
    cout << "Modifying through ptr2:" << endl;
    *ptr2 = 200;
    
    cout << "  sharedVar = " << sharedVar << endl;
    cout << "  *ptr1 = " << *ptr1 << endl;
    cout << "  *ptr2 = " << *ptr2 << endl;
    cout << "  *ptr3 = " << *ptr3 << endl;
    cout << "  All values changed because they reference the same memory!" << endl;
    cout << endl;
}

/**
 * @brief Demonstrates pointer sizes and memory layout
 */
void demonstratePointerSizes() {
    cout << "7. POINTER SIZES AND MEMORY LAYOUT" << endl;
    cout << "===================================" << endl;
    
    // Different data types
    char c = 'X';
    short s = 1000;
    int i = 50000;
    long l = 1000000L;
    float f = 3.14f;
    double d = 2.71828;
    
    // Pointers to different types
    char* cPtr = &c;
    short* sPtr = &s;
    int* iPtr = &i;
    long* lPtr = &l;
    float* fPtr = &f;
    double* dPtr = &d;
    
    cout << "Data type sizes:" << endl;
    cout << "  char: " << sizeof(char) << " byte(s)" << endl;
    cout << "  short: " << sizeof(short) << " byte(s)" << endl;
    cout << "  int: " << sizeof(int) << " byte(s)" << endl;
    cout << "  long: " << sizeof(long) << " byte(s)" << endl;
    cout << "  float: " << sizeof(float) << " byte(s)" << endl;
    cout << "  double: " << sizeof(double) << " byte(s)" << endl << endl;
    
    cout << "Pointer sizes (all should be the same on a given architecture):" << endl;
    cout << "  char*: " << sizeof(cPtr) << " byte(s)" << endl;
    cout << "  short*: " << sizeof(sPtr) << " byte(s)" << endl;
    cout << "  int*: " << sizeof(iPtr) << " byte(s)" << endl;
    cout << "  long*: " << sizeof(lPtr) << " byte(s)" << endl;
    cout << "  float*: " << sizeof(fPtr) << " byte(s)" << endl;
    cout << "  double*: " << sizeof(dPtr) << " byte(s)" << endl << endl;
    
    cout << "Key insight: All pointers are the same size regardless of what they point to!" << endl;
    cout << "This is because pointers store memory addresses, not the actual data." << endl;
    
    // Architecture information
    cout << "\nArchitecture information:" << endl;
    cout << "  Pointer size: " << sizeof(void*) << " bytes" << endl;
    cout << "  Architecture: " << (sizeof(void*) == 8 ? "64-bit" : 
                                   sizeof(void*) == 4 ? "32-bit" : "Unknown") << endl;
    cout << endl;
}
