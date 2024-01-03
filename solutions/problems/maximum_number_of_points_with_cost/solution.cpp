typedef long long ll;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<vector<ll>> dp(points.size());
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points[0].size(); j++) {
                dp[i].push_back((ll)(points[i][j]));
            }
        }
        for (int row = 1; row < points.size(); row++) {
            vector<ll> best = dp[row-1];
            int bestidx = 0;
            //sweep left -> right
            for (int col = 1; col < points[0].size(); col++) {
                if (dp[row-1][bestidx] - dp[row-1][col] >= (ll)(col - bestidx)) {
                    best[col] = max(best[col],dp[row-1][bestidx] - (ll)(col - bestidx));
                }
                else {
                    bestidx = col;
                }
            }
            bestidx = points[0].size()-1;
            //sweep right -> left
            for (int col = points[0].size()-2; col >= 0; col--) {
                if (dp[row-1][bestidx] - dp[row-1][col] >= (ll)(bestidx-col)) {
                    best[col] = max(best[col],dp[row-1][bestidx]-(ll)(bestidx-col));
                }
                else {
                    bestidx = col;
                }
            }
            for (int i = 0; i < dp[row].size(); i++) {
                dp[row][i] += best[i];
            }
        }
        vector<ll> last = dp.back();
        ll mx = -1;
        for (ll entry : last) {
            mx = max(entry,mx);
        }
        return mx;
    }
};