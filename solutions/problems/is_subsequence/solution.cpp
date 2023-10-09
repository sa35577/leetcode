class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s1 = 0, s2 = 0;
        if (s.size() > t.size()) return false;
        while (s1 < s.size() && s2 < t.size()) {
            while (s2 < t.size() && t[s2] != s[s1]) s2++;
            if (s2 == t.size()) break;
            //cout << s1 << " " << s2 << endl;
            s1++; s2++;
        }
        return s1 == s.size();
    }
};