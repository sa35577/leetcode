class Solution {
public:
    
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2);
        v[0] = -1, v[1] = -1;
        //check if exists
        int L = 0, R = nums.size()-1;
        bool exists = false;
        while (L <= R) {
            int mid = L + (R-L)/2;
            if (nums[mid] == target) {
                exists = true;
                break;
            }
            else if (nums[mid] > target) {
                R = mid-1;
            }
            else {
                L = mid+1;
            }
        }
        if (!exists) return v;
        //left bound
        L = 0, R = nums.size()-1;
        while (L < R) {
            int mid = (L+R)/2;
            if (nums[mid] > target) R = mid-1;
            else if (nums[mid] == target) R = mid;
            else L = mid+1;
            
	    }
        v[0] = L;
        //right bound
        L = 0, R = nums.size()-1;
        while (L+1 < R) {
            int mid = (L+R)/2;
            if (nums[mid] > target) R = mid-1;
            else if (nums[mid] == target) L = mid;
            else L = mid+1;
        }
        if (nums[R] == target) v[1] = R;
        else v[1] = L;
        return v;
    }
};