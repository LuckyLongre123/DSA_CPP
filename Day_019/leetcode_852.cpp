/**
 * ================================================================================
 * LeetCode 852:Peak Index in Mountain Array - Binary Search Application
 * ================================================================================
 * 
 * ! Problem: Given a mountain array `arr`, return the index `i` such that:
 * ! - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 * ! - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 * ! Guaranteed to have exactly one peak element.
 * 
 * * Approach:
 * * 1. Use binary search to efficiently find the peak
 * * 2. Compare middle element with its right neighbor
 * * 3. If arr[mid] < arr[mid+1], peak is on the right side
 * * 4. Otherwise, peak is on the left side (including mid)
 * * 5. Converge search space until finding the peak
 * 
 * ? Time Complexity: O(log n) - Binary search halves the search space each iteration
 * ? Space Complexity: O(1) - Constant extra space used
 * 
 * TODO Key Insight: 
 * *    - Mountain array guarantees existence of exactly one peak
 * *    - Binary search is optimal because array is partially sorted
 * *    - No need to check both neighbors - one comparison determines direction
 * 
 * * Optimizations: 
 * *    - Logarithmic time complexity instead of linear O(n) scan
 * *    - Early convergence when search space narrows to single element
 * ================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    /**
     * Finds the peak index in a mountain array using binary search
     * @param arr The mountain array to search
     * @return The index of the peak element
     */
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;             // * Left boundary of search space
        int end = arr.size() - 1;  // * Right boundary of search space
         
        while (start < end) {
            int mid = start + (end - start) / 2;  // * Calculate middle index (prevents overflow)
             
            // ? Compare mid with its right neighbor to determine which side has the peak
            if (arr[mid] < arr[mid + 1]) {
                // *Peak is on the right side (ascending slope)
                start = mid + 1;  // ! Move left boundary right, excluding mid
            } else {
                // *Peak is on the left side or at mid (descending slope)
                end = mid;  // ! Move right boundary to mid, keeping it in search space
            }
        }
         
        // * When start == end, we've found the peak
        return start;
    }
};
 
// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================
 
/**
 * Helper function to print test result
 */
void printTestResult(vector<int>& arr, int result, int expected) {
    cout << "\nArray: [";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]\n";
    cout << "   Result:   " << result << " (value: " << arr[result] << ")\n";
    cout << "   Expected: " << expected << " (value: " << arr[expected] << ")\n";
    cout << "   Status:   " << (result == expected ? "PASS" : "FAIL");
    if (result != expected) {
        cout << " (Expected index: " << expected << ")";
    }
    cout << "\n";
}
 
int main() {
    Solution solution;
     
    // * Test Case 1: Small mountain
    {
        vector<int> arr = {0, 1, 0};
        int result = solution.peakIndexInMountainArray(arr);
        printTestResult(arr, result, 1);
    }
     
    // * Test Case 2: Larger mountain
    {
        vector<int> arr = {0, 2, 1, 0};
        int result = solution.peakIndexInMountainArray(arr);
        printTestResult(arr, result, 1);
    }
     
    // * Test Case 3:Peak near the end
    {
        vector<int> arr = {0, 10, 5, 2};
        int result = solution.peakIndexInMountainArray(arr);
        printTestResult(arr, result, 1);
    }
     
    // * Test Case 4: Multiple elements ascending then descending
    {
        vector<int> arr = {3, 4, 5, 1};
        int result = solution.peakIndexInMountainArray(arr);
        printTestResult(arr, result, 2);
    }
     
    // * Test Case 5: Large mountain array
    {
        vector<int> arr = {0, 1, 2, 4, 8, 9, 10, 7, 5, 3, 2, 1};
        int result = solution.peakIndexInMountainArray(arr);
        printTestResult(arr, result, 6);
    }
     
    // * Test Case 6:Peak at second position
    {
        vector<int> arr = {1, 5, 3};
        int result = solution.peakIndexInMountainArray(arr);
        printTestResult(arr, result, 1);
    }
     
    // * Test Case 7: Gradual ascent, sharp descent
    {
        vector<int> arr = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
        int result = solution.peakIndexInMountainArray(arr);
        printTestResult(arr, result, 2);
    }
     
    // * Test Case 8: Sharp ascent, gradual descent
    {
        vector<int> arr = {10, 20, 30, 29, 28, 27, 26, 25};
        int result = solution.peakIndexInMountainArray(arr);
        printTestResult(arr, result, 2);
    }
     
    return 0;
}
 
/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The binary search approach is optimal for mountain arrays
 * ! - The key insight is using the comparison with right neighbor to guide search
 * * - Time complexity O(log n) is much better than linear scan O(n)
 * ? - This pattern works for any unimodal function (single peak)
 * * - The algorithm is guaranteed to converge because peak existence is guaranteed
 * ================================================================================
 */