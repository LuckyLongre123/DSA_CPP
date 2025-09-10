/*
 * SELECTION SORT ALGORITHM
 * 
 * Problem: Sort an array in ascending order using selection sort technique
 * 
 * Algorithm Explanation:
 * Selection Sort divides the array into sorted and unsorted portions.
 * It repeatedly finds the minimum element from the unsorted portion
 * and places it at the beginning of the unsorted portion.
 * 
 * How it works:
 * 1. Find the minimum element in the entire array
 * 2. Swap it with the first element
 * 3. Find the minimum element in the remaining unsorted array
 * 4. Swap it with the first element of the unsorted portion
 * 5. Repeat until the entire array is sorted
 * 
 * Time Complexity:
 * - Best Case: O(n²) - always performs the same number of comparisons
 * - Average Case: O(n²)
 * - Worst Case: O(n²)
 * 
 * Space Complexity: O(1) - only uses constant extra space
 * 
 * Example:
 * Input: [64, 25, 12, 22, 11]
 * Step 1: [11, 25, 12, 22, 64] (11 is minimum, swap with first)
 * Step 2: [11, 12, 25, 22, 64] (12 is minimum in remaining, swap with second)
 * Step 3: [11, 12, 22, 25, 64] (22 is minimum in remaining, swap with third)
 * Step 4: [11, 12, 22, 25, 64] (25 is minimum in remaining, already in place)
 * Result: [11, 12, 22, 25, 64]
 */

#include <vector>
using namespace std;

class Solution
{
public:
    void selectionSort(vector<int> &arr, int n)
    {
        // Traverse through all array elements
        for (int i = 0; i < n - 1; i++)
        {
            // Find the minimum element in the remaining unsorted array
            int minIndex = i; // Assume current element is minimum
            
            // Check all elements from i+1 to n-1
            for (int j = i + 1; j < n; j++)
            {
                // If we find a smaller element, update minIndex
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
            
            // Swap the found minimum element with the first element
            // of the unsorted portion (at index i)
            swap(arr[minIndex], arr[i]);
        }
    }
};