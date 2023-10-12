class Solution {
public:

    set<pair<int,int>> intervals;
    vector<long long> psa;

    long long rangeSum(int L, int R) {
        if (L == 0) return psa[R];
        return psa[R] - psa[L-1];
    }

    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        
        psa.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            psa.push_back(psa.back()+nums[i]);
        }
        
        intervals.insert({0,nums.size()-1});
        multiset<long long> sums;
        sums.insert(psa.back());
        vector<long long> ret;
        for (int query : removeQueries) {
            auto it = intervals.upper_bound({query,INT_MAX});
            it--;
            pair<int,int> breaker = *it;
            intervals.erase(breaker);
            auto sumsIt = sums.lower_bound(rangeSum(breaker.first,breaker.second));
            sums.erase(sumsIt);
            // sums.erase(rangeSum(breaker.first,breaker.second));
            pair<int,int> p1;
            pair<int,int> p2;
            if (breaker.first == query && breaker.second == query) {
                ;
            }
            else if (breaker.first == query) {
                p2 = {query+1,breaker.second};
                intervals.insert(p2);
                sums.insert(rangeSum(p2.first,p2.second));
            }
            else if (breaker.second == query) {
                p1 = {breaker.first,query-1};
                intervals.insert(p1);
                sums.insert(rangeSum(p1.first,p1.second));
            }
            else {
                p1 = {breaker.first,query-1};
                p2 = {query+1,breaker.second};
                intervals.insert(p1);
                intervals.insert(p2);
                sums.insert(rangeSum(p2.first,p2.second));
                sums.insert(rangeSum(p1.first,p1.second));
            }

            if (sums.empty()) ret.push_back(0LL);
            else ret.push_back(*sums.rbegin());
        }
        return ret;
    }
};