/**
 * @file 04_pointers_functions.cpp
 * @brief Pointers and Functions - Intermediate to Advanced Level
 * @author C++ Pointers Learning Guide
 * 
 * This file demonstrates pointers with functions:
 * - Pass by pointer vs pass by reference
 * - Returning pointers from functions
 * - Function pointers
 * - Callback functions
 * - Pointer to member functions
 * 
 * Compilation: g++ -std=c++17 -Wall -Wextra -o pointers_functions 04_pointers_functions.cpp
 * Run: ./pointers_functions
 */

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

// Function declarations
void demonstratePassByPointer();
void demonstrateReturningPointers();
void demonstrateFunctionPointers();
void demonstrateCallbackFunctions();
void demonstratePointerToMemberFunctions();
void demonstrateAdvancedFunctionPointers();

// Helper functions for demonstrations
void swap(int* a, int* b);
void swapRef(int& a, int& b);
int* findMax(int arr[], int size);
int* createArray(int size, int initialValue);
void processArray(int arr[], int size, void (*processor)(int&));

// Mathematical operations for function pointer demo
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

// Callback function examples
void doubleValue(int& x);
void squareValue(int& x);
void printValue(int& x);

// Class for member function pointers
class Calculator {
public:
    int value;
    Calculator(int v = 0) : value(v) {}
    
    int add(int x) { return value + x; }
    int multiply(int x) { return value * x; }
    void setValue(int v) { value = v; }
    void display() const { cout << "Value: " << value << endl; }
};

int main() {
    cout << "=== C++ Pointers and Functions Demonstration ===" << endl;
    cout << "=================================================" << endl << endl;
    
    demonstratePassByPointer();
    demonstrateReturningPointers();
    demonstrateFunctionPointers();
    demonstrateCallbackFunctions();
    demonstratePointerToMemberFunctions();
    demonstrateAdvancedFunctionPointers();
    
    cout << "\n=== End of Pointers and Functions Demo ===" << endl;
    return 0;
}

/**
 * @brief Demonstrates pass by pointer vs other parameter passing methods
 */
void demonstratePassByPointer() {
    cout << "1. PASS BY POINTER VS OTHER METHODS" << endl;
    cout << "====================================" << endl;
    
    int x = 10, y = 20;
    cout << "Initial values: x = " << x << ", y = " << y << endl << endl;
    
    // Pass by pointer
    cout << "Using pass by pointer:" << endl;
    cout << "  Before swap: x = " << x << ", y = " << y << endl;
    swap(&x, &y);
    cout << "  After swap: x = " << x << ", y = " << y << endl << endl;
    
    // Pass by reference (for comparison)
    cout << "Using pass by reference:" << endl;
    cout << "  Before swap: x = " << x << ", y = " << y << endl;
    swapRef(x, y);
    cout << "  After swap: x = " << x << ", y = " << y << endl << endl;
    
    // Demonstrate null pointer handling
    cout << "Null pointer handling:" << endl;
    int* nullPtr = nullptr;
    int* validPtr = &x;
    
    cout << "  Calling swap with null pointer (safe version):" << endl;
    swap(nullPtr, validPtr);  // Our swap function should handle this safely
    cout << "  x remains: " << x << endl << endl;
    
    // Multiple output parameters
    cout << "Multiple output parameters using pointers:" << endl;
    int a = 15, b = 25;
    int sum, product, difference;
    
    auto calculate = [](int* x, int* y, int* s, int* p, int* d) {
        if (x && y && s && p && d) {
            *s = *x + *y;
            *p = *x * *y;
            *d = *x - *y;
        }
    };
    
    calculate(&a, &b, &sum, &product, &difference);
    cout << "  Input: a = " << a << ", b = " << b << endl;
    cout << "  Results: sum = " << sum << ", product = " << product << ", difference = " << difference << endl;
    cout << endl;
}

/**
 * @brief Demonstrates returning pointers from functions
 */
void demonstrateReturningPointers() {
    cout << "2. RETURNING POINTERS FROM FUNCTIONS" << endl;
    cout << "=====================================" << endl;
    
    // Finding maximum element
    int numbers[] = {45, 23, 78, 12, 67, 89, 34, 56};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    int* maxPtr = findMax(numbers, size);
    if (maxPtr) {
        cout << "Maximum value: " << *maxPtr << " at address " << maxPtr << endl;
        cout << "Index of maximum: " << maxPtr - numbers << endl;
    }
    cout << endl;
    
    // Creating dynamic arrays
    cout << "Creating dynamic array:" << endl;
    int* dynamicArr = createArray(5, 100);
    
    cout << "  Created array: ";
    for (int i = 0; i < 5; i++) {
        cout << dynamicArr[i] << " ";
    }
    cout << endl;
    
    // Modify the array
    for (int i = 0; i < 5; i++) {
        dynamicArr[i] += i * 10;
    }
    
    cout << "  Modified array: ";
    for (int i = 0; i < 5; i++) {
        cout << dynamicArr[i] << " ";
    }
    cout << endl;
    
    delete[] dynamicArr;  // Don't forget to free memory!
    cout << "  Dynamic array memory freed" << endl << endl;
    
    // Returning local variable address (DANGEROUS - don't do this!)
    cout << "WARNING: Never return address of local variables!" << endl;
    cout << "This would be undefined behavior:" << endl;
    cout << "  int* badFunction() {" << endl;
    cout << "      int local = 42;" << endl;
    cout << "      return &local;  // WRONG! local is destroyed when function ends" << endl;
    cout << "  }" << endl;
    cout << endl;
}

/**
 * @brief Demonstrates basic function pointers
 */
void demonstrateFunctionPointers() {
    cout << "3. FUNCTION POINTERS" << endl;
    cout << "====================" << endl;
    
    // Function pointer declaration and initialization
    int (*operation)(int, int) = add;
    
    int a = 15, b = 5;
    cout << "Using function pointers for calculations:" << endl;
    cout << "  a = " << a << ", b = " << b << endl << endl;
    
    // Using different operations
    operation = add;
    cout << "  add: " << a << " + " << b << " = " << operation(a, b) << endl;
    
    operation = subtract;
    cout << "  subtract: " << a << " - " << b << " = " << operation(a, b) << endl;
    
    operation = multiply;
    cout << "  multiply: " << a << " * " << b << " = " << operation(a, b) << endl;
    
    operation = divide;
    cout << "  divide: " << a << " / " << b << " = " << operation(a, b) << endl << endl;
    
    // Array of function pointers
    int (*operations[])(int, int) = {add, subtract, multiply, divide};
    const char* opNames[] = {"add", "subtract", "multiply", "divide"};
    
    cout << "Using array of function pointers:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "  " << opNames[i] << "(" << a << ", " << b << ") = " 
             << operations[i](a, b) << endl;
    }
    cout << endl;
    
    // Function pointer as parameter
    auto calculator = [](int x, int y, int (*func)(int, int)) -> int {
        return func(x, y);
    };
    
    cout << "Function pointer as parameter:" << endl;
    cout << "  calculator(10, 3, add) = " << calculator(10, 3, add) << endl;
    cout << "  calculator(10, 3, multiply) = " << calculator(10, 3, multiply) << endl;
    cout << endl;
}

/**
 * @brief Demonstrates callback functions
 */
void demonstrateCallbackFunctions() {
    cout << "4. CALLBACK FUNCTIONS" << endl;
    cout << "=====================" << endl;
    
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);
    
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl << endl;
    
    // Process array with different callbacks
    cout << "Processing with doubleValue callback:" << endl;
    processArray(data, size, doubleValue);
    cout << "  Result: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl << endl;
    
    cout << "Processing with squareValue callback:" << endl;
    processArray(data, size, squareValue);
    cout << "  Result: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl << endl;
    
    // Using lambda as callback
    cout << "Using lambda as callback (add 10 to each element):" << endl;
    auto addTen = [](int& x) { x += 10; };
    processArray(data, size, addTen);
    cout << "  Result: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl << endl;
    
    // Event-driven programming simulation
    cout << "Event-driven programming simulation:" << endl;
    
    struct EventHandler {
        void (*onStart)();
        void (*onProcess)(int);
        void (*onEnd)();
    };
    
    auto startHandler = []() { cout << "  Event: Starting process..." << endl; };
    auto processHandler = [](int value) { cout << "  Event: Processing " << value << endl; };
    auto endHandler = []() { cout << "  Event: Process completed!" << endl; };
    
    EventHandler handler = {startHandler, processHandler, endHandler};
    
    // Simulate event processing
    handler.onStart();
    for (int i = 1; i <= 3; i++) {
        handler.onProcess(i);
    }
    handler.onEnd();
    cout << endl;
}

/**
 * @brief Demonstrates pointer to member functions
 */
void demonstratePointerToMemberFunctions() {
    cout << "5. POINTER TO MEMBER FUNCTIONS" << endl;
    cout << "===============================" << endl;
    
    Calculator calc(10);
    cout << "Calculator object created with initial value: " << calc.value << endl << endl;
    
    // Pointer to member function
    int (Calculator::*mathOp)(int) = &Calculator::add;
    void (Calculator::*setter)(int) = &Calculator::setValue;
    void (Calculator::*displayer)() const = &Calculator::display;
    
    cout << "Using pointer to member functions:" << endl;
    
    // Call member function through pointer
    int result = (calc.*mathOp)(5);
    cout << "  calc.add(5) through pointer: " << result << endl;
    
    // Change operation
    mathOp = &Calculator::multiply;
    result = (calc.*mathOp)(3);
    cout << "  calc.multiply(3) through pointer: " << result << endl << endl;
    
    // Using with pointer to object
    Calculator* calcPtr = &calc;
    result = (calcPtr->*mathOp)(4);
    cout << "  calcPtr->multiply(4) through pointer: " << result << endl;
    
    (calcPtr->*setter)(25);
    cout << "  After setting value to 25:" << endl;
    cout << "    ";
    (calcPtr->*displayer)();
    cout << endl;
    
    // Array of member function pointers
    int (Calculator::*operations[])(int) = {&Calculator::add, &Calculator::multiply};
    const char* opNames[] = {"add", "multiply"};
    
    cout << "Using array of member function pointers:" << endl;
    for (int i = 0; i < 2; i++) {
        result = (calc.*operations[i])(7);
        cout << "  " << opNames[i] << "(7) = " << result << endl;
    }
    cout << endl;
}

/**
 * @brief Demonstrates advanced function pointer concepts
 */
void demonstrateAdvancedFunctionPointers() {
    cout << "6. ADVANCED FUNCTION POINTER CONCEPTS" << endl;
    cout << "======================================" << endl;
    
    // std::function (modern C++ approach)
    cout << "Using std::function (modern C++):" << endl;
    
    std::function<int(int, int)> modernOp;
    
    modernOp = add;
    cout << "  std::function with regular function: " << modernOp(8, 3) << endl;
    
    modernOp = [](int a, int b) { return a * a + b * b; };
    cout << "  std::function with lambda: " << modernOp(3, 4) << endl;
    
    // Function object (functor)
    struct Multiplier {
        int factor;
        Multiplier(int f) : factor(f) {}
        int operator()(int x) const { return x * factor; }
    };
    
    std::function<int(int)> multiplier = Multiplier(5);
    cout << "  std::function with functor: " << multiplier(6) << endl << endl;
    
    // Higher-order functions
    cout << "Higher-order functions:" << endl;
    
    auto applyTwice = [](int x, std::function<int(int)> func) {
        return func(func(x));
    };
    
    auto increment = [](int x) { return x + 1; };
    auto square = [](int x) { return x * x; };
    
    cout << "  applyTwice(5, increment) = " << applyTwice(5, increment) << endl;
    cout << "  applyTwice(3, square) = " << applyTwice(3, square) << endl << endl;
    
    // Function composition
    cout << "Function composition:" << endl;
    
    auto compose = [](std::function<int(int)> f, std::function<int(int)> g) {
        return [f, g](int x) { return f(g(x)); };
    };
    
    auto addTwo = [](int x) { return x + 2; };
    auto timesThree = [](int x) { return x * 3; };
    
    auto composed = compose(addTwo, timesThree);  // (x * 3) + 2
    cout << "  compose(addTwo, timesThree)(4) = " << composed(4) << endl;
    cout << "  This computes (4 * 3) + 2 = " << composed(4) << endl << endl;
    
    // Using with STL algorithms
    cout << "Using function pointers with STL algorithms:" << endl;
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << "  Original vector: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;
    
    // Transform using lambda
    transform(numbers.begin(), numbers.end(), numbers.begin(), 
              [](int x) { return x * x; });
    
    cout << "  After squaring: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;
    
    // Count elements using predicate
    auto isEven = [](int x) { return x % 2 == 0; };
    int evenCount = count_if(numbers.begin(), numbers.end(), isEven);
    cout << "  Even numbers count: " << evenCount << endl;
    cout << endl;
}

// Helper function implementations
void swap(int* a, int* b) {
    if (a && b) {  // Null pointer check
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

void swapRef(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int* findMax(int arr[], int size) {
    if (!arr || size <= 0) return nullptr;
    
    int* maxPtr = arr;
    for (int i = 1; i < size; i++) {
        if (arr[i] > *maxPtr) {
            maxPtr = &arr[i];
        }
    }
    return maxPtr;
}

int* createArray(int size, int initialValue) {
    if (size <= 0) return nullptr;
    
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = initialValue;
    }
    return arr;
}

void processArray(int arr[], int size, void (*processor)(int&)) {
    if (!arr || !processor) return;
    
    for (int i = 0; i < size; i++) {
        processor(arr[i]);
    }
}

// Mathematical operations
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

// Callback functions
void doubleValue(int& x) { x *= 2; }
void squareValue(int& x) { x *= x; }
void printValue(int& x) { cout << x << " "; }
