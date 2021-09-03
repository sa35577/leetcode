class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = prices.back();
        int best = 0;
        for (int i = prices.size()-2; i >= 0; i--) {
            best = max(best,mx-prices[i]);
            mx = max(mx,prices[i]);
        }
        return best;
        
    }
};