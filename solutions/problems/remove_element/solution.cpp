class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for (int x : nums) {
            if (x != val) cnt++;
        }
        int L = 0, R = nums.size()-1;
        while (L < R) {
            while (R >= 0 && nums[R] == val) R--;
            while (L < nums.size() && nums[L] != val) L++;
            if (L >= R || R == -1 || L == nums.size()) break;
            swap(nums[L],nums[R]);
        }
        return cnt;
    }
};