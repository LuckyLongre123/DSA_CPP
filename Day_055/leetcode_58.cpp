class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();

        int i = n - 1;

        while (i >= 0 && s[i] == ' ')
            i--;

        if (i == -1)
            return 0;

        int j = i;
        while (j >= 0 && s[j] != ' ')
            j--;

        if (j == -1)
            return i + 1;

        return i - j;
    }
};