class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bool s[100005];
        for (int i = 0; i < 100005; i++) s[i] = 0;
        for (int i : nums) {
            if (s[i] == 1) return i;
            s[i] = 1;
        }
        return -1;
    }
};