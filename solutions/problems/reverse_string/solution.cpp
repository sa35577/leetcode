class Solution {
public:
    void reverseString(vector<char>& s) {
        int L = 0, R = s.size()-1;
        while (L < R) {
            char a = s[L];
            char b = s[R];
            s[L] = b;
            s[R] = a;
            L++;
            R--;
        }
    }
};