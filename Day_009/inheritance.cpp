/*
 * Day 9: Inheritance in C++
 * This file demonstrates inheritance concepts including base classes, derived classes,
 * access specifiers, method overriding, and polymorphism basics
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * SECTION 1: Basic Inheritance - Vehicle Hierarchy
 */

// Base class
class Vehicle {
protected:  // Protected members accessible to derived classes
    string brand;
    string model;
    int year;
    double price;
    
public:
    // Constructor
    Vehicle(string b, string m, int y, double p) {
        brand = b;
        model = m;
        year = y;
        price = p;
        cout << "Vehicle constructor called for " << brand << " " << model << endl;
    }
    
    // Virtual destructor (important for inheritance)
    virtual ~Vehicle() {
        cout << "Vehicle destructor called for " << brand << " " << model << endl;
    }
    
    // Getter methods
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    
    // Virtual methods (can be overridden by derived classes)
    virtual void displayInfo() const {
        cout << "Vehicle: " << year << " " << brand << " " << model << " - $" << price << endl;
    }
    
    virtual void startEngine() const {
        cout << "Starting " << brand << " " << model << " engine..." << endl;
    }
    
    virtual double calculateInsurance() const {
        return price * 0.05;  // Base 5% of vehicle price
    }
    
    // Non-virtual method
    void honk() const {
        cout << brand << " " << model << " goes BEEP BEEP!" << endl;
    }
};

// Derived class - Car
class Car : public Vehicle {
private:
    int doors;
    string fuelType;
    double fuelCapacity;
    
public:
    // Constructor - calls base class constructor
    Car(string b, string m, int y, double p, int d, string fuel, double capacity) 
        : Vehicle(b, m, y, p) {  // Call base constructor
        doors = d;
        fuelType = fuel;
        fuelCapacity = capacity;
        cout << "Car constructor called" << endl;
    }
    
    // Destructor
    ~Car() {
        cout << "Car destructor called" << endl;
    }
    
    // Getter methods for car-specific attributes
    int getDoors() const { return doors; }
    string getFuelType() const { return fuelType; }
    double getFuelCapacity() const { return fuelCapacity; }
    
    // Override base class methods
    void displayInfo() const override {
        cout << "Car: " << year << " " << brand << " " << model << endl;
        cout << "  Doors: " << doors << ", Fuel: " << fuelType << endl;
        cout << "  Capacity: " << fuelCapacity << "L, Price: $" << price << endl;
    }
    
    void startEngine() const override {
        cout << "Starting " << brand << " " << model << " car engine with " << fuelType << "..." << endl;
    }
    
    double calculateInsurance() const override {
        double baseInsurance = Vehicle::calculateInsurance();
        // Cars have lower insurance than base vehicles
        return baseInsurance * 0.8;
    }
    
    // Car-specific methods
    void openTrunk() const {
        cout << "Opening " << brand << " " << model << " trunk" << endl;
    }
    
    void calculateFuelEfficiency(double distance, double fuelUsed) const {
        if (fuelUsed > 0) {
            double efficiency = distance / fuelUsed;
            cout << brand << " " << model << " fuel efficiency: " << efficiency << " km/L" << endl;
        }
    }
};

// Another derived class - Motorcycle
class Motorcycle : public Vehicle {
private:
    int engineSize;  // in CC
    bool hasSidecar;
    
public:
    // Constructor
    Motorcycle(string b, string m, int y, double p, int engine, bool sidecar = false)
        : Vehicle(b, m, y, p) {
        engineSize = engine;
        hasSidecar = sidecar;
        cout << "Motorcycle constructor called" << endl;
    }
    
    // Destructor
    ~Motorcycle() {
        cout << "Motorcycle destructor called" << endl;
    }
    
    // Getters
    int getEngineSize() const { return engineSize; }
    bool getHasSidecar() const { return hasSidecar; }
    
    // Override methods
    void displayInfo() const override {
        cout << "Motorcycle: " << year << " " << brand << " " << model << endl;
        cout << "  Engine: " << engineSize << "CC";
        if (hasSidecar) cout << " with sidecar";
        cout << ", Price: $" << price << endl;
    }
    
    void startEngine() const override {
        cout << "Starting " << brand << " " << model << " motorcycle engine (" << engineSize << "CC)..." << endl;
    }
    
    double calculateInsurance() const override {
        double baseInsurance = Vehicle::calculateInsurance();
        // Motorcycles have higher insurance due to risk
        return baseInsurance * 1.5;
    }
    
    // Motorcycle-specific methods
    void wheelie() const {
        cout << "Performing wheelie on " << brand << " " << model << "!" << endl;
    }
};

/*
 * SECTION 2: Multiple Inheritance Example
 */

// First base class
class Engine {
protected:
    int horsepower;
    string engineType;
    
public:
    Engine(int hp, string type) : horsepower(hp), engineType(type) {
        cout << "Engine constructor: " << hp << "HP " << type << endl;
    }
    
    virtual ~Engine() {
        cout << "Engine destructor" << endl;
    }
    
    int getHorsepower() const { return horsepower; }
    string getEngineType() const { return engineType; }
    
    virtual void startEngine() const {
        cout << "Starting " << horsepower << "HP " << engineType << " engine" << endl;
    }
};

// Second base class
class GPS {
protected:
    string gpsModel;
    bool isActive;
    
public:
    GPS(string model) : gpsModel(model), isActive(false) {
        cout << "GPS constructor: " << model << endl;
    }
    
    virtual ~GPS() {
        cout << "GPS destructor" << endl;
    }
    
    string getGPSModel() const { return gpsModel; }
    bool getIsActive() const { return isActive; }
    
    void activateGPS() {
        isActive = true;
        cout << "GPS " << gpsModel << " activated" << endl;
    }
    
    void navigate(const string& destination) const {
        if (isActive) {
            cout << "Navigating to " << destination << " using " << gpsModel << endl;
        } else {
            cout << "GPS not active. Please activate first." << endl;
        }
    }
};

// Multiple inheritance class
class SmartCar : public Car, public Engine, public GPS {
private:
    bool autonomousMode;
    
public:
    SmartCar(string b, string m, int y, double p, int d, string fuel, double capacity,
             int hp, string engineType, string gpsModel)
        : Car(b, m, y, p, d, fuel, capacity),
          Engine(hp, engineType),
          GPS(gpsModel),
          autonomousMode(false) {
        cout << "SmartCar constructor called" << endl;
    }
    
    ~SmartCar() {
        cout << "SmartCar destructor called" << endl;
    }
    
    bool getAutonomousMode() const { return autonomousMode; }
    
    void enableAutonomous() {
        autonomousMode = true;
        activateGPS();  // GPS needed for autonomous driving
        cout << "Autonomous mode enabled for " << brand << " " << model << endl;
    }
    
    void disableAutonomous() {
        autonomousMode = false;
        cout << "Autonomous mode disabled for " << brand << " " << model << endl;
    }
    
    // Override startEngine to use Engine's version
    void startEngine() const override {
        Engine::startEngine();  // Call Engine's startEngine
        cout << "Smart systems initialized" << endl;
    }
    
    void displayInfo() const override {
        Car::displayInfo();  // Call Car's displayInfo
        cout << "  Engine: " << horsepower << "HP " << engineType << endl;
        cout << "  GPS: " << gpsModel << (isActive ? " (Active)" : " (Inactive)") << endl;
        cout << "  Autonomous: " << (autonomousMode ? "Enabled" : "Disabled") << endl;
    }
    
    void autoDrive(const string& destination) {
        if (autonomousMode && isActive) {
            cout << "Auto-driving to " << destination << "..." << endl;
            navigate(destination);
        } else {
            cout << "Cannot auto-drive. Check autonomous mode and GPS status." << endl;
        }
    }
};

/*
 * SECTION 3: Abstract Base Class Example
 */

// Abstract base class (has pure virtual functions)
class Shape {
protected:
    string color;
    
public:
    Shape(string c) : color(c) {
        cout << "Shape constructor: " << color << endl;
    }
    
    virtual ~Shape() {
        cout << "Shape destructor" << endl;
    }
    
    string getColor() const { return color; }
    
    // Pure virtual functions (must be implemented by derived classes)
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    virtual void displayInfo() const = 0;
    
    // Non-pure virtual function (can be overridden)
    virtual void changeColor(const string& newColor) {
        color = newColor;
        cout << "Shape color changed to " << color << endl;
    }
};

// Derived class from abstract base
class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(string c, double w, double h) : Shape(c), width(w), height(h) {
        cout << "Rectangle constructor" << endl;
    }
    
    ~Rectangle() {
        cout << "Rectangle destructor" << endl;
    }
    
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    
    // Implement pure virtual functions
    double calculateArea() const override {
        return width * height;
    }
    
    double calculatePerimeter() const override {
        return 2 * (width + height);
    }
    
    void displayInfo() const override {
        cout << "Rectangle: " << color << ", " << width << "x" << height << endl;
        cout << "  Area: " << calculateArea() << ", Perimeter: " << calculatePerimeter() << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(string c, double r) : Shape(c), radius(r) {
        cout << "Circle constructor" << endl;
    }
    
    ~Circle() {
        cout << "Circle destructor" << endl;
    }
    
    double getRadius() const { return radius; }
    
    // Implement pure virtual functions
    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
    
    double calculatePerimeter() const override {
        return 2 * 3.14159 * radius;
    }
    
    void displayInfo() const override {
        cout << "Circle: " << color << ", radius " << radius << endl;
        cout << "  Area: " << calculateArea() << ", Perimeter: " << calculatePerimeter() << endl;
    }
};

int main() {
    cout << "=== Inheritance Demonstration ===" << endl;
    
    /*
     * SECTION 4: Basic Inheritance Usage
     */
    
    cout << "\n=== Basic Inheritance ===" << endl;
    
    // Create base class object
    Vehicle genericVehicle("Generic", "Model", 2020, 15000.0);
    genericVehicle.displayInfo();
    genericVehicle.startEngine();
    cout << "Insurance: $" << genericVehicle.calculateInsurance() << endl;
    
    cout << "\n--- Creating Car ---" << endl;
    Car myCar("Toyota", "Camry", 2023, 28000.0, 4, "Gasoline", 60.0);
    myCar.displayInfo();
    myCar.startEngine();
    myCar.openTrunk();
    myCar.calculateFuelEfficiency(400.0, 25.0);
    cout << "Car insurance: $" << myCar.calculateInsurance() << endl;
    
    cout << "\n--- Creating Motorcycle ---" << endl;
    Motorcycle myBike("Harley-Davidson", "Street 750", 2022, 8000.0, 750, false);
    myBike.displayInfo();
    myBike.startEngine();
    myBike.wheelie();
    cout << "Motorcycle insurance: $" << myBike.calculateInsurance() << endl;
    
    /*
     * SECTION 5: Polymorphism with Base Class Pointers
     */
    
    cout << "\n=== Polymorphism Demo ===" << endl;
    
    vector<Vehicle*> garage;
    garage.push_back(new Car("BMW", "X5", 2023, 55000.0, 4, "Gasoline", 80.0));
    garage.push_back(new Motorcycle("Yamaha", "R1", 2023, 17000.0, 1000));
    garage.push_back(new Car("Tesla", "Model 3", 2023, 45000.0, 4, "Electric", 75.0));
    
    cout << "All vehicles in garage:" << endl;
    for (size_t i = 0; i < garage.size(); i++) {
        cout << "\nVehicle " << (i + 1) << ":" << endl;
        garage[i]->displayInfo();  // Calls appropriate derived class method
        garage[i]->startEngine();
        cout << "Insurance: $" << garage[i]->calculateInsurance() << endl;
    }
    
    // Clean up memory
    for (Vehicle* vehicle : garage) {
        delete vehicle;
    }
    garage.clear();
    
    /*
     * SECTION 6: Multiple Inheritance
     */
    
    cout << "\n=== Multiple Inheritance ===" << endl;
    
    SmartCar smartCar("Tesla", "Model S", 2024, 80000.0, 4, "Electric", 100.0,
                      670, "Electric Motor", "Tesla GPS v3.0");
    
    smartCar.displayInfo();
    smartCar.startEngine();
    smartCar.enableAutonomous();
    smartCar.autoDrive("San Francisco");
    
    /*
     * SECTION 7: Abstract Base Class
     */
    
    cout << "\n=== Abstract Base Class ===" << endl;
    
    // Cannot create Shape object directly (it's abstract)
    // Shape shape("red");  // This would cause compilation error
    
    Rectangle rect("Blue", 5.0, 3.0);
    rect.displayInfo();
    rect.changeColor("Green");
    rect.displayInfo();
    
    Circle circle("Red", 4.0);
    circle.displayInfo();
    
    // Polymorphism with abstract base class
    vector<Shape*> shapes;
    shapes.push_back(new Rectangle("Yellow", 8.0, 6.0));
    shapes.push_back(new Circle("Purple", 3.5));
    shapes.push_back(new Rectangle("Orange", 4.0, 4.0));
    
    cout << "\nAll shapes:" << endl;
    double totalArea = 0.0;
    for (size_t i = 0; i < shapes.size(); i++) {
        cout << "\nShape " << (i + 1) << ":" << endl;
        shapes[i]->displayInfo();
        totalArea += shapes[i]->calculateArea();
    }
    
    cout << "\nTotal area of all shapes: " << totalArea << endl;
    
    // Clean up
    for (Shape* shape : shapes) {
        delete shape;
    }
    
    /*
     * SECTION 8: Access Specifier Demonstration
     */
    
    cout << "\n=== Access Specifier Demo ===" << endl;
    
    class AccessDemo : public Vehicle {
    public:
        AccessDemo() : Vehicle("Demo", "Car", 2023, 20000.0) {}
        
        void demonstrateAccess() {
            // Can access protected members from base class
            cout << "Accessing protected members:" << endl;
            cout << "Brand: " << brand << endl;      // protected - accessible
            cout << "Model: " << model << endl;      // protected - accessible
            // cout << price << endl;                // private - not accessible
            cout << "Price: " << getPrice() << endl; // Use public getter instead
        }
    };
    
    AccessDemo demo;
    demo.demonstrateAccess();
    
    cout << "\n=== Inheritance Complete! ===" << endl;
    
    return 0;
}

/*
 * INHERITANCE KEY CONCEPTS:
 * 
 * 1. INHERITANCE TYPES:
 *    - public: public members remain public, protected remain protected
 *    - protected: public and protected members become protected
 *    - private: all members become private
 * 
 * 2. ACCESS SPECIFIERS:
 *    - private: Only accessible within the class
 *    - protected: Accessible in class and derived classes
 *    - public: Accessible everywhere
 * 
 * 3. CONSTRUCTOR/DESTRUCTOR ORDER:
 *    - Construction: Base class first, then derived class
 *    - Destruction: Derived class first, then base class
 * 
 * 4. METHOD OVERRIDING:
 *    - Use virtual keyword in base class
 *    - Use override keyword in derived class (C++11)
 *    - Virtual destructor important for proper cleanup
 * 
 * 5. POLYMORPHISM:
 *    - Base class pointers can point to derived objects
 *    - Virtual functions enable runtime method selection
 *    - Pure virtual functions create abstract classes
 * 
 * 6. MULTIPLE INHERITANCE:
 *    - Class can inherit from multiple base classes
 *    - Use scope resolution (::) to resolve ambiguity
 *    - Diamond problem can occur (solved with virtual inheritance)
 * 
 * 7. ABSTRACT CLASSES:
 *    - Contains at least one pure virtual function
 *    - Cannot be instantiated directly
 *    - Derived classes must implement all pure virtual functions
 * 
 * BENEFITS:
 * - Code reusability
 * - Hierarchical organization
 * - Polymorphic behavior
 * - Extensibility
 * 
 * BEST PRACTICES:
 * - Use virtual destructors in base classes
 * - Prefer composition over inheritance when appropriate
 * - Keep inheritance hierarchies shallow
 * - Use protected for members that derived classes need
 * - Document inheritance relationships clearly
 * - Use abstract base classes to define interfaces
 */
