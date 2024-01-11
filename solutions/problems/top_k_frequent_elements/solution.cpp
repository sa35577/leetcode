class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        set<pair<int,int>> st;
        for (int x : nums) {
            if (freq.find(x) == freq.end()) {
                freq[x] = 1;
                if (st.size() < k) st.insert({1,x});
                else ; //otherwise theres no kicking since we have 1 frequency is minimal
            }
            else {
                int curFreq = freq[x];
                if (curFreq >= (*(st.begin())).first) {
                    auto it = st.lower_bound({curFreq,x});
                    if (it != st.end() && (*(it)).second == x) {
                        st.erase(it);
                        st.insert({curFreq+1,x});
                    }
                    else {
                        st.erase(st.begin());
                        st.insert({curFreq+1,x});
                    }
                }
                else {
                    ;
                }
                freq[x]++;
            }
        }
        vector<int> res;
        for (pair<int,int> p : st) {
            res.push_back(p.second);
        }
        return res;
    }
};