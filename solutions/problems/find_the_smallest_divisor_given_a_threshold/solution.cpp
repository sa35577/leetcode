class Solution {
public:
    bool test(vector<int>& nums, int threshold, int t) {
        int score = 0;
        for (int x : nums) {
            if (x % t == 0) score += x/t;
            else score += x/t + 1;
        }
        return (score <= threshold);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int L = 1, R = 100000000;
        while (L + 1 < R) {
            if (test(nums,threshold,(L+R)/2)) {
                R = (L+R)/2;
            }
            else L = (L+R)/2 + 1;
        }
        if (test(nums,threshold,L)) return L;
        return R;
    }
};