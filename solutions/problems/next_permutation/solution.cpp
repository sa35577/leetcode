class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // if its reverse sorted order, reverse it and return
        // from back to front, (i.e. i == n-1 to 0): find max i such that nums[i] > nums[i-1]
        // put the lowest of nums[i-1] .. nums[n] there, and sort the remainder
        

        //check if reverse
        bool done = true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) {
                done = false;
                break;
            }
        }
        if (done) {
            reverse(nums.begin(),nums.end());
            return;
        }

        for (int i = nums.size()-1; i > 0; i--) {
            if (nums[i] > nums[i-1]) {
                int uBound = nums[i], uBoundIndex = i;
                for (int j = i+1; j < nums.size(); j++) {
                    if (nums[j] > nums[i-1] && nums[j] <= uBound) {
                        uBound = nums[j];
                        uBoundIndex = j;
                    }
                }
                swap(nums[uBoundIndex],nums[i-1]);
                sort(nums.begin()+i,nums.end());
                return;
            }
        }
        return;
    }
};