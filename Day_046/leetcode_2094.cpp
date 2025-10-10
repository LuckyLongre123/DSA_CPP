class Solution {
    public:
        vector<int> findEvenNumbers(vector<int>& digits) {
            set<int> st;
    
            int n = digits.size();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        if (i == j || j == k || i == k)
                            continue;
    
                        int d1 = digits[i], d2 = digits[j], d3 = digits[k];
    
                        if (d1 == 0)
                            continue;
    
                        if (d3 % 2 != 0)
                            continue;
    
                        int num = d1 * 100 + d2 * 10 + d3;
                        st.insert(num);
                    }
                }
            }
            return vector<int>(st.begin(), st.end());
        }
    };