class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,string>> v;
        for (string str : strs) {
            string str2 = str;
            sort(str2.begin(),str2.end());
            v.push_back(make_pair(str2,str));
        }
        sort(v.begin(),v.end());
        vector<vector<string>> ret;
        vector<string> first{v[0].second};
        ret.push_back(first);
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first == v[i-1].first) {
                ret.back().push_back(v[i].second);
            }
            else {
                vector<string> newest;
                newest.push_back(v[i].second);
                ret.push_back(newest);
            }
        }
        return ret;

    }
};