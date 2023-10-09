class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp[i] = max if you sell at i
        //dp[i] = max(dp[i-2] + min(prices[i-1]), dp[i-3] + min(prices[i-2],prices[i-1]),..)

        if (prices.size() == 1) return 0;
        if (prices.size() == 2) return max(prices[1]-prices[0],0);
        vector<int> dp;
        dp.resize(prices.size());
        dp[0] = 0;
        dp[1] = max(prices[1]-prices[0],0);
        for (int i = 2; i < prices.size(); i++) {
            int mn = INT_MAX;
            dp[i] = 0;
            for (int j = i-2; j >= 0; j--) {
                dp[i] = max(dp[i],dp[j]+prices[i]-mn);
                mn = min(mn,prices[j+1]);
            }
            //case for start from beginning
            dp[i] = max(dp[i],0+prices[i]-mn);
            dp[i] = max(dp[i],0+prices[i]-prices[0]);
            cout << dp[i] << " ";
        }
        int mx = -1;
        for (int x : dp) mx = max(mx,x);
        return mx;
    }
};