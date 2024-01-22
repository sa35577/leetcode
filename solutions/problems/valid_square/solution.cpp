class Solution {
public:
    int dist(vector<int>& v1, vector<int>& v2) {
        return (v1[0] - v2[0]) * (v1[0] - v2[0]) + (v1[1] - v2[1]) * (v1[1] - v2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> v;
        set<pair<int,int>> st;
        v.push_back(dist(p1,p2));
        v.push_back(dist(p1,p3));
        v.push_back(dist(p1,p4));
        v.push_back(dist(p3,p2));
        v.push_back(dist(p4,p2));
        v.push_back(dist(p3,p4));
        sort(v.begin(),v.end());
        for (vector<int> vv : {p1,p2,p3,p4}) {
            st.insert({vv[0],vv[1]});
        }
        if (st.size() != 4) return false;
        if (v[4] != v[5]) return false;
        if (v[0] != v[1] || v[0] != v[2] || v[0] != v[3]) return false;
        return (v[0] * 2 == v[5]);
    }
};