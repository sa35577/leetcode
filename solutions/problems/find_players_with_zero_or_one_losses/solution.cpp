class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        pair<int,int> num[100005];
        for (int i = 0; i < 100005; i++) num[i] = make_pair(0,0);
        for (vector<int> match : matches) {
            num[match[0]].first++;
            num[match[1]].second++;
        }
        vector<int> v1,v2;
        for (int i = 0; i < 100005; i++) {
            if (num[i].first > 0 && num[i].second == 0) v1.push_back(i);
            if (num[i].second == 1) v2.push_back(i);
        }
        vector<vector<int>> res{v1,v2};
        return res;
    }
};