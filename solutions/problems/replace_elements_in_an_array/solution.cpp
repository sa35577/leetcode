class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        set<pair<int,int>> s;
        for (int i = 0; i < nums.size(); i++) {
            pair<int,int> p = {nums[i],i};
            s.insert(p);
        }
        for (vector<int> v : operations) {
            pair<int,int> p = {v[0],-1};
            pair<int,int> inSet = *s.lower_bound(p);
            s.erase(inSet);
            pair<int,int> newinSet = {v[1],inSet.second};
            //cout << newinSet.first << " " << newinSet.second << "\n";
            s.insert(newinSet);
        }
        vector<int> v;
        v.resize(nums.size());
        for (auto it = s.begin(); it != s.end(); it++) {
            pair<int,int> p = *it;
            v[p.second] = p.first;
        }
        return v;
    }
};