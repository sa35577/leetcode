class Solution {
public:
    bool intersects(vector<int> &a, vector<int> &b) {
        if (a[1] < b[0] || b[1] < a[0]) return false;
        return true;
    }
    vector<int> unite(vector<int> &a, vector<int> &b) {
        vector<int> v;
        if (!intersects(a,b)) return v;
        v.push_back(min(a[0],b[0]));
        v.push_back(max(a[1],b[1]));
        return v;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // + 2.5 mins
        vector<vector<int>> newIntervals;
        int idx = 0;
        while (idx < intervals.size() && intervals[idx][1] < newInterval[0]) {
            newIntervals.push_back(intervals[idx]);
            idx++;
        }
        // cout << idx << endl;
        
        while (idx < intervals.size() && intersects(intervals[idx],newInterval)) {
            newInterval = unite(newInterval,intervals[idx++]);
        }
        
        newIntervals.push_back(newInterval);
        while (idx < intervals.size()) {
            newIntervals.push_back(intervals[idx]);
            idx++;
        }

        return newIntervals;



    }
};