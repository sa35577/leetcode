class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int dp[201][201];
        for (int i = 0; i <= 200; i++) {
            for (int j = 0; j <= 200; j++) dp[i][j] = 0;
        }
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) dp[i][j] = dp[i-1][0];
                else if (j == i) dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]);
                }
                dp[i][j] += triangle[i][j];
            }
        }
        int mn = INT_MAX;
        int last = triangle.size()-1;
        for (int i = 0; i < triangle.size(); i++) {
            mn = min(mn,dp[last][i]);
        }
        return mn;
    }
    
};