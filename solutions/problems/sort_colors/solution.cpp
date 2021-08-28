class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3);
        for (int i : nums) v[i]++;
        int idx = 0;
        while (v[0] > 0) {
            nums[idx] = 0;
            idx++;
            v[0]--;
        }
        while (v[1] > 0) {
            nums[idx] = 1;
            idx++;
            v[1]--;
        }
        while (v[2] > 0) {
            nums[idx] = 2;
            idx++;
            v[2]--;
        }
    }
};