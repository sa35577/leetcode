class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> v(n*n+1);
        v[0] = 0;
        int cnt = 1;
        for (int row = n-1; row >= 0; row--) {
            if (((n-1) - row) % 2 == 0) { //moving right
                for (int col = 0; col < n; col++) {
                    v[cnt++] = board[row][col];
                }
            }
            else { //moving left
                for (int col = n-1; col >= 0; col--) {
                    v[cnt++] = board[row][col];
                }
            }
        }
        // cout << "done\n";
        vector<int> mn(n*n+1);
        fill(mn.begin(),mn.end(),100000);
        // mn[1] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        while (!pq.empty()) {
            pair<int,int> cur = pq.top();
            pq.pop();
            int dist = cur.first, pos = cur.second;
            // cout << dist << " " << pos << endl;
            if (mn[pos] > dist) {
                mn[pos] = dist;
                for (int i = pos+1; i <= min(n*n,pos+6); i++) {
                    int nxt = i;
                    if (v[nxt] != -1) nxt = v[nxt];
                    if (mn[nxt] > dist+1) {
                        pq.push({dist+1,nxt});
                    }
                }
            }
        }
        // for (int i = 1; i <= n*n; i++) {
        //     cout << mn[i] << " ";
        //     if (i % n == 0) cout << endl;
        // }
        if (mn[n*n] == 100000) return -1;
        return mn[n*n];
    }
};