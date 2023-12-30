class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[10001];
        fill(dp,dp+10001,INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i-coin] != INT_MAX) {
                    dp[i] = min(dp[i],dp[i-coin]+1);
                }
            }
        }
        if (dp[amount] == INT_MAX) return -1; 
        return dp[amount];
    }
};