class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1);
        fill(dp.begin(),dp.end(),false);
        dp[0] = true;
        for (int i = 0; i < s.size(); i++) {
            if (dp[i]) {
                for (string word : wordDict) {
                    if (i + word.size() < dp.size() && s.substr(i,word.size()) == word) {
                        dp[i + word.size()] = true;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};