class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0, R = 0;
        int sum = nums[0];
        int minLength = INT_MAX;
        while (R+1 < nums.size() && sum < target) {
            R++;
            sum += nums[R];
        }
        if (sum < target) {
            return 0;
        }
        minLength = R-L+1;
        while (L < nums.size() && R < nums.size()) {
            sum -= nums[L];
            L++;
            while (R+1 < nums.size() && sum < target) {
                R++;
                sum += nums[R];
            }
            if (sum < target) break;
            minLength = min(minLength,R-L+1);
        }
        return minLength;
    }
};