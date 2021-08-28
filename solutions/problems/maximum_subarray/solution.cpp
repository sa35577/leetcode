class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bigMx = -1e9-6;
        int prevMx = 0;
        for (int i = 0; i < nums.size(); i++) {
            prevMx = max(nums[i],nums[i]+prevMx);
            bigMx = max(bigMx,prevMx);
        }
        return bigMx;
    }
};