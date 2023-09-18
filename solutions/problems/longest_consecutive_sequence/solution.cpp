class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for (int i : nums) s.insert(i);
        int prev = INT_MIN;
        int ans = 1;
        int mx = 0;
        for (auto it = s.begin(); it != s.end(); it++) {
            int x = *it;
            if (x == prev+1) {
                ans++;
                mx = max(ans,mx);
            }
            else {
                ans = 1;
                mx = max(ans,mx);
            }
            prev = x;
        }
        return mx;
    }
};