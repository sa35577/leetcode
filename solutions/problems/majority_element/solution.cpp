class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int cur = INT_MIN;
        for (int i : nums) {
            if (cnt == 0) {
                cnt = 1;
                cur = i;
            }
            else {
                if (cur == i) cnt++;
                else cnt--;
            }
        }
        return cur;
    }
};