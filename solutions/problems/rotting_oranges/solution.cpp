class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        deque<pair<int,int>> deck;
        int ans = 0;
        // int seenSoFar = 0;
        int m = (int)(grid.size()), n = (int)(grid[0].size());
        vector<vector<int>> vis;

        for (int i = 0; i < m; i++) {
            vis.push_back({});
            for (int j = 0; j < n; j++) {
                vis.back().push_back(INT_MAX);
                if (grid[i][j] == 2) {
                    vis.back().back() = 0;
                    deck.push_back({i,j});
                }
            }
        }

        while (!deck.empty()) {
            pair<int,int> p = deck.front();
            deck.pop_front();
            int i = p.first, j = p.second;
            ans = max(ans,vis[i][j]);

            if (i - 1 >= 0 && grid[i-1][j] == 1) {
                grid[i-1][j] = 2;
                vis[i-1][j] = vis[i][j] + 1;
                deck.push_back({i-1,j});
            }

            if (i + 1 < m && grid[i+1][j] == 1) {
                grid[i+1][j] = 2;
                vis[i+1][j] = vis[i][j] + 1;
                deck.push_back({i+1,j});
            }

            if (j - 1 >= 0 && grid[i][j-1] == 1) {
                grid[i][j-1] = 2;
                vis[i][j-1] = vis[i][j] + 1;
                deck.push_back({i,j-1});
            }

            if (j + 1 < n && grid[i][j+1] == 1) {
                grid[i][j+1] = 2;
                vis[i][j+1] = vis[i][j] + 1;
                deck.push_back({i,j+1});
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return ans;

    }
};