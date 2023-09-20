class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i],i});
        }
        for (int i = 0; i < k; i++) {
            pair<int,int> cur = pq.top();
            pq.pop();
            nums[cur.second]++;
            pq.push({nums[cur.second],cur.second});
        }
        long long mod = 1000000007;
        long long res = 1;
        for (int i : nums) {
            res = (res * (long long)(i)) % mod;
        }
        return res;
    }
};