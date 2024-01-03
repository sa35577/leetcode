class Solution {
public:
    int maxVal(vector<int> &v) {
        int mx = -1;
        for (int i : v) mx = max(mx,i);
        return mx;
    }
    bool test(vector<int>& candies, long long k, int sz) {
        if (sz == 0) return true;
        long long score = 0;
        for (int i : candies) {
            score += (long long)(i / sz);
        }
        return (score >= k);
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int L = 0;
        int R = maxVal(candies);
        while (L+1 < R) {
            int mid = (L+R)/2;
            if (test(candies,k,mid)) {
                L = mid;
            }
            else {
                R = mid-1;
            }
        }
        if (test(candies,k,R)) return R;
        return L;

    }
};