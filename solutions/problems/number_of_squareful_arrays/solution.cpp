class Solution {
public:
    bool isPf(int val) {
        if (val == 0 || val == 46340 * 46340) return true;
        int L = 0, R = 46340;
        while (L < R) {
            int mid = (L+R)/2;
            if (mid*mid == val) return true;
            else if (mid*mid < val) L = mid+1;
            else R = mid - 1;
        }
        if (L*L == val) return true;
        return false;
    }
    int rec(vector<int>& nums, vector<bool> used, vector<vector<bool>> graph, int curIndex) {
        bool ended = true;
        for (int i = 0; i < used.size(); i++) {
            if (!used[i]) {
                ended = false;
                break;
            }
        }
        if (ended) return 1;
        int curPos = 0;
        int res = 0;
        while (curPos < nums.size()) {
            if (!used[curPos]) {
                if (graph[curIndex][curPos]) {
                    vector<bool> recUsed = used;
                    recUsed[curPos] = true;
                    res += rec(nums,recUsed,graph,curPos);
                }
                while (curPos+1 < nums.size() && nums[curPos] == nums[curPos+1]) curPos++;
            }
            curPos++;
        }
        return res;
    }
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(),nums.end());  
        vector<vector<bool>> graph;
        for (int i = 0; i < 13; i++) {
            vector<bool> v;
            for (int j = 0; j < 13; j++) v.push_back(false);
            graph.push_back(v);
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (isPf(nums[i]+nums[j])) {
                    graph[i][j] = true;
                    graph[j][i] = true;
                }
                else {
                    graph[i][j] = false;
                    graph[j][i] = false;
                }
            }
        }
        int curPos = 0;
        vector<bool> allFalse;
        for (int i = 0; i < nums.size(); i++) allFalse.push_back(false);
        int res = 0;
        while (curPos < nums.size()) {
            vector<bool> v = allFalse;
            v[curPos] = true;
            res += rec(nums,v,graph,curPos);
            while (curPos+1 < nums.size() && nums[curPos] == nums[curPos+1]) curPos++;
            curPos++;
        }
        return res;
    }
    
};