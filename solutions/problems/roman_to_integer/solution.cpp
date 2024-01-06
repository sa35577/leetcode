class Solution {
public:
    int romanToInt(string s) {
        int val = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'M') val += 1000;
            else if (c == 'D') val += 500;
            else if (c == 'C') {
                if (s[i+1] == 'D') {
                    i++;
                    val += 400;
                }
                else if (s[i+1] == 'M') {
                    i++;
                    val += 900;
                }
                else {
                    val += 100;
                }
            }
            else if (c == 'L') val += 50;
            else if (c == 'X') {
                if (s[i+1] == 'L') {
                    i++;
                    val += 40;
                }
                else if (s[i+1] == 'C') {
                    i++;
                    val += 90;
                }
                else {
                    val += 10;
                }
            }
            else if (c == 'V') val += 5;
            else if (c == 'I') {
                if (s[i+1] == 'V') {
                    i++;
                    val += 4;
                }
                else if (s[i+1] == 'X') {
                    i++;
                    val += 9;
                }
                else {
                    val += 1;
                }
            }
        }
        return val;
    }
};