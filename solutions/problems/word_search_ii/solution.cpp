class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& vis, int idx, int i, int j) {
        if (idx == word.size()) return true;
        vis[i][j] = 1;
        int m = board.size(), n = board[0].size();
        if (i-1 >= 0 && vis[i-1][j] == 0 && board[i-1][j] == word[idx]) {
            if (dfs(board,word,vis,idx+1,i-1,j)) return true;
        }
        if (i+1 < m && vis[i+1][j] == 0 && board[i+1][j] == word[idx]) {
            if (dfs(board,word,vis,idx+1,i+1,j)) return true;
        }
        if (j-1 >= 0 && vis[i][j-1] == 0 && board[i][j-1] == word[idx]) {
            if (dfs(board,word,vis,idx+1,i,j-1)) return true;
        }
        if (j+1 < n && vis[i][j+1] == 0 && board[i][j+1] == word[idx]) {
            if (dfs(board,word,vis,idx+1,i,j+1)) return true;
        }            
        vis[i][j] = 0;
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> base,vis;
        for (int i = 0; i < m; i++) {
            base.push_back({});
            for (int j = 0; j < n; j++) {
                base.back().push_back(0);
            }
            
        }
        bool adj[26][26];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) adj[i][j] = 0;
        }
        for (int i = 0; i < m-1; i++) {
            for (int j = 0; j < n; j++) {
                adj[board[i][j] - 'a'][board[i+1][j] - 'a'] = 1;
                adj[board[i+1][j] - 'a'][board[i][j] - 'a'] = 1;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n-1; j++) {
                adj[board[i][j] - 'a'][board[i][j+1] - 'a'] = 1;
                adj[board[i][j+1] - 'a'][board[i][j] - 'a'] = 1;
            }
        }
        for (string word : words) {
            bool done = false;
            bool bad = false;
            for (int i = 1; i < word.size(); i++) {
                if (!adj[word[i]-'a'][word[i-1]-'a']) {
                    bad = true;
                    break;
                }
            }
            if (bad) continue;
            for (int ii = 0; ii < m; ii++) {
                for (int jj = 0; jj < n; jj++) {
                    if (board[ii][jj] == word[0]) {
                        vis = base;
                        if (dfs(board,word,vis,1,ii,jj)) {
                            // cout << ii << " " << jj << endl;
                            ret.push_back(word);
                            done = true;
                        }
                    }
                    if (done) break;
                }
                if (done) break;
            }
            // if (done) ret.push_back(word);
        }
        return ret;
        
    }
};