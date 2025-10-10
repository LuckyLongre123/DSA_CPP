class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            vector<int> seen(256, -1);
            int maxLen = 0;
            int st = 0;
    
            for (int i = 0; i < s.size(); i++) {
                if (seen[s[i]] >= st) {
                    st = seen[s[i]] + 1;
                }
                seen[s[i]] = i;
                maxLen = max(maxLen, i - st + 1);
            }
    
            return maxLen;
        }
    };
    