class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> kValues;
        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i] - nums[0];
            if (x % 2 == 0 && x != 0) kValues.push_back(x/2);
        }
        for (int k : kValues) {
            queue<int> q;
            vector<int> v;
            for (int i = 0; i < nums.size(); i++) {
                if (q.size() > 0 && q.front() == nums[i]) {
                    q.pop();
                    v.push_back(nums[i]-k);
                }
                else {
                    q.push(nums[i]+2*k);
                }
            }
            if (q.size() == 0) return v;
        }
        vector<int> empty;
        return empty;
    }
};