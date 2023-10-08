class Solution {
public:
    unordered_map<int,int> mp; //map: hash(i,j) -> optimal val
    vector<int> mx1,mn1; //max of nums1[i...]
    vector<int> mx2,mn2; //max of nums2[i...]
    vector<int> nums1,nums2;

    int hash(int x1, int x2) {
        return x1 * 500 + x2;
    }

    pair<int,int> unhash(int idx) {
        return make_pair(idx / 500, idx % 500);
    }

    int dp(int i, int j) {
        if (i == nums1.size() || j == nums2.size()) return 0;
        if (mp.find(hash(i,j)) != mp.end()) return mp[hash(i,j)];

        if (mx1[i] < 0 && mn2[j] > 0) {
            mp[hash(i,j)] = mx1[i] * mn2[j];
            return mp[hash(i,j)];
        }
        if (mn1[i] > 0 && mx2[j] < 0) {
            mp[hash(i,j)] = mn1[i] * mx2[j];
            return mp[hash(i,j)];
        }

        int x1 = nums1[i] * nums2[j] + dp(i+1,j+1);
        int x2 = dp(i,j+1);
        int x3 = dp(i+1,j);
        int x4 = nums1[i] * nums2[j];
        mp[hash(i,j)] = max(max(x1,x2),max(x3,x4));
        return mp[hash(i,j)];
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        mx1.push_back(nums1.back());
        mx2.push_back(nums2.back());
        mn1.push_back(nums1.back());
        mn2.push_back(nums2.back());   
        for (int i = nums1.size()-1; i >= 0; i--) {
            mx1.push_back(max(mx1.back(),nums1[i]));
            mn1.push_back(min(mn1.back(),nums1[i]));
        }
        for (int i = nums2.size()-1; i >= 0; i--) {
            mx2.push_back(max(mx2.back(),nums2[i]));
            mn2.push_back(min(mn2.back(),nums2[i]));
        }
        reverse(mx1.begin(),mx1.end());
        reverse(mx2.begin(),mx2.end());
        reverse(mn1.begin(),mn1.end());
        reverse(mn2.begin(),mn2.end());
        return dp(0,0);
    }
};