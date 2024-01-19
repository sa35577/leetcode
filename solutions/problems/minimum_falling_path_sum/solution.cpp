class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if (matrix[0].size() == 1) {
            for (int i = 1; i < matrix.size(); i++) {
                matrix[i][0] += matrix[i-1][0];
                return matrix.back().back();
            }

        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (j == 0) {
                    matrix[i][j] += min(matrix[i-1][j],matrix[i-1][j+1]);
                }
                else if (j == matrix[0].size()-1) {
                    matrix[i][j] += min(matrix[i-1][j-1],matrix[i-1][j]);
                }
                else {
                    matrix[i][j] += min(matrix[i-1][j],min(matrix[i-1][j-1],matrix[i-1][j+1]));
                }
            }
        }
        int mn = INT_MAX;
        for (int x : matrix.back()) {
            mn = min(mn,x);
        }
        return mn;
    }
};