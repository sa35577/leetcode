class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int vis[201];
        int n = isConnected.size();
        for (int i = 0; i <= 200; i++) vis[i] = 0;
        int numProvinces = 0;
        for (int idx = 0; idx < n; idx++) {
            if (vis[idx] == 0) {
                numProvinces++;
                deque<int> deck;
                deck.push_back(idx);
                vis[idx] = numProvinces;
                while (!deck.empty()) {
                    int x = deck.front();
                    deck.pop_front();
                    
                        
                    for (int i = 0; i < n; i++) {
                        if (isConnected[x][i] && vis[i] == 0) {
                            vis[i] = numProvinces;
                            deck.push_back(i);
                        }
                    }
                    
                }
            }
        }
        return numProvinces;
    }
};