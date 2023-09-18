class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> oldarray[21];
        vector<vector<int>> newarray[21];
        vector<int> empty;
        oldarray[0].push_back(empty);
        newarray[0].push_back(empty);
        for (int val = 1; val <= n; val++) { //inserting val
            for (int i = 0; i < k; i++) {
                for (vector<int> v : oldarray[i]) {
                    v.push_back(val);
                    newarray[i+1].push_back(v);
                }
            }
            for (int i = 0; i <= n; i++) oldarray[i] = newarray[i];
        }
        return newarray[k];

    }
};