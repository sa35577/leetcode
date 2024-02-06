class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() == 1) return false;
        unordered_map<int,int> last;
        last[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % k;
            if (last.find(sum) != last.end() && last[sum] < i-1) {
                return true;
            }
            if (last.find(sum) == last.end()) last[sum] = i;
        }
        return false;
    }
};