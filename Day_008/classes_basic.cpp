/*
 * Day 8: Simple Programming Organization for Beginners
 * This file demonstrates basic ways to organize code and data
 * Focus on simple concepts before advanced object-oriented programming
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * SECTION 1: Simple Data Organization
 * Using structures to group related information
 */

struct SimpleCalculator {
    int num1;
    int num2;
    
    int add() {
        return num1 + num2;
    }
    
    int subtract() {
        return num1 - num2;
    }
    
    int multiply() {
        return num1 * num2;
    }
    
    void showResults() {
        cout << num1 << " + " << num2 << " = " << add() << endl;
        cout << num1 << " - " << num2 << " = " << subtract() << endl;
        cout << num1 << " * " << num2 << " = " << multiply() << endl;
    }
};

/*
 * SECTION 2: Simple Student Information
 * Organizing student data and simple operations
 */

struct Student {
    string name;
    int age;
    char grade;
    
    void displayInfo() {
        cout << "Student: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
    }
    
    bool isHonorStudent() {
        return (grade == 'A');
    }
    
    void celebrateBirthday() {
        age++;
        cout << name << " is now " << age << " years old!" << endl;
    }
};

/*
 * SECTION 3: Simple Book Information
 * Organizing book data with simple functions
 */

struct Book {
    string title;
    string author;
    int pages;
    
    void displayInfo() {
        cout << "Book: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
    
    bool isLongBook() {
        return (pages > 300);
    }
    
    void addPages(int newPages) {
        pages += newPages;
        cout << "Added " << newPages << " pages. Total now: " << pages << endl;
    }
};

int main() {
    cout << "=== Simple Programming Organization ===" << endl;
    
    /*
     * SECTION 4: Using Simple Calculator
     */
    
    cout << "\n=== Calculator Demo ===" << endl;
    
    SimpleCalculator calc;
    calc.num1 = 15;
    calc.num2 = 7;
    calc.showResults();
    
    cout << "\nAnother calculation:" << endl;
    calc.num1 = 25;
    calc.num2 = 8;
    calc.showResults();
    
    /*
     * SECTION 5: Using Student Structure
     */
    
    cout << "\n=== Student Demo ===" << endl;
    
    Student student1;
    student1.name = "Alice";
    student1.age = 18;
    student1.grade = 'A';
    
    student1.displayInfo();
    cout << "Honor student: " << (student1.isHonorStudent() ? "Yes" : "No") << endl;
    student1.celebrateBirthday();
    
    /*
     * SECTION 6: Working with Books
     */
    
    cout << "\n=== Book Demo ===" << endl;
    
    Book book1;
    book1.title = "Harry Potter";
    book1.author = "J.K. Rowling";
    book1.pages = 350;
    
    book1.displayInfo();
    cout << "Long book: " << (book1.isLongBook() ? "Yes" : "No") << endl;
    book1.addPages(50);
    
    /*
     * SECTION 7: Multiple Students Practice
     */
    
    cout << "\n=== Multiple Students ===" << endl;
    
    Student students[3];
    
    students[0] = {"Emma", 18, 'A'};
    students[1] = {"David", 19, 'B'};
    students[2] = {"Sarah", 20, 'A'};
    
    cout << "Class list:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\nStudent " << (i + 1) << ":" << endl;
        students[i].displayInfo();
        cout << "Honor student: " << (students[i].isHonorStudent() ? "Yes" : "No") << endl;
    }
    
    /*
     * PRACTICE EXERCISES FOR BEGINNERS:
     */
    
    cout << "\n=== Practice Exercises ===" << endl;
    cout << "Try these exercises on your own:" << endl;
    cout << "1. Create a Car structure with make, model, year, and functions" << endl;
    cout << "2. Make a simple BankAccount with deposit and withdraw" << endl;
    cout << "3. Create a Pet structure with name, age, and simple actions" << endl;
    cout << "4. Build a simple Game Player with score and level" << endl;
    cout << "5. Make a Recipe structure with ingredients and cooking time" << endl;
    
    cout << "\n=== Simple Programming Organization Complete! ===" << endl;
    
    return 0;
}

/*
 * SIMPLE PROGRAMMING ORGANIZATION FOR BEGINNERS:
 * 
 * 1. STRUCTURES WITH FUNCTIONS:
 *    - struct Name { data; functions; }; - Group related items
 *    - Functions can work with the data in the structure
 *    - Easy way to organize code and data together
 * 
 * 2. CREATING AND USING OBJECTS:
 *    - StructName objectName; - Create an object
 *    - objectName.data = value; - Set data
 *    - objectName.function(); - Call function
 * 
 * 3. SIMPLE FUNCTIONS IN STRUCTURES:
 *    - Functions that display information
 *    - Functions that check conditions (return true/false)
 *    - Functions that modify the data
 * 
 * 4. MULTIPLE OBJECTS:
 *    - Create arrays of structures: Student students[10];
 *    - Each object has its own data
 *    - Can process multiple objects with loops
 * 
 * 5. WHY ORGANIZE CODE THIS WAY:
 *    - Keep related data and functions together
 *    - Make code easier to understand and maintain
 *    - Reuse the same structure for different objects
 *    - Foundation for more advanced programming
 * 
 * BEGINNER TIPS:
 * - Start with simple structures (3-4 data items)
 * - Add simple functions that are easy to understand
 * - Practice creating multiple objects
 * - Use meaningful names for everything
 * - Test each function to make sure it works
 * 
 * PRACTICE IDEAS:
 * - Create structures for real-world objects
 * - Add functions that make sense for those objects
 * - Practice with arrays of objects
 * - Build simple interactive programs
 * - Experiment with different data types
 */
