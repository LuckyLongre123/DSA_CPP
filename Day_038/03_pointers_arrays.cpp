/**
 * @file 03_pointers_arrays.cpp
 * @brief Pointers and Arrays - Intermediate Level
 * @author C++ Pointers Learning Guide
 * 
 * This file demonstrates the relationship between pointers and arrays:
 * - Array-pointer equivalence
 * - Array traversal with pointers
 * - Multi-dimensional arrays and pointers
 * - String manipulation with pointers
 * - Dynamic arrays
 * 
 * Compilation: g++ -std=c++17 -Wall -Wextra -o pointers_arrays 03_pointers_arrays.cpp
 * Run: ./pointers_arrays
 */

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

// Function declarations
void demonstrateArrayPointerEquivalence();
void demonstrateArrayTraversal();
void demonstrateStringPointers();
void demonstrateMultiDimensionalArrays();
void demonstrateDynamicArrays();
void demonstrateArrayParameters();
void demonstratePointerArrays();

int main() {
    cout << "=== C++ Pointers and Arrays Demonstration ===" << endl;
    cout << "==============================================" << endl << endl;
    
    demonstrateArrayPointerEquivalence();
    demonstrateArrayTraversal();
    demonstrateStringPointers();
    demonstrateMultiDimensionalArrays();
    demonstrateDynamicArrays();
    demonstrateArrayParameters();
    demonstratePointerArrays();
    
    cout << "\n=== End of Pointers and Arrays Demo ===" << endl;
    return 0;
}

/**
 * @brief Demonstrates the equivalence between arrays and pointers
 */
void demonstrateArrayPointerEquivalence() {
    cout << "1. ARRAY-POINTER EQUIVALENCE" << endl;
    cout << "=============================" << endl;
    
    int numbers[] = {10, 20, 30, 40, 50};
    int* ptr = numbers;  // Array name is a pointer to first element
    
    cout << "Array: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl << endl;
    
    cout << "Address comparisons:" << endl;
    cout << "  numbers (array name): " << numbers << endl;
    cout << "  &numbers[0]: " << &numbers[0] << endl;
    cout << "  ptr: " << ptr << endl;
    cout << "  All three are the same: " << (numbers == &numbers[0] && numbers == ptr ? "Yes" : "No") << endl << endl;
    
    cout << "Equivalent ways to access array elements:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "  Index " << i << ":" << endl;
        cout << "    numbers[" << i << "] = " << numbers[i] << endl;
        cout << "    *(numbers + " << i << ") = " << *(numbers + i) << endl;
        cout << "    ptr[" << i << "] = " << ptr[i] << endl;
        cout << "    *(ptr + " << i << ") = " << *(ptr + i) << endl;
        cout << "    All equal: " << (numbers[i] == *(numbers + i) && 
                                      numbers[i] == ptr[i] && 
                                      numbers[i] == *(ptr + i) ? "Yes" : "No") << endl;
    }
    cout << endl;
    
    // Important difference: sizeof
    cout << "Important difference - sizeof:" << endl;
    cout << "  sizeof(numbers): " << sizeof(numbers) << " bytes (entire array)" << endl;
    cout << "  sizeof(ptr): " << sizeof(ptr) << " bytes (just the pointer)" << endl;
    cout << "  Array elements: " << sizeof(numbers) / sizeof(numbers[0]) << endl;
    cout << endl;
}

/**
 * @brief Demonstrates different ways to traverse arrays with pointers
 */
void demonstrateArrayTraversal() {
    cout << "2. ARRAY TRAVERSAL WITH POINTERS" << endl;
    cout << "=================================" << endl;
    
    double values[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
    const int size = sizeof(values) / sizeof(values[0]);
    
    cout << "Array size: " << size << " elements" << endl << endl;
    
    // Method 1: Traditional index-based
    cout << "Method 1 - Traditional index-based:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "  values[" << i << "] = " << values[i] << endl;
    }
    cout << endl;
    
    // Method 2: Pointer arithmetic with fixed base
    cout << "Method 2 - Pointer arithmetic with fixed base:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "  *(values + " << i << ") = " << *(values + i) << endl;
    }
    cout << endl;
    
    // Method 3: Moving pointer
    cout << "Method 3 - Moving pointer:" << endl;
    double* ptr = values;
    for (int i = 0; i < size; i++) {
        cout << "  *ptr = " << *ptr << " at address " << ptr << endl;
        ptr++;
    }
    cout << endl;
    
    // Method 4: Pointer range (C++ style)
    cout << "Method 4 - Pointer range (C++ style):" << endl;
    double* start = values;
    double* end = values + size;
    int index = 0;
    for (double* current = start; current != end; ++current) {
        cout << "  Element " << index++ << ": " << *current << endl;
    }
    cout << endl;
    
    // Method 5: Reverse traversal
    cout << "Method 5 - Reverse traversal:" << endl;
    ptr = values + size - 1;  // Point to last element
    for (int i = size - 1; i >= 0; i--) {
        cout << "  Element " << i << ": " << *ptr << endl;
        ptr--;
    }
    cout << endl;
}

/**
 * @brief Demonstrates string manipulation with pointers
 */
void demonstrateStringPointers() {
    cout << "3. STRING MANIPULATION WITH POINTERS" << endl;
    cout << "=====================================" << endl;
    
    char greeting[] = "Hello, World!";
    char* ptr = greeting;
    
    cout << "Original string: \"" << greeting << "\"" << endl;
    cout << "String length: " << strlen(greeting) << " characters" << endl << endl;
    
    // Character-by-character access
    cout << "Character-by-character access:" << endl;
    for (int i = 0; greeting[i] != '\0'; i++) {
        cout << "  greeting[" << i << "] = '" << greeting[i] << "' (ASCII: " << (int)greeting[i] << ")" << endl;
    }
    cout << endl;
    
    // Using pointer traversal
    cout << "Using pointer traversal:" << endl;
    ptr = greeting;
    int pos = 0;
    while (*ptr != '\0') {
        cout << "  Position " << pos++ << ": '" << *ptr << "'" << endl;
        ptr++;
    }
    cout << endl;
    
    // String modification through pointers
    cout << "String modification through pointers:" << endl;
    ptr = greeting;
    while (*ptr != '\0') {
        if (*ptr == 'o') {
            *ptr = '0';  // Replace 'o' with '0'
        }
        ptr++;
    }
    cout << "  Modified string: \"" << greeting << "\"" << endl << endl;
    
    // String literals and pointers
    const char* message = "This is a string literal";
    cout << "String literal pointer:" << endl;
    cout << "  message points to: \"" << message << "\"" << endl;
    cout << "  Address: " << (void*)message << endl;
    cout << "  Note: String literals are typically stored in read-only memory" << endl << endl;
    
    // Array of strings
    const char* fruits[] = {"Apple", "Banana", "Cherry", "Date", "Elderberry"};
    const int numFruits = sizeof(fruits) / sizeof(fruits[0]);
    
    cout << "Array of string pointers:" << endl;
    for (int i = 0; i < numFruits; i++) {
        cout << "  fruits[" << i << "] = \"" << fruits[i] << "\" at " << (void*)fruits[i] << endl;
    }
    cout << endl;
}

/**
 * @brief Demonstrates multi-dimensional arrays and pointers
 */
void demonstrateMultiDimensionalArrays() {
    cout << "4. MULTI-DIMENSIONAL ARRAYS AND POINTERS" << endl;
    cout << "=========================================" << endl;
    
    int matrix[3][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };
    
    cout << "2D Array (3x4 matrix):" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  Row " << i << ": ";
        for (int j = 0; j < 4; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Pointer to array of 4 integers
    int (*rowPtr)[4] = matrix;
    
    cout << "Using pointer to array:" << endl;
    cout << "  matrix address: " << matrix << endl;
    cout << "  rowPtr address: " << rowPtr << endl;
    cout << "  Same address: " << (matrix == rowPtr ? "Yes" : "No") << endl << endl;
    
    cout << "Accessing elements through rowPtr:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  Row " << i << ": ";
        for (int j = 0; j < 4; j++) {
            cout << setw(3) << rowPtr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Alternative: pointer arithmetic
    cout << "Using pointer arithmetic:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  Row " << i << ": ";
        for (int j = 0; j < 4; j++) {
            cout << setw(3) << (*(rowPtr + i))[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Treating 2D array as 1D
    int* flatPtr = (int*)matrix;
    cout << "Treating 2D array as 1D (row-major order):" << endl;
    for (int i = 0; i < 12; i++) {
        cout << "  flatPtr[" << setw(2) << i << "] = " << setw(2) << flatPtr[i];
        if ((i + 1) % 4 == 0) cout << "  (end of row " << i / 4 << ")";
        cout << endl;
    }
    cout << endl;
}

/**
 * @brief Demonstrates dynamic array allocation and management
 */
void demonstrateDynamicArrays() {
    cout << "5. DYNAMIC ARRAYS" << endl;
    cout << "=================" << endl;
    
    int size;
    cout << "Enter array size: ";
    cin >> size;
    
    // Dynamic allocation
    int* dynamicArray = new int[size];
    
    cout << "Allocated array of " << size << " integers" << endl;
    cout << "Array address: " << dynamicArray << endl << endl;
    
    // Initialize array
    cout << "Initializing array with squares:" << endl;
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = i * i;
        cout << "  dynamicArray[" << i << "] = " << dynamicArray[i] << endl;
    }
    cout << endl;
    
    // Resize simulation (create new larger array)
    int newSize = size + 3;
    int* newArray = new int[newSize];
    
    cout << "Resizing to " << newSize << " elements:" << endl;
    
    // Copy old data
    for (int i = 0; i < size; i++) {
        newArray[i] = dynamicArray[i];
    }
    
    // Initialize new elements
    for (int i = size; i < newSize; i++) {
        newArray[i] = i * 10;
    }
    
    // Clean up old array
    delete[] dynamicArray;
    dynamicArray = newArray;
    
    cout << "New array contents:" << endl;
    for (int i = 0; i < newSize; i++) {
        cout << "  newArray[" << i << "] = " << dynamicArray[i] << endl;
    }
    cout << endl;
    
    // 2D dynamic array
    cout << "Creating 2D dynamic array (3x4):" << endl;
    int rows = 3, cols = 4;
    
    // Method 1: Array of pointers
    int** matrix2D = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix2D[i] = new int[cols];
    }
    
    // Initialize
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix2D[i][j] = value++;
        }
    }
    
    // Display
    for (int i = 0; i < rows; i++) {
        cout << "  Row " << i << ": ";
        for (int j = 0; j < cols; j++) {
            cout << setw(3) << matrix2D[i][j] << " ";
        }
        cout << endl;
    }
    
    // Cleanup 2D array
    for (int i = 0; i < rows; i++) {
        delete[] matrix2D[i];
    }
    delete[] matrix2D;
    
    // Cleanup 1D array
    delete[] dynamicArray;
    
    cout << "All dynamic memory cleaned up!" << endl;
    cout << endl;
}

/**
 * @brief Demonstrates array parameters in functions
 */
void printArray(int arr[], int size) {
    cout << "    Inside printArray:" << endl;
    cout << "      sizeof(arr): " << sizeof(int*) << " bytes (pointer size)" << endl;
    cout << "      Array contents: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArrayPtr(int* arr, int size) {
    cout << "    Inside printArrayPtr:" << endl;
    cout << "      sizeof(arr): " << sizeof(arr) << " bytes (pointer size)" << endl;
    cout << "      Array contents: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void modifyArray(int arr[], int size) {
    cout << "    Modifying array elements (multiplying by 2):" << endl;
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

void demonstrateArrayParameters() {
    cout << "6. ARRAY PARAMETERS IN FUNCTIONS" << endl;
    cout << "=================================" << endl;
    
    int testArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(testArray) / sizeof(testArray[0]);
    
    cout << "Original array:" << endl;
    cout << "  sizeof(testArray): " << sizeof(testArray) << " bytes (full array)" << endl;
    cout << "  Array size: " << size << " elements" << endl;
    cout << "  Contents: ";
    for (int i = 0; i < size; i++) {
        cout << testArray[i] << " ";
    }
    cout << endl << endl;
    
    cout << "Passing to printArray(int arr[], int size):" << endl;
    printArray(testArray, size);
    cout << endl;
    
    cout << "Passing to printArrayPtr(int* arr, int size):" << endl;
    printArrayPtr(testArray, size);
    cout << endl;
    
    cout << "Note: Both functions receive the same thing - a pointer!" << endl;
    cout << "The [] notation in parameters is just syntactic sugar." << endl << endl;
    
    cout << "Modifying array through function:" << endl;
    cout << "  Before modification: ";
    for (int i = 0; i < size; i++) {
        cout << testArray[i] << " ";
    }
    cout << endl;
    
    modifyArray(testArray, size);
    
    cout << "  After modification: ";
    for (int i = 0; i < size; i++) {
        cout << testArray[i] << " ";
    }
    cout << endl;
    cout << "  Array was modified because functions receive a pointer to the original data!" << endl;
    cout << endl;
}

/**
 * @brief Demonstrates arrays of pointers
 */
void demonstratePointerArrays() {
    cout << "7. ARRAYS OF POINTERS" << endl;
    cout << "=====================" << endl;
    
    // Array of integer pointers
    int a = 10, b = 20, c = 30, d = 40;
    int* ptrArray[] = {&a, &b, &c, &d};
    int numPtrs = sizeof(ptrArray) / sizeof(ptrArray[0]);
    
    cout << "Array of integer pointers:" << endl;
    for (int i = 0; i < numPtrs; i++) {
        cout << "  ptrArray[" << i << "] points to " << *ptrArray[i] 
             << " at address " << ptrArray[i] << endl;
    }
    cout << endl;
    
    // Modify values through pointer array
    cout << "Modifying values through pointer array:" << endl;
    for (int i = 0; i < numPtrs; i++) {
        *ptrArray[i] += 100;
    }
    
    cout << "  After modification:" << endl;
    cout << "    a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << endl;
    cout << endl;
    
    // Array of string pointers (command line arguments style)
    const char* argv[] = {"program", "-v", "--help", "input.txt", nullptr};
    int argc = 4;  // Don't count the nullptr
    
    cout << "Command line arguments simulation:" << endl;
    cout << "  argc = " << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << "  argv[" << i << "] = \"" << argv[i] << "\"" << endl;
    }
    cout << endl;
    
    // Dynamic array of pointers
    cout << "Dynamic array of pointers:" << endl;
    int** dynamicPtrArray = new int*[3];
    
    dynamicPtrArray[0] = new int(100);
    dynamicPtrArray[1] = new int(200);
    dynamicPtrArray[2] = new int(300);
    
    cout << "  Created dynamic array of 3 int pointers:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "    dynamicPtrArray[" << i << "] points to " << *dynamicPtrArray[i] << endl;
    }
    
    // Cleanup
    for (int i = 0; i < 3; i++) {
        delete dynamicPtrArray[i];
    }
    delete[] dynamicPtrArray;
    
    cout << "  Dynamic pointer array cleaned up!" << endl;
    cout << endl;
}
