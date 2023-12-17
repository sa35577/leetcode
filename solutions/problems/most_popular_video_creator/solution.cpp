class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string,long long> popularity; //map: creator -> sum of views
        map<string,pair<long long,string>> bestVideo; //map: creator -> pair{max view, id}

        long long highestView = -1;

        for (int i = 0; i < creators.size(); i++) {
            if (popularity.find(creators[i]) == popularity.end()) {
                popularity[creators[i]] = 0;
            }
            long long v = (long long)(views[i]);
            popularity[creators[i]] += v;
            highestView = max(highestView,popularity[creators[i]]);

            if (bestVideo.find(creators[i]) == bestVideo.end()) {
                bestVideo[creators[i]] = make_pair(-v,ids[i]);
            }
            else {
                pair<long long,string> nextVideo = make_pair(-v,ids[i]);
                if (nextVideo < bestVideo[creators[i]]) {
                    bestVideo[creators[i]] = nextVideo;
                }
            }
        }

        vector<vector<string>> ret;
        for (auto it = popularity.begin(); it != popularity.end(); it++) {
            if (it->second == highestView) {
                string creator = it->first;
                vector<string> creatorData{creator,bestVideo[creator].second};
                ret.push_back(creatorData);
            }
        }
        return ret;
    }
};