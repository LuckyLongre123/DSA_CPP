/**
 * ================================================================================
 * LeetCode 11: Container With Most Water - Two Pointer Algorithm
 * ================================================================================
 * 
 * ! Problem: Given n non-negative integers representing heights of vertical lines,
 * ! find two lines that together with the x-axis form a container that holds the
 * ! most water. Return the maximum amount of water the container can store.
 * 
 * * Approach:
 * * 1. Initialize two pointers at the start and end of the array
 * * 2. Calculate area formed by the two pointers
 * * 3. Move the pointer with smaller height inward (greedy choice)
 * * 4. Keep track of maximum area encountered
 * * 5. Continue until pointers meet
 * 
 * ? Time Complexity: O(n) - Single pass through the array with two pointers
 * ? Space Complexity: O(1) - Only constant extra space for variables
 * 
 * TODO Key Insight: 
 * *    - The area is limited by the shorter line (height)
 * *    - Moving the shorter pointer gives us a chance to find a taller line
 * *    - Moving the taller pointer can only decrease the area (width decreases, height can't improve)
 * 
 * * Optimizations: 
 * *    - Two-pointer technique eliminates need for O(n²) brute force
 * *    - Greedy approach guarantees we don't miss the optimal solution
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * Finds the maximum area of water that can be contained between two lines
     * @param height Vector of integers representing heights of vertical lines
     * @return The maximum area of water that can be contained
     */
    int maxArea(vector<int>& height) {
        int left = 0;                    // * Start pointer at beginning
        int right = height.size() - 1;   // * End pointer at last element
        int max_area = 0;                // * Stores maximum area found
        
        while (left < right) {
            // ! Calculate current area: width × minimum height
            // ? Width = distance between pointers (right - left)
            // ? Height = minimum of the two heights (water level limited by shorter line)
            int area = min(height[left], height[right]) * (right - left);
            
            // * Update maximum area if current area is larger
            max_area = max(max_area, area);
            
            // ! Greedy choice: Move the pointer with smaller height
            // ? Moving the shorter line gives potential for taller line
            // ? Moving the taller line can only decrease area (width shrinks, height won't improve)
            if (height[left] < height[right]) {
                left++;   // * Move left pointer rightward
            } else {
                right--;  // * Move right pointer leftward
            }
        }
        
        return max_area;
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(vector<int> height, int result, int expected) {
    cout << "\nheight = [";
    for (int i = 0; i < height.size(); i++) {
        cout << height[i];
        if (i < height.size() - 1) cout << ",";
    }
    cout << "]\n";
    cout << "   Result:   " << result << "\n";
    cout << "   Expected: " << expected << "\n";
    cout << "   Status:   " << (result == expected ? "PASS" : "FAIL");
    if (result != expected) {
        cout << " (Expected: " << expected << ")";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Standard case with varying heights
    {
        vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        int result = solution.maxArea(height);
        printTestResult(height, result, 49);
    }
    
    // * Test Case 2: Simple case with two lines
    {
        vector<int> height = {1, 1};
        int result = solution.maxArea(height);
        printTestResult(height, result, 1);
    }
    
    // * Test Case 3: Ascending heights
    {
        vector<int> height = {1, 2, 3, 4, 5};
        int result = solution.maxArea(height);
        printTestResult(height, result, 6);
    }
    
    // * Test Case 4: Descending heights
    {
        vector<int> height = {5, 4, 3, 2, 1};
        int result = solution.maxArea(height);
        printTestResult(height, result, 6);
    }
    
    // ! Test Case 5: All same heights
    {
        vector<int> height = {4, 4, 4, 4, 4};
        int result = solution.maxArea(height);
        printTestResult(height, result, 16);
    }
    
    // ! Test Case 6: Large heights at edges
    {
        vector<int> height = {10, 1, 1, 1, 10};
        int result = solution.maxArea(height);
        printTestResult(height, result, 40);
    }
    
    // * Test Case 7: Mountain pattern
    {
        vector<int> height = {1, 3, 5, 7, 5, 3, 1};
        int result = solution.maxArea(height);
        printTestResult(height, result, 12);
    }
    
    // * Test Case 8: Valley pattern
    {
        vector<int> height = {7, 5, 3, 1, 3, 5, 7};
        int result = solution.maxArea(height);
        printTestResult(height, result, 42);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The two-pointer technique is optimal for this problem (no better solution exists)
 * ! - The greedy choice of moving the shorter pointer is proven to be correct
 * * - This algorithm guarantees we explore all potentially optimal configurations
 * ? - Alternative brute force approach would be O(n²) checking all pairs
 * * - The solution works because area = min(h[i], h[j]) × (j - i)
 * ! - Moving the taller pointer can NEVER improve the solution (width decreases, height can't increase)
 * ================================================================================
 */