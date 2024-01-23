class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> squares;
        int v = 1;
        while (v*v <= n) {
            squares.push_back(v*v);
            v++;
        }
        bool alice[100005];
        bool bob[100005];
        memset(alice,0,sizeof(alice));
        memset(bob,0,sizeof(bob));
        for (int x : squares) {
            alice[x] = true;
            bob[x] = true;
        }
        for (int i = 1; i < n; i++) {
            if (!alice[i]) {
                for (int x : squares) {
                    if (i+x <= n) bob[i+x] = true;
                    else break;
                }
            }
            if (!bob[i]) {
                for (int x : squares) {
                    if (i+x <= n) alice[i+x] = true;
                    else break;
                }
            }
        }
        return alice[n];
    }
};