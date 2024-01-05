class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = 0;
        while (matrix[row][col] < target && col+1 < matrix[0].size()) col++;
        if (matrix[row][col] == target) return true;
        while (row+1 < matrix.size()) {
            row++;
            while (col > 0 && matrix[row][col-1] >= target) col--;
            if (matrix[row][col] == target) return true;
        } 
        return false;
    }
};