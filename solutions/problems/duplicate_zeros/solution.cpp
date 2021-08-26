class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> res;
        int sz = arr.size();
        for (int i : arr) {
            res.push_back(i);
            if (res.size() == sz) break;
            if (i == 0) res.push_back(i);
            if (res.size() == sz) break;
        }
        arr = res;
    }
};