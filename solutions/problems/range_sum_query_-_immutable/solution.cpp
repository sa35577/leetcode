class NumArray {
public:
    vector<int> psa;
    NumArray(vector<int>& nums) {
        psa.resize(nums.size()+1);
        for (int i = 1; i < psa.size(); i++) {
            psa[i] = psa[i-1] + nums[i-1];
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