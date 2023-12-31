class Solution {
public:
    int f(int x) {
        return x + 20000;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int dp[40005];
        int ndp[40005];
        memset(dp,0,sizeof(dp));
        memset(ndp,0,sizeof(ndp));
        dp[f(0)] = 1;
        for (int x : nums) {
            for (int i = 0; i < 40005; i++) {
                if (dp[i] > 0) {
                    ndp[i+x] += dp[i];
                    ndp[i-x] += dp[i];
                }
            }
            for (int i = 0; i < 40005; i++) dp[i] = ndp[i];
            memset(ndp,0,sizeof(ndp));
            // for (int i = -5; i <= 5; i++) cout << dp[f(i)] << " ";
            cout << endl;
        }
        return dp[f(target)];
    }
};