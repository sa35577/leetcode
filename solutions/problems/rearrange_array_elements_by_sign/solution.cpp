class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg;
        for (int x : nums) {
            if (x > 0) pos.push_back(x);
            if (x < 0) neg.push_back(x);
        }
        vector<int> v;
        for (int i = 0; i < pos.size(); i++) {
            v.push_back(pos[i]);
            v.push_back(neg[i]);
        }
        return v;
    }
};