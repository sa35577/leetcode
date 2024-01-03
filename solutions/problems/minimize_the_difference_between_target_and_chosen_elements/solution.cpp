class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        bool dp[4905];
        bool ndp[4905];
        fill(dp,dp+4905,false);
        fill(ndp,ndp+4905,false);
        dp[0] = true;
        for (int row = 0; row < mat.size(); row++) {
            for (int i = 0; i < 4905; i++) {
                if (dp[i]) {
                    for (int col = 0; col < mat[0].size(); col++) {
                        if (i + mat[row][col] < 4905) {
                            ndp[i + mat[row][col]] = 1;
                        }
                    }
                }
            }
            for (int i = 0; i < 4905; i++) {
                dp[i] = ndp[i];
                ndp[i] = 0;
            }
        }
        if (dp[target]) return 0;
        int diff = 1;
        while (diff < 4905) {
            if (target-diff >= 0 && dp[target-diff]) return diff;
            else if (target+diff < 4905 && dp[target+diff]) return diff;
            diff++;
        }
        return -1;
    }
};