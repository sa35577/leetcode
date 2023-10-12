class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ans = INT_MIN;
        int L = 0, R = houses.size()-1;
        while (L < houses.size() && houses[L] <= heaters[0]) {
            ans = max(ans,heaters[0]-houses[L]);
            L++;
        }
        if (L == houses.size()) return ans;
        while (R >= 0 && houses[R] >= heaters.back()) {
            ans = max(ans,houses[R] - heaters.back());
            R--;
        }
        if (R == -1) return ans;
        int curIdx = 0;
        for (int i = L; i <= R; i++) {
            if (heaters[curIdx] >= houses[i]) {
                ans = max(ans,heaters[curIdx]-houses[i]);
            }
            else {
                while (curIdx + 1 < heaters.size() && abs(heaters[curIdx+1] - houses[i]) <= abs(heaters[curIdx] - houses[i])) curIdx++;
                ans = max(ans,abs(heaters[curIdx] - houses[i]));
            }
        }
        return ans;
    }
};