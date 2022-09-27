class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zerocnt = 0, onecnt = 0, twocnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zerocnt++;
            else if (nums[i] == 1) onecnt++;
            else twocnt++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (zerocnt > 0) {
                nums[i] = 0;
                zerocnt--;
            }
            else if (onecnt > 0) {
                nums[i] = 1;
                onecnt--;
            }
            else nums[i] = 2;
        }
    }
};