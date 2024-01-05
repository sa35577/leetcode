class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix{nums[0]},suffix{nums.back()};
        for (int i = 1; i < nums.size(); i++) prefix.push_back(prefix.back() * nums[i]);
        for (int i = (int)(nums.size())-2; i >= 0; i--) {
            suffix.push_back(suffix.back() * nums[i]);
        }
        for (int i = 0; i < prefix.size(); i++) {
            cout << prefix[i] << " ";
        }
        cout << endl;
        reverse(suffix.begin(),suffix.end());
        for (int i = 0; i < suffix.size(); i++) {
            cout << suffix[i] << " ";
        }
        cout << endl;
        vector<int> ans(nums.size());
        ans[0] = suffix[1];
        ans.back() = prefix[prefix.size()-2];
        for (int i = 1; i < ans.size()-1; i++) {
            ans[i] = prefix[i-1] * suffix[i+1];
        }
        return ans;
    }
};