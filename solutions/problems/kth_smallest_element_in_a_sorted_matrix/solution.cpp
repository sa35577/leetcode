class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for (int i = 0; i < matrix[0].size(); i++) pq.push({matrix[0][i],{0,i}});
        int cur = -1;
        for (int rep = 1; rep <= k; rep++) {
            pair<int,pair<int,int>> p = pq.top();
            pq.pop();
            cur = p.first;
            p.second.first++;
            if (p.second.first < matrix.size()) {
                p.first = matrix[p.second.first][p.second.second];
                pq.push(p);
            }
        }
        return cur;
    }
};