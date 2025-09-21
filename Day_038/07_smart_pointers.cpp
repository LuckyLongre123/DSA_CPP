/**
 * @file 07_smart_pointers.cpp
 * @brief Smart Pointers (Modern C++) - Advanced Level
 * @author C++ Pointers Learning Guide
 * 
 * This file demonstrates modern C++ smart pointers:
 * - unique_ptr for exclusive ownership
 * - shared_ptr for shared ownership
 * - weak_ptr for breaking circular references
 * - Custom deleters and allocators
 * - Best practices and performance considerations
 * 
 * Compilation: g++ -std=c++17 -Wall -Wextra -o smart_pointers 07_smart_pointers.cpp
 * Run: ./smart_pointers
 */

#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

// Function declarations
void demonstrateUniquePtr();
void demonstrateSharedPtr();
void demonstrateWeakPtr();
void demonstrateCustomDeleters();
void demonstrateSmartPtrPerformance();
void demonstrateSmartPtrBestPractices();
void demonstrateSmartPtrWithContainers();

// Helper classes for demonstrations
class Resource {
private:
    string name;
    static int count;

public:
    Resource(const string& n) : name(n) {
        count++;
        cout << "    Resource '" << name << "' created (total: " << count << ")" << endl;
    }
    
    ~Resource() {
        count--;
        cout << "    Resource '" << name << "' destroyed (remaining: " << count << ")" << endl;
    }
    
    void use() const {
        cout << "    Using resource '" << name << "'" << endl;
    }
    
    const string& getName() const { return name; }
    static int getCount() { return count; }
};

int Resource::count = 0;

// Node class for circular reference demonstration
class Node {
public:
    int data;
    shared_ptr<Node> next;
    weak_ptr<Node> parent;  // Use weak_ptr to break cycles
    
    Node(int d) : data(d) {
        cout << "    Node " << data << " created" << endl;
    }
    
    ~Node() {
        cout << "    Node " << data << " destroyed" << endl;
    }
};

int main() {
    cout << "=== C++ Smart Pointers Demonstration ===" << endl;
    cout << "=========================================" << endl << endl;
    
    demonstrateUniquePtr();
    demonstrateSharedPtr();
    demonstrateWeakPtr();
    demonstrateCustomDeleters();
    demonstrateSmartPtrPerformance();
    demonstrateSmartPtrBestPractices();
    demonstrateSmartPtrWithContainers();
    
    cout << "\n=== End of Smart Pointers Demo ===" << endl;
    return 0;
}

/**
 * @brief Demonstrates unique_ptr for exclusive ownership
 */
void demonstrateUniquePtr() {
    cout << "1. UNIQUE_PTR - EXCLUSIVE OWNERSHIP" << endl;
    cout << "====================================" << endl;
    
    // Basic unique_ptr usage
    cout << "Basic unique_ptr creation and usage:" << endl;
    {
        unique_ptr<Resource> ptr = make_unique<Resource>("UniqueResource1");
        ptr->use();
        
        // Automatic cleanup when ptr goes out of scope
    }
    cout << "  unique_ptr automatically cleaned up" << endl << endl;
    
    // Transfer ownership with move
    cout << "Transfer ownership with move:" << endl;
    unique_ptr<Resource> ptr1 = make_unique<Resource>("MovableResource");
    cout << "  ptr1 owns: " << (ptr1 ? ptr1->getName() : "nothing") << endl;
    
    unique_ptr<Resource> ptr2 = move(ptr1);
    cout << "  After move:" << endl;
    cout << "    ptr1 owns: " << (ptr1 ? ptr1->getName() : "nothing") << endl;
    cout << "    ptr2 owns: " << (ptr2 ? ptr2->getName() : "nothing") << endl;
    cout << endl;
    
    // unique_ptr with arrays
    cout << "unique_ptr with arrays:" << endl;
    {
        unique_ptr<int[]> arrayPtr = make_unique<int[]>(5);
        
        for (int i = 0; i < 5; i++) {
            arrayPtr[i] = i * i;
        }
        
        cout << "  Array contents: ";
        for (int i = 0; i < 5; i++) {
            cout << arrayPtr[i] << " ";
        }
        cout << endl;
        
        // Automatic cleanup with delete[]
    }
    cout << "  Array automatically cleaned up" << endl << endl;
    
    // Release and reset
    cout << "Release and reset operations:" << endl;
    unique_ptr<Resource> ptr3 = make_unique<Resource>("ReleasableResource");
    
    Resource* rawPtr = ptr3.release();  // Transfer ownership to raw pointer
    cout << "  After release, ptr3 owns: " << (ptr3 ? "something" : "nothing") << endl;
    cout << "  Raw pointer points to: " << rawPtr->getName() << endl;
    
    ptr3.reset(rawPtr);  // Take ownership back
    cout << "  After reset, ptr3 owns: " << ptr3->getName() << endl;
    
    ptr3.reset();  // Release and delete
    cout << "  After reset(), resource should be destroyed" << endl;
    cout << endl;
}

/**
 * @brief Demonstrates shared_ptr for shared ownership
 */
void demonstrateSharedPtr() {
    cout << "2. SHARED_PTR - SHARED OWNERSHIP" << endl;
    cout << "=================================" << endl;
    
    // Basic shared_ptr usage
    cout << "Basic shared_ptr creation and sharing:" << endl;
    {
        shared_ptr<Resource> ptr1 = make_shared<Resource>("SharedResource");
        cout << "  ptr1 reference count: " << ptr1.use_count() << endl;
        
        {
            shared_ptr<Resource> ptr2 = ptr1;  // Share ownership
            cout << "  After sharing:" << endl;
            cout << "    ptr1 reference count: " << ptr1.use_count() << endl;
            cout << "    ptr2 reference count: " << ptr2.use_count() << endl;
            
            ptr1->use();
            ptr2->use();
            
        }  // ptr2 goes out of scope
        
        cout << "  After ptr2 destroyed:" << endl;
        cout << "    ptr1 reference count: " << ptr1.use_count() << endl;
        
    }  // ptr1 goes out of scope, resource destroyed
    cout << "  Resource automatically destroyed when last shared_ptr is destroyed" << endl << endl;
    
    // Multiple shared_ptr instances
    cout << "Multiple shared_ptr instances:" << endl;
    shared_ptr<Resource> mainPtr = make_shared<Resource>("MultiSharedResource");
    vector<shared_ptr<Resource>> ptrs;
    
    // Create multiple references
    for (int i = 0; i < 3; i++) {
        ptrs.push_back(mainPtr);
        cout << "  Added reference " << i + 1 << ", count: " << mainPtr.use_count() << endl;
    }
    
    // Remove references
    ptrs.clear();
    cout << "  After clearing vector, count: " << mainPtr.use_count() << endl;
    
    mainPtr.reset();
    cout << "  After resetting mainPtr, resource should be destroyed" << endl;
    cout << endl;
    
    // Aliasing constructor
    cout << "Aliasing constructor:" << endl;
    struct Container {
        int value1 = 10;
        int value2 = 20;
    };
    
    shared_ptr<Container> containerPtr = make_shared<Container>();
    shared_ptr<int> valuePtr(containerPtr, &containerPtr->value1);  // Alias to member
    
    cout << "  Container reference count: " << containerPtr.use_count() << endl;
    cout << "  Value through alias: " << *valuePtr << endl;
    
    containerPtr.reset();  // Container still alive because of alias
    cout << "  After container reset, value still accessible: " << *valuePtr << endl;
    
    valuePtr.reset();  // Now container is destroyed
    cout << "  Container destroyed when alias is reset" << endl;
    cout << endl;
}

/**
 * @brief Demonstrates weak_ptr for breaking circular references
 */
void demonstrateWeakPtr() {
    cout << "3. WEAK_PTR - BREAKING CIRCULAR REFERENCES" << endl;
    cout << "===========================================" << endl;
    
    // Basic weak_ptr usage
    cout << "Basic weak_ptr usage:" << endl;
    {
        shared_ptr<Resource> sharedPtr = make_shared<Resource>("WeakResource");
        weak_ptr<Resource> weakPtr = sharedPtr;
        
        cout << "  shared_ptr count: " << sharedPtr.use_count() << endl;
        cout << "  weak_ptr expired: " << (weakPtr.expired() ? "yes" : "no") << endl;
        
        // Convert weak_ptr to shared_ptr
        if (auto lockedPtr = weakPtr.lock()) {
            cout << "  Successfully locked weak_ptr: " << lockedPtr->getName() << endl;
            cout << "  Reference count after lock: " << sharedPtr.use_count() << endl;
        }
        
    }  // shared_ptr destroyed
    
    // Check if weak_ptr is expired
    cout << "  After shared_ptr destroyed:" << endl;
    // weakPtr is now expired (can't access this after scope)
    cout << endl;
    
    // Circular reference problem and solution
    cout << "Circular reference demonstration:" << endl;
    {
        auto node1 = make_shared<Node>(1);
        auto node2 = make_shared<Node>(2);
        auto node3 = make_shared<Node>(3);
        
        // Create circular structure
        node1->next = node2;
        node2->next = node3;
        node3->next = node1;  // This would create a cycle with shared_ptr
        
        // Use weak_ptr for parent relationships to break cycles
        node2->parent = node1;
        node3->parent = node2;
        
        cout << "  Created circular structure with weak_ptr parents" << endl;
        cout << "  node1 reference count: " << node1.use_count() << endl;
        cout << "  node2 reference count: " << node2.use_count() << endl;
        cout << "  node3 reference count: " << node3.use_count() << endl;
        
        // Access parent through weak_ptr
        if (auto parent = node2->parent.lock()) {
            cout << "  node2's parent is node " << parent->data << endl;
        }
        
    }  // All nodes should be properly destroyed
    cout << "  All nodes destroyed (no memory leak)" << endl;
    cout << endl;
    
    // Observer pattern with weak_ptr
    cout << "Observer pattern with weak_ptr:" << endl;
    
    class Subject {
        vector<weak_ptr<Resource>> observers;
    public:
        void addObserver(shared_ptr<Resource> observer) {
            observers.push_back(observer);
            cout << "    Added observer: " << observer->getName() << endl;
        }
        
        void notify() {
            cout << "    Notifying observers:" << endl;
            auto it = observers.begin();
            while (it != observers.end()) {
                if (auto observer = it->lock()) {
                    observer->use();
                    ++it;
                } else {
                    cout << "    Removing expired observer" << endl;
                    it = observers.erase(it);
                }
            }
        }
    };
    
    Subject subject;
    {
        auto observer1 = make_shared<Resource>("Observer1");
        auto observer2 = make_shared<Resource>("Observer2");
        
        subject.addObserver(observer1);
        subject.addObserver(observer2);
        
        subject.notify();
        
    }  // Observers destroyed
    
    cout << "  After observers destroyed:" << endl;
    subject.notify();  // Should clean up expired weak_ptrs
    cout << endl;
}

/**
 * @brief Demonstrates custom deleters and allocators
 */
void demonstrateCustomDeleters() {
    cout << "4. CUSTOM DELETERS AND ALLOCATORS" << endl;
    cout << "==================================" << endl;
    
    // Custom deleter for unique_ptr
    cout << "Custom deleter for unique_ptr:" << endl;
    {
        auto customDeleter = [](Resource* ptr) {
            cout << "    Custom deleter called for " << ptr->getName() << endl;
            delete ptr;
        };
        
        unique_ptr<Resource, decltype(customDeleter)> ptr(
            new Resource("CustomDeletedResource"), customDeleter);
        
        ptr->use();
    }  // Custom deleter called automatically
    cout << endl;
    
    // Custom deleter for shared_ptr
    cout << "Custom deleter for shared_ptr:" << endl;
    {
        auto arrayDeleter = [](int* ptr) {
            cout << "    Custom array deleter called" << endl;
            delete[] ptr;
        };
        
        shared_ptr<int> arrayPtr(new int[5], arrayDeleter);
        
        for (int i = 0; i < 5; i++) {
            arrayPtr.get()[i] = i * 2;
        }
        
        cout << "    Array contents: ";
        for (int i = 0; i < 5; i++) {
            cout << arrayPtr.get()[i] << " ";
        }
        cout << endl;
        
    }  // Custom deleter called
    cout << endl;
    
    // File handle with custom deleter
    cout << "File handle with custom deleter:" << endl;
    {
        auto fileDeleter = [](FILE* file) {
            if (file) {
                cout << "    Closing file handle" << endl;
                fclose(file);
            }
        };
        
        // Note: This is just for demonstration - use std::fstream in real code
        unique_ptr<FILE, decltype(fileDeleter)> filePtr(nullptr, fileDeleter);
        
        // Simulate file operations
        cout << "    File operations would happen here" << endl;
        
    }  // File automatically closed
    cout << endl;
    
    // Custom allocator simulation
    cout << "Custom allocator simulation:" << endl;
    {
        auto customAllocator = [](size_t size) -> void* {
            cout << "    Custom allocator: allocating " << size << " bytes" << endl;
            return malloc(size);
        };
        
        auto customDeallocator = [](void* ptr) {
            cout << "    Custom deallocator called" << endl;
            free(ptr);
        };
        
        // Simulate custom allocation
        void* memory = customAllocator(sizeof(Resource));
        Resource* resource = new(memory) Resource("CustomAllocatedResource");
        
        resource->use();
        
        // Manual cleanup for placement new
        resource->~Resource();
        customDeallocator(memory);
    }
    cout << endl;
}

/**
 * @brief Demonstrates performance considerations
 */
void demonstrateSmartPtrPerformance() {
    cout << "5. SMART POINTER PERFORMANCE CONSIDERATIONS" << endl;
    cout << "============================================" << endl;
    
    cout << "Memory overhead comparison:" << endl;
    cout << "  Raw pointer size: " << sizeof(Resource*) << " bytes" << endl;
    cout << "  unique_ptr size: " << sizeof(unique_ptr<Resource>) << " bytes" << endl;
    cout << "  shared_ptr size: " << sizeof(shared_ptr<Resource>) << " bytes" << endl;
    cout << "  weak_ptr size: " << sizeof(weak_ptr<Resource>) << " bytes" << endl << endl;
    
    // make_shared vs shared_ptr constructor
    cout << "make_shared vs shared_ptr constructor:" << endl;
    cout << "  make_shared<T>() - Single allocation (object + control block)" << endl;
    cout << "  shared_ptr<T>(new T()) - Two allocations (object, then control block)" << endl;
    cout << "  Recommendation: Always use make_shared when possible" << endl << endl;
    
    // Reference counting overhead
    cout << "Reference counting considerations:" << endl;
    {
        shared_ptr<Resource> original = make_shared<Resource>("PerformanceTest");
        
        cout << "  Creating copies (reference counting overhead):" << endl;
        vector<shared_ptr<Resource>> copies;
        
        for (int i = 0; i < 5; i++) {
            copies.push_back(original);  // Atomic increment
            cout << "    Copy " << i + 1 << " created, ref count: " << original.use_count() << endl;
        }
        
        copies.clear();  // Atomic decrements
        cout << "    After clearing copies, ref count: " << original.use_count() << endl;
    }
    cout << endl;
    
    // Move semantics with smart pointers
    cout << "Move semantics optimization:" << endl;
    {
        auto createResource = []() -> unique_ptr<Resource> {
            return make_unique<Resource>("MovedResource");
        };
        
        cout << "  Creating and moving unique_ptr (no copy overhead):" << endl;
        unique_ptr<Resource> moved = createResource();  // Move, not copy
        moved->use();
    }
    cout << endl;
}

/**
 * @brief Demonstrates smart pointer best practices
 */
void demonstrateSmartPtrBestPractices() {
    cout << "6. SMART POINTER BEST PRACTICES" << endl;
    cout << "================================" << endl;
    
    cout << "Best Practice 1: Prefer make_unique and make_shared" << endl;
    {
        // GOOD
        auto good = make_unique<Resource>("GoodPractice");
        
        // AVOID (exception safety issues)
        // processFunction(shared_ptr<Resource>(new Resource("Bad")), riskyFunction());
        
        cout << "  Always use make_unique/make_shared for exception safety" << endl;
    }
    cout << endl;
    
    cout << "Best Practice 2: Use unique_ptr by default" << endl;
    {
        // Start with unique_ptr
        unique_ptr<Resource> resource = make_unique<Resource>("DefaultUnique");
        
        // Convert to shared_ptr only when sharing is needed
        shared_ptr<Resource> shared = move(resource);  // Efficient conversion
        
        cout << "  Start with unique_ptr, convert to shared_ptr when needed" << endl;
        cout << "  shared_ptr reference count: " << shared.use_count() << endl;
    }
    cout << endl;
    
    cout << "Best Practice 3: Avoid circular references" << endl;
    {
        // Use weak_ptr to break cycles
        auto parent = make_shared<Node>(1);
        auto child = make_shared<Node>(2);
        
        parent->next = child;        // shared_ptr (ownership)
        child->parent = parent;      // weak_ptr (observation)
        
        cout << "  Used weak_ptr for parent reference to avoid cycles" << endl;
        cout << "  Parent ref count: " << parent.use_count() << endl;
    }
    cout << endl;
    
    cout << "Best Practice 4: Pass smart pointers correctly" << endl;
    
    // Function parameter guidelines
    auto useResource = [](const Resource& r) {  // Pass by reference when not transferring ownership
        r.use();
    };
    
    // Example function signatures for best practices
    cout << "  Function parameter best practices:" << endl;
    cout << "    - Pass by reference when not transferring ownership" << endl;
    cout << "    - Pass by value to transfer/share ownership" << endl;
    cout << "    - Use const& for read-only access" << endl;
    
    {
        auto resource = make_unique<Resource>("ParameterResource");
        
        useResource(*resource);  // No ownership transfer
        cout << "  Passed by reference - no ownership change" << endl;
        
        // resource = takeOwnership(move(resource));  // Transfer ownership
        // cout << "  Transferred ownership through function" << endl;
    }
    cout << endl;
    
    cout << "Best Practice 5: Reset and release properly" << endl;
    {
        unique_ptr<Resource> ptr = make_unique<Resource>("ResetResource");
        
        // Reset with new resource
        ptr.reset(new Resource("NewResource"));
        cout << "  Reset with new resource (old one destroyed)" << endl;
        
        // Release ownership
        Resource* raw = ptr.release();
        cout << "  Released ownership to raw pointer" << endl;
        
        // Take ownership back
        ptr.reset(raw);
        cout << "  Took ownership back" << endl;
    }
    cout << endl;
}

/**
 * @brief Demonstrates smart pointers with containers
 */
void demonstrateSmartPtrWithContainers() {
    cout << "7. SMART POINTERS WITH CONTAINERS" << endl;
    cout << "==================================" << endl;
    
    // Vector of unique_ptrs
    cout << "Vector of unique_ptrs:" << endl;
    {
        vector<unique_ptr<Resource>> resources;
        
        for (int i = 0; i < 3; i++) {
            resources.push_back(make_unique<Resource>("VectorResource" + to_string(i)));
        }
        
        cout << "  Created vector with " << resources.size() << " unique_ptrs" << endl;
        
        // Use resources
        for (const auto& resource : resources) {
            resource->use();
        }
        
        // Move from vector
        unique_ptr<Resource> moved = move(resources[0]);
        resources[0] = nullptr;  // Now empty
        
        cout << "  Moved resource from vector: " << moved->getName() << endl;
        
    }  // All resources automatically cleaned up
    cout << "  Vector destroyed, all resources cleaned up" << endl << endl;
    
    // Vector of shared_ptrs
    cout << "Vector of shared_ptrs:" << endl;
    {
        vector<shared_ptr<Resource>> sharedResources;
        shared_ptr<Resource> original = make_shared<Resource>("SharedVectorResource");
        
        // Add multiple references to same resource
        for (int i = 0; i < 3; i++) {
            sharedResources.push_back(original);
        }
        
        cout << "  Reference count after adding to vector: " << original.use_count() << endl;
        
        // Remove some references
        sharedResources.pop_back();
        cout << "  Reference count after pop_back: " << original.use_count() << endl;
        
        sharedResources.clear();
        cout << "  Reference count after clear: " << original.use_count() << endl;
        
    }  // original goes out of scope, resource destroyed
    cout << "  Resource destroyed when last reference removed" << endl << endl;
    
    // Polymorphic containers
    cout << "Polymorphic containers with smart pointers:" << endl;
    
    class Base {
    public:
        virtual ~Base() { cout << "    Base destructor" << endl; }
        virtual void action() const = 0;
    };
    
    class Derived1 : public Base {
    public:
        ~Derived1() override { cout << "    Derived1 destructor" << endl; }
        void action() const override { cout << "    Derived1 action" << endl; }
    };
    
    class Derived2 : public Base {
    public:
        ~Derived2() override { cout << "    Derived2 destructor" << endl; }
        void action() const override { cout << "    Derived2 action" << endl; }
    };
    
    {
        vector<unique_ptr<Base>> polymorphicContainer;
        
        polymorphicContainer.push_back(make_unique<Derived1>());
        polymorphicContainer.push_back(make_unique<Derived2>());
        polymorphicContainer.push_back(make_unique<Derived1>());
        
        cout << "  Polymorphic container with " << polymorphicContainer.size() << " objects:" << endl;
        
        for (const auto& obj : polymorphicContainer) {
            obj->action();
        }
        
    }  // Proper virtual destruction
    cout << "  All polymorphic objects properly destroyed" << endl;
    cout << endl;
}
