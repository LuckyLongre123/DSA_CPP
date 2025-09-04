/*
 * Day 10: Review and Practice - C++ Fundamentals Summary
 * This file provides a comprehensive review of all concepts covered
 * in the 10-day C++ fundamentals course with practice exercises
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <memory>
#include <fstream>

using namespace std;

/*
 * SECTION 1: Basic Concepts Review (Days 1-2)
 */

void reviewBasics() {
    cout << "\n=== BASICS REVIEW (Days 1-2) ===" << endl;
    
    // Variables and data types
    int age = 25;
    double salary = 50000.50;
    char grade = 'A';
    bool isActive = true;
    string name = "John Doe";
    
    cout << "Variables: " << name << ", age " << age << ", grade " << grade << endl;
    
    // Input/Output
    cout << "Enter a number: ";
    int userNumber;
    cin >> userNumber;
    cout << "You entered: " << userNumber << endl;
    
    // Arithmetic operations
    int a = 10, b = 3;
    cout << "Arithmetic: " << a << " + " << b << " = " << (a + b) << endl;
    cout << "Division: " << a << " / " << b << " = " << (a / b) << " (integer)" << endl;
    cout << "Modulo: " << a << " % " << b << " = " << (a % b) << endl;
    
    // Conditional statements
    if (userNumber > 0) {
        cout << "Number is positive" << endl;
    } else if (userNumber < 0) {
        cout << "Number is negative" << endl;
    } else {
        cout << "Number is zero" << endl;
    }
    
    // Switch statement
    switch (grade) {
        case 'A': cout << "Excellent!" << endl; break;
        case 'B': cout << "Good!" << endl; break;
        case 'C': cout << "Average" << endl; break;
        default: cout << "Grade not recognized" << endl;
    }
    
    // Loops
    cout << "For loop (1-5): ";
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    cout << "While loop countdown: ";
    int count = 5;
    while (count > 0) {
        cout << count << " ";
        count--;
    }
    cout << endl;
}

/*
 * SECTION 2: Functions and Recursion Review (Day 3)
 */

// Function examples
int add(int x, int y) {
    return x + y;
}

void greet(const string& name) {
    cout << "Hello, " << name << "!" << endl;
}

// Pass by reference
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Recursive function
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Function overloading
double add(double x, double y) {
    return x + y;
}

void reviewFunctions() {
    cout << "\n=== FUNCTIONS REVIEW (Day 3) ===" << endl;
    
    // Function calls
    cout << "add(5, 3) = " << add(5, 3) << endl;
    cout << "add(2.5, 3.7) = " << add(2.5, 3.7) << endl;
    
    greet("Alice");
    
    // Pass by reference
    int x = 10, y = 20;
    cout << "Before swap: x=" << x << ", y=" << y << endl;
    swap(x, y);
    cout << "After swap: x=" << x << ", y=" << y << endl;
    
    // Recursion
    cout << "factorial(5) = " << factorial(5) << endl;
    
    // Lambda function (C++11)
    auto multiply = [](int a, int b) { return a * b; };
    cout << "Lambda multiply(4, 5) = " << multiply(4, 5) << endl;
}

/*
 * SECTION 3: Arrays and Strings Review (Day 4)
 */

void reviewArraysStrings() {
    cout << "\n=== ARRAYS & STRINGS REVIEW (Day 4) ===" << endl;
    
    // Arrays
    int numbers[5] = {10, 20, 30, 40, 50};
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // 2D Array
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "2D Array:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // Strings
    string text = "Hello World";
    cout << "String: " << text << endl;
    cout << "Length: " << text.length() << endl;
    cout << "First char: " << text[0] << endl;
    cout << "Substring: " << text.substr(0, 5) << endl;
    
    // String operations
    string str1 = "Hello";
    string str2 = "World";
    string combined = str1 + " " + str2;
    cout << "Combined: " << combined << endl;
    
    // Find in string
    size_t pos = text.find("World");
    if (pos != string::npos) {
        cout << "Found 'World' at position: " << pos << endl;
    }
}

/*
 * SECTION 4: Pointers and Dynamic Memory Review (Day 5)
 */

void reviewPointers() {
    cout << "\n=== POINTERS REVIEW (Day 5) ===" << endl;
    
    // Basic pointers
    int value = 42;
    int* ptr = &value;
    
    cout << "Value: " << value << endl;
    cout << "Address: " << &value << endl;
    cout << "Pointer: " << ptr << endl;
    cout << "Dereferenced: " << *ptr << endl;
    
    // Dynamic memory allocation
    int* dynamicArray = new int[5];
    for (int i = 0; i < 5; i++) {
        dynamicArray[i] = (i + 1) * 10;
    }
    
    cout << "Dynamic array: ";
    for (int i = 0; i < 5; i++) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;
    
    delete[] dynamicArray;  // Clean up memory
    
    // Smart pointers (C++11)
    unique_ptr<int> smartPtr = make_unique<int>(100);
    cout << "Smart pointer value: " << *smartPtr << endl;
    // Automatic cleanup when smartPtr goes out of scope
}

/*
 * SECTION 5: Structures and Classes Review (Days 6-8)
 */

// Structure
struct Point {
    double x, y;
    
    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

// Class with encapsulation
class Rectangle {
private:
    double width, height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double getArea() const { return width * height; }
    double getPerimeter() const { return 2 * (width + height); }
    
    void setDimensions(double w, double h) {
        if (w > 0 && h > 0) {
            width = w;
            height = h;
        }
    }
    
    void display() const {
        cout << "Rectangle: " << width << "x" << height 
             << ", Area: " << getArea() << endl;
    }
};

void reviewStructuresClasses() {
    cout << "\n=== STRUCTURES & CLASSES REVIEW (Days 6-8) ===" << endl;
    
    // Structure usage
    Point p1 = {3.0, 4.0};
    cout << "Point p1: ";
    p1.display();
    cout << endl;
    
    // Class usage
    Rectangle rect(5.0, 3.0);
    rect.display();
    
    rect.setDimensions(7.0, 4.0);
    cout << "After resize: ";
    rect.display();
    
    // Vector of objects
    vector<Point> points = {{1, 2}, {3, 4}, {5, 6}};
    cout << "Points in vector: ";
    for (const auto& point : points) {
        point.display();
        cout << " ";
    }
    cout << endl;
}

/*
 * SECTION 6: Inheritance and Polymorphism Review (Day 9)
 */

// Base class
class Shape {
protected:
    string color;
    
public:
    Shape(const string& c) : color(c) {}
    virtual ~Shape() = default;
    
    virtual double getArea() const = 0;  // Pure virtual
    virtual void draw() const {
        cout << "Drawing " << color << " shape";
    }
    
    string getColor() const { return color; }
};

// Derived class
class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(const string& c, double r) : Shape(c), radius(r) {}
    
    double getArea() const override {
        return 3.14159 * radius * radius;
    }
    
    void draw() const override {
        cout << "Drawing " << color << " circle with radius " << radius;
    }
};

class Square : public Shape {
private:
    double side;
    
public:
    Square(const string& c, double s) : Shape(c), side(s) {}
    
    double getArea() const override {
        return side * side;
    }
    
    void draw() const override {
        cout << "Drawing " << color << " square with side " << side;
    }
};

void reviewInheritancePolymorphism() {
    cout << "\n=== INHERITANCE & POLYMORPHISM REVIEW (Day 9) ===" << endl;
    
    // Polymorphism with base class pointers
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>("Red", 5.0));
    shapes.push_back(make_unique<Square>("Blue", 4.0));
    shapes.push_back(make_unique<Circle>("Green", 3.0));
    
    cout << "Polymorphic shape operations:" << endl;
    for (const auto& shape : shapes) {
        shape->draw();
        cout << ", Area: " << shape->getArea() << endl;
    }
}

/*
 * SECTION 7: STL Containers Review (Day 9)
 */

void reviewSTLContainers() {
    cout << "\n=== STL CONTAINERS REVIEW (Day 9) ===" << endl;
    
    // Vector
    vector<int> numbers = {5, 2, 8, 1, 9};
    cout << "Vector before sort: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;
    
    sort(numbers.begin(), numbers.end());
    cout << "Vector after sort: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;
    
    // Map
    map<string, int> ages;
    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages["Charlie"] = 28;
    
    cout << "Map contents:" << endl;
    for (const auto& [name, age] : ages) {
        cout << name << ": " << age << endl;
    }
    
    // Set
    set<int> uniqueNumbers = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    cout << "Set (unique, sorted): ";
    for (int n : uniqueNumbers) cout << n << " ";
    cout << endl;
    
    // Queue
    queue<string> taskQueue;
    taskQueue.push("Task 1");
    taskQueue.push("Task 2");
    taskQueue.push("Task 3");
    
    cout << "Processing queue: ";
    while (!taskQueue.empty()) {
        cout << taskQueue.front() << " ";
        taskQueue.pop();
    }
    cout << endl;
    
    // Stack
    stack<int> numberStack;
    for (int i = 1; i <= 5; i++) {
        numberStack.push(i);
    }
    
    cout << "Stack (LIFO): ";
    while (!numberStack.empty()) {
        cout << numberStack.top() << " ";
        numberStack.pop();
    }
    cout << endl;
}

/*
 * SECTION 8: File I/O Review (Day 7)
 */

void reviewFileIO() {
    cout << "\n=== FILE I/O REVIEW (Day 7) ===" << endl;
    
    // Write to file
    ofstream outFile("review_test.txt");
    if (outFile.is_open()) {
        outFile << "This is a test file" << endl;
        outFile << "Line 2: Numbers 1, 2, 3" << endl;
        outFile << "Line 3: End of file" << endl;
        outFile.close();
        cout << "File written successfully" << endl;
    }
    
    // Read from file
    ifstream inFile("review_test.txt");
    if (inFile.is_open()) {
        string line;
        cout << "File contents:" << endl;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
}

/*
 * SECTION 9: Practice Exercises
 */

void practiceExercises() {
    cout << "\n=== PRACTICE EXERCISES ===" << endl;
    
    // Exercise 1: Find maximum in array
    cout << "\nExercise 1: Find maximum in array" << endl;
    vector<int> testArray = {23, 45, 12, 67, 34, 89, 56};
    int maxVal = *max_element(testArray.begin(), testArray.end());
    cout << "Array: ";
    for (int n : testArray) cout << n << " ";
    cout << "\nMaximum value: " << maxVal << endl;
    
    // Exercise 2: Count vowels in string
    cout << "\nExercise 2: Count vowels in string" << endl;
    string testString = "Hello World Programming";
    int vowelCount = 0;
    for (char c : testString) {
        char lower = tolower(c);
        if (lower == 'a' || lower == 'e' || lower == 'i' || 
            lower == 'o' || lower == 'u') {
            vowelCount++;
        }
    }
    cout << "String: " << testString << endl;
    cout << "Vowel count: " << vowelCount << endl;
    
    // Exercise 3: Fibonacci sequence
    cout << "\nExercise 3: Fibonacci sequence (first 10 numbers)" << endl;
    vector<int> fibonacci = {0, 1};
    for (int i = 2; i < 10; i++) {
        fibonacci.push_back(fibonacci[i-1] + fibonacci[i-2]);
    }
    cout << "Fibonacci: ";
    for (int n : fibonacci) cout << n << " ";
    cout << endl;
    
    // Exercise 4: Word frequency counter
    cout << "\nExercise 4: Word frequency counter" << endl;
    string sentence = "the quick brown fox jumps over the lazy dog";
    map<string, int> wordFreq;
    
    string word = "";
    for (char c : sentence + " ") {  // Add space to process last word
        if (c == ' ') {
            if (!word.empty()) {
                wordFreq[word]++;
                word = "";
            }
        } else {
            word += c;
        }
    }
    
    cout << "Sentence: " << sentence << endl;
    cout << "Word frequencies:" << endl;
    for (const auto& [w, count] : wordFreq) {
        cout << w << ": " << count << endl;
    }
}

/*
 * SECTION 10: Best Practices Summary
 */

void showBestPractices() {
    cout << "\n=== C++ BEST PRACTICES SUMMARY ===" << endl;
    
    cout << "\n1. CODE ORGANIZATION:" << endl;
    cout << "   - Use meaningful variable and function names" << endl;
    cout << "   - Keep functions small and focused" << endl;
    cout << "   - Use consistent indentation and formatting" << endl;
    cout << "   - Add comments for complex logic" << endl;
    
    cout << "\n2. MEMORY MANAGEMENT:" << endl;
    cout << "   - Prefer smart pointers over raw pointers" << endl;
    cout << "   - Always delete dynamically allocated memory" << endl;
    cout << "   - Use RAII (Resource Acquisition Is Initialization)" << endl;
    cout << "   - Avoid memory leaks and dangling pointers" << endl;
    
    cout << "\n3. OBJECT-ORIENTED DESIGN:" << endl;
    cout << "   - Use encapsulation to hide implementation details" << endl;
    cout << "   - Make data members private by default" << endl;
    cout << "   - Use virtual destructors in base classes" << endl;
    cout << "   - Follow the Single Responsibility Principle" << endl;
    
    cout << "\n4. STL USAGE:" << endl;
    cout << "   - Prefer STL containers over raw arrays" << endl;
    cout << "   - Use algorithms from <algorithm> header" << endl;
    cout << "   - Choose the right container for your use case" << endl;
    cout << "   - Use range-based for loops when possible" << endl;
    
    cout << "\n5. ERROR HANDLING:" << endl;
    cout << "   - Use exceptions for error handling" << endl;
    cout << "   - Validate input parameters" << endl;
    cout << "   - Check file operations for success" << endl;
    cout << "   - Provide meaningful error messages" << endl;
    
    cout << "\n6. PERFORMANCE:" << endl;
    cout << "   - Pass large objects by const reference" << endl;
    cout << "   - Use const wherever possible" << endl;
    cout << "   - Avoid unnecessary copying" << endl;
    cout << "   - Profile before optimizing" << endl;
}

/*
 * MAIN FUNCTION
 */

int main() {
    cout << "=== C++ FUNDAMENTALS REVIEW AND PRACTICE ===" << endl;
    cout << "This program reviews all concepts from the 10-day course" << endl;
    
    try {
        reviewBasics();
        reviewFunctions();
        reviewArraysStrings();
        reviewPointers();
        reviewStructuresClasses();
        reviewInheritancePolymorphism();
        reviewSTLContainers();
        reviewFileIO();
        practiceExercises();
        showBestPractices();
        
        cout << "\n=== COURSE COMPLETION ===" << endl;
        cout << "Congratulations! You have successfully reviewed all major C++ concepts." << endl;
        cout << "You are now ready to tackle more advanced programming challenges!" << endl;
        
        cout << "\n=== NEXT STEPS ===" << endl;
        cout << "1. Practice with more complex projects" << endl;
        cout << "2. Learn advanced C++ features (templates, lambda functions)" << endl;
        cout << "3. Study data structures and algorithms" << endl;
        cout << "4. Explore specific domains (graphics, networking, databases)" << endl;
        cout << "5. Contribute to open-source projects" << endl;
        
    } catch (const exception& e) {
        cout << "Error during review: " << e.what() << endl;
    }
    
    return 0;
}

/*
 * COMPLETE COURSE SUMMARY:
 * 
 * DAY 1: C++ Basics
 * ✓ Program structure, variables, data types, I/O
 * 
 * DAY 2: Control Flow
 * ✓ Conditionals, loops, logical operators
 * 
 * DAY 3: Functions and Recursion
 * ✓ Function definition, parameters, scope, recursion
 * 
 * DAY 4: Arrays and Strings
 * ✓ 1D/2D arrays, string operations, character arrays
 * 
 * DAY 5: Pointers and Dynamic Memory
 * ✓ Pointer basics, dynamic allocation, memory management
 * 
 * DAY 6: Structures and Vectors
 * ✓ User-defined types, STL vector, data organization
 * 
 * DAY 7: File I/O and Exception Handling
 * ✓ File operations, error handling, data persistence
 * 
 * DAY 8: Classes and Objects
 * ✓ OOP basics, encapsulation, constructors/destructors
 * 
 * DAY 9: Inheritance and Polymorphism
 * ✓ Class hierarchies, virtual functions, STL containers
 * 
 * DAY 10: Final Projects and Review
 * ✓ Complete applications, best practices, next steps
 * 
 * SKILLS ACQUIRED:
 * - Fundamental programming concepts
 * - Object-oriented programming
 * - Memory management
 * - Data structure usage
 * - File handling
 * - Error management
 * - Code organization
 * - Problem-solving approaches
 * 
 * You are now equipped with solid C++ fundamentals for DSA and beyond!
 */
