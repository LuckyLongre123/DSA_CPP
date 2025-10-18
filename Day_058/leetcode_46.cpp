class Solution {
private:
    void getPermutes(vector<int> nums, int i, vector<vector<int>>& ans) {
        // base case
        if (i >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            getPermutes(nums, i + 1, ans);
            swap(nums[i], nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPermutes(nums, 0, ans);
        return ans;
    }
};