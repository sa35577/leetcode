class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int L = 0, R = matrix.size()-1;
        int mid;
        while (L < R-1) {
            mid = (L + R)/2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] > target) {
                R = mid;
            }
            else if (matrix[mid][0] < target) L = mid;
        }
        cout << L << " " << R << endl;
        if (matrix[R][0] > target) ;
        else if (L != R) L++;
        int idx = L;
        L = 0;
        R = matrix[idx].size()-1;
        while (L <= R) {
            mid = (L + R)/2;
            if (matrix[idx][mid] == target) return true;
            else if (matrix[idx][mid] > target) R = mid-1;
            else L = mid+1;
        }
        return false;
    }
};