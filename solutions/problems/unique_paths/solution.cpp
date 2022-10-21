class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[100][100];
        for (int i = 0; i < 100; i++) {
            dp[i][0] = 1;
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        // m--;
        // n--;
        // if (m+n == 0) return 1;
        // //m+n choose m = (m+n)!/m!*n!
        // long long num = 1;
        // long long denom = 1;
        // for (int i = max(m,n)+1; i <= m+n; i++) {
        //     long long x = (long long)(i);
        //     num *= x;
        // }
        // for (int i = min(m,n); i >= 1; i--) {
        //     long long x = (long long)(i);
        //     denom *= x;
        // }
        // long long res = num / denom;
        // return (int)(res);


    }
};