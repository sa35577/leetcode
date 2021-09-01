class Solution {
public:
    int rob(vector<int>& nums) {
        int mx = -1;
        //include first house
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(dp[0],nums[1]);
        for (int i = 2; i < dp.size()-1; i++) {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        mx = dp[dp.size()-2];
        //don't include first house
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        mx = max(mx,dp.back());
        return mx;
        
    }
};