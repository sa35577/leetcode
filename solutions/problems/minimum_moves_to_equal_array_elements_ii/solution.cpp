class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if (nums.size() == 1) return 0;
        long long N = (long long)(nums.size());
        vector<long long> sumLeft{(long long)(nums[0])}, sumRight{(long long)(nums.back())};
        for (int i = 1; i < nums.size(); i++) {
            sumLeft.push_back(sumLeft.back()+(long long)(nums[i]));
        }
        for (int i = (int)(nums.size())-2; i >= 0; i--) {
            sumRight.push_back(sumRight.back()+(long long)(nums[i]));
        }
        reverse(sumRight.begin(),sumRight.end());
        long long mn = min(sumRight[1] - (long long)(nums[0]) * (N-1), (long long)(nums.back()) * (N-1) -  sumLeft[N-2]);

        for (long long i = 1; i < N-1; i++) {
            long long cur = (long long)(nums[(int)(i)]);
            mn = min(mn, cur*i - sumLeft[(int)(i-1)] + sumRight[(int)(i+1)] - cur*(N-i-1));

        }
        return (int)(mn);


    }
};