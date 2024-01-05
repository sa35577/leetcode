class Solution {
public:
    bool test(vector<int>& nums, int k, int largestSum) {
        int cnt = 0;
        int idx = 0;
        int curSum;
        while (idx < nums.size()) {
            // if (largestSum == 17) cout << idx << ":) " ;
            curSum = nums[idx];
            while (idx+1 < nums.size() && curSum + nums[idx+1] <= largestSum) {
                idx++;
                curSum += nums[idx];
            }
            cnt++;
            idx++;
        }
        // cout << endl;
        return (cnt <= k);
    }
    int splitArray(vector<int>& nums, int k) {
        int L = 0, R = 0;
        for (int x : nums) {
            L = max(L,x);
            R += x;
        }
        while (L+1 < R) {
            // cout << L << " " << R << endl;
            int mid = (L+R)/2;
            if (test(nums,k,mid)) {
                R = mid;
            }
            else {
                L = mid+1;
            }
        }
        // cout << L << " " << R << endl;
        if (test(nums,k,L)) return L;
        return R;
    }
};