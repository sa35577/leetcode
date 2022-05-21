class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = -1, mx = 0;
        mn = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            mx = max(prices[i]-mn,mx);
            mn = min(mn,prices[i]);
        }
        return mx;
    }
};