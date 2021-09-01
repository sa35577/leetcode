#include <unordered_set>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        if (nums.size() <= k) {
            for (int i : nums) st.insert(i);
            if (st.size() < nums.size()) return true;
            else return false;
        }
        for (int i = 0; i <= k; i++) st.insert(nums[i]);
        if (st.size() < k+1) return true;
        int idx = k;
        while (idx+1 < nums.size()) {
            st.erase(nums[idx-k]);
            st.insert(nums[++idx]);
            if (st.size() < k+1) return true;
        }
        return false;
    }
};