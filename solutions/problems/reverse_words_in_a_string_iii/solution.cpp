class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string t;
        string out;
        while (ss >> t) {
            reverse(t.begin(),t.end());
            out += t;
            out += ' ';
        }
        reverse(out.begin(),out.end());
        out = out.substr(1);
        reverse(out.begin(),out.end());
        return out;
    }
};