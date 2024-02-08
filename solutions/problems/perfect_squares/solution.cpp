class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
        for (int i = 1; i <= 100; i++) sq.push_back(i*i);
        vector<int> dp(n+1);
        fill(dp.begin(),dp.end(),100000);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++) {
            for (int &x : sq) {
                if (i - x < 0) break;
                dp[i] = min(dp[i],dp[i-x]+1);
            }
        }
        return dp.back();

    }
};