#include <unordered_set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        int L = 0, R = 0;
        int mx = -1;
        unordered_set<char> st;
        while (R < s.size()) {
            st.insert(s[R]);
            if (st.size() < R-L+1) {
                while (L < R && s[R] != s[L]) {
                    st.erase(s[L]);
                    L++;
                }
                if (L < R && s[L] == s[R]) {
                    L++;
                }
            }
            mx = max(mx,R-L+1);
            R++;
        }
        return mx;
    }
};