/**
 * ================================================================================
 * 🎯 LeetCode 4: Median of Two Sorted Arrays - Advanced Binary Search
 * ================================================================================
 * 
 * 🎯 Problem: Given two sorted arrays nums1 and nums2 of size m and n respectively,
 * return the median of the two sorted arrays. The overall run time complexity 
 * should be O(log (m+n)).
 * 
 * 📝 Approach: Binary Search on Partitions
 * 1. Ensure nums1 is the smaller array (optimization)
 * 2. Use binary search to find the correct partition point in nums1
 * 3. Calculate corresponding partition point in nums2
 * 4. Check if partition is valid (left elements ≤ right elements)
 * 5. If valid, calculate median based on total length (odd/even)
 * 6. If invalid, adjust search space based on comparison
 * 
 * ⚡ Time Complexity: O(log(min(m,n))) - Binary search on smaller array
 * 💾 Space Complexity: O(1) - Constant extra space used
 * 
 * 🧠 Key Insight: 
 *    - Instead of merging arrays, we find the correct partition point
 *    - Median divides the combined array into two equal halves
 *    - Binary search helps us find this partition efficiently
 * 
 * 🚀 Optimizations: 
 *    - Search on smaller array to minimize time complexity
 *    - Use INT_MIN/INT_MAX for boundary conditions
 *    - Single pass binary search without array merging
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 #include <climits>
 #include <algorithm>
 #include <iomanip>
 #include <cassert>
 #include <chrono>
 using namespace std;
 
 class Solution {
 public:
     //! MAIN FUNCTION: Finds median of two sorted arrays using binary search
     //! @param nums1 First sorted array (will be ensured to be smaller)
     //! @param nums2 Second sorted array
     //! @return The median value as a double
     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         // * Optimization: Always search on the smaller array
         if (nums1.size() > nums2.size()) {
             return findMedianSortedArrays(nums2, nums1);
         }
         
         int n = nums1.size();  // * Size of smaller array
         int m = nums2.size();  // * Size of larger array
         int low = 0, high = n; // * Binary search bounds on nums1
         
         while (low <= high) {
             // * Partition point in nums1 (number of elements from nums1 in left half)
             int cut1 = (low + high) / 2;
             
             // * Corresponding partition point in nums2
             // * Total left half size should be (n+m+1)/2
             int cut2 = (n + m + 1) / 2 - cut1;
             
             // * Get boundary elements for comparison
             // ? Use INT_MIN/MAX for edge cases when partition is at boundary
             int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];  // * Last element in left half of nums1
             int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];  // * Last element in left half of nums2
             int right1 = (cut1 == n) ? INT_MAX : nums1[cut1];     // * First element in right half of nums1
             int right2 = (cut2 == m) ? INT_MAX : nums2[cut2];     // * First element in right half of nums2
             
             // * Check if we found the correct partition
             // ? Valid partition: max(left_half) ≤ min(right_half)
             if (left1 <= right2 && left2 <= right1) {
                 // * Found correct partition! Calculate median
                 if ((n + m) % 2 == 0) {
                     // ? Even total length: median = average of two middle elements
                     return (max(left1, left2) + min(right1, right2)) / 2.0;
                 } else {
                     // ? Odd total length: median = maximum of left half
                     return max(left1, left2);
                 }
             } 
             // * Partition invalid: adjust search space
             else if (left1 > right2) {
                 // ? Too many elements from nums1 in left half
                 high = cut1 - 1;  // * Move partition left in nums1
             } else {
                 // ? Too few elements from nums1 in left half  
                 low = cut1 + 1;   // * Move partition right in nums1
             }
         }
         
         // * Should never reach here for valid input
         return 0.0;
     }
     
     //! ALTERNATIVE: Brute force approach for comparison (not optimal)
     //! Time: O(m+n), Space: O(m+n)
     double findMedianBruteForce(vector<int>& nums1, vector<int>& nums2) {
         vector<int> merged;
         int i = 0, j = 0;
         
         // Merge two sorted arrays
         while (i < nums1.size() && j < nums2.size()) {
             if (nums1[i] <= nums2[j]) {
                 merged.push_back(nums1[i++]);
             } else {
                 merged.push_back(nums2[j++]);
             }
         }
         
         // Add remaining elements
         while (i < nums1.size()) merged.push_back(nums1[i++]);
         while (j < nums2.size()) merged.push_back(nums2[j++]);
         
         int n = merged.size();
         if (n % 2 == 0) {
             return (merged[n/2 - 1] + merged[n/2]) / 2.0;
         } else {
             return merged[n/2];
         }
     }
     
     //! HELPER: Validates that arrays are sorted (for testing)
     bool areArraysSorted(const vector<int>& nums1, const vector<int>& nums2) {
         auto isSorted = [](const vector<int>& arr) {
             for (int i = 1; i < arr.size(); i++) {
                 if (arr[i] < arr[i-1]) return false;
             }
             return true;
         };
         return isSorted(nums1) && isSorted(nums2);
     }
 };
 
 // ============================================================
 // 🧪 TESTING SUITE - Comprehensive test cases and validation
 // ============================================================
 
 //! Helper function to print test result with detailed formatting
 void printTestResult(const vector<int>& nums1, const vector<int>& nums2, 
                     double result, double expected, const string& testName) {
     cout << "\n🔍 " << testName << "\n";
     cout << "   nums1:    [";
     for (int i = 0; i < nums1.size(); i++) {
         cout << nums1[i] << (i < nums1.size()-1 ? ", " : "");
     }
     cout << "]\n";
     cout << "   nums2:    [";
     for (int i = 0; i < nums2.size(); i++) {
         cout << nums2[i] << (i < nums2.size()-1 ? ", " : "");
     }
     cout << "]\n";
     cout << "   Result:   " << fixed << setprecision(5) << result << "\n";
     cout << "   Expected: " << fixed << setprecision(5) << expected << "\n";
     
     bool passed = abs(result - expected) < 1e-9;
     cout << "   Status:   " << (passed ? "✅ PASS" : "❌ FAIL") << "\n";
     if (!passed) {
         cout << "   Error:    " << abs(result - expected) << "\n";
     }
 }
 
 //! Performance testing function
 void performanceTest(Solution& solution) {
     cout << "\n🚀 Performance Testing:\n";
     
     // Large arrays test
     vector<int> large1, large2;
     for (int i = 0; i < 1000; i += 2) large1.push_back(i);
     for (int i = 1; i < 1000; i += 2) large2.push_back(i);
     
     auto start = chrono::high_resolution_clock::now();
     double result = solution.findMedianSortedArrays(large1, large2);
     auto end = chrono::high_resolution_clock::now();
     
     auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
     cout << "   Large arrays (1000 elements each): " << result << "\n";
     cout << "   Time taken: " << duration.count() << " microseconds\n";
 }
 
 int main() {
     Solution solution;
     
     cout << "================================================================================\n";
     cout << "🎯 LeetCode 4: Median of Two Sorted Arrays - Comprehensive Testing\n";
     cout << "================================================================================\n";
     
     // Test Case 1: Basic example from LeetCode
     {
         vector<int> nums1 = {1, 3};
         vector<int> nums2 = {2};
         double result = solution.findMedianSortedArrays(nums1, nums2);
         printTestResult(nums1, nums2, result, 2.0, "Basic Example - Odd Length");
     }
     
     // Test Case 2: Even total length
     {
         vector<int> nums1 = {1, 2};
         vector<int> nums2 = {3, 4};
         double result = solution.findMedianSortedArrays(nums1, nums2);
         printTestResult(nums1, nums2, result, 2.5, "Even Total Length");
     }
     
     // Test Case 3: One empty array
     {
         vector<int> nums1 = {};
         vector<int> nums2 = {1};
         double result = solution.findMedianSortedArrays(nums1, nums2);
         printTestResult(nums1, nums2, result, 1.0, "One Empty Array");
     }
     
     // Test Case 4: Different sizes
     {
         vector<int> nums1 = {1, 3};
         vector<int> nums2 = {2, 4, 5, 6};
         double result = solution.findMedianSortedArrays(nums1, nums2);
         printTestResult(nums1, nums2, result, 3.5, "Different Sizes");
     }
     
     // Test Case 5: All elements in one array are smaller
     {
         vector<int> nums1 = {1, 2, 3};
         vector<int> nums2 = {4, 5, 6, 7};
         double result = solution.findMedianSortedArrays(nums1, nums2);
         printTestResult(nums1, nums2, result, 4.0, "Disjoint Arrays - First Smaller");
     }
     
     // Test Case 6: All elements in one array are larger
     {
         vector<int> nums1 = {4, 5, 6};
         vector<int> nums2 = {1, 2, 3};
         double result = solution.findMedianSortedArrays(nums1, nums2);
         printTestResult(nums1, nums2, result, 3.5, "Disjoint Arrays - First Larger");
     }
     
     // Test Case 7: Single elements
     {
         vector<int> nums1 = {1};
         vector<int> nums2 = {2};
         double result = solution.findMedianSortedArrays(nums1, nums2);
         printTestResult(nums1, nums2, result, 1.5, "Single Elements Each");
     }
     
     // Test Case 8: Duplicate elements
     {
         vector<int> nums1 = {1, 1, 3, 3};
         vector<int> nums2 = {1, 1, 3, 3};
         double result = solution.findMedianSortedArrays(nums1, nums2);
         printTestResult(nums1, nums2, result, 2.0, "Duplicate Elements");
     }
     
     // Test Case 9: Negative numbers
     {
         vector<int> nums1 = {-5, -3, -1};
         vector<int> nums2 = {-2, 0, 2};
         double result = solution.findMedianSortedArrays(nums1, nums2);
         printTestResult(nums1, nums2, result, -1.5, "Negative Numbers");
     }
     
     // Test Case 10: Large range
     {
         vector<int> nums1 = {-1000000};
         vector<int> nums2 = {1000000};
         double result = solution.findMedianSortedArrays(nums1, nums2);
         printTestResult(nums1, nums2, result, 0.0, "Large Range");
     }
     
     // Performance testing
     performanceTest(solution);
     
     // Algorithm comparison
     cout << "\n🔬 Algorithm Comparison:\n";
     {
         vector<int> nums1 = {1, 3, 8, 9, 15};
         vector<int> nums2 = {7, 11, 18, 19, 21, 25};
         
         double optimized = solution.findMedianSortedArrays(nums1, nums2);
         double bruteForce = solution.findMedianBruteForce(nums1, nums2);
         
         cout << "   Optimized (Binary Search): " << optimized << "\n";
         cout << "   Brute Force (Merge):       " << bruteForce << "\n";
         cout << "   Results Match: " << (abs(optimized - bruteForce) < 1e-9 ? "✅ YES" : "❌ NO") << "\n";
     }
     
     cout << "\n================================================================================\n";
     cout << "🎉 All tests completed! Binary search approach provides O(log(min(m,n))) efficiency.\n";
     cout << "================================================================================\n";
     
     return 0;
 }
 
 /*
  * ================================================================================
  * 📝 Algorithm Analysis and Key Insights:
  * 
  * 🎯 Core Concept:
  * - The median divides a sorted array into two equal halves
  * - For combined arrays, we need to find the partition that creates equal halves
  * - Binary search helps us find this partition efficiently
  * 
  * 🔍 Partition Logic:
  * - cut1: number of elements from nums1 in the left half
  * - cut2: number of elements from nums2 in the left half
  * - Constraint: cut1 + cut2 = (m + n + 1) / 2
  * 
  * ✅ Valid Partition Conditions:
  * - left1 ≤ right2 (max of nums1's left ≤ min of nums2's right)
  * - left2 ≤ right1 (max of nums2's left ≤ min of nums1's right)
  * 
  * 🚀 Optimization Techniques:
  * - Always search on smaller array: reduces time from O(log(m+n)) to O(log(min(m,n)))
  * - Use INT_MIN/MAX for boundary cases: handles edge partitions elegantly
  * - Single pass: no need to actually merge arrays
  * 
  * 🧪 Edge Cases Handled:
  * - Empty arrays, single elements, duplicate values
  * - Negative numbers, large ranges
  * - Arrays of very different sizes
  * ================================================================================
  */
 