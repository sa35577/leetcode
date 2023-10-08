class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        long long llbricks = (long long)(bricks);
        if (heights.size() <= ladders) return heights.size()-1;
        multiset<int> st;
        int idx = 1;
        while (st.size() != ladders) {
            while (idx < heights.size() && heights[idx] - heights[idx-1] <= 0) idx++;
            if (idx == heights.size()) break;
            st.insert(heights[idx] - heights[idx-1]);
            idx++;
        }
        while (idx < heights.size() && heights[idx] - heights[idx-1] <= 0) idx++;
        if (idx == heights.size()) return idx-1;
        long long sum = 0;
        // cout << "here\n";
        while (idx < heights.size() && sum <= llbricks) {
            // cout << idx << " with sum: " << sum << ", elements: ";
            // for (auto it = st.begin(); it != st.end(); it++) cout << *it << " " ;
            // cout << endl;
            
            while (idx < heights.size() && heights[idx] - heights[idx-1] <= 0) idx++;
            if (idx == heights.size()) break;
            int diff = heights[idx] - heights[idx-1];
            if (diff > 0) {
                if (ladders == 0 || diff <= *(st.begin())) {
                    sum += diff;
                }
                else {
                    sum += *(st.begin());
                    st.erase(st.begin());
                    st.insert(diff);
                }
            }
            if (sum > llbricks) break;
            idx++;
        }
        // int mx = -1;
        // for (int x : heights) mx = max(mx,x);
        // cout << "Max is: " << mx << endl;
        // cout << idx << " with sum: " << sum << ", elements: ";
        //     for (auto it = st.begin(); it != st.end(); it++) cout << *it << " " ;
        //     cout << endl;
        // for (int i = idx; i < heights.size() && i <= 72329; i++) cout << heights[i] << endl;
        return idx-1;
    }
};