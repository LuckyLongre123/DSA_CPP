/*
 * INSERTION SORT ALGORITHM
 * 
 * Problem: Sort an array in ascending order using insertion sort technique
 * 
 * Algorithm Explanation:
 * Insertion Sort builds the final sorted array one item at a time.
 * It works by taking elements from the unsorted portion and inserting
 * them into their correct position in the sorted portion.
 * 
 * How it works:
 * 1. Start with the second element (index 1) as the first element is considered sorted
 * 2. Compare the current element with elements in the sorted portion (to its left)
 * 3. Shift all larger elements one position to the right
 * 4. Insert the current element in its correct position
 * 5. Repeat for all remaining elements
 * 
 * Time Complexity:
 * - Best Case: O(n) - when array is already sorted
 * - Average Case: O(n²)
 * - Worst Case: O(n²) - when array is sorted in reverse order
 * 
 * Space Complexity: O(1) - only uses constant extra space
 * 
 * Example:
 * Input: [5, 2, 4, 6, 1, 3]
 * Step 1: [2, 5, 4, 6, 1, 3] (insert 2)
 * Step 2: [2, 4, 5, 6, 1, 3] (insert 4)
 * Step 3: [2, 4, 5, 6, 1, 3] (6 already in place)
 * Step 4: [1, 2, 4, 5, 6, 3] (insert 1)
 * Step 5: [1, 2, 3, 4, 5, 6] (insert 3)
 */

#include <vector>
using namespace std;

class Solution
{
public:
    void insertionSort(vector<int> &arr, int n)
    {
        // Start from the second element (index 1)
        // First element is considered already sorted
        for (int i = 1; i < n; i++)
        {
            // Store the current element to be inserted
            int temp = arr[i];
            
            // Start comparing with the element just before current
            int j = i - 1;
            
            // Move elements that are greater than temp one position ahead
            // Continue until we find the correct position for temp
            while (j >= 0 && arr[j] > temp)
            {
                arr[j + 1] = arr[j]; // Shift element to right
                j--; // Move to the previous element
            }
            
            // Insert the current element at its correct position
            arr[j + 1] = temp;
        }
    }
};