class Solution {
public:
    bool scoreBalance(string s) {
        int totalSum = 0;
        for (char ch : s)
            totalSum += ch - 'a' + 1;

        int leftSum = 0;
        for (int i = 0; i < s.length() - 1; i++) { 
            leftSum += s[i] - 'a' + 1;
            int rightSum = totalSum - leftSum;
            if (leftSum == rightSum)
                return true;  
        }
        return false;  
    }
};
