class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<pair<int,int>> diffs;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += abs(nums1[i]-nums2[i]);
            sum %= 1000000007;
        }
        int maxDiff = 0;
        vector<int> n1 = nums1;
        sort(n1.begin(),n1.end());
        for (int i = 0; i < n; i++) {
            int x = nums2[i];
            int idx = std::lower_bound(n1.begin(),n1.end(),x) - n1.begin();
            if (idx == n) {
                maxDiff = max(maxDiff,abs(nums1[i]-nums2[i]) - abs(n1[idx-1]-x));
            }
            else {
                maxDiff = max(maxDiff,abs(nums1[i]-nums2[i]) - abs(n1[idx]-x));
                if (idx > 0) maxDiff = max(maxDiff,abs(nums1[i]-nums2[i]) - abs(n1[idx-1]-x));
            }
        }
        return (sum+1000000007 - maxDiff) % 1000000007;
    }
};