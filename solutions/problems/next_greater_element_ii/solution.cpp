class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        res.resize(nums.size());
        int n = nums.size();
        int mx = INT_MIN;
        int needToFill = 0;
        for (int i : nums) mx = max(i,mx);
        for (int i = 0; i < res.size(); i++) {
            if (nums[i] == mx) res[i] = INT_MAX;
            else {
                res[i] = 0;
                needToFill++;
            }
        }
        int L = 0;
        deque<int> dq; //queries are such that q0 >= q1 >= q2 >= ...
        // for (int i = 0; i < res.size(); i++) {
        //     cout << res[i] << " ";
        // }
        // cout << endl;
        while (needToFill > 0) {
            while (res[L] != 0) L = (L + 1) % n;
            dq.push_back(L);
            while (!dq.empty()) {
                L = (L + 1) % n;
                while (!dq.empty() && nums[L] > nums[dq.back()]) { //answer current queries with current element
                    res[dq.back()] = nums[L];
                    needToFill--;
                    dq.pop_back();
                }
                if (res[L] == 0) dq.push_back(L); //add current element to list of queries, if needed
            }
        }
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == INT_MAX) res[i] = -1;
        }
        return res;
    }
};