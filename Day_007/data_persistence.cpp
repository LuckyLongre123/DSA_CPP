/*
 * Day 7: Data Persistence Project
 * This file demonstrates saving and loading program data using files
 * Practical example of file I/O for maintaining application state
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Student {
    string name;
    int age;
    double gpa;
    string major;
};

// Function to save students to file
void saveStudents(const vector<Student>& students, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Could not open file for writing: " + filename);
    }
    
    for (const Student& student : students) {
        file << student.name << "," << student.age << "," 
             << student.gpa << "," << student.major << endl;
    }
    
    file.close();
    cout << "Saved " << students.size() << " students to " << filename << endl;
}

// Function to load students from file
vector<Student> loadStudents(const string& filename) {
    vector<Student> students;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "File " << filename << " not found. Starting with empty list." << endl;
        return students;
    }
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, major, ageStr, gpaStr;
        
        if (getline(ss, name, ',') &&
            getline(ss, ageStr, ',') &&
            getline(ss, gpaStr, ',') &&
            getline(ss, major)) {
            
            Student student;
            student.name = name;
            student.age = stoi(ageStr);
            student.gpa = stod(gpaStr);
            student.major = major;
            
            students.push_back(student);
        }
    }
    
    file.close();
    cout << "Loaded " << students.size() << " students from " << filename << endl;
    return students;
}

// Function to display all students
void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students in database." << endl;
        return;
    }
    
    cout << "\n=== Student Database ===" << endl;
    for (size_t i = 0; i < students.size(); i++) {
        cout << (i + 1) << ". " << students[i].name 
             << " (Age: " << students[i].age 
             << ", GPA: " << students[i].gpa 
             << ", Major: " << students[i].major << ")" << endl;
    }
}

// Function to add new student
void addStudent(vector<Student>& students) {
    Student newStudent;
    
    cout << "\n=== Add New Student ===" << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    cout << "Age: ";
    cin >> newStudent.age;
    cout << "GPA: ";
    cin >> newStudent.gpa;
    cout << "Major: ";
    cin.ignore();
    getline(cin, newStudent.major);
    
    students.push_back(newStudent);
    cout << "Student added successfully!" << endl;
}

int main() {
    cout << "=== Student Database with Data Persistence ===" << endl;
    
    const string filename = "students.txt";
    vector<Student> students;
    
    try {
        // Load existing data
        students = loadStudents(filename);
        
        int choice;
        do {
            cout << "\n=== Main Menu ===" << endl;
            cout << "1. Display all students" << endl;
            cout << "2. Add new student" << endl;
            cout << "3. Save and exit" << endl;
            cout << "4. Exit without saving" << endl;
            cout << "Choice: ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    displayStudents(students);
                    break;
                    
                case 2:
                    addStudent(students);
                    break;
                    
                case 3:
                    saveStudents(students, filename);
                    cout << "Data saved. Goodbye!" << endl;
                    break;
                    
                case 4:
                    cout << "Exiting without saving. Goodbye!" << endl;
                    break;
                    
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
            
        } while (choice != 3 && choice != 4);
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}

/*
 * DATA PERSISTENCE CONCEPTS:
 * 
 * 1. FILE FORMAT DESIGN:
 *    - CSV format for structured data
 *    - Delimiter-separated values
 *    - One record per line
 *    - Consider escape characters for special data
 * 
 * 2. SERIALIZATION:
 *    - Converting objects to file format
 *    - Handling different data types
 *    - Maintaining data integrity
 * 
 * 3. DESERIALIZATION:
 *    - Reading file format back to objects
 *    - Error handling for corrupted data
 *    - Validation of loaded data
 * 
 * 4. APPLICATION STATE:
 *    - Save program state between runs
 *    - User preferences and settings
 *    - Application data and records
 * 
 * BEST PRACTICES:
 * - Always validate loaded data
 * - Handle file corruption gracefully
 * - Provide backup/recovery options
 * - Use appropriate file formats
 * - Consider data versioning for updates
 */
