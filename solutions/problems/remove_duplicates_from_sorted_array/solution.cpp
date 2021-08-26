class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int shift = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1-shift]) shift++;
            else nums[i-shift] = nums[i];
        }
        return nums.size()-shift;
    }
};