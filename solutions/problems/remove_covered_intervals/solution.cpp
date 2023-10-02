class Solution {
public:

    struct less_than_key
    {
        inline bool operator() (const vector<int>& struct1, const vector<int>& struct2)
        {
            if (struct1[0] != struct2[0]) return (struct1[0] < struct2[0]);
            return (struct1[1] > struct2[1]);
        }
    };

    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),less_than_key());
        
        // for (int i = 0; i < intervals.size(); i++) {
        //     cout << intervals[i][0] << " "  << intervals[i][1] << endl;
        // }

        vector<bool> valid;
        for (int i = 0; i < intervals.size(); i++) valid.push_back(true);
        for (int i = 0; i < intervals.size(); i++) {
            if (valid[i]) {
                for (int j = i+1; j < intervals.size(); j++) {
                    if (intervals[j][0] >= intervals[i][1]) break;
                    if (valid[j] && intervals[j][1] <= intervals[i][1]) {
                        valid[j] = false;
                    }
                }
            }
            
        }
        int sum = 0;
        for (bool b : valid) {
            if (b) sum++;
        }
        return sum;
    }
};