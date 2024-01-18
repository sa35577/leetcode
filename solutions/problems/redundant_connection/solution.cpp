class Solution {
public:
    int repeatingVertex = -1;
    set<pair<int,int>> st;
    bool dfs(vector<vector<int>> &graph, vector<bool>& vis, int n, int v, int prev) {
        vis[v] = true;
        for (int nxt : graph[v]) {
            if (nxt != prev) {
                if (vis[nxt]) {
                    repeatingVertex = nxt;
                    st.insert({nxt,v});
                    st.insert({v,nxt});
                    return true;
                }
                else {
                    if (dfs(graph,vis,n,nxt,v)) {
                        if (repeatingVertex != -1) {
                            st.insert({nxt,v});
                            st.insert({v,nxt});
                            if (repeatingVertex == v) {
                                repeatingVertex = -1;
                            }
                        } 
                        return true;
                    }
                }
            }
        }
        vis[v] = false;
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // graph has n-1 edges if n vertices
        // therefore edges.size() = n
        int n = edges.size();
        vector<vector<int>> graph(n+1);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(1);
        vector<bool> vis(n+1);
        fill(vis.begin(),vis.end(),false);
        dfs(graph,vis,n,1,-1);
        reverse(edges.begin(),edges.end());
        for (vector<int> edge : edges) {
            pair<int,int> p;
            p.first = edge[0];
            p.second = edge[1];
            if (st.find(p) != st.end()) return edge;
        }
        return {-1,-1};
    }
};