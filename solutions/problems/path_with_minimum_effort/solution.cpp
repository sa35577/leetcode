class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int mn[105][105];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int y = heights.size(), x = heights[0].size();
        for (int i = 0; i < 105; i++) {
            for (int j = 0; j < 105; j++) {
                mn[i][j] = INT_MAX;
            }
        }
        pq.push({0,{0,0}});

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int dist = cur.first, cy = cur.second.first, cx = cur.second.second;
            if (mn[cy][cx] <= dist) {
                ;
            }
            else {
                mn[cy][cx] = dist;
                if (cy > 0) {
                    pq.push({max(abs(heights[cy-1][cx]-heights[cy][cx]),dist),{cy-1,cx}});
                }
                if (cx > 0) {
                    pq.push({max(abs(heights[cy][cx-1]-heights[cy][cx]),dist),{cy,cx-1}});
                }
                if (cy < y-1) {
                    pq.push({max(abs(heights[cy+1][cx]-heights[cy][cx]),dist),{cy+1,cx}});
                }
                if (cx < x-1) {
                    pq.push({max(abs(heights[cy][cx+1]-heights[cy][cx]),dist),{cy,cx+1}});
                }
            }
        }
        return mn[y-1][x-1];
    }
};