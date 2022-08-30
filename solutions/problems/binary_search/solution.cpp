class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int idx = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        // if (idx < nums.size() && nums[idx] == target) return idx;
        // return -1;
        int L = 0, R = nums.size() - 1;
        while (L < R) {
            int mid = (L+R)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) R = mid-1;
            else L = mid+1;
        }
        if (nums[L] == target) return L;
        return -1;
    }
};