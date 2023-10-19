class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int lcs[1001][1001];
        for (int i = 0; i < 1001; i++) {
            for (int j = 0; j < 1001; j++) lcs[i][j] = 0;
        }
        map<char, int> lastSeen;
        // lcs[i][j] is the lcs including char j in text 2
        for (int j = 0; j < text2.size(); j++) {
            for (int i = 0; i < text1.size(); i++) {
                if (i > 0) {
                    lcs[i][j] = lcs[i-1][j];
                    if (text1[i] == text2[j] && j > 0) lcs[i][j] = max(lcs[i-1][j-1]+1,lcs[i][j]);
                    else if (text1[i] == text2[j]) lcs[i][j] = max(1,lcs[i][j]);
                }
                else {
                    if (text1[i] == text2[j]) lcs[i][j] = max(1,lcs[i][j]);
                }

                if (j > 0) lcs[i][j] = max(lcs[i][j],lcs[i][j-1]);
            }
        }
        return lcs[text1.size()-1][text2.size()-1];

    }
};