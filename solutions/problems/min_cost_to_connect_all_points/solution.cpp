class Solution {
public:
    vector<int> ranksize;
    vector<int> rank;

    int getRank(int i) {
        if (rank[i] != i) {
            return getRank(rank[i]);
        }
        return i;
    }

    int mergeRank(int ri, int rj) {
        if (ranksize[ri] >= ranksize[rj]) {
            ranksize[ri] += ranksize[rj];
            return ri;
        }
        else {
            ranksize[rj] += ranksize[ri];
            return rj;
        }
    }



    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < i; j++) {
                pq.push({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]),{j,i}});
            }
        }
        rank.resize(points.size());
        for (int i = 0; i < points.size(); i++) rank[i] = i;
        ranksize.resize(points.size());
        fill(ranksize.begin(),ranksize.end(),1);
        int cost = 0;
        while (!pq.empty()) {
            pair<int,pair<int,int>> cur = pq.top();
            pq.pop();
            int dist = cur.first, i = cur.second.first, j = cur.second.second;
            int ri = getRank(i), rj = getRank(j);
            if (ri != rj) {
                int newRank = mergeRank(ri,rj);
                rank[ri] = newRank;
                rank[rj] = newRank;
                cost += dist;
            }
        }
        return cost;
    }
};