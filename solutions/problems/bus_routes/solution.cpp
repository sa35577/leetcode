class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int,vector<int>> busses;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                if (busses.find(stop) == busses.end()) {
                    busses[stop] = {};
                }
                busses[stop].push_back(i);
            }
        }
        map<int,int> minBusses; //map from stop to minimum number of busses
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        bool use[501];
        memset(use,0,sizeof(use));
        pq.push({0,source});
        minBusses[source] = 0;
        while (!pq.empty()) {
            pair<int,int> cur = pq.top();
            pq.pop();
            int soFar = cur.first, stop = cur.second;
            if (minBusses[stop] < soFar) continue;
            for (int bus : busses[stop]) {
                if (!use[bus]) {
                    for (int nextStop : routes[bus]) {
                        if (minBusses.find(nextStop) == minBusses.end() || minBusses[nextStop] > soFar+1) {
                            minBusses[nextStop] = soFar+1;
                            pq.push({soFar+1,nextStop});
                        }
                    }
                    use[bus] = 1;
                }
            }
        }
        if (minBusses.find(target) == minBusses.end()) return -1;
        return minBusses[target];
    }
};