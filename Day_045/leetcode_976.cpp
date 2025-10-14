/**
 * ================================================================================
 * LeetCode 976: Largest Perimeter Triangle - Geometry & Greedy Algorithm
 * ================================================================================
 * 
 * ! Problem: Given an integer array `nums`, return the largest perimeter of a 
 * ! triangle with a non-zero area, formed from three of these lengths. If it is 
 * ! impossible to form any triangle of a non-zero area, return 0.
 * 
 * * Approach:
 * * 1. Sort the array in descending order (largest to smallest)
 * * 2. Iterate through consecutive triplets from the largest values
 * * 3. Check triangle inequality: a < b + c (where a is largest side)
 * * 4. Return the first valid triangle's perimeter
 * * 5. If no valid triangle found, return 0
 * 
 * ? Time Complexity: O(n log n) - Dominated by sorting operation
 * ? Space Complexity: O(1) - Only constant extra space (sorting is in-place)
 * 
 * TODO Key Insight: 
 * *    - Triangle Inequality: Sum of any two sides must be greater than the third
 * *    - For sorted array, only need to check: largest < (second + third)
 * *    - Greedy approach: Check largest values first to maximize perimeter
 * *    - If a triplet fails, all smaller values with same 'a' will also fail
 * 
 * * Optimizations: 
 * *    - Sort in descending order to find maximum perimeter early
 * *    - Single pass after sorting - early termination on first valid triangle
 * *    - No need to check all three inequalities (a<b+c, b<a+c, c<a+b)
 * *    - Since sorted: if a < b+c holds, other inequalities automatically hold
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * Finds the largest perimeter of a valid triangle from given side lengths
     * @param nums Vector of positive integers representing potential side lengths
     * @return The largest perimeter possible, or 0 if no valid triangle exists
     */
    int largestPerimeter(vector<int>& nums) {
        // * Sort in descending order to check largest possible perimeters first
        sort(nums.begin(), nums.end(), greater<int>());
        
        int n = nums.size();
        
        // * Iterate through all possible triplets of consecutive elements
        // ? We check consecutive triplets because sorting ensures optimal pairing
        for (int i = 0; i < n - 2; i++) {
            int a = nums[i];      // * Largest side of current triplet
            int b = nums[i + 1];  // * Second largest side
            int c = nums[i + 2];  // * Smallest side of triplet
            
            // ! Triangle Inequality Check: largest side < sum of other two sides
            // ? Since array is sorted (a >= b >= c), we only need to check a < b + c
            // ? If this holds, then b < a + c and c < a + b automatically hold
            if (a < b + c) {
                // * Valid triangle found! Return perimeter immediately
                return a + b + c;
            }
            
            // ? If a >= b + c, then this triplet cannot form a valid triangle
            // ? Continue to next triplet with smaller values
        }
        
        // ! No valid triangle found after checking all triplets
        return 0;
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result with visual formatting
 */
void printTestResult(vector<int> nums, int result, int expected) {
    cout << "\nInput: [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]\n";
    cout << "   Result:   " << result << "\n";
    cout << "   Expected: " << expected << "\n";
    cout << "   Status:   " << (result == expected ? "✅ PASS" : "❌ FAIL");
    if (result != expected) {
        cout << " (Expected: " << expected << ")";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Standard case with valid triangle
    {
        vector<int> nums = {2, 1, 2};
        int result = solution.largestPerimeter(nums);
        printTestResult(nums, result, 5);
        // ? Sorted: [2, 2, 1] → 2 < 2+1 ✓ → Perimeter = 5
    }
    
    // * Test Case 2: Multiple triangles possible
    {
        vector<int> nums = {3, 2, 3, 4};
        int result = solution.largestPerimeter(nums);
        printTestResult(nums, result, 10);
        // ? Sorted: [4, 3, 3, 2] → 4 < 3+3 ✓ → Perimeter = 10
    }
    
    // ! Test Case 3: No valid triangle possible
    {
        vector<int> nums = {1, 2, 1};
        int result = solution.largestPerimeter(nums);
        printTestResult(nums, result, 0);
        // ? Sorted: [2, 1, 1] → 2 >= 1+1 ✗ → No triangle
    }
    
    // * Test Case 4: Large array with valid triangle
    {
        vector<int> nums = {3, 6, 2, 3};
        int result = solution.largestPerimeter(nums);
        printTestResult(nums, result, 8);
        // ? Sorted: [6, 3, 3, 2] → 6 >= 3+3 ✗, then 3 < 3+2 ✓ → Perimeter = 8
    }
    
    // * Test Case 5: All sides equal (equilateral triangle)
    {
        vector<int> nums = {5, 5, 5};
        int result = solution.largestPerimeter(nums);
        printTestResult(nums, result, 15);
        // ? Sorted: [5, 5, 5] → 5 < 5+5 ✓ → Perimeter = 15
    }
    
    // ! Test Case 6: Two very small sides
    {
        vector<int> nums = {1, 1, 100};
        int result = solution.largestPerimeter(nums);
        printTestResult(nums, result, 0);
        // ? Sorted: [100, 1, 1] → 100 >= 1+1 ✗ → No triangle
    }
    
    // * Test Case 7: Large perimeter case
    {
        vector<int> nums = {10, 20, 15};
        int result = solution.largestPerimeter(nums);
        printTestResult(nums, result, 45);
        // ? Sorted: [20, 15, 10] → 20 < 15+10 ✓ → Perimeter = 45
    }
    
    // * Test Case 8: Multiple elements, largest triangle in middle
    {
        vector<int> nums = {1, 2, 2, 4, 18, 8};
        int result = solution.largestPerimeter(nums);
        printTestResult(nums, result, 20);
        // ? Sorted: [18, 8, 4, 2, 2, 1] → 18 >= 8+4 ✗ → 8 < 4+2 fails... → checks until 8+4+2 or 4+2+2
    }
    
    // * Test Case 9: Minimum input size
    {
        vector<int> nums = {5, 4, 3};
        int result = solution.largestPerimeter(nums);
        printTestResult(nums, result, 12);
        // ? Sorted: [5, 4, 3] → 5 < 4+3 ✓ → Perimeter = 12
    }
    
    // ! Test Case 10: Barely fails triangle inequality
    {
        vector<int> nums = {10, 5, 5};
        int result = solution.largestPerimeter(nums);
        printTestResult(nums, result, 0);
        // ? Sorted: [10, 5, 5] → 10 >= 5+5 ✗ → No triangle
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The greedy approach works because sorting ensures we check maximum perimeters first
 * ! - Triangle inequality only needs one check when sides are sorted: a < b + c
 * * - Time complexity is dominated by sorting O(n log n), iteration is O(n)
 * ? - Degenerate triangles (zero area) occur when a = b + c (equality case)
 * * - Solution is optimal - cannot improve beyond O(n log n) due to sorting requirement
 * ================================================================================
 */