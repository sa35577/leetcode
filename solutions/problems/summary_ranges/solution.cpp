class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int L = 0, R = 0;
        vector<string> ret;
        while (L < nums.size()) {
            R = L;
            while (R + 1 < nums.size() && nums[R + 1] > nums[R] && nums[R+1] == nums[R] + 1) R++;
            if (L == R) ret.push_back(to_string(nums[L]));
            else ret.push_back(to_string(nums[L]) + "->" + to_string(nums[R]));
            L = R+1;
        }
        return ret;
    }
};