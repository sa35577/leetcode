class Solution {
public:
    pair<int,int> check(vector<vector<int>>&vis) {
        for (int i = 0; i < 3; i++) {
            if (vis[i][0] == vis[i][1] && vis[i][1] == vis[i][2] && vis[i][0] != -1) return {i,0};
        }
        for (int i = 0; i < 3; i++) {
            if (vis[0][i] == vis[1][i] && vis[1][i] == vis[2][i] && vis[0][i] != -1) return {0,i};
        }
        if (vis[0][0] == vis[1][1] && vis[1][1] == vis[2][2] && vis[1][1] != -1) return {1,1};
        if (vis[2][0] == vis[1][1] && vis[1][1] == vis[0][2] && vis[1][1] != -1) return {1,1};
        return {-1,-1};
        
    }
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> vis;
        for (int i = 0; i < 3; i++) {
            vis.push_back({-1,-1,-1});
        }
        int cnt = 0;
        for (vector<int> move : moves) {
            vis[move[0]][move[1]] = cnt % 2;
            pair<int,int> p = check(vis);
            if (p.first != -1) {
                // cout << move[0] << " " << move[1];
                if (cnt % 2 == 0) return "A";
                return "B";
            }
            cnt++;
        }
        if (moves.size() == 9) return "Draw";
        return "Pending";
    }
};