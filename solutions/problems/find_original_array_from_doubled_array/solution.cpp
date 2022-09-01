class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> v;
        sort(changed.begin(),changed.end());
        queue<int> q;
        for (int i = 0; i < changed.size(); i++) {
            if (q.size() > 0 && q.front() == changed[i]) {
                v.push_back(changed[i]/2);
                q.pop();
            }
            else q.push(2*changed[i]);
        }
        if (q.size() > 0) {
            v.clear();
        }
        return v;
    }
};