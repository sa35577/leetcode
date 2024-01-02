class Solution {
public:
    int test(vector<int> &nums, int maxdiff) {
        // returns number of pairs whose distance is <= maxdiff
        int L = 0, R = -1;
        int cnt = 0;
        for (; L < nums.size(); L++) {
            if (R < L) R = L;
            while (R+1 < nums.size() && nums[R+1] - nums[L] <= maxdiff) R++;
            cnt += R-L;
        }
        return cnt;

    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int L = 0, R = nums.back();
        while (L < R) {
            int mid = (L+R)/2;
            int v = test(nums,mid);
            if (v > k) {
                R = mid-1;
            }
            else if (v < k) {
                L = mid+1;
            }
            else {
                R = mid;
            }
        }
        while (test(nums,L) < k) L++;
        return L;
    }
};