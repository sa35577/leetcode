class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> neg,pos;
        bool isPos = false;
        for (int i = 0; i < arr.size(); i++) {
            if (isPos) {
                pos.push_back(arr[i]);
            }
            else {
                if (arr[i] >= 0) {
                    isPos = true;
                    pos.push_back(arr[i]);
                }
                else neg.push_back(arr[i]);
            }
        }
        reverse(neg.begin(),neg.end());
        queue<int> q;
        for (int i = 0; i < neg.size(); i++) {
            if (q.size() > 0 && q.front() == neg[i]) {
                q.pop();
            }
            else {
                q.push(2*neg[i]);
            }
        }
        if (q.size() > 0) return false;
        for (int i = 0; i < pos.size(); i++) {
            if (q.size() > 0 && q.front() == pos[i]) {
                q.pop();
            }
            else {
                q.push(2*pos[i]);
            }
        }
        if (q.size() > 0) return false;
        return true;
        
    }
};