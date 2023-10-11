class Solution {
public:
    string frequencySort(string s) {
        map<char,int> freq;
        for (char c : s) {
            if (freq.find(c) == freq.end()) freq[c] = 0;
            freq[c]++;
        }
        set<pair<int,char>> st;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            st.insert({it->second,it->first});
        }
        string res = "";
        for (auto it = st.rbegin(); it != st.rend(); it++) {
            pair<int,char> p = *it;
            for (int i = 0; i < p.first; i++) res += p.second;
        }
        return res;
    }
};