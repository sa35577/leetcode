class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if (grid.size() * grid[0].size() <= 2) return false;
        vector<vector<bool>> forward(grid.size(),vector<bool>(grid[0].size()));
        vector<vector<bool>> backward(grid.size(),vector<bool>(grid[0].size()));
        for (vector<bool> &v : forward) {
            fill(v.begin(),v.end(),false);
        }
        for (vector<bool> &v : backward) {
            fill(v.begin(),v.end(),false);
        }
        forward[0][0] = true;
        backward.back().back() = true;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) continue;
                if ((i >= 1 && forward[i-1][j]) || (j >= 1 && forward[i][j-1])) {
                    forward[i][j] = true;
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int ii = grid.size()-1-i;
                int jj = grid[0].size()-1-j;
                if (grid[ii][jj] == 0) continue;
                if ((i >= 1 && backward[ii+1][jj]) || (j >= 1 && backward[ii][jj+1])) {
                    backward[ii][jj] = true;
                }
            }
        }
        vector<int> rowCount(10000);
        fill(rowCount.begin(),rowCount.end(),0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (forward[i][j] && backward[i][j]) {
                    rowCount[i+j]++;
                }
                // cout << ( backward[i][j]) << " ";
            }
            // cout << endl;
        }
        for (int i = 1; i < grid.size()+grid[0].size()-2; i++) {
            if (rowCount[i] <= 1) return true;
        }
        return false;
    }
};