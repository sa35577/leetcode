class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() == 1) {
            ret.push_back(nums);
            return ret;
        }
        for (int i = 0; i < nums.size(); i++) {
            vector<int> v2 = nums;
            v2.erase(v2.begin()+i);
            vector<vector<int>> rec = permute(v2);
            for (vector<int> v : rec) {
                v.push_back(nums[i]);
                ret.push_back(v);
            }
        }
        return ret;
    }
};