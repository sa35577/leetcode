class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1); //dp[i] represents number of ways of s(i...n)
        dp.back() = 1;
        for (int tail = s.size()-1; tail >= 0; tail--) {
            if (s[tail] >= '1' && s[tail] <= '9') dp[tail] += dp[tail+1];
            if (tail >= 1) {
                if (s[tail-1] == '1' || (s[tail-1] == '2' && s[tail] >= '0' && s[tail] <= '6')) {
                    dp[tail-1] += dp[tail+1]; 
                }
            }
        }
        return dp[0];
    }
};