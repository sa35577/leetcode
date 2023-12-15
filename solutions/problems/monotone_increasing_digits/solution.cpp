class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if (n < 10) return n;
        vector<int> digs;
        while (n > 0) {
            digs.push_back(n % 10);
            n /= 10;
        }
        reverse(digs.begin(),digs.end());
        bool goDown = false;
        vector<int> oldDigs = digs;
        for (int i = 1; i < digs.size(); i++) {
            if (goDown) {
                digs[i] = 9;
            }
            else {
                if (oldDigs[i] < digs[i-1]) {
                    digs[i-1]--;
                    for (int j = i-2; j >= 0; j--) {
                        if (digs[j] <= digs[j+1]) break;
                        digs[j] = digs[j+1];
                        digs[j+1] = 9;
                    }
                    goDown = true;
                    i--;
                }

            }
        }
        int ret = 0;
        for (int idx = 0; idx < digs.size(); idx++) {
            ret = ret * 10 + digs[idx];
        }
        return ret;


    }
};