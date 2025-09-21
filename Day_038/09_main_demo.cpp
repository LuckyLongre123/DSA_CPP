/**
 * @file 09_main_demo.cpp
 * @brief Complete C++ Pointers Demonstration
 * @author C++ Pointers Learning Guide
 * 
 * This file provides a comprehensive demonstration of all pointer concepts
 * covered in the learning guide. It serves as a complete showcase and
 * quick reference for all major pointer techniques.
 * 
 * Compilation: g++ -std=c++17 -Wall -Wextra -o main_demo 09_main_demo.cpp
 * Run: ./main_demo
 */

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <functional>

using namespace std;

// Demo function declarations
void demoBasicPointers();
void demoPointerArithmetic();
void demoPointersAndArrays();
void demoPointersAndFunctions();
void demoDynamicMemory();
void demoAdvancedPointers();
void demoSmartPointers();
void demoRealWorldExample();

// Helper classes and functions
class Person {
public:
    string name;
    int age;
    
    Person(const string& n, int a) : name(n), age(a) {
        cout << "    Person " << name << " created" << endl;
    }
    
    ~Person() {
        cout << "    Person " << name << " destroyed" << endl;
    }
    
    void introduce() const {
        cout << "    Hi, I'm " << name << ", age " << age << endl;
    }
};

// Simple data structure for demonstration
struct Node {
    int data;
    shared_ptr<Node> next;
    
    Node(int d) : data(d) {}
};

int main() {
    cout << "=========================================" << endl;
    cout << "  C++ POINTERS COMPLETE DEMONSTRATION   " << endl;
    cout << "=========================================" << endl;
    cout << "This demo showcases all major pointer concepts" << endl;
    cout << "covered in the comprehensive learning guide." << endl;
    cout << "=========================================" << endl << endl;
    
    // Run all demonstrations
    demoBasicPointers();
    demoPointerArithmetic();
    demoPointersAndArrays();
    demoPointersAndFunctions();
    demoDynamicMemory();
    demoAdvancedPointers();
    demoSmartPointers();
    demoRealWorldExample();
    
    cout << "=========================================" << endl;
    cout << "  DEMONSTRATION COMPLETE!" << endl;
    cout << "=========================================" << endl;
    cout << "You've seen all major C++ pointer concepts:" << endl;
    cout << "✓ Basic pointer operations" << endl;
    cout << "✓ Pointer arithmetic" << endl;
    cout << "✓ Pointers with arrays and functions" << endl;
    cout << "✓ Dynamic memory management" << endl;
    cout << "✓ Advanced pointer techniques" << endl;
    cout << "✓ Modern smart pointers" << endl;
    cout << "✓ Real-world applications" << endl;
    cout << "\nNext steps: Practice with the exercises!" << endl;
    
    return 0;
}

/**
 * @brief Demonstrates basic pointer concepts
 */
void demoBasicPointers() {
    cout << "1. BASIC POINTERS DEMO" << endl;
    cout << "======================" << endl;
    
    // Basic pointer operations
    int value = 42;
    int* ptr = &value;
    
    cout << "  Basic pointer operations:" << endl;
    cout << "    value = " << value << " at address " << &value << endl;
    cout << "    ptr = " << ptr << " (points to value)" << endl;
    cout << "    *ptr = " << *ptr << " (dereference)" << endl;
    
    // Modify through pointer
    *ptr = 100;
    cout << "    After *ptr = 100: value = " << value << endl;
    
    // Null pointer safety
    int* nullPtr = nullptr;
    cout << "    Safe null pointer check: " << (nullPtr ? "valid" : "null") << endl;
    
    cout << endl;
}

/**
 * @brief Demonstrates pointer arithmetic
 */
void demoPointerArithmetic() {
    cout << "2. POINTER ARITHMETIC DEMO" << endl;
    cout << "==========================" << endl;
    
    int numbers[] = {10, 20, 30, 40, 50};
    int* ptr = numbers;
    
    cout << "  Array traversal with pointer arithmetic:" << endl;
    cout << "    Array: ";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
    
    // Pointer increment
    cout << "    Using pointer increment:" << endl;
    ptr = numbers;
    for (int i = 0; i < 5; i++) {
        cout << "      ptr[" << i << "] = " << *ptr << endl;
        ptr++;
    }
    
    // Pointer differences
    int* start = numbers;
    int* end = numbers + 4;
    cout << "    Pointer difference: " << (end - start) << " elements" << endl;
    
    cout << endl;
}

/**
 * @brief Demonstrates pointers with arrays
 */
void demoPointersAndArrays() {
    cout << "3. POINTERS AND ARRAYS DEMO" << endl;
    cout << "============================" << endl;
    
    // Array-pointer equivalence
    double values[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double* ptr = values;
    
    cout << "  Array-pointer equivalence:" << endl;
    cout << "    values == ptr: " << (values == ptr ? "true" : "false") << endl;
    cout << "    values[2] == *(ptr + 2): " << (values[2] == *(ptr + 2) ? "true" : "false") << endl;
    
    // Dynamic array
    cout << "  Dynamic array creation:" << endl;
    int size = 4;
    int* dynArray = new int[size];
    
    for (int i = 0; i < size; i++) {
        dynArray[i] = (i + 1) * 10;
    }
    
    cout << "    Dynamic array: ";
    for (int i = 0; i < size; i++) {
        cout << dynArray[i] << " ";
    }
    cout << endl;
    
    delete[] dynArray;
    cout << "    Dynamic array cleaned up" << endl;
    
    cout << endl;
}

/**
 * @brief Demonstrates pointers with functions
 */
void demoPointersAndFunctions() {
    cout << "4. POINTERS AND FUNCTIONS DEMO" << endl;
    cout << "===============================" << endl;
    
    // Pass by pointer
    auto swap = [](int* a, int* b) {
        if (a && b) {
            int temp = *a;
            *a = *b;
            *b = temp;
        }
    };
    
    int x = 10, y = 20;
    cout << "  Before swap: x = " << x << ", y = " << y << endl;
    swap(&x, &y);
    cout << "  After swap: x = " << x << ", y = " << y << endl;
    
    // Function pointers
    auto add = [](int a, int b) { return a + b; };
    auto multiply = [](int a, int b) { return a * b; };
    
    int (*operation)(int, int) = add;
    cout << "  Function pointer (add): 5 + 3 = " << operation(5, 3) << endl;
    
    operation = multiply;
    cout << "  Function pointer (multiply): 5 * 3 = " << operation(5, 3) << endl;
    
    cout << endl;
}

/**
 * @brief Demonstrates dynamic memory management
 */
void demoDynamicMemory() {
    cout << "5. DYNAMIC MEMORY DEMO" << endl;
    cout << "======================" << endl;
    
    // Single object allocation
    cout << "  Single object allocation:" << endl;
    Person* person = new Person("Alice", 25);
    person->introduce();
    delete person;
    
    // Array allocation
    cout << "  Array allocation:" << endl;
    Person* people = new Person[2]{{"Bob", 30}, {"Carol", 28}};
    
    for (int i = 0; i < 2; i++) {
        people[i].introduce();
    }
    
    delete[] people;
    
    // RAII demonstration
    cout << "  RAII with automatic cleanup:" << endl;
    {
        class SafeResource {
            int* data;
        public:
            SafeResource(int size) : data(new int[size]) {
                cout << "    SafeResource allocated" << endl;
            }
            ~SafeResource() {
                delete[] data;
                cout << "    SafeResource cleaned up" << endl;
            }
        };
        
        SafeResource resource(100);
        // Automatic cleanup when resource goes out of scope
    }
    
    cout << endl;
}

/**
 * @brief Demonstrates advanced pointer concepts
 */
void demoAdvancedPointers() {
    cout << "6. ADVANCED POINTERS DEMO" << endl;
    cout << "=========================" << endl;
    
    // Double pointers
    cout << "  Double pointers:" << endl;
    int value = 42;
    int* ptr = &value;
    int** pptr = &ptr;
    
    cout << "    value = " << value << endl;
    cout << "    *ptr = " << *ptr << endl;
    cout << "    **pptr = " << **pptr << endl;
    
    // Const pointers
    cout << "  Const pointer variations:" << endl;
    int a = 10;
    
    const int* ptr1 = &a;        // Pointer to const
    int* const ptr2 = &a;        // Const pointer
    const int* const ptr3 = &a;  // Const pointer to const
    
    cout << "    Pointer to const: " << *ptr1 << endl;
    cout << "    Const pointer: " << *ptr2 << endl;
    cout << "    Const pointer to const: " << *ptr3 << endl;
    
    // Void pointers
    cout << "  Void pointer type erasure:" << endl;
    void* vptr = &value;
    cout << "    Void pointer to int: " << *(int*)vptr << endl;
    
    float f = 3.14f;
    vptr = &f;
    cout << "    Void pointer to float: " << *(float*)vptr << endl;
    
    cout << endl;
}

/**
 * @brief Demonstrates smart pointers
 */
void demoSmartPointers() {
    cout << "7. SMART POINTERS DEMO" << endl;
    cout << "======================" << endl;
    
    // unique_ptr
    cout << "  unique_ptr (exclusive ownership):" << endl;
    {
        unique_ptr<Person> uniquePerson = make_unique<Person>("David", 35);
        uniquePerson->introduce();
        
        // Transfer ownership
        unique_ptr<Person> anotherPtr = move(uniquePerson);
        cout << "    After move, original ptr is: " << (uniquePerson ? "valid" : "null") << endl;
        
    }  // Automatic cleanup
    
    // shared_ptr
    cout << "  shared_ptr (shared ownership):" << endl;
    {
        shared_ptr<Person> sharedPerson = make_shared<Person>("Eve", 32);
        cout << "    Reference count: " << sharedPerson.use_count() << endl;
        
        {
            shared_ptr<Person> anotherRef = sharedPerson;
            cout << "    After sharing, count: " << sharedPerson.use_count() << endl;
        }
        
        cout << "    After scope exit, count: " << sharedPerson.use_count() << endl;
    }  // Automatic cleanup when last reference is destroyed
    
    // weak_ptr
    cout << "  weak_ptr (breaking cycles):" << endl;
    {
        auto node1 = make_shared<Node>(1);
        auto node2 = make_shared<Node>(2);
        
        node1->next = node2;
        // If we had node2->prev = node1 as shared_ptr, it would create a cycle
        // weak_ptr prevents this issue
        
        cout << "    Created linked structure without cycles" << endl;
    }  // Proper cleanup
    
    cout << endl;
}

/**
 * @brief Demonstrates real-world pointer usage
 */
void demoRealWorldExample() {
    cout << "8. REAL-WORLD EXAMPLE" << endl;
    cout << "=====================" << endl;
    
    cout << "  Building a simple task management system:" << endl;
    
    // Task class
    class Task {
    public:
        string description;
        bool completed;
        
        Task(const string& desc) : description(desc), completed(false) {}
        
        void complete() {
            completed = true;
            cout << "    ✓ Completed: " << description << endl;
        }
        
        void display() const {
            cout << "    " << (completed ? "✓" : "○") << " " << description << endl;
        }
    };
    
    // Task manager using smart pointers
    class TaskManager {
    private:
        vector<shared_ptr<Task>> tasks;
        
    public:
        void addTask(const string& description) {
            tasks.push_back(make_shared<Task>(description));
            cout << "    Added task: " << description << endl;
        }
        
        void completeTask(size_t index) {
            if (index < tasks.size()) {
                tasks[index]->complete();
            }
        }
        
        void displayTasks() const {
            cout << "    Current tasks:" << endl;
            for (const auto& task : tasks) {
                task->display();
            }
        }
        
        void removeCompletedTasks() {
            auto it = remove_if(tasks.begin(), tasks.end(),
                [](const shared_ptr<Task>& task) {
                    return task->completed;
                });
            tasks.erase(it, tasks.end());
            cout << "    Removed completed tasks" << endl;
        }
    };
    
    // Demonstrate the system
    TaskManager manager;
    
    manager.addTask("Learn C++ pointers");
    manager.addTask("Practice pointer arithmetic");
    manager.addTask("Implement data structures");
    manager.addTask("Master smart pointers");
    
    manager.displayTasks();
    
    cout << "  Completing some tasks:" << endl;
    manager.completeTask(0);  // Learn C++ pointers
    manager.completeTask(3);  // Master smart pointers
    
    manager.displayTasks();
    
    cout << "  Cleaning up completed tasks:" << endl;
    manager.removeCompletedTasks();
    
    manager.displayTasks();
    
    cout << "  All memory automatically managed by smart pointers!" << endl;
    cout << endl;
}
