class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(),sortedNums.end());
        int L = 0;
        int R = nums.size()-1;
        while (L < nums.size() && nums[L] == sortedNums[L]) L++;
        while (R >= 0 && nums[R] == sortedNums[R]) R--;
        if (L == nums.size()) return 0;
        return R-L+1;
    }
};