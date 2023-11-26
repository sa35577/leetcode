class Solution {
public:
    int bfs(vector<vector<pair<int,int>>>& grid, int v, int y, int x) {
        deque<pair<int,int>> q;
        q.push_back({y,x});
        grid[y][x].second = v;
        int sz = 0;
        while (!q.empty()) {
            sz++;
            pair<int,int> cur = q.front();
            q.pop_front();
            int cy = cur.first, cx = cur.second;
            if (cy > 0 && grid[cy-1][cx].first == 1 && grid[cy-1][cx].second == 0) {
                q.push_back({cy-1,cx});
                grid[cy-1][cx].second = v;
            }
            if (cy < grid.size()-1 && grid[cy+1][cx].first == 1 && grid[cy+1][cx].second == 0) {
                q.push_back({cy+1,cx});
                grid[cy+1][cx].second = v;
            }
            if (cx > 0 && grid[cy][cx-1].first == 1 && grid[cy][cx-1].second == 0) {
                q.push_back({cy,cx-1});
                grid[cy][cx-1].second = v;
            }
            if (cx < grid[0].size()-1 && grid[cy][cx+1].first == 1 && grid[cy][cx+1].second == 0) {
                q.push_back({cy,cx+1});
                grid[cy][cx+1].second = v;
            }
        }
        return sz;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<pair<int,int>>> v;
        v.resize(grid.size());
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                v[i].push_back({grid[i][j],0});
            }
        }
        int mx = 0;
        int cnt = 1;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[0].size(); j++) {
                if (v[i][j].first == 1) {
                    mx = max(mx,bfs(v,cnt,i,j));
                    cnt++;
                }
            }
        }
        return mx;
    }
};