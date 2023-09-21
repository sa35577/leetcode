class Solution {
public:
    bool intersects(vector<int> &a, vector<int> &b) {
        if (a[1] < b[0] || b[1] < a[0]) return false;
        return true;
    }
    vector<int> mergeIntervals(vector<int> &a, vector<int> &b) {
        if (!intersects(a,b)) {
            return {};
        }
        vector<int> v{min(a[0],b[0]), max(a[1],b[1])};
        return v;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //+ 30
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> newIntervals;
        int idxL = 0, idxR = 0;
        while (idxL < intervals.size()) {
            idxR = idxL+1;
            vector<int> curInterval = intervals[idxL];
            while (idxR < intervals.size() && intersects(curInterval,intervals[idxR])) {
                curInterval = mergeIntervals(curInterval,intervals[idxR]);
                idxR++;
            }
            newIntervals.push_back(curInterval);
            idxL = idxR;
        }
        return newIntervals;
    }
};