#define ll long long
class Solution {
public:
    ll pows[50005];
    ll mod = 1000000007LL;
    string shortestPalindrome(string s) {
        pows[0] = 1;
        for (int i = 1; i < 50005; i++) {
            pows[i] = pows[i-1] * (27LL);
            pows[i] %= mod;
        }
        if (s.size() < 2) return s;
        int mxidx = -1;
        ll hashfront = 0, hashback = 0;
        for (int i = 0; i < s.size(); i++) {
            hashfront = (hashfront * (27LL)) % mod;
            hashfront = (hashfront + (long long)(s[i]-'a'+1)) % mod;
            hashback = (hashback + ((long long)(s[i]-'a'+1) * pows[i]) % mod) % mod;
            if (hashfront == hashback && s[0] == s[i]) mxidx = i;
        }
        string frontprefix = "";
        for (int i = mxidx+1; i < s.size(); i++) frontprefix += s[i];
        reverse(frontprefix.begin(),frontprefix.end());
        return frontprefix + s;
    }
};