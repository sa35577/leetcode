class Solution {
public:
    int findMin(vector<int>& nums) {
        int L = 0, R = nums.size() - 1;
        while (L+1 < R) {
            int mid = (L+R)/2;
            if (nums[mid] >= nums[L]) L = mid;
            else R = mid;
        }
        int maxIndex = L;
        if (nums[R] >= nums[L]) maxIndex = R;
        return nums[(maxIndex+1) % (nums.size())];
    }
};