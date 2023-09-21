class Solution {
public:
    bool intersects(vector<int> &a, vector<int> &b) {
        if (a[1] <= b[0] || b[1] <= a[0]) return false;
        return true;
    }

    // bool overlaps(vector<int> &a, vector<int> &b) {
    //     if (intersects(a,b) && )
    // }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //+ 45
        sort(intervals.begin(),intervals.end());
        for (vector<int> interval : intervals) {
            cout << interval[0] << " " << interval[1] << endl;
        }
        int cnt = 0;
        int idxL = 0;
        while (idxL < intervals.size()) {
           int mnIdx = idxL;
           int mnVal = intervals[idxL][1];
           int idxR =  idxL;
           while (idxR < intervals.size() && intersects(intervals[mnIdx],intervals[idxR])) {
                // cout << idxL << " " << mnIdx << " " << idxR << "\n";
            //    cout << intervals[mnIdx][0] << " " << intervals[mnIdx][1] << " " << intervals[idxR][0] << " " << intervals[idxR][1] << endl;
               if (mnVal > intervals[idxR][1]) {
                   mnVal = intervals[idxR][1];
                   mnIdx = idxR;
               }
               
               //cout << idxL << " " << idxR << endl;
               if (idxR > idxL) {
                //    cout << idxL << " " << mnIdx << " " << idxR << "here\n";
                   cnt++;
               }
               idxR++;
           }
           idxL = idxR;
        }
        return cnt;

    }
};