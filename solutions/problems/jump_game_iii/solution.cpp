class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size());
        vis[start] = 0;
        deque<int> deck;
        deck.push_back(start);
        while (!deck.empty()) {
            int cur = deck.front();
            deck.pop_front();
            if (!vis[cur]) {
                vis[cur] = 1;
                if (cur-arr[cur] >= 0 && !vis[cur-arr[cur]]) deck.push_back(cur-arr[cur]);
                if (cur+arr[cur] < arr.size() && !vis[cur+arr[cur]]) deck.push_back(cur+arr[cur]);
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0 && vis[i]) return true;
        }
        return false;
    }
};