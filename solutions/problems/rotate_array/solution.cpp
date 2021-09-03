class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (k == 0) return;
        vector<int> nums2(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            nums2[(i+k)%(nums.size())] = nums[i];
        }
        nums = nums2;
    }
};