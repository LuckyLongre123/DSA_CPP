#include <iostream>
#include <vector>
using namespace std;

/* 
================================================================================
LeetCode Problem 852: Peak Index in a Mountain Array
================================================================================
An array `arr` is a **mountain array** if the following hold:
1. arr.length >= 3
2. There exists some index `i` (0 < i < arr.length - 1) such that:
   arr[0] < arr[1] < ... < arr[i-1] < arr[i] > arr[i+1] > ... > arr[n-1]

Given a mountain array `arr`, return the index `i` where arr[i] is the peak element.

--------------------------------------------------------------------------------
Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1

Example 3:
Input: arr = [0,10,5,2]
Output: 1

--------------------------------------------------------------------------------
Constraints:
* 3 <= arr.length <= 10^5
* 0 <= arr[i] <= 10^6
* arr is guaranteed to be a mountain array
================================================================================
✨ Easy Explanation (Beginner Friendly)
================================================================================
The array first increases (going uphill) → then decreases (going downhill).  
The "peak" is the highest point.

⚡ Trick:
- Use **binary search** instead of scanning the whole array.
- At each mid:
  - If arr[mid] < arr[mid+1], we are in **increasing part**, so move right.
  - Else, we are in **decreasing part** (peak is mid or left), so move left.

Finally, when `s == e`, that index is the peak.

⏱ Time Complexity: O(log n)  
📦 Space Complexity: O(1)
================================================================================
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;                  // * Start pointer
        int e = arr.size() - 1;     // * End pointer

        // * Binary search loop
        while (s < e) {
            int mid = s + (e - s) / 2;  // * Middle index (safe from overflow)

            // ? If middle < next → peak lies on the right
            if (arr[mid] < arr[mid + 1]) {
                s = mid + 1;  // * Move right
            } 
            // ? Otherwise → peak is mid or on the left
            else {
                e = mid;      // * Move left (include mid)
            }
        }

        // * At the end, s == e → peak index found
        return s;
    }
};

int main() {
    Solution obj;

    // * Example 1
    vector<int> arr1 = {0,1,0};
    cout << "Peak index in [0,1,0] → " 
         << obj.peakIndexInMountainArray(arr1) << endl;

    // * Example 2
    vector<int> arr2 = {0,2,1,0};
    cout << "Peak index in [0,2,1,0] → " 
         << obj.peakIndexInMountainArray(arr2) << endl;

    // * Example 3
    vector<int> arr3 = {0,10,5,2};
    cout << "Peak index in [0,10,5,2] → " 
         << obj.peakIndexInMountainArray(arr3) << endl;

    return 0;
}
