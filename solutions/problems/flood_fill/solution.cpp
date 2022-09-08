class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        int st = image[sr][sc];
        vector<vector<bool>> vis;
        
        for (int i = 0; i < image.size(); i++) {
            vector<bool> v;
            for (int j = 0; j < image[0].size(); j++) v.push_back(0);
            vis.push_back(v);
        }
        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            
            if (p.first >= 0 && p.first < image.size() && p.second >= 0 && p.second < image[0].size() && !vis[p.first][p.second]) {
                vis[p.first][p.second] = 1;
                if (st == image[p.first][p.second]) {
                    image[p.first][p.second] = color;
                    q.push(make_pair(p.first-1,p.second));
                    q.push(make_pair(p.first+1,p.second));
                    q.push(make_pair(p.first,p.second-1));
                    q.push(make_pair(p.first,p.second+1));
                }
            }
        }
        return image;
    }
};