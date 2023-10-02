class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<int, long long> sum;
        unordered_map<int,vector<int>> locs;
        vector<long long> res;
        res.resize(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (locs.find(nums[i]) == locs.end()) {
                vector<int> v{i};
                locs[nums[i]] = v;
                sum[nums[i]] = 0;
            } 
            else {
                locs[nums[i]].push_back(i);
                sum[nums[i]] += (long long)(i - locs[nums[i]][0]);
            }
        }

        for (auto it = locs.begin(); it != locs.end(); it++) {
            int val = it->first;
            vector<int> v = it->second;
            res[v[0]] = sum[val];
            for (int i = 1; i < v.size(); i++) {
                int diff = v[i] - v[i-1];
                // things before: 0 .. i-1
                // things after: i+1 .. v.size()-1
                long long curSum = res[v[i-1]];
                curSum += (i-1) * diff;
                curSum -= (v.size()-1-i)*diff;
                res[v[i]] = curSum;
            }
        }
        return res;

    }
};