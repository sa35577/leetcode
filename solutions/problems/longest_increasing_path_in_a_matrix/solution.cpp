class Solution {
public:
    vector<pair<int,int>> getNeighbours(int i, int j, int m, int n) {
        vector<pair<int,int>> v;
        //row above
        if (i-1 >= 0) {
            v.push_back({i-1,j});
            // if (j-1 >= 0) v.push_back({i-1,j-1});
            // if (j+1 < n) v.push_back({i-1,j+1});
        }
        //current row
        if (j-1 >= 0) v.push_back({i,j-1});
        if (j+1 < n) v.push_back({i,j+1});
        //row below
        if (i+1 < m) {
            v.push_back({i+1,j});
            // if (j-1 >= 0) v.push_back({i+1,j-1});
            // if (j+1 < n) v.push_back({i+1,j+1});
        }
        return v;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>> pq;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                pq.push({matrix[i][j],{i,j}});
            }
        }
        vector<vector<int>> dp(matrix.size());
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) dp[i].push_back(1);
        }
        int mx = 1;
        while (!pq.empty()) {
            pair<int,pair<int,int>> cur = pq.top();
            pair<int,int> pos = cur.second;
            pq.pop();
            vector<pair<int,int>> neighbours = getNeighbours(pos.first,pos.second,matrix.size(),matrix[0].size());
            for (pair<int,int> n : neighbours) {
                if (matrix[n.first][n.second] > matrix[pos.first][pos.second]) {
                    dp[pos.first][pos.second] = max(dp[pos.first][pos.second],dp[n.first][n.second]+1);
                }
            }
            mx = max(mx,dp[pos.first][pos.second]);
            // cout << pos.first << " " << pos.second << ": " << dp[pos.first][pos.second] << endl;

        }
        return mx;
    }
};