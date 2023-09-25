class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int vis[301][301];
        int cntIslands = 0;

        for (int i = 0; i < 301; i++) {
            for (int j = 0; j < 301; j++) {
                vis[i][j] = -1;
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (vis[i][j] == -1 && grid[i][j] == '1') {
                    int val = cntIslands;
                    cntIslands++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while (!q.empty()) {
                        pair<int,int> p = q.front();
                        //cout << p.first << " " << p.second << endl;
                        q.pop();
                        if (vis[p.first][p.second] == -1) {
                            vis[p.first][p.second] = val;
                            if (p.first > 0 && vis[p.first-1][p.second] == -1 && grid[p.first-1][p.second] == '1') {
                                q.push({p.first-1,p.second});
                            }
                            if (p.second > 0 && vis[p.first][p.second-1] == -1 && grid[p.first][p.second-1] == '1') {
                                q.push({p.first,p.second-1});
                            }
                            if (p.first < grid.size()-1 && vis[p.first+1][p.second] == -1 && grid[p.first+1][p.second] == '1') {
                                q.push({p.first+1,p.second});
                            }
                            if (p.second < grid[p.first].size()-1 && vis[p.first][p.second+1] == -1 && grid[p.first][p.second+1] == '1') {
                                q.push({p.first,p.second+1});
                            }
                        }
                    }
                } 
            }
        }

        return cntIslands;
    }
};