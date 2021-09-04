class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (r*c != mat.size()*mat[0].size()) return mat;
        vector<vector<int>> nmat(r);
        for (int i = 0; i < r; i++) {
            vector<int> v(c);
            nmat[i] = v;
        }
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                int pos1 = (i*mat[i].size()+j)/c;
                int pos2 = (i*mat[i].size()+j) % c;
                nmat[pos1][pos2] = mat[i][j];
            }
        }
        return nmat;
    }
};