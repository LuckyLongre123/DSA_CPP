/**
 * ================================================================================
 * LeetCode 4: Median of Two Sorted Arrays - Advanced Binary Search
 * ================================================================================
 * 
 * ! Problem: Given two sorted arrays nums1 and nums2 of size m and n respectively,
 * ! return the median of the two sorted arrays. The overall run time complexity 
 * ! should be O(log(min(m,n))).
 * 
 * * Approach:
 * * 1. Apply binary search on the smaller array for optimal performance
 * * 2. Find the correct partition point that divides both arrays
 * * 3. Ensure left partition elements ≤ right partition elements
 * * 4. Calculate median based on total length (odd/even)
 * * 5. Adjust partition using binary search until valid configuration found
 * 
 * ? Time Complexity: O(log(min(m,n))) - Binary search on smaller array
 * ? Space Complexity: O(1) - Constant extra space used
 * 
 * TODO Key Insight: 
 * *    - Instead of merging arrays (O(m+n)), we use binary search on partition points
 * *    - The median divides the combined array into two equal halves
 * *    - We find partition where max(left_half) ≤ min(right_half)
 * *    - Binary search on smaller array ensures logarithmic time complexity
 * 
 * * Optimizations: 
 * *    - Always search on smaller array to minimize iterations
 * *    - Use integer min/max for boundary conditions
 * *    - Single pass binary search with intelligent partition calculation
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * Finds median of two sorted arrays using binary search partitioning
     * @param nums1 First sorted array
     * @param nums2 Second sorted array
     * @return The median value as a double
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // ! OPTIMIZATION: Always perform binary search on the smaller array
        // ? This reduces time complexity from O(log(max(m,n))) to O(log(min(m,n)))
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int n = nums1.size();  // * Size of smaller array
        int m = nums2.size();  // * Size of larger array
        
        // * Binary search bounds: we can partition nums1 at any position [0, n]
        int low = 0, high = n;
        
        while (low <= high) {
            // * PARTITION CALCULATION
            // ? cut1: partition index in nums1 (elements to the left)
            // ? cut2: corresponding partition index in nums2 to maintain equal halves
            int cut1 = (low + high) / 2;  // * Binary search midpoint in nums1
            int cut2 = (n + m + 1) / 2 - cut1;  // * Calculated to balance partitions
            
            // ! BOUNDARY HANDLING: Use INT_MIN/INT_MAX for out-of-bounds elements
            // ? When cut1 = 0, no elements from nums1 in left partition → use -∞
            // ? When cut1 = n, all elements from nums1 in left partition → use +∞
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            
            int right1 = (cut1 == n) ? INT_MAX : nums1[cut1];
            int right2 = (cut2 == m) ? INT_MAX : nums2[cut2];
            
            // * VALIDATION: Check if partition is correct
            // ? Correct partition means: max(left_half) ≤ min(right_half)
            // ? Specifically: left1 ≤ right2 AND left2 ≤ right1
            if (left1 <= right2 && left2 <= right1) {
                // ! MEDIAN CALCULATION based on total length
                if ((n + m) % 2 == 0) {
                    // * Even total length: median = average of two middle elements
                    // ? max(left1, left2) = largest in left partition
                    // ? min(right1, right2) = smallest in right partition
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    // * Odd total length: median = largest element in left partition
                    // ? We add 1 in cut2 formula, so left partition has one extra element
                    return max(left1, left2);
                }
            } 
            // * BINARY SEARCH ADJUSTMENT
            else if (left1 > right2) {
                // ? left1 is too large, need to take fewer elements from nums1
                // ? Move partition left in nums1
                high = cut1 - 1;
            } 
            else {
                // ? left2 > right1, need to take more elements from nums1
                // ? Move partition right in nums1
                low = cut1 + 1;
            }
        }
        
        // ! This should never be reached with valid input
        return 0.0;
    }
};

// ============================================================
// * TESTING SUITE - Comprehensive verification with examples
// ============================================================

/**
 * Helper function to print array
 */
void printArray(const vector<int>& arr, const string& name) {
    cout << name << " = [";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]";
}

/**
 * Helper function to print test result
 */
void printTestResult(vector<int>& nums1, vector<int>& nums2, double result, double expected) {
    cout << "\n";
    printArray(nums1, "nums1");
    cout << "\n";
    printArray(nums2, "nums2");
    cout << "\n   Result:   " << result << "\n";
    cout << "   Expected: " << expected << "\n";
    cout << "   Status:   " << (abs(result - expected) < 0.00001 ? "PASS ✓" : "FAIL ✗");
    cout << "\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Simple merge - two equal-sized arrays
    {
        vector<int> nums1 = {1, 3};
        vector<int> nums2 = {2};
        double result = solution.findMedianSortedArrays(nums1, nums2);
        printTestResult(nums1, nums2, result, 2.0);
    }
    
    // * Test Case 2: Even total length - average of middle two
    {
        vector<int> nums1 = {1, 2};
        vector<int> nums2 = {3, 4};
        double result = solution.findMedianSortedArrays(nums1, nums2);
        printTestResult(nums1, nums2, result, 2.5);
    }
    
    // * Test Case 3: One empty array
    {
        vector<int> nums1 = {};
        vector<int> nums2 = {1};
        double result = solution.findMedianSortedArrays(nums1, nums2);
        printTestResult(nums1, nums2, result, 1.0);
    }
    
    // * Test Case 4: Different sized arrays
    {
        vector<int> nums1 = {1, 3, 8, 9, 15};
        vector<int> nums2 = {7, 11, 18, 19, 21, 25};
        double result = solution.findMedianSortedArrays(nums1, nums2);
        printTestResult(nums1, nums2, result, 11.0);
    }
    
    // ! Test Case 5: Large difference in sizes
    {
        vector<int> nums1 = {1, 2};
        vector<int> nums2 = {1, 2, 3, 4, 5, 6};
        double result = solution.findMedianSortedArrays(nums1, nums2);
        printTestResult(nums1, nums2, result, 3.0);
    }
    
    // ! Test Case 6: All elements in nums1 smaller than nums2
    {
        vector<int> nums1 = {1, 2, 3};
        vector<int> nums2 = {4, 5, 6};
        double result = solution.findMedianSortedArrays(nums1, nums2);
        printTestResult(nums1, nums2, result, 3.5);
    }
    
    // * Test Case 7: Single element in each array
    {
        vector<int> nums1 = {1};
        vector<int> nums2 = {2};
        double result = solution.findMedianSortedArrays(nums1, nums2);
        printTestResult(nums1, nums2, result, 1.5);
    }
    
    // * Test Case 8: Negative numbers
    {
        vector<int> nums1 = {-5, -3, -1};
        vector<int> nums2 = {-2, 0, 2, 4};
        double result = solution.findMedianSortedArrays(nums1, nums2);
        printTestResult(nums1, nums2, result, -1.0);
    }
    
    // ! Test Case 9: Duplicate elements
    {
        vector<int> nums1 = {1, 1, 1};
        vector<int> nums2 = {1, 1, 1};
        double result = solution.findMedianSortedArrays(nums1, nums2);
        printTestResult(nums1, nums2, result, 1.0);
    }
    
    // * Test Case 10: Large range values
    {
        vector<int> nums1 = {100000};
        vector<int> nums2 = {100001};
        double result = solution.findMedianSortedArrays(nums1, nums2);
        printTestResult(nums1, nums2, result, 100000.5);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - This is one of the most challenging problems requiring deep understanding
 * *   of binary search and partitioning logic
 * ! - The key insight is partitioning, not merging - this achieves O(log n) complexity
 * * - Always search on smaller array to optimize performance
 * ? - The partition formula (n + m + 1) / 2 ensures left partition has equal or
 *     one more element than right partition
 * ! - Edge cases with empty arrays are handled via INT_MIN/INT_MAX sentinels
 * * - This technique is applicable to other partition-based problems
 * ================================================================================
 */