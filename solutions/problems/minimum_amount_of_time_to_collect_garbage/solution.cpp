class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<vector<int>> data;
        for (int i = 0; i < garbage.size(); i++) {
            data.push_back({0,0,0});
        }
        int lastM = 0, lastP = 0, lastG = 0;
        for (int i = 0; i < garbage.size(); i++) {
            for (char c : garbage[i]) {
                if (c == 'M') {
                    lastM = i;
                    data[i][0]++;
                }
                else if (c == 'P') {
                    lastP = i;
                    data[i][1]++;
                }
                else {
                    lastG = i;
                    data[i][2]++;
                }
            }
        }
        int score = garbage[0].size();
        int i = 0;
        while (i < lastM) {
            score += travel[i];
            i++;
            score += data[i][0];
        }
        i = 0;
        while (i < lastP) {
            score += travel[i];
            i++;
            score += data[i][1];
        }
        i = 0;
        while (i < lastG) {
            score += travel[i];
            i++;
            score += data[i][2];
        }
        return score;
    }
};