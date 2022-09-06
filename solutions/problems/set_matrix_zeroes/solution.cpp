class Solution {
public:
    void chaseDown(vector<vector<int>>& matrix, int y, int x) {
        for (int k = 0; k < matrix[y].size(); k++) {
            matrix[y][k] = 0;
        }
        for (int k = 0; k < matrix.size(); k++) {
            matrix[k][x] = 0;
        }
    }
    void firstRun(vector<vector<int>>& matrix, int i, int j) {
        bool done = false;
        if (i == matrix.size()-1 && j == matrix[0].size()-1) done = true;
        if (done) {
            if (matrix[i][j] == 0) chaseDown(matrix,i,j);
            return;
        }
        int newi = i, newj = j;
        if (newj == matrix[0].size()-1) {
            newj = 0;
            newi++;
        }
        else newj++;
        if (matrix[i][j] == 0) {
            firstRun(matrix,newi,newj);
            chaseDown(matrix,i,j);
        }
        else firstRun(matrix,newi,newj);
    }
    void setZeroes(vector<vector<int>>& matrix) {
        firstRun(matrix,0,0);
    }
};