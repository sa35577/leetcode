class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> v;
        int curPos = 0;
        while (curPos < intervals.size() && intervals[curPos][1] < newInterval[0]) {
            v.push_back(intervals[curPos++]);
        }
        if (curPos == intervals.size()) {
            v.push_back(newInterval);
            return v;
        }
        int L = 0,R = 0;
        if (intervals[curPos][0] < newInterval[0]) { //build with current interval in array as left end
            L = intervals[curPos][0];
            R = max(intervals[curPos][1],newInterval[1]);
            while (curPos < intervals.size() && intervals[curPos][0] <= R) {
                R = max(R,intervals[curPos++][1]);
            }
        }
        else { //build with new interval as left end
            L = newInterval[0];
            R = newInterval[1];
            while (curPos < intervals.size() && intervals[curPos][0] <= R) {
                R = max(R,intervals[curPos++][1]);
            }
        }
        vector<int> newElement{L,R};
        v.push_back(newElement);
        while (curPos < intervals.size()) {
                v.push_back(intervals[curPos++]);
        }
        return v;
    }
};