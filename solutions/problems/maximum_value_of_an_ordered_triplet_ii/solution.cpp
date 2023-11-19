class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<long long> N;
        for (int i : nums) {
            N.push_back((long long)(i));
        }
        vector<long long> mxLeft{N[0]};
        vector<long long> mxRight{N.back()};
        for (int i = 1; i < nums.size(); i++) {
            mxLeft.push_back(max(mxLeft.back(),N[i]));
        }
        for (int i = nums.size()-2; i >= 0; i--) {
            mxRight.push_back(max(mxRight.back(),N[i]));
        }
        reverse(mxRight.begin(),mxRight.end());
        long long result = 0;
        for (int i = 1; i < nums.size()-1; i++) {
            result = max(result,(mxLeft[i-1] - N[i]) * mxRight[i+1]);
        }
        return result;
    }
};