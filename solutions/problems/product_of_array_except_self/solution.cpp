class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> numsL = nums, numsR = nums, numsRet = nums;
        for (int i = 1; i < nums.size(); i++) {
            numsL[i] = numsL[i-1] * nums[i];
        }        
        for (int i = nums.size()-2; i >= 0; i--) {
            numsR[i] = numsR[i+1] * nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) numsRet[i] = numsR[i+1];
            else if (i == nums.size()-1) numsRet[i] = numsL[i-1];
            else numsRet[i] = numsL[i-1] * numsR[i+1];
        }
        return numsRet;
    }
};