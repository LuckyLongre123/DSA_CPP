/**
 * ================================================================================
 * 🌀 LeetCode 852: Peak Index in a Mountain Array - Binary Search Solution
 * ================================================================================
 * 
 * 🎯 Problem: Given a mountain array `arr`, return the index of the peak element.
 * A mountain array is defined as an array that first increases and then decreases.
 * 
 * 📝 Approach: Modified Binary Search
 * 1. Use binary search to find the peak in O(log n) time
 * 2. At each step, compare middle element with its next element:
 *    - If arr[mid] < arr[mid+1], we're in the increasing part → search right
 *    - Else, we're in the decreasing part → search left (including mid)
 * 3. The loop breaks when start == end, which is the peak index
 * 
 * ⚡ Time Complexity: O(log n) - Each iteration halves the search space
 * 💾 Space Complexity: O(1) - Constant extra space used
 * 
 * 🧠 Key Insight: 
 *    - The peak is the first element where the sequence stops increasing
 *    - The array is guaranteed to be a mountain, so we don't need to handle invalid cases
 * 
 * 🚀 Optimizations: 
 *    - Single pass algorithm
 *    - No extra space required
 *    - Early termination when peak is found
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    //! MAIN FUNCTION: Finds the peak index in a mountain array
    //! @param arr The mountain array (guaranteed to be valid)
    //! @return The index of the peak element
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        //? Binary search to find the peak
        while (start < end) {
            int mid = start + (end - start) / 2;  // Prevents overflow

            if (arr[mid] < arr[mid + 1]) {
                //? We're in the increasing part, move right
                start = mid + 1;
            } else {
                //? We're in the decreasing part, move left (including mid)
                end = mid;
            }
        }

        //! At this point, start == end and it's the peak index
        return start;
    }
    
    //! ALTERNATIVE: Linear scan approach (for reference)
    //! Time: O(n), Space: O(1)
    int peakIndexInMountainArrayLinear(vector<int>& arr) {
        for (int i = 1; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                return i;
            }
        }
        return -1;  // Shouldn't reach here for valid mountain arrays
    }
};

// ============================================================
// 🧪 TESTING SUITE - Verifies solution with various test cases
// ============================================================

//! Helper function to print test results
void printTestResult(const vector<int>& arr, int result, int expected) {
    cout << "\n🔍 Input: arr = [";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "]\n";
    
    cout << "   Peak Index: " << result << " (Value: " << arr[result] << ")\n";
    cout << "   Expected:   " << expected << " (Value: " << arr[expected] << ")\n";
    cout << "   Status:     " << (result == expected ? "✅ PASS" : "❌ FAIL");
    if (result != expected) {
        cout << " (Expected: " << expected << ")";
    }
    cout << "\n";
    
    // Print visual representation
    int max_val = *max_element(arr.begin(), arr.end());
    for (int i = max_val; i > 0; i--) {
        for (int num : arr) {
            cout << (num >= i ? "▲ " : "  ");
        }
        cout << "\n";
    }
    
    // Print indices
    for (size_t i = 0; i < arr.size(); i++) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    
    // Test Case 1: Smallest possible mountain array
    {
        vector<int> arr = {0, 1, 0};
        int result = solution.peakIndexInMountainArray(arr);
        printTestResult(arr, result, 1);
    }
    
    // Test Case 2: Mountain array with peak at index 1
    {
        vector<int> arr = {0, 2, 1, 0};
        int result = solution.peakIndexInMountainArray(arr);
        printTestResult(arr, result, 1);
    }
    
    // Test Case 3: Mountain array with peak at index 1 (steep increase)
    {
        vector<int> arr = {0, 10, 5, 2};
        int result = solution.peakIndexInMountainArray(arr);
        printTestResult(arr, result, 1);
    }
    
    // Test Case 4: Larger mountain array with peak in the middle
    {
        vector<int> arr = {1, 3, 5, 8, 10, 12, 15, 12, 10, 8, 5, 3, 1};
        int result = solution.peakIndexInMountainArray(arr);
        printTestResult(arr, result, 6);
    }
    
    // Test Case 5: Mountain array with peak near the end
    {
        vector<int> arr = {1, 3, 5, 7, 9, 10, 15, 12, 11};
        int result = solution.peakIndexInMountainArray(arr);
        printTestResult(arr, result, 6);
    }
    
    // Test Case 6: Mountain array with peak near the start
    {
        vector<int> arr = {10, 15, 12, 10, 8, 5, 3, 1};
        int result = solution.peakIndexInMountainArray(arr);
        printTestResult(arr, result, 1);
    }
    
    return 0;
}

/*
 * ================================================================================
 * 📝 Additional Notes:
 * - The solution assumes the input is a valid mountain array as per the problem constraints
 * - For invalid inputs (non-mountain arrays), the behavior is undefined
 * - The linear search alternative is simpler but less efficient (O(n) vs O(log n))
 * - The binary search approach is optimal for this problem given the constraints
 * ================================================================================
 */
