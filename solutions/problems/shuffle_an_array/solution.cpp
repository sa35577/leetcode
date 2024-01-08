class Solution {
public:
    vector<int> original;
    vector<int> cur;
    Solution(vector<int>& nums) {
        original = nums;
        cur = nums;
    }
    
    vector<int> reset() {
        cur = original;
        return cur;
    }
    
    vector<int> shuffle() {
        unordered_set<int> st;
        vector<pair<int,int>> v;
        while (st.size() != original.size()) {
            int x = rand() % INT_MAX;
            if (st.find(x) == st.end()) {
                st.insert(x);
                int sz = st.size();
                v.push_back({x,sz-1});
            }
        }
        // cout << "here\n";
        sort(v.begin(),v.end());
        // for (pair<int,int> i : v) cout << i.first << " " << i.second << endl;
        for (int i = 0; i < original.size(); i++) {
            cur[i] = original[v[i].second];
        }
        return cur;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */