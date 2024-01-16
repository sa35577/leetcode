class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for (vector<int> &v: grid) {
            for (int &x : v) {
                if (x < 0) cnt++;
            }
        }
        return cnt;
    }
};