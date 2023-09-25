class Solution {
public:
    vector<int> prereq[2001];
    int res[2001]; //0 if not visited, -1 if cant finish, 1 if can finish
    bool rec(int idx) {
        bool cur = true;
        if (res[idx] == -1) return false; //dependency or cant finish
        if (res[idx] == 1) return true; //already computed to be ok
        res[idx] = -1;
        for (int i : prereq[idx]) {
            bool recres = rec(i);
            if (!recres) {
                cur = false;
                break;
            }
        }
        if (cur) res[idx] = 1;
        return cur;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (vector<int> v : prerequisites) {
            prereq[v[0]].push_back(v[1]);
        }
        for (int i = 0; i < 2001; i++) res[i] = 0;
        for (int i = 0; i < numCourses; i++) {
            if (!rec(i)) return false;
        }
        return true;
    }
};