class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        for (int num : nums) {
            totalXor ^= num;
        }
        if (totalXor!= 0)
            return nums.size();

        for (int num : nums)
            if (num != 0)
                return nums.size() - 1;
        return 0;
    }
};