class Solution {
public:
    bool canJump(vector<int>& nums) {
        bitset<100010> b;
        b[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (b[i]) {
                if (i + nums[i] >= nums.size()) return true;
                for (int j = i+1; j <= i + nums[i]; j++) b[j] = 1;
            }
        }
        return b[nums.size()-1];
    }
};