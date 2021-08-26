class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> missing;
        for (int i = 1; i < nums[0]; i++) missing.push_back(i);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = nums[i-1]+1; j < nums[i]; j++) missing.push_back(j);
        }
        for (int i = nums.back()+1; i <= nums.size(); i++) missing.push_back(i);
        return missing;
    }
};