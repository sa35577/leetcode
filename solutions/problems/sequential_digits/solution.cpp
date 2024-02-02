class Solution {
public:
    vector<int> gen() {
        vector<int> v;
        for (int i = 1; i <= 9; i++) {
            int end = i;
            v.push_back(i);
            while (end+1 < 10) {
                end++;
                v.push_back(v.back() * 10 + end);
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v = gen();
        int idx = 0;
        vector<int> res;
        while (idx < v.size() && v[idx] <= high) {
            if (v[idx] >= low) res.push_back(v[idx]);
            idx++;
        }
        return res;
    }
};