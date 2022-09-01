class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> v;
        for (int i = 1; i < nums.size(); i++) {
            v.push_back((nums[i] + nums[i-1]) % 10);
        }
        return triangularSum(v);
    }
};