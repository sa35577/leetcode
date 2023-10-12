class Solution {
public:
    struct Value {
        int countLeft;
        int countUp;
    } dp[151][151];
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) dp[i][j].countUp = mat[i][j];
                else {
                    dp[i][j].countUp = (dp[i-1][j].countUp + 1) * mat[i][j];
                }
            }
        }
        
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (j == 0) dp[i][j].countLeft = mat[i][j];
                else {
                    dp[i][j].countLeft = (dp[i][j-1].countLeft + 1) * mat[i][j];
                }
            }
        }
        
        int sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int mn = INT_MAX;
                for (int k = 0; k < dp[i][j].countLeft; k++) {
                    //cout << i << " " << j << " " << dp[i][j].countLeft << endl;
                    mn = min(mn,dp[i][j-k].countUp); 
                    sum += mn;
                }
            }
        }
        
        return sum;
    }
};