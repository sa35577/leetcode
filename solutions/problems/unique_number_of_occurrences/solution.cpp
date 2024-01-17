class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for (int &x : arr) {
            if (mp.find(x) == mp.end()) mp[x] = 1;
            else mp[x]++;
        }
        unordered_set<int> st;
        for (auto it = mp.begin(); it != mp.end(); it++) st.insert(it->second);
        return st.size() == mp.size();
    }
};