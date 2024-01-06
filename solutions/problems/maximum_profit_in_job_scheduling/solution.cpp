class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // sort jobs by increasing end time
        // for every job, check what the highest profit achieved <= the start time is. how?
        // for every end time, have a max profit variable of maximum attainable profit with that as the end time considered
        // maxprofit(endTime[i]) = maxprofit(endTime[i-1], profit[i] + maxprofit(highest end time before startTime[i]))
        vector<pair<pair<int,int>,int>> v;
        for (int i = 0; i < startTime.size(); i++) {
            v.push_back({{endTime[i],startTime[i]},profit[i]});
        }
        sort(v.begin(),v.end());
        set<pair<int,int>> maxProfit; //maxProfit{right end, maximal profit up to current index}
        int mx = -1;
        for (pair<pair<int,int>,int> cur : v) {
            int right = cur.first.first, left = cur.first.second, score = cur.second;
            auto it = maxProfit.upper_bound({left,INT_MAX});
            if (it == maxProfit.begin() || maxProfit.empty()) {
                mx = max(mx,score);
                maxProfit.insert({right,mx});
                
            }
            else {
                it--;
                pair<int,int> prev = *it;
                int newScore = prev.second + score;
                mx = max(mx,newScore);
                maxProfit.insert({right,mx});
            }
        }
        return mx;

    }
};