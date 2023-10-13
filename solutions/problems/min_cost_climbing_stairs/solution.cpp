class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp;
        for (int i : cost) {
            dp.push_back(0);
        }
        dp.push_back(0);
        
        for (int i = 0; i <= cost.size(); i++) {
            if (i == 0) dp[i] = 0;
            else if (i == 1) dp[i] = 0;
            else {
                dp[i] = min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1]);
            }
        }
        return dp.back();
    }
};