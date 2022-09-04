class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if (nums[0] == nums[nums.size()-1]) return 0;
        int idxLeft = 0, idxRight = nums.size()-1;
        while (idxLeft < nums.size() && nums[idxLeft] == nums[0]) ++idxLeft;
        while (idxRight > 0 && nums[idxRight] == nums.back()) --idxRight;
        return idxRight-idxLeft+1;
        
        
    }
};