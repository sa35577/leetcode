class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}};
        vector<int> v;
        for (int i = 2; i <= numRows; i++) {
            v.clear();
            v.push_back(1);
            for (int j = 1; j < res.back().size(); j++) {
                v.push_back(res.back()[j] + res.back()[j-1]);
            }
            v.push_back(1);
            res.push_back(v);
        }
        return res;
        
    }
};