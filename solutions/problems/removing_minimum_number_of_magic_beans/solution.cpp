class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        if (beans.size() == 1) return 0LL;
        vector<long long> jellybean;
        for (int bean : beans) {
            jellybean.push_back((long long)(bean));
        }
        sort(jellybean.begin(),jellybean.end());
        vector<long long> sumLeft{jellybean[0]}, sumRight{jellybean.back()};
        for (int i = 1; i < jellybean.size(); i++) {
            sumLeft.push_back(sumLeft.back()+jellybean[i]);
        }
        for (int i = (int)(jellybean.size()) - 2; i >= 0; i--) {
            sumRight.push_back(sumRight.back()+jellybean[i]);
        }
        reverse(sumRight.begin(),sumRight.end());
        long long sz = (long long)(jellybean.size());

        long long mn = min(sumRight[1] - jellybean[0] * (sz-1), sumLeft[jellybean.size()-2]);
        for (int i = 1; i < jellybean.size()-1; i++) {
            mn = min(mn,sumLeft[i-1] + sumRight[i+1] - jellybean[i] * (sz-(long long)(i+1)));
        }
        return mn;
    }
};