class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int dp[1005][105];
        int best = 0;
        for (int i = 0; i < 1005; i++) {
            for (int j = 0; j < 105; j++) {
                dp[i][j] = 0;
            }
        }
        for (int kk = 1; kk <= k; kk++) {
            int bestValue = INT_MIN;
            for (int i = 0; i < prices.size(); i++) {
                dp[i][kk] = max(dp[i][kk-1],bestValue+prices[i]);
                bestValue = max(bestValue,dp[i][kk-1] - prices[i]);
                if (i > 0) dp[i][kk] = max(dp[i][kk],dp[i-1][kk]);
                best = max(best,dp[i][kk]);
                // cout << dp[i][kk] << " ";
            }
            // cout << endl;
        }
        return best;
    }
};