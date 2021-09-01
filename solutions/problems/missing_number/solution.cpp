class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int tot = 0;
        int numsTot = 0;
        tot = (nums.size()*(nums.size()+1))/2;
        for (int i : nums) numsTot += i;
        return tot-numsTot;
    }
};