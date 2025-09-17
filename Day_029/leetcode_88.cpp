#include <iostream>
#include <vector>
using namespace std;

/*
================================================================================
LeetCode 88: Merge Sorted Array
================================================================================
🔹 Problem Description:
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
and two integers m and n, representing the number of elements in nums1 and nums2.
Merge nums2 into nums1 as one sorted array. nums1 has size m+n with extra space.

--------------------------------------------------------------------------------
Example 1:
Input:  nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

Example 2:
Input:  nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]

Constraints:
* nums1.length == m + n
* nums2.length == n
* 0 <= m, n <= 200
* -10^9 <= nums1[i], nums2[i] <= 10^9
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
👉 Idea: Three-pointer merge using temporary copy of nums1

Steps:
1. Copy the first m elements of nums1 into a temp array.
2. Use pointers:
   - i → temp array (original nums1)
   - j → nums2
   - k → position in nums1 to place next element
3. Compare temp[i] and nums2[j]:
   - Place smaller value in nums1[k]
   - Increment corresponding pointer(s)
4. After loop, copy remaining elements (if any) from temp or nums2.
5. nums1 now contains merged sorted array.

⏱ Time Complexity: O(m + n)  
📦 Space Complexity: O(m) (for temp array)
================================================================================
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;  // * Pointers for temp and nums2
        int k = 0;         // * Pointer for position in nums1

        // * Temporary copy of nums1 to preserve original elements
        vector<int> temp(nums1.begin(), nums1.begin() + m);

        // * Merge process: compare elements from temp and nums2
        while (i < m && j < n) {
            if(temp[i] < nums2[j]) {
                nums1[k++] = temp[i++];  // * Take element from temp (nums1)
            } else {
                nums1[k++] = nums2[j++]; // * Take element from nums2
            }
        }

        // * Copy remaining elements from temp (if any)
        while(i < m) nums1[k++] = temp[i++];

        // * Copy remaining elements from nums2 (if any)
        while(j < n) nums1[k++] = nums2[j++];
    }
};

// ==================== Driver Code for Testing ====================
int main() {
    Solution obj;

    // * Example 1
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    obj.merge(nums1, 3, nums2, 3);
    cout << "Merged array: [";
    for(int i = 0; i < nums1.size(); i++) cout << nums1[i] << (i < nums1.size()-1 ? "," : "");
    cout << "]" << endl;

    // * Example 2
    vector<int> nums3 = {1};
    vector<int> nums4 = {};
    obj.merge(nums3, 1, nums4, 0);
    cout << "Merged array: [";
    for(int i = 0; i < nums3.size(); i++) cout << nums3[i] << (i < nums3.size()-1 ? "," : "");
    cout << "]" << endl;

    return 0;
}
