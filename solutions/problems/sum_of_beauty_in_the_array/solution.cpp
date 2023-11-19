class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> mxLeft{nums[0]};
        vector<int> mnRight{nums.back()};
        for (int i = 1; i < nums.size(); i++) {
            mxLeft.push_back(max(mxLeft.back(),nums[i]));
        }
        for (int i = nums.size()-2; i >= 0; i--) {
            mnRight.push_back(min(mnRight.back(),nums[i]));
        }
        reverse(mnRight.begin(),mnRight.end());
        int beauty = 0;
        for (int i = 1; i < nums.size()-1; i++) {
            if (mxLeft[i-1] < nums[i] && nums[i] < mnRight[i+1]) beauty += 2;
            else if (nums[i-1] < nums[i] && nums[i] < nums[i+1]) beauty++;
        }
        return beauty;
    }
};