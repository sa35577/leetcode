class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        multiset<int> left, right;
        for (int i : nums) right.insert(i);
        right.erase(right.lower_bound(nums[0]));
        left.insert(nums[0]);
        for (int i = 1; i < nums.size()-1; i++) {
            right.erase(right.lower_bound(nums[i]));
            auto it = left.begin();
            int x = *it;
            if (x < nums[i]) {
                auto it2 = right.upper_bound(x);
                if (it2 != right.end()) {
                    int y = *it2;
                    if (y > x && y < nums[i]) return true;
                }
            }
            left.insert(nums[i]);
        }
        return false;
    }
};