class Solution {
public:
    int inclusible(int L, int R) {
        //in any range L,R of inclusible things, we can take (R-L+1)/2 houses
        if (L > R) return 0;
        return (R-L)/2+1;
    }
    int minCapability(vector<int>& nums, int k) {
        // cout << inclusible(0,3) << " " << inclusible(0,2) << " " << inclusible(4,3) << endl;
        vector<pair<int,int>> desc;
        for (int i = 0; i < nums.size(); i++) desc.push_back({nums[i],i});
        sort(desc.rbegin(),desc.rend());
        set<int> st;
        st.insert(-1);
        st.insert(nums.size());
        int curk = inclusible(0,nums.size()-1);
        int iteration = 0;
        for (pair<int,int> cur : desc) {
            int idx = cur.second;
            int val = cur.first;
            auto it = st.lower_bound(idx);
            auto it2 = it;
            it2--;
            int prevR = *it, prevL = *it2;
            curk -= inclusible(prevL+1,prevR-1);
            curk += inclusible(prevL+1,idx-1);
            curk += inclusible(idx+1,prevR-1);
            // cout << prevL << " " << idx << " " << prevR << endl;
            if (curk < k) {
                return val;
            }
            else st.insert(idx);
            iteration++;
            // cout << curk << endl;
        }
        return desc.back().first;

    }
};