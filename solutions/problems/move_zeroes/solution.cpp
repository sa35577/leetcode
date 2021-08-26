class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int writer = 0, reader = 0;
        for (reader = 0; reader < nums.size(); reader++) {
            if (nums[reader] != 0) {
                nums[writer] = nums[reader];
                writer++;
            }
        }
        for (int i = writer; i < nums.size(); i++) nums[i] = 0;
        
    }
};