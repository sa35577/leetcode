class Solution {
public:
    bool intersects(vector<int> &a, vector<int> &b) {
        return (a[0] >= b[0] && a[0] <= b[1]) || (a[1] >= b[0] && a[1] <= b[1]);
    }
    void printInterval(vector<int> &a) {
        cout << a[0] << " " << a[1] << endl;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int L = 0;
        while (L < intervals.size()) {
            int R = L;
            vector<int> insertingInterval = intervals[L];
            while (R < intervals.size() && intersects(intervals[R],insertingInterval)) {
                insertingInterval[1] = max(insertingInterval[1],intervals[R][1]);
                R++;
            }
            R--;
            ans.push_back(insertingInterval);
            cout << L << " " << R << endl;
            L = R+1;
        }
        return ans;
    }
};