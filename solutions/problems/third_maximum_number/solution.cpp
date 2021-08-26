class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int uni = 1;
        int idx = nums.size()-2;
        int res = 0;
        while (idx >= 0 && uni < 3) {
            if (nums[idx] != nums[idx+1]) uni++;
            if (uni == 3) res = nums[idx];
            idx--;
        }
        if (uni < 3) return nums[nums.size()-1];
        return res;
        
        
        
    }
};