class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long left = 0, right = 0;
        for (int x : nums) right += (long long)(x);
        int minAbsDiff = INT_MAX;
        int bestIdx = -1;
        long long numleft = 0, numright = nums.size();
        for (int idx = 0; idx < nums.size(); idx++) {
            left += (long long)(nums[idx]);
            right -= (long long)(nums[idx]);
            numleft++;
            numright--;
            long long avgleft = left/numleft, avgright = 0;
            if (numright != 0) avgright = right/numright;
            long long diff = abs(avgleft-avgright);
            if (diff <= (long long)(INT_MAX) && (int)(diff) < minAbsDiff) {
                minAbsDiff = (int)(diff);
                bestIdx = idx;
            }
        }
        return bestIdx;
    }
};