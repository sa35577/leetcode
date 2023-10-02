class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> diff;
        int sum = 0;
        for (int i = 1; i < nums.size(); i++) {
            diff.push_back(nums[i] - nums[i-1]);
        }
        for (int i = 0; i < diff.size(); i++) {
            int R = i;
            while (R+1 < diff.size() && diff[R+1] == diff[i]) R++;
            int curDiff = R-i;
            sum += curDiff;

        }
        return sum;
    }
};