class Solution {
public:
    int countRange(int L, int R) {
        return R-L+1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int L = 0, R = nums.size()-1;
        while (L < R) {
            int mid = (L+R)/2;
            if (((mid == 0) || (mid > 0 && nums[mid-1] != nums[mid])) && ((mid == nums.size()-1) || (mid < nums.size()-1 && nums[mid] != nums[mid+1]))) return nums[mid];
            if (mid > 0 && nums[mid] == nums[mid-1]) {
                if (countRange(L,mid-2) % 2 == 1) {
                    R = mid-2;
                }
                else L = mid+1;
            }
            else {
                if (countRange(L,mid-1) % 2 == 1) {
                    R = mid-1;
                }
                else L = mid+2;
            }
        }
        return nums[L];
    }
};