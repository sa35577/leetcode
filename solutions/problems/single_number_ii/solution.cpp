class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int arr[32];
        fill(arr,arr+32,0);
        int neg = 0;
        int intmincnt = 0;
        for (int x : nums) {
            if (x == INT_MIN) intmincnt++;
        }
        if (intmincnt == 1) return INT_MIN;
        for (int x : nums) {
            int idx = 0;
            while (x != 0) {
                if (x % 2 == 1 || x % 2 == -1) arr[idx]++;
                x /= 2;
                idx++;
            }

        }
        for (int i = 0; i < 32; i++) arr[i] %= 3;
        int x = 0;
        if (arr[31] == 1) {
            //negative
            x = INT_MIN;
            for (int i = 30; i >= 0; i++) {
                if (arr[i] == 1) x += (1 << i);
            }
        }
        else {
            for (int i = 30; i >= 0; i--) {
                x = x * 2 + arr[i];
            }
        }
        int xcnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) xcnt++;
        }
        if (xcnt == 1) return x;
        return -x;

    }
};