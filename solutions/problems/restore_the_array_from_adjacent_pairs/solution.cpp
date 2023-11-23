class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,vector<int>> nxt;
        for (vector<int> v : adjacentPairs) {
            if (nxt.find(v[0]) == nxt.end()) nxt[v[0]] = {};
            nxt[v[0]].push_back(v[1]);
            if (nxt.find(v[1]) == nxt.end()) nxt[v[1]] = {};
            nxt[v[1]].push_back(v[0]);
        }
        queue<int> q;
        map<int,bool> vis;
        deque<int> dq;
        dq.push_back(adjacentPairs[0][0]);
        q.push(adjacentPairs[0][0]);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            vis[x] = true;
            vector<int> v = nxt[x];
            vector<int> nextin;
            for (int i : v) {
                if (vis.find(i) == vis.end()) nextin.push_back(i);
            }
            if (nextin.size() == 2) {
                dq.push_back(nextin[0]);
                dq.push_front(nextin[1]);
                q.push(nextin[0]);
                q.push(nextin[1]);
            }
            else if (nextin.size() == 1) {
                if (dq.front() == x) {
                    dq.push_front(nextin[0]);
                    q.push(nextin[0]);
                }
                else {
                    dq.push_back(nextin[0]);
                    q.push(nextin[0]);
                }
            }
        }
        vector<int> res;
        while (!dq.empty()) {
            res.push_back(dq.front());
            dq.pop_front();
        }
        return res;
    }
};