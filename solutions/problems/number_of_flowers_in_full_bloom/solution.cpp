class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<pair<int,int>> allTimes;
        for (int i = 0; i < flowers.size(); i++) {
            allTimes.push_back({flowers[i][0],1});
            allTimes.push_back({flowers[i][1]+1,-1});
        }
        sort(allTimes.begin(),allTimes.end());
        set<pair<int,int>> score; //pair<time,score>
        int prevScore = 0;
        for (int i = 0; i < allTimes.size(); i++) {
            int j = i;
            while (j < allTimes.size() && allTimes[j].first == allTimes[i].first) {
                prevScore += allTimes[j].second;
                j++;
            }
            j--;
            i = j;
            score.insert({allTimes[j].first,prevScore});
        }
        vector<int> ret;
        for (int time : people) {
            auto it = score.upper_bound({time,INT_MAX});
            if (it == score.begin()) ret.push_back(0);
            else {
                it--;
                ret.push_back((*it).second);
            }
        }
        return ret;
    }
};