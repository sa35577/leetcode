class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp{cost[0],cost[1]};
        for (int i = 2; i < cost.size(); i++) {
            dp.push_back(min(dp[i-2]+cost[i], dp[i-1] + cost[i]));
        }
        int n = cost.size()-1;
        return min(dp[n],dp[n-1]);
    }
};