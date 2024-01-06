class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum = 0, rightsum = 0;
        for (int x : nums) rightsum += x;
        rightsum -= nums[0];
        if (leftsum == rightsum) return 0;
        for (int i = 1; i < nums.size(); i++) {
            leftsum += nums[i-1];
            rightsum -= nums[i];
            if (leftsum == rightsum) return i;
        }
        return -1;
    }
};