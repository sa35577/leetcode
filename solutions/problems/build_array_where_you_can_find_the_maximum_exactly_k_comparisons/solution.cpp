class Solution {
public:
    long long MOD = 1000000007;
    unordered_map<int,long long> mp;
    int M,N;
    int hash(int i, int mx, int r) {
        return i * 1000 * 1000 + mx * 1000 + r;
    }

    int rec(int i, int mx, int r) {
        if (mp.find(hash(i,mx,r)) != mp.end()) return mp[hash(i,mx,r)];
        if (i == N) {
            if (r == 0) {
                mp[hash(i,mx,r)] = 1;
                return mp[hash(i,mx,r)];
            }
            else {
                return 0;
            }
        }
        if (r < 0) return 0;
        long long ans = 0;
        for (int x = 1; x <= mx; x++) {
            ans = (ans + rec(i+1,mx,r)) % MOD;
        }
        for (int x = mx+1; x <= M; x++) {
            ans = (ans + rec(i+1,x,r-1)) % MOD;
        }
        mp[hash(i,mx,r)] = ans;
        return mp[hash(i,mx,r)];
    }
    int numOfArrays(int n, int m, int k) {
        M = m; N = n;
        return (int)(rec(0,0,k));
    }

};