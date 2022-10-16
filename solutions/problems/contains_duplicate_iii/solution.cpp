class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<int> s;
        int sz = nums.size();
        for (int i = 0; i <= min(indexDiff,sz-1); i++) {
            s.insert(nums[i]);
        }
        for (int idx = 0; idx < sz; idx++) {
            s.erase(s.lower_bound(nums[idx]));
            auto it = s.lower_bound(nums[idx]-valueDiff);
            if (it != s.end()) {
                int val = *it;
                if (val <= nums[idx]+valueDiff) return true;
            }
            if (idx - indexDiff >= 0) s.erase(s.lower_bound(nums[idx-indexDiff]));
            if (idx + indexDiff + 1 < sz) s.insert(nums[idx + indexDiff + 1]);
            s.insert(nums[idx]);
        }
        return false;
    }
};