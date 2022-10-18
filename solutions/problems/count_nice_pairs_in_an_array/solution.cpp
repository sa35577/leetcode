class Solution {
public:
    long long calc(int l, int r) {
        long long dist = (r-l+1);
        long long ret = (dist - 1) * (dist);
        ret = ret/2;
        return ret;
    }
    int countNicePairs(vector<int>& nums) {
        vector<long long> n, rn;
        for (int x : nums) {
            n.push_back((long long)x);
            long long res = 0, cur = n.back();
            while (cur > 0) {
                res = res * 10 + (cur % 10);
                cur /= 10;
            }
            rn.push_back(res);
        }
        vector<long long> diffs;
        for (int i = 0; i < n.size(); i++) {
            diffs.push_back(n[i]-rn[i]);
        }
        long long MOD = 1000000007, cnt = 0;
        sort(diffs.begin(),diffs.end());
        int l=0,r=0;
        while (l < diffs.size()) {
            while (r+1 < diffs.size() && diffs[r+1] == diffs[l]) r++;
            cnt = (cnt + calc(l,r)) % MOD;
            l = r+1;
        }
        return (int)(cnt);

    }
};