class Solution {
public:

    int dfs(vector<vector<pair<int,int>>> &adjlist, vector<int> &prev, vector<bool> &vis, int cur) {
        cout << "Current vertex: " << cur << endl;
        for (pair<int,int> nxt : adjlist[cur]) {
            if (vis[nxt.first] && nxt.first != prev[cur]) {
                prev[nxt.first] = cur;
                return nxt.first;
            }
            else if (nxt.first != prev[cur]) {
                prev[nxt.first] = cur;
                vis[nxt.first] = 1;
                int rec = dfs(adjlist,prev,vis,nxt.first);
                if (rec != -1) return rec;
            }
        }
        return -1;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = -1;
        for (vector<int> edge : edges) {
            n = max(n,edge[0]);
            n = max(n,edge[1]);
        }
        vector<bool> vis(n+1);
        for (int i = 0; i <= n; i++) vis[i] = 0;
        vector<vector<pair<int,int>>> adjlist;
        adjlist.resize(n+1);
        int cnt = 0;
        for (vector<int> edge : edges) {
            adjlist[edge[0]].push_back({edge[1],cnt});
            adjlist[edge[1]].push_back({edge[0],cnt});
            cnt++;
        }



        vis[1] = 1;
        vector<int> prev;
        prev.resize(n+1);
        for (int i = 0; i <= n; i++) prev[i] = INT_MAX;
        
        int cyclicEnd = dfs(adjlist,prev,vis,1);

        for (int i = 1; i < prev.size(); i++) cout << i << ": " << prev[i] << endl;

        int mx = -1;
        int cur = cyclicEnd;
        while (!(cur == cyclicEnd && mx > -1)) {
            cout << cur;
            int prevVertex = prev[cur];

            for (int i = 0; i < edges.size(); i++) {
                if ((edges[i][0] == cur && edges[i][1] == prevVertex) || (edges[i][0] == prevVertex && edges[i][1] == cur)) {
                    mx = max(mx,i);
                    break;
                }
            }

            cur = prevVertex;
        }
        return edges[mx];

        
    }
};