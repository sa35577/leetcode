class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for (int i : nums) {
            if (mp.find(i) == mp.end()) mp[i] = 1;
            else mp[i]++;
        }
        set<pair<int,int>> s;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            s.insert({it->second,it->first});
        }
        int cnt = 0;
        vector<int> res;
        for (auto rit = s.rbegin(); rit != s.rend(); rit++) {
            res.push_back(rit->second);
            ++cnt;
            if (cnt == k) break;
        }
        return res;
        
    }
};