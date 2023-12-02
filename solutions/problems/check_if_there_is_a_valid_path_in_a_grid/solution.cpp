class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<bool>> vis;
        vector<bool> v;
        for (int j = 0; j < grid[0].size(); j++) {
            v.push_back(false);
        }
        for (int i = 0; i < grid.size(); i++) vis.push_back(v);
        vis[0][0] = 1;
        deque<pair<int,int>> q;
        q.push_back({0,0});
        while (!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop_front();
            int y = cur.first, x = cur.second;
            cout << y << " " << x << endl;
            if (grid[y][x] % 2 == 1) {
                //left
                if (x-1 >= 0 && !vis[y][x-1] && (grid[y][x-1] == 1 || grid[y][x-1] == 4 || grid[y][x-1] == 6)) {
                    vis[y][x-1] = 1;
                    q.push_back({y,x-1});
                }
            }
            if (grid[y][x] == 1 || grid[y][x] == 4 || grid[y][x] == 6) {
                //right
                if (x+1 < grid[0].size() && !vis[y][x+1] && (grid[y][x+1] % 2 == 1)) {
                    vis[y][x+1] = 1;
                    q.push_back({y,x+1});
                }
            }
            if (grid[y][x] == 2 || grid[y][x] >= 5) {
                //up
                if (y-1 >= 0 && !vis[y-1][x] && (grid[y-1][x] >= 2 && grid[y-1][x] <= 4)) {
                    vis[y-1][x] = 1;
                    q.push_back({y-1,x});
                }
            }
            if (grid[y][x] >= 2 && grid[y][x] <= 4) {
                //down
                if (y+1 < grid.size() && !vis[y+1][x] && (grid[y+1][x] == 2 || grid[y+1][x] >= 5)) {
                    vis[y+1][x] = 1;
                    q.push_back({y+1,x});
                }
            }
        }
        return vis.back().back();
    }
};