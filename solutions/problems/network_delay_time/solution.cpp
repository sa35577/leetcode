class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> vis(n+1);
        int cnt = n;
        fill(vis.begin(),vis.end(),false);
        vector<vector<pair<int,int>>> graph(n+1);
        for (vector<int> v : times) {
            graph[v[0]].push_back({v[1],v[2]});
        }
        pq.push({0,k});

        while (!pq.empty()) {
            pair<int,int> cur = pq.top();
            // cout << cur.first << " " << cur.second << endl;
            pq.pop();
            int dist = cur.first, node = cur.second;
            if (vis[node]) continue;
            vis[node] = 1;
            cnt--;
            if (cnt == 0) return dist;
            for (pair<int,int> nxt : graph[node]) {
                if (!vis[nxt.first]) {
                    pq.push({nxt.second + dist, nxt.first});
                }
            }

        }
        return -1;

    }
};