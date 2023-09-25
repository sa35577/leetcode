#include <algorithm>
class Solution {
public:

    int indexOfLeaf[100005];

    struct Node {
        int L,R;
        int lazy;
        int val;
    } seg[4*100005];

    void build_tree(int v, int L, int R) {
        seg[v].L = L;
        seg[v].R = R;
        seg[v].val = -1;
        if (L == R) {
            indexOfLeaf[L] = v;
            return;
        }
        build_tree(v*2,L,(L+R)/2);
        build_tree(v*2+1,(L+R)/2+1,R);
    }   

    void updateRange(int v, int UL, int UR, int val) {
        int L = seg[v].L, R = seg[v].R;
        if (R < UL || UR < L) return;
        if (seg[v].val != -1) return; //something more optimal is already there
        if (UL <= L && R <= UR) {
            seg[v].val = val;
            return;
        }
        updateRange(v*2,UL,UR,val);
        updateRange(v*2+1,UL,UR,val);
    }  

    void push_all(int v) {
        int L = seg[v].L, R = seg[v].R;
        if (L == R) {
            return;
        }
        if (seg[v].val != -1) {
            if (seg[v*2].val == -1) seg[v*2].val = seg[v].val;
            if (seg[v*2+1].val == -1) seg[v*2+1].val = seg[v].val;
        }
        push_all(v*2);
        push_all(v*2+1);
    }




    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // sort interval by costs, lowest to highest
        // sort queries
        // BINARY SEARCH ON THE QUERIES for applied min and max
        // delete queries that have smallest interval size

        vector<pair<int,pair<int,int>>> sortedIntervals; //
        for (vector<int> v : intervals) {
            sortedIntervals.push_back({v[1]-v[0]+1,{v[0],v[1]}});
        }
        sort(sortedIntervals.begin(),sortedIntervals.end());
        vector<pair<int,int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i],i});
        }
        sort(sortedQueries.begin(),sortedQueries.end());

        build_tree(1,0,queries.size()-1);

        for (pair<int,pair<int,int>> interval : sortedIntervals) {
            auto it = std::lower_bound(sortedQueries.begin(),sortedQueries.end(),make_pair(interval.second.first,-1));
            auto it2 = std::upper_bound(sortedQueries.begin(),sortedQueries.end(),make_pair(interval.second.second,INT_MAX));
            it2--;
            if (it != sortedQueries.end()) {
                int posL = (it - sortedQueries.begin());
                int posR = (it2 - sortedQueries.begin());
                updateRange(1,posL,posR,interval.second.second - interval.second.first + 1);
            }
        }
        push_all(1);

        vector<int> res;
        res.resize(queries.size());

        for (int i = 0; i < sortedQueries.size(); i++) {
            res[sortedQueries[i].second] = seg[indexOfLeaf[i]].val;
        }
        return res;
    }
};