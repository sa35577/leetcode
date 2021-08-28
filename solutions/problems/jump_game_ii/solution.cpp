#include <bits/stdc++.h>
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size());
        for (int i = 1; i < dp.size(); i++) dp[i] = INT_MAX;
        dp[0] = 0;
        for (int i = 0; i < dp.size()-1; i++) {
            if (dp[i] != INT_MAX) {
                for (int j = i+1; j < min((int)dp.size(),i+nums[i]+1); j++) {
                    dp[j] = min(dp[j],dp[i]+1);
                }
            }
        }
        return dp.back();
    }
};