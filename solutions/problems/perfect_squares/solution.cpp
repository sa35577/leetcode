class Solution {
public:
    int numSquares(int n) {
        int sq[102];
        for (int i = 0; i < 102; i++) sq[i] = i*i;
        vector<int> dp(n+1);
        for (int i = 1; i <= n; i++) dp[i] = 100000;
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 102; j++) {
                if (i+sq[j] <= n && dp[i+sq[j]] > dp[i]+1) {
                    dp[i+sq[j]] = dp[i]+1;
                }
            }
        }
        return dp.back();
    }
};