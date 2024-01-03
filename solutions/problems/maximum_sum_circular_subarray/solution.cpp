class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = -1e6;
        int prevmx = 0;
        //maximum without a loop
        for (int i = 0; i < nums.size(); i++) {
            prevmx = max(prevmx+nums[i],nums[i]);
            ans = max(ans,prevmx);
        }

        vector<int> psa{nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            psa.push_back(psa.back()+nums[i]);
        }
        // cout << psa[0] << " ";
        for (int i = 1; i < nums.size(); i++) {
            psa[i] = max(psa[i],psa[i-1]);
            // cout << psa[i] << " ";
        }
        // cout << endl;

        vector<int> psarev{nums.back()};
        for (int i = nums.size()-2; i >= 0; i--) {
            psarev.push_back(psarev.back()+nums[i]);
        }
        reverse(psarev.begin(),psarev.end());
        for (int i = nums.size()-2; i >= 0; i--) {
            psarev[i] = max(psarev[i],psarev[i+1]);
        }
        for (int i = 0; i < nums.size()-1; i++) {
            ans = max(ans,psa[i]+psarev[i+1]);
        }
        
        return ans;
    }
};