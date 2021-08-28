class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int globalMax = INT_MIN;
        int localMax = 0;
        int globalMin = INT_MAX;
        int localMin = 0;
        for (int i = 0; i < nums.size(); i++) {
            localMax = max(nums[i],nums[i]+localMax);
            globalMax = max(globalMax,localMax);
            localMin = min(nums[i],nums[i]+localMin);
            globalMin = min(globalMin,localMin);
        }
        return max(abs(globalMax),abs(globalMin));
    }
};