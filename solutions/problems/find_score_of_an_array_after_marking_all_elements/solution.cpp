class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        vector<pair<int,int>> scores;
        bool done[100005];
        for (int i = 0; i < nums.size(); i++) {
            scores.push_back({nums[i],i});
            done[i] = false;
        }
        sort(scores.begin(),scores.end());
        for (pair<int,int> p : scores) {
            if (!done[p.second]) {
                //cout << p.second << endl;
                done[p.second] = 1;
                if (p.second > 0) done[p.second-1] = 1;
                if (p.second + 1 < nums.size()) done[p.second+1] = 1;
                score += p.first;
            }
        }
        return score;

    }
};