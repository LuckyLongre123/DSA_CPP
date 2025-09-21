/**
 * @file 05_dynamic_memory.cpp
 * @brief Dynamic Memory Management - Advanced Level
 * @author C++ Pointers Learning Guide
 * 
 * This file demonstrates dynamic memory management:
 * - new and delete operators
 * - Memory leaks and prevention
 * - RAII (Resource Acquisition Is Initialization)
 * - Custom memory management
 * - Memory debugging techniques
 * 
 * Compilation: g++ -std=c++17 -Wall -Wextra -g -fsanitize=address -o dynamic_memory 05_dynamic_memory.cpp
 * Run: ./dynamic_memory
 */

#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <cstring>

using namespace std;
using namespace std::chrono;

// Function declarations
void demonstrateBasicDynamicAllocation();
void demonstrateArrayAllocation();
void demonstrateMemoryLeaks();
void demonstrateRAII();
void demonstrateCustomMemoryManagement();
void demonstrateMemoryDebugging();
void demonstratePerformanceConsiderations();

// RAII classes for demonstration
class SafeIntArray {
private:
    int* data;
    size_t size;

public:
    SafeIntArray(size_t s) : size(s) {
        data = new int[size];
        cout << "    SafeIntArray: Allocated " << size << " integers" << endl;
    }
    
    ~SafeIntArray() {
        delete[] data;
        cout << "    SafeIntArray: Freed " << size << " integers" << endl;
    }
    
    // Prevent copying (or implement proper copy semantics)
    SafeIntArray(const SafeIntArray&) = delete;
    SafeIntArray& operator=(const SafeIntArray&) = delete;
    
    // Allow moving
    SafeIntArray(SafeIntArray&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }
    
    SafeIntArray& operator=(SafeIntArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
    
    int& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }
    
    size_t getSize() const { return size; }
};

// Custom memory pool for demonstration
class SimpleMemoryPool {
private:
    char* pool;
    size_t poolSize;
    size_t offset;

public:
    SimpleMemoryPool(size_t size) : poolSize(size), offset(0) {
        pool = new char[poolSize];
        cout << "    MemoryPool: Created pool of " << poolSize << " bytes" << endl;
    }
    
    ~SimpleMemoryPool() {
        delete[] pool;
        cout << "    MemoryPool: Destroyed pool" << endl;
    }
    
    void* allocate(size_t size) {
        if (offset + size > poolSize) {
            cout << "    MemoryPool: Out of memory!" << endl;
            return nullptr;
        }
        void* ptr = pool + offset;
        offset += size;
        cout << "    MemoryPool: Allocated " << size << " bytes at offset " << (offset - size) << endl;
        return ptr;
    }
    
    void reset() {
        offset = 0;
        cout << "    MemoryPool: Reset pool" << endl;
    }
    
    size_t getUsed() const { return offset; }
    size_t getAvailable() const { return poolSize - offset; }
    size_t getPoolSize() const { return poolSize; }
};

int main() {
    cout << "=== C++ Dynamic Memory Management Demonstration ===" << endl;
    cout << "===================================================" << endl << endl;
    
    demonstrateBasicDynamicAllocation();
    demonstrateArrayAllocation();
    demonstrateMemoryLeaks();
    demonstrateRAII();
    demonstrateCustomMemoryManagement();
    demonstrateMemoryDebugging();
    demonstratePerformanceConsiderations();
    
    cout << "\n=== End of Dynamic Memory Management Demo ===" << endl;
    return 0;
}

/**
 * @brief Demonstrates basic dynamic allocation with new and delete
 */
void demonstrateBasicDynamicAllocation() {
    cout << "1. BASIC DYNAMIC ALLOCATION" << endl;
    cout << "===========================" << endl;
    
    // Single object allocation
    cout << "Allocating single integer:" << endl;
    int* ptr = new int(42);
    cout << "  Allocated int with value: " << *ptr << endl;
    cout << "  Address: " << ptr << endl;
    cout << "  Size: " << sizeof(*ptr) << " bytes" << endl;
    
    *ptr = 100;
    cout << "  Modified value: " << *ptr << endl;
    
    delete ptr;
    cout << "  Memory freed" << endl;
    ptr = nullptr;  // Good practice
    cout << endl;
    
    // Different data types
    cout << "Allocating different data types:" << endl;
    
    double* dPtr = new double(3.14159);
    char* cPtr = new char('A');
    bool* bPtr = new bool(true);
    
    cout << "  double: " << *dPtr << " at " << dPtr << endl;
    cout << "  char: " << *cPtr << " at " << (void*)cPtr << endl;
    cout << "  bool: " << *bPtr << " at " << bPtr << endl;
    
    delete dPtr;
    delete cPtr;
    delete bPtr;
    cout << "  All memory freed" << endl << endl;
    
    // Initialization variations
    cout << "Different initialization methods:" << endl;
    
    int* ptr1 = new int;        // Uninitialized (garbage value)
    int* ptr2 = new int();      // Zero-initialized
    int* ptr3 = new int(55);    // Value-initialized
    int* ptr4 = new int{77};    // Brace-initialized (C++11)
    
    cout << "  Uninitialized: " << *ptr1 << " (garbage)" << endl;
    cout << "  Zero-initialized: " << *ptr2 << endl;
    cout << "  Value-initialized: " << *ptr3 << endl;
    cout << "  Brace-initialized: " << *ptr4 << endl;
    
    delete ptr1;
    delete ptr2;
    delete ptr3;
    delete ptr4;
    cout << endl;
}

/**
 * @brief Demonstrates dynamic array allocation
 */
void demonstrateArrayAllocation() {
    cout << "2. DYNAMIC ARRAY ALLOCATION" << endl;
    cout << "============================" << endl;
    
    int size = 5;
    cout << "Allocating array of " << size << " integers:" << endl;
    
    // Array allocation
    int* arr = new int[size];
    cout << "  Array allocated at: " << arr << endl;
    
    // Initialize array
    for (int i = 0; i < size; i++) {
        arr[i] = i * i;
    }
    
    cout << "  Array contents: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Array with initialization
    cout << "\nArray with initialization:" << endl;
    int* arr2 = new int[size]();  // Zero-initialized
    cout << "  Zero-initialized array: ";
    for (int i = 0; i < size; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    // C++11 brace initialization
    int* arr3 = new int[5]{1, 2, 3, 4, 5};
    cout << "  Brace-initialized array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
    
    delete[] arr;   // Note: delete[] for arrays
    delete[] arr2;
    delete[] arr3;
    cout << "  All arrays freed" << endl << endl;
    
    // 2D dynamic array
    cout << "2D dynamic array allocation:" << endl;
    int rows = 3, cols = 4;
    
    // Method 1: Array of pointers
    int** matrix = new int*[rows];
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
    cout << "  Matrix contents:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "    ";
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // Cleanup 2D array
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    cout << "  2D array freed" << endl << endl;
    
    // Method 2: Single allocation (more efficient)
    cout << "2D array as single allocation:" << endl;
    int* flatMatrix = new int[rows * cols];
    
    // Initialize
    for (int i = 0; i < rows * cols; i++) {
        flatMatrix[i] = i + 1;
    }
    
    // Access as 2D (row-major order)
    cout << "  Flat matrix as 2D:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "    ";
        for (int j = 0; j < cols; j++) {
            cout << flatMatrix[i * cols + j] << " ";
        }
        cout << endl;
    }
    
    delete[] flatMatrix;
    cout << "  Flat matrix freed" << endl;
    cout << endl;
}

/**
 * @brief Demonstrates memory leaks and how to prevent them
 */
void demonstrateMemoryLeaks() {
    cout << "3. MEMORY LEAKS AND PREVENTION" << endl;
    cout << "===============================" << endl;
    
    cout << "Common memory leak scenarios:" << endl << endl;
    
    // Scenario 1: Forgetting to delete
    cout << "Scenario 1: Forgetting to delete (LEAK!)" << endl;
    cout << "  int* leak = new int(100);" << endl;
    cout << "  // Forgot to delete leak!" << endl;
    cout << "  This causes a memory leak!" << endl << endl;
    
    // Scenario 2: Exception before delete
    cout << "Scenario 2: Exception before delete" << endl;
    cout << "  Demonstrating exception safety:" << endl;
    
    try {
        int* ptr = new int[1000];
        cout << "    Allocated array" << endl;
        
        // Simulate an exception
        if (true) {  // This would be some condition that might throw
            delete[] ptr;  // Clean up before throwing
            throw runtime_error("Simulated exception");
        }
        
        delete[] ptr;  // This line would never be reached
    } catch (const exception& e) {
        cout << "    Caught exception: " << e.what() << endl;
        cout << "    Memory was cleaned up before throwing" << endl;
    }
    cout << endl;
    
    // Scenario 3: Early return
    cout << "Scenario 3: Early return without cleanup" << endl;
    
    auto riskyFunction = [](bool earlyReturn) {
        int* ptr = new int[100];
        cout << "    Allocated memory in function" << endl;
        
        if (earlyReturn) {
            cout << "    Early return - cleaning up first" << endl;
            delete[] ptr;
            return;
        }
        
        // Normal processing...
        delete[] ptr;
        cout << "    Normal cleanup" << endl;
    };
    
    riskyFunction(true);   // Early return case
    riskyFunction(false);  // Normal case
    cout << endl;
    
    // Scenario 4: Double deletion
    cout << "Scenario 4: Double deletion (UNDEFINED BEHAVIOR!)" << endl;
    int* ptr = new int(42);
    cout << "    Allocated integer" << endl;
    
    delete ptr;
    cout << "    First delete - OK" << endl;
    
    // delete ptr;  // NEVER DO THIS! Undefined behavior!
    cout << "    Second delete would be undefined behavior!" << endl;
    
    ptr = nullptr;  // Safe practice
    delete ptr;     // Deleting nullptr is safe (no-op)
    cout << "    Deleting nullptr is safe" << endl;
    cout << endl;
}

/**
 * @brief Demonstrates RAII (Resource Acquisition Is Initialization)
 */
void demonstrateRAII() {
    cout << "4. RAII (RESOURCE ACQUISITION IS INITIALIZATION)" << endl;
    cout << "================================================" << endl;
    
    cout << "RAII ensures automatic resource cleanup:" << endl << endl;
    
    // Using RAII class
    cout << "Using RAII class:" << endl;
    {
        SafeIntArray arr(10);
        
        // Initialize array
        for (size_t i = 0; i < arr.getSize(); i++) {
            arr[i] = i * 2;
        }
        
        cout << "    Array contents: ";
        for (size_t i = 0; i < arr.getSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        // Exception safety test
        try {
            if (arr.getSize() > 5) {
                throw runtime_error("Test exception");
            }
        } catch (const exception& e) {
            cout << "    Exception caught: " << e.what() << endl;
            cout << "    RAII will still clean up automatically" << endl;
        }
        
    }  // Destructor called here automatically
    cout << "    RAII object destroyed, memory cleaned up" << endl << endl;
    
    // Comparison with manual management (exception-safe version)
    cout << "Manual management (exception-safe approach):" << endl;
    int* manualArray = nullptr;
    
    try {
        manualArray = new int[5];
        cout << "    Manually allocated array" << endl;
        
        // Some processing...
        for (int i = 0; i < 5; i++) {
            manualArray[i] = i;
        }
        
        // Normal cleanup
        delete[] manualArray;
        manualArray = nullptr;
        cout << "    Manually cleaned up successfully" << endl;
        
    } catch (...) {
        // Exception cleanup - only delete if not already deleted
        if (manualArray) {
            delete[] manualArray;
            manualArray = nullptr;
            cout << "    Exception cleanup performed" << endl;
        }
        throw;
    }
    cout << endl;
    
    // Modern C++ approach with smart pointers
    cout << "Modern C++ with smart pointers:" << endl;
    {
        auto smartArray = std::make_unique<int[]>(5);
        cout << "    Smart pointer array created" << endl;
        
        for (int i = 0; i < 5; i++) {
            smartArray[i] = i * 3;
        }
        
        cout << "    Smart array contents: ";
        for (int i = 0; i < 5; i++) {
            cout << smartArray[i] << " ";
        }
        cout << endl;
        
    }  // Automatic cleanup
    cout << "    Smart pointer automatically cleaned up" << endl;
    cout << endl;
}

/**
 * @brief Demonstrates custom memory management techniques
 */
void demonstrateCustomMemoryManagement() {
    cout << "5. CUSTOM MEMORY MANAGEMENT" << endl;
    cout << "===========================" << endl;
    
    // Memory pool demonstration
    cout << "Memory pool demonstration:" << endl;
    {
        SimpleMemoryPool pool(1024);  // 1KB pool
        
        cout << "    Pool status: " << pool.getUsed() << "/" << pool.getPoolSize() << " bytes used" << endl;
        
        // Allocate some memory
        int* intPtr = static_cast<int*>(pool.allocate(sizeof(int)));
        if (intPtr) {
            *intPtr = 42;
            cout << "    Allocated int: " << *intPtr << endl;
        }
        
        double* doublePtr = static_cast<double*>(pool.allocate(sizeof(double)));
        if (doublePtr) {
            *doublePtr = 3.14;
            cout << "    Allocated double: " << *doublePtr << endl;
        }
        
        // Allocate array
        char* charArray = static_cast<char*>(pool.allocate(100));
        if (charArray) {
            strcpy(charArray, "Hello from memory pool!");
            cout << "    Allocated string: " << charArray << endl;
        }
        
        cout << "    Pool status: " << pool.getUsed() << "/" << pool.getPoolSize() << " bytes used" << endl;
        cout << "    Available: " << pool.getAvailable() << " bytes" << endl;
        
        // Reset pool
        pool.reset();
        cout << "    After reset: " << pool.getUsed() << "/" << pool.getPoolSize() << " bytes used" << endl;
        
    }  // Pool destructor cleans up everything
    cout << endl;
    
    // Stack allocator simulation
    cout << "Stack allocator simulation:" << endl;
    
    class StackAllocator {
        char* memory;
        size_t size;
        size_t top;
        
    public:
        StackAllocator(size_t s) : size(s), top(0) {
            memory = new char[size];
            cout << "    StackAllocator: Created " << size << " byte stack" << endl;
        }
        
        ~StackAllocator() {
            delete[] memory;
            cout << "    StackAllocator: Destroyed" << endl;
        }
        
        void* push(size_t bytes) {
            if (top + bytes > size) return nullptr;
            void* ptr = memory + top;
            top += bytes;
            cout << "    StackAllocator: Pushed " << bytes << " bytes, top = " << top << endl;
            return ptr;
        }
        
        void pop(size_t bytes) {
            if (bytes > top) top = 0;
            else top -= bytes;
            cout << "    StackAllocator: Popped " << bytes << " bytes, top = " << top << endl;
        }
        
        size_t getTop() const { return top; }
    };
    
    {
        StackAllocator stack(512);
        
        // Push some allocations
        int* a = static_cast<int*>(stack.push(sizeof(int)));
        if (a) *a = 10;
        
        double* b = static_cast<double*>(stack.push(sizeof(double)));
        if (b) *b = 2.5;
        
        char* c = static_cast<char*>(stack.push(50));
        if (c) strcpy(c, "Stack allocated string");
        
        cout << "    Values: int=" << *a << ", double=" << *b << ", string=" << c << endl;
        
        // Pop in reverse order (LIFO)
        stack.pop(50);           // Pop string
        stack.pop(sizeof(double)); // Pop double
        stack.pop(sizeof(int));    // Pop int
        
    }  // Stack destructor cleans up
    cout << endl;
}

/**
 * @brief Demonstrates memory debugging techniques
 */
void demonstrateMemoryDebugging() {
    cout << "6. MEMORY DEBUGGING TECHNIQUES" << endl;
    cout << "==============================" << endl;
    
    cout << "Memory debugging strategies:" << endl << endl;
    
    // 1. Null pointer checks
    cout << "1. Always check for allocation failure:" << endl;
    size_t hugeSize = 1000000000;  // 1GB - might fail
    int* ptr = new(std::nothrow) int[hugeSize];
    
    if (ptr == nullptr) {
        cout << "    Allocation failed - handled gracefully" << endl;
    } else {
        cout << "    Large allocation succeeded" << endl;
        delete[] ptr;
    }
    cout << endl;
    
    // 2. Set pointers to nullptr after deletion
    cout << "2. Set pointers to nullptr after deletion:" << endl;
    int* safePtr = new int(100);
    cout << "    Allocated: " << *safePtr << endl;
    
    delete safePtr;
    safePtr = nullptr;  // Prevent accidental reuse
    
    if (safePtr == nullptr) {
        cout << "    Pointer safely set to nullptr" << endl;
    }
    cout << endl;
    
    // 3. Use tools like Valgrind, AddressSanitizer
    cout << "3. Memory debugging tools:" << endl;
    cout << "    - Compile with: g++ -fsanitize=address -g" << endl;
    cout << "    - Use Valgrind: valgrind --leak-check=full ./program" << endl;
    cout << "    - Use static analysis tools" << endl;
    cout << endl;
    
    // 4. Custom debug allocator
    cout << "4. Custom debug tracking:" << endl;
    
    static size_t allocCount = 0;
    static size_t deallocCount = 0;
    
    auto debugNew = [](size_t size) -> void* {
        void* ptr = malloc(size);
        if (ptr) {
            allocCount++;
            cout << "    DEBUG: Allocated " << size << " bytes at " << ptr 
                 << " (total allocs: " << allocCount << ")" << endl;
        }
        return ptr;
    };
    
    auto debugDelete = [](void* ptr) {
        if (ptr) {
            deallocCount++;
            cout << "    DEBUG: Freed memory at " << ptr 
                 << " (total frees: " << deallocCount << ")" << endl;
            free(ptr);
        }
    };
    
    // Use debug allocator
    void* p1 = debugNew(100);
    void* p2 = debugNew(200);
    void* p3 = debugNew(50);
    
    debugDelete(p1);
    debugDelete(p2);
    debugDelete(p3);
    
    cout << "    Final stats: " << allocCount << " allocations, " 
         << deallocCount << " deallocations" << endl;
    cout << endl;
}

/**
 * @brief Demonstrates performance considerations
 */
void demonstratePerformanceConsiderations() {
    cout << "7. PERFORMANCE CONSIDERATIONS" << endl;
    cout << "==============================" << endl;
    
    const int iterations = 100000;
    
    // Stack vs Heap allocation performance
    cout << "Stack vs Heap allocation performance:" << endl;
    
    // Stack allocation timing
    auto start = high_resolution_clock::now();
    volatile int dummy = 0;  // Prevent optimization
    for (int i = 0; i < iterations; i++) {
        int stackArray[100];  // Stack allocation
        stackArray[0] = i;    // Use it to prevent optimization
        dummy += stackArray[0];  // Actually use the value
    }
    auto end = high_resolution_clock::now();
    auto stackTime = duration_cast<microseconds>(end - start);
    
    // Heap allocation timing
    start = high_resolution_clock::now();
    for (int i = 0; i < iterations; i++) {
        int* heapArray = new int[100];  // Heap allocation
        heapArray[0] = i;               // Use it
        delete[] heapArray;             // Clean up
    }
    end = high_resolution_clock::now();
    auto heapTime = duration_cast<microseconds>(end - start);
    
    cout << "    Stack allocation time: " << stackTime.count() << " microseconds" << endl;
    cout << "    Heap allocation time: " << heapTime.count() << " microseconds" << endl;
    cout << "    Heap is " << (double)heapTime.count() / stackTime.count() 
         << "x slower than stack" << endl << endl;
    
    // Memory fragmentation demonstration
    cout << "Memory fragmentation considerations:" << endl;
    
    vector<void*> ptrs;
    
    // Allocate many small blocks
    cout << "    Allocating many small blocks..." << endl;
    for (int i = 0; i < 1000; i++) {
        ptrs.push_back(malloc(16));  // Small allocations
    }
    
    // Free every other block (creates fragmentation)
    cout << "    Freeing every other block (creates fragmentation)..." << endl;
    for (size_t i = 0; i < ptrs.size(); i += 2) {
        free(ptrs[i]);
        ptrs[i] = nullptr;
    }
    
    // Try to allocate a larger block
    cout << "    Trying to allocate larger block..." << endl;
    void* largeBlock = malloc(8000);  // Might fail due to fragmentation
    
    if (largeBlock) {
        cout << "    Large allocation succeeded" << endl;
        free(largeBlock);
    } else {
        cout << "    Large allocation failed (fragmentation?)" << endl;
    }
    
    // Clean up remaining blocks
    for (void* ptr : ptrs) {
        if (ptr) free(ptr);
    }
    
    cout << "    Cleanup completed" << endl << endl;
    
    // Memory alignment considerations
    cout << "Memory alignment considerations:" << endl;
    
    struct UnalignedStruct {
        char c;
        int i;
        char c2;
        double d;
    };
    
    struct AlignedStruct {
        double d;  // 8-byte aligned
        int i;     // 4-byte aligned
        char c;    // 1-byte
        char c2;   // 1-byte
        // Compiler adds padding
    };
    
    cout << "    Unaligned struct size: " << sizeof(UnalignedStruct) << " bytes" << endl;
    cout << "    Aligned struct size: " << sizeof(AlignedStruct) << " bytes" << endl;
    cout << "    Proper alignment can improve performance and reduce memory usage" << endl;
    cout << endl;
}
