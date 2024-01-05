class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long left = 0, right = 0;
        cout << INT_MIN << endl;
        for (int x : nums) right += x;
        int idx = 0;
        int cnt = 0;
        while (idx < nums.size()-1) {
            left += nums[idx];
            right -= nums[idx];
            if (left >= right) cnt++;
            idx++;
        }
        return cnt;
    }
};