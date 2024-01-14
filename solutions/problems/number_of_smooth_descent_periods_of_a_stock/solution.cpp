class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int L = 0;
        long long tot = 0;
        while (L < prices.size()) {
            int R = L;
            while (R+1 < prices.size() && prices[R+1] == prices[R] - 1) R++;
            long long diff = (long long)(R - L + 1);
            tot += (diff * (diff + 1))/2LL;
            L = R+1;
        }
        return tot;
    }
};