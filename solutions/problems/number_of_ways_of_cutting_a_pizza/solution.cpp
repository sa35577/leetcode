class Solution {
public:
    vector<vector<int>> numApples;
    int cnt(int tr, int tc, int br, int bc) {
        int bottomRight = numApples[br][bc];
        int bottomLeft = 0, topRight = 0, topLeft = 0;
        if (tc != 0) bottomLeft = numApples[br][tc-1];
        if (tr != 0) topRight = numApples[tr-1][bc];
        if (tr != 0 && tc != 0) topLeft = numApples[tr-1][tc-1];
        return bottomRight - bottomLeft - topRight + topLeft;
    }
    int ways(vector<string>& pizza, int k) {
        vector<vector<int>> numApplesH(pizza.size());
        for (int i = 0; i < pizza.size(); i++) {
            if (pizza[i][0] == 'A') numApplesH[i].push_back(1);
            else numApplesH[i].push_back(0);
            for (int j = 1; j < pizza[0].size(); j++) {
                int base = numApplesH[i].back();
                if (pizza[i][j] == 'A') numApplesH[i].push_back(base+1);
                else numApplesH[i].push_back(base+0);
            }
        }
        numApples.resize(pizza.size());
        numApples[0] = numApplesH[0];
        for (int i = 1; i < pizza.size(); i++) {
            numApples[i] = numApplesH[i];
            for (int j = 0; j < pizza[0].size(); j++) {
                numApples[i][j] += numApples[i-1][j];
            }
        }
        int dp[50][50][11];
        bool use[50][50][11];
        const int mod = 1000000007;
        memset(dp,0,sizeof(dp));
        memset(use,0,sizeof(use));
        //dp[i][j][k] represents the number of rectangles after k cuts, whose last pizza slice has the top left corner in i,j
        dp[0][0][0] = 1;
        use[0][0][0] = 1;
        int r = pizza.size(), c = pizza[0].size();
        for (int kk = 0; kk < k-1; kk++) {
            // cout << "k: " << kk << endl;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    // cout << dp[i][j][kk] << " ";
                    if (use[i][j][kk] != 0) { // if this square is nonzero
                        for (int cutRow = i; cutRow < r; cutRow++) {
                            //bounding box (i,j) to (cutRow,c-1)
                            if (cnt(i,j,cutRow,c-1) > 0 && cnt(i,j,cutRow,c-1) < cnt(i,j,r-1,c-1)) {
                                //new top left is at row cutRow+1
                                if (cutRow+1 < r) {
                                    dp[cutRow+1][j][kk+1] = (dp[cutRow+1][j][kk+1] + dp[i][j][kk]) % mod;
                                    use[cutRow+1][j][kk+1] = true;
                                }
                            }
                        }
                        for (int cutCol = j; cutCol < c; cutCol++) {
                            //bounding box (i,j) to (r-1,cutCol)
                            if (cnt(i,j,r-1,cutCol) > 0 && cnt(i,j,r-1,cutCol) < cnt(i,j,r-1,c-1)) {
                                if (cutCol+1 < c) {
                                    dp[i][cutCol+1][kk+1] = (dp[i][cutCol+1][kk+1] + dp[i][j][kk]) % mod;
                                    use[i][cutCol+1][kk+1] = true;
                                }
                            }
                        }
                    }
                }
                // cout << endl;
            }
        }
        int res = 0;
        // cout << "K: " << endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (cnt(i,j,r-1,c-1) > 0) res = (res + dp[i][j][k-1]) % mod;
                // cout << dp[i][j][k-1] << " ";
            }
            // cout << endl;
        }
        return res;
    }
};