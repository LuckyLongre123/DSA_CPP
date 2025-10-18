class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int valtoremin = 0; 
        int n = nums.size();
        if(n < 2) return n;

        int maxLen = 2, curLen = 2;

        for(int i = 2; i < n; i++){
            if(nums[i] == nums[i-1] + nums[i-2]){
                curLen++;
            } else {
                curLen = 2;
            }
            maxLen = max(maxLen, curLen);
            valtoremin = curLen;
        }

        return maxLen;
    }
};