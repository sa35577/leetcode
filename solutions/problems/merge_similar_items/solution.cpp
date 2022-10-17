class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int> mp;
        for (int i = 0; i < items1.size(); i++) {
            if (mp.find(items1[i][0]) != mp.end()) {
                mp[items1[i][0]] += items1[i][1];
            }
            else mp[items1[i][0]] = items1[i][1];
        }
        for (int i = 0; i < items2.size(); i++) {
            if (mp.find(items2[i][0]) != mp.end()) {
                mp[items2[i][0]] += items2[i][1];
            }
            else mp[items2[i][0]] = items2[i][1];
        }
        vector<vector<int>> ret;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vector<int> v{it->first,it->second};
            ret.push_back(v);
        }
        return ret;
    }
};