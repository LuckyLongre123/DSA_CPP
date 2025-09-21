/**
 * @file 02_pointer_arithmetic.cpp
 * @brief Pointer Arithmetic - Intermediate Level
 * @author C++ Pointers Learning Guide
 * 
 * This file demonstrates pointer arithmetic concepts including:
 * - Basic arithmetic operations (+, -, ++, --)
 * - Pointer differences
 * - Pointer comparisons
 * - Memory address calculations
 * - Type-specific arithmetic
 * 
 * Compilation: g++ -std=c++17 -Wall -Wextra -o pointer_arithmetic 02_pointer_arithmetic.cpp
 * Run: ./pointer_arithmetic
 */

#include <iostream>
#include <iomanip>

using namespace std;

// Function declarations
void demonstrateBasicArithmetic();
void demonstrateIncrementDecrement();
void demonstratePointerDifferences();
void demonstratePointerComparisons();
void demonstrateTypeSpecificArithmetic();
void demonstrateMemoryLayout();
void demonstrateBoundaryChecking();

int main() {
    cout << "=== C++ Pointer Arithmetic Demonstration ===" << endl;
    cout << "=============================================" << endl << endl;
    
    demonstrateBasicArithmetic();
    demonstrateIncrementDecrement();
    demonstratePointerDifferences();
    demonstratePointerComparisons();
    demonstrateTypeSpecificArithmetic();
    demonstrateMemoryLayout();
    demonstrateBoundaryChecking();
    
    cout << "\n=== End of Pointer Arithmetic Demo ===" << endl;
    return 0;
}

/**
 * @brief Demonstrates basic pointer arithmetic operations
 */
void demonstrateBasicArithmetic() {
    cout << "1. BASIC POINTER ARITHMETIC OPERATIONS" << endl;
    cout << "=======================================" << endl;
    
    int numbers[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int* ptr = numbers;  // Points to first element
    
    cout << "Array: ";
    for (int i = 0; i < 10; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl << endl;
    
    cout << "Pointer arithmetic operations:" << endl;
    cout << "  ptr points to: " << *ptr << " (index 0)" << endl;
    cout << "  ptr + 1 points to: " << *(ptr + 1) << " (index 1)" << endl;
    cout << "  ptr + 2 points to: " << *(ptr + 2) << " (index 2)" << endl;
    cout << "  ptr + 5 points to: " << *(ptr + 5) << " (index 5)" << endl;
    cout << "  ptr + 9 points to: " << *(ptr + 9) << " (index 9)" << endl << endl;
    
    // Demonstrate that ptr[i] is equivalent to *(ptr + i)
    cout << "Equivalence demonstration:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "  ptr[" << i << "] = " << ptr[i] 
             << ", *(ptr + " << i << ") = " << *(ptr + i) 
             << " (always equivalent)" << endl;
    }
    cout << endl;
}

/**
 * @brief Demonstrates increment and decrement operations
 */
void demonstrateIncrementDecrement() {
    cout << "2. INCREMENT AND DECREMENT OPERATIONS" << endl;
    cout << "=====================================" << endl;
    
    double values[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double* ptr = values;
    
    cout << "Array: ";
    for (int i = 0; i < 5; i++) {
        cout << values[i] << " ";
    }
    cout << endl << endl;
    
    cout << "Forward traversal using increment:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "  ptr points to: " << *ptr << " at address " << ptr << endl;
        ptr++;  // Move to next element
    }
    
    cout << "\nAfter incrementing, ptr is now past the array" << endl;
    cout << "  ptr address: " << ptr << endl;
    
    // Move back to last element
    ptr--;
    cout << "\nAfter decrementing once:" << endl;
    cout << "  ptr points to: " << *ptr << " (last element)" << endl;
    
    cout << "\nBackward traversal using decrement:" << endl;
    for (int i = 4; i >= 0; i--) {
        cout << "  ptr points to: " << *ptr << " at address " << ptr << endl;
        if (i > 0) ptr--;  // Don't decrement on last iteration
    }
    
    cout << "\nPre-increment vs Post-increment:" << endl;
    ptr = values;  // Reset to beginning
    cout << "  Initial: *ptr = " << *ptr << endl;
    cout << "  *ptr++ = " << *ptr++ << " (post-increment, returns current then moves)" << endl;
    cout << "  Now *ptr = " << *ptr << endl;
    cout << "  *++ptr = " << *++ptr << " (pre-increment, moves then returns)" << endl;
    cout << endl;
}

/**
 * @brief Demonstrates pointer differences and distance calculations
 */
void demonstratePointerDifferences() {
    cout << "3. POINTER DIFFERENCES AND DISTANCES" << endl;
    cout << "=====================================" << endl;
    
    int array[] = {100, 200, 300, 400, 500, 600, 700, 800};
    int* start = array;
    int* middle = array + 3;
    int* end = array + 7;
    
    cout << "Array positions:" << endl;
    cout << "  start points to: " << *start << " at index 0" << endl;
    cout << "  middle points to: " << *middle << " at index 3" << endl;
    cout << "  end points to: " << *end << " at index 7" << endl << endl;
    
    cout << "Pointer differences (in elements):" << endl;
    cout << "  middle - start = " << middle - start << " elements" << endl;
    cout << "  end - start = " << end - start << " elements" << endl;
    cout << "  end - middle = " << end - middle << " elements" << endl;
    cout << "  start - end = " << start - end << " elements (negative)" << endl << endl;
    
    cout << "Address differences (in bytes):" << endl;
    cout << "  (char*)middle - (char*)start = " << (char*)middle - (char*)start << " bytes" << endl;
    cout << "  (char*)end - (char*)start = " << (char*)end - (char*)start << " bytes" << endl;
    cout << "  sizeof(int) = " << sizeof(int) << " bytes" << endl;
    cout << "  Notice: byte difference = element difference × sizeof(type)" << endl << endl;
    
    // Calculate array size using pointers
    int arraySize = end - start + 1;  // +1 because end points to last element
    cout << "Array size calculation using pointers: " << arraySize << " elements" << endl;
    cout << endl;
}

/**
 * @brief Demonstrates pointer comparisons
 */
void demonstratePointerComparisons() {
    cout << "4. POINTER COMPARISONS" << endl;
    cout << "======================" << endl;
    
    float data[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    float* ptr1 = data;
    float* ptr2 = data + 2;
    float* ptr3 = data + 4;
    
    cout << "Pointer positions:" << endl;
    cout << "  ptr1 -> " << *ptr1 << " (index 0)" << endl;
    cout << "  ptr2 -> " << *ptr2 << " (index 2)" << endl;
    cout << "  ptr3 -> " << *ptr3 << " (index 4)" << endl << endl;
    
    cout << "Equality comparisons:" << endl;
    cout << "  ptr1 == ptr2: " << (ptr1 == ptr2 ? "true" : "false") << endl;
    cout << "  ptr1 == data: " << (ptr1 == data ? "true" : "false") << endl;
    cout << "  ptr2 == (data + 2): " << (ptr2 == (data + 2) ? "true" : "false") << endl << endl;
    
    cout << "Relational comparisons:" << endl;
    cout << "  ptr1 < ptr2: " << (ptr1 < ptr2 ? "true" : "false") << endl;
    cout << "  ptr2 < ptr3: " << (ptr2 < ptr3 ? "true" : "false") << endl;
    cout << "  ptr3 > ptr1: " << (ptr3 > ptr1 ? "true" : "false") << endl;
    cout << "  ptr1 <= ptr2: " << (ptr1 <= ptr2 ? "true" : "false") << endl;
    cout << "  ptr2 >= ptr1: " << (ptr2 >= ptr1 ? "true" : "false") << endl << endl;
    
    // Practical use: bounds checking
    cout << "Bounds checking example:" << endl;
    float* current = data;
    float* arrayEnd = data + 5;  // One past the last element
    
    int count = 0;
    while (current < arrayEnd) {
        cout << "  Element " << count << ": " << *current << endl;
        current++;
        count++;
    }
    cout << endl;
}

/**
 * @brief Demonstrates type-specific arithmetic behavior
 */
void demonstrateTypeSpecificArithmetic() {
    cout << "5. TYPE-SPECIFIC ARITHMETIC BEHAVIOR" << endl;
    cout << "====================================" << endl;
    
    // Different data types
    char charArray[] = {'A', 'B', 'C', 'D', 'E'};
    short shortArray[] = {10, 20, 30, 40, 50};
    int intArray[] = {100, 200, 300, 400, 500};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    
    char* charPtr = charArray;
    short* shortPtr = shortArray;
    int* intPtr = intArray;
    double* doublePtr = doubleArray;
    
    cout << "Type sizes:" << endl;
    cout << "  char: " << sizeof(char) << " byte(s)" << endl;
    cout << "  short: " << sizeof(short) << " byte(s)" << endl;
    cout << "  int: " << sizeof(int) << " byte(s)" << endl;
    cout << "  double: " << sizeof(double) << " byte(s)" << endl << endl;
    
    cout << "Address increments when adding 1 to pointers:" << endl;
    cout << "  charPtr: " << charPtr << " -> " << (charPtr + 1) 
         << " (difference: " << (char*)(charPtr + 1) - (char*)charPtr << " bytes)" << endl;
    cout << "  shortPtr: " << shortPtr << " -> " << (shortPtr + 1) 
         << " (difference: " << (char*)(shortPtr + 1) - (char*)shortPtr << " bytes)" << endl;
    cout << "  intPtr: " << intPtr << " -> " << (intPtr + 1) 
         << " (difference: " << (char*)(intPtr + 1) - (char*)intPtr << " bytes)" << endl;
    cout << "  doublePtr: " << doublePtr << " -> " << (doublePtr + 1) 
         << " (difference: " << (char*)(doublePtr + 1) - (char*)doublePtr << " bytes)" << endl << endl;
    
    cout << "Key insight: ptr + 1 moves by sizeof(type) bytes, not 1 byte!" << endl;
    cout << "This allows pointer arithmetic to work correctly with any data type." << endl;
    cout << endl;
}

/**
 * @brief Demonstrates memory layout and address patterns
 */
void demonstrateMemoryLayout() {
    cout << "6. MEMORY LAYOUT AND ADDRESS PATTERNS" << endl;
    cout << "======================================" << endl;
    
    int sequence[] = {11, 22, 33, 44, 55, 66, 77, 88};
    int* ptr = sequence;
    
    cout << "Memory layout visualization:" << endl;
    cout << "Index | Value | Address    | Hex Address" << endl;
    cout << "------|-------|------------|------------" << endl;
    
    for (int i = 0; i < 8; i++) {
        cout << setw(5) << i << " | " 
             << setw(5) << sequence[i] << " | " 
             << ptr + i << " | " 
             << hex << ptr + i << dec << endl;
    }
    cout << endl;
    
    // Show address arithmetic
    cout << "Address arithmetic verification:" << endl;
    cout << "  Base address: " << ptr << endl;
    cout << "  ptr + 3 calculated: " << ptr + 3 << endl;
    cout << "  Manual calculation: " << (void*)((char*)ptr + 3 * sizeof(int)) << endl;
    cout << "  Match: " << (ptr + 3 == (int*)((char*)ptr + 3 * sizeof(int)) ? "Yes" : "No") << endl;
    cout << endl;
    
    // Demonstrate non-contiguous memory (different variables)
    int var1 = 111;
    int var2 = 222;
    int var3 = 333;
    
    cout << "Non-contiguous variables (may not be sequential):" << endl;
    cout << "  var1 (" << var1 << ") at: " << &var1 << endl;
    cout << "  var2 (" << var2 << ") at: " << &var2 << endl;
    cout << "  var3 (" << var3 << ") at: " << &var3 << endl;
    cout << "  Note: These addresses may not be sequential!" << endl;
    cout << endl;
}

/**
 * @brief Demonstrates boundary checking and safe practices
 */
void demonstrateBoundaryChecking() {
    cout << "7. BOUNDARY CHECKING AND SAFE PRACTICES" << endl;
    cout << "========================================" << endl;
    
    int safeArray[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
    const int arraySize = sizeof(safeArray) / sizeof(safeArray[0]);
    
    int* start = safeArray;
    int* end = safeArray + arraySize;  // One past the last element
    
    cout << "Array size: " << arraySize << " elements" << endl;
    cout << "Valid range: [" << start << ", " << end << ")" << endl;
    cout << "Note: end pointer is one past the last valid element" << endl << endl;
    
    // Safe traversal
    cout << "Safe forward traversal:" << endl;
    int* current = start;
    int index = 0;
    while (current < end) {
        cout << "  Index " << index << ": " << *current << " at " << current << endl;
        current++;
        index++;
    }
    cout << endl;
    
    // Safe backward traversal
    cout << "Safe backward traversal:" << endl;
    current = end - 1;  // Point to last valid element
    index = arraySize - 1;
    while (current >= start) {
        cout << "  Index " << index << ": " << *current << " at " << current << endl;
        current--;
        index--;
    }
    cout << endl;
    
    // Demonstrate bounds checking
    cout << "Bounds checking examples:" << endl;
    int* testPtr = start + 5;  // Point to middle of array
    
    cout << "  testPtr points to index 5: " << *testPtr << endl;
    cout << "  Is testPtr within bounds? " << (testPtr >= start && testPtr < end ? "Yes" : "No") << endl;
    
    testPtr = start - 1;  // Before array (dangerous!)
    cout << "  testPtr = start - 1 (before array)" << endl;
    cout << "  Is testPtr within bounds? " << (testPtr >= start && testPtr < end ? "Yes" : "No") << endl;
    
    testPtr = end;  // After array (dangerous!)
    cout << "  testPtr = end (after array)" << endl;
    cout << "  Is testPtr within bounds? " << (testPtr >= start && testPtr < end ? "Yes" : "No") << endl;
    
    cout << "\nIMPORTANT: Always check bounds before dereferencing pointers!" << endl;
    cout << "Accessing memory outside array bounds leads to undefined behavior." << endl;
    cout << endl;
}
