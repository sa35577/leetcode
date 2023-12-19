class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<bool> vis(n+1);
        vector<vector<int>> graph(n+1);
        for (vector<int> v : paths) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
            
        }
        fill(vis.begin(),vis.end(),false);
        vector<int> answer(n);
        fill(answer.begin(),answer.end(),0);
        for (int idx = 1; idx <= n; idx++) {
            if (answer[idx-1] == 0) {
                //BFS
                deque<int> deck;
                deck.push_back(idx);
                while (!deck.empty()) {
                    int cur = deck.front();
                    deck.pop_front();
                    if (vis[idx]) continue;
                    vis[idx] = 1;
                    bool occ[5];
                    for (int i = 0; i < 5; i++) occ[i] = false;
                    for (int i : graph[cur]) {
                        if (vis[i]) occ[answer[i-1]] = true;
                        else deck.push_back(i);
                    }
                    int colour = 1;
                    while (occ[colour]) colour++;
                    answer[idx-1] = colour;   
                }
            }
        }
        return answer;
    }
};