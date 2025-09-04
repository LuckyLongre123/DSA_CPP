/*
 * Day 9: Polymorphism in C++
 * This file demonstrates runtime polymorphism, virtual functions,
 * function overriding, and dynamic binding concepts
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

/*
 * SECTION 1: Basic Polymorphism with Animals
 */

// Base class with virtual functions
class Animal {
protected:
    string name;
    int age;
    double weight;
    
public:
    Animal(string n, int a, double w) : name(n), age(a), weight(w) {
        cout << "Animal constructor: " << name << endl;
    }
    
    virtual ~Animal() {
        cout << "Animal destructor: " << name << endl;
    }
    
    // Virtual functions for polymorphic behavior
    virtual void makeSound() const {
        cout << name << " makes a generic animal sound" << endl;
    }
    
    virtual void move() const {
        cout << name << " moves around" << endl;
    }
    
    virtual void eat() const {
        cout << name << " eats food" << endl;
    }
    
    virtual void displayInfo() const {
        cout << "Animal: " << name << ", Age: " << age << ", Weight: " << weight << "kg" << endl;
    }
    
    // Non-virtual function
    void sleep() const {
        cout << name << " is sleeping" << endl;
    }
    
    // Getters
    string getName() const { return name; }
    int getAge() const { return age; }
    double getWeight() const { return weight; }
};

// Derived class - Dog
class Dog : public Animal {
private:
    string breed;
    
public:
    Dog(string n, int a, double w, string b) : Animal(n, a, w), breed(b) {
        cout << "Dog constructor: " << name << endl;
    }
    
    ~Dog() {
        cout << "Dog destructor: " << name << endl;
    }
    
    // Override virtual functions
    void makeSound() const override {
        cout << name << " barks: Woof! Woof!" << endl;
    }
    
    void move() const override {
        cout << name << " runs on four legs" << endl;
    }
    
    void eat() const override {
        cout << name << " eats dog food and bones" << endl;
    }
    
    void displayInfo() const override {
        cout << "Dog: " << name << " (" << breed << "), Age: " << age << ", Weight: " << weight << "kg" << endl;
    }
    
    // Dog-specific methods
    void fetch() const {
        cout << name << " fetches the ball!" << endl;
    }
    
    void wagTail() const {
        cout << name << " wags tail happily!" << endl;
    }
};

// Derived class - Cat
class Cat : public Animal {
private:
    bool isIndoor;
    
public:
    Cat(string n, int a, double w, bool indoor = true) : Animal(n, a, w), isIndoor(indoor) {
        cout << "Cat constructor: " << name << endl;
    }
    
    ~Cat() {
        cout << "Cat destructor: " << name << endl;
    }
    
    // Override virtual functions
    void makeSound() const override {
        cout << name << " meows: Meow! Meow!" << endl;
    }
    
    void move() const override {
        cout << name << " gracefully walks and jumps" << endl;
    }
    
    void eat() const override {
        cout << name << " eats cat food and fish" << endl;
    }
    
    void displayInfo() const override {
        cout << "Cat: " << name << ", Age: " << age << ", Weight: " << weight << "kg";
        cout << " (" << (isIndoor ? "Indoor" : "Outdoor") << ")" << endl;
    }
    
    // Cat-specific methods
    void purr() const {
        cout << name << " purrs contentedly" << endl;
    }
    
    void scratch() const {
        cout << name << " scratches the furniture" << endl;
    }
};

// Derived class - Bird
class Bird : public Animal {
private:
    double wingspan;
    bool canFly;
    
public:
    Bird(string n, int a, double w, double ws, bool fly = true) 
        : Animal(n, a, w), wingspan(ws), canFly(fly) {
        cout << "Bird constructor: " << name << endl;
    }
    
    ~Bird() {
        cout << "Bird destructor: " << name << endl;
    }
    
    // Override virtual functions
    void makeSound() const override {
        cout << name << " chirps: Tweet! Tweet!" << endl;
    }
    
    void move() const override {
        if (canFly) {
            cout << name << " flies with " << wingspan << "cm wingspan" << endl;
        } else {
            cout << name << " walks and hops" << endl;
        }
    }
    
    void eat() const override {
        cout << name << " eats seeds and insects" << endl;
    }
    
    void displayInfo() const override {
        cout << "Bird: " << name << ", Age: " << age << ", Weight: " << weight << "kg";
        cout << ", Wingspan: " << wingspan << "cm";
        cout << " (" << (canFly ? "Can fly" : "Cannot fly") << ")" << endl;
    }
    
    // Bird-specific methods
    void buildNest() const {
        cout << name << " builds a nest" << endl;
    }
    
    void migrate() const {
        if (canFly) {
            cout << name << " migrates to warmer regions" << endl;
        } else {
            cout << name << " cannot migrate (flightless)" << endl;
        }
    }
};

/*
 * SECTION 2: Advanced Polymorphism with Shapes
 */

class Shape {
protected:
    string color;
    double x, y;  // Position
    
public:
    Shape(string c, double posX = 0, double posY = 0) : color(c), x(posX), y(posY) {}
    virtual ~Shape() = default;
    
    // Pure virtual functions
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void draw() const = 0;
    
    // Virtual functions with default implementation
    virtual void move(double deltaX, double deltaY) {
        x += deltaX;
        y += deltaY;
        cout << "Shape moved to (" << x << ", " << y << ")" << endl;
    }
    
    virtual void changeColor(const string& newColor) {
        color = newColor;
        cout << "Shape color changed to " << color << endl;
    }
    
    // Non-virtual functions
    string getColor() const { return color; }
    double getX() const { return x; }
    double getY() const { return y; }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(string c, double r, double x = 0, double y = 0) : Shape(c, x, y), radius(r) {}
    
    double getArea() const override {
        return 3.14159 * radius * radius;
    }
    
    double getPerimeter() const override {
        return 2 * 3.14159 * radius;
    }
    
    void draw() const override {
        cout << "Drawing " << color << " circle with radius " << radius 
             << " at (" << x << ", " << y << ")" << endl;
    }
    
    double getRadius() const { return radius; }
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(string c, double w, double h, double x = 0, double y = 0) 
        : Shape(c, x, y), width(w), height(h) {}
    
    double getArea() const override {
        return width * height;
    }
    
    double getPerimeter() const override {
        return 2 * (width + height);
    }
    
    void draw() const override {
        cout << "Drawing " << color << " rectangle " << width << "x" << height 
             << " at (" << x << ", " << y << ")" << endl;
    }
    
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

class Triangle : public Shape {
private:
    double base, height;
    
public:
    Triangle(string c, double b, double h, double x = 0, double y = 0) 
        : Shape(c, x, y), base(b), height(h) {}
    
    double getArea() const override {
        return 0.5 * base * height;
    }
    
    double getPerimeter() const override {
        // Assuming equilateral triangle for simplicity
        return 3 * base;
    }
    
    void draw() const override {
        cout << "Drawing " << color << " triangle with base " << base 
             << " and height " << height << " at (" << x << ", " << y << ")" << endl;
    }
    
    double getBase() const { return base; }
    double getTriangleHeight() const { return height; }
};

/*
 * SECTION 3: Function Overloading vs Overriding Demo
 */

class Calculator {
public:
    // Function overloading (compile-time polymorphism)
    int add(int a, int b) {
        cout << "Adding two integers: " << a << " + " << b << endl;
        return a + b;
    }
    
    double add(double a, double b) {
        cout << "Adding two doubles: " << a << " + " << b << endl;
        return a + b;
    }
    
    int add(int a, int b, int c) {
        cout << "Adding three integers: " << a << " + " << b << " + " << c << endl;
        return a + b + c;
    }
    
    string add(const string& a, const string& b) {
        cout << "Concatenating strings: " << a << " + " << b << endl;
        return a + b;
    }
    
    virtual void displayType() const {
        cout << "Basic Calculator" << endl;
    }
};

class ScientificCalculator : public Calculator {
public:
    // Function overriding (runtime polymorphism)
    void displayType() const override {
        cout << "Scientific Calculator" << endl;
    }
    
    // Additional scientific functions
    double power(double base, double exponent) {
        cout << "Calculating " << base << "^" << exponent << endl;
        double result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
        return result;
    }
    
    double squareRoot(double number) {
        cout << "Calculating square root of " << number << endl;
        // Simple approximation
        double guess = number / 2;
        for (int i = 0; i < 10; i++) {
            guess = (guess + number / guess) / 2;
        }
        return guess;
    }
};

int main() {
    cout << "=== Polymorphism Demonstration ===" << endl;
    
    /*
     * SECTION 4: Basic Polymorphism with Animals
     */
    
    cout << "\n=== Animal Polymorphism ===" << endl;
    
    // Create different animals
    vector<unique_ptr<Animal>> zoo;
    zoo.push_back(make_unique<Dog>("Buddy", 3, 25.5, "Golden Retriever"));
    zoo.push_back(make_unique<Cat>("Whiskers", 2, 4.2, true));
    zoo.push_back(make_unique<Bird>("Tweety", 1, 0.1, 15.0, true));
    zoo.push_back(make_unique<Dog>("Rex", 5, 30.0, "German Shepherd"));
    zoo.push_back(make_unique<Cat>("Shadow", 4, 5.1, false));
    
    cout << "All animals in the zoo:" << endl;
    for (const auto& animal : zoo) {
        cout << "\n--- Animal Info ---" << endl;
        animal->displayInfo();
        animal->makeSound();
        animal->move();
        animal->eat();
        animal->sleep();  // Non-virtual function - same for all
    }
    
    /*
     * SECTION 5: Polymorphic Function Calls
     */
    
    cout << "\n=== Polymorphic Function Demo ===" << endl;
    
    // Function that works with any Animal
    auto feedAnimal = [](const Animal& animal) {
        cout << "Feeding " << animal.getName() << ":" << endl;
        animal.eat();
        animal.makeSound();  // Polymorphic call
    };
    
    Dog myDog("Fido", 2, 20.0, "Labrador");
    Cat myCat("Mittens", 3, 4.5, true);
    Bird myBird("Robin", 1, 0.08, 12.0, true);
    
    feedAnimal(myDog);
    feedAnimal(myCat);
    feedAnimal(myBird);
    
    /*
     * SECTION 6: Shape Polymorphism
     */
    
    cout << "\n=== Shape Polymorphism ===" << endl;
    
    vector<unique_ptr<Shape>> canvas;
    canvas.push_back(make_unique<Circle>("Red", 5.0, 10, 20));
    canvas.push_back(make_unique<Rectangle>("Blue", 8.0, 6.0, 30, 40));
    canvas.push_back(make_unique<Triangle>("Green", 6.0, 4.0, 50, 60));
    canvas.push_back(make_unique<Circle>("Yellow", 3.0, 70, 80));
    
    cout << "Drawing all shapes:" << endl;
    double totalArea = 0;
    for (const auto& shape : canvas) {
        shape->draw();
        cout << "  Area: " << shape->getArea() << endl;
        cout << "  Perimeter: " << shape->getPerimeter() << endl;
        totalArea += shape->getArea();
    }
    
    cout << "Total area of all shapes: " << totalArea << endl;
    
    // Move all shapes
    cout << "\nMoving all shapes by (5, 5):" << endl;
    for (const auto& shape : canvas) {
        shape->move(5, 5);
    }
    
    /*
     * SECTION 7: Function Overloading vs Overriding
     */
    
    cout << "\n=== Function Overloading vs Overriding ===" << endl;
    
    Calculator basicCalc;
    ScientificCalculator sciCalc;
    
    cout << "Function Overloading (Compile-time Polymorphism):" << endl;
    cout << "Result: " << basicCalc.add(5, 3) << endl;
    cout << "Result: " << basicCalc.add(2.5, 3.7) << endl;
    cout << "Result: " << basicCalc.add(1, 2, 3) << endl;
    cout << "Result: " << basicCalc.add(string("Hello"), string(" World")) << endl;
    
    cout << "\nFunction Overriding (Runtime Polymorphism):" << endl;
    Calculator* calc1 = &basicCalc;
    Calculator* calc2 = &sciCalc;
    
    cout << "Basic calculator type: ";
    calc1->displayType();
    cout << "Scientific calculator type: ";
    calc2->displayType();
    
    cout << "\nScientific calculator specific functions:" << endl;
    cout << "2^8 = " << sciCalc.power(2, 8) << endl;
    cout << "√25 = " << sciCalc.squareRoot(25) << endl;
    
    /*
     * SECTION 8: Virtual Function Table Demonstration
     */
    
    cout << "\n=== Virtual Function Table Demo ===" << endl;
    
    // Array of base class pointers
    Animal* animals[] = {
        new Dog("Spot", 4, 22.0, "Beagle"),
        new Cat("Fluffy", 3, 4.8, true),
        new Bird("Eagle", 5, 3.2, 200.0, true)
    };
    
    cout << "Calling virtual functions through base class pointers:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\nAnimal " << (i + 1) << ":" << endl;
        animals[i]->displayInfo();  // Virtual function call
        animals[i]->makeSound();    // Virtual function call
        animals[i]->move();         // Virtual function call
    }
    
    // Clean up
    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }
    
    /*
     * SECTION 9: Dynamic Casting
     */
    
    cout << "\n=== Dynamic Casting Demo ===" << endl;
    
    Animal* animal = new Dog("Max", 6, 28.0, "Bulldog");
    
    // Try to cast to Dog
    Dog* dog = dynamic_cast<Dog*>(animal);
    if (dog != nullptr) {
        cout << "Successfully cast to Dog!" << endl;
        dog->fetch();
        dog->wagTail();
    }
    
    // Try to cast to Cat (should fail)
    Cat* cat = dynamic_cast<Cat*>(animal);
    if (cat == nullptr) {
        cout << "Cannot cast Dog to Cat (as expected)" << endl;
    }
    
    delete animal;
    
    cout << "\n=== Polymorphism Complete! ===" << endl;
    
    return 0;
}

/*
 * POLYMORPHISM KEY CONCEPTS:
 * 
 * 1. TYPES OF POLYMORPHISM:
 *    - Compile-time: Function overloading, operator overloading
 *    - Runtime: Virtual functions, function overriding
 * 
 * 2. VIRTUAL FUNCTIONS:
 *    - Enable runtime polymorphism
 *    - Resolved at runtime using virtual function table (vtable)
 *    - Base class pointer can call derived class methods
 * 
 * 3. FUNCTION OVERRIDING:
 *    - Derived class provides specific implementation
 *    - Same function signature as base class
 *    - Use 'override' keyword for clarity and safety
 * 
 * 4. PURE VIRTUAL FUNCTIONS:
 *    - virtual function = 0;
 *    - Makes class abstract
 *    - Must be implemented by derived classes
 * 
 * 5. VIRTUAL DESTRUCTOR:
 *    - Ensures proper cleanup in inheritance hierarchy
 *    - Always use virtual destructor in base classes
 * 
 * 6. DYNAMIC BINDING:
 *    - Function call resolved at runtime
 *    - Based on actual object type, not pointer type
 *    - Enables polymorphic behavior
 * 
 * 7. VIRTUAL FUNCTION TABLE (VTABLE):
 *    - Table of function pointers for each class
 *    - Used to resolve virtual function calls
 *    - Each object has pointer to its class's vtable
 * 
 * BENEFITS:
 * - Code flexibility and extensibility
 * - Uniform interface for different types
 * - Easy to add new types without changing existing code
 * - Supports open/closed principle
 * 
 * BEST PRACTICES:
 * - Use virtual destructors in base classes
 * - Use 'override' keyword in derived classes
 * - Prefer smart pointers for automatic memory management
 * - Keep virtual function interfaces stable
 * - Use pure virtual functions to define contracts
 * - Consider performance impact of virtual function calls
 * 
 * COMMON PITFALLS:
 * - Forgetting virtual destructor
 * - Calling virtual functions in constructors/destructors
 * - Slicing when passing objects by value
 * - Not using 'override' keyword
 */
