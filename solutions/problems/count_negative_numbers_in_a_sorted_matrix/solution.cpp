class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int pos = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            while (pos-1 >= 0 && grid[i][pos-1] < 0) pos--;
            cnt += (grid[0].size()-1)-pos+1;
            
        }
        return cnt;
    }
};