class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        //sum inside (x1,y1,x2,y2) is dp[y2][x2] - dp[y1-1][x2] - dp[y2][x2-1] + dp[y1-1][x1-1]
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 1; col < matrix[0].size(); col++) {
                matrix[row][col] += matrix[row][col-1];
            }
        }
        for (int row = 1; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[0].size(); col++) {
                matrix[row][col] += matrix[row-1][col];
            }
        }
        for (vector<int>& v : matrix) {
            for (int &x : v) cout << x << " ";
            cout << endl;
        }
        int sum = 0;
        for (int top = -1; top < (int)(matrix.size())-1; top++) {
            for (int bottom = top+1; bottom < matrix.size(); bottom++) {
                //get all in a frequency map
                unordered_map<int,int> freq;
                // freq[0] = 1;
                for (int col = 0; col < matrix[0].size(); col++) {
                    //dp[top][col] - dp[bottom][col]
                    int q1 = (top == -1) ? 0 : matrix[top][col];
                    int q2 = matrix[bottom][col];
                    if (freq.find(q1-q2) == freq.end()) freq[q1-q2] = 0;
                    freq[q1-q2]++;
                }
                // if (top == -1 && bottom == 0) {
                //     for (auto it = freq.begin(); it != freq.end(); it++) {
                //         cout << it->first << " " << it->second << endl;
                //     }
                //     cout << "-----\n";
                // }
                //for a given left end, we need to find a corresponding thing of value -(target - current)
                if (freq.find(-target) != freq.end()) sum += freq[-target];
                for (int col = 0; col < matrix[0].size(); col++) {
                    //dp[top][col] - dp[bottom][col]
                    int q1 = (top == -1) ? 0 : matrix[top][col];
                    int q2 = matrix[bottom][col];
                    freq[q1-q2]--;
                    if (freq.find(q1-q2 - target) != freq.end()) sum += freq[q1-q2 - target];
                }
                // cout << top << " " << bottom << ": " << sum << endl;
            }
        }
        return sum;
    }
};