class Solution {
public:
    int algorithmScore(vector<int>& score, int L, int R) {
        string firstMode = "";
        if (score[L] < score[L+1]) firstMode = "up";
        if (score[L] > score[L+1]) firstMode = "down";
        vector<int> diffs;
        int idx = L;
        while (idx < R) {
            if (score[idx] < score[idx+1]) {
                diffs.push_back(2);
                idx++;
                while (idx + 1 <= R && score[idx] < score[idx+1]) {
                    diffs.back()++;
                    idx++;
                }
            }
            else {
                diffs.push_back(2);
                idx++;
                while (idx + 1 <= R && score[idx] > score[idx+1]) {
                    diffs.back()++;
                    idx++;
                }
            }
            // cout << "Diffs: ";
            // for (int i : diffs) cout << i << " ";
        }
        
        // cout << endl;
        bool first = true;
        int prevHeight = 0;
        int val = 0;
        for (int diff : diffs) {
            if (first) {
                val += ((diff - 1) * diff) / 2;
                if (firstMode == "up") {
                    prevHeight = diff - 1;
                    firstMode = "down";
                }
                else {
                    prevHeight = 0;
                    firstMode = "up";
                }
                first = false;
            }
            else {
                if (firstMode == "up") { //start from 0
                    val += ((diff - 1) * diff) / 2;
                    firstMode = "down";
                    prevHeight = diff-1;
                }
                else { //check what prev height is
                    if (diff - 1 >= prevHeight) { //remove previous height from sum
                        val += ((diff - 1) * diff) / 2;
                        val -= prevHeight;
                    }
                    else { //use as stacker, sum from 0 to diff - 2
                        val += ((diff - 2) * (diff - 1)) / 2;
                    }
                    firstMode = "up";
                    prevHeight = 0;
                }
            }
        }
        return val;
    }
    int candy(vector<int>& ratings) {
        //at most 2 numbers consecutive, remove others in between
        if (ratings.size() == 1) return 1;
        int curGroup = 1;
        vector<int> unionGroup;
        vector<int> score;
        unionGroup.resize(ratings.size());
        score.resize(ratings.size());
        for (int i = 0; i < unionGroup.size(); i++) {
            unionGroup[i] = 0;
            score[i] = 0;
        }
        int idx = 0;
        map<int,pair<int,int>> groups;
        // for (int x : ratings) cout << x << " " ;
        // cout << endl;
        while (idx < unionGroup.size()) {
            // cout << idx << endl;
            if (idx + 1 < unionGroup.size() && ratings[idx] == ratings[idx+1]) {
                idx++;
            }
            else if (idx + 1 < unionGroup.size()) {
                score[idx] = 0;
                unionGroup[idx] = curGroup;
                int L = idx;
                idx++;
                while (true) {
                    score[idx] = score[idx-1];
                    if (ratings[idx] < ratings[idx-1]) score[idx]--;
                    else score[idx]++;
                    unionGroup[idx] = curGroup;
                    if (idx + 1 == unionGroup.size() || ratings[idx+1] == ratings[idx]) break;
                    idx++;
                }
                int R = idx;
                groups[curGroup] = {L,R};
                curGroup++;
                idx++;
                // while (idx + 1 < unionGroup.size() && ratings[idx+1] == ratings[idx]) {
                //     idx++;
                // }

            }
            else {
                score[idx] = 0;
                unionGroup[idx] = curGroup;
                idx++;
                curGroup++;
            }
            // cout << "The current group is " << curGroup << endl;
        }
        // cout << "Done\n";
        // for (int i = 0; i < unionGroup.size(); i++) {
        //     cout << unionGroup[i] << " " ;
        // }
        // cout << endl;
        //groups are 1 ... curGroup - 1
        int tot = 0;
        for (auto it = groups.begin(); it != groups.end(); it++) {
            tot += algorithmScore(score,(it->second).first,(it->second).second);
        }
        return score.size() + tot;

    }
};