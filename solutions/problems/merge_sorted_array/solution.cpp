class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        int n1 = 0, n2 = 0;
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        if (n == 0) return;
        
        while (!(n1 == m && n2 == n)) {
            if (n1 != m && n2 != n) {
                if (nums1[n1] <= nums2[n2]) {
                    res.push_back(nums1[n1]);
                    n1++;
                }
                else {
                    res.push_back(nums2[n2]);
                    n2++;
                }
            }
            else if (n1 != m) {
                res.push_back(nums1[n1]);
                n1++;
            }
            else {
                res.push_back(nums2[n2]);
                n2++;
            }
        }
        nums1 = res;
        
    }
};