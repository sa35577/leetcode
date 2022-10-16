class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        multiset<int> s;
        multiset<int> ss;
        for (int x : nums) s.insert(x);
        for (int x : nums) ss.insert(-x);
        s.erase(s.lower_bound(nums[0]));
        ss.erase(ss.lower_bound(-nums[0]));
        int dest = INT_MAX;
        for (int i = 1; i < nums.size()-1; i++) {
            s.erase(s.lower_bound(nums[i]));
            ss.erase(ss.lower_bound(-nums[i]));
            for (int j = 0; j < i; j++) {
                int targ = target - (nums[i] + nums[j]);
                auto it = s.lower_bound(targ);
                if (it != s.end()) {
                    int res1 = *it;
                    if (abs(dest) > abs(res1-targ)) dest = res1-targ;
                    auto it2 = ss.lower_bound(-targ);
                    if (it2 != ss.end()) {
                        int res2 = *it2;
                        res2 = -res2;
                        if (abs(dest) > abs(res2-targ)) dest = res2-targ;
                    }
                }
                else {
                    auto it2 = s.rbegin();
                    int res2 = *it2;
                    if (abs(dest) > abs(res2-targ)) dest = res2-targ;
                }
            }
            cout << dest << " ";
        }
        return dest+target;
    }
};