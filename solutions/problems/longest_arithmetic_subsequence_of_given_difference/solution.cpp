class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int> seqLength;
        int mx = 0;
        for (int x : arr) {
            if (seqLength.find(x - difference) == seqLength.end()) {
                seqLength[x] = 1;
            }
            else {
                seqLength[x] = max(seqLength[x - difference] + 1, seqLength[x]);
            }
            mx = max(mx,seqLength[x]);
        }
        return mx;
    }
};