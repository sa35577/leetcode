class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int modval = grid[0][0] % x;
        vector<long long> v;
        map<int,long long> freq;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] % x != modval) return -1;
                int val = (grid[i][j] - modval) / x;
                if (freq.find(val) == freq.end()) {
                    freq[val] = 0;
                    v.push_back((long long)(val));
                }
                freq[val]++;
            }
        }
        sort(v.begin(),v.end());
        if (v.size() == 1) return 0;
        // for (int i : v) cout << i << " ";

        vector<long long> sumLeft{v[0] * freq[v[0]]}, sumRight{v.back() * freq[v.back()]};
        vector<long long> freqLeft{freq[v[0]]}, freqRight{freq[v.back()]};
        for (int i = 1; i < v.size(); i++) {
            sumLeft.push_back(sumLeft.back()+v[i] * freq[v[i]]);
            freqLeft.push_back(freqLeft.back() + freq[v[i]]);
        }
        for (int i = (int)(v.size()) - 2; i >= 0; i--) {
            sumRight.push_back(sumRight.back()+v[i] * freq[v[i]]);
            freqRight.push_back(freqRight.back() + freq[v[i]]);
        }
        reverse(sumRight.begin(),sumRight.end());
        reverse(freqRight.begin(),freqRight.end());
        int sz = (int)(v.size());

        long long mn = min(sumRight[1] - v[0] * freqRight[1], v.back() * freqLeft[v.size()-2] - sumLeft[v.size()-2]);
        for (int i = 1; i < v.size()-1; i++) {
            mn = min(mn,v[i] * freqLeft[i-1] - sumLeft[i-1] + sumRight[i+1] - v[i] * freqRight[i+1]);
        }
        return (int)(mn);

    }

};