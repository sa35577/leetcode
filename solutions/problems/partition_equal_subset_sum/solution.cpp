class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<bool> v(20005);
        fill(v.begin(),v.end(),false);
        int sum = 0;
        v[0] = true;
        for (int x : nums) {
            for (int i = 20000; i >= 0; i--) {
                if (v[i]) v[i + x] = true;
            }
            sum += x;
        }
        return (sum % 2 == 0 && v[sum/2]);
        
    }
};