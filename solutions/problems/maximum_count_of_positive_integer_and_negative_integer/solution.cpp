class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        auto it = upper_bound(nums.begin(),nums.end(),0);
        int idx = it - nums.begin();
        // if (idx == 0 || idx == nums.size()-1) return nums.size();
        int pos = nums.size()-1-idx+1;
        auto it2 = lower_bound(nums.begin(),nums.end(),0);
        if (it2 == nums.begin()) return pos;
        it2--;
        int idx2 = it2-nums.begin();
        pos = max(pos,idx2-0+1);
        return pos;
    }
};