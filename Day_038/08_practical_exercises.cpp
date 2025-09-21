/**
 * @file 08_practical_exercises.cpp
 * @brief Practical Exercises and Projects
 * @author C++ Pointers Learning Guide
 * 
 * This file contains hands-on exercises to practice pointer concepts:
 * - Basic pointer manipulation exercises
 * - Dynamic data structure implementations
 * - Memory management challenges
 * - Real-world application examples
 * 
 * Compilation: g++ -std=c++17 -Wall -Wextra -o exercises 08_practical_exercises.cpp
 * Run: ./exercises
 */

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// Exercise implementations
void exercise1_BasicPointerManipulation();
void exercise2_DynamicArrayOperations();
void exercise3_LinkedListImplementation();
void exercise4_StringManipulation();
void exercise5_FunctionPointerCalculator();
void exercise6_SmartPointerDataStructures();
void exercise7_MemoryPoolImplementation();

// Helper classes and structures
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

class SimpleLinkedList {
private:
    ListNode* head;
    
public:
    SimpleLinkedList() : head(nullptr) {}
    
    ~SimpleLinkedList() {
        clear();
    }
    
    void insert(int value) {
        ListNode* newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
    }
    
    void display() const {
        ListNode* current = head;
        cout << "List: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    void clear() {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    bool remove(int value) {
        if (!head) return false;
        
        if (head->data == value) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        
        ListNode* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }
        
        if (current->next) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }
        
        return false;
    }
};

int main() {
    cout << "=== C++ Pointers Practical Exercises ===" << endl;
    cout << "=========================================" << endl << endl;
    
    cout << "Choose an exercise to run (1-7), or 0 to run all:" << endl;
    cout << "1. Basic Pointer Manipulation" << endl;
    cout << "2. Dynamic Array Operations" << endl;
    cout << "3. Linked List Implementation" << endl;
    cout << "4. String Manipulation with Pointers" << endl;
    cout << "5. Function Pointer Calculator" << endl;
    cout << "6. Smart Pointer Data Structures" << endl;
    cout << "7. Memory Pool Implementation" << endl;
    
    int choice;
    cout << "Enter choice: ";
    cin >> choice;
    cout << endl;
    
    switch (choice) {
        case 0:
            exercise1_BasicPointerManipulation();
            exercise2_DynamicArrayOperations();
            exercise3_LinkedListImplementation();
            exercise4_StringManipulation();
            exercise5_FunctionPointerCalculator();
            exercise6_SmartPointerDataStructures();
            exercise7_MemoryPoolImplementation();
            break;
        case 1: exercise1_BasicPointerManipulation(); break;
        case 2: exercise2_DynamicArrayOperations(); break;
        case 3: exercise3_LinkedListImplementation(); break;
        case 4: exercise4_StringManipulation(); break;
        case 5: exercise5_FunctionPointerCalculator(); break;
        case 6: exercise6_SmartPointerDataStructures(); break;
        case 7: exercise7_MemoryPoolImplementation(); break;
        default: cout << "Invalid choice!" << endl;
    }
    
    return 0;
}

/**
 * @brief Exercise 1: Basic pointer manipulation challenges
 */
void exercise1_BasicPointerManipulation() {
    cout << "EXERCISE 1: BASIC POINTER MANIPULATION" << endl;
    cout << "=======================================" << endl;
    
    // Challenge 1: Swap three variables using pointers
    cout << "Challenge 1: Rotate three variables (a->b, b->c, c->a)" << endl;
    int a = 10, b = 20, c = 30;
    cout << "  Before: a=" << a << ", b=" << b << ", c=" << c << endl;
    
    // Solution using pointers
    int* pa = &a, *pb = &b, *pc = &c;
    int temp = *pa;
    *pa = *pc;
    *pc = *pb;
    *pb = temp;
    
    cout << "  After rotation: a=" << a << ", b=" << b << ", c=" << c << endl << endl;
    
    // Challenge 2: Find min and max using single function
    cout << "Challenge 2: Find min and max in array using pointers" << endl;
    int arr[] = {45, 23, 78, 12, 67, 89, 34};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    auto findMinMax = [](int* arr, int size, int** min, int** max) {
        if (!arr || size <= 0) return;
        
        *min = *max = arr;
        for (int i = 1; i < size; i++) {
            if (arr[i] < **min) *min = &arr[i];
            if (arr[i] > **max) *max = &arr[i];
        }
    };
    
    int* minPtr, *maxPtr;
    findMinMax(arr, size, &minPtr, &maxPtr);
    
    cout << "  Array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
    cout << "  Min: " << *minPtr << " at index " << (minPtr - arr) << endl;
    cout << "  Max: " << *maxPtr << " at index " << (maxPtr - arr) << endl;
    cout << endl;
}

/**
 * @brief Exercise 2: Dynamic array operations
 */
void exercise2_DynamicArrayOperations() {
    cout << "EXERCISE 2: DYNAMIC ARRAY OPERATIONS" << endl;
    cout << "=====================================" << endl;
    
    // Challenge: Implement resizable array
    cout << "Challenge: Implement a resizable dynamic array" << endl;
    
    class DynamicArray {
    private:
        int* data;
        size_t size;
        size_t capacity;
        
    public:
        DynamicArray() : data(nullptr), size(0), capacity(0) {}
        
        ~DynamicArray() {
            delete[] data;
        }
        
        void push_back(int value) {
            if (size >= capacity) {
                resize(capacity == 0 ? 1 : capacity * 2);
            }
            data[size++] = value;
        }
        
        void resize(size_t newCapacity) {
            int* newData = new int[newCapacity];
            for (size_t i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
            cout << "    Resized to capacity " << capacity << endl;
        }
        
        void display() const {
            cout << "    Array (" << size << "/" << capacity << "): ";
            for (size_t i = 0; i < size; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
        
        int& operator[](size_t index) {
            return data[index];
        }
        
        size_t getSize() const { return size; }
    };
    
    DynamicArray dynArr;
    
    cout << "  Adding elements to dynamic array:" << endl;
    for (int i = 1; i <= 10; i++) {
        dynArr.push_back(i * i);
        if (i % 3 == 0) dynArr.display();
    }
    
    dynArr.display();
    cout << endl;
}

/**
 * @brief Exercise 3: Linked list implementation
 */
void exercise3_LinkedListImplementation() {
    cout << "EXERCISE 3: LINKED LIST IMPLEMENTATION" << endl;
    cout << "=======================================" << endl;
    
    cout << "Challenge: Implement and manipulate a linked list" << endl;
    
    SimpleLinkedList list;
    
    // Insert elements
    cout << "  Inserting elements: 5, 3, 8, 1, 9" << endl;
    list.insert(5);
    list.insert(3);
    list.insert(8);
    list.insert(1);
    list.insert(9);
    list.display();
    
    // Remove elements
    cout << "  Removing element 8:" << endl;
    if (list.remove(8)) {
        cout << "    Successfully removed 8" << endl;
    }
    list.display();
    
    cout << "  Removing element 1:" << endl;
    if (list.remove(1)) {
        cout << "    Successfully removed 1" << endl;
    }
    list.display();
    
    cout << "  Trying to remove non-existent element 99:" << endl;
    if (!list.remove(99)) {
        cout << "    Element 99 not found" << endl;
    }
    list.display();
    
    cout << endl;
}

/**
 * @brief Exercise 4: String manipulation with pointers
 */
void exercise4_StringManipulation() {
    cout << "EXERCISE 4: STRING MANIPULATION WITH POINTERS" << endl;
    cout << "==============================================" << endl;
    
    // Challenge 1: Reverse string in-place
    cout << "Challenge 1: Reverse string in-place using pointers" << endl;
    char str1[] = "Hello World";
    cout << "  Original: " << str1 << endl;
    
    char* start = str1;
    char* end = str1 + strlen(str1) - 1;
    
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    
    cout << "  Reversed: " << str1 << endl << endl;
    
    // Challenge 2: Count words using pointers
    cout << "Challenge 2: Count words using pointers" << endl;
    const char* text = "The quick brown fox jumps over the lazy dog";
    cout << "  Text: " << text << endl;
    
    const char* ptr = text;
    int wordCount = 0;
    bool inWord = false;
    
    while (*ptr) {
        if (*ptr != ' ' && *ptr != '\t' && *ptr != '\n') {
            if (!inWord) {
                wordCount++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
        ptr++;
    }
    
    cout << "  Word count: " << wordCount << endl << endl;
    
    // Challenge 3: Find substring
    cout << "Challenge 3: Find substring using pointers" << endl;
    const char* haystack = "Programming with pointers is powerful";
    const char* needle = "pointers";
    cout << "  Text: " << haystack << endl;
    cout << "  Searching for: " << needle << endl;
    
    const char* found = strstr(haystack, needle);
    if (found) {
        cout << "  Found at position: " << (found - haystack) << endl;
    } else {
        cout << "  Not found" << endl;
    }
    cout << endl;
}

/**
 * @brief Exercise 5: Function pointer calculator
 */
void exercise5_FunctionPointerCalculator() {
    cout << "EXERCISE 5: FUNCTION POINTER CALCULATOR" << endl;
    cout << "========================================" << endl;
    
    cout << "Challenge: Build a calculator using function pointers" << endl;
    
    // Define operation functions
    auto add = [](double a, double b) -> double { return a + b; };
    auto subtract = [](double a, double b) -> double { return a - b; };
    auto multiply = [](double a, double b) -> double { return a * b; };
    auto divide = [](double a, double b) -> double { 
        return b != 0 ? a / b : 0; 
    };
    
    // Function pointer array
    double (*operations[])(double, double) = {add, subtract, multiply, divide};
    const char* opNames[] = {"+", "-", "*", "/"};
    
    double x = 15.5, y = 3.2;
    cout << "  Operands: x = " << x << ", y = " << y << endl;
    cout << "  Results:" << endl;
    
    for (int i = 0; i < 4; i++) {
        double result = operations[i](x, y);
        cout << "    " << x << " " << opNames[i] << " " << y << " = " << result << endl;
    }
    
    // Advanced: Calculator with operation selection
    cout << "\n  Interactive calculator simulation:" << endl;
    
    auto calculate = [&](int opIndex, double a, double b) -> double {
        if (opIndex >= 0 && opIndex < 4) {
            return operations[opIndex](a, b);
        }
        return 0;
    };
    
    // Simulate some calculations
    struct Calculation {
        double a, b;
        int op;
        const char* desc;
    };
    
    Calculation calcs[] = {
        {10, 5, 0, "10 + 5"},
        {20, 8, 1, "20 - 8"},
        {7, 6, 2, "7 * 6"},
        {45, 9, 3, "45 / 9"}
    };
    
    for (const auto& calc : calcs) {
        double result = calculate(calc.op, calc.a, calc.b);
        cout << "    " << calc.desc << " = " << result << endl;
    }
    
    cout << endl;
}

/**
 * @brief Exercise 6: Smart pointer data structures
 */
void exercise6_SmartPointerDataStructures() {
    cout << "EXERCISE 6: SMART POINTER DATA STRUCTURES" << endl;
    cout << "==========================================" << endl;
    
    cout << "Challenge: Implement binary tree using smart pointers" << endl;
    
    struct TreeNode {
        int data;
        shared_ptr<TreeNode> left;
        shared_ptr<TreeNode> right;
        
        TreeNode(int val) : data(val) {}
    };
    
    class BinaryTree {
    private:
        shared_ptr<TreeNode> root;
        
        void inorderHelper(shared_ptr<TreeNode> node, vector<int>& result) {
            if (node) {
                inorderHelper(node->left, result);
                result.push_back(node->data);
                inorderHelper(node->right, result);
            }
        }
        
    public:
        void insert(int value) {
            root = insertHelper(root, value);
        }
        
        shared_ptr<TreeNode> insertHelper(shared_ptr<TreeNode> node, int value) {
            if (!node) {
                return make_shared<TreeNode>(value);
            }
            
            if (value < node->data) {
                node->left = insertHelper(node->left, value);
            } else {
                node->right = insertHelper(node->right, value);
            }
            
            return node;
        }
        
        vector<int> inorderTraversal() {
            vector<int> result;
            inorderHelper(root, result);
            return result;
        }
        
        int getNodeCount() const {
            return countNodes(root);
        }
        
    private:
        int countNodes(shared_ptr<TreeNode> node) const {
            if (!node) return 0;
            return 1 + countNodes(node->left) + countNodes(node->right);
        }
    };
    
    BinaryTree tree;
    
    cout << "  Inserting values: 50, 30, 70, 20, 40, 60, 80" << endl;
    vector<int> values = {50, 30, 70, 20, 40, 60, 80};
    
    for (int val : values) {
        tree.insert(val);
    }
    
    cout << "  Tree node count: " << tree.getNodeCount() << endl;
    
    vector<int> inorder = tree.inorderTraversal();
    cout << "  Inorder traversal: ";
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;
    
    cout << "  Smart pointers automatically manage tree memory!" << endl;
    cout << endl;
}

/**
 * @brief Exercise 7: Memory pool implementation
 */
void exercise7_MemoryPoolImplementation() {
    cout << "EXERCISE 7: MEMORY POOL IMPLEMENTATION" << endl;
    cout << "=======================================" << endl;
    
    cout << "Challenge: Implement a simple memory pool allocator" << endl;
    
    class MemoryPool {
    private:
        char* pool;
        size_t poolSize;
        size_t blockSize;
        vector<void*> freeBlocks;
        
    public:
        MemoryPool(size_t totalSize, size_t blockSz) 
            : poolSize(totalSize), blockSize(blockSz) {
            pool = new char[poolSize];
            
            // Initialize free block list
            size_t numBlocks = poolSize / blockSize;
            for (size_t i = 0; i < numBlocks; i++) {
                freeBlocks.push_back(pool + i * blockSize);
            }
            
            cout << "  Created memory pool: " << poolSize << " bytes, " 
                 << numBlocks << " blocks of " << blockSize << " bytes each" << endl;
        }
        
        ~MemoryPool() {
            delete[] pool;
            cout << "  Memory pool destroyed" << endl;
        }
        
        void* allocate() {
            if (freeBlocks.empty()) {
                cout << "    Pool exhausted!" << endl;
                return nullptr;
            }
            
            void* block = freeBlocks.back();
            freeBlocks.pop_back();
            cout << "    Allocated block at offset " 
                 << ((char*)block - pool) << endl;
            return block;
        }
        
        void deallocate(void* ptr) {
            if (ptr >= pool && ptr < pool + poolSize) {
                freeBlocks.push_back(ptr);
                cout << "    Deallocated block at offset " 
                     << ((char*)ptr - pool) << endl;
            }
        }
        
        size_t getAvailableBlocks() const {
            return freeBlocks.size();
        }
    };
    
    // Test the memory pool
    MemoryPool pool(1024, 64);  // 1KB pool with 64-byte blocks
    
    cout << "  Available blocks: " << pool.getAvailableBlocks() << endl;
    
    // Allocate some blocks
    vector<void*> allocatedBlocks;
    
    cout << "  Allocating 5 blocks:" << endl;
    for (int i = 0; i < 5; i++) {
        void* block = pool.allocate();
        if (block) {
            allocatedBlocks.push_back(block);
            // Use the block (write some data)
            *static_cast<int*>(block) = i * 100;
        }
    }
    
    cout << "  Available blocks after allocation: " << pool.getAvailableBlocks() << endl;
    
    // Read back data
    cout << "  Data in allocated blocks: ";
    for (void* block : allocatedBlocks) {
        cout << *static_cast<int*>(block) << " ";
    }
    cout << endl;
    
    // Deallocate some blocks
    cout << "  Deallocating 3 blocks:" << endl;
    for (int i = 0; i < 3; i++) {
        pool.deallocate(allocatedBlocks[i]);
    }
    
    cout << "  Available blocks after deallocation: " << pool.getAvailableBlocks() << endl;
    cout << endl;
}
