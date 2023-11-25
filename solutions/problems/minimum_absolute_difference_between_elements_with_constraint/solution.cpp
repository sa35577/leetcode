class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        if (x == nums.size()-1) {
            return abs(nums[0]-nums.back());
        }
        multiset<int> st;
        for (int i = x; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        
        int globalbest = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            // for (auto it3 = st.begin(); it3 != st.end(); it3++)  {
            //     cout << *it3 << " ";
            // }
            // cout << endl;
            auto it = st.lower_bound(nums[i]);
            auto it2 = it;
            int best = -1;
            if (it == st.begin()) {
                best = min(abs(nums[i]-(*it)), abs(nums[i]-(*it2)));
            }
            else {
                it--;
                best = min(abs(nums[i]-(*it)), abs(nums[i]-(*it2)));
            }
            
            // cout << best << endl;
            if (st.size() > 0) globalbest = min(globalbest,best);

            if (i+x < nums.size()) st.erase(st.lower_bound(nums[i+x]));
            if (i-x+1 >= 0) st.insert(nums[i-x+1]);
        }
        return globalbest;

        
    }
};