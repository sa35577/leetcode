class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int L = 0, R = 0, cnt = 0;
        while (L < nums.size()) {
            cnt++;
            while (R < nums.size() && nums[R] - nums[L] <= k) R++;
            L = R;
        }
        return cnt;
    }
};