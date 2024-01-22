class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> f;
        int dom = -1;
        for (int x : nums) {
            if (f.find(x) == f.end()) f[x] = 0;
            f[x]++;
            if (f[x] * 2 > nums.size()) dom = x;
        }
        int cnt = 0;
        int idx = 0;
        while (idx < nums.size()) {
            if (nums[idx] == dom) cnt++;
            if (cnt * 2 > (idx-0+1) && (f[dom] - cnt) * 2 > (nums.size()-1 - (idx+1) + 1)) {
                return idx;
            }
            idx++;
        }
        return -1;

    }
};