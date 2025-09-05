// LeetCode Problem 852: Peak Index in a Mountain Array
// An array arr a mountain if the following properties hold:
// - arr.length >= 3
// - There exists some i with 0 < i < arr.length - 1 such that:
//   arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[i] is the peak element.
// Example 1: Input: arr = [0,1,0], Output: 1
// Example 2: Input: arr = [0,2,1,0], Output: 1

#include <vector>
using namespace std;

class Solution {
    public:
        // Function to find peak index in mountain array using binary search
        int peakIndexInMountainArray(vector<int>& arr) {
            int s = 0;                    // Start pointer
            int e = arr.size() - 1;       // End pointer
    
            // Binary search to find the peak
            while(s < e){
                int mid = s + (e - s)/2;  // Calculate middle to avoid overflow
                
                // If mid element is smaller than next element, peak is on the right
                if(arr[mid] < arr[mid + 1]){
                    s = mid + 1;  // Move to right half (ascending part)
                }else{
                    // If mid element is greater than or equal to next element
                    // Peak is at mid or on the left side
                    e = mid;      // Move to left half (including mid)
                }
            }
            
            // When s == e, we found the peak index
            return s;
        }
    };