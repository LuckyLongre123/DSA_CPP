class Solution {
private:
    void getLetterCombinations(string digits, string output, int index, vector<string>& ans, string map[]) {
        // base case
        if (index >= digits.length()) {
            ans.push_back(output);
            return;
        }

        int numIndex = digits[index] - '0';
        string val = map[numIndex];

        for (int i = 0; i < val.length(); i++) {
            output.push_back(val[i]);
            getLetterCombinations(digits, output, index + 1, ans, map);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {

        if (digits == "")
            return {};
        vector<string> ans;
        string map[10] = {"",    "",    "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};
        getLetterCombinations(digits, "", 0, ans, map);

        return ans;
    }
};