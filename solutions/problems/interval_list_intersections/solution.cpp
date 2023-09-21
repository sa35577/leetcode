class Solution {
public:
    vector<int> intersection(vector<int> &a, vector<int> &b) {
        vector<int> v;
        if (a[1] < b[0] || b[1] < a[0]) return v;
        if (a[0] <= b[0]) {
            v.push_back(b[0]);
            v.push_back(min(b[1],a[1]));
        }
        else {
            v.push_back(a[0]);
            v.push_back(min(b[1],a[1]));
        }
        return v;
    }

    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int firstPtr = 0;
        int secondPtr = 0;
        vector<vector<int>> res;
        while (firstPtr < firstList.size() && secondPtr < secondList.size()) {
            vector<int> intersect = intersection(firstList[firstPtr],secondList[secondPtr]);
            if (intersect.size() == 0) {
                if (firstList[firstPtr][0] > secondList[secondPtr][1]) secondPtr++;
                else firstPtr++;
            }
            else {
                res.push_back(intersect);
                if (firstList[firstPtr][1] >= secondList[secondPtr][1]) secondPtr++;
                else firstPtr++;
            }
        }
        return res;
    }
};