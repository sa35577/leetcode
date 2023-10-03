class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int sum = 0;
        map<int,int> freq;
        for (int i : nums) {
            if (freq.find(i) == freq.end()) {
                freq[i] = 1;
            }
            sum += freq[i]-1;
            freq[i]++;
        }
        return sum;
    }
};