class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> psa(nums.size()+1);
        psa[0] = 0;
        for (int i = 0; i < nums.size(); i++) psa[i+1] = psa[i]+nums[i];
        
        int L = 0, R = 0;
        int mx = 0;
        unordered_set<int> st;
        while (R < nums.size()) {
            st.insert(nums[R]);
            if (st.size() < R-L+1) {
                while (nums[L] != nums[R]) {
                    st.erase(nums[L]);
                    L++;
                }
                if (L < R && nums[L] == nums[R]) L++;
            }
            mx = max(mx,psa[R+1]-psa[L]);
            R++;
        }
        return mx;
    }
};