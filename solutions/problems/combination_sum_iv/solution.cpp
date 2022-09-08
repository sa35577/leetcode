class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int dp[1001];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < target; i++) {
            for (int c : nums) {
                if (i + c <= target) {
                    if (INT_MAX - dp[i+c] >= dp[i]) dp[i+c] += dp[i];
                    else dp[i+c] = INT_MAX;
                }
            }
        }
        return dp[target];
    }
};