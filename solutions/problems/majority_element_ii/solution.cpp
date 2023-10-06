class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int i : nums) {
            if (freq.find(i) == freq.end()) freq[i] = 0;
            freq[i]++;
        }
        vector<int> res;
        int n = nums.size()/3;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second > n) res.push_back(it->first);
        }
        return res;
    }
};