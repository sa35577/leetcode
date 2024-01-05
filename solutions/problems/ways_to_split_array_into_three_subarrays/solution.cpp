class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int suffixSum = 0;
        const int mod = 1e9+7;
        int res = 0;
        vector<int> psa{nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            psa.push_back(psa.back()+nums[i]);
        }
        for (int suffix = nums.size()-1; suffix >= 2; suffix--) {
            suffixSum += nums[suffix];
            if (psa[suffix-1] > 2*suffixSum) {
                ; //santiy check for if its possible to splite [1,...,suffix-1] into 2 parts who are both less than or equal to in size than the suffix sum
            }
            else {
                // now find bounds L,R
                // R = max value such that psa[R] <= psa[suffix-1]-psa[R]
                // L = min value such that suffixSum >= psa[suffix-1] - psa[L]
                auto itL = lower_bound(psa.begin(),psa.end(),psa[suffix-1] - suffixSum);
                int L = itL - psa.begin();
                auto itR = upper_bound(psa.begin(),psa.end(),psa[suffix-1]/2);
                itR--;
                int R = itR - psa.begin();
                if (L <= R && L <= suffix-2) {
                    R = min(R,suffix-2);
                    res = ((R-L+1) + res) % mod;
                }
            }
        }
        return res;
    }
};