class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            int one = cost[0], two = cost[1];
            for (int i = 2; i < n; i++) {
                int current = cost[i] + min(one, two);
                one = two;
                two = current;
            }
            return min(one, two);
        }
    };