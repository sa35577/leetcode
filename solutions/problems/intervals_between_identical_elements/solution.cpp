class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int,vector<long long>> idxs;
        for (int i = 0; i < arr.size(); i++) {
            if (idxs.find(arr[i]) == idxs.end()) idxs[arr[i]] = {};
            idxs[arr[i]].push_back((long long)(i));
        }
        vector<long long> ans(arr.size());
        for (auto it = idxs.begin(); it != idxs.end(); it++) {
            vector<long long> v = it->second;
            long long curSum = 0;
            for (int i = 1; i < v.size(); i++) {
                curSum += v[i] - v[0];
            }
            ans[v[0]] = curSum;
            for (int i = 1; i < v.size(); i++) {
                long long shift = v[i] - v[i-1];
                curSum -= shift * (long long)(v.size()-i);
                curSum += shift * (long long)(i);
                ans[v[i]] = curSum;
            }
        }
        return ans;
    }
};