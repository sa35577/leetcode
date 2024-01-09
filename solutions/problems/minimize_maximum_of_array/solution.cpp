class Solution {
public:
    bool test(vector<int>& nums, int k) {
        int idx = nums.size()-2;
        long long cur = nums[nums.size()-1];
        long long prev = nums[nums.size()-2];
        while (true) {
            if (cur > k) {
                prev += (long long)(cur-k);
                cur -= (cur-k);
            }
            cur = prev;
            idx--;
            if (idx == -1) break; 
            prev = nums[idx];
        }
        return cur <= k;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int L = 0, R = INT_MAX;
        while (L+1 < R) {
            int mid = (L+R)/2;
            if (test(nums,mid)) R = mid;
            else L = mid+1;
        }
        if (test(nums,L)) return L;
        return R;

    }
};