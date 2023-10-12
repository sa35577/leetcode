class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() <= 1) return points.size();
        set<pair<int,int>> leftSort,rightSort;
        for (vector<int> point : points) {
            leftSort.insert(make_pair(point[0],point[1]));
            rightSort.insert(make_pair(point[1],point[0]));
        }
        int cnt = 0;
        while (rightSort.size() > 0) {
            cnt++;
            pair<int,int> p = *rightSort.begin();
            //rightSort.erase(rightSort.begin());
            //leftSort.erase({p.second,p.first});
            while (!leftSort.empty() && (*leftSort.begin()).first <= p.first) {
                pair<int,int> p = *leftSort.begin();
                leftSort.erase(leftSort.begin());
                rightSort.erase({p.second,p.first});
            }
        }
        return cnt;
    }
};