class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res,nums = nums2;
        res.resize(nums.size());
        int n = nums.size();
        int mx = INT_MIN;
        int needToFill = 0;
        for (int i : nums) mx = max(i,mx);
        for (int i = 0; i < res.size(); i++) {
            if (nums[i] == mx) res[i] = INT_MAX;
            else {
                res[i] = -2;
                needToFill++;
            }
        }
        int L = 0;
        deque<int> dq;
        bool exhuast = false;
        while (needToFill > 0 && !exhuast) {
            while (res[L] != -2) L = (L + 1);
            if (L == n) {exhuast = true; break;}
            dq.push_back(L);
            while (!dq.empty()) {
                L = (L + 1);
                if (L == n) {exhuast = true; break;}
                while (!dq.empty() && nums[L] > nums[dq.back()]) { //answer current queries with current element
                    res[dq.back()] = nums[L];
                    needToFill--;
                    dq.pop_back();
                }
                if (res[L] == -2) dq.push_back(L); //add current element to list of queries, if needed
            }
        }
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == INT_MAX || res[i] == -2) res[i] = -1;
        }

        // for (int i : res) cout << i << " ";
        // cout << endl;
        
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        vector<int> ret;
        for (int x : nums1) {
            ret.push_back(res[mp[x]]);
        }
        return ret;
    }
};