class Solution {
public:
    vector<pair<int,int>> getNeighbours(int r, int c, int m, int n) {
        vector<pair<int,int>> res;
        if (r-1 >= 0) res.push_back({r-1,c});
        if (r+1 < m) res.push_back({r+1,c});
        if (c-1 >= 0) res.push_back({r,c-1});
        if (c+1 < n) res.push_back({r,c+1});
        return res;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int startCol = image[sr][sc];
        image[sr][sc] = color;
        vector<vector<bool>> vis(image.size());
        for (vector<bool>&v : vis) {
            v.resize(image[0].size());
            fill(v.begin(),v.end(),false);
        }
        vis[sr][sc] = 1;
        while (!q.empty()) {
            pair<int,int> cur = q.front();
            int r = cur.first, c = cur.second;
            q.pop();
            for (pair<int,int> nxt : getNeighbours(r,c,image.size(),image[0].size())) {
                if (image[nxt.first][nxt.second] == startCol && !vis[nxt.first][nxt.second]) {
                    image[nxt.first][nxt.second] = color;
                    vis[r][c] = true;
                    q.push(nxt);
                }
            }
        }
        return image;
    }
};