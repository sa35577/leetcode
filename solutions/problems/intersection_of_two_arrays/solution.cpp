class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for (int i : nums1) {
            s.insert(i);
        }
        vector<int> v;
        for (int i : nums2) {
            if (s.count(i) > 0) {
                s.erase(i);
                v.push_back(i);
            }
        }
        return v;
    }
};