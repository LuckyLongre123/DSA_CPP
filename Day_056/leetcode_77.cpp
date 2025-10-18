class Solution {
private:
    void solve(int start, int n, int k, vector<int> output,
               vector<vector<int>>& ans) {
        // base case
        if (output.size() == k) {
            ans.push_back(output);
            return;
        }

        for (int i = start; i <= n; i++) {
            output.push_back(i);
            solve(i + 1, n, k, output, ans);
            output.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        solve(1, n, k, {}, ans);
        return ans;
    }
};