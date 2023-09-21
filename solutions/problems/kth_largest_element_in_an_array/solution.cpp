class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> s;
        int cnt = 0;
        for (int i : nums) {
            s.insert(i);
            cnt++;
            if (cnt > k) {
                s.erase(s.begin());
            }
        }
        return *s.begin();
    }
};