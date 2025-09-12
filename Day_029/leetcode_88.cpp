/*
 * LeetCode 88: Merge Sorted Array
 * 
 * Problem Description:
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
 * and two integers m and n, representing the number of elements in nums1 and nums2.
 * Merge nums2 into nums1 as one sorted array. nums1 has size m+n with extra space.
 * 
 * Examples:
 * Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * Output: [1,2,2,3,5,6]
 * 
 * Input: nums1 = [1], m = 1, nums2 = [], n = 0
 * Output: [1]
 * 
 * Approach: Three-Pointer Merge with Temporary Array
 * - Create temporary copy of nums1 to preserve original values
 * - Use three pointers: i (temp array), j (nums2), k (result position)
 * - Compare elements and place smaller one in result position
 * - Handle remaining elements from both arrays
 * 
 * Time Complexity: O(m + n) - single pass through both arrays
 * Space Complexity: O(m) - temporary array for nums1
 */

#include <vector>
using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = 0, j = 0;  // Pointers for temp array and nums2
            int k = 0;         // Pointer for result position in nums1
            
            // Create temporary copy of nums1 to preserve original values
            vector<int> temp = nums1;
            
            // Merge process: compare elements from both arrays
            while (i < m && j < n){
                if(temp[i] < nums2[j]){
                    nums1[k++] = temp[i++];  // Take from temp (original nums1)
                }else{
                    nums1[k++] = nums2[j++]; // Take from nums2
                }
            }
    
            // Copy remaining elements from temp array (if any)
            while(i < m){
                nums1[k++] = temp[i++];
            }
            
            // Copy remaining elements from nums2 (if any)
            while(j < n){
                nums1[k++] = nums2[j++];
            }
        }
    };