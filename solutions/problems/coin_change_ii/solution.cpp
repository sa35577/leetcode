class Solution {
public:
    int change(int amount, vector<int>& coins) {
        long long dp[5001];
        for (int i = 1; i <= 5000; i++) dp[i] = 0;
        dp[0] = 1;
        for (int coin : coins) {
            for (int j = coin; j <= 5000; j++) {
                dp[j] += dp[j-coin];
            }
        }
        return (int)(dp[amount]);
    }
};