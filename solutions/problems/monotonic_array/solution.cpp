class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool b1 = true,b2 = true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) b1 = false;
            if (nums[i] < nums[i-1]) b2 = false;
        }
        return (b1 || b2);
    }
};