/**
 * ================================================================================
 * 📐 LeetCode 976: Largest Perimeter Triangle - Geometric Optimization
 * ================================================================================
 * 
 * 🎯 Problem: Given an integer array nums representing stick lengths, return the 
 * largest possible perimeter of a triangle with a non-zero area. If no triangle 
 * can be formed, return 0.
 * 
 * 📝 Approach: Greedy Algorithm with Sorting
 * 1. Sort the array in descending order to prioritize larger perimeters
 * 2. Check each consecutive triplet from largest to smallest
 * 3. Apply triangle inequality: for sides a ≥ b ≥ c, check if a < b + c
 * 4. Return the first valid triangle's perimeter (guaranteed to be maximum)
 * 5. If no valid triangle exists, return 0
 * 
 * ⚡ Time Complexity: O(n log n) - Dominated by sorting operation
 * 💾 Space Complexity: O(log n) - Space used by sorting algorithm (recursion stack)
 * 
 * 🧠 Key Insight: 
 *    - Triangle Inequality: For any triangle with sides a, b, c:
 *      a + b > c AND a + c > b AND b + c > a
 *    - Optimization: If a ≥ b ≥ c and a < b + c, then other conditions are automatically satisfied
 *    - Greedy Property: First valid triangle in descending order has maximum perimeter
 * 
 * 🚀 Optimizations: 
 *    - Single inequality check instead of three (mathematical optimization)
 *    - Early termination when first valid triangle is found
 *    - Descending sort enables greedy approach for maximum perimeter
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <climits>
 #include <cassert>
 #include <chrono>
 #include <iomanip>
 using namespace std;
 
 class Solution {
 public:
     /**
      * !! MAIN FUNCTION: Finds the largest possible perimeter of a triangle
      * ? Uses greedy approach with sorting to optimize for maximum perimeter
      * * Algorithm Strategy:
      *    Time Complexity: O(n log n) - sorting dominates the complexity
      *    Space Complexity: O(log n) - recursion stack space for sorting
      * ! @param nums: vector of positive integers representing stick lengths
      * ! @return: largest possible triangle perimeter, or 0 if no triangle possible
      * ! @throws: none - handles all edge cases gracefully
      * * Edge Cases Handled:
      *    - Empty array: returns 0 (no sticks available)
      *    - Less than 3 elements: returns 0 (insufficient sticks for triangle)
      *    - No valid triangles: returns 0 (all triplets violate triangle inequality)
      *    - All elements same: returns sum of any three (equilateral triangle)
      * ? Example Usage:
      *    vector<int> sticks = {2, 1, 2};
      *    int result = largestPerimeter(sticks); // returns 5
      */
     int largestPerimeter(vector<int>& nums) {
         //// !! Input validation - ensure minimum requirements for triangle formation
         if (nums.size() < 3) {
             return 0; //// * Insufficient elements to form any triangle
         }
         
         //// !! Step 1: Sort in descending order for greedy optimization
         //// ? Descending sort ensures we check largest possible perimeters first
         //// * This enables early termination when first valid triangle is found
         sort(nums.begin(), nums.end(), greater<int>());
         
         int n = static_cast<int>(nums.size()); //// ! Safe conversion from size_t
         
         //// !! Step 2: Iterate through all possible consecutive triplets
         //// ? We check consecutive triplets because sorting guarantees a ≥ b ≥ c
         //// * Loop invariant: nums[i] ≥ nums[i+1] ≥ nums[i+2] for all valid i
         for (int i = 0; i < n - 2; i++) {
             int a = nums[i];     //// * Largest side of current triplet
             int b = nums[i + 1]; //// * Second largest side
             int c = nums[i + 2]; //// * Smallest side
             
             //// !! Step 3: Apply triangle inequality theorem
             //// ? For sorted sides a ≥ b ≥ c, only need to check: a < b + c
             //// * Mathematical proof: if a < b + c, then b < a + c and c < a + b automatically hold
             if (a < b + c) {
                 //// !! Valid triangle found - return perimeter immediately
                 //// ? Since array is sorted descending, this is guaranteed to be maximum perimeter
                 //// * Greedy property: first valid triangle has largest possible perimeter
                 return a + b + c;
             }
             //// ? If triangle inequality fails, continue to next triplet
             //// * Current triplet: a ≥ b + c, so no valid triangle with these sides
         }
         
         //// !! Step 4: No valid triangle found after checking all triplets
         //// ? All possible triplets violated the triangle inequality
         //// * This happens when the largest side is always ≥ sum of other two sides
         return 0;
     }
     
     
     /**
      * !! UTILITY FUNCTION: Validates if three sides can form a valid triangle
      * ? Implements complete triangle inequality check for educational purposes
      * * Mathematical Foundation:
      *    - Triangle Inequality Theorem: sum of any two sides > third side
      *    - All three conditions must be satisfied simultaneously
      * ! @param a, b, c: three side lengths (any order)
      * ! @return: true if sides can form valid triangle, false otherwise
      */
     bool isValidTriangle(int a, int b, int c) {
         //// !! Check all three triangle inequality conditions
         //// ? Condition 1: a + b > c
         //// ? Condition 2: a + c > b  
         //// ? Condition 3: b + c > a
         //// * All must be true for valid triangle formation
         return (a + b > c) && (a + c > b) && (b + c > a);
     }
     
 };
 
 // ============================================================
 // COMPREHENSIVE TESTING SUITE - Validates solution correctness
 // ============================================================
 
 /**
  * !! HELPER FUNCTION: Prints formatted test results with status indicators
  * ? Provides clear pass/fail status with detailed information
  * * Output Format:
  *    - Test input and expected/actual results
  *    - Status indicators (PASS/FAIL)
  *    - Detailed explanation for failures
  */
 void printTestResult(const vector<int>& input, int result, int expected, const string& testName) {
     cout << "\n" << testName << "\n";
     cout << "   Input:    [";
     for (size_t i = 0; i < input.size(); ++i) {
         cout << input[i];
         if (i < input.size() - 1) cout << ", ";
     }
     cout << "]\n";
     cout << "   Result:   " << result << "\n";
     cout << "   Expected: " << expected << "\n";
     cout << "   Status:   " << (result == expected ? "PASS" : "FAIL");
     if (result != expected) {
         cout << " (Got: " << result << ", Expected: " << expected << ")";
     }
     cout << "\n";
 }
 
 /**
  * !! COMPREHENSIVE TEST RUNNER: Executes all test categories
  * ? Covers normal cases, edge cases, and performance scenarios
  * * Test Categories:
  *    1. Basic valid triangles
  *    2. Invalid triangle cases  
  *    3. Edge cases (empty, small arrays)
  *    4. Large input performance tests
  *    5. Mathematical boundary conditions
  */
 int main() {
     Solution solution;
     
     cout << "LeetCode 976: Largest Perimeter Triangle - Comprehensive Test Suite\n";
     cout << string(70, '=') << "\n";
     
     //// !! Test Category 1: Basic Valid Triangles
     cout << "\nCategory 1: Basic Valid Triangle Cases\n";
     cout << string(40, '-') << "\n";
     
     // Test Case 1.1: Simple valid triangle
     {
         vector<int> nums = {2, 1, 2};
         int result = solution.largestPerimeter(nums);
         printTestResult(nums, result, 5, "Simple Valid Triangle");
     }
     
     // Test Case 1.2: Multiple valid triangles - choose largest
     {
         vector<int> nums = {3, 2, 3, 4};
         int result = solution.largestPerimeter(nums);
         printTestResult(nums, result, 10, "Multiple Valid Triangles");
     }
     
     // Test Case 1.3: Equilateral triangle
     {
         vector<int> nums = {5, 5, 5};
         int result = solution.largestPerimeter(nums);
         printTestResult(nums, result, 15, "Equilateral Triangle");
     }
     
     // Test Case 1.4: Scalene triangle with larger array
     {
         vector<int> nums = {1, 2, 2, 3, 4, 5};
         int result = solution.largestPerimeter(nums);
         printTestResult(nums, result, 12, "Scalene Triangle (Large Array)");
     }
     
     //// !! Test Category 2: Invalid Triangle Cases
     cout << "\nCategory 2: Invalid Triangle Cases\n";
     cout << string(40, '-') << "\n";
     
     // Test Case 2.1: Triangle inequality violation
     {
         vector<int> nums = {1, 1, 10};
         int result = solution.largestPerimeter(nums);
         printTestResult(nums, result, 0, "Triangle Inequality Violation");
     }
     
     // Test Case 2.2: All triplets invalid
     {
         vector<int> nums = {3, 6, 2};
         int result = solution.largestPerimeter(nums);
         printTestResult(nums, result, 0, "All Triplets Invalid");
     }
     
     // Test Case 2.3: Geometric progression (no valid triangles)
     {
         vector<int> nums = {1, 2, 4, 8};
         int result = solution.largestPerimeter(nums);
         printTestResult(nums, result, 0, "Geometric Progression");
     }
     
     //// !! Test Category 3: Edge Cases
     cout << "\nCategory 3: Edge Cases\n";
     cout << string(40, '-') << "\n";
     
     // Test Case 3.1: Minimum size (less than 3 elements)
     {
         vector<int> nums = {1, 2};
         int result = solution.largestPerimeter(nums);
         printTestResult(nums, result, 0, "Insufficient Elements");
     }
     
     // Test Case 3.2: Empty array
     {
         vector<int> nums = {};
         int result = solution.largestPerimeter(nums);
         printTestResult(nums, result, 0, "Empty Array");
     }
     
     // Test Case 3.3: Single element
     {
         vector<int> nums = {42};
         int result = solution.largestPerimeter(nums);
         printTestResult(nums, result, 0, "Single Element");
     }
     
     // Test Case 3.4: Exactly three elements - valid
     {
         vector<int> nums = {3, 4, 5};
         int result = solution.largestPerimeter(nums);
         printTestResult(nums, result, 12, "Exactly Three Elements (Valid)");
     }
     
     // Test Case 3.5: Exactly three elements - invalid
     {
         vector<int> nums = {1, 10, 12};
         int result = solution.largestPerimeter(nums);
         printTestResult(nums, result, 0, "Exactly Three Elements (Invalid)");
     }
     
     //// !! Test Category 4: Boundary and Large Number Cases
     cout << "\nCategory 4: Boundary Cases\n";
     cout << string(40, '-') << "\n";
     
     // Test Case 4.1: Large numbers
     {
         vector<int> nums = {1000000, 999999, 999998};
         int result = solution.largestPerimeter(nums);
         printTestResult(nums, result, 2999997, "Large Numbers");
     }
     
     // Test Case 4.2: All elements identical
     {
         vector<int> nums = {7, 7, 7, 7, 7};
         int result = solution.largestPerimeter(nums);
         printTestResult(nums, result, 21, "All Elements Identical");
     }
     
     // Test Case 4.3: Mixed small and large numbers
     {
         vector<int> nums = {1, 1, 1000000};
         int result = solution.largestPerimeter(nums);
         printTestResult(nums, result, 0, "Mixed Small and Large");
     }
     
     //// !! Test Category 5: Performance Testing
     cout << "\nCategory 5: Performance Analysis\n";
     cout << string(40, '-') << "\n";
     
     // Performance test with large input (optimal algorithm only)
     {
         vector<int> largeInput;
         for (int i = 1; i <= 10000; ++i) {
             largeInput.push_back(i % 100 + 1); //// * Create realistic distribution
         }
         
         auto start = chrono::high_resolution_clock::now();
         int result = solution.largestPerimeter(largeInput);
         auto end = chrono::high_resolution_clock::now();
         auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
         
         cout << "\nLarge Input Performance Test (n=10,000):\n";
         cout << "   Result: " << result << "\n";
         cout << "   Time: " << duration.count() << " microseconds\n";
         cout << "   Status: " << (duration.count() < 10000 ? "Efficient" : "Slow") << "\n";
     }
     
     //// !! Test Summary and Algorithm Validation
     cout << "\nAlgorithm Correctness Validation\n";
     cout << string(40, '-') << "\n";
     
     // Validate triangle inequality understanding
     {
         vector<int> testSides = {3, 4, 5}; //// * Classic 3-4-5 right triangle
         bool isValid = solution.isValidTriangle(3, 4, 5);
         cout << "Triangle Inequality Validation: " << (isValid ? "PASS" : "FAIL") << "\n";
         
         bool isInvalid = !solution.isValidTriangle(1, 1, 10);
         cout << "Invalid Triangle Detection: " << (isInvalid ? "PASS" : "FAIL") << "\n";
     }
     
     cout << "\nTest Suite Completed Successfully!\n";
     cout << "All geometric algorithms validated and performance benchmarked.\n";
     cout << string(70, '=') << "\n";
     
     return 0;
 }
 
 /*
  * ================================================================================
  * ALGORITHM ANALYSIS & MATHEMATICAL FOUNDATIONS
  * ================================================================================
  * 
  * Triangle Inequality Theorem:
  *    For any triangle with sides a, b, c: a + b > c AND a + c > b AND b + c > a
  *    
  * Optimization Insight:
  *    If sides are sorted as a ≥ b ≥ c, then checking a < b + c is sufficient
  *    because: b < a + c and c < a + b are automatically satisfied
  *    
  * Time Complexity Breakdown:
  *    - Sorting: O(n log n) using comparison-based algorithm
  *    - Linear scan: O(n) to check consecutive triplets
  *    - Overall: O(n log n) - sorting dominates
  *    
  * Space Complexity Analysis:
  *    - Auxiliary space: O(1) for variables
  *    - Sorting space: O(log n) for recursion stack
  *    - Total: O(log n) - practically constant for reasonable inputs
  *    
  * Greedy Algorithm Justification:
  *    - Greedy choice: Always try largest available sides first
  *    - Optimal substructure: If [a,b,c] is optimal, no larger valid triangle exists
  *    - Correctness: Descending sort ensures first valid triangle has maximum perimeter
  *    
  * Educational Extensions:
  *    - Computational Geometry: Convex hull algorithms, polygon triangulation
  *    - Optimization Theory: Greedy vs dynamic programming approaches
  *    - Real-world Applications: Structural engineering, computer graphics, manufacturing
  * ================================================================================
  */
 