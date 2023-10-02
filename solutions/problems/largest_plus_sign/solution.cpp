#include <algorithm>
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int grid[501][501];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = 1;
            }
        }
        for (vector<int> mine : mines) {
            grid[mine[0]][mine[1]] = 0;
        }
        pair<vector<int>,vector<int>> horizontal[501], vertical[501];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // cout << i << " " << j << endl;
                if (grid[i][j] == 1) {
                    int R = j;
                    while (R + 1 < n && grid[i][R+1] == 1) R++;
                    horizontal[i].first.push_back(j);
                    horizontal[i].second.push_back(R);
                    j = R;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 1) {
                    int R = i;
                    while (R + 1 < n && grid[R+1][j] == 1) R++;
                    vertical[j].first.push_back(i);
                    vertical[j].second.push_back(R);
                    // cout << j << " " << i << " " << R << endl;
                    i = R;
                    
                }
            }
        }
        int order = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // cout << i << " " << j << endl;
                if (grid[i][j] == 1) {
                    auto it = std::lower_bound(horizontal[i].second.begin(),horizontal[i].second.end(),j);
                    int L = j, R = j;
                    if (it != horizontal[i].second.end()) {
                        int idx = it - horizontal[i].second.begin();
                        // cout << idx << endl;
                        L = horizontal[i].first[idx]; R = horizontal[i].second[idx];
                    }
                    auto it2 = std::lower_bound(vertical[j].second.begin(),vertical[j].second.end(),i);
                    int U = i, D = i;
                    if (it2 != vertical[j].second.end()) {
                        int idx =  it2 - vertical[j].second.begin();
                        // cout << idx << endl;
                        U = vertical[j].first[idx]; D = vertical[j].second[idx];
                    }

                    int mn = INT_MAX;
                    mn = min(mn,j-L+1);
                    mn = min(mn,R-j+1);
                    mn = min(mn,i-U+1);
                    mn = min(mn,D-i+1);
                    order = max(order,mn);
                }
            }
        }
        return order;
    }
};