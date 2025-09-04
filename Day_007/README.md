# Day 7: File I/O & Exception Handling

## 🎯 Learning Objectives
- Learn to read from and write to files
- Understand different file modes and operations
- Master exception handling with try-catch blocks
- Practice error handling and program robustness
- Combine file operations with data structures

## 📚 Topics Covered

### 1. File Stream Basics
- **ifstream**: Input file stream for reading
- **ofstream**: Output file stream for writing
- **fstream**: Bidirectional file stream
- **File Modes**: ios::in, ios::out, ios::app, ios::binary

### 2. File Operations
- **Opening Files**: Using constructor or open() method
- **Reading Data**: Using >>, getline(), read()
- **Writing Data**: Using <<, write()
- **Closing Files**: Automatic or explicit close()

### 3. Exception Handling
- **try-catch Blocks**: Handling runtime errors
- **Exception Types**: Standard exceptions
- **throw Statement**: Creating custom exceptions
- **Exception Safety**: Writing robust code

### 4. Error Handling
- **File Errors**: Checking if file operations succeed
- **Input Validation**: Handling invalid user input
- **Resource Management**: Ensuring proper cleanup
- **Graceful Degradation**: Continuing when possible

## 💻 Practice Files
- `file_basic.cpp` - Basic file reading and writing
- `file_advanced.cpp` - Advanced file operations and modes
- `exception_handling.cpp` - Try-catch blocks and error handling
- `data_persistence.cpp` - Saving and loading program data
- `robust_programs.cpp` - Building error-resistant applications

## 🔥 Mini Challenges
1. Create a program that saves user data to a file
2. Build a simple text file analyzer
3. Implement a basic logging system
4. Create a student grade file manager
5. Build a configuration file reader/writer

## 📖 Key Concepts to Remember
- Always check if file operations succeed
- Use appropriate file modes for your needs
- Handle exceptions to prevent crashes
- Close files properly (or use RAII)
- Validate all input data

## 🚀 Next Day Preview
Tomorrow we'll explore classes and objects - the foundation of object-oriented programming!
