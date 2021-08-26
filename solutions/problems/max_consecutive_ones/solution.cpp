class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cur = 1;
                while (i+1 < nums.size() && nums[i+1] == 1) {
                    cur++;
                    i++;
                }
                mx = max(cur,mx);
            }
        }
        return mx;
    }
};