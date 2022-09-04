class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int sum = 0, cur = 0;
        for (int i : nums) sum += i;
        vector<int> v;
        int idx = 0;
        while (2*cur <= sum) {
            v.push_back(nums[idx]);
            cur += nums[idx++];
        }
        return v;
    }
};