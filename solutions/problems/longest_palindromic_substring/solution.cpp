class Solution {
public:
    string longestPalindrome(string s) {
        int maxi = 0, maxdiff = 0;
        for (int i = 0; i < s.size(); i++) {
            int curdiff = 0;
            while (i - (curdiff + 1) >= 0 && i + (curdiff + 1) < s.size() && s[i - (curdiff + 1)] == s[i + (curdiff + 1)]) curdiff++;
            if (curdiff > maxdiff) {
                maxi = i;
                maxdiff = curdiff;
            }
        }
        string ans1 = s.substr(maxi-maxdiff,2*maxdiff+1);

        string t = "";
        for (char c : s) {
            t += c;
            t += 'x';
        }
        t.pop_back();
        int maxi2 = 0, maxdiff2 = 0;
        for (int i = 1; i < t.size(); i += 2) {
            int curdiff = 0;
            while (i - (2*curdiff + 1) >= 0 && i + (2*curdiff + 1) < t.size() && t[i - (2*curdiff + 1)] == t[i + (2*curdiff + 1)]) curdiff++;
            if (curdiff > maxdiff2) {
                maxi2 = i;
                maxdiff2 = curdiff;
            }
        }

        if (maxdiff2 > maxdiff) return s.substr(maxi2/2-maxdiff2+1,2*maxdiff2);
        return ans1;
    }
};