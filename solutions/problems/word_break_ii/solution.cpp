class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> dp(s.size()+1);
        dp[0] = {""};
        for (int i = 0; i < s.size(); i++) {
            if (dp[i].size() != 0) {
                for (string word : wordDict) {
                    if (i + word.size() < dp.size() && s.substr(i,word.size()) == word) {
                        for (string v : dp[i]) {
                            if (v != "") {
                                v += " " + word;
                            }
                            else v += word;
                            dp[i + word.size()].push_back(v);
                        }
                    }
                }
            }
        }
        return dp.back();
        
        
    }
};