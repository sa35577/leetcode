class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //break problem down all left indexes for R that works
        int L = 0, prod = 1;
        int sum = 0;
        for (int R = 0; R < nums.size(); R++) {
            prod *= nums[R];
            while (L <= R && prod >= k) {
                prod /= nums[L];
                L++;
            }
            if (L > R) continue;
            sum += (R-L+1);
        }
        return sum;
    }
};