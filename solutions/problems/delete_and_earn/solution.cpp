class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> vals;
        int idx = 0, jmp = 0;
        while (idx < nums.size()) {
            pair<int,int> p = {nums[idx],0};
            jmp = 1;
            while (idx+jmp < nums.size() && nums[idx+jmp] == nums[idx]) jmp++;
            p.second = jmp;
            vals.push_back(p);
            idx = idx+jmp;
        }
        vector<int> dp(vals.size());
        dp[0] = vals[0].first * vals[0].second;
        for (int i = 1; i < vals.size(); i++) {
            if (i == 1) {
                if (vals[1].first - vals[0].first == 1) {
                    dp[i] = max(dp[i-1],vals[1].first*vals[1].second);
                }
                else {
                    dp[i] = dp[i-1] + vals[1].first*vals[1].second;
                }
            }
            else {
                if (vals[i].first - vals[i-1].first == 1) {
                    dp[i] = max(dp[i-1],dp[i-2] + vals[i].first*vals[i].second);     
                }
                else {
                    dp[i] = dp[i-1] + vals[i].first*vals[i].second;
                }
            }
            
        }
        return dp.back();
    }
};