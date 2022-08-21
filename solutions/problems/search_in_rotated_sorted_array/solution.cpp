class Solution {
public:
    int mxIndex(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int L = 0, R = nums.size() - 1;
        while (L + 1 < R) {
            int mid = (L+R)/2;
            if (nums[mid] >= nums[L]) L = mid;
            else R = mid;
        }
        if (nums[L] <= nums[R]) return R;
        return L;
    }
    int search(vector<int>& nums, int target) {
        int maxIndex = mxIndex(nums);
        int minIndex = (maxIndex+1) % (nums.size()); //offset = minIndex - 0
        int offset = minIndex;
        int L = 0, R = nums.size() - 1;
        while (L < R) {
            int mid = (L+R)/2;
            int idx = (mid + offset) % (nums.size());
            if (nums[idx] == target) return idx;
            else if (nums[idx] > target) R = mid-1;
            else L = mid+1;
        }
        if (nums[(L+offset)%(nums.size())] == target) return (L+offset)%(nums.size());
        return -1;
    }
};