class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int evens = 0;
        for (int i : nums) if (i%2 == 0) evens++;
        if (evens == 0 || evens == nums.size()) return nums;
        int ev = 0, od = nums.size()-1;
        for (; ev < evens; ev++) {
            if (nums[ev] % 2 == 1) {
                while (nums[od] % 2 == 1) od--;
                nums[ev] = nums[ev] ^ nums[od];
                nums[od] = nums[ev] ^ nums[od];
                nums[ev] = nums[ev] ^ nums[od];
            }
        }
        return nums;
    }
};