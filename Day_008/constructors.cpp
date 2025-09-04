/*
 * Day 8: Constructors and Destructors in C++
 * This file demonstrates different types of constructors and destructors
 * Essential for proper object initialization and cleanup
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * SECTION 1: Class with Multiple Constructor Types
 */

class Car {
private:
    string brand;
    string model;
    int year;
    double price;
    static int totalCars; // Static member to count total cars
    
public:
    // Default constructor
    Car() {
        cout << "Default constructor called" << endl;
        brand = "Unknown";
        model = "Unknown";
        year = 2000;
        price = 0.0;
        totalCars++;
    }
    
    // Parameterized constructor
    Car(string b, string m, int y, double p) {
        cout << "Parameterized constructor called" << endl;
        brand = b;
        model = m;
        year = y;
        price = p;
        totalCars++;
    }
    
    // Constructor with partial parameters
    Car(string b, string m) {
        cout << "Partial constructor called" << endl;
        brand = b;
        model = m;
        year = 2020;
        price = 25000.0;
        totalCars++;
    }
    
    // Copy constructor
    Car(const Car& other) {
        cout << "Copy constructor called" << endl;
        brand = other.brand;
        model = other.model;
        year = other.year;
        price = other.price;
        totalCars++;
    }
    
    // Destructor
    ~Car() {
        cout << "Destructor called for " << brand << " " << model << endl;
        totalCars--;
    }
    
    // Getter methods
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    
    // Static method to get total cars
    static int getTotalCars() { return totalCars; }
    
    // Display method
    void displayInfo() const {
        cout << year << " " << brand << " " << model << " - $" << price << endl;
    }
    
    // Method to calculate age
    int getAge() const {
        return 2024 - year;
    }
};

// Initialize static member
int Car::totalCars = 0;

/*
 * SECTION 2: Class with Constructor Initialization List
 */

class Person {
private:
    const string name;     // const member must be initialized in constructor
    int age;
    string address;
    
public:
    // Constructor with initialization list
    Person(string n, int a, string addr) : name(n), age(a), address(addr) {
        cout << "Person constructor called for " << name << endl;
    }
    
    // Destructor
    ~Person() {
        cout << "Person destructor called for " << name << endl;
    }
    
    // Getter methods
    string getName() const { return name; }
    int getAge() const { return age; }
    string getAddress() const { return address; }
    
    // Display method
    void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age << ", Address: " << address << endl;
    }
};

/*
 * SECTION 3: Class with Dynamic Memory Management
 */

class DynamicArray {
private:
    int* data;
    int size;
    
public:
    // Constructor
    DynamicArray(int s) {
        cout << "DynamicArray constructor called for size " << s << endl;
        size = s;
        data = new int[size];
        
        // Initialize with default values
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }
    
    // Copy constructor (important for dynamic memory)
    DynamicArray(const DynamicArray& other) {
        cout << "DynamicArray copy constructor called" << endl;
        size = other.size;
        data = new int[size];
        
        // Copy data
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    
    // Destructor (crucial for memory cleanup)
    ~DynamicArray() {
        cout << "DynamicArray destructor called, freeing memory" << endl;
        delete[] data;
    }
    
    // Methods to manipulate array
    void setValue(int index, int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }
    
    int getValue(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        return -1; // Error value
    }
    
    int getSize() const { return size; }
    
    void display() const {
        cout << "Array contents: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Constructors and Destructors Demo ===" << endl;
    
    /*
     * SECTION 4: Different Constructor Usage
     */
    
    cout << "\n=== Different Constructor Types ===" << endl;
    
    // Default constructor
    Car car1;
    car1.displayInfo();
    
    // Parameterized constructor
    Car car2("Toyota", "Camry", 2022, 28000.0);
    car2.displayInfo();
    
    // Partial constructor
    Car car3("Honda", "Civic");
    car3.displayInfo();
    
    cout << "Total cars created: " << Car::getTotalCars() << endl;
    
    /*
     * SECTION 5: Copy Constructor Demo
     */
    
    cout << "\n=== Copy Constructor Demo ===" << endl;
    
    Car originalCar("BMW", "X5", 2023, 55000.0);
    cout << "Original car:" << endl;
    originalCar.displayInfo();
    
    // Copy constructor called
    Car copiedCar = originalCar;
    cout << "Copied car:" << endl;
    copiedCar.displayInfo();
    
    cout << "Total cars after copying: " << Car::getTotalCars() << endl;
    
    /*
     * SECTION 6: Constructor Initialization List
     */
    
    cout << "\n=== Constructor Initialization List ===" << endl;
    
    Person person1("Alice Johnson", 25, "123 Main St");
    person1.displayInfo();
    
    Person person2("Bob Smith", 30, "456 Oak Ave");
    person2.displayInfo();
    
    /*
     * SECTION 7: Dynamic Memory Management
     */
    
    cout << "\n=== Dynamic Memory Management ===" << endl;
    
    {
        DynamicArray arr1(5);
        
        // Fill array with values
        for (int i = 0; i < arr1.getSize(); i++) {
            arr1.setValue(i, (i + 1) * 10);
        }
        
        arr1.display();
        
        // Copy constructor demonstration
        DynamicArray arr2 = arr1;
        cout << "Copied array:" << endl;
        arr2.display();
        
        // Modify original to show they're independent
        arr1.setValue(0, 999);
        cout << "After modifying original:" << endl;
        cout << "Original: ";
        arr1.display();
        cout << "Copy: ";
        arr2.display();
        
    } // Destructors called here when objects go out of scope
    
    cout << "Dynamic arrays destroyed" << endl;
    
    /*
     * SECTION 8: Object Lifecycle Demonstration
     */
    
    cout << "\n=== Object Lifecycle Demo ===" << endl;
    
    cout << "Creating vector of cars..." << endl;
    vector<Car> garage;
    
    // Add cars to vector (copy constructor called)
    garage.push_back(Car("Ford", "Mustang", 2021, 35000.0));
    garage.push_back(Car("Chevrolet", "Corvette", 2023, 65000.0));
    
    cout << "Cars in garage:" << endl;
    for (size_t i = 0; i < garage.size(); i++) {
        cout << (i + 1) << ". ";
        garage[i].displayInfo();
    }
    
    cout << "Total cars in system: " << Car::getTotalCars() << endl;
    
    /*
     * SECTION 9: Constructor with Validation
     */
    
    cout << "\n=== Constructor with Validation ===" << endl;
    
    class ValidatedCar {
    private:
        string brand;
        int year;
        double price;
        
    public:
        ValidatedCar(string b, int y, double p) {
            cout << "ValidatedCar constructor called" << endl;
            
            // Validate and set brand
            if (!b.empty()) {
                brand = b;
            } else {
                brand = "Unknown";
                cout << "Warning: Empty brand name, set to 'Unknown'" << endl;
            }
            
            // Validate and set year
            if (y >= 1900 && y <= 2024) {
                year = y;
            } else {
                year = 2020;
                cout << "Warning: Invalid year, set to 2020" << endl;
            }
            
            // Validate and set price
            if (p >= 0) {
                price = p;
            } else {
                price = 0.0;
                cout << "Warning: Negative price, set to 0" << endl;
            }
        }
        
        void displayInfo() const {
            cout << year << " " << brand << " - $" << price << endl;
        }
    };
    
    // Test validation
    ValidatedCar validCar("Tesla", 2023, 45000.0);
    ValidatedCar invalidCar("", 2030, -5000.0);
    
    cout << "Valid car: ";
    validCar.displayInfo();
    cout << "Invalid car (corrected): ";
    invalidCar.displayInfo();
    
    /*
     * SECTION 10: Destructor Order Demonstration
     */
    
    cout << "\n=== Destructor Order Demo ===" << endl;
    
    {
        cout << "Creating objects in local scope..." << endl;
        Car localCar1("Audi", "A4", 2022, 40000.0);
        Car localCar2("Mercedes", "C-Class", 2023, 45000.0);
        Car localCar3("Lexus", "ES", 2021, 38000.0);
        
        cout << "Objects created, about to leave scope..." << endl;
    } // Destructors called in reverse order of construction
    
    cout << "Left local scope, destructors completed" << endl;
    cout << "Remaining cars in system: " << Car::getTotalCars() << endl;
    
    cout << "\n=== Constructors and Destructors Complete! ===" << endl;
    
    return 0;
} // All remaining objects destroyed here

/*
 * CONSTRUCTOR AND DESTRUCTOR KEY CONCEPTS:
 * 
 * 1. CONSTRUCTOR TYPES:
 *    - Default: ClassName()
 *    - Parameterized: ClassName(params)
 *    - Copy: ClassName(const ClassName& other)
 *    - Move: ClassName(ClassName&& other) [C++11]
 * 
 * 2. CONSTRUCTOR FEATURES:
 *    - Same name as class
 *    - No return type
 *    - Called automatically when object created
 *    - Can be overloaded
 *    - Initialization list: ClassName(params) : member1(value1), member2(value2) {}
 * 
 * 3. DESTRUCTOR:
 *    - ~ClassName()
 *    - Called when object is destroyed
 *    - No parameters, no return type
 *    - Cannot be overloaded
 *    - Used for cleanup (free memory, close files, etc.)
 * 
 * 4. OBJECT LIFECYCLE:
 *    - Construction: Constructor called
 *    - Usage: Object methods called
 *    - Destruction: Destructor called
 * 
 * 5. COPY CONSTRUCTOR:
 *    - Called when object is copied
 *    - Important for classes with dynamic memory
 *    - Default copy constructor does shallow copy
 *    - Custom copy constructor for deep copy
 * 
 * 6. STATIC MEMBERS:
 *    - Belong to class, not individual objects
 *    - Shared among all objects
 *    - Accessed using ClassName::memberName
 * 
 * 7. INITIALIZATION LIST:
 *    - More efficient than assignment in constructor body
 *    - Required for const members and references
 *    - Syntax: Constructor(params) : member1(value1), member2(value2) {}
 * 
 * BEST PRACTICES:
 * - Always initialize all member variables
 * - Use initialization lists when possible
 * - Provide copy constructor for classes with pointers
 * - Free allocated memory in destructor
 * - Validate constructor parameters
 * - Make destructors virtual in base classes (for inheritance)
 * 
 * COMMON MISTAKES:
 * - Forgetting to initialize members
 * - Not providing copy constructor for dynamic memory
 * - Memory leaks (not freeing in destructor)
 * - Calling virtual functions in constructor/destructor
 */
