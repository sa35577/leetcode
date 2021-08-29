class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(obstacleGrid.size());
        for (int i = 0; i < dp.size(); i++) {
            vector<int> v (obstacleGrid[0].size());
            dp[i] = v;
        }
        for (int i = 0; i < obstacleGrid[0].size(); i++) {
            if (obstacleGrid[0][i] == 0) dp[0][i] = 1;
            else break;
        }
        for (int i = 0; i < obstacleGrid.size(); i++) {
            if (obstacleGrid[i][0] == 0) dp[i][0] = 1;
            else break;
        }
        for (int i = 1; i < obstacleGrid.size(); i++) {
            for (int j = 1; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else dp[i][j] = 0;
            }
        }
        return dp.back().back();
    }
};