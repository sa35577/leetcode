class Solution {
public:
    bool dfs(vector<vector<int>>& adjList, int v, vector<int>& res, vector<bool>& vis) {
        vis[v] = true;
        if (v == 0) {
            res.push_back(0);
            return true;
        }
        for (int nxt : adjList[v]) {
            if (!vis[nxt] && dfs(adjList,nxt,res,vis)) {
                res.push_back(v);
                return true;
            }
        }
        return false;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>> adjList(edges.size()+1);
        for (vector<int> edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(edges.size()+1);
        fill(vis.begin(),vis.end(),false);
        vector<int> bobToZero = {};
        dfs(adjList,bob,bobToZero,vis);
        reverse(bobToZero.begin(),bobToZero.end());
        vector<int> score(edges.size()+1);
        fill(score.begin(),score.end(),0);
        score[0] = amount[0];
        queue<pair<int,int>> q; //pair<iteration,node>
        q.push({0,0});
        fill(vis.begin(),vis.end(),false);
        int intersectionTime = -1, warningIteration = INT_MIN;
        vis[0] = 1;
        int mx = INT_MIN;
        unordered_map<int,int> bobNodes;
        for (int i = 0; i < bobToZero.size(); i++) {
            bobNodes[bobToZero[i]] = i;
        }
        // cout << endl;

        while (!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            int iteration = cur.first, node = cur.second;
            bool isLeaf = true;
            cout << node << " " << score[node] << endl;
            for (int nextNode : adjList[node]) {
                if (!vis[nextNode]) {
                    q.push({iteration+1,nextNode});
                    if (warningIteration == INT_MIN) {
                        if (bobNodes.find(nextNode) != bobNodes.end()) {
                            // if (nextNode == 3) cout << warningIteart
                            
                            if (bobNodes[nextNode] == iteration+1) {
                                warningIteration = bobNodes[nextNode] - 1; //next warning
                                score[nextNode] = score[node] + amount[nextNode]/2;
                            }
                            else if (bobNodes[nextNode] >= iteration+1) {
                                score[nextNode] = score[node] + amount[nextNode];
                            }
                            else {
                                score[nextNode] = score[node] + 0;
                            }
                        }
                        else {
                            score[nextNode] = score[node] + amount[nextNode];
                        }
                    }
                    else {
                        if (warningIteration >= 0 && bobToZero[warningIteration] == nextNode) {
                            warningIteration--;
                            score[nextNode] = score[node] + 0;
                        }
                        else {
                            score[nextNode] = score[node] + amount[nextNode];
                        }
                    }
                    vis[nextNode] = true;
                    isLeaf = false;
                }
            }
            if (isLeaf) mx = max(mx,score[node]);
        }
        return mx;

    }
};