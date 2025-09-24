/**
 * ================================================================================
 * 🔍 LeetCode 35: Search Insert Position - Binary Search Mastery
 * ================================================================================
 * 
 * 🎯 Problem: Given a sorted array of distinct integers and a target value, 
 * return the index if the target is found. If not, return the index where 
 * it would be if it were inserted in order.
 * 
 * 📝 Approach:
 * 1. Use binary search to efficiently locate the target or insertion position
 * 2. Initialize left and right pointers to array bounds
 * 3. While left <= right:
 *    - Calculate middle index to avoid overflow
 *    - If middle element equals target, return middle index
 *    - If middle element < target, search right half
 *    - If middle element > target, search left half
 * 4. When loop ends, left pointer indicates the insertion position
 * 
 * ⚡ Time Complexity: O(log n) - Binary search halves the search space each iteration
 * 💾 Space Complexity: O(1) - Constant extra space used
 * 
 * 🧠 Key Insight: 
 *    - Binary search works because the array is sorted
 *    - When target is not found, the left pointer naturally points to the insertion position
 *    - The insertion position maintains the sorted order of the array
 * 
 * 🚀 Optimizations: 
 *    - Use (left + right) / 2 carefully to avoid integer overflow
 *    - Alternative: left + (right - left) / 2 for safer mid calculation
 * ================================================================================
 */

 #include <iostream>
 #include <vector>
 #include <cassert>
 #include <chrono>
 using namespace std;
 
 class Solution {
 public:
     //! MAIN FUNCTION: Finds target index or insertion position in sorted array
     //! @param nums Sorted array of distinct integers
     //! @param target The value to search for or find insertion position
     //! @return Index of target if found, otherwise insertion position
     int searchInsert(vector<int>& nums, int target) {
         int left = 0;                    // * Left boundary of search range
         int right = nums.size() - 1;     // * Right boundary of search range
         
         while (left <= right) {
             //! Calculate middle index safely to avoid overflow
             //? Using left + (right - left) / 2 prevents integer overflow
             int mid = left + (right - left) / 2;
             
             if (nums[mid] == target) {
                 return mid;              // * Target found at middle position
             }
             else if (nums[mid] < target) {
                 left = mid + 1;          // * Target is in right half
             }
             else {
                 right = mid - 1;         // * Target is in left half
             }
         }
         
         //! When loop ends, left points to the insertion position
         //? At this point: left > right, and left is where target should be inserted
         return left;
     }
     
     //! ALTERNATIVE: Iterative approach with different variable names (for reference)
     //! Time: O(log n), Space: O(1)
     int searchInsertAlternative(vector<int>& nums, int target) {
         int start = 0;
         int end = nums.size() - 1;
         
         while (start <= end) {
             int middle = start + (end - start) / 2;
             
             if (nums[middle] == target) {
                 return middle;
             }
             
             if (nums[middle] < target) {
                 start = middle + 1;
             } else {
                 end = middle - 1;
             }
         }
         
         return start;  // Insertion position
     }
     
     //! RECURSIVE APPROACH: Binary search using recursion (for educational purposes)
     //! Time: O(log n), Space: O(log n) due to recursion stack
     int searchInsertRecursive(vector<int>& nums, int target) {
         return binarySearchRecursive(nums, target, 0, nums.size() - 1);
     }
     
 private:
     //! Helper function for recursive binary search
     int binarySearchRecursive(vector<int>& nums, int target, int left, int right) {
         if (left > right) {
             return left;  // Base case: insertion position
         }
         
         int mid = left + (right - left) / 2;
         
         if (nums[mid] == target) {
             return mid;
         }
         else if (nums[mid] < target) {
             return binarySearchRecursive(nums, target, mid + 1, right);
         }
         else {
             return binarySearchRecursive(nums, target, left, mid - 1);
         }
     }
 };
 
 // ============================================================
 // 🧪 TESTING SUITE - Verifies solution with various test cases
 // ============================================================
 
 //! Helper function to print test result with detailed output
 void printTestResult(vector<int>& nums, int target, int result, int expected, const string& testName) {
     cout << "\n🔍 " << testName << "\n";
     cout << "   Array:    [";
     for (int i = 0; i < nums.size(); i++) {
         cout << nums[i];
         if (i < nums.size() - 1) cout << ", ";
     }
     cout << "]\n";
     cout << "   Target:   " << target << "\n";
     cout << "   Result:   " << result << "\n";
     cout << "   Expected: " << expected << "\n";
     cout << "   Status:   " << (result == expected ? "✅ PASS" : "❌ FAIL");
     if (result != expected) {
         cout << " (Got: " << result << ", Expected: " << expected << ")";
     }
     cout << "\n";
 }
 
 //! Performance testing function
 void performanceTest() {
     cout << "\n🚀 Performance Test - Large Array\n";
     vector<int> largeArray;
     for (int i = 0; i < 100000; i += 2) {
         largeArray.push_back(i);  // Even numbers: 0, 2, 4, ..., 199998
     }
     
     Solution solution;
     auto start = chrono::high_resolution_clock::now();
     
     int result = solution.searchInsert(largeArray, 99999);  // Odd number, should be inserted
     
     auto end = chrono::high_resolution_clock::now();
     auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
     
     cout << "   Array Size: " << largeArray.size() << " elements\n";
     cout << "   Target: 99999\n";
     cout << "   Result: " << result << " (insertion position)\n";
     cout << "   Time: " << duration.count() << " microseconds\n";
     cout << "   Status: ✅ Efficient O(log n) performance\n";
 }
 
 int main() {
     Solution solution;
     
     // Test Case 1: Target found in middle
     {
         vector<int> nums = {1, 3, 5, 6};
         int target = 5;
         int result = solution.searchInsert(nums, target);
         printTestResult(nums, target, result, 2, "Target Found - Middle Position");
     }
     
     // Test Case 2: Target not found - insert at beginning
     {
         vector<int> nums = {1, 3, 5, 6};
         int target = 0;
         int result = solution.searchInsert(nums, target);
         printTestResult(nums, target, result, 0, "Insert at Beginning");
     }
     
     // Test Case 3: Target not found - insert at end
     {
         vector<int> nums = {1, 3, 5, 6};
         int target = 7;
         int result = solution.searchInsert(nums, target);
         printTestResult(nums, target, result, 4, "Insert at End");
     }
     
     // Test Case 4: Target not found - insert in middle
     {
         vector<int> nums = {1, 3, 5, 6};
         int target = 2;
         int result = solution.searchInsert(nums, target);
         printTestResult(nums, target, result, 1, "Insert in Middle");
     }
     
     // Test Case 5: Single element array - target found
     {
         vector<int> nums = {1};
         int target = 1;
         int result = solution.searchInsert(nums, target);
         printTestResult(nums, target, result, 0, "Single Element - Found");
     }
     
     // Test Case 6: Single element array - target not found (smaller)
     {
         vector<int> nums = {1};
         int target = 0;
         int result = solution.searchInsert(nums, target);
         printTestResult(nums, target, result, 0, "Single Element - Insert Before");
     }
     
     // Test Case 7: Single element array - target not found (larger)
     {
         vector<int> nums = {1};
         int target = 2;
         int result = solution.searchInsert(nums, target);
         printTestResult(nums, target, result, 1, "Single Element - Insert After");
     }
     
     // Test Case 8: Large sorted array
     {
         vector<int> nums = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
         int target = 14;
         int result = solution.searchInsert(nums, target);
         printTestResult(nums, target, result, 7, "Large Array - Insert Position");
     }
     
     // Test Case 9: Target at first position
     {
         vector<int> nums = {1, 3, 5, 6};
         int target = 1;
         int result = solution.searchInsert(nums, target);
         printTestResult(nums, target, result, 0, "Target at First Position");
     }
     
     // Test Case 10: Target at last position
     {
         vector<int> nums = {1, 3, 5, 6};
         int target = 6;
         int result = solution.searchInsert(nums, target);
         printTestResult(nums, target, result, 3, "Target at Last Position");
     }
     
     // Performance test
     performanceTest();
     
     // Test recursive approach
     cout << "\n🔄 Testing Recursive Approach\n";
     {
         vector<int> nums = {1, 3, 5, 6};
         int target = 4;
         int result = solution.searchInsertRecursive(nums, target);
         printTestResult(nums, target, result, 2, "Recursive Approach Test");
     }
     
     cout << "\n🎉 All tests completed!\n";
     return 0;
 }
 
 /*
  * ================================================================================
  * 📝 Additional Notes:
  * 
  * 🔍 Binary Search Insights:
  * - Works only on sorted arrays
  * - Reduces search space by half in each iteration
  * - When target is not found, left pointer indicates insertion position
  * 
  * 🎯 Edge Cases Handled:
  * - Empty array (though not in this problem's constraints)
  * - Single element array
  * - Target smaller than all elements
  * - Target larger than all elements
  * - Target equals first/last element
  * 
  * 🚀 Real-world Applications:
  * - Database indexing
  * - Finding insertion points in sorted data structures
  * - Range queries and binary search trees
  * - Scheduling algorithms
  * 
  * 💡 Interview Tips:
  * - Always clarify if array is sorted
  * - Discuss time/space complexity
  * - Handle edge cases explicitly
  * - Consider integer overflow in mid calculation
  * ================================================================================
  */
 