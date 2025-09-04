/*
 * Day 4: Basic Arrays in C++
 * This file demonstrates array fundamentals and basic operations
 * Arrays allow storing multiple values of the same type
 */

#include <iostream>
#include <algorithm>  // For sort function

using namespace std;

int main() {
    cout << "=== Basic Arrays in C++ ===" << endl;
    
    /*
     * SECTION 1: Array Declaration and Initialization
     * Different ways to create and initialize arrays
     */
    
    cout << "\n=== Array Declaration and Initialization ===" << endl;
    
    // Method 1: Declare then assign
    int numbers[5];
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;
    
    // Method 2: Initialize during declaration
    int scores[] = {85, 92, 78, 96, 88};  // Size automatically determined
    
    // Method 3: Declare with size and initialize
    int grades[5] = {90, 85, 92, 78, 96};
    
    // Method 4: Partial initialization (rest filled with 0)
    int values[5] = {1, 2};  // values = {1, 2, 0, 0, 0}
    
    cout << "Arrays created successfully!" << endl;
    
    /*
     * SECTION 2: Array Traversal and Display
     * Using loops to access all elements
     */
    
    cout << "\n=== Array Traversal ===" << endl;
    
    // Display numbers array
    cout << "Numbers array: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // Display scores array using sizeof to get length
    cout << "Scores array: ";
    int scoresSize = sizeof(scores) / sizeof(scores[0]);
    for (int i = 0; i < scoresSize; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;
    
    // Using range-based for loop (C++11 feature)
    cout << "Grades array (range-based loop): ";
    for (int grade : grades) {
        cout << grade << " ";
    }
    cout << endl;
    
    /*
     * SECTION 3: Array Input from User
     * Getting array values from user input
     */
    
    cout << "\n=== Array Input ===" << endl;
    
    const int SIZE = 3;
    int userNumbers[SIZE];
    
    cout << "Enter " << SIZE << " numbers:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Number " << (i + 1) << ": ";
        cin >> userNumbers[i];
    }
    
    cout << "You entered: ";
    for (int i = 0; i < SIZE; i++) {
        cout << userNumbers[i] << " ";
    }
    cout << endl;
    
    /*
     * SECTION 4: Array Operations - Finding Maximum and Minimum
     */
    
    cout << "\n=== Finding Max and Min ===" << endl;
    
    int testArray[] = {64, 34, 25, 12, 22, 11, 90};
    int arraySize = sizeof(testArray) / sizeof(testArray[0]);
    
    int maximum = testArray[0];
    int minimum = testArray[0];
    int maxIndex = 0, minIndex = 0;
    
    for (int i = 1; i < arraySize; i++) {
        if (testArray[i] > maximum) {
            maximum = testArray[i];
            maxIndex = i;
        }
        if (testArray[i] < minimum) {
            minimum = testArray[i];
            minIndex = i;
        }
    }
    
    cout << "Array: ";
    for (int i = 0; i < arraySize; i++) {
        cout << testArray[i] << " ";
    }
    cout << endl;
    cout << "Maximum: " << maximum << " at index " << maxIndex << endl;
    cout << "Minimum: " << minimum << " at index " << minIndex << endl;
    
    /*
     * SECTION 5: Array Operations - Sum and Average
     */
    
    cout << "\n=== Sum and Average ===" << endl;
    
    int sum = 0;
    for (int i = 0; i < arraySize; i++) {
        sum += testArray[i];
    }
    
    double average = (double)sum / arraySize;
    
    cout << "Sum of all elements: " << sum << endl;
    cout << "Average: " << average << endl;
    
    /*
     * SECTION 6: Array Searching
     * Linear search to find an element
     */
    
    cout << "\n=== Array Searching ===" << endl;
    
    int searchValue = 25;
    int foundIndex = -1;
    
    for (int i = 0; i < arraySize; i++) {
        if (testArray[i] == searchValue) {
            foundIndex = i;
            break;
        }
    }
    
    if (foundIndex != -1) {
        cout << "Value " << searchValue << " found at index " << foundIndex << endl;
    } else {
        cout << "Value " << searchValue << " not found in array" << endl;
    }
    
    /*
     * SECTION 7: Array Reversal
     * Reversing array elements in place
     */
    
    cout << "\n=== Array Reversal ===" << endl;
    
    int reverseArray[] = {1, 2, 3, 4, 5};
    int revSize = sizeof(reverseArray) / sizeof(reverseArray[0]);
    
    cout << "Original array: ";
    for (int i = 0; i < revSize; i++) {
        cout << reverseArray[i] << " ";
    }
    cout << endl;
    
    // Reverse the array
    for (int i = 0; i < revSize / 2; i++) {
        int temp = reverseArray[i];
        reverseArray[i] = reverseArray[revSize - 1 - i];
        reverseArray[revSize - 1 - i] = temp;
    }
    
    cout << "Reversed array: ";
    for (int i = 0; i < revSize; i++) {
        cout << reverseArray[i] << " ";
    }
    cout << endl;
    
    /*
     * SECTION 8: Array Sorting
     * Using built-in sort function
     */
    
    cout << "\n=== Array Sorting ===" << endl;
    
    int sortArray[] = {64, 34, 25, 12, 22, 11, 90};
    int sortSize = sizeof(sortArray) / sizeof(sortArray[0]);
    
    cout << "Before sorting: ";
    for (int i = 0; i < sortSize; i++) {
        cout << sortArray[i] << " ";
    }
    cout << endl;
    
    sort(sortArray, sortArray + sortSize);
    
    cout << "After sorting: ";
    for (int i = 0; i < sortSize; i++) {
        cout << sortArray[i] << " ";
    }
    cout << endl;
    
    /*
     * SECTION 9: Array Copying
     * Copying elements from one array to another
     */
    
    cout << "\n=== Array Copying ===" << endl;
    
    int source[] = {10, 20, 30, 40, 50};
    int destination[5];
    int copySize = 5;
    
    // Copy elements
    for (int i = 0; i < copySize; i++) {
        destination[i] = source[i];
    }
    
    cout << "Source array: ";
    for (int i = 0; i < copySize; i++) {
        cout << source[i] << " ";
    }
    cout << endl;
    
    cout << "Destination array: ";
    for (int i = 0; i < copySize; i++) {
        cout << destination[i] << " ";
    }
    cout << endl;
    
    /*
     * SECTION 10: Array Statistics
     * Computing various statistics
     */
    
    cout << "\n=== Array Statistics ===" << endl;
    
    int data[] = {15, 23, 8, 42, 16, 4, 35, 19};
    int dataSize = sizeof(data) / sizeof(data[0]);
    
    // Count even and odd numbers
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < dataSize; i++) {
        if (data[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
    
    cout << "Data: ";
    for (int i = 0; i < dataSize; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    cout << "Even numbers: " << evenCount << endl;
    cout << "Odd numbers: " << oddCount << endl;
    
    // Find second largest
    sort(data, data + dataSize);
    cout << "Second largest: " << data[dataSize - 2] << endl;
    
    cout << "\n=== Basic Arrays Complete! ===" << endl;
    
    return 0;
}

/*
 * KEY ARRAY CONCEPTS:
 * 
 * 1. ARRAY DECLARATION:
 *    - Fixed size: int arr[10];
 *    - With initialization: int arr[] = {1,2,3};
 *    - Partial initialization: int arr[5] = {1,2}; // rest are 0
 * 
 * 2. ARRAY INDEXING:
 *    - Zero-based: first element is arr[0]
 *    - Last element is arr[size-1]
 *    - Bounds checking is programmer's responsibility
 * 
 * 3. ARRAY SIZE:
 *    - Fixed at compile time
 *    - Get size: sizeof(arr) / sizeof(arr[0])
 *    - Size must be constant expression
 * 
 * 4. ARRAY TRAVERSAL:
 *    - for loop: for(int i = 0; i < size; i++)
 *    - Range-based: for(int element : array)
 *    - While loop: while(index < size)
 * 
 * 5. COMMON OPERATIONS:
 *    - Search: Linear search through elements
 *    - Sort: Arrange in ascending/descending order
 *    - Reverse: Swap elements from ends
 *    - Copy: Transfer elements to another array
 * 
 * 6. ARRAY LIMITATIONS:
 *    - Fixed size (can't grow/shrink)
 *    - No bounds checking
 *    - Passed by reference to functions
 *    - No built-in size information
 * 
 * BEST PRACTICES:
 * - Always initialize arrays
 * - Check bounds before accessing
 * - Use const for array size
 * - Use meaningful variable names
 * - Consider using std::vector for dynamic arrays
 * 
 * COMMON MISTAKES:
 * - Array index out of bounds
 * - Forgetting array is 0-based
 * - Not initializing array elements
 * - Assuming array knows its size
 */
