class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 1) return nums;
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> score;
        score.resize(nums.size());
        score[0] = {1,-1};
        int best = 1;
        for (int i = 1; i < nums.size(); i++) {
            score[i] = {1,-1};
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    // cout << i << " " << j << endl;
                    if (score[j].first + 1 > score[i].first) {
                        score[i].first = score[j].first + 1;
                        score[i].second = j;
                    }
                }
            }
            best = max(best,score[i].first);
        }
        // cout << best << endl;
        int ptr = 0;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            if (score[i].first == best) {
                ptr = i;
                break;
            }
        }
        while (ptr != -1) {
            ret.push_back(nums[ptr]);
            ptr = score[ptr].second;
        }
        return ret;

    }
};