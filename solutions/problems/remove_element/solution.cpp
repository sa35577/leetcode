class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int backIdx = nums.size()-1;
        int cnt = 0;
        for (int i : nums) if (i == val) cnt++;
        for (int i = 0; i < nums.size()-cnt; i++) {
            if (nums[i] == val) {
                while (nums[backIdx] == val) backIdx--;
                nums[i] = nums[backIdx];
                nums[backIdx] = val;
            }
        }
        return nums.size()-cnt;
    }
};