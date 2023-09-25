class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        bool reachPacific[201][201];
        int reachAtlantic[201][201];
        bool vis[201][201];
        for (int i = 0; i < 201; i++) {
            for (int j = 0; j < 201; j++) {
                reachPacific[i][j] = false;
                reachAtlantic[i][j] = false;
                vis[i][j] = false;
            }
        }

        queue<pair<int,int>> q;
        for (int i = 0; i < heights.size(); i++) {
            q.push({i,0});
        }
        for (int i = 0; i < heights[0].size(); i++) {
            q.push({0,i});
        }
        
        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int y = p.first, x = p.second;
            if (!vis[y][x]) {
                vis[y][x] = 1;
                reachPacific[y][x] = true;
                if (y > 0 && !vis[y-1][x] && heights[y-1][x] >= heights[y][x]) {
                    q.push({y-1,x});
                }
                if (y < heights.size()-1 && !vis[y+1][x] && heights[y+1][x] >= heights[y][x]) {
                    q.push({y+1,x});
                }
                if (x > 0 && !vis[y][x-1] && heights[y][x-1] >= heights[y][x]) {
                    q.push({y,x-1});
                }
                if (x < heights[0].size()-1 && !vis[y][x+1] && heights[y][x+1] >= heights[y][x]) {
                    q.push({y,x+1});
                }

            }
        }
        
        for (int i = 0; i < 201; i++) {
            for (int j = 0; j < 201; j++) {
                vis[i][j] = false;
            }
        }

        for (int i = 0; i < heights.size(); i++) {
            q.push({i,heights[0].size()-1});
        }
        for (int i = 0; i < heights[0].size(); i++) {
            q.push({heights.size()-1,i});
        }

        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int y = p.first, x = p.second;
            if (!vis[y][x]) {
                vis[y][x] = 1;
                reachAtlantic[y][x] = true;
                if (y > 0 && !vis[y-1][x] && heights[y-1][x] >= heights[y][x]) {
                    q.push({y-1,x});
                }
                if (y < heights.size()-1 && !vis[y+1][x] && heights[y+1][x] >= heights[y][x]) {
                    q.push({y+1,x});
                }
                if (x > 0 && !vis[y][x-1] && heights[y][x-1] >= heights[y][x]) {
                    q.push({y,x-1});
                }
                if (x < heights[0].size()-1 && !vis[y][x+1] && heights[y][x+1] >= heights[y][x]) {
                    q.push({y,x+1});
                }

            }
        }

        vector<vector<int>> res;

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                if (reachPacific[i][j] && reachAtlantic[i][j]) {
                    vector<int> v{i,j};
                    res.push_back(v);
                }
            }
        }

        return res;

    }
};