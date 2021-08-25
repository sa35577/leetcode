class NumArray {
public:
    vector<int> A;
    vector<int> psa;
    NumArray(vector<int>& nums) {
        A.push_back(0);
        psa.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            A.push_back(nums[i]);
            psa.push_back(psa[i]+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return psa[right+1]-psa[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */