class Solution {
public:
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int,int>> leftEnds;
        vector<int> res;
        for (int i = 0; i < intervals.size(); i++) {
            leftEnds.push_back({intervals[i][0],i});
        }
        sort(leftEnds.begin(),leftEnds.end());
        
        for (vector<int> interval : intervals) {
            int L = 0, R = intervals.size() - 1;
            int mid = 0;
            int val = interval[1];
            while (L < R) {
                mid = (L+R)/2;
                if (val > leftEnds[mid].first) L = mid+1;
                else R = mid;
            }
            mid = L;
            if (val > leftEnds[mid].first) res.push_back(-1);
            else res.push_back(leftEnds[mid].second);
        }
        return res;
    }
};