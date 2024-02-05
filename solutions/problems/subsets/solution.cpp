class Solution {
public:
    vector<vector<int>> getAll(vector<int>& nums, int idx, vector<int>& soFar) {
        if (idx == nums.size()) return {soFar};
        //pass forward skipping
        vector<vector<int>> v1 = getAll(nums,idx+1,soFar);
        soFar.push_back(nums[idx]);
        vector<vector<int>> v2 = getAll(nums,idx+1,soFar);
        soFar.pop_back();
        v1.insert(v1.end(),v2.begin(),v2.end());
        return v1;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> e{};
        return getAll(nums,0,e);
    }
};