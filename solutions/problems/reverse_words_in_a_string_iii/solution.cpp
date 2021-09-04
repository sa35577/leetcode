class Solution {
public:
    string rev(string s) {
        int L = 0, R = s.size()-1;
        while (L < R) {
            char a = s[L], b = s[R];
            s[L] = b, s[R] = a;
            L++, R--;
        }
        return s;
    }
    string reverseWords(string s) {
        string res = "";
        int L = 0;
        int R = 0;
        while (L < s.size() && R < s.size()) {
            while (R+1 < s.size() && s[R+1] != ' ') {
                R++;
            }
            res += rev(s.substr(L,R-L+1));
            L = R+2;
            R += 2;
            res += " ";
        }
        if (res[res.size()-1] == ' ') res = res.substr(0,res.size()-1);
        return res;
        
    }
};