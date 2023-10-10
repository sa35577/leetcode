#include <algorithm>
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        vector<pair<int,int>> bestStart;
        set<int> seen;
        for (vector<int> e : events) {
            if (seen.find(e[0]) == seen.end()) {
                seen.insert(e[0]);
                bestStart.push_back({e[0],e[2]});
            }
            else {
                bestStart.back() = max(bestStart.back(),{e[0],e[2]});
            }
        }
        vector<pair<int,int>> mxStart{bestStart.back()};
        for (int i = bestStart.size()-1; i >= 0; i--) {
            mxStart.push_back({bestStart[i].first,max(mxStart.back().second,bestStart[i].second)});
        }
        reverse(mxStart.begin(),mxStart.end());
        vector<pair<int,int>> eventsRev;
        for (int i = 0; i < events.size(); i++) {
            eventsRev.push_back({events[i][1],events[i][2]});
        }
        sort(eventsRev.begin(),eventsRev.end());
        int mxScore = 0;
        for (pair<int,int> e : eventsRev) {
            int endVal = e.first, score = e.second;
            auto it = std::lower_bound(mxStart.begin(),mxStart.end(),make_pair(endVal,INT_MAX));
            if (it != mxStart.end()) {
                pair<int,int> secondaryBest = mxStart[it-mxStart.begin()];
                mxScore = max(mxScore,score + secondaryBest.second);
            }
            else {
                mxScore = max(mxScore,score);
            }
        }
        return mxScore;
    }
};