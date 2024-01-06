class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bigmx = INT_MIN;
        int prevmx = -1e6;
        for (int x : nums) {
            prevmx = max(prevmx+x,x);
            bigmx = max(bigmx,prevmx);
        }
        return bigmx;
    }
};