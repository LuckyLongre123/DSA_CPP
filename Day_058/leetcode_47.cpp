class Solution {
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans,
                   vector<int>& current, vector<bool>& used) {
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, ans, current, used);
            used[i] = false;
            current.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, current, used);
        return ans;
    }
};
