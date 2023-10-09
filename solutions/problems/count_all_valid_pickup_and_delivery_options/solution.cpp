class Solution {
public:
    long long fact[501];
    map<pair<int,int>, long long> mp;
    long long cnt(int n, int openSoFar, int diff) {
        // cout << openSoFar << " " << diff << endl;
        //diff = left - right
        if (mp.find({openSoFar,diff}) != mp.end()) return mp[{openSoFar,diff}];
        if (openSoFar == n) {
            mp[{openSoFar,diff}] = fact[diff];
            return mp[{openSoFar,diff}];
        }
        long long sum = ((n-openSoFar)*cnt(n,openSoFar+1,diff+1)) % 1000000007LL;
        if (diff > 0) sum = (sum + diff * cnt(n,openSoFar,diff-1)) % 1000000007LL;
        mp[{openSoFar,diff}] = sum;
        return sum;
    }
    int countOrders(int n) {
        fact[0] = 1;
        for (int i = 1; i <= 500; i++) fact[i] = (i * fact[i-1]) % 1000000007LL;
        return (int)cnt(n,0,0);
    }
};