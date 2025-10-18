class Solution {
private:
    void getSubSets(vector<int> nums, vector<int> otp, int index, vector<vector<int>>& ans) {
        if (index >= nums.size()) {
            ans.push_back(otp);
            return;
        }

        getSubSets(nums, otp, index + 1, ans);

        otp.push_back(nums[index]);
        getSubSets(nums, otp, index + 1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        getSubSets(nums, {}, 0, ans);

        return ans;
    }
};