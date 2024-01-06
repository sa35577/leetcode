class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % 2 == 1) return false;
        bool dp[20005];
        bool ndp[20005];
        fill(dp,dp+20005,false);
        fill(ndp,ndp+20005,false);
        dp[0] = 1;
        for (int x : nums) {
            for (int i = 0; i < 20005; i++) {
                if (dp[i]) ndp[i+x] = 1;
            }
            for (int i = 0; i < 20005; i++) {
                dp[i] = ndp[i];
            }
        }
        return dp[sum/2];
    }
};