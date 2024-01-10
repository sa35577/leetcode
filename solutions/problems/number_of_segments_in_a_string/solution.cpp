class Solution {
public:
    int countSegments(string s) {
        int idx = 0;
        int cnt = 0;

        while (idx < s.size() && s[idx] == ' ') idx++;

        while (idx < s.size()) {
            while (idx < s.size() && s[idx] != ' ') idx++;
            cnt++;
            if (idx == s.size()) return cnt;
            while (idx < s.size() && s[idx] == ' ') idx++;
        }

        return cnt;
    }
};