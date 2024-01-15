class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size());
        dp[0] = {{nums[0]}};
        set<vector<int>> st;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] <= nums[i]) {
                    for (vector<int> v : dp[j]) {
                        
                        v.push_back(nums[i]);
                        dp[i].push_back(v);
                    }
                }
            }
            for (vector<int> v : dp[i]) {
                st.insert(v);
            }
            dp[i].push_back({nums[i]});
        }
        vector<vector<int>> res;
        for (vector<int> v : st) {
            res.push_back(v);
        }
        return res;

    }
};