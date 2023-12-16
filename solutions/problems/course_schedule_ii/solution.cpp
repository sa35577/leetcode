class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph;
        graph.resize(numCourses);
        vector<int> cnt(numCourses);
        int vis = 0;
        for (int i = 0; i < numCourses; i++) cnt[i] = 0;
        for (vector<int> req : prerequisites) {
            cnt[req[0]]++;
            graph[req[1]].push_back(req[0]);
        }
        deque<int> deck;
        for (int i = 0; i < numCourses; i++) {
            if (cnt[i] == 0) {
                deck.push_back(i);
                vis++;
            }
        }

        vector<int> order;

        while (!deck.empty()) {
            int x = deck.front();
            order.push_back(x);
            deck.pop_front();
            for (int nxt : graph[x]) {
                cnt[nxt]--;
                if (cnt[nxt] == 0) {
                    vis++;
                    deck.push_back(nxt);
                }
            }
        }

        if (vis == numCourses) return order;
        return {};
    }
};