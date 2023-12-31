class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size()) return 0;
        if (s.size() == t.size()) {
            if (s == t) return 1;
            return 0;
        }
        int prev[1005], cur[1005];
        memset(prev,0,sizeof(prev));
        memset(cur,0,sizeof(cur));
        if (s[0] == t[0]) prev[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            prev[i] = prev[i-1];
            if (s[i] == t[0]) prev[i]++;
        }
        for (int i = 1; i < t.size(); i++) {
            for (int j = i; j <= s.size(); j++) {
                cur[j] = cur[j-1];
                if (s[j] == t[i] && INT_MAX - cur[j] >= prev[j-1]) {
                    cur[j] += prev[j-1];
                } 
            }

            for (int j = 0; j < 1005; j++) prev[j] = cur[j];
            memset(cur,0,sizeof(cur));
        }
        return prev[s.size()];
    }
};