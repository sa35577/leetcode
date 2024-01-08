class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> nums2;
        for (int x : nums) if (x < pivot) nums2.push_back(x);
        for (int x : nums) if (x == pivot) nums2.push_back(x);
        for (int x : nums) if (x > pivot) nums2.push_back(x);
        return nums2;
    }

};