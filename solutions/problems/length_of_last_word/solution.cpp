class Solution {
public:
    int lengthOfLastWord(string s) {
        while (s.size() > 0 && s.back() == ' ') s.pop_back();
        int cnt = 0;
        while (s.size() > 0 && s.back() != ' ') {
            s.pop_back();
            cnt++;
        }
        return cnt;
    }
};