class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        if (nums.size() == 1) return nums;
        vector<int> v;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                if (nums[1] > nums[0]+1) v.push_back(nums[0]);
            }
            else if (i == nums.size()-1) {
                if (nums[nums.size()-2] < nums.back()-1) {
                    v.push_back(nums.back());
                }
            }
            else {
                if (nums[i-1] < nums[i]-1 && nums[i+1] > nums[i]+1) v.push_back(nums[i]);
            }

        }
        return v;
        
    }
};