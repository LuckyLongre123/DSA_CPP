class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        int sz = int(s.length());
        if (numRows < sz)
            sz = numRows;

        vector<string> rows(sz);

        bool down = false;
        int curRow = 0;
        for (char ch : s) {
            rows[curRow] += ch;

            if (curRow == 0)
                down = true;
            else if (curRow == numRows - 1)
                down = false;
            curRow += down ? 1 : -1;
        }
        string ans = "";
        for (string row : rows) {
            ans += row;
        }
        return ans;
    }
};