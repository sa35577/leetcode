class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> freq;
        int cnt = 0;
        int sum = 0;
        freq[0] = 1;
        for (int x : nums) {
            // cout << cnt << endl;
            sum += x;
            if (freq.find(sum-k) != freq.end()) cnt += freq[sum-k];
            if (freq.find(sum) == freq.end()) freq[sum] = 0;
            freq[sum]++;
        }
        return cnt;
    }
};