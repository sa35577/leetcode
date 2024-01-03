class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        bool down = true;
        int r = 0, c = 0;
        vector<vector<int>> v(numRows);
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < 1000; j++) {
                v[i].push_back(0);
            }
        }
        // cout << s << " ";
        for (int i = 0; i < s.size(); i++) {
            // cout << i << " " << r << " " << c << endl;
            v[r][c] = (int)(s[i]);
            if (down) {
                r++;
                if (r == numRows) {
                    c++;
                    r--; r--;
                    down = false;
                }
            }
            else {
                r--;
                c++;
                if (r == -1) {
                    r++; r++;
                    c--;
                    down = true;
                }
            }
        }
        // cout << "here";
        string ret = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < v[0].size(); j++) {
                if (v[i][j] > 0) {
                    ret += (char)(v[i][j]);
                }
            }
        }
        return ret;
    }
};