class Solution {
public:
    bool canCross(vector<int>& stones) {
        set<int> st[20001];
        st[0].insert(1);
        for (int i = 0; i < stones.size(); i++) {
            for (int x : st[i]) {
                auto it = lower_bound(stones.begin(),stones.end(),x+stones[i]);
                if (it == stones.end()) continue;
                int idx = (int)(it - stones.begin());
                if (stones[idx] == x + stones[i]) {
                    st[idx].insert(x);
                    st[idx].insert(x-1);
                    st[idx].insert(x+1);
                }
            }
        }
        return st[stones.size()-1].size() > 0;
    }
};