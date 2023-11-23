class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for (int i = 0; i < l.size(); i++) {
            int L = l[i], R = r[i];
            vector<int> v;
            for (int j = L; j <= R; j++) v.push_back(nums[j]);
            sort(v.begin(),v.end());
            if (v.size() <= 2) {
                res.push_back(true);
            }
            else {
                int diff = v[1]-v[0];
                bool valid = true;
                for (int j = 2; j < v.size(); j++) {
                    if (v[j] - v[j-1] != diff) {
                        valid = false;
                        break;
                    }
                }
                res.push_back(valid);
            }
        }
        return res;
    }
};