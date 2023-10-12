class Solution {
public:
    struct Pos {
        int scoreLeft;
        int scoreUp;
        int val;
    } dp[301][301];
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) dp[i][j].scoreLeft = (matrix[i][j]-'0');
                else dp[i][j].scoreLeft = (dp[i-1][j].scoreLeft + 1) * (matrix[i][j]-'0');
                dp[i][j].scoreUp = 0;
                dp[i][j].val = 0;
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (j == 0) dp[i][j].scoreUp = (matrix[i][j]-'0');
                else dp[i][j].scoreUp = (dp[i][j-1].scoreUp + 1) * (matrix[i][j]-'0');
            }
        }

        int mx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]-'0' == 1) {
                    dp[i][j].val = 1;
                    //how far left, how far up, how far diagionally
                    if (i != 0 && j != 0) {
                        int score = min(1 + dp[i-1][j].scoreLeft, 1 + dp[i][j-1].scoreUp);
                        score = min(score, 1 + dp[i-1][j-1].val);
                        dp[i][j].val = score;
                    }
                }
                else {
                    ;
                }
                mx = max(mx,dp[i][j].val * dp[i][j].val);
            }
        }
        return mx;
    }
};