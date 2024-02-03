class Solution {
public:
    int is5Pow(int x) {
        if (x == 1) return true;
        if (x % 5 != 0) return false;
        return is5Pow(x/5);
    }
    int minimumBeautifulSubstrings(string s) {
        vector<int> dp(s.size()+1);
        fill(dp.begin(),dp.end(),-1);
        dp[0] = 0;
        for (int i = 0; i < s.size(); i++) {
           if (s[i] == '0') continue;
           if (dp[i] == -1) continue;
           int v = 0;
           for (int j = i; j < s.size(); j++) {
               v = v*2 + (s[j]-'0');
               if (is5Pow(v)) {
                   if (dp[j+1] == -1) dp[j+1] = dp[i]+1;
                   else dp[j+1] = min(dp[j+1],dp[i]+1);
               }
           }
        }
        return dp.back();
    }
};