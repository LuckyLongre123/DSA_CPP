class Solution {
    public:
        int climbStairs(int n) {
            if (n <= 2)
                return n;
            int one = 1, two = 2, current = 0;
            for (int i = 3; i <= n; i++) {
                current = one + two;
                one = two;
                two = current;
            }
            return two;
        }
    };