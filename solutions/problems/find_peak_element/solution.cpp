class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) {
            if (nums[0] > nums[1]) return 0;
            return 1;
        }
        int L = 0, R = nums.size()-1;
        while (L < R) {
            if (R - L == 1) {
                if (nums[L] > nums[R]) return L;
                return R;
            }
            int mid = (L+R)/2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            else if (nums[mid-1] > nums[mid]) R = mid-1;
            else L = mid+1;
        }
        return L;
    }
};