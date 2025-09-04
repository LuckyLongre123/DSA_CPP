/*
 * Day 6: Simple Data Organization for Beginners
 * This file demonstrates basic ways to organize related data
 * Focus on simple concepts before advanced structures
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * SECTION 1: Simple Structure Definition
 * A structure groups related information together
 */

struct Student {
    string name;
    int age;
    char grade;
};

struct Book {
    string title;
    string author;
    int pages;
};

int main() {
    cout << "=== Simple Data Organization ===" << endl;
    
    /*
     * SECTION 2: Creating and Using Simple Structures
     */
    
    cout << "\n=== Creating Students ===" << endl;
    
    // Method 1: Declare then assign values
    Student student1;
    student1.name = "Alice";
    student1.age = 18;
    student1.grade = 'A';
    
    // Method 2: Initialize during declaration
    Student student2 = {"Bob", 19, 'B'};
    
    cout << "Students created successfully!" << endl;
    
    /*
     * SECTION 3: Displaying Structure Information
     */
    
    cout << "\n=== Student Information ===" << endl;
    
    cout << "Student 1:" << endl;
    cout << "Name: " << student1.name << endl;
    cout << "Age: " << student1.age << endl;
    cout << "Grade: " << student1.grade << endl;
    
    cout << "\nStudent 2:" << endl;
    cout << "Name: " << student2.name << endl;
    cout << "Age: " << student2.age << endl;
    cout << "Grade: " << student2.grade << endl;
    
    /*
     * SECTION 4: Changing Structure Values
     */
    
    cout << "\n=== Updating Student Information ===" << endl;
    
    cout << "Before update:" << endl;
    cout << student1.name << " has grade: " << student1.grade << endl;
    
    // Update student information
    student1.grade = 'A';
    student1.age = 19;
    
    cout << "After update:" << endl;
    cout << student1.name << " has grade: " << student1.grade << " and age: " << student1.age << endl;
    
    /*
     * SECTION 5: Working with Books
     */
    
    cout << "\n=== Book Examples ===" << endl;
    
    Book book1 = {"Harry Potter", "J.K. Rowling", 300};
    Book book2;
    
    book2.title = "The Hobbit";
    book2.author = "J.R.R. Tolkien";
    book2.pages = 250;
    
    cout << "Book 1: " << book1.title << " by " << book1.author << " (" << book1.pages << " pages)" << endl;
    cout << "Book 2: " << book2.title << " by " << book2.author << " (" << book2.pages << " pages)" << endl;
    
    /*
     * SECTION 6: Multiple Students (Simple Array)
     */
    
    cout << "\n=== Class of Students ===" << endl;
    
    Student classroom[3] = {
        {"Emma", 18, 'A'},
        {"David", 19, 'B'},
        {"Sarah", 20, 'A'}
    };
    
    cout << "Class List:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Student " << (i + 1) << ": " << classroom[i].name 
             << ", Age: " << classroom[i].age 
             << ", Grade: " << classroom[i].grade << endl;
    }
    
    // Count A grades
    int aGrades = 0;
    for (int i = 0; i < 3; i++) {
        if (classroom[i].grade == 'A') {
            aGrades++;
        }
    }
    cout << "Students with A grade: " << aGrades << endl;
    
    /*
     * SECTION 7: Comparing Students
     */
    
    cout << "\n=== Comparing Students ===" << endl;
    
    if (student1.age > student2.age) {
        cout << student1.name << " is older than " << student2.name << endl;
    } else if (student1.age < student2.age) {
        cout << student2.name << " is older than " << student1.name << endl;
    } else {
        cout << "Both students are the same age" << endl;
    }
    
    if (student1.grade == student2.grade) {
        cout << "Both students have the same grade" << endl;
    } else {
        cout << "Students have different grades" << endl;
    }
    
    /*
     * SECTION 8: Getting User Input for Structures
     */
    
    cout << "\n=== Creating New Student ===" << endl;
    
    Student newStudent;
    cout << "Enter student name: ";
    cin >> newStudent.name;
    cout << "Enter student age: ";
    cin >> newStudent.age;
    cout << "Enter student grade (A, B, C, etc.): ";
    cin >> newStudent.grade;
    
    cout << "\nNew student created:" << endl;
    cout << "Name: " << newStudent.name << endl;
    cout << "Age: " << newStudent.age << endl;
    cout << "Grade: " << newStudent.grade << endl;
    
    /*
     * PRACTICE EXERCISES FOR BEGINNERS:
     */
    
    cout << "\n=== Practice Exercises ===" << endl;
    cout << "Try these exercises on your own:" << endl;
    cout << "1. Create a Car structure with make, model, and year" << endl;
    cout << "2. Make an array of 5 cars and display them" << endl;
    cout << "3. Create a Person structure with name and age" << endl;
    cout << "4. Find the oldest person in an array of people" << endl;
    cout << "5. Create a simple address book using structures" << endl;
    
    return 0;
}

/*
 * SIMPLE STRUCTURE CONCEPTS FOR BEGINNERS:
 * 
 * 1. WHAT ARE STRUCTURES:
 *    - A way to group related information together
 *    - Like a container that holds different types of data
 *    - Example: Student has name, age, and grade
 * 
 * 2. CREATING STRUCTURES:
 *    - Define the structure: struct Student { ... };
 *    - Create variables: Student student1;
 *    - Assign values: student1.name = "Alice";
 * 
 * 3. ACCESSING DATA:
 *    - Use dot notation: student1.name
 *    - Can read: cout << student1.name;
 *    - Can modify: student1.age = 20;
 * 
 * 4. ARRAYS OF STRUCTURES:
 *    - Student classroom[10]; - Array of 10 students
 *    - Access: classroom[0].name
 *    - Use loops to process multiple structures
 * 
 * 5. WHY USE STRUCTURES:
 *    - Organize related data together
 *    - Make code easier to understand
 *    - Reduce the number of separate variables
 *    - Foundation for more advanced concepts
 * 
 * BEGINNER TIPS:
 * - Start with simple structures (2-3 members)
 * - Use meaningful names for structures and members
 * - Practice with real-world examples (students, books, cars)
 * - Always initialize your structures
 * - Use structures when you have related data
 * 
 * PRACTICE IDEAS:
 * - Create a structure for your favorite movie
 * - Make a simple contact book
 * - Store information about your pets
 * - Create a structure for school subjects
 * - Practice with arrays of structures
 */
