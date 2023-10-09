class Solution {
public:
    int maxProfit(vector<int>& prices) {
        bool descending = true;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - prices[i-1] > 0) {
                descending = false;
                break;
            }
        }
        if (descending) return 0;
        vector<int> dp1,dp2;
        for (int i = 0; i < prices.size(); i++) {
            dp1.push_back(INT_MIN);
            dp2.push_back(INT_MIN);
        }

        dp1[0] = -prices[0];
        int mn = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - mn > dp1[i]) {
                dp1[i] = prices[i] - mn;
            }
            dp1[i] = max(dp1[i],dp1[i-1]);
            mn = min(mn,prices[i]);
            // cout << dp1[i] << " ";
        }
        // cout << endl;
        dp2[0] = dp1[0];
        int bestidx = 0;
        int mx = dp1[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] + mx > dp2[i]) {
                dp2[i] = prices[i] + mx;
            }
            dp2[i] = max(dp2[i],dp2[i-1]);
            if (dp1[i] - prices[i] > mx) {
                bestidx = i;
                mx = dp1[i] - prices[i];
            }
        }
        int bestVal = INT_MIN;
        for (int i : dp1) bestVal = max(bestVal,i);
        for (int i : dp2) bestVal = max(bestVal,i);
        return bestVal;
    }
};