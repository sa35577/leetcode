class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int L = 0, R = nums.size()-1;
        while (L < R) {
            int mid = (L+R)/2;
            if (target == nums[mid]) return mid;
            else if (target > nums[mid]) L = mid+1;
            else R = mid-1;
        }
        if (nums[L] == target) return L;
        if (nums[L] < target) return L+1;
        return L;
    }
};