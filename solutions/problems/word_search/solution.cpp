class Solution {
public:
    vector<pair<int,int>> getNeighbours(int r, int c, int numRows, int numCols) {
        vector<pair<int,int>> v;
        if (r > 0) v.push_back({r-1,c});
        if (r + 1 < numRows) v.push_back({r+1,c});
        if (c > 0) v.push_back({r,c-1});
        if (c + 1 < numCols) v.push_back({r,c+1});
        return v;
    }
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, string word, int idx, int r, int c) {
        if (idx == word.size() - 1) return true;
        vis[r][c] = true;

        for (pair<int,int> &nextpos : getNeighbours(r,c,board.size(),board[0].size())) {
            if (!vis[nextpos.first][nextpos.second] && board[nextpos.first][nextpos.second] == word[idx+1] && dfs(board,vis,word,idx+1,nextpos.first,nextpos.second)) return true;
        }

        vis[r][c] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        //check frequency of characters and see if it is even possible for the word to exist
        map<char,int> boardFreq;
        for (vector<char> & v : board) {
            for (char &c : v) {
                if (boardFreq.find(c) == boardFreq.end()) boardFreq[c] = 0;
                boardFreq[c]++;
            }
        }
        for (char &c : word) {
            if (boardFreq.find(c) == boardFreq.end() || boardFreq[c] == 0) return false;
            boardFreq[c]--;
        }
        //use a dfs solution from all the starting chars
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size()));
        for (vector<bool> & b : vis) {
            fill(b.begin(),b.end(),false);
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board,vis,word,0,i,j)) return true;
                }
            }
        }
        return false;
    }
};