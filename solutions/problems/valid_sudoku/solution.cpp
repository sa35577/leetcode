class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            set<int> st;
            int cnt = 0;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    st.insert(board[i][j]-'0');
                    cnt++;
                }
            }
            if (st.size() != cnt) return false;
        }

        for (int j = 0; j < 9; j++) {
            set<int> st;
            int cnt = 0;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    st.insert(board[i][j]-'0');
                    cnt++;
                }
            }
            if (st.size() != cnt) return false;
        }

        for (int i = 0; i < 9; i+= 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<pair<int,int>> v{{i,j},{i+1,j},{i+2,j},{i,j+1},{i+1,j+1},{i+2,j+1},{i,j+2},{i+1,j+2},{i+2,j+2}};
                set<int> st;
                int cnt = 0;
                for (pair<int,int> p : v) {
                    if (board[p.first][p.second] != '.') {
                        st.insert(board[p.first][p.second]);
                        cnt++;
                    }
                }
                if (st.size() != cnt) return false;
            }
        }
        return true;
    }
};