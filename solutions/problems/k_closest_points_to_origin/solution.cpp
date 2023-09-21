class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for (vector<int> point : points) {
            pq.push({point[0]*point[0] + point[1]*point[1],{point[0],point[1]}});
        }
        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            vector<int> v;
            pair<int,pair<int,int>> p = pq.top();
            pq.pop();
            v.push_back(p.second.first);
            v.push_back(p.second.second);
            res.push_back(v);
        }
        return res;
    }
};