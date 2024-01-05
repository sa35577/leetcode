class Solution {
public:
    vector<pair<int,int>> getNeighbours(int r, int c, int m, int n) {
        vector<pair<int,int>> v;
        if (r-1 >= 0) v.push_back({r-1,c});
        if (r+1 < m) v.push_back({r+1,c});
        if (c-1 >= 0) v.push_back({r,c-1});
        if (c+1 < n) v.push_back({r,c+1});
        return v;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int numIslands = 0;
        vector<vector<int>> vis;
        for (int i = 0; i < grid.size(); i++) {
            vis.push_back({});
            for (int j = 0; j < grid[0].size(); j++) {
                vis.back().push_back(0);
            }
        }
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0 && vis[i][j] == 0) {
                    numIslands++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = numIslands;
                    while (!q.empty()) {
                        pair<int,int> p = q.front();
                        q.pop();
                        int r = p.first, c = p.second;
                        for (pair<int,int> nxt : getNeighbours(r,c,grid.size(),grid[0].size())) {
                            if (grid[nxt.first][nxt.second] == 0 && vis[nxt.first][nxt.second] == 0) {
                                vis[nxt.first][nxt.second] = numIslands;
                                q.push(nxt);
                            }
                        }
                    }
                }
            }
        }
        vector<bool> res(numIslands+1);
        fill(res.begin(),res.end(),true);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // cout << vis[i][j] << " ";
                if (vis[i][j] > 0 && getNeighbours(i,j,grid.size(),grid[0].size()).size() < 4) {
                    res[vis[i][j]] = false;
                    // cout << vis[i][j] << " " << i << " " << j << endl;
                }
            }
            // cout << endl;
        }
        int cnt = 0;
        for (bool b : res) {
            if (b) cnt++;
        }
        return cnt-1;
        
    }
};