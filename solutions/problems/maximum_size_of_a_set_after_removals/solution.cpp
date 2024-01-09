class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp1,mp2;
        for (int x : nums1) {
            if (mp1.find(x) == mp1.end()) mp1[x] = 1;
            else mp1[x]++;
        }
        for (int x : nums2) {
            if (mp2.find(x) == mp2.end()) mp2[x] = 1;
            else mp2[x]++;
        }
        int sameNumbers = 0, leftUnique = 0, rightUnique = 0;
        for (auto it = mp1.begin(); it != mp1.end(); it++) {
            int x = it->first;
            if (mp2.find(x) == mp2.end()) leftUnique++;
            else sameNumbers++;
        }
        for (auto it = mp2.begin(); it != mp2.end(); it++) {
            int x = it->first;
            if (mp1.find(x) == mp1.end()) rightUnique++;
            else ;
        }
        int n = nums1.size();
        if (leftUnique >= n/2 && rightUnique >= n/2) {
            return n;
        }
        else if (leftUnique >= n/2) {
            return n/2 + min(n/2,rightUnique+sameNumbers);
        }
        else if (rightUnique >= n/2) {
            return n/2 + min(n/2,leftUnique+sameNumbers);
        }
        return min(n,leftUnique+rightUnique+sameNumbers);
    }
};