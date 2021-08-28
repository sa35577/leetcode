class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount+1);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = LLONG_MAX;
            for (int j : coins) {
                if (i-j >= 0 && dp[i-j] != LLONG_MAX) {
                    dp[i] = min(dp[i],dp[i-j]+1);
                }
            }
        }
        return (int)dp.back();
        
    }
};