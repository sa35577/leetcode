class Solution {
public:
    bool test(vector<int>& w, int days, int test) {
        int cap = 0;
        int cnt = 0;
        for (int x : w) {
            if (cap + x <= test) {
                cap += x;
            }
            else {
                cnt += 1;
                cap = x;
            }
        }
        cnt += 1;
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int L = 1, R = INT_MAX - 1000;
        for (int w : weights) {
            L = max(L,w);
        }
        while (L+1 < R) {
            if (test(weights,days,(L+R)/2)) R = (L+R)/2;
            else L = (L+R)/2+1;
        }
        if (test(weights,days,L)) return L;
        return R;
    }
};