class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows[200], cols[200];
        memset(rows,0,sizeof(rows));
        memset(cols,0,sizeof(cols));

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }
        int cnt = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (rows[i] == 1 && cols[j] == 1 && mat[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};