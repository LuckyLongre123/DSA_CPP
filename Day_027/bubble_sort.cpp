/*
 * BUBBLE SORT ALGORITHM
 * 
 * Problem: Sort an array in ascending order using bubble sort technique
 * 
 * Algorithm Explanation:
 * Bubble Sort is a simple sorting algorithm that repeatedly steps through the list,
 * compares adjacent elements and swaps them if they are in the wrong order.
 * The pass through the list is repeated until the list is sorted.
 * 
 * How it works:
 * 1. Compare adjacent elements in the array
 * 2. If the first element is greater than the second, swap them
 * 3. Continue this process for the entire array
 * 4. After each pass, the largest element "bubbles up" to its correct position
 * 5. Repeat until no swaps are needed (array is sorted)
 * 
 * Optimization: Use a flag to detect if any swaps occurred in a pass.
 * If no swaps occur, the array is already sorted and we can terminate early.
 * 
 * Time Complexity: 
 * - Best Case: O(n) - when array is already sorted
 * - Average Case: O(n²)
 * - Worst Case: O(n²) - when array is sorted in reverse order
 * 
 * Space Complexity: O(1) - only uses constant extra space
 * 
 * Example:
 * Input: [64, 34, 25, 12, 22, 11, 90]
 * Pass 1: [34, 25, 12, 22, 11, 64, 90] (90 bubbles to end)
 * Pass 2: [25, 12, 22, 11, 34, 64, 90] (64 bubbles to position)
 * Continue until sorted: [11, 12, 22, 25, 34, 64, 90]
 */

#include <vector>
using namespace std;

class Solution
{
public:
    void bubbleSort(vector<int> &arr, int n)
    {
        // Outer loop for number of passes
        // We need at most n-1 passes to sort n elements
        for (int i = 0; i < n - 1; i++)
        {
            // Flag to optimize: if no swaps occur, array is sorted
            bool flag = false;
            
            // Inner loop for comparisons in each pass
            // After i passes, last i elements are already in place
            // So we only need to check first (n-i-1) elements
            for (int j = 0; j < n - i - 1; j++)
            {
                // Compare adjacent elements
                if (arr[j] > arr[j + 1])
                {
                    // Swap if they are in wrong order
                    swap(arr[j], arr[j + 1]);
                    flag = true; // Mark that a swap occurred
                }
            }
            
            // If no swapping occurred, array is already sorted
            if (flag == false)
                break;
        }
    }
};