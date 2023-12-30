class Solution {
public:
    bool exists(vector<vector<char>>& board, string &word, int curRow, int curCol, int pos, int deltaRow, int deltaCol, vector<vector<bool>>& vis) {
        if (pos == word.size()) return true;
        if (curRow < 0 || curRow >= board.size() || curCol < 0 || curCol >= board[0].size()) return false;
        if (word[pos] != board[curRow][curCol]) return false;
        if (vis[curRow][curCol]) return false;
        vis[curRow][curCol] = true;
        if (!(deltaRow == 1 && deltaCol == 0)) {
            if (exists(board,word,curRow+1,curCol,pos+1,-1,0,vis)) return true;
        }
        if (!(deltaRow == -1 && deltaCol == 0)) {
            if (exists(board,word,curRow-1,curCol,pos+1,1,0,vis)) return true;
        }
        if (!(deltaRow == 0 && deltaCol == 1)) {
            if (exists(board,word,curRow,curCol+1,pos+1,0,-1,vis)) return true;
        }
        if (!(deltaRow == 0 && deltaCol == -1)) {
            if (exists(board,word,curRow,curCol-1,pos+1,0,1,vis)) return true;
        }
        vis[curRow][curCol] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis;
        int freq[256];
        fill(freq,freq+256,0);
        int r = board.size(), c = board[0].size();
        for (int i = 0; i < r; i++) {
            vector<bool> v;
            for (int j = 0; j < c; j++) {
                v.push_back(false);
                freq[(int)board[i][j]]++;
            }
            vis.push_back(v);
        }
        int wordfreq[256];
        fill(wordfreq,wordfreq+256,0);
        for (char c : word) {
            wordfreq[(int)c]++;
            if (wordfreq[(int)c] > freq[(int)c]) return false;
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (exists(board,word,i,j,0,0,0,vis)) return true;
            }
        }
        return false;
    }
};