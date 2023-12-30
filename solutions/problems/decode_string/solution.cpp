class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        string out = "";
        int multiplier = 0;
        while (i < s.size()) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                out += s[i];
                i++;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                int j = i;
                while (j < s.size()) {
                    j++;
                    if (s[j] == '[') {
                        j--;
                        break;
                    }
                }
                multiplier = stoi(s.substr(i,j-i+1));
                i = j+1;
            }
            else {
                int numLeft = 1;
                int j = i;
                while (j < s.size()) {
                    j++;
                    if (s[j] == '[') numLeft++;
                    else if (s[j] == ']') numLeft--;
                    if (numLeft == 0) break;
                }
                string rec = decodeString(s.substr(i+1,(j-1) - (i+1) + 1));
                for (int k = 0; k < multiplier; k++) out += rec;
                i = j+1;
            }
        }
        return out;
    }
};