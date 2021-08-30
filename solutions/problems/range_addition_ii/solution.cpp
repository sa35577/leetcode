class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0) return m*n;
        int minA = INT_MAX, minB = INT_MAX;
        for (vector<int> v : ops) {
            minA = min(minA,v[0]);
            minB = min(minB,v[1]);
        }
        return minA*minB;
        
    }
};