class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sq;
        for (int i = 0; i < nums.size(); i++) nums[i] = abs(nums[i]);
        int mid = 0;
        while (mid+1 < nums.size() && nums[mid] >= nums[mid+1]) mid++;
        sq.push_back(nums[mid]*nums[mid]);
        int L = mid-1, R = mid+1;
        while (L >= 0 || R < nums.size()) {
            if (L >= 0 && R < nums.size()) {
                if (nums[L] <= nums[R]) {
                    sq.push_back(nums[L]*nums[L]);
                    L--;
                }
                else {
                    sq.push_back(nums[R]*nums[R]);
                    R++;
                }
            }
            else if (L >= 0) {
                sq.push_back(nums[L]*nums[L]);
                L--;
            }
            else {
                sq.push_back(nums[R]*nums[R]);
                R++;
            }
            
        }
        return sq;
    }
};