class Solution {
public:
    int lengthOfLastWord(string s) {
        int idx = s.size()-1;
        if (s.size() == 0) return 0;
        while (idx >= 0 && s[idx] == ' ') idx--;
        int cnt = 0;
        while (idx >= 0 && s[idx] != ' ') {
            cnt++;
            idx--;
        }
        return cnt;
    }
};