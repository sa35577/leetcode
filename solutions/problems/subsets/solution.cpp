class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        if (nums.size() == 0) {
            vector<int> empty;
            v.push_back(empty);
            return v;
        }
        vector<int> rec = nums;
        int val = nums[0];
        rec.erase(rec.begin());
        vector<vector<int>> subsetsRec = subsets(rec);
        v.insert(v.end(),subsetsRec.begin(),subsetsRec.end());
        for (vector<int> w : subsetsRec) {
            w.push_back(val);
            v.push_back(w);
        }
        return v;
    }
};