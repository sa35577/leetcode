class Solution {
public:
    int minimumMoves(string s) {
        int moves = 0;
        vector<bool> v;
        for (char c : s) {
            if (c == 'X') v.push_back(true);
            else v.push_back(false);
        }
        for (int i = 0; i < v.size(); i++) {
            if (v[i]) {
                moves++;
                v[i] = false;
                if (i+1 < v.size()) v[i+1] = false;
                if (i+2 < v.size()) v[i+2] = false;
            }
        }
        return moves;
    }
};