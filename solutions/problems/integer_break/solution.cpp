class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        int mx = 1;
        for (int k = 2; k <= n; k++) {
            vector<int> v;
            for (int i = 0; i < k; i++) v.push_back(n/k);
            for (int i = 0; i < n%k; i++) v[i]++;
            int prod = 1;
            for (int i : v) {
                prod *= i;
            }
            mx = max(mx,prod);
        }
        return mx;
    }

};