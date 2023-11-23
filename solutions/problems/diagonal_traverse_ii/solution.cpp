class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<pair<int,int>> v;
        //pair<sum,second coordinate>
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                v.push_back({i+j,j});
            }
        }
        sort(v.begin(),v.end());
        vector<int> res;
        for (pair<int,int> p : v) {
            res.push_back(nums[p.first - p.second][p.second]);
        }
        return res;
    }
};