class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // vector<int> v;
        int cnt = 0;
        for (int x : nums) {
            if (x > 0) cnt++;
            // if (x > 0) v.push_back(x);
        }
        int L = 0, R = nums.size()-1;
        while (L < cnt) {
            while (L < cnt && nums[L] > 0) L++;
            if (L == cnt) break;
            while (nums[R] <= 0) R--;
            swap(nums[L],nums[R]);
        }
        for (int x : nums) cout << x << " ";
        while (nums.size() > cnt) nums.pop_back();

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // for (int x : v) cout << x << " ";
            // cout << endl;
            int x = nums[i];
            if (x <= 0) continue;
            if (nums[i]-1 == x) {
                nums[i] = -1;
                continue;
            }
            int idx = i;
            bool first = true;
            while (nums[idx] > 0) {
                int x = nums[idx]; //next value
                if (first) nums[idx] = 0;
                else nums[idx] = -1;
                first = false;
                if (x > n) {
                    // swap(v[n-1],v[x-1]);
                    // n--;
                    if (i < x) i--;
                    break;
                }
                else if (nums[x-1] <= 0) {
                    nums[x-1]--;
                    idx = x-1; //break on next iteration
                }
                else {
                    idx = x-1; //continue
                }
            }

        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) return i+1;
        }
        return nums.size()+1;
    }
};