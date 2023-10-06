#include <algorithm>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> st;
        for (int i : nums) {
            if (st.empty()) st.push_back(i);
            else if (st[0] > i) st[0] = i;
            else {
                auto it = std::upper_bound(st.begin(),st.end(),i);
                auto it2 = it;
                it2--;
                if (st[it2-st.begin()] != i) {
                    if (it == st.end()) st.push_back(i);
                    else st[it-st.begin()] = i;
                }
            }

            // for (int j : st) cout << j << " ";
            // cout << endl;
            
            
        }
        return st.size();
    }
};