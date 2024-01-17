class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> b{-1};
        
        for (int row = n-1; row >= 0; row--) {
            if (((n-1) - row) % 2 == 0) {
                //sweep right
                for (int col = 0; col < n; col++) b.push_back(board[row][col]);
            }
            else {
                //sweep left
                for (int col = n-1; col >= 0; col--) b.push_back(board[row][col]);
            }
        }
        vector<int> minDist(b.size());
        fill(minDist.begin(),minDist.end(),INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        minDist[1] = 0;
        while (!pq.empty()) {
            pair<int,int> cur = pq.top();
            int dist = cur.first, node = cur.second;
            pq.pop();
            for (int i = 1; i <= min(n*n - node,6); i++) {
                int nxt = node + i;
                if (b[nxt] != -1) nxt = b[nxt];
                if (minDist[nxt] > dist + 1) {
                    minDist[nxt] = dist + 1;
                    pq.push({dist+1,nxt});
                }
            }
        }
        if (minDist.back() == INT_MAX) return -1;
        return minDist.back();
    }
};