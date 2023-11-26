class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> v;
        vector<int> w;
        for (int i = 0; i < matrix[0].size(); i++) w.push_back(0);
        for (int i = 0; i < matrix.size(); i++) v.push_back(w);
        
        v[0] = matrix[0];
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] != 0) v[i][j] = 1 + v[i-1][j];
            }
        }
        int mx = 0;
        for (int i = 0; i < v.size(); i++) {
            sort(v[i].rbegin(),v[i].rend());
            for (int j = 0; j < v[i].size(); j++) {
                mx = max(mx,(j+1)*v[i][j]);
            }
        }
        return mx;
    }
};