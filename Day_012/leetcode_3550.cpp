// LeetCode Problem 3550: Find the Smallest Index Where Index Equals Sum of Digits
// Given an array of integers, find the smallest index i such that i equals the sum of digits of nums[i].
// Return the smallest such index, or -1 if no such index exists.
// Example: nums = [12, 34, 5, 67] → index 2 has value 5, sum of digits = 5, so return 2

#include <vector>
using namespace std;

class Solution {
    public:
        // Function that finds the smallest index where index equals sum of digits of the element at that index
        int smallestIndex(vector<int>& nums) {       
            // Iterate through each index in the array
            for(int i = 0; i < nums.size(); i++){
                // Get the current number at index i
                int temp = nums[i];
                int sum = 0;
                
                // Calculate sum of digits of the current number
                while(temp != 0){
                    sum += temp % 10;  // Add the last digit to sum
                    temp /= 10;        // Remove the last digit from temp
                }
                
                // Check if current index equals the sum of digits
                if(i == sum) return i;  // Return the index if condition is met
            }
            
            // Return -1 if no index satisfies the condition
            return -1;
        }
    };