class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for (int i = 0; i < s.size(); i++) {
            if (tolower(s[i]) != s[i] || toupper(s[i]) != s[i]) t += tolower(s[i]);
            else if (s[i]-'0' >= 0 && s[i]-'0' < 10) t += s[i];
        }
        string u = "";
        for (int i = t.size()-1; i > -1; i--) u += t[i];
        return (u==t);
    }
};