class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int mxDist = -1, i = nums1.size()-1, j = nums2.size()-1;
        while (i >= 0 && j >= 0) {
            if (i > j) i--;
            else if (nums1[i] > nums2[j]) j--;
            else {
                mxDist = max(mxDist,j-i);
                i--;
            }
        }
        if (mxDist == -1) return 0;
        return mxDist;
    }
};