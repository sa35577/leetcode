class Solution {
public:
    int countNeighbours(vector<vector<int>>& board, int i, int j) {
        int U=i,D=i;
        if (i < board.size()-1) D++;
        if (i > 0) U--;
        int L=j,R=j;
        if (j < board[0].size()-1) R++;
        if (j > 0) L--;
        int res = 0;
        for (int y = U; y <= D; y++) {
            for (int x = L; x <= R; x++) {
                if (!(y == i && x == j)) res += board[y][x];
            }
        }
        return res;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> v;
        vector<int> empty;
        for (int i = 0; i < board.size(); i++) {
            v.push_back(empty);
            for (int j = 0; j < board[0].size(); j++) {
                int aliveNeighbours = countNeighbours(board,i,j);
                if (board[i][j] == 1) {
                    if (aliveNeighbours < 2 || aliveNeighbours > 3) v[i].push_back(0);
                    else v[i].push_back(1);
                }
                else {
                    if (aliveNeighbours == 3) v[i].push_back(1);
                    else v[i].push_back(0);
                }
            }
        }
        board = v;
    }
};