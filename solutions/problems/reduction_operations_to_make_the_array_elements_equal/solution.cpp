class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int R = 1;
        int cnt = 0;
        while (R < nums.size()) {
            while (R < nums.size() && nums[R] == nums[R-1]) R++;
            if (R == nums.size()) break;
            cnt += R;
            R++;
        }
        return cnt;
    }
};