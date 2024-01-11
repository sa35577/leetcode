class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dp(100);
        fill(dp.begin(),dp.end(),INT_MAX);
        vector<int> ndp(100);
        fill(ndp.begin(),ndp.end(),INT_MAX);
        dp[src] = 0;
        for (int _ = 0; _ <= k; _++) {
            for (vector<int> flight : flights) {
                if (dp[flight[0]] != INT_MAX) {
                    ndp[flight[1]] = min(ndp[flight[1]],dp[flight[0]]+flight[2]);
                }
            }
            for (int i = 0; i < 100; i++) {
                ndp[i] = min(ndp[i],dp[i]);
                // if (i < n) cout << ndp[i] << " ";
                dp[i] = ndp[i];
                ndp[i] = INT_MAX;
            }
            // cout << endl;
        }
        if (dp[dst] == INT_MAX) return -1;
        return dp[dst];

    }
};