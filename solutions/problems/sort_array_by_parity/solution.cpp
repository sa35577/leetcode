class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> dck;
        vector<int> cck;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) dck.emplace_back(nums[i]);
            else cck.emplace_back(nums[i]);
        }
        dck.insert(dck.end(), cck.begin(), cck.end());
        return dck;
    }
};