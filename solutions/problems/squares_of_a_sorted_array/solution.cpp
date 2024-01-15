class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> freq(10005);
        fill(freq.begin(),freq.end(),0);
        for (int x : nums) {
            freq[abs(x)]++;
        }
        vector<int> res;
        for (int i = 0; i < freq.size(); i++) {
            for (int j = 0; j < freq[i]; j++) {
                res.push_back(i*i);
            }
        }
        return res;
    }
};