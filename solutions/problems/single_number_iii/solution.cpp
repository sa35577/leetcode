class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorvalue = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            xorvalue = xorvalue ^ nums[i];
        }
        // cout << xorvalue << endl;
        int g1 = 0, g2 = 0;
        int cnt = 0;
        while (xorvalue % 2 == 0) {
            cnt++;
            xorvalue /= 2;
        }
        // cout << cnt << endl;
        for (int x : nums) {
            if ((x >> cnt) % 2 == 0) g1 ^= x;
            else g2 ^= x;
        }
        return {g1,g2};
    }
};