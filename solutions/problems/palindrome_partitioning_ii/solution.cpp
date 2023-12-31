#define ll long long
class Solution {
public:

    bool isPalindrome(string &s, int L, int R) {
        // while (R >= 0 && L < s.size() && L <= R) {
        while (L <= R) {
            if (s[L] != s[R]) return false;
            L++;
            R--;
        }
        return true;
    }
    int minCut(string s) {
        vector<int> endPalindrome[2005];

        ll pows[2005];
        ll mod = 1000000007LL;
        pows[0] = 1;
        for (int i = 1; i < 2005; i++) {
            pows[i] = (pows[i-1] * (27LL)) % mod;
        }

        for (int i = 0; i < s.size(); i++) {
            ll hashforward = 0LL, hashbackward = 0LL;
            for (int j = i; j >= 0; j--) {
                hashforward += (pows[i-j] * (ll)(s[j]-'a'+1)) % mod;
                hashforward %= mod;
                hashbackward = ((hashbackward * (27LL)) % mod + (ll)(s[j]-'a'+1)) % mod;
                if (hashforward == hashbackward && isPalindrome(s,j,i)) {
                    endPalindrome[i].push_back(j-1);
                }
            }
        }
        vector<int> dp(2005);
        fill(dp.begin(),dp.end(),100000);
        for (int i = 0; i < s.size(); i++) {
            for (int j : endPalindrome[i]) {
                if (j == -1) dp[i] = min(1,dp[i]);
                else dp[i] = min(dp[i],dp[j]+1);
            }
        }
        return dp[s.size()-1]-1;

    }
};