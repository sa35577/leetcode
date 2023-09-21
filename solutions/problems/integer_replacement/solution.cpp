class Solution {
public:
    
    map<long long, int> mp;
    int intReploacement(long long N) {
        if (mp.find(N) != mp.end()) return mp[N];
        if (N == 1) {
            mp[1] = 0;
            return mp[1];
        }
        if (N % 2 == 0) {
            mp[N] = 1 + intReploacement(N/2);
            return mp[N];
        }
        else {
            mp[N] = 1 + min(intReploacement(N-1),intReploacement(N+1));
            return mp[N];
        }
        return mp[N];

    }
    int integerReplacement(int n) {
        return intReploacement((long long)(n));
    }
};