/**
 * @file 06_advanced_pointers.cpp
 * @brief Advanced Pointer Concepts - Expert Level
 * @author C++ Pointers Learning Guide
 * 
 * This file demonstrates advanced pointer concepts:
 * - Pointer to pointer (double pointers)
 * - Const pointers and pointers to const
 * - Void pointers and type casting
 * - Function pointers advanced usage
 * - Pointer arithmetic with structures
 * 
 * Compilation: g++ -std=c++17 -Wall -Wextra -o advanced_pointers 06_advanced_pointers.cpp
 * Run: ./advanced_pointers
 */

#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

// Function declarations
void demonstrateDoublePointers();
void demonstrateConstPointers();
void demonstrateVoidPointers();
void demonstrateAdvancedFunctionPointers();
void demonstrateStructurePointers();
void demonstratePointerCasting();
void demonstrateComplexPointerExpressions();

// Structure for demonstrations
struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    void display() const { cout << "(" << x << ", " << y << ")"; }
};

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

int main() {
    cout << "=== C++ Advanced Pointer Concepts Demonstration ===" << endl;
    cout << "====================================================" << endl << endl;
    
    demonstrateDoublePointers();
    demonstrateConstPointers();
    demonstrateVoidPointers();
    demonstrateAdvancedFunctionPointers();
    demonstrateStructurePointers();
    demonstratePointerCasting();
    demonstrateComplexPointerExpressions();
    
    cout << "\n=== End of Advanced Pointers Demo ===" << endl;
    return 0;
}

/**
 * @brief Demonstrates pointer to pointer (double pointers)
 */
void demonstrateDoublePointers() {
    cout << "1. POINTER TO POINTER (DOUBLE POINTERS)" << endl;
    cout << "========================================" << endl;
    
    int value = 42;
    int* ptr = &value;
    int** pptr = &ptr;
    int*** ppptr = &pptr;
    
    cout << "Multi-level pointer chain:" << endl;
    cout << "  value = " << value << " at address " << &value << endl;
    cout << "  ptr = " << ptr << " (points to value)" << endl;
    cout << "  pptr = " << pptr << " (points to ptr)" << endl;
    cout << "  ppptr = " << ppptr << " (points to pptr)" << endl << endl;
    
    cout << "Accessing value through different levels:" << endl;
    cout << "  Direct: value = " << value << endl;
    cout << "  Through ptr: *ptr = " << *ptr << endl;
    cout << "  Through pptr: **pptr = " << **pptr << endl;
    cout << "  Through ppptr: ***ppptr = " << ***ppptr << endl << endl;
    
    // Modify through double pointer
    **pptr = 100;
    cout << "After **pptr = 100:" << endl;
    cout << "  value = " << value << endl;
    cout << "  *ptr = " << *ptr << endl;
    cout << "  **pptr = " << **pptr << endl << endl;
    
    // Practical use: Function that modifies a pointer
    auto modifyPointer = [](int** pp, int newValue) {
        *pp = new int(newValue);
    };
    
    int* dynamicPtr = nullptr;
    cout << "Before modifyPointer: dynamicPtr = " << dynamicPtr << endl;
    
    modifyPointer(&dynamicPtr, 200);
    cout << "After modifyPointer: dynamicPtr = " << dynamicPtr << ", *dynamicPtr = " << *dynamicPtr << endl;
    
    delete dynamicPtr;
    cout << endl;
    
    // Array of pointers
    cout << "Array of pointers:" << endl;
    int a = 10, b = 20, c = 30;
    int* ptrArray[] = {&a, &b, &c};
    int** arrayPtr = ptrArray;
    
    for (int i = 0; i < 3; i++) {
        cout << "  arrayPtr[" << i << "] points to " << *arrayPtr[i] << endl;
    }
    cout << endl;
}

/**
 * @brief Demonstrates const pointers and pointers to const
 */
void demonstrateConstPointers() {
    cout << "2. CONST POINTERS AND POINTERS TO CONST" << endl;
    cout << "========================================" << endl;
    
    int x = 10, y = 20;
    
    // 1. Pointer to constant
    cout << "1. Pointer to constant (const int*):" << endl;
    const int* ptr1 = &x;
    cout << "  ptr1 points to: " << *ptr1 << endl;
    
    // *ptr1 = 30;  // ERROR: Cannot modify value through pointer
    ptr1 = &y;      // OK: Can change what it points to
    cout << "  After ptr1 = &y: " << *ptr1 << endl << endl;
    
    // 2. Constant pointer
    cout << "2. Constant pointer (int* const):" << endl;
    int* const ptr2 = &x;
    cout << "  ptr2 points to: " << *ptr2 << endl;
    
    *ptr2 = 40;     // OK: Can modify value
    // ptr2 = &y;   // ERROR: Cannot change what it points to
    cout << "  After *ptr2 = 40: " << *ptr2 << endl << endl;
    
    // 3. Constant pointer to constant
    cout << "3. Constant pointer to constant (const int* const):" << endl;
    const int* const ptr3 = &x;
    cout << "  ptr3 points to: " << *ptr3 << endl;
    
    // *ptr3 = 50;  // ERROR: Cannot modify value
    // ptr3 = &y;   // ERROR: Cannot change what it points to
    cout << "  ptr3 is completely immutable" << endl << endl;
    
    // Practical example: Function parameters
    auto printArray = [](const int* arr, int size) {
        cout << "  Array contents: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
            // arr[i] = 0;  // ERROR: Cannot modify through const pointer
        }
        cout << endl;
    };
    
    int numbers[] = {1, 2, 3, 4, 5};
    cout << "Using const pointer in function:" << endl;
    printArray(numbers, 5);
    cout << endl;
}

/**
 * @brief Demonstrates void pointers and type casting
 */
void demonstrateVoidPointers() {
    cout << "3. VOID POINTERS AND TYPE CASTING" << endl;
    cout << "==================================" << endl;
    
    void* vptr;
    int i = 42;
    float f = 3.14f;
    char c = 'A';
    
    cout << "Void pointer can point to any type:" << endl;
    
    vptr = &i;
    cout << "  Pointing to int: " << *(int*)vptr << endl;
    
    vptr = &f;
    cout << "  Pointing to float: " << *(float*)vptr << endl;
    
    vptr = &c;
    cout << "  Pointing to char: " << *(char*)vptr << endl << endl;
    
    // Generic function using void pointers
    auto genericPrint = [](void* ptr, char type) {
        switch (type) {
            case 'i': cout << "  Int value: " << *(int*)ptr << endl; break;
            case 'f': cout << "  Float value: " << *(float*)ptr << endl; break;
            case 'c': cout << "  Char value: " << *(char*)ptr << endl; break;
            default: cout << "  Unknown type" << endl;
        }
    };
    
    cout << "Generic function with void pointers:" << endl;
    genericPrint(&i, 'i');
    genericPrint(&f, 'f');
    genericPrint(&c, 'c');
    cout << endl;
    
    // Memory operations with void pointers
    cout << "Memory operations with void pointers:" << endl;
    char buffer[100];
    void* bufPtr = buffer;
    
    // Copy different types to buffer
    memcpy(bufPtr, &i, sizeof(int));
    memcpy((char*)bufPtr + sizeof(int), &f, sizeof(float));
    memcpy((char*)bufPtr + sizeof(int) + sizeof(float), &c, sizeof(char));
    
    // Read back
    int readInt = *(int*)bufPtr;
    float readFloat = *(float*)((char*)bufPtr + sizeof(int));
    char readChar = *(char*)((char*)bufPtr + sizeof(int) + sizeof(float));
    
    cout << "  Stored and retrieved: int=" << readInt 
         << ", float=" << readFloat << ", char=" << readChar << endl;
    cout << endl;
}

/**
 * @brief Demonstrates advanced function pointer usage
 */
void demonstrateAdvancedFunctionPointers() {
    cout << "4. ADVANCED FUNCTION POINTERS" << endl;
    cout << "==============================" << endl;
    
    // Function pointer arrays for state machines
    enum State { IDLE, RUNNING, PAUSED, STOPPED };
    
    auto idleHandler = []() { cout << "  State: IDLE - Waiting for input" << endl; };
    auto runHandler = []() { cout << "  State: RUNNING - Processing data" << endl; };
    auto pauseHandler = []() { cout << "  State: PAUSED - Temporarily stopped" << endl; };
    auto stopHandler = []() { cout << "  State: STOPPED - Shutting down" << endl; };
    
    void (*stateHandlers[])() = {idleHandler, runHandler, pauseHandler, stopHandler};
    
    cout << "State machine using function pointer array:" << endl;
    for (int state = IDLE; state <= STOPPED; state++) {
        stateHandlers[state]();
    }
    cout << endl;
    
    // Function pointers with different signatures
    cout << "Function pointers with different signatures:" << endl;
    
    auto intFunc = [](int x) -> int { return x * 2; };
    auto floatFunc = [](float x) -> float { return x * 1.5f; };
    auto stringFunc = [](const char* s) -> int { return strlen(s); };
    
    int (*intFPtr)(int) = intFunc;
    float (*floatFPtr)(float) = floatFunc;
    int (*stringFPtr)(const char*) = stringFunc;
    
    cout << "  intFunc(5) = " << intFPtr(5) << endl;
    cout << "  floatFunc(3.0) = " << floatFPtr(3.0f) << endl;
    cout << "  stringFunc(\"Hello\") = " << stringFPtr("Hello") << endl;
    cout << endl;
    
    // Returning function pointers
    auto getFunctionByType = [](char type) -> void(*)() {
        static auto typeA = []() { cout << "  Function A executed" << endl; };
        static auto typeB = []() { cout << "  Function B executed" << endl; };
        static auto typeC = []() { cout << "  Function C executed" << endl; };
        
        switch (type) {
            case 'A': return typeA;
            case 'B': return typeB;
            case 'C': return typeC;
            default: return nullptr;
        }
    };
    
    cout << "Returning function pointers:" << endl;
    auto func = getFunctionByType('B');
    if (func) func();
    cout << endl;
}

/**
 * @brief Demonstrates pointer arithmetic with structures
 */
void demonstrateStructurePointers() {
    cout << "5. STRUCTURE POINTERS AND ARITHMETIC" << endl;
    cout << "=====================================" << endl;
    
    Point points[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    Point* ptr = points;
    
    cout << "Array of Point structures:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "  points[" << i << "]: ";
        points[i].display();
        cout << " at address " << &points[i] << endl;
    }
    cout << endl;
    
    cout << "Accessing through pointer arithmetic:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "  (ptr + " << i << "): ";
        (ptr + i)->display();
        cout << " - x=" << (ptr + i)->x << ", y=" << (ptr + i)->y << endl;
    }
    cout << endl;
    
    // Linked list with pointers
    cout << "Linked list demonstration:" << endl;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    
    cout << "  List contents: ";
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    
    // Cleanup linked list
    current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    cout << "  Linked list cleaned up" << endl << endl;
    
    // Structure member pointers
    cout << "Pointers to structure members:" << endl;
    Point p(10, 20);
    
    int Point::*xPtr = &Point::x;
    int Point::*yPtr = &Point::y;
    
    cout << "  p.x through member pointer: " << p.*xPtr << endl;
    cout << "  p.y through member pointer: " << p.*yPtr << endl;
    
    Point* pPtr = &p;
    cout << "  pPtr->x through member pointer: " << pPtr->*xPtr << endl;
    cout << "  pPtr->y through member pointer: " << pPtr->*yPtr << endl;
    cout << endl;
}

/**
 * @brief Demonstrates pointer casting techniques
 */
void demonstratePointerCasting() {
    cout << "6. POINTER CASTING TECHNIQUES" << endl;
    cout << "==============================" << endl;
    
    // C-style casting
    cout << "C-style casting:" << endl;
    int value = 0x12345678;
    int* intPtr = &value;
    char* charPtr = (char*)intPtr;
    
    cout << "  Original int: 0x" << hex << value << dec << endl;
    cout << "  Bytes: ";
    for (int i = 0; i < 4; i++) {
        cout << "0x" << hex << (unsigned char)charPtr[i] << " ";
    }
    cout << dec << endl << endl;
    
    // Static cast
    cout << "Static cast:" << endl;
    double d = 3.14159;
    void* voidPtr = &d;
    double* doublePtr = static_cast<double*>(voidPtr);
    cout << "  Value through static_cast: " << *doublePtr << endl << endl;
    
    // Reinterpret cast
    cout << "Reinterpret cast:" << endl;
    long long bigInt = 0x123456789ABCDEF0LL;
    long long* bigIntPtr = &bigInt;
    int* intArray = reinterpret_cast<int*>(bigIntPtr);
    
    cout << "  Original long long: 0x" << hex << bigInt << dec << endl;
    cout << "  As two ints: 0x" << hex << intArray[0] << " 0x" << intArray[1] << dec << endl << endl;
    
    // Const cast
    cout << "Const cast:" << endl;
    const int constValue = 100;
    const int* constPtr = &constValue;
    int* nonConstPtr = const_cast<int*>(constPtr);
    
    cout << "  Original const value: " << constValue << endl;
    cout << "  Through const_cast: " << *nonConstPtr << endl;
    // Note: Modifying through const_cast is undefined behavior if original was const
    cout << endl;
}

/**
 * @brief Demonstrates complex pointer expressions
 */
void demonstrateComplexPointerExpressions() {
    cout << "7. COMPLEX POINTER EXPRESSIONS" << endl;
    cout << "===============================" << endl;
    
    // Array of pointers to functions
    cout << "Array of pointers to functions:" << endl;
    
    auto func1 = [](int x) { return x + 1; };
    auto func2 = [](int x) { return x * 2; };
    auto func3 = [](int x) { return x * x; };
    
    int (*funcArray[])(int) = {func1, func2, func3};
    
    for (int i = 0; i < 3; i++) {
        cout << "  funcArray[" << i << "](5) = " << funcArray[i](5) << endl;
    }
    cout << endl;
    
    // Pointer to array
    cout << "Pointer to array:" << endl;
    int matrix[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int (*rowPtr)[4] = matrix;
    
    for (int i = 0; i < 3; i++) {
        cout << "  Row " << i << ": ";
        for (int j = 0; j < 4; j++) {
            cout << rowPtr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Complex declaration parsing
    cout << "Complex pointer declarations:" << endl;
    cout << "  int* ptr;                    // Pointer to int" << endl;
    cout << "  int* arr[10];                // Array of 10 pointers to int" << endl;
    cout << "  int (*ptr)[10];              // Pointer to array of 10 ints" << endl;
    cout << "  int* (*ptr)[10];             // Pointer to array of 10 pointers to int" << endl;
    cout << "  int (*func)(int);            // Pointer to function taking int, returning int" << endl;
    cout << "  int (*funcArr[10])(int);     // Array of 10 pointers to functions" << endl;
    cout << endl;
    
    // Practical example: Command dispatch table
    cout << "Command dispatch table:" << endl;
    
    struct Command {
        const char* name;
        void (*handler)(int);
    };
    
    auto helpCmd = [](int) { cout << "    Help: Available commands..." << endl; };
    auto exitCmd = [](int code) { cout << "    Exit: Exiting with code " << code << endl; };
    auto statusCmd = [](int) { cout << "    Status: System running normally" << endl; };
    
    Command commands[] = {
        {"help", helpCmd},
        {"exit", exitCmd},
        {"status", statusCmd}
    };
    
    for (const auto& cmd : commands) {
        cout << "  Executing '" << cmd.name << "': ";
        cmd.handler(0);
    }
    cout << endl;
}
