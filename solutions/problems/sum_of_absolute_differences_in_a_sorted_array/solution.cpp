class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> psafront,psaback;
        psafront.push_back(nums[0]);
        psaback.push_back(nums.back());
        for (int i = 1; i < nums.size(); i++) {
            psafront.push_back(psafront.back()+nums[i]);
        }
        for (int i = nums.size()-2; i >= 0; i--) {
            psaback.push_back(psaback.back()+nums[i]);
        }
        reverse(psaback.begin(),psaback.end());
        vector<int> ret;
        int x = nums.size()-1;
        ret.push_back(psaback[1]-nums[0]*x);
        for (int i = 1; i < nums.size()-1; i++) {
            ret.push_back(nums[i]*i - psafront[i-1] + psaback[i+1] - nums[i]*(x-i));
            // cout << nums[i]*i - psafront[i-1] << " " << psaback[i+1] - nums[i]*(x-i) << endl;
        }
        ret.push_back(nums.back()*x - psafront[psafront.size()-2]);
        return ret;
    }
};