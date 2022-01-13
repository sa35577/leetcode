class Solution {
public:
    int maxDistance(vector<int>& colors) {
        pair<int,int> extremes[101];
        bitset<101> vis;
        for (int i = 0; i < colors.size(); i++) {
            if (vis[colors[i]]) {
                extremes[colors[i]].second = i;
            }
            else {
                extremes[colors[i]].first = i;
                extremes[colors[i]].second = i;
                vis[colors[i]] = 1;
            }
        }
        int mx = -1;
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < i; j++) {
                if (vis[i] && vis[j]) {
                    mx = max(mx,abs(extremes[i].first-extremes[j].second));
                    mx = max(mx,abs(extremes[j].first-extremes[i].second));
                    mx = max(mx,abs(extremes[j].second-extremes[i].second));
                    mx = max(mx,abs(extremes[j].first-extremes[i].first));
                }
            }
        }
        return mx;
    }
};