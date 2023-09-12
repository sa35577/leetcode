class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() <= 2) {
            reverse(nums.begin(),nums.end());
            return nums;
        }
        reverse(nums.begin(),nums.end());
        vector<int> leftProd, rightProd;
        leftProd.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            leftProd.push_back(leftProd.back() * nums[i]);
        }
        reverse(nums.begin(),nums.end());
        reverse(leftProd.begin(),leftProd.end());
        leftProd.push_back(1);
        vector<int> res;
        int num = 1;
        for (int i = 0; i < nums.size(); i++) {
            res.push_back(num*leftProd[i+1]);
            num = num * nums[i];
        }
        return res;

    }
};