class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> mnRight{nums[0]};
        vector<int> mnLeft{nums.back()};
        for (int i = 1; i < nums.size(); i++) {
            mnRight.push_back(min(mnRight.back(),nums[i]));
        }
        for (int i = nums.size()-2; i >= 0; i--) {
            mnLeft.push_back(min(mnLeft.back(),nums[i]));
        }
        reverse(mnLeft.begin(),mnLeft.end());
        int result = INT_MAX;
        for (int i = 1; i < nums.size()-1; i++) {
            if (nums[i] > mnRight[i-1] && nums[i] > mnLeft[i+1]) {
                result = min(result,nums[i] + mnRight[i-1] + mnLeft[i+1]);
            }
        }
        if (result == INT_MAX) return -1;
        return result;
    }
};