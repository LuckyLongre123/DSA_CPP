/*
 * Day 6: Vectors in C++
 * This file demonstrates the vector container from STL
 * Vectors are dynamic arrays that can grow and shrink automatically
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cout << "=== Vectors in C++ ===" << endl;
    
    /*
     * SECTION 1: Vector Declaration and Initialization
     */
    
    cout << "\n=== Vector Declaration ===" << endl;
    
    // Method 1: Empty vector
    vector<int> numbers;
    
    // Method 2: Vector with initial size
    vector<int> scores(5);  // 5 elements, all initialized to 0
    
    // Method 3: Vector with size and initial value
    vector<int> grades(5, 100);  // 5 elements, all set to 100
    
    // Method 4: Initialize with values
    vector<int> data = {10, 20, 30, 40, 50};
    
    // Method 5: Copy from another vector
    vector<int> copy = data;
    
    cout << "Vectors created successfully!" << endl;
    
    /*
     * SECTION 2: Basic Vector Operations
     */
    
    cout << "\n=== Basic Vector Operations ===" << endl;
    
    // Check if vector is empty
    cout << "numbers vector is empty: " << (numbers.empty() ? "true" : "false") << endl;
    cout << "data vector is empty: " << (data.empty() ? "true" : "false") << endl;
    
    // Get vector size
    cout << "data vector size: " << data.size() << endl;
    cout << "grades vector size: " << grades.size() << endl;
    
    // Display vector contents
    cout << "data vector contents: ";
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    
    /*
     * SECTION 3: Adding Elements to Vector
     */
    
    cout << "\n=== Adding Elements ===" << endl;
    
    // Add elements to empty vector
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    
    cout << "After adding elements to numbers: ";
    for (int num : numbers) {  // Range-based for loop
        cout << num << " ";
    }
    cout << endl;
    
    // Add multiple elements
    for (int i = 4; i <= 10; i++) {
        numbers.push_back(i);
    }
    
    cout << "After adding more elements: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Vector size is now: " << numbers.size() << endl;
    
    /*
     * SECTION 4: Accessing Vector Elements
     */
    
    cout << "\n=== Accessing Elements ===" << endl;
    
    // Using [] operator
    cout << "First element (using []): " << data[0] << endl;
    cout << "Last element (using []): " << data[data.size() - 1] << endl;
    
    // Using at() method (safer - throws exception if out of bounds)
    cout << "Second element (using at()): " << data.at(1) << endl;
    
    // Using front() and back()
    cout << "First element (using front()): " << data.front() << endl;
    cout << "Last element (using back()): " << data.back() << endl;
    
    // Modifying elements
    data[0] = 100;
    data.at(1) = 200;
    
    cout << "After modification: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;
    
    /*
     * SECTION 5: Removing Elements
     */
    
    cout << "\n=== Removing Elements ===" << endl;
    
    vector<int> testVector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << "Original vector: ";
    for (int num : testVector) {
        cout << num << " ";
    }
    cout << endl;
    
    // Remove last element
    testVector.pop_back();
    cout << "After pop_back(): ";
    for (int num : testVector) {
        cout << num << " ";
    }
    cout << endl;
    
    // Remove multiple elements from the end
    testVector.pop_back();
    testVector.pop_back();
    cout << "After removing 2 more: ";
    for (int num : testVector) {
        cout << num << " ";
    }
    cout << endl;
    
    /*
     * SECTION 6: Vector Capacity and Memory
     */
    
    cout << "\n=== Vector Capacity ===" << endl;
    
    vector<int> capacityTest;
    
    cout << "Initial capacity: " << capacityTest.capacity() << endl;
    cout << "Initial size: " << capacityTest.size() << endl;
    
    // Add elements and observe capacity changes
    for (int i = 1; i <= 10; i++) {
        capacityTest.push_back(i);
        cout << "Size: " << capacityTest.size() 
             << ", Capacity: " << capacityTest.capacity() << endl;
    }
    
    /*
     * SECTION 7: Vector Input from User
     */
    
    cout << "\n=== Vector Input ===" << endl;
    
    vector<int> userNumbers;
    int count;
    
    cout << "How many numbers do you want to enter? ";
    cin >> count;
    
    cout << "Enter " << count << " numbers:" << endl;
    for (int i = 0; i < count; i++) {
        int num;
        cout << "Number " << (i + 1) << ": ";
        cin >> num;
        userNumbers.push_back(num);
    }
    
    cout << "You entered: ";
    for (int num : userNumbers) {
        cout << num << " ";
    }
    cout << endl;
    
    /*
     * SECTION 8: Vector Algorithms
     */
    
    cout << "\n=== Vector Algorithms ===" << endl;
    
    vector<int> algorithmTest = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Original vector: ";
    for (int num : algorithmTest) {
        cout << num << " ";
    }
    cout << endl;
    
    // Sort the vector
    sort(algorithmTest.begin(), algorithmTest.end());
    cout << "After sorting: ";
    for (int num : algorithmTest) {
        cout << num << " ";
    }
    cout << endl;
    
    // Find an element
    int searchValue = 25;
    auto it = find(algorithmTest.begin(), algorithmTest.end(), searchValue);
    if (it != algorithmTest.end()) {
        int index = distance(algorithmTest.begin(), it);
        cout << "Found " << searchValue << " at index " << index << endl;
    } else {
        cout << searchValue << " not found" << endl;
    }
    
    /*
     * SECTION 9: Vector of Different Data Types
     */
    
    cout << "\n=== Different Data Types ===" << endl;
    
    // Vector of strings
    vector<string> names = {"Alice", "Bob", "Charlie", "Diana"};
    cout << "Names: ";
    for (const string& name : names) {
        cout << name << " ";
    }
    cout << endl;
    
    // Vector of doubles
    vector<double> prices = {19.99, 25.50, 12.75, 8.25};
    cout << "Prices: $";
    for (double price : prices) {
        cout << price << " ";
    }
    cout << endl;
    
    // Vector of booleans
    vector<bool> flags = {true, false, true, true, false};
    cout << "Flags: ";
    for (bool flag : flags) {
        cout << (flag ? "T" : "F") << " ";
    }
    cout << endl;
    
    /*
     * SECTION 10: Vector Statistics
     */
    
    cout << "\n=== Vector Statistics ===" << endl;
    
    vector<int> stats = {85, 92, 78, 96, 88, 73, 91, 87};
    
    cout << "Data: ";
    for (int value : stats) {
        cout << value << " ";
    }
    cout << endl;
    
    // Calculate sum
    int sum = 0;
    for (int value : stats) {
        sum += value;
    }
    cout << "Sum: " << sum << endl;
    cout << "Average: " << (double)sum / stats.size() << endl;
    
    // Find min and max
    auto minIt = min_element(stats.begin(), stats.end());
    auto maxIt = max_element(stats.begin(), stats.end());
    
    cout << "Minimum: " << *minIt << endl;
    cout << "Maximum: " << *maxIt << endl;
    
    // Count elements greater than average
    double average = (double)sum / stats.size();
    int aboveAverage = 0;
    for (int value : stats) {
        if (value > average) {
            aboveAverage++;
        }
    }
    cout << "Elements above average: " << aboveAverage << endl;
    
    /*
     * SECTION 11: Vector Insertion and Deletion
     */
    
    cout << "\n=== Advanced Operations ===" << endl;
    
    vector<int> advanced = {1, 2, 4, 5};
    
    cout << "Before insertion: ";
    for (int num : advanced) {
        cout << num << " ";
    }
    cout << endl;
    
    // Insert element at specific position
    advanced.insert(advanced.begin() + 2, 3);  // Insert 3 at index 2
    
    cout << "After inserting 3: ";
    for (int num : advanced) {
        cout << num << " ";
    }
    cout << endl;
    
    // Erase element at specific position
    advanced.erase(advanced.begin() + 1);  // Remove element at index 1
    
    cout << "After erasing index 1: ";
    for (int num : advanced) {
        cout << num << " ";
    }
    cout << endl;
    
    // Clear all elements
    advanced.clear();
    cout << "After clear(), size: " << advanced.size() << endl;
    cout << "Is empty: " << (advanced.empty() ? "true" : "false") << endl;
    
    cout << "\n=== Vectors Complete! ===" << endl;
    
    return 0;
}

/*
 * VECTOR KEY CONCEPTS:
 * 
 * 1. VECTOR DECLARATION:
 *    - vector<type> name; // Empty vector
 *    - vector<type> name(size); // With initial size
 *    - vector<type> name(size, value); // Size with default value
 *    - vector<type> name = {val1, val2, ...}; // With initial values
 * 
 * 2. ADDING ELEMENTS:
 *    - push_back(value) // Add to end
 *    - insert(position, value) // Insert at specific position
 *    - emplace_back(args) // Construct element in place
 * 
 * 3. REMOVING ELEMENTS:
 *    - pop_back() // Remove last element
 *    - erase(position) // Remove at specific position
 *    - clear() // Remove all elements
 * 
 * 4. ACCESSING ELEMENTS:
 *    - vec[index] // Direct access (no bounds check)
 *    - vec.at(index) // Safe access (throws exception)
 *    - vec.front() // First element
 *    - vec.back() // Last element
 * 
 * 5. SIZE AND CAPACITY:
 *    - size() // Number of elements
 *    - capacity() // Allocated memory size
 *    - empty() // Check if empty
 *    - reserve(n) // Reserve memory for n elements
 * 
 * 6. ITERATING:
 *    - for(int i = 0; i < vec.size(); i++) // Index-based
 *    - for(auto element : vec) // Range-based
 *    - for(auto it = vec.begin(); it != vec.end(); ++it) // Iterator
 * 
 * 7. ALGORITHMS:
 *    - sort(vec.begin(), vec.end()) // Sort elements
 *    - find(vec.begin(), vec.end(), value) // Find element
 *    - min_element(), max_element() // Find min/max
 * 
 * ADVANTAGES OVER ARRAYS:
 * - Dynamic size (can grow/shrink)
 * - Automatic memory management
 * - Rich set of member functions
 * - STL algorithm compatibility
 * - Bounds checking with at()
 * - Exception safety
 * 
 * PERFORMANCE:
 * - Random access: O(1)
 * - Insert/delete at end: O(1) amortized
 * - Insert/delete at middle: O(n)
 * - Search: O(n) for unsorted, O(log n) for sorted
 * 
 * WHEN TO USE VECTORS:
 * - Need dynamic array
 * - Don't know size at compile time
 * - Want automatic memory management
 * - Need STL algorithm compatibility
 * - Want bounds checking option
 */
