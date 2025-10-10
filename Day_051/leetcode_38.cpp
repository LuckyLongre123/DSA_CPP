class Solution {
    private:
        vector<pair<int, char>> strToPair(string str) {
            vector<pair<int, char>> ans;
            int count = 1;
            char c = str[0];
            int l = str.length();
            for (int i = 0; i < l - 1; i++) {
                if (str[i] == str[i + 1])
    
                    count++;
    
                else {
                    ans.push_back({count, c});
                    count = 1;
                    c = str[i + 1];
                }
            }
            ans.push_back({count, c});
    
            return ans;
        }
    
        string pairToStr(vector<pair<int, char>> strPair) {
            int s = strPair.size();
            string ans = "";
            for (int i = 0; i < s; i++) {
                ans += to_string(strPair[i].first) + strPair[i].second;
            }
            return ans;
        }
    
    public:
        string countAndSay(int n) {
            if (n == 1)
                return "1";
            string current = "1";
            while (--n) {
                vector<pair<int, char>> strPair = strToPair(current);
                current = pairToStr(strPair);
            }
            return current;
        }
    };
    