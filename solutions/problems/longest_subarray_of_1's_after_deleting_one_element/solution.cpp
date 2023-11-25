class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum < 1) return sum;
        if (nums.size() == 1) return 0;
        vector<int> leftCount{0},rightCount{0};
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] == 1) leftCount.push_back(leftCount.back()+1);
            else leftCount.push_back(0);
        }
        for (int i = nums.size()-2; i >= 0; i--) {
            if (nums[i+1] == 1) rightCount.push_back(rightCount.back()+1);
            else rightCount.push_back(0);
        }
        reverse(rightCount.begin(),rightCount.end());
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            ret = max(ret,leftCount[i]+rightCount[i]);
        }
        return ret;


    }
};