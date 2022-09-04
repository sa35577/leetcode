class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int leftptr = 0, rightptr = 0, curptr = 0;
        while (leftptr < nums.size()) {
            rightptr = leftptr;
            while (rightptr+1 < nums.size() && nums[rightptr+1] == nums[leftptr]) ++rightptr;
            if (leftptr == rightptr) {
                nums[curptr] = nums[leftptr];
                curptr++;
                leftptr++;
            }
            else {
                nums[curptr] = nums[leftptr];
                curptr++;
                nums[curptr] = nums[rightptr];
                curptr++;
                leftptr = rightptr+1;
            }
        }
        return curptr;
    }
};