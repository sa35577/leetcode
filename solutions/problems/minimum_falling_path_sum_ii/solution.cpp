class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 1) return grid.back().back();
        int n = grid.size();
        for (int i = 1; i < n; i++) {
            multiset<int> st;
            for (int &x : grid[i-1]) st.insert(x);
            for (int j = 0; j < n; j++) {
                cout << j << endl;
                st.erase(st.lower_bound(grid[i-1][j]));
                grid[i][j] += *(st.begin());
                st.insert(grid[i-1][j]);
            }
        }
        int mn = INT_MAX;
        for (int &x : grid.back()) mn = min(mn,x);
        return mn;
    }
};