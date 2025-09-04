/*
 * Day 4: Simple Array Practice for Beginners
 * This file demonstrates basic array operations that are easy to understand
 * Focus on fundamental array concepts without complexity
 */

#include <iostream>

using namespace std;

int main() {
    cout << "=== Simple Array Practice ===" << endl;
    
    /*
     * SECTION 1: Basic Array Operations Practice
     * Simple exercises to understand arrays better
     */
    
    cout << "\n=== Array Practice Exercises ===" << endl;
    
    // Exercise 1: Create and display an array
    int numbers[5] = {10, 20, 30, 40, 50};
    
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // Exercise 2: Find sum of array elements
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
    }
    cout << "Sum of array elements: " << sum << endl;
    
    // Exercise 3: Count even and odd numbers
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < 5; i++) {
        if (numbers[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
    cout << "Even numbers: " << evenCount << ", Odd numbers: " << oddCount << endl;
    
    /*
     * SECTION 2: Array Input and Processing
     * Getting array values from user and processing them
     */
    
    cout << "\n=== Array Input Practice ===" << endl;
    
    // Exercise 4: Get array from user
    int userArray[3];
    cout << "Enter 3 numbers: ";
    for (int i = 0; i < 3; i++) {
        cin >> userArray[i];
    }
    
    cout << "You entered: ";
    for (int i = 0; i < 3; i++) {
        cout << userArray[i] << " ";
    }
    cout << endl;
    
    // Exercise 5: Find largest number in user array
    int largest = userArray[0];
    for (int i = 1; i < 3; i++) {
        if (userArray[i] > largest) {
            largest = userArray[i];
        }
    }
    cout << "Largest number: " << largest << endl;
    
    /*
     * SECTION 3: Simple Array Search
     * Finding elements in an array
     */
    
    cout << "\n=== Array Search Practice ===" << endl;
    
    // Exercise 6: Search for a number in array
    int searchArray[6] = {5, 12, 8, 3, 15, 7};
    int searchNumber = 8;
    bool found = false;
    int position = -1;
    
    cout << "Array: ";
    for (int i = 0; i < 6; i++) {
        cout << searchArray[i] << " ";
    }
    cout << endl;
    
    cout << "Searching for: " << searchNumber << endl;
    
    for (int i = 0; i < 6; i++) {
        if (searchArray[i] == searchNumber) {
            found = true;
            position = i;
            break;
        }
    }
    
    if (found) {
        cout << "Found " << searchNumber << " at position " << position << endl;
    } else {
        cout << searchNumber << " not found in array" << endl;
    }
    
    /*
     * SECTION 4: Array Copying
     * Copying elements from one array to another
     */
    
    cout << "\n=== Array Copying Practice ===" << endl;
    
    // Exercise 7: Copy array elements
    int originalArray[4] = {100, 200, 300, 400};
    int copiedArray[4];
    
    cout << "Original array: ";
    for (int i = 0; i < 4; i++) {
        cout << originalArray[i] << " ";
        copiedArray[i] = originalArray[i];  // Copy each element
    }
    cout << endl;
    
    cout << "Copied array: ";
    for (int i = 0; i < 4; i++) {
        cout << copiedArray[i] << " ";
    }
    cout << endl;
    
    /*
     * SECTION 5: Simple Array Statistics
     * Basic calculations with arrays
     */
    
    cout << "\n=== Array Statistics ===" << endl;
    
    // Exercise 8: Calculate average of array elements
    int grades[5] = {85, 92, 78, 96, 89};
    int total = 0;
    
    cout << "Student grades: ";
    for (int i = 0; i < 5; i++) {
        cout << grades[i] << " ";
        total += grades[i];
    }
    cout << endl;
    
    double average = (double)total / 5;
    cout << "Total: " << total << endl;
    cout << "Average: " << average << endl;
    
    // Exercise 9: Count grades above average
    int aboveAverage = 0;
    for (int i = 0; i < 5; i++) {
        if (grades[i] > average) {
            aboveAverage++;
        }
    }
    cout << "Grades above average: " << aboveAverage << endl;
    
    
    /*
     * PRACTICE EXERCISES FOR BEGINNERS:
     * Try these exercises to practice array concepts
     */
    
    cout << "\n=== Practice Exercises ===" << endl;
    cout << "Try these exercises on your own:" << endl;
    cout << "1. Create an array of 7 days and store temperatures" << endl;
    cout << "2. Find the day with highest temperature" << endl;
    cout << "3. Count how many days had temperature above 25°C" << endl;
    cout << "4. Create an array of your favorite numbers and sort them" << endl;
    cout << "5. Make a simple grade calculator using arrays" << endl;
    
    return 0;
}

/*
 * SIMPLE ARRAY CONCEPTS FOR BEGINNERS:
 * 
 * 1. ARRAY BASICS:
 *    - int arr[size]; - Creates array of fixed size
 *    - int arr[5] = {1, 2, 3, 4, 5}; - Initialize with values
 *    - Arrays store multiple values of same type
 * 
 * 2. ACCESSING ELEMENTS:
 *    - arr[0] - First element (index starts from 0)
 *    - arr[4] - Last element in array of size 5
 *    - Use index to read or write values
 * 
 * 3. LOOPS WITH ARRAYS:
 *    - for(int i = 0; i < size; i++) - Standard loop
 *    - Use loop to process all elements
 *    - i is the index, arr[i] is the element
 * 
 * 4. COMMON OPERATIONS:
 *    - Sum: Add all elements together
 *    - Search: Find if element exists
 *    - Max/Min: Find largest/smallest element
 *    - Count: Count elements meeting condition
 * 
 * 5. APPLICATIONS:
 *    - Store student grades
 *    - Keep track of temperatures
 *    - Store shopping list prices
 *    - Game scores
 * 
 * BEGINNER TIPS:
 * - Always initialize arrays before use
 * - Be careful with array bounds (0 to size-1)
 * - Use meaningful variable names
 * - Start with small arrays to practice
 * - Use cout to display array contents
 * 
 * PRACTICE MORE:
 * - Try different array sizes
 * - Practice with different data types
 * - Create simple programs using arrays
 * - Experiment with user input arrays
 */
