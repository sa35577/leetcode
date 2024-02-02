class Solution {
public:
    const int mod = 1e9+7;
    int calcsum(vector<int>& psa, int R, int sz) {
        if (R < sz) return psa[R];
        int notinc = R-sz;
        return ((psa[R] - psa[notinc]) % mod + mod) % mod;
    }
    int kInversePairs(int n, int k) {
        
        int dp[1001][1001];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            vector<int> psa;
            psa.push_back(dp[i-1][0]);
            for (int j = 1; j <= k; j++) {
                psa.push_back((psa.back() + dp[i-1][j]) % mod);
            }
            for (int j = 0; j <= k; j++) {
                dp[i][j] = calcsum(psa,j,i);
            }
        }
        return dp[n][k];
    }
};