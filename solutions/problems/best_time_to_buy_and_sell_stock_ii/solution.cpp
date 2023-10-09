class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp;
        for (int i = 0; i < prices.size(); i++) dp.push_back(0);
        dp[0] = -prices[0];
        int mx = -prices[0];
        for (int i = 1; i < dp.size(); i++) {
            if (prices[i] + mx > dp[i]) {
                dp[i] = prices[i] + mx;
            }
            dp[i] = max(dp[i],dp[i-1]);
            mx = max(mx,dp[i]-prices[i]);
            // cout << dp[i] << " ";
        }
        int bestScore = 0;
        for (int x : dp) bestScore = max(x,bestScore);
        return bestScore;
    }
};