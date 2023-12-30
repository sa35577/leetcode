class Solution {
public:
    int sum(int L, int R) {
        int l1 = L+R;
        int l2 = R-L+1;
        if (l1 % 2 == 0) {
            return (l1/2) * l2;
        }
        return (l2/2) * l1;
    }
    int minIncrementForUnique(vector<int>& nums) {
        int score = 0;
        sort(nums.begin(),nums.end());
        int L = 0, R = 0;
        int numDefer = 0;
        while (L < nums.size()) {
            R = L;
            while (R+1 < nums.size() && nums[R+1] == nums[L]) R++;
            numDefer += R-L;
            if (R+1 == nums.size()) {
                //defer all
                if (numDefer >= 0) {
                    score += sum(1,numDefer);
                    numDefer = 0;
                }
            }
            else {
                int numBetween = nums[R+1] - nums[L] - 1; //this is how many we can defer at most
                if (numBetween >= numDefer) {
                    score += sum(1,numDefer);
                    numDefer = 0;
                }
                else {
                    score += sum(1,numBetween);
                    numDefer -= numBetween;
                    score += numDefer * (nums[R+1] - nums[L]);
                }
            }
            L = R+1;
        }
        return score;
    }
};