class Solution {
public:
    vector<vector<int>> orderedPermuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() == 1) {
            ret.push_back(nums);
            return ret;
        }
        int cPos = 0;
        while (cPos < nums.size()) {
            vector<int> v2 = nums;
            v2.erase(v2.begin()+cPos);
            for (vector<int> v : orderedPermuteUnique(v2)) {
                v.push_back(nums[cPos]);
                ret.push_back(v);
            }
            while (cPos+1 < nums.size() && nums[cPos] == nums[cPos+1]) {
                cPos++;
            }
            cPos++;
        }
        return ret;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return orderedPermuteUnique(nums);
    }
};