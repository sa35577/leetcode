class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<map<int,int>> v; //vector<map: difference -> max seq length
        v.resize(nums.size());
        int mx = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i-1; j >= 0; j--) {
                int diff = nums[i] - nums[j];
                int curResult;
                if (v[j].find(diff) == v[j].end()) curResult = 2;
                else curResult = v[j][diff] + 1;
                
                if (v[i].find(diff) == v[i].end()) v[i][diff] = curResult;
                else v[i][diff] = max(v[i][diff],curResult);
                mx = max(mx,curResult);
                
            }
        }
        return mx;
    }
};