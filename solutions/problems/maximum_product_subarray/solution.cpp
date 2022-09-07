class Solution {
public:
    int subArrayProd(vector<int>& nums, int L, int R) {
        if (L > R) return 0;
        int res = 1;
        for (int i = L; i <= R; i++) res *= nums[i];
        return res;
    }
    
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums.back();
        vector<int> zeroidx{-1};
        int mx = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zeroidx.push_back(i);
            mx = max(mx,nums[i]);
        }
        zeroidx.push_back(nums.size());
        
        for (int i = 1; i < zeroidx.size(); i++) {
            int L = zeroidx[i-1]+1;
            int R = zeroidx[i]-1;
            
            int cntneg = 0;
            for (int i = L; i <= R; i++) if (nums[i] < 0) cntneg++;
            if (cntneg % 2 == 0) {
                mx = max(mx,subArrayProd(nums,L,R));
            }
            else {
                int leftptr = L, rightptr = R;
                while (nums[leftptr] > 0) leftptr++;
                while (nums[rightptr] > 0) rightptr--;
                mx = max(mx,subArrayProd(nums,leftptr+1,R));
                mx = max(mx,subArrayProd(nums,L,rightptr-1));
            }
        }
        return mx;
    }
    
};