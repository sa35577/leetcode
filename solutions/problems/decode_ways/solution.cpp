class Solution {
public:
    int numDecodings(string s) {
        int dp[101];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < s.size(); i++) {
            //cout << dp[i] << " ";
            if (s[i] != '0') {
                if (INT_MAX - dp[i+1] >= dp[i]) dp[i+1] += dp[i];
                else dp[i+1] = INT_MAX;
                
                if (i != s.size() - 1) {
                    int val = 10 * (s[i]-'0') + (s[i+1]-'0');
                    if (val >= 1 && val <= 26) {
                        if (INT_MAX - dp[i+2] >= dp[i]) dp[i+2] += dp[i];
                        else dp[i+2] = INT_MAX;
                    }
                }
            }
            
        }
        return dp[s.size()];
    }
};