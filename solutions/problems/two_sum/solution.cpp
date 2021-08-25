class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v = nums;
        sort(v.begin(),v.end());
        int L = 0, R = v.size()-1;
        while (L < R) {
            if (v[L]+v[R] == target) break;
            else if (v[L]+v[R] > target) R--;
            else L++;
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == v[L] || nums[i] == v[R]) res.push_back(i);
        }
        return res;
    }
};