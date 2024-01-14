class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long tot = 0;
        long long L = -1;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                if (L == -1) L = (long long)(r);
                tot += (long long)(r) - L + 1LL;
            }
            else {
                L = -1;
            }
        }
        return tot;
    }
};