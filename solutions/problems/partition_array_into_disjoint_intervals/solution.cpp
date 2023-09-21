class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> mx{nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            mx.push_back(max(nums[i],mx.back()));
        }
        reverse(nums.begin(),nums.end());
        vector<int> mn{nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            mn.push_back(min(nums[i],mn.back()));
        }
        reverse(nums.begin(),nums.end());
        reverse(mn.begin(),mn.end());
        for (int i = 0; i < nums.size(); i++) {
            if (mx[i] <= mn[i+1]) return i+1;
        }
        return -1;

    }

};